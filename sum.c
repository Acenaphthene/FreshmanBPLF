/******************************************************
 * @brief: 求和等实现部分
 * @birth: 在 2020-12-18 由刘子阳创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include <stdio.h>
#include <string.h>

#include "money.h"
#include "str_in.h"

/***************************
 * @brief: 遍历链表求特定日期特定用途的消费总和
 * @complexity: O(n)
 ***************************/
double SumOfUseDay(List *cur, int year, int month, int day, char use[]) {
  double sum = 0;

  while (cur != NULL) {
    if (strcmp(cur->data.usage, use) == 0 &&
        (cur->data.year == year && cur->data.month == month &&
         cur->data.day == day))
      sum += cur->data.cost;

    cur = cur->next;
  }

  return sum;
}
/***************************
 * @brief: 遍历链表求特定月特定用途的消费总和
 * @complexity: O(n)
 ***************************/
double SumOfUseMonth(List *cur, int year, int month, char use[]) {
  double sum = 0;

  while (cur != NULL) {
    if (strcmp(cur->data.usage, use) == 0 &&
        (cur->data.year == year && cur->data.month == month))
      sum += cur->data.cost;

    cur = cur->next;
  }

  return sum;
}
/***************************
 * @brief: 遍历链表求特定年特定用途的消费总和
 * @complexity: O(n)
 ***************************/
double SumOfUseYear(List *cur, int year, char use[]) {
  double sum = 0;

  while (cur != NULL) {
    if (strcmp(cur->data.usage, use) == 0 && (cur->data.year == year))
      sum += cur->data.cost;

    cur = cur->next;
  }

  return sum;
}

// 用于排序
typedef struct {
  char usage[50];
  double sum;
} Sum_usage;

/***************************
 * @brief: 遍历链表求特定日期的消费总和
 * @complexity: O(n)
 ***************************/
double SumOfDay(List *cur, int year, int month, int day) {
  double sum = 0;

  while (cur != NULL) {
    if (cur->data.month == month && cur->data.day == day &&
        cur->data.year == year)
      sum += (cur->data.cost);

    cur = cur->next;
  }
  return sum;
}
/***************************
 * @brief: 遍历链表求特定月的消费总和
 * @complexity: O(n)
 ***************************/
double SumOfMonth(List *cur, int year, int month) {
  double sum = 0;

  while (cur != NULL) {
    if (cur->data.month == month && cur->data.year == year)
      sum += (cur->data.cost);

    cur = cur->next;
  }

  return sum;
}
/***************************
 * @brief: 遍历链表求特定年的消费总和
 * @complexity: O(n)
 ***************************/
double SumOfYear(List *cur, int year) {
  double sum = 0;

  while (cur != NULL) {
    if (cur->data.year == year) sum += (cur->data.cost);

    cur = cur->next;
  }

  return sum;
}

/***************************
 * @brief: 遍历已求的月的消费总和输出条形图
 * @complexity: O(n)
 ***************************/
void PrintEachMonth(List *cur, int year) {
  double sums[12];
  for (int i = 0; i < 12;) sums[i] = SumOfMonth(cur, year, ++i);

  color(YELLOW), printf("\n--------------");
  color(YELLOW_BLACK), printf("%4d年每月消费", year);
  color(YELLOW), puts("---------------\n");
  color(NORMAL);

  for (int j = 0; j < 12; ++j) {
    printf("第%2d月|", j + 1);

    if (sums[j]) {
      for (int o = 0; o <= sums[j]; o += 200) {
        printf("█");

        if (o > 3500) {
          printf(" ...");
          break;
        }
      }
    }

    printf(" %.2lf元\n", sums[j]);
  }

  color(YELLOW), puts("------------------------------------------\n");
}
/***************************
 * @brief: 遍历已求的天的消费总和输出条形图
 * @complexity: O(n)
 ***************************/
void PrintEachDay(List *cur, int year, int month) {
  double sums[31];
  for (int i = 0; i < 31;) sums[i] = SumOfDay(cur, year, month, ++i);

  color(YELLOW), printf("\n-----------");
  color(YELLOW_BLACK), printf("%d年%2d月每日消费", year, month);
  color(YELLOW), puts("--------------");
  color(NORMAL);

  for (int j = 0; j < 31; ++j) {
    if (sums[j] > 0) {
      printf("%2d月%2d日|", month, j + 1);

      if (sums[j]) {
        for (int o = 0; o <= sums[j]; o += 10) {
          printf("█");

          if (o > 400) {
            printf(" ...");
            break;
          }
        }
      }

      printf(" %.2lf元\n", sums[j]);
    }
  }

  color(YELLOW), puts("------------------------------------------");
}

/***************************
 * @brief: 通过中间变量交换两个变量
 * @complexity: O(1)
 ***************************/
void swap(Sum_usage *x, Sum_usage *y) {
  Sum_usage t = *x;
  *x = *y;
  *y = t;
}
/***************************
 * @brief: 利用类选择排序算法求出前几个消费种类
 * @complexity: O(n^2)
 ***************************/
void SelectionSort(Sum_usage arr[], int len, int Max) {
  for (int i = 0, maxx; i < len - 1; ++i) {
    maxx = i;
    for (int j = i + 1; j < Max; ++j)
      if (arr[j].sum > arr[maxx].sum) maxx = j;
    swap(&arr[maxx], &arr[i]);
  }
}
/***************************
 * @brief: 遍历数组判断有无重名
 * @complexity: O(n)
 ***************************/
bool NoExist(Sum_usage s[], int i, char usage[]) {
  for (int j = 0; j <= i; ++j)
    if (strcmp(s[j].usage, usage) == 0) return false;

  return true;
}

/***************************
 * @brief: 遍历数组输出特定日期的所有用途
 ***************************/
void PrintUsageDay(List *cur, int year, int month, int day) {
  Sum_usage usagelist[99];
  int i, s = 0;

  for (i = 0; cur != NULL && i < 99; cur = cur->next) {
    if (cur->data.year == year && cur->data.month == month &&
        cur->data.day == day && NoExist(usagelist, i, cur->data.usage)) {
      strcpy(usagelist[i].usage, cur->data.usage);
      usagelist[i].sum =
          SumOfUseDay(head, year, month, day, usagelist[i].usage);
      ++i;
    }
  }

  if (i > 15) {
    printf(
        "需要查看的消费数目过多（共%d条），是否只按照降序显示排行较前的消费？\n"
        "是请输入查看的数量（1~%d），若仍全部查看请输入0:",
        i, i);
    s = GetInt(0, i);
  }
  if (!s) s = i;
  SelectionSort(usagelist, s + 1, i);

  color(YELLOW), printf("\n---------");
  color(YELLOW_BLACK), printf("%d年%2d月%2d日消费用途", year, month, day);
  color(YELLOW), puts("------------");
  color(NORMAL);

  for (int j = 0; j < s; ++j) {
    printf("%-13s|", usagelist[j].usage);

    for (double o = 0.0; o <= usagelist[j].sum; o += 20.0) {
      printf("█");

      if (o > 800) {
        printf(" ...");
        break;
      }
    }

    printf(" %.2lf元\n", usagelist[j].sum);
  }

  color(YELLOW), puts("------------------------------------------");
}
/***************************
 * @brief: 遍历数组输出特定月的所有用途
 * @complexity: O(n)
 ***************************/
void PrintUsageMonth(List *cur, int year, int month) {
  Sum_usage usagelist[999];
  int i, s = 0;

  for (i = 0; cur != NULL && i < 3999; cur = cur->next) {
    if (cur->data.year == year && cur->data.month == month &&
        NoExist(usagelist, i, cur->data.usage)) {
      strcpy(usagelist[i].usage, cur->data.usage);
      usagelist[i].sum = SumOfUseMonth(head, year, month, usagelist[i].usage);
      ++i;
    }
  }

  if (i > 15) {
    printf(
        "需要查看的消费数目过多，是否只按照降序显示排行较前的消费？\n"
        "是请输入查看的数量（1-%d），若仍全部查看请输入0:",
        i);
    s = GetInt(0, i);
  }
  if (!s) s = i;
  SelectionSort(usagelist, s + 1, i);

  color(YELLOW), printf("\n-----------");
  color(YELLOW_BLACK), printf("%d年%2d月消费用途", year, month);
  color(YELLOW), puts("---------------");
  color(NORMAL);

  for (int j = 0; j < s; ++j) {
    printf("%-13s|", usagelist[j].usage);

    for (int o = 0.0; o <= usagelist[j].sum; o += 50.0) {
      printf("█");

      if (o > 4000) {
        printf(" ...");
        break;
      }
    }

    printf(" %.2lf元\n", usagelist[j].sum);
  }

  color(YELLOW), puts("------------------------------------------");
}
/***************************
 * @brief: 遍历数组输出特定年的所有用途
 * @complexity: O(n)
 ***************************/
void PrintUsageYear(List *cur, int year) {
  Sum_usage usagelist[9999];
  int i, s = 0;
  for (i = 0; cur != NULL && i < 9999; cur = cur->next) {
    if (cur->data.year == year && NoExist(usagelist, i, cur->data.usage)) {
      strcpy(usagelist[i].usage, cur->data.usage);
      usagelist[i].sum = SumOfUseYear(head, year, usagelist[i].usage);
      i++;
    }
  }
  if (i > 15) {
    printf(
        "需要查看的消费数目过多，是否只按照降序显示排行较前的消费？\n"
        "是请输入查看的数量（1-%d），若仍全部查看请输入0:",
        i);
    s = GetInt(0, i);
  }
  if (!s) s = i;
  SelectionSort(usagelist, s + 1, i);

  color(YELLOW), printf("\n---------------");
  color(YELLOW_BLACK), printf("%d年消费用途", year);
  color(YELLOW), puts("------------------");
  color(NORMAL);

  for (int j = 0; j < s; ++j) {
    printf("%-13s|", usagelist[j].usage);

    for (int o = 0; o <= usagelist[j].sum; o += 100) {
      printf("█");

      if (o > 4000) {
        printf(" ...");
        break;
      }
    }

    printf(" %.2lf元\n", usagelist[j].sum);
  }

  color(YELLOW), puts("-------------------------------------------");
}
