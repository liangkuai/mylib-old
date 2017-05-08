/**
 * common.h
 *
 * 通用
 * 
 * Create by liangkuai
 *
 * Date: 2017/03/07
 */



#ifndef _COMMON_H_LIANGKUAI_
#define _COMMON_H_LIANGKUAI_

/*
 * 自定义表示布尔类型
 * C99前不支持布尔类型
 */
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*
 * 程序或函数执行状态
 */
#define EXECUTE_SUCCESS 1
#define EXECUTE_FAILURE -1

/*
 * 宏，交换两个值
 */
#ifndef swap
#define swap(a,b) (a^=b,b^=a,a^=b)
#endif

#endif // _COMMON_H_LIANGKUAI_
