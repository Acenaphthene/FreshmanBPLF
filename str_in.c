/******************************************************
 * @brief: ������ʵ�ֲ���
 * @birth: �� 2021-01-04 �����ʴ���
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#include "str_in.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/***************************
 * @brief: ����fgets����һ�е��ַ�����
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
      printf("����������������������룺");
      while (getchar() != '\n') continue;
      continue;
    } else {
      target->str[target->end] = '\0';
      break;
    }
  }
}
/***************************
 * @brief: �����ַ���ʣ�����ݣ��ҵ���һ���ǿո��ַ�
 * @complexity: O(n)
 ***************************/
bool seof(Sstream *sstr) {
  while (sstr->str[sstr->cur] == ' ') ++sstr->cur;
  return sstr->cur == sstr->end;
}

/***************************
 * @brief: ����isdigit�ж�����������
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
 * @brief: ����isdigit�ж�������һ�����2λС������ʵ��
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
 * @brief: ͨ���ж��ո�����һ�������ո���ַ���
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
 * @brief: ����tolower����y/n�ж�
 * @complexity: O(1)
 ***************************/
bool GetYN() {
  bool ret;
  while (1) {
    SstreamInit(&strin);
    strin.str[strin.cur] = tolower(strin.str[strin.cur]);
    ret = (strin.str[strin.cur] == 'y') ? true : false;
    if ((!ret && strin.str[strin.cur] != 'n') || (++strin.cur, !seof(&strin)))
      printf("����������y��n��");
    else
      return ret;
  }
}
/***************************
 * @brief: ����SstreamInt����һ���������������䷶Χ
 ***************************/
int GetInt(int l, int r) {
  int ret;
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(&ret, &strin) || !seof(&strin) || ret < l || ret > r) {
      printf("\t\t\t\t����������һ��%d~%d��������", l, r);
    } else {
      break;
    }
  }
  return ret;
}
/***************************
 * @brief: ����SstreamMoney����һ�����
 ***************************/
double GetMoney() {
  double ret;
  while (1) {
    SstreamInit(&strin);
    if (!SstreamMoney(&ret, &strin) || !seof(&strin)) {
      printf("����������һ������2λС������ʵ����");
    } else {
      break;
    }
  }
  return ret;
}

// ƽ��������ÿ���µ�����
static const int kMonth[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
/***************************
 * @brief: �ж��Ƿ�Ϊ���꣬��Ϊ��Ԫǰʱ�ݹ����һ��
 * @param: year����
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
 * @brief: ����SstreamInt���������������������䷶Χ
 ***************************/
void GetDay(int *year, int *month, int *day) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(year, &strin) || !SstreamInt(month, &strin) ||
        !SstreamInt(day, &strin) || !seof(&strin)) {
      printf("��������������������");
    } else if (!*year) {
      printf("�����겻��Ϊ0�����������룺");
    } else if (*month < 1 || *month > 12) {
      printf("������Ϊ1~12�����������������룺");
    } else if (*day < 1 || *day > kMonth[isleap(*year)][*month]) {
      printf("���󣺸��µ���Ϊ1~%d�����������������룺",
             kMonth[isleap(*year)][*month]);
    } else {
      break;
    }
  }
}
/***************************
 * @brief: ����SstreamInt���������������������䷶Χ
 ***************************/
void GetMonth(int *year, int *month) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(year, &strin) || !SstreamInt(month, &strin) ||
        !seof(&strin)) {
      printf("��������������������");
    } else if (!*year) {
      printf("�����겻��Ϊ0�����������룺");
    } else if (*month < 1 || *month > 12) {
      printf("������Ϊ1~12�����������������룺");
    } else {
      break;
    }
  }
}
/***************************
 * @brief: ����SstreamInt����һ���������������䷶Χ
 ***************************/
void GetYear(int *year) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamInt(year, &strin) || !seof(&strin)) {
      printf("����������һ��������");
    } else if (!*year) {
      printf("�����겻��Ϊ0�����������룺");
    } else {
      break;
    }
  }
}

/***************************
 * @brief: ����SstreamStr����һ�������ո���ַ���
 ***************************/
void GetUsage(char *usage) {
  while (true) {
    SstreamInit(&strin);
    if (!SstreamStr(usage, &strin)) {
      printf("������;���������������룺");
    } else if (!seof(&strin)) {
      printf("������;�����пո����������룺");
    } else {
      break;
    }
  }
}