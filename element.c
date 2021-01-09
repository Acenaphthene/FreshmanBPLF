/******************************************************
 * @brief: Ԫ�ز��롢ɾ�����޸ĵ�ʵ�ֲ���
 * @birth: �� 2020-12-18 �ɳ�˼ͬ����
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "money.h"
#include "str_in.h"

/***************************
 * @brief: ���Ƚϣ��� a < b �򷵻���
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
 * @brief: ͨ��cmp�����ҵ�����λ�ò�����
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
 * @brief: ����ʱ�������ҵ�����ɾ���ִ�в���
 * @complexity: O(n)
 ***************************/
void Delete(int id) {
  List *cur = head, *tmp;
  int cnt = 0;

  while (++cnt != id) cur = cur->next;

  tmp = cur->next;

  printf("���Ϊ%d���������£�\n");
  puts("ID\t���\t����\t\t����\t\t��;");
  OutPutSingle(tmp->data, id, 1);

  printf("��ȷ��Ҫɾ����һ��������(y/n)��");
  if (GetYN()) {
    cur->next = tmp->next;
    free(tmp);
    --current_cnt;
  }
}
/***************************
 * @brief: ����ʱ�������ҵ������޸��ִ�в���
 * @complexity: O(n)
 ***************************/
void Revise(int id) {
  List *cur = head, *tmp;
  int cnt = 0;

  while (++cnt != id) cur = cur->next;

  tmp = cur->next;

  printf("���Ϊ%d���������£�\n");
  OutPutSingle(tmp->data, id, 1);

  printf("��ȷ��Ҫ�޸���һ��������(y/n)��");
  if (GetYN()) {
    system("cls");

    printf("�����뻨�ѽ���114514����");
    tmp->data.cost = GetMoney();

    printf("\n�����뻨��;�����磺�չ�UESTC����");
    GetUsage(tmp->data.usage);
  }
}
