/******************************************************
 * @brief: ��������Լ���ɫ����
 * @birth: �� 2020-01-04 �����ʴ���
 * @revision: �� 2021-01-07 ����������޸�
 ******************************************************/

#ifndef COLOR_STR
#define COLOR_STR

#include <stdbool.h>

// ����һ��������
typedef struct {
  char str[256];
  int cur, end;
} Sstream;

extern Sstream strin;  // Ĭ���ַ�������

/***************************
 * @brief: ��stdin��ȡһ����Ч����
 * @param: target��&strin
 ***************************/
extern void SstreamInit(Sstream *target);
/***************************
 * @brief: ��鵱ǰ�ַ����Ƿ񵽴��β
 * @param: sstr��&strin
 ***************************/
extern bool seof(Sstream *sstr);

/***************************
 * @brief: ���ַ�������һ������
 * @param: target��Ŀ��������sstr��&strin
 * @ret: �Ƿ�ɹ�����
 ***************************/
extern bool SstreamInt(int *target, Sstream *sstr);
/***************************
 * @brief: ���ַ�������һ��������λС������ʵ��
 * @param: target��Ŀ��ʵ����sstr��&strin
 * @ret: �Ƿ�ɹ�����
 ***************************/
extern bool SstreamMoney(double *target, Sstream *sstr);
/***************************
 * @brief: ���ַ�������һ���޿ո���ַ���
 * @param: target��Ŀ���ַ�����sstr��&strin
 * @ret: �Ƿ�ɹ�����
 ***************************/
extern bool SstreamStr(char *target, Sstream *sstr);

/***************************
 * @brief: ���ַ�������y/n�ж�
 * @param: void
 * @ret: y/n�ж����
 ***************************/
extern bool GetYN();
/***************************
 * @brief: ����һ��[l, r]������
 * @param: l��r���������½�
 ***************************/
extern int GetInt(int l, int r);
/***************************
 * @brief: ������
 * @param: void
 ***************************/
extern double GetMoney();
/***************************
 * @brief: ����ȷ�е�һ��
 * @param: year��month��day��ʱ��
 ***************************/
extern void GetDay(int *year, int *month, int *day);
/***************************
 * @brief: ����ȷ�е�һ����
 * @param: year��month��ʱ��
 ***************************/
extern void GetMonth(int *year, int *month);
/***************************
 * @brief: ����ȷ�е�һ��
 * @param: year��ʱ��
 ***************************/
extern void GetYear(int *year);
/***************************
 * @brief: ������;
 * @param: usage����;
 ***************************/
extern void GetUsage(char *usage);

// ��ɫ���ƺ�
#define NORMAL 7

#define DARKBLUE 1        //����ɫ����
#define RED 4             //��ɫ����
#define PURPLE 5          //��ɫ����
#define GREY 8            //��ɫ����
#define GREEN 10          //��ɫ����
#define LIGHTBLUE 11      //ǳ������
#define WHITE 15          //����ɫ����
#define ORANGE 268        //��ɫ����
#define YELLOW 14         //��ɫ����
#define RED_BLACK 64      //��׺���
#define RED_WHITE 79      //��װ���
#define YELLOW_BLACK 224  //�Ƶ׺���
#define WHITE_BLACK 240   //�׵׺���
#define WHITE_RED 244     //�׵׺���
#define WHITE_GREEN 250   //�׵�����
#define GREEN_BLACK 416   //�̵׺���
#define DARKYELLOW 262    //���ɫ

/***************************
 * @brief: ������ɫ
 * @param: x��Ŀ����ɫ
 ***************************/
extern void color(int x);
/***************************
 * @brief: �����ɫ����
 * @param: i���ո���
 ***************************/
extern void putskg(int i);

#endif
