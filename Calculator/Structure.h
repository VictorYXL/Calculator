#pragma once

#include<string>
#include<map>
#include<list>
#include"SignList.h"
#include"Define.h"
#define MAXVAR 10
#define MAXLENGTH 100
//
//表达式结构体
struct Expression
{
	string expStr;//表达式字符串
	ExpType expType;//表达式类型
	InequaitonType inequaitonType;//不等式类型
	ErrorType errorType;//
	SignList signList;//词法单元链表
	int typePos;//表达式类型符在词法单元中的位置
};
