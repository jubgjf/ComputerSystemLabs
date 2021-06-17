#include <stdio.h>

/**
 * 初始化虚拟内存管理
 *
 * @return 一切正常则返回 0，否则返回 -1
 */
extern int mm_init(void);

/**
 * 通过增加 brk 指针来分配一个新块，块大小双字向上对齐
 *
 * @param size 待分配大小
 * @return 返回块指针
 */
extern void *mm_malloc(size_t size);

/**
 * 释放 ptr 块
 *
 * @param ptr 块指针
 */
extern void mm_free(void *ptr);

/**
 * 调整已分配块的大小
 *
 * @param ptr 块指针
 * @param size 调整后的块大小
 * @return 返回调整后的块指针
 */
extern void *mm_realloc(void *ptr, size_t size);


/* 
 * Students work in teams of one or two.  Teams enter their team name, 
 * personal names and login IDs in a struct of this
 * type in their bits.c file.
 */
typedef struct {
    char *teamname; /* ID1+ID2 or ID1 */
    char *name1;    /* full name of first member */
    char *id1;      /* login ID of first member */
    char *name2;    /* full name of second member (if any) */
    char *id2;      /* login ID of second member */
} team_t;

extern team_t team;

