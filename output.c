/******************************************************
 * @brief: ���ʵ�ֲ���
 * @birth: �� 2020-12-18 �ɷ����
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#include <stdio.h>
#include <string.h>

#include "money.h"
#include "str_in.h"

/***************************
 * @brief: ���һ�����Ѽ�¼
 * @complexity: O(1)
 ***************************/
inline void OutPutSingle(Expend expend, int n, int n1) {
  if (expend.cost > 500)
    color(RED);
  else if (expend.cost > 100)
    color(YELLOW);
  else
    color(GREEN);
  printf("%-d\t%-d\t%d.%02d.%02d\t%.2lf\t\t%s\n", n, n1, expend.year,
         expend.month, expend.day, expend.cost, expend.usage);
  color(NORMAL);
}

/***************************
 * @brief: ����ض����ڵ��������Ѽ�¼
 * @complexity: O(n)
 ***************************/
void OutPutDay(List *cur, int year, int month, int day) {
  int cnt = 0, num = 0;
  List *tmp;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;
    if (cur->data.year == year && cur->data.month == month &&
        cur->data.day == day) {
      if (!num) {
        color(YELLOW_BLACK), puts("\t���\t����\t����\t��;");
        tmp = cur;
      }

      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) {  // δ��ѯ�����ʱ��������
    printf("��û�м�¼��%d��%d��%d�յĻ��Ѽ�¼��\n\n", year, month, day);
  } else {
    double sum = SumOfDay(tmp, year, month, day);
    if (sum >= 200.0) {
      color(RED_WHITE), puts("�㻨��Ǯ�е��  ��:("), color(NORMAL);
    } else {
      color(GREEN), puts("��Ļ��Ѻ�����: )"), color(NORMAL);
    }

    printf("���뿴������Ļ���ͼ�� (y/n)"), color(YELLOW);
    if (GetYN()) PrintUsageDay(tmp, year, month, day);
  }
}

/***************************
 * @brief: ����ض��µ��������Ѽ�¼
 * @complexity: O(n)
 ***************************/
void OutPutMonth(List *cur, int year, int month) {
  int cnt = 0, num = 0;
  List *tmp;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;
    if (cur->data.year == year && cur->data.month == month) {
      if (!num) {
        color(YELLOW_BLACK), puts("ID\t���\t����\t\t����\t\t��;");
        tmp = cur;
      }
      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) {  //δ��ѯ�����ʱ��������
    printf("��û�м�¼��%d��%d�µĻ��Ѽ�¼��\n\n", year, month);
  } else {
    double sum = SumOfMonth(tmp, year, month);
    if (sum >= 2000.0) {
      color(RED_WHITE), puts("�㻨��Ǯ�е��  ��:("), color(NORMAL);
    } else {
      color(GREEN), puts("��Ļ��Ѻ�����: )"), color(NORMAL);
    }

    printf("���뿴�����µĻ���ͼ�� (y/n)"), color(YELLOW);
    if (GetYN()) {
      PrintUsageMonth(tmp, year, month);
      putchar('\n');
      PrintEachDay(tmp, year, month);
    }
  }
}

/***************************
 * @brief: ����ض�����������Ѽ�¼
 * @complexity: O(n)
 ***************************/
void OutPutYear(List *cur, int year) {
  int cnt = 0, num = 0;
  List *tmp;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;
    if (cur->data.year == year) {
      if (!num) {
        color(YELLOW_BLACK), puts("ID\t���\t����\t\t����\t\t��;");
        tmp = cur;
      }
      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) {  // δ��ѯ�����ʱ��������
    printf("��û�м�¼��%d��Ļ��Ѽ�¼��\n\n", year);
  } else {
    double sum = SumOfYear(tmp, year);
    if (sum >= 20000.0) {
      color(RED_WHITE), puts("�㻨��Ǯ�е��  ��:("), color(NORMAL);
    } else {
      color(GREEN), puts("��Ļ��Ѻ�����: )"), color(NORMAL);
    }
    printf("���뿴������Ļ���ͼ�� (y/n)"), color(YELLOW);
    if (GetYN()) {
      PrintUsageYear(tmp, year);
      putchar('\n');
      PrintEachMonth(tmp, year);
    }
  }
  return;
}

/***************************
 * @brief: ����ض������������Ѽ�¼
 * @complexity: O(n)
 ***************************/
void SearchByCost(List *cur, double cost) {
  int cnt = 0, num = 0;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;

    if (cur->data.cost == cost) {
      if (!num) color(YELLOW_BLACK), puts("ID\t���\t����\t\t����\t\t��;");
      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) printf("��û�м�¼����Ϊ%.2lf�ļ�¼��\n\n", cost);
}

/***************************
 * @brief: ����ض���;���������Ѽ�¼
 * @complexity: O(n)
 ***************************/
void SearchByUse(List *cur, char use[]) {
  int cnt = 0, num = 0;
  double sum = 0.0;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;

    if (strcmp(cur->data.usage, use) == 0) {
      if (!num) color(YELLOW_BLACK), puts("ID\t���\t����\t\t����\t\t��;");
      OutPutSingle(cur->data, cnt, ++num);

      sum += cur->data.cost;
    }
  }

  if (!num) {  // δ��ѯ�����ʱ��������
    printf("��û�м�¼��;Ϊ%s�Ļ��Ѽ�¼��\n", use);
  } else {
    if (sum >= 400.0) {
      color(RED_WHITE), puts("�㻨��Ǯ�е��  ��:("), color(NORMAL);
    } else {
      color(GREEN), puts("��Ļ��Ѻ�����: )"), color(NORMAL);
    }
  }
}
