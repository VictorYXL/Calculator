#include"Count.h"
SignList *Solve(Expression *exp,int from,int to,map<string, double> VariableMap,map<string,SignList> FunctionMap,SignList *osl)
{
	SignList *sl;
	if (osl==NULL)
		sl=new SignList(&exp->signList);
	else sl=new SignList(*osl);
	//变量替换
	for (int i=from;i<=to;i++)
	{
		if (sl->at(i)->st==SignType::variablest)
			if (VariableMap.count(sl->at(i)->variables)>=1)
				sl->Modify(i,new Sign(VariableMap[sl->at(i)->variables]));
			else 
			{
				exp->errorType=ErrorType::unknownVariable;
				return NULL;
			}
	}
	//函数替换
	for (int i=from;i<=to;i++)
	{
		if (sl->at(i)->st==SignType::functionst)
		{
			double Number[MAXVAR];
			int nc=0;
			if (sl->at(i+1)->st!=SignType::operatorst || sl->at(i+1)->operators!='(')
			{
				exp->errorType=ErrorType::noEnoughVariablesInFunction;
				return NULL;
			}
			if (FunctionMap.count(sl->at(i)->functions)==0)
			{
				exp->errorType=ErrorType::unknownFunction;
				return NULL;
			}
			//提取参数
			int p=MatchBracket(sl,i+1),x=i+2;
			int deep=0;
			for (int j=i+2;j<=p-1;j++)
			{
				if (sl->at(j)->st==SignType::operatorst && sl->at(j)->operators=='(')
					deep++;
				else if (sl->at(j)->st==SignType::operatorst && sl->at(j)->operators==')')
					deep--;
				if ((sl->at(j)->st==SignType::operatorst && sl->at(j)->operators==',' && deep==0) || j==p-1)
				{
					if (j==p-1)
						j++;
					SignList *ttsl=Solve(exp,x,j-1,VariableMap,FunctionMap,sl);
					if (ttsl==NULL)
						return NULL;
					else
					{
						Number[nc]=ttsl->at(x)->numbers;
						nc++;
						x=j+1;
					}
				}
			}
			//替换参数
			SignList *tsl=new SignList(&FunctionMap[sl->at(i)->functions]);
			for (int j=0;j<tsl->Count();j++)
				if (tsl->at(j)->st==SignType::variablest && tsl->at(j)->variables[0]<10)
					if (tsl->at(j)->variables[0]>=nc)
					{
						exp->errorType=ErrorType::noEnoughVariablesInFunction;
						return NULL;
					}
					else tsl->Modify(j,new Sign(Number[tsl->at(j)->variables[0]]));
			//加入表达式
			p=MatchBracket(sl,i+1);
			for (int j=i;j<=p;j++)
				sl->Remove(i);
			to-=p-i+1;
			//printf("   %d", to);
			sl->Insert(i,new Sign(')'));
			for (int j=tsl->Count()-1;j>=0;j--)
				sl->Insert(i,tsl->at(j));
			sl->Insert(i,new Sign('('));
			to+=tsl->Count()+2;
		}
	}
	//括号消除
	for (int i=from;i<=to;i++)
	{
		if (i< sl->Count() && sl->at(i)->st==SignType::operatorst && sl->at(i)->operators=='(')
		{
			int p=MatchBracket(sl,i);
			double s=Solve(exp,i+1,p-1,VariableMap,FunctionMap,sl)->at(i+1)->numbers;
			p = MatchBracket(sl, i);
			for (int j=0;j<p-i+1;j++)
				sl->Remove(i);
			to-=(p-i+1);
			sl->Insert(i,new Sign(s));
			to++;
		}
	}

	//乘方
	for (int i=from+1;i<=to-1;i++)
	{
		if (i< sl->Count() && sl->at(i)->st==SignType::operatorst && sl->at(i)->operators=='^')
		{
			CheckNumber
			double s=pow(sl->at(i-1)->numbers,sl->at(i+1)->numbers);
			ModifyList
		}
	}
	//乘除
	for (int i=from+1;i<=to-1;i++)
	{
		if (i< sl->Count() && sl->at(i)->st==SignType::operatorst && (sl->at(i)->operators=='*' || sl->at(i)->operators=='/'))
		{
			CheckNumber
			if (sl->at(i)->operators=='/' && sl->at(i+1)->numbers==0)
			{
				exp->errorType=ErrorType::DivisorIsZero;
				return NULL;
			}
			double s;
			if (sl->at(i)->operators=='*')
				s=sl->at(i-1)->numbers * sl->at(i+1)->numbers;
			else s=sl->at(i-1)->numbers / sl->at(i+1)->numbers;
			ModifyList
		}
	}

	//加减
	for (int i=from+1;i<=to-1;i++)
	{
		if (i< sl->Count() && sl->at(i)->st==SignType::operatorst && (sl->at(i)->operators=='+' || sl->at(i)->operators=='-'))
		{
			CheckNumber
			double s;
			if (sl->at(i)->operators=='+')
				s=sl->at(i-1)->numbers + sl->at(i+1)->numbers;
			else s=sl->at(i-1)->numbers - sl->at(i+1)->numbers;
			ModifyList
		}
	}
	return sl;
}

//括号匹配
int MatchBracket(SignList *sl,int from)
{
	int depth=0,pos;
	for (pos=from;pos<sl->Count();pos++)
	{
		if (sl->at(pos)->operators=='(')
			depth++;
		else if (sl->at(pos)->operators==')')
		{
			depth--;
			if (depth==0)
				return pos;
		}
	}
	return -1;
}

//定义函数
SignList* DefineFunction(Expression *exp, map<string, double> VariableMap, map<string, SignList> FunctionMap)
{
	int k = 0;
	Sign *ts;
	SignList *tvar = new SignList();
	SignList *sl = new SignList(&exp->signList);
	for (int i = 2; i <= exp->typePos - 2; i++)
	{
		ts = sl->at(i);
		if (i % 2 == 0)
			if (ts->st != SignType::variablest)
			{
				exp->errorType = ErrorType::WrongVariablestInFunction;
				return NULL;
			}
			else tvar->add(ts);
		else if (ts->st != SignType::operatorst || ts->operators != ',')
		{
			exp->errorType = ErrorType::WrongVariablestInFunction;
			return NULL;
		}
	}
	exp->signList.at(0)->variablesCounts = tvar->Count();
	for (int i = 0; i <= exp->typePos; i++)
		sl->Remove(0);
	for (int j = exp->typePos + 1; j < exp->signList.Count(); j++)
	{
		int i = j - exp->typePos - 1;
		ts = sl->at(i);
		if (ts->st == SignType::variablest)
		{
			k = tvar->Find(ts);
			if (k >= 0)
				ts->variables = k;
			else if (VariableMap.count(ts->variables) >= 1)
				sl->Modify(i, new Sign(VariableMap[sl->at(i)->variables]));
			else
			{
				exp->errorType = ErrorType::unknownVariable;
				return NULL;
			}
		}
		else if (ts->st == SignType::functionst)
			if (FunctionMap.count(ts->functions) < 1)
			{
				exp->errorType = ErrorType::unknownFunction;
				return NULL;
			}
	}
	return sl;
}