/******************************************************
 * @brief: ��ɫ���Ʋ���
 * @birth: �� 2020-01-04 �ɷ����
 * @revision: �� 2021-01-07 ����������޸�
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
