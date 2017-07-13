#include<Windows.h>
#include<iostream>
#include<string>
#include"GetType.h"
#include"GetWord.h"
#include"Structure.h"
#include"Others.h"
#include"Count.h"
using namespace std;

#define StrMax 1000
//������
int main()
{
	Expression *exp;
	SignList *sl;
	string tstr;
	Sign *ts;
	bool flag=true;
	//Hash���¼����ֵ
	static map<string, double> VariableMap;
	//Hash���¼�������ʽ
	static map<string,SignList> FunctionMap;
	static map<string,string> FunctionMap1;
	printExplanation();
	while (flag)
	{
		exp=getExp();
		getType(exp);
		if (exp->errorType!=OK)
		{
			reportError(exp);
			continue;
		}
		getWord(exp);
		switch(exp->expType)
		{
		case over:
			flag=false;
			break;
		case clean:
			system("cls");
			printExplanation();
			break;
		case Help:
			//XXXXXXXXX
			break;
		case showVF:
			cout<<"����:"<<endl;
			{
				map<string,double>::iterator it;
				for(it=VariableMap.begin();it!=VariableMap.end();++it)
					cout<<"  "<<it->first<<" = "<<it->second<<endl;
			}
			cout<<"����(�Ե�ʱ����Ϊ׼):"<<endl;
			{
				map<string,string>::iterator it;
				for(it=FunctionMap1.begin();it!=FunctionMap1.end();++it)
					cout<<"  "<<it->second<<endl;
			}
			cout<<endl;
			break;
		case calculate:
			sl=Solve(exp,0,exp->signList.Count()-1,VariableMap,FunctionMap,NULL);
			if (sl==NULL)
				reportError(exp);
			else if (sl->at(0)->st!=SignType::numberst)
				cout<<"������Ϊ: 0"<<endl<<endl;
				else cout<<"������Ϊ: "<<std::fixed <<sl->at(0)->numbers<<endl<<endl;
			break;
		case equation:
			break;
		case assignment:
			if (exp->signList.at(0)->st!=SignType::variablest)
			{
				exp->errorType=ErrorType::LeftVariablesOrFunctionIsNeeded;
				reportError(exp);
				break;
			}
			tstr=exp->signList.at(0)->variables;
			sl=Solve(exp,2,exp->signList.Count()-1,VariableMap,FunctionMap,NULL);
			if (sl==NULL)
				reportError(exp);
			else 
			{
				VariableMap[tstr]=sl->at(2)->numbers;
				cout<<"��ֵ��� "<<tstr<<" = "<<sl->at(2)->numbers<<endl<<endl;
			}
			break;
		case function:
			sl=DefineFunction(exp,VariableMap,FunctionMap);
			if (sl==NULL)
				reportError(exp);
			else 
			{
				FunctionMap[exp->signList.at(0)->functions]=*sl;
				string str;
				cout<<"��ֵ��� ";
				for (int i=0;i<exp->signList.Count();i++)
					if (i==exp->typePos)
						str+="=";
					else
					{
						if (i<exp->typePos)
							ts=exp->signList.at(i);
						else ts=sl->at(i-exp->typePos-1);
						switch(ts->st)
						{
						case SignType::numberst:
							char s1[MAXLENGTH];
							if (ts->numbers==(int)ts->numbers)
								sprintf(s1,"%d",(int)ts->numbers);
							else sprintf(s1,"%f", ts->numbers);
							str+=s1;
							break;
						case SignType::operatorst:
							str+=ts->operators;
							break;
						case SignType::variablest:
							if (ts->variables[0]<10)
								str+=exp->signList.at(ts->variables[0]*2+2)->variables;
							else 
								str+=ts->variables;
							break;
						case SignType::functionst:
							str+=ts->functions;
							break;
							}
						}
					FunctionMap1[exp->signList.at(0)->functions]=str;
					cout<<str;
					cout<<endl<<endl;
			}
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}