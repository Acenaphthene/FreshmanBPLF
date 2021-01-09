/******************************************************
 * @brief: 文件操作部分
 * @birth: 在 2021-01-03 由舒适创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "money.h"

static const char *kFile = "data.bin";  // 存档文件名

/***************************
 * @brief: 利用fopen和fread从存档文件读入数据
 * @complexity: O(n)
 ***************************/
void InitFromFile(List **L) {
  FILE *fin;
  List *cur;

  *L = (List *)malloc(sizeof(List));
  if (*L == NULL) {
    puts("链表头炸裂，即将退出...\n");
    system("pause");
    exit(EXIT_FAILURE);
  }
  cur = *L;

  if ((fin = fopen(kFile, "r")) != NULL) {
    fread(&current_cnt, sizeof(current_cnt), 1, fin);
    int cnt = 0;

    while (++cnt <= current_cnt) {
      if ((cur->next = (List *)malloc(sizeof(List))) == NULL) {
        puts("链表节点炸裂，读取结束\n");
        break;
      }

      cur = cur->next;
      fread(&(cur->data), sizeof(Expend), 1, fin);
    }

    printf("消费记录已读取，现有%u条记录。\n\n", current_cnt);
    system("pause");
  }
  cur->next = NULL;

  fclose(fin);
}

/***************************
 * @brief: 利用fopen和fwrite向存档文件写入数据
 * @complexity: O(n)
 ***************************/
void SaveToFile(List *L) {
  FILE *fout;

  if ((fout = fopen(kFile, "w")) == NULL) {
    puts("创建存档炸裂，无法保存");
  } else {
    fwrite(&current_cnt, sizeof(current_cnt), 1, fout);
    int cnt = 0;

    while (++cnt <= current_cnt) {
      L = L->next;
      fwrite(&(L->data), sizeof(Expend), 1, fout);
    }

    printf("%u条记录已保存\n\n", current_cnt);

    fclose(fout);
  }
  //  ClearData(head);
  return;
}

/***************************
 * @brief: 遍历链表，删除每个结点
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

  puts("已清除当前读取的记录\n");
}

/***************************
 * @brief: 利用remove移除存档文件
 * @complexity: O(1)
 ***************************/
void DestroyFile() {
  remove(kFile);

  FILE *fin;
  if ((fin = fopen(kFile, "r")) == NULL)
    puts("存档文件已移除\n");
  else
    printf("存档文件移除失败，请手动删除%s\n\n", kFile);
}
