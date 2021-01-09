/******************************************************
 * @brief: ������ʵ�ֲ���
 * @birth: �� 2020-12-18 ������𩴴��
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "money.h"
#include "str_in.h"

unsigned int current_cnt;  // Ԫ�ؼ�����
List *head;                // ����ͷ
Sstream strin;             // Ĭ���ַ�������

int opt, judge;        // �û�����Ĺ��ܱ��
int year, month, day;  // �û������������
char usage[50];        // �û������������;
int cnt;               // ɾ�����Ѽ�¼�ı��
Expend expend;         // �����û��������������Ľṹ��

/***************************
 * @brief: �������������
 * @param: void
 ***************************/
void menu() {
  color(NORMAL), puts("\n\n\n\t\t\t\t=======================================");
  color(YELLOW_BLACK), puts("\t\t\t\t\t   ��ѧ����֧����ϵͳ   ");
  color(NORMAL), puts("\t\t\t\t=======================================\n");

  puts("\t\t\t\t***************************************\n");
  putskg(8), color(WHITE_BLACK), printf("\t\t\t1.��ʾ֧����¼");
  putskg(8), color(WHITE_BLACK), puts("2.����֧����¼\n");

  putskg(8), color(WHITE_BLACK), printf("\t\t\t3.����֧����¼");
  putskg(8), color(WHITE_BLACK), puts("4.�޸���������\n");

  putskg(8), color(WHITE_BLACK), printf("\t\t\t5.ɾ��֧����¼");
  putskg(8), color(WHITE_BLACK), puts("6.����֧���ܺ�\n");

  putskg(8), color(WHITE_BLACK), printf("\t\t\t7.���沢���˳�");
  putskg(8), color(WHITE_BLACK), puts("8.ɾ�������˳�\n");
  color(NORMAL), puts("\t\t\t\t***************************************\n");

  color(LIGHTBLUE), printf("\t\t\t\t��������Ҫʹ�õĹ��ܶ�Ӧ��ţ�");
  color(YELLOW);
}

/***************************
 * @brief: ʵ�ָ�������
 * @param: void
 ***************************/
void Opt1();
void Opt2();
void Opt3();
void Opt4();
void Opt5();
void Opt6();
void Opt7();
void Opt8();

/***************************
 * @brief: ʵ�ֳ���Ĺ���
 * @param: void
 ***************************/
int main() {
  system("cls"), InitFromFile(&head);  // ����ͷ��ʼ��

  while (true) {
    system("cls"), menu();  // ��ӡ�˵������û�������Ӧ���ܱ��

    // ����һ��1~8����������ʾ�û�ѡ��Ĳ���
    opt = GetInt(1, 8);

    switch (opt) {
      case 1: {  // ���� 1�����в���֧����¼����
        Opt1();
        break;
      }
      case 2: {
        Opt2();
        break;
      }
      case 3: {
        Opt3();
        break;
      }
      case 4: {
        Opt4();
        break;
      }
      case 5: {
        Opt5();
        break;
      }
      case 6: {
        Opt6();
        break;
      }
      case 7: {
        Opt7();
        break;
      }
      case 8: {
        Opt8();
        break;
      }
      default: {
        assert(false);
      }
    }

    puts("\n��������������\n");
    system("pause");
  }
}

void Opt1() {  // ��ʾ֧����¼
  system("cls");

  color(LIGHTBLUE);
  puts(
      "***************************************\n"
      "\t1. ����һ��֧����¼\n"
      "\t2. ����һ��֧����¼\n"
      "\t3. ����һ��֧����¼\n"
      "***************************************");
  color(YELLOW), printf("��������Ҫʹ�õĹ��ܶ�Ӧ��ţ�");

  judge = GetInt(1, 3);

  switch (judge) {
    case 1: {
      printf("������������ڣ��磺2020 8 12����");
      GetDay(&year, &month, &day);
      OutPutDay(head, year, month, day);
      break;
    }
    case 2: {
      printf("����������·ݣ��磺2020 8����");
      GetMonth(&year, &month);
      OutPutMonth(head, year, month);
      break;
    }
    case 3: {
      printf("�����������ݣ��磺2020����");
      GetYear(&year);
      OutPutYear(head, year);
      break;
    }
    default: {
      assert(false);
    }
  }
}
void Opt2() {  // ����֧����¼
  system("cls");

  color(LIGHTBLUE);
  puts(
      "***************************************\n"
      "\t1.�������Ѷ����\n"
      "\t2.���ݻ�����;����\n"
      "***************************************");
  color(YELLOW), printf("��������Ҫʹ�õĹ��ܶ�Ӧ��ţ�");

  // ����һ��1~2����������ʾ�û�ѡ��Ĳ���
  judge = GetInt(1, 2);

  switch (judge) {
    case 1: {
      printf("��������ҽ�");

      SearchByCost(head, GetMoney());

      break;
    }
    case 2: {
      printf("�����������;��");
      GetUsage(usage);

      SearchByUse(head, usage);

      break;
    }
    default: {
      assert(false);
    }
  }
}
void Opt3() {  // �������Ѽ�¼
  system("cls");

  printf("�����뻨�ѽ���114514����");
  expend.cost = GetMoney();

  printf("\n�����뻨�����ڣ��磺1919 8 10����");
  GetDay(&expend.year, &expend.month, &expend.day);

  printf("\n�����뻨��;�����磺�չ�UESTC����");
  GetUsage(expend.usage);

  Insert(expend);
  SaveToFile(head);
}
void Opt4() {  // �޸����Ѽ�¼
  system("cls");

  printf("��������Ҫ�޸ĵļ�¼��ţ�");
  cnt = GetInt(1, current_cnt);

  Revise(cnt);
  SaveToFile(head);
}
void Opt5() {  // ɾ�����Ѽ�¼
  system("cls");

  printf("��������Ҫɾ���ļ�¼��ţ�");
  cnt = GetInt(1, current_cnt);

  Delete(cnt);
  SaveToFile(head);
}
void Opt6() {  // ���������ܺ�
  system("cls");

  puts(
      "1.����һ��֧���ܺ�\n"
      "2.����һ��֧���ܺ�\n"
      "3.����һ��֧���ܺ�\n");

  printf("��������Ҫʹ�õĹ��ܶ�Ӧ�ı�ţ�");
  judge = GetInt(1, 3);

  switch (judge) {
    case 1: {
      printf("������������ڣ���:2020 1 12����");
      GetDay(&year, &month, &day);
      printf("���� %d��%d��%d�յĻ����ǣ�%lf", year, month, day,
             SumOfDay(head, year, month, day));
      break;
    }
    case 2: {
      printf("����������·ݣ��磺2020 8����");
      GetMonth(&year, &month);
      printf("����%d��%d�µĻ����ǣ�%lf", year, month,
             SumOfMonth(head, year, month));
      break;
    }
    case 3: {
      printf("�����������ݣ��磺2020����");
      GetYear(&year);
      printf("����%d��Ļ����ǣ�%lf", year, SumOfYear(head, year));
      break;
    }
    default: {
      assert(false);
    }
  }
}
void Opt7() {  // ���沢�˳�
  system("cls");

  SaveToFile(head);

  puts("�����˳�����");
  system("pause");
  system("cls");
  exit(EXIT_SUCCESS);
}
void Opt8() {  // ɾ�����ݲ��˳�
  system("cls");

  //�����û�����ֹ�û����������ݱ�ɾ��
  printf("���Ƿ�Ҫɾ���������ݣ����ɻָ�����(y/n)��");
  if (GetYN()) {
    DestroyFile();
    ClearData(head);

    puts("�����˳�����\n");
    system("pause");

    exit(EXIT_SUCCESS);
  }
}