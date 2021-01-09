/******************************************************
 * @brief: ��ѧ����֧����ϵͳ����Ҫͷ�ļ�
 * @birth: �� 2020-12-01 �����ʴ���
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#ifndef STAR_MONEY
#define STAR_MONEY

// ����һ�����Ѽ�¼
typedef struct {
  int year, month, day;
  double cost;
  char usage[50];
} Expend;

// ������
typedef struct Node {
  Expend data;
  struct Node *next;
} List;
extern List *head;  // ����ͷ

extern unsigned int current_cnt;  // Ԫ�ؼ�����

//-----------------------------------------------------------------------------
// file_io.h

/***************************
 * @brief: �Ӵ浵��ʼ������
 * @param: List**��&head
 ***************************/
void InitFromFile(List **);
/***************************
 * @brief: �������浽�ļ�
 * @param: head
 ***************************/
void SaveToFile(List *);
/***************************
 * @brief: �������ǰ����
 * @param: head
 ***************************/
void ClearData(List *);
/***************************
 * @brief: ɾ���浵�ļ�
 * @param: void
 ***************************/
void DestroyFile();

//-----------------------------------------------------------------------------
// output.h

/***************************
 * @brief: ���expend������
 * @param: expend��Ҫ��������ݣ�n��ID��n1�����
 ***************************/
void OutPutSingle(Expend expend, int n, int n1);
/***************************
 * @brief: ���û�����ľ������ڽ��в���
 * @param: cur��head��year, month, day��ʱ��
 ***************************/
void OutPutDay(List *cur, int year, int month, int day);
/***************************
 * @brief: ���û�������·ݽ��в���
 * @param: cur��head��year, month��ʱ��
 ***************************/
void OutPutMonth(List *cur, int year, int month);
/***************************
 * @brief: ���û��������ݽ��в���
 * @param: cur��head��year��ʱ��
 ***************************/
void OutPutYear(List *cur, int year);

/***************************
 * @brief: ���û��������;���в���
 * @param: cur��head��use����;
 ***************************/
void SearchByUse(List *cur, char use[]);
/***************************
 * @brief: ���û�����Ļ��ѽ����в���
 * @param: cur��head��cost�����
 ***************************/
void SearchByCost(List *cur, double cost);

//-----------------------------------------------------------------------------
// element.h

/***************************
 * @brief: �����µ����Ѽ�¼
 * @param: expend�����Ѽ�¼��Ϣ
 ***************************/
void Insert(Expend expend);
/***************************
 * @brief: ����ʱ������ɾ��
 * @param: id��ʱ������
 ***************************/
void Delete(int id);
/***************************
 * @brief: ����ʱ�������޸�
 * @param: id��ʱ������
 ***************************/
void Revise(int id);

//-----------------------------------------------------------------------------
// sum.h

/***************************
 * @brief: ����һ�������ܺ�
 * @param: cur��head��year, month, day��ʱ��
 ***************************/
double SumOfDay(List *cur, int year, int month, int day);
/***************************
 * @brief: ����һ���������ܺ�
 * @param: cur��head��year, month��ʱ��
 ***************************/
double SumOfMonth(List *cur, int year, int month);
/***************************
 * @brief: ����һ�������ܺ�
 * @param: cur��head��year��ʱ��
 ***************************/
double SumOfYear(List *cur, int year);

/***************************
 * @brief: ����ͼ���ӻ��ض���;����
 * @param: cur��head��year��ʱ��
 ***************************/
void PrintUsageYear(List *cur, int year);
/***************************
 * @brief: ����ͼ���ӻ��ض���;����
 * @param: cur��head��year��month��ʱ��
 ***************************/
void PrintUsageMonth(List *cur, int year, int month);
/***************************
 * @brief: ����ͼ���ӻ��ض���;����
 * @param: cur��head��year��month��day��ʱ��
 ***************************/
void PrintUsageDay(List *cur, int year, int month, int day);

/***************************
 * @brief: ����ͼ���ӻ�������
 * @param: cur��head��year��ʱ��
 ***************************/
void PrintEachMonth(List *cur, int year);
/***************************
 * @brief: ����ͼ���ӻ�������
 * @param: cur��head��year��month��ʱ��
 ***************************/
void PrintEachDay(List *cur, int year, int month);

//-----------------------------------------------------------------------------

#endif  // STAR_MONEY