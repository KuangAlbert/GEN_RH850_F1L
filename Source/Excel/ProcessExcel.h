/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: Process Excel
 * Instance		:
 * Description	:
 *-----------------------------------------------------------------------
 * Version		: v1.0
 * Date			: 2018/08/27
 * Author		: uidp5021
 ***********************************************************************/
 /*-History--------------------------------------------------------------
 * Version       Date               Name            Changes and comments
 * 1.0           2018/08/27			Lishi           add Init version
*=========================================================================*/
#ifndef __PROCESS_EXCEL_
#define __PROCESS_EXCEL_
#include "config.h"
#define R(a) (a-1)
#define L(b) (b-65)

#define R_STAET_100 R(2)		/* 行开始检索 */
#define R_END_100	R(301)		/* 行检索结束 */

#define L_STAET_100 L('C')		/* 列开始检索 */
#define L_END_100	L('P')		/* 列检索结束 */

#define		SET_BIT(x, n)		x=( x | ((1U)<<(n)) )
#define		CLEAR_BIT(x,n)		x=(x &~(1U<<(n)))

extern void ProcessExcel(void);
extern U8 SearchAlternativNum(wchar_t* cell);
#endif /* PROCESS_EXCEL */