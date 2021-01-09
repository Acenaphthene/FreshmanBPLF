/******************************************************
 * @brief: �ļ���������
 * @birth: �� 2021-01-03 �����ʴ���
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "money.h"

static const char *kFile = "data.bin";  // �浵�ļ���

/***************************
 * @brief: ����fopen��fread�Ӵ浵�ļ���������
 * @complexity: O(n)
 ***************************/
void InitFromFile(List **L) {
  FILE *fin;
  List *cur;

  *L = (List *)malloc(sizeof(List));
  if (*L == NULL) {
    puts("����ͷը�ѣ������˳�...\n");
    system("pause");
    exit(EXIT_FAILURE);
  }
  cur = *L;

  if ((fin = fopen(kFile, "r")) != NULL) {
    fread(&current_cnt, sizeof(current_cnt), 1, fin);
    int cnt = 0;

    while (++cnt <= current_cnt) {
      if ((cur->next = (List *)malloc(sizeof(List))) == NULL) {
        puts("����ڵ�ը�ѣ���ȡ����\n");
        break;
      }

      cur = cur->next;
      fread(&(cur->data), sizeof(Expend), 1, fin);
    }

    printf("���Ѽ�¼�Ѷ�ȡ������%u����¼��\n\n", current_cnt);
    system("pause");
  }
  cur->next = NULL;

  fclose(fin);
}

/***************************
 * @brief: ����fopen��fwrite��浵�ļ�д������
 * @complexity: O(n)
 ***************************/
void SaveToFile(List *L) {
  FILE *fout;

  if ((fout = fopen(kFile, "w")) == NULL) {
    puts("�����浵ը�ѣ��޷�����");
  } else {
    fwrite(&current_cnt, sizeof(current_cnt), 1, fout);
    int cnt = 0;

    while (++cnt <= current_cnt) {
      L = L->next;
      fwrite(&(L->data), sizeof(Expend), 1, fout);
    }

    printf("%u����¼�ѱ���\n\n", current_cnt);

    fclose(fout);
  }
  //  ClearData(head);
  return;
}

/***************************
 * @brief: ��������ɾ��ÿ�����
 * @complexity: O(n)
 ***************************/
void ClearData(List *L) {
  List *tmp;

  while (L->next) {
    tmp = L->next;
    L->next = tmp->next;
    free(tmp);
  }
  current_cnt = 0U;

  puts("�������ǰ��ȡ�ļ�¼\n");
}

/***************************
 * @brief: ����remove�Ƴ��浵�ļ�
 * @complexity: O(1)
 ***************************/
void DestroyFile() {
  remove(kFile);

  FILE *fin;
  if ((fin = fopen(kFile, "r")) == NULL)
    puts("�浵�ļ����Ƴ�\n");
  else
    printf("�浵�ļ��Ƴ�ʧ�ܣ����ֶ�ɾ��%s\n\n", kFile);
}
