#ifndef COMPUTERSYSTEMLABS_XTOY_H
#define COMPUTERSYSTEMLABS_XTOY_H

/**
 * 字符串转整数
 * @param str 字符串
 * @return 返回对应的整数
 */
int cs_atoi(char *str);

/**
 * 字符串转浮点数
 * @param str 字符串
 * @return 返回对应的浮点数
 */
float cs_atof(char *str);

/**
 * 整数转字符串
 * @param num 整数
 * @return 对应的字符串
 */
char *cs_itoa(int num);

/**
 * 浮点数转字符串
 * @param num 浮点数
 * @return 对应的字符串
 */
char *cs_ftoa(float num);

#endif //COMPUTERSYSTEMLABS_XTOY_H
