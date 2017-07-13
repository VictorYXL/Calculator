#include"GetType.h"
//获取表达式
Expression *getExp()
{
	Expression *exp=new Expression();
	cout<<"请输入表达式:";
	getline(cin,exp->expStr);
	return exp;
}

//判断类型，分解排除判断类型的错误
void getType(Expression *exp)
{
	bool eq=false;//等号出现标志
	bool lr=false;//大于小于号出现标志
	bool in=false;//判断是否为合法字符
	char inlist[10]={'+','-','*','/','!','^','.','(',')',','};//除数字，字母，大于小于等于号外的合法字符
	exp->errorType=OK;
	exp->inequaitonType=none;
	if (exp->expStr=="?")
	{
		exp->expType=Help;
		return;
	}
	if (exp->expStr=="$")
	{
		exp->expType=showVF;
		return;
	}
	if (exp->expStr=="~")
	{
		exp->expType=over;
		return;
	}
	if (exp->expStr=="#")
	{
		exp->expType=clean;
		return;
	}
	for (int i=0;i<exp->expStr.length();i++)
	{
		in=false;
		for (int j=0;j<10;j++)
			if (exp->expStr[i]==inlist[j])
				in=true;
		if (exp->expStr[i]=='=')
		{
			if (eq==false)
			{
				eq=true;
				//根据等号前后判断表达式类型
				if (lr==true)
				{
					exp->errorType=ineqautionError;
					break;
				}
				else if (i<exp->expStr.length()-1)
					if (i-1>=0 && exp->expStr[i-1]==')')
						exp->expType=function;
					else exp->expType=assignment;
					/*if (i-1>=0 && exp->expStr[i-1]==':' )
					if (i-2>=0 && exp->expStr[i-2]==')')
						exp->expType=function;
					else exp->expType=assignment;*/
				else if (i-1>=0 && (exp->expStr[i-1]=='<' ||  exp->expStr[i-1]=='>'))
				{
					exp->expType=inequation;
					lr=true;
				}
				else if (i+1>=exp->expStr.length())
					exp->expType=calculate;
				else exp->expType=equation;
			}
			else 
			{
				//超过一个等号为错误
				exp->errorType=moreThanOneEqualSign;
				break;
			}
		}else if (exp->expStr[i]=='>' || exp->expStr[i]=='<')
		{
			//判断不等式类型
			exp->expType=inequation;
			//已经确定类型在输入不等号，错误
			if (eq==true || lr==true)
			{
				exp->errorType=ineqautionError;
				break;
			}
			lr=true;
			if (exp->expStr[i]=='<')
			{
				if (i+1<exp->expStr.length() && exp->expStr[i+1]=='>')
				{
					exp->inequaitonType=notEqual;
					i++;
				}
				else if (i+1<exp->expStr.length() && exp->expStr[i+1]=='=')
				{
					exp->inequaitonType=biggerEqual;
					i++;
				}
				else exp->inequaitonType=bigger;
			}
			else if (exp->expStr[i]=='>')
			{
				if (i+1<exp->expStr.length() && exp->expStr[i+1]=='=')
				{
					exp->inequaitonType=smallerEqual;
					i++;
				}
				else exp->inequaitonType=smaller;
			}
		}else if (exp->expStr[i]==':')
		{
			//:后没有=号的错误
			if (i+1>=exp->expStr.length() || exp->expStr[i+1]!='=')
			{
				exp->errorType=noneEqualSignAfterColon;
				break;
			}
		}
		else if (exp->expStr[i]>='0' && exp->expStr[i]<='9' || ((exp->expStr[i]>='A' && exp->expStr[i]<='Z')||(exp->expStr[i]>='a' && exp->expStr[i]<='z')) || in==true)
		{
			//合法字符
		}
		else 
		{
			exp->errorType=unknownSign;
			break;
		}
	}
	if (eq==false)
		exp->expType=calculate;
	return;
}
