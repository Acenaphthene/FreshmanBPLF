/******************************************************
 * @brief: 主函数实现部分
 * @birth: 在 2021-01-04 由舒适创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include "str_in.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/***************************
 * @brief: 利用fgets读入一行到字符流中
 * @complexity: O(n)
 ***************************/
void SstreamInit(Sstream *target) {
  while (1) {
    do {
      fgets(target->str, 256, stdin);
      for (target->cur = 0; target->str[target->cur] == ' '; ++target->cur)
        continue;
    } while ((target->end = strlen(target->str)) - target->cur == 1);
    if (target->str[--target->end] != '\n') {
      printf("错误：输入过长，请重新输入：");
      while (getchar() != '\n') continue;
      continue;
    } else {
      target->str[target->end] = '\0';
      break;
    }
  }
}
/***************************
 * @brief: 遍历字符流剩余内容，找到第一个非空格字符
 * @complexity: O(n)
 ***************************/
bool seof(Sstream *sstr) {
  while (sstr->str[sstr->cur] == ' ') ++sstr->cur;
  return sstr->cur == sstr->end;
}

/***************************
 * @brief: 利用isdigit判定并读入整数
 * @complexity: O(1)
 ***************************/
bool SstreamInt(int *target, Sstream *sstr) {
  int f = 1;
  if (seof(sstr)) return false;
  *target = 0;
  if (sstr->str[sstr->cur] == '-') f = -1, ++sstr->cur;
  while (isdigit(sstr->str[sstr->cur])) {
    *target = *target * 10 + sstr->str[sstr->cur] - '0';
    ++sstr->cur;
  }
  *target *= f;
  return (sstr->str[sstr->cur] != ' ' && sstr->cur != sstr->end) ? false : true;
}
/***************************
 * @brief: 利用isdigit判定并读入一个最多2位小数的正实数
 * @complexity: O(1)
 ***************************/
bool SstreamMoney(double *target, Sstream *sstr) {
  if (seof(sstr)) return false;
  *target = 0.0;
  while (isdigit(sstr->str[sstr->cur])) {
    *target = (*target) * 10.0 + (double)(sstr->str[sstr->cur] - '0');
    ++sstr->cur;
  }
  if (sstr->str[sstr->cur] == '.') {
    if (isdigit(sstr->str[++sstr->cur]))
      *target += (double)sstr->str[sstr->cur] / 10.0;
    if (isdigit(sstr->str[++sstr->cur]))
      *target += (double)sstr->str[sstr->cur] / 100.0;
    if (isdigit(sstr->str[++sstr->cur])) return false;
  }
  return (sstr->str[sstr->cur] != ' ' && sstr->cur != sstr->end) ? false : true;
}
/***************************
 * @brief: 通过判定空格输入一个不含空格的字符串
 * @complexity: O(n)
 ***************************/
bool SstreamStr(char *target, Sstream *sstr) {
  if (seof(sstr)) return false;
  sscanf(sstr->str + sstr->cur, "%s", target);
  int char_cnt = strlen(target);
  target[49] = '\0';
  if (char_cnt > 50) return false;
  sstr->cur += char_cnt;
  return true;
}

/***************************
 * @brief: 利用tolower输入y/n判定
 * @complexity: O(1)
 ***************************/
bool GetYN() {
  bool ret;
  while (1) {
    SstreamInit(&strin);
    strin.str[strin.cur] = tolower(strin.str[strin.cur]);
    ret = (strin.str[strin.cur] == 'y') ? true : false;
    if ((!ret && strin.str[strin.cur] != 'n') || (++strin.cur, !seof(&strin)))
      printf("错误：请输入y或n：");
    else
      return ret;
  }
}
/***************************
 * @brief: 利用SstreamInt读入一个整数，并控制其范围
 ***************************/
int GetInt(int l, int r) {
  int ret;
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(&ret, &strin) || !seof(&strin) || ret < l || ret > r) {
      printf("\t\t\t\t错误：请输入一个%d~%d的整数：", l, r);
    } else {
      break;
    }
  }
  return ret;
}
/***************************
 * @brief: 利用SstreamMoney读入一个金额
 ***************************/
double GetMoney() {
  double ret;
  while (1) {
    SstreamInit(&strin);
    if (!SstreamMoney(&ret, &strin) || !seof(&strin)) {
      printf("错误：请输入一个至多2位小数的正实数：");
    } else {
      break;
    }
  }
  return ret;
}

// 平年与闰年每个月的天数
static const int kMonth[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
/***************************
 * @brief: 判断是否为闰年，当为公元前时递归调用一次
 * @param: year：年
 * @complexity: O(1)
 ***************************/
static bool isleap(int year) {
  if (year > 0) {
    if (year % 400 == 0) {
      return true;
    } else if (year % 100 == 0) {
      return false;
    } else if (year % 4 == 0) {
      return true;
    } else {
      return false;
    }
  } else {
    return isleap(year % 400 + 401);
  }
}

/***************************
 * @brief: 利用SstreamInt读入三个整数，并控制其范围
 ***************************/
void GetDay(int *year, int *month, int *day) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(year, &strin) || !SstreamInt(month, &strin) ||
        !SstreamInt(day, &strin) || !seof(&strin)) {
      printf("错误：请输入三个整数：");
    } else if (!*year) {
      printf("错误：年不能为0，请重新输入：");
    } else if (*month < 1 || *month > 12) {
      printf("错误：月为1~12的整数，请重新输入：");
    } else if (*day < 1 || *day > kMonth[isleap(*year)][*month]) {
      printf("错误：该月的日为1~%d的整数，请重新输入：",
             kMonth[isleap(*year)][*month]);
    } else {
      break;
    }
  }
}
/***************************
 * @brief: 利用SstreamInt读入两个整数，并控制其范围
 ***************************/
void GetMonth(int *year, int *month) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(year, &strin) || !SstreamInt(month, &strin) ||
        !seof(&strin)) {
      printf("错误：请输入两个整数：");
    } else if (!*year) {
      printf("错误：年不能为0，请重新输入：");
    } else if (*month < 1 || *month > 12) {
      printf("错误：月为1~12的整数，请重新输入：");
    } else {
      break;
    }
  }
}
/***************************
 * @brief: 利用SstreamInt读入一个整数，并控制其范围
 ***************************/
void GetYear(int *year) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(year, &strin) || !seof(&strin)) {
      printf("错误：请输入一个整数：");
    } else if (!*year) {
      printf("错误：年不能为0，请重新输入：");
    } else {
      break;
    }
  }
}

/***************************
 * @brief: 利用SstreamStr读入一个不带空格的字符串
 ***************************/
void GetUsage(char *usage) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamStr(usage, &strin)) {
      printf("错误：用途过长，请重新输入：");
    } else if (!seof(&strin)) {
      printf("错误：用途不能有空格，请重新输入：");
    } else {
      break;
    }
  }
}