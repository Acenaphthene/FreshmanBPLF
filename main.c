/******************************************************
 * @brief: 主函数实现部分
 * @birth: 在 2020-12-18 由任峙皓创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "money.h"
#include "str_in.h"

unsigned int current_cnt;  // 元素计数器
List *head;                // 链表头
Sstream strin;             // 默认字符输入流

int opt, judge;        // 用户输入的功能编号
int year, month, day;  // 用户输入的年月日
char usage[50];        // 用户输入的消费用途
int cnt;               // 删除消费记录的编号
Expend expend;         // 存入用户输入的消费情况的结构体

/***************************
 * @brief: 输出主交互界面
 * @param: void
 ***************************/
void menu() {
  color(NORMAL), puts("\n\n\n\t\t\t\t=======================================");
  color(YELLOW_BLACK), puts("\t\t\t\t\t   大学生收支管理系统   ");
  color(NORMAL), puts("\t\t\t\t=======================================\n");

  puts("\t\t\t\t***************************************\n");
  putskg(8), color(WHITE_BLACK), printf("\t\t\t1.显示支出记录");
  putskg(8), color(WHITE_BLACK), puts("2.查找支出记录\n");

  putskg(8), color(WHITE_BLACK), printf("\t\t\t3.增加支出记录");
  putskg(8), color(WHITE_BLACK), puts("4.修改已有数据\n");

  putskg(8), color(WHITE_BLACK), printf("\t\t\t5.删除支出记录");
  putskg(8), color(WHITE_BLACK), puts("6.计算支出总和\n");

  putskg(8), color(WHITE_BLACK), printf("\t\t\t7.保存并且退出");
  putskg(8), color(WHITE_BLACK), puts("8.删档并且退出\n");
  color(NORMAL), puts("\t\t\t\t***************************************\n");

  color(LIGHTBLUE), printf("\t\t\t\t请输入想要使用的功能对应编号：");
  color(YELLOW);
}

/***************************
 * @brief: 实现各个功能
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
 * @brief: 实现程序的功能
 * @param: void
 ***************************/
int main() {
  system("cls"), InitFromFile(&head);  // 链表头初始化

  while (true) {
    system("cls"), menu();  // 打印菜单，让用户输入相应功能编号

    // 读入一个1~8的整数，表示用户选择的操作
    opt = GetInt(1, 8);

    switch (opt) {
      case 1: {  // 操作 1：进行查找支出记录操作
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

    puts("\n即将返回主界面\n");
    system("pause");
  }
}

void Opt1() {  // 显示支出记录
  system("cls");

  color(LIGHTBLUE);
  puts(
      "***************************************\n"
      "\t1. 查找一天支出记录\n"
      "\t2. 查找一月支出记录\n"
      "\t3. 查找一年支出记录\n"
      "***************************************");
  color(YELLOW), printf("请输入想要使用的功能对应编号：");

  judge = GetInt(1, 3);

  switch (judge) {
    case 1: {
      printf("请输入查找日期（如：2020 8 12）：");
      GetDay(&year, &month, &day);
      OutPutDay(head, year, month, day);
      break;
    }
    case 2: {
      printf("请输入查找月份（如：2020 8）：");
      GetMonth(&year, &month);
      OutPutMonth(head, year, month);
      break;
    }
    case 3: {
      printf("请输入查找年份（如：2020）：");
      GetYear(&year);
      OutPutYear(head, year);
      break;
    }
    default: {
      assert(false);
    }
  }
}
void Opt2() {  // 查找支出记录
  system("cls");

  color(LIGHTBLUE);
  puts(
      "***************************************\n"
      "\t1.根据消费额查找\n"
      "\t2.根据花费用途查找\n"
      "***************************************");
  color(YELLOW), printf("请输入想要使用的功能对应编号：");

  // 读入一个1~2的整数，表示用户选择的操作
  judge = GetInt(1, 2);

  switch (judge) {
    case 1: {
      printf("请输入查找金额：");

      SearchByCost(head, GetMoney());

      break;
    }
    case 2: {
      printf("请输入查找用途：");
      GetUsage(usage);

      SearchByUse(head, usage);

      break;
    }
    default: {
      assert(false);
    }
  }
}
void Opt3() {  // 增加消费记录
  system("cls");

  printf("请输入花费金额（如114514）：");
  expend.cost = GetMoney();

  printf("\n请输入花费日期（如：1919 8 10）：");
  GetDay(&expend.year, &expend.month, &expend.day);

  printf("\n请输入花费途径（如：收购UESTC）：");
  GetUsage(expend.usage);

  Insert(expend);
  SaveToFile(head);
}
void Opt4() {  // 修改消费记录
  system("cls");

  printf("请输入想要修改的记录编号：");
  cnt = GetInt(1, current_cnt);

  Revise(cnt);
  SaveToFile(head);
}
void Opt5() {  // 删除消费记录
  system("cls");

  printf("请输入想要删除的记录编号：");
  cnt = GetInt(1, current_cnt);

  Delete(cnt);
  SaveToFile(head);
}
void Opt6() {  // 计算消费总和
  system("cls");

  puts(
      "1.计算一天支出总和\n"
      "2.计算一月支出总和\n"
      "3.计算一年支出总和\n");

  printf("请输入想要使用的功能对应的编号：");
  judge = GetInt(1, 3);

  switch (judge) {
    case 1: {
      printf("请输入具体日期（如:2020 1 12）：");
      GetDay(&year, &month, &day);
      printf("你在 %d年%d月%d日的花费是：%lf", year, month, day,
             SumOfDay(head, year, month, day));
      break;
    }
    case 2: {
      printf("请输入具体月份（如：2020 8）：");
      GetMonth(&year, &month);
      printf("你在%d年%d月的花费是：%lf", year, month,
             SumOfMonth(head, year, month));
      break;
    }
    case 3: {
      printf("请输入具体年份（如：2020）：");
      GetYear(&year);
      printf("你在%d年的花费是：%lf", year, SumOfYear(head, year));
      break;
    }
    default: {
      assert(false);
    }
  }
}
void Opt7() {  // 保存并退出
  system("cls");

  SaveToFile(head);

  puts("即将退出程序");
  system("pause");
  system("cls");
  exit(EXIT_SUCCESS);
}
void Opt8() {  // 删除数据并退出
  system("cls");

  //警告用户，防止用户点错造成数据被删除
  printf("你是否要删除所有数据（不可恢复）？(y/n)：");
  if (GetYN()) {
    DestroyFile();
    ClearData(head);

    puts("即将退出程序\n");
    system("pause");

    exit(EXIT_SUCCESS);
  }
}