#pragma once

#include<string>
using namespace std;

//错误类型
enum ErrorType
{
	OK,//没有错误
	moreThanOneEqualSign,//超过一个等号
	noneEqualSignAfterColon,//冒号后没有等号
	ineqautionError,//不等式表达错误
	bracketsNotMatch,//括号不匹配
	unknownSign,//未知符号
	unknownVariable,//未赋值的变量
	unknownFunction,//未知定义的函数
	noEnoughVariablesInFunction,//函数参数不足
	tooManyVariablesInFunction,//函数参数过多
	noEnoughVariablesInOperator,//运算符缺少参数
	operatorIsNeeded,//缺少运算符
	DivisorIsZero,//除数为0
	VagueVariables,//无法判断求解变量
	LeftVariablesOrFunctionIsNeeded,//赋值左边需为变量或函数
	WrongVariablestInFunction,//函数参数错误
	//....
};

//不等式类型
enum InequaitonType
{
	none,//不是不等式
	notEqual,//不等于
	bigger,//大于
	biggerEqual,//大于等于
	smaller,//小于
	smallerEqual,//小于等于
};

//表达式类型
enum ExpType
{
	calculate,//计算式
	inequation,//不等式
	equation,//方程
	assignment,//赋值
	function,//函数
	over,//结束
	clean,//清屏
	showVF,//显示变量和函数
	Help,//帮助
};

//词法单元类型
enum SignType
{
	numberst,//数字
	operatorst,//运算符
	variablest,//变量
	functionst,//函数
};

//词法单元
struct Sign 
{
	SignType st;//类型
	double numbers;//数字
	char operators;//运算符
	string variables;//变量
	string functions;//函数
	int variablesCounts;//函数的参数个数
	Sign(){};
	Sign (double number)
	{
		this->numbers=number;
		this->st=numberst;
	}
	Sign (int number)
	{
		this->numbers=number;
		this->st=numberst;
	}
	Sign (char operatorc)
	{
		this->operators=operatorc;
		this->st=operatorst;
	}
	Sign (string variable)
	{
		this->variables=variable;
		this->st=variablest;
	}
	Sign (string function,int variablesCount)//variablesCount为-1表示尚未获取参数个数
	{
		this->functions=function;
		this->variablesCounts=variablesCount;
		this->st=functionst;
	}
};