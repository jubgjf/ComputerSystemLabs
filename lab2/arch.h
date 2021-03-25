#ifndef COMPUTERSYSTEMLABS_ARCH_H
#define COMPUTERSYSTEMLABS_ARCH_H

/**
 * 输出Windows 32位下各个数据类型所占字节数
 */
void win_x86();

/**
 * 输出Windows 64位下各个数据类型所占字节数
 */
void win_x64();

/**
 * 输出Linux 32位下各个数据类型所占字节数
 */
void linux_32();

/**
 * 输出Linux 64位下各个数据类型所占字节数
 */
void linux_64();

/**
 * 依次调用调用win_x86、win_x64、linux_32、linux_64
 */
void print_archs();

#endif //COMPUTERSYSTEMLABS_ARCH_H
