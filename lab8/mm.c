/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
        /* Team name */
        "1190200703",
        /* First member's full name */
        "Jiannan Guan",
        /* First member's email address */
        "guanjiannan@outlook.com",
        /* Second member's full name (leave blank if none) */
        "",
        /* Second member's email address (leave blank if none) */
        ""
};


/* 字长 */
#define WSIZE 4
#define DSIZE 8

/* 每次扩展堆的块大小 */
#define CHUNKSIZE (1<<12)

/* 分离空闲链表最大链表数量 */
#define LISTMAX 16

/* 求最大值 */
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* 将块大小和分配情况打包进一个字 */
#define PACK(size, alloc) ((size) | (alloc))

/* 读取和写入 p 处的一个字 */
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

/* 将 ptr 写入到 p */
#define SET_PTR(p, ptr) (*(unsigned int *)(p) = (unsigned int)(ptr))

/* p 处的块大小和分配情况 */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* 指向 ptr 对应块的头部或尾部的指针 */
#define HDRP(ptr) ((char *)(ptr) - WSIZE)
#define FTRP(ptr) ((char *)(ptr) + GET_SIZE(HDRP(ptr)) - DSIZE)

/* 指向 ptr 对应块在地址顺序中的上一块或下一块的指针 */
#define PREV_BLKP(ptr) ((char *)(ptr) - GET_SIZE((char *)(ptr) - DSIZE))
#define NEXT_BLKP(ptr) ((char *)(ptr) + GET_SIZE((char *)(ptr) - WSIZE))

/* 指向 ptr 对应块在大小类中的上一块或下一块的指针 */
#define PREV_CLSP(ptr) ((char *)(ptr))
#define NEXT_CLSP(ptr) ((char *)(ptr) + WSIZE)

/* ptr 对应块在大小类中的上一块或下一块 */
#define PREV_CLS(ptr) (*(char **)(ptr))
#define NEXT_CLS(ptr) (*(char **)(NEXT_CLSP(ptr)))

/* 双字向上对齐 */
#define ALIGNMENT DSIZE
#define ALIGN(size) ((((size) + (ALIGNMENT-1)) / (ALIGNMENT)) * (ALIGNMENT))


/**
 * 分离空闲链表
 * <br/>
 * 该数组中最多有 LISTMAX 个大小类，大小类按照 2 的幂进行划分，即
 * 1-2, 3-4, 5-8, 9-16, ...
 * <br/>
 * 每个大小类中的链表都是双向链表，
 * 前驱节点指针可用 PREV_CLSP 宏获取，
 * 后继节点指针可用 NEXT_CLSP 宏获取
 */
void *segregated_free_lists[LISTMAX];


/**
 * 按照向上双字对齐，向内存系统请求额外的堆空间
 *
 * @param words 需要扩展的字大小
 * @return 扩展成功则返回块首地址指针，否则返回 NULL
 */
static void *extend_heap(size_t words);

/**
 * 将 ptr 对应的空闲块插入到分离空闲链表中
 *
 * @param ptr 空闲块指针
 * @param size 空闲块大小
 */
static void insert_node(void *ptr, size_t size);

/**
 * 将 ptr 对应的块从分离空闲链表中删除
 *
 * @param ptr 块指针
 */
static void delete_node(void *ptr);

/**
 * 合并与 ptr 对应的块相邻的空闲块
 *
 * @param ptr 当前块指针
 * @return 合并后的块指针
 */
static void *coalesce(void *ptr);

/**
 * 在 ptr 指向的空闲块中分配 size 大小的块
 * <br/>
 * 若剩下的空间大于 ALIGNMENT，则将剩余空间分割并插入到分离空闲链表
 *
 * @param ptr 空闲块首地址
 * @param size 待分配大小
 * @return 返回块指针
 */
static void *place(void *ptr, size_t size);

/**
 * 初始化虚拟内存管理
 *
 * @return 一切正常则返回 0，否则返回 -1
 */
int mm_init(void);

/**
 * 通过增加 brk 指针来分配一个新块，块大小双字向上对齐
 *
 * @param size 待分配大小
 * @return 返回块指针
 */
void *mm_malloc(size_t size);

/**
 * 释放 ptr 块
 *
 * @param ptr 块指针
 */
void mm_free(void *ptr);

/**
 * 调整已分配块的大小
 *
 * @param ptr 块指针
 * @param size 调整后的块大小
 * @return 返回调整后的块指针
 */
void *mm_realloc(void *ptr, size_t size);


static void *extend_heap(size_t words) {
    size_t size = ALIGN(words);
    void *ptr;

    if ((ptr = mem_sbrk(words)) == (void *) -1) {
        return NULL;
    }

    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));

    // 新的结尾块
    PUT(HDRP(NEXT_BLKP(ptr)), PACK(0, 1));

    // 将新块插入到分离空闲链表
    insert_node(ptr, size);

    return coalesce(ptr);
}

static void insert_node(void *ptr, size_t size) {
    int list_index = 0;
    size_t search_size = size;
    void *search_ptr = NULL;
    void *insert_ptr = NULL;

    // 通过块大小找到对应的大小类所在的链位置
    while (list_index < LISTMAX - 1 && search_size > 1) {
        search_size >>= 1;
        list_index++;
    }

    // 在块大小由小到大排序的链中寻找插入位置
    search_ptr = segregated_free_lists[list_index];
    while (search_ptr != NULL && size > GET_SIZE(HDRP(search_ptr))) {
        insert_ptr = search_ptr;
        search_ptr = NEXT_CLS(search_ptr);
    }

    if (search_ptr && insert_ptr) {
        // ... -> insert_ptr -> (在此插入 ptr) -> search_ptr -> ...
        SET_PTR(NEXT_CLSP(ptr), search_ptr);
        SET_PTR(PREV_CLSP(search_ptr), ptr);
        SET_PTR(PREV_CLSP(ptr), insert_ptr);
        SET_PTR(NEXT_CLSP(insert_ptr), ptr);
    } else if (search_ptr && !insert_ptr) {
        // NULL -> (在此插入 ptr) -> search_ptr -> ...
        SET_PTR(NEXT_CLSP(ptr), search_ptr);
        SET_PTR(PREV_CLSP(search_ptr), ptr);
        SET_PTR(PREV_CLSP(ptr), NULL);
        segregated_free_lists[list_index] = ptr;
    } else if (!search_ptr && insert_ptr) {
        // ... -> insert_ptr -> (在此插入 ptr) -> NULL
        SET_PTR(NEXT_CLSP(ptr), NULL);
        SET_PTR(PREV_CLSP(ptr), insert_ptr);
        SET_PTR(NEXT_CLSP(insert_ptr), ptr);
    } else if (!search_ptr && !insert_ptr) {
        // NULL -> (在此插入 ptr) -> NULL
        // 该大小类链表为空，这是第一次插入节点
        SET_PTR(NEXT_CLSP(ptr), NULL);
        SET_PTR(PREV_CLSP(ptr), NULL);
        segregated_free_lists[list_index] = ptr;
    }
}

static void delete_node(void *ptr) {
    int list_index = 0;
    size_t size = GET_SIZE(HDRP(ptr));

    // 通过块大小找到对应的大小类所在的链位置
    while ((list_index < LISTMAX - 1) && (size > 1)) {
        size >>= 1;
        list_index++;
    }

    if (NEXT_CLS(ptr) && PREV_CLS(ptr)) {
        // ... -> ptr -> ...
        SET_PTR(PREV_CLSP(NEXT_CLS(ptr)), PREV_CLS(ptr));
        SET_PTR(NEXT_CLSP(PREV_CLS(ptr)), NEXT_CLS(ptr));
    } else if (NEXT_CLS(ptr) && !PREV_CLS(ptr)) {
        // NULL -> ptr -> ...
        SET_PTR(PREV_CLSP(NEXT_CLS(ptr)), NULL);
        segregated_free_lists[list_index] = NEXT_CLS(ptr);
    } else if (!NEXT_CLS(ptr) && PREV_CLS(ptr)) {
        // ... -> ptr -> NULL
        SET_PTR(NEXT_CLSP(PREV_CLS(ptr)), NULL);
    } else if (!NEXT_CLS(ptr) && !PREV_CLS(ptr)) {
        // NULL -> ptr -> NULL
        segregated_free_lists[list_index] = NULL;
    }
}

static void *coalesce(void *ptr) {
    size_t prev_alloc = GET_ALLOC(HDRP(PREV_BLKP(ptr)));
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));
    size_t size = GET_SIZE(HDRP(ptr));

    if (prev_alloc && next_alloc) {
        // 前后都是已分配的，直接返回
        return ptr;
    } else if (prev_alloc && !next_alloc) {
        // 后边的是空闲块，需要合并
        delete_node(ptr);
        delete_node(NEXT_BLKP(ptr));
        size += GET_SIZE(HDRP(NEXT_BLKP(ptr)));
        PUT(HDRP(ptr), PACK(size, 0));
        PUT(FTRP(ptr), PACK(size, 0));
    } else if (!prev_alloc && next_alloc) {
        // 前边的是空闲块，需要合并
        delete_node(ptr);
        delete_node(PREV_BLKP(ptr));
        size += GET_SIZE(HDRP(PREV_BLKP(ptr)));
        PUT(FTRP(ptr), PACK(size, 0));
        PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
        ptr = PREV_BLKP(ptr);
    } else {
        // 两侧都是空闲块，需要合并
        delete_node(ptr);
        delete_node(PREV_BLKP(ptr));
        delete_node(NEXT_BLKP(ptr));
        size += GET_SIZE(HDRP(PREV_BLKP(ptr))) +
                GET_SIZE(HDRP(NEXT_BLKP(ptr)));
        PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
        PUT(FTRP(NEXT_BLKP(ptr)), PACK(size, 0));
        ptr = PREV_BLKP(ptr);
    }

    insert_node(ptr, size);

    return ptr;
}

static void *place(void *ptr, size_t size) {
    size_t total_size = GET_SIZE(HDRP(ptr));
    size_t redundant_size = total_size - size;
    size_t critical_size = 96;   // 用于减少外部碎片的临界大小，可以适当调整

    delete_node(ptr);

    if (redundant_size < DSIZE * 2) {
        // 剩余大小小于对齐字节，不做分割
        PUT(HDRP(ptr), PACK(total_size, 1));
        PUT(FTRP(ptr), PACK(total_size, 1));

        return ptr;
    } else if (size >= critical_size) {
        // 分割空闲的 ptr 块：前半部分不使用，后半部分用于装载 size
        PUT(HDRP(ptr), PACK(redundant_size, 0));
        PUT(FTRP(ptr), PACK(redundant_size, 0));
        PUT(HDRP(NEXT_BLKP(ptr)), PACK(size, 1));
        PUT(FTRP(NEXT_BLKP(ptr)), PACK(size, 1));

        insert_node(ptr, redundant_size);

        return NEXT_BLKP(ptr);
    } else {
        // 分割空闲的 ptr 块：前半部分用于装载 size，后半部分不使用
        PUT(HDRP(ptr), PACK(size, 1));
        PUT(FTRP(ptr), PACK(size, 1));
        PUT(HDRP(NEXT_BLKP(ptr)), PACK(redundant_size, 0));
        PUT(FTRP(NEXT_BLKP(ptr)), PACK(redundant_size, 0));

        insert_node(NEXT_BLKP(ptr), redundant_size);

        return ptr;
    }
}

int mm_init(void) {
    char *heap;

    // 初始化分离空闲链表
    for (int i = 0; i < LISTMAX; i++) {
        segregated_free_lists[i] = NULL;
    }

    // 初始化堆，向内存系统请求 4 个字的空间
    if ((heap = mem_sbrk(4 * WSIZE)) == (void *) -1) {
        return -1;
    }

    // 用于对齐的填充字
    PUT(heap, 0);

    // 序言块头部
    PUT(heap + (1 * WSIZE), PACK(DSIZE, 1));
    // 序言块尾部
    PUT(heap + (2 * WSIZE), PACK(DSIZE, 1));

    // 结尾块，只有头部
    PUT(heap + (3 * WSIZE), PACK(0, 1));

    // 1 << 6 为堆的初始大小，可以使内存利用率相对较高
    if (extend_heap(1 << 6) == NULL) {
        return -1;
    }

    return 0;
}

void *mm_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    } else if (size <= DSIZE) {
        size = 2 * DSIZE;
    } else {
        size = ALIGN(size + DSIZE);
    }

    int list_index = 0;
    size_t search_size = size;
    void *ptr = NULL;

    while (list_index < LISTMAX) {
        if (search_size <= 1 && segregated_free_lists[list_index] != NULL) {
            ptr = segregated_free_lists[list_index];
            while (ptr != NULL && size > GET_SIZE(HDRP(ptr))) {
                ptr = NEXT_CLS(ptr);
            }
            if (ptr != NULL) {  // 找到对应的块
                break;
            }
        }

        search_size >>= 1;
        list_index++;
    }

    // 没有找到合适大小的块
    if (ptr == NULL) {
        if ((ptr = extend_heap(MAX(size, CHUNKSIZE))) == NULL) {
            return NULL;
        }
    }

    ptr = place(ptr, size);

    return ptr;
}

void mm_free(void *ptr) {
    size_t size = GET_SIZE(HDRP(ptr));

    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));

    insert_node(ptr, size);
    coalesce(ptr);
}

void *mm_realloc(void *ptr, size_t size) {
    int remain_size;

    if (size == 0) {
        return NULL;
    } else if (size <= DSIZE) {
        size = 2 * DSIZE;
    } else {
        size = ALIGN(size + DSIZE);
    }

    if ((remain_size = GET_SIZE(HDRP(ptr)) - size) >= 0) {
        // 请求的块小于原来的块，则原样返回
        return ptr;
    } else if (!GET_ALLOC(HDRP(NEXT_BLKP(ptr))) ||
               !GET_SIZE(HDRP(NEXT_BLKP(ptr)))) {
        // 检查下一个块是否是空闲块或结束块，以减小外部碎片

        remain_size = GET_SIZE(HDRP(ptr)) +
                      GET_SIZE(HDRP(NEXT_BLKP(ptr))) - size;
        if (remain_size < 0) {
            // 加上后边的块，空间也不够
            size_t extend_size = MAX(-remain_size, CHUNKSIZE);
            if (!extend_heap(extend_size)) {
                return NULL;
            }
            remain_size += extend_size;
        }

        delete_node(NEXT_BLKP(ptr));
        PUT(HDRP(ptr), PACK(size + remain_size, 1));
        PUT(FTRP(ptr), PACK(size + remain_size, 1));
    } else {
        // 申请一个全新的块，复制原来的内容，释放原来的块
        void *new_block = mm_malloc(size);
        memcpy(new_block, ptr, GET_SIZE(HDRP(ptr)));
        mm_free(ptr);

        return new_block;
    }

    return ptr;
}
