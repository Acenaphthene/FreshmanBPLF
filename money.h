/******************************************************
 * @brief: 大学生收支管理系统的主要头文件
 * @birth: 在 2020-12-01 由舒适创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#ifndef STAR_MONEY
#define STAR_MONEY

// 保存一条消费记录
typedef struct {
  int year, month, day;
  double cost;
  char usage[50];
} Expend;

// 链表结点
typedef struct Node {
  Expend data;
  struct Node *next;
} List;
extern List *head;  // 链表头

extern unsigned int current_cnt;  // 元素计数器

//-----------------------------------------------------------------------------
// file_io.h

/***************************
 * @brief: 从存档初始化链表
 * @param: List**：&head
 ***************************/
void InitFromFile(List **);
/***************************
 * @brief: 将链表保存到文件
 * @param: head
 ***************************/
void SaveToFile(List *);
/***************************
 * @brief: 清除链表当前内容
 * @param: head
 ***************************/
void ClearData(List *);
/***************************
 * @brief: 删除存档文件
 * @param: void
 ***************************/
void DestroyFile();

//-----------------------------------------------------------------------------
// output.h

/***************************
 * @brief: 输出expend的内容
 * @param: expend：要输出的内容；n：ID；n1：编号
 ***************************/
void OutPutSingle(Expend expend, int n, int n1);
/***************************
 * @brief: 对用户输入的具体日期进行查找
 * @param: cur：head；year, month, day：时间
 ***************************/
void OutPutDay(List *cur, int year, int month, int day);
/***************************
 * @brief: 对用户输入的月份进行查找
 * @param: cur：head；year, month：时间
 ***************************/
void OutPutMonth(List *cur, int year, int month);
/***************************
 * @brief: 对用户输入的年份进行查找
 * @param: cur：head；year：时间
 ***************************/
void OutPutYear(List *cur, int year);

/***************************
 * @brief: 对用户输入的用途进行查找
 * @param: cur：head；use：用途
 ***************************/
void SearchByUse(List *cur, char use[]);
/***************************
 * @brief: 对用户输入的花费金额进行查找
 * @param: cur：head；cost：金额
 ***************************/
void SearchByCost(List *cur, double cost);

//-----------------------------------------------------------------------------
// element.h

/***************************
 * @brief: 插入新的消费纪录
 * @param: expend：消费记录信息
 ***************************/
void Insert(Expend expend);
/***************************
 * @brief: 按照时间序数删除
 * @param: id：时间序数
 ***************************/
void Delete(int id);
/***************************
 * @brief: 按照时间序数修改
 * @param: id：时间序数
 ***************************/
void Revise(int id);

//-----------------------------------------------------------------------------
// sum.h

/***************************
 * @brief: 计算一天消费总和
 * @param: cur：head；year, month, day：时间
 ***************************/
double SumOfDay(List *cur, int year, int month, int day);
/***************************
 * @brief: 计算一个月消费总和
 * @param: cur：head；year, month：时间
 ***************************/
double SumOfMonth(List *cur, int year, int month);
/***************************
 * @brief: 计算一年消费总和
 * @param: cur：head；year：时间
 ***************************/
double SumOfYear(List *cur, int year);

/***************************
 * @brief: 条形图可视化特定用途消费
 * @param: cur：head；year：时间
 ***************************/
void PrintUsageYear(List *cur, int year);
/***************************
 * @brief: 条形图可视化特定用途消费
 * @param: cur：head；year，month：时间
 ***************************/
void PrintUsageMonth(List *cur, int year, int month);
/***************************
 * @brief: 条形图可视化特定用途消费
 * @param: cur：head；year，month，day：时间
 ***************************/
void PrintUsageDay(List *cur, int year, int month, int day);

/***************************
 * @brief: 条形图可视化月消费
 * @param: cur：head；year：时间
 ***************************/
void PrintEachMonth(List *cur, int year);
/***************************
 * @brief: 条形图可视化日消费
 * @param: cur：head；year，month：时间
 ***************************/
void PrintEachDay(List *cur, int year, int month);

//-----------------------------------------------------------------------------

#endif  // STAR_MONEY