/******************************************************
 * @brief: 颜色控制部分
 * @birth: 在 2020-01-04 由范宇创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include <stdio.h>
#include <windows.h>

#include "str_in.h"

void color(int x) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void putskg(int i) {
  color(NORMAL);
  while (i--) putchar(' ');
}
