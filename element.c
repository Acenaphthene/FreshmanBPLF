/******************************************************
 * @brief: 元素插入、删除和修改的实现部分
 * @birth: 在 2020-12-18 由陈思同创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "money.h"
#include "str_in.h"

/***************************
 * @brief: 逐层比较，若 a < b 则返回真
 * @complexity: O(1)
 ***************************/
static bool cmp(Expend a, Expend b) {
  if (a.year > b.year) return false;
  if (a.year == b.year) {
    if (a.month > b.month) return false;
    if (a.month == b.month) {
      if (a.day > b.day) return false;
      if (a.day == b.day) {
        return a.cost < b.cost;
      }
    }
  }
  return true;
}
/***************************
 * @brief: 通过cmp函数找到插入位置并插入
 * @complexity: O(n)
 ***************************/
void Insert(Expend expend) {
  List *target = (List *)malloc(sizeof(List)), *cur = head;

  while (cur->next != NULL && !cmp(expend, cur->next->data)) cur = cur->next;

  target->data = expend;
  target->next = cur->next;
  cur->next = target;

  ++current_cnt;
}

/***************************
 * @brief: 按照时间排序找到所需删除项并执行操作
 * @complexity: O(n)
 ***************************/
void Delete(int id) {
  List *cur = head, *tmp;
  int cnt = 0;

  while (++cnt != id) cur = cur->next;

  tmp = cur->next;

  printf("编号为%d的数据如下：\n");
  puts("ID\t序号\t日期\t\t花费\t\t用途");
  OutPutSingle(tmp->data, id, 1);

  printf("你确定要删除这一条数据吗？(y/n)：");
  if (GetYN()) {
    cur->next = tmp->next;
    free(tmp);
    --current_cnt;
  }
}
/***************************
 * @brief: 按照时间排序找到所需修改项并执行操作
 * @complexity: O(n)
 ***************************/
void Revise(int id) {
  List *cur = head, *tmp;
  int cnt = 0;

  while (++cnt != id) cur = cur->next;

  tmp = cur->next;

  printf("编号为%d的数据如下：\n");
  OutPutSingle(tmp->data, id, 1);

  printf("你确定要修改这一条数据吗？(y/n)：");
  if (GetYN()) {
    system("cls");

    printf("请输入花费金额（如114514）：");
    tmp->data.cost = GetMoney();

    printf("\n请输入花费途径（如：收购UESTC）：");
    GetUsage(tmp->data.usage);
  }
}
