/******************************************************
 * @brief: 输出实现部分
 * @birth: 在 2020-12-18 由范宇创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include <stdio.h>
#include <string.h>

#include "money.h"
#include "str_in.h"

/***************************
 * @brief: 输出一条消费记录
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
 * @brief: 输出特定日期的所有消费记录
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
        color(YELLOW_BLACK), puts("\t序号\t日期\t花费\t用途");
        tmp = cur;
      }

      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) {  // 未查询到结果时的输出结果
    printf("你没有记录在%d年%d月%d日的花费记录。\n\n", year, month, day);
  } else {
    double sum = SumOfDay(tmp, year, month, day);
    if (sum >= 200.0) {
      color(RED_WHITE), puts("你花的钱有点多  ！:("), color(NORMAL);
    } else {
      color(GREEN), puts("你的花费很正常: )"), color(NORMAL);
    }

    printf("你想看看这天的花费图吗 (y/n)"), color(YELLOW);
    if (GetYN()) PrintUsageDay(tmp, year, month, day);
  }
}

/***************************
 * @brief: 输出特定月的所有消费记录
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
        color(YELLOW_BLACK), puts("ID\t序号\t日期\t\t花费\t\t用途");
        tmp = cur;
      }
      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) {  //未查询到结果时的输出结果
    printf("你没有记录在%d年%d月的花费记录。\n\n", year, month);
  } else {
    double sum = SumOfMonth(tmp, year, month);
    if (sum >= 2000.0) {
      color(RED_WHITE), puts("你花的钱有点多  ！:("), color(NORMAL);
    } else {
      color(GREEN), puts("你的花费很正常: )"), color(NORMAL);
    }

    printf("你想看看这月的花费图吗 (y/n)"), color(YELLOW);
    if (GetYN()) {
      PrintUsageMonth(tmp, year, month);
      putchar('\n');
      PrintEachDay(tmp, year, month);
    }
  }
}

/***************************
 * @brief: 输出特定年的所有消费记录
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
        color(YELLOW_BLACK), puts("ID\t序号\t日期\t\t花费\t\t用途");
        tmp = cur;
      }
      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) {  // 未查询到结果时的输出结果
    printf("你没有记录在%d年的花费记录。\n\n", year);
  } else {
    double sum = SumOfYear(tmp, year);
    if (sum >= 20000.0) {
      color(RED_WHITE), puts("你花的钱有点多  ！:("), color(NORMAL);
    } else {
      color(GREEN), puts("你的花费很正常: )"), color(NORMAL);
    }
    printf("你想看看这年的花费图吗 (y/n)"), color(YELLOW);
    if (GetYN()) {
      PrintUsageYear(tmp, year);
      putchar('\n');
      PrintEachMonth(tmp, year);
    }
  }
  return;
}

/***************************
 * @brief: 输出特定金额的所有消费记录
 * @complexity: O(n)
 ***************************/
void SearchByCost(List *cur, double cost) {
  int cnt = 0, num = 0;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;

    if (cur->data.cost == cost) {
      if (!num) color(YELLOW_BLACK), puts("ID\t序号\t日期\t\t花费\t\t用途");
      OutPutSingle(cur->data, cnt, ++num);
    }
  }

  if (!num) printf("你没有记录花费为%.2lf的记录。\n\n", cost);
}

/***************************
 * @brief: 输出特定用途的所有消费记录
 * @complexity: O(n)
 ***************************/
void SearchByUse(List *cur, char use[]) {
  int cnt = 0, num = 0;
  double sum = 0.0;

  while (cur->next != NULL) {
    cur = cur->next;
    ++cnt;

    if (strcmp(cur->data.usage, use) == 0) {
      if (!num) color(YELLOW_BLACK), puts("ID\t序号\t日期\t\t花费\t\t用途");
      OutPutSingle(cur->data, cnt, ++num);

      sum += cur->data.cost;
    }
  }

  if (!num) {  // 未查询到结果时的输出结果
    printf("你没有记录用途为%s的花费记录。\n", use);
  } else {
    if (sum >= 400.0) {
      color(RED_WHITE), puts("你花的钱有点多  ！:("), color(NORMAL);
    } else {
      color(GREEN), puts("你的花费很正常: )"), color(NORMAL);
    }
  }
}
