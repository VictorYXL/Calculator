#include"Others.h"

//打印说明
void printExplanation()
{
	cout<<"常规计算："<<endl<<"     计算等号右边为空或不输入等号，支持+-*/^()等，可出现已定义的函数和变量，"<<endl<<"     如计算 10*a^2+f(10,g(a))"<<endl;
	//cout<<"求解方程："<<endl<<"     请勿省略乘号，最多支持二次方程"<<endl<<"     如 10*a^2+20=25^2"<<endl;
	//cout<<"求解不等式："<<endl<<"     支持>、<、>=、<=和<>（不等号）等，请勿省略乘号"<<endl<<"     如 10*a^2-25^(0.5)<>25^2"<<endl;
	cout<<"变量赋值："<<endl<<"     变量名=变量表达式，变量名字母开头，可以包含数字，区分大小写"<<endl<<"     如 a1=-10*20"<<endl;
	cout<<"定义函数: "<<endl<<"      函数名(参数表)=函数表达式，函数名字母开头，可以包含数字，区分大小写"<<endl<<"      如 f(a,b)=a^b+b^a"<<endl;
	cout<<"请使用英文输入"<<endl;
	//cout<<"输入?打开详细帮助，输入$显示变量和函数，";
	cout<<"输入$显示变量和函数，输入#清屏，输入~结束"<<endl<<endl;
}

//报告错误
void reportError(Expression *exp)
{
	cout<<"表达式出现错误！"<<endl;
	cout<<"错误类型: ";
	switch (exp->errorType)
	{
	case moreThanOneEqualSign:
		cout<<"超过一个等号";
		break;
	case noneEqualSignAfterColon:
		cout<<"赋值缺少等号";
		break;
	case ineqautionError:
		cout<<"不等式表达错误";
		break;
	case bracketsNotMatch:
		cout<<"括号不匹配";
		break;
	case unknownSign:
		cout<<"未知符号";
		break;
	case unknownVariable:
		cout<<"使用未赋值的变量";
		break;
	case unknownFunction:
		cout<<"使用未定义的函数";
		break;
	case noEnoughVariablesInFunction:
		cout<<"函数参数不足";
		break;
	case tooManyVariablesInFunction:
		cout<<"函数参数过多";
		break;
	case noEnoughVariablesInOperator:
		cout<<"运算符缺少参数";
		break;
	case operatorIsNeeded:
		cout<<"运算符缺失";
		break;
	case DivisorIsZero:
		cout<<"除数零";
		break;
	case VagueVariables:
		cout<<"无法判断求解变量";
		break;
	case LeftVariablesOrFunctionIsNeeded:
		cout<<"赋值左边需为变量或函数";
		break;
	case WrongVariablestInFunction:
		cout<<"定义函数的形式参数错误";
		break;
	}
	cout<<endl<<endl;
}