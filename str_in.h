/******************************************************
 * @brief: 输入检验以及颜色控制
 * @birth: 在 2020-01-04 由舒适创建
 * @revision: 在 2021-01-07 由舒适最后修改
 ******************************************************/

#ifndef COLOR_STR
#define COLOR_STR

#include <stdbool.h>

// 保存一行输入流
typedef struct {
  char str[256];
  int cur, end;
} Sstream;

extern Sstream strin;  // 默认字符输入流

/***************************
 * @brief: 从stdin获取一行有效输入
 * @param: target：&strin
 ***************************/
extern void SstreamInit(Sstream *target);
/***************************
 * @brief: 检查当前字符流是否到达结尾
 * @param: sstr：&strin
 ***************************/
extern bool seof(Sstream *sstr);

/***************************
 * @brief: 从字符流读入一个整数
 * @param: target：目标整数；sstr：&strin
 * @ret: 是否成功读入
 ***************************/
extern bool SstreamInt(int *target, Sstream *sstr);
/***************************
 * @brief: 从字符流读入一个至多两位小数的正实数
 * @param: target：目标实数；sstr：&strin
 * @ret: 是否成功读入
 ***************************/
extern bool SstreamMoney(double *target, Sstream *sstr);
/***************************
 * @brief: 从字符流读入一个无空格的字符串
 * @param: target：目标字符串；sstr：&strin
 * @ret: 是否成功读入
 ***************************/
extern bool SstreamStr(char *target, Sstream *sstr);

/***************************
 * @brief: 从字符流读入y/n判定
 * @param: void
 * @ret: y/n判定结果
 ***************************/
extern bool GetYN();
/***************************
 * @brief: 读入一个[l, r]的整数
 * @param: l，r：整数上下界
 ***************************/
extern int GetInt(int l, int r);
/***************************
 * @brief: 读入金额
 * @param: void
 ***************************/
extern double GetMoney();
/***************************
 * @brief: 读入确切的一天
 * @param: year，month，day：时间
 ***************************/
extern void GetDay(int *year, int *month, int *day);
/***************************
 * @brief: 读入确切的一个月
 * @param: year，month：时间
 ***************************/
extern void GetMonth(int *year, int *month);
/***************************
 * @brief: 读入确切的一年
 * @param: year：时间
 ***************************/
extern void GetYear(int *year);
/***************************
 * @brief: 读入用途
 * @param: usage：用途
 ***************************/
extern void GetUsage(char *usage);

// 颜色控制宏
#define NORMAL 7

#define DARKBLUE 1        //深蓝色字体
#define RED 4             //红色字体
#define PURPLE 5          //紫色字体
#define GREY 8            //灰色字体
#define GREEN 10          //绿色字体
#define LIGHTBLUE 11      //浅蓝字体
#define WHITE 15          //亮白色字体
#define ORANGE 268        //橙色字体
#define YELLOW 14         //黄色字体
#define RED_BLACK 64      //红底黑字
#define RED_WHITE 79      //红底白字
#define YELLOW_BLACK 224  //黄底黑字
#define WHITE_BLACK 240   //白底黑字
#define WHITE_RED 244     //白底红字
#define WHITE_GREEN 250   //白底绿字
#define GREEN_BLACK 416   //绿底黑字
#define DARKYELLOW 262    //深黄色

/***************************
 * @brief: 调整颜色
 * @param: x：目标颜色
 ***************************/
extern void color(int x);
/***************************
 * @brief: 输出无色空行
 * @param: i：空格数
 ***************************/
extern void putskg(int i);

#endif
