#include"GetType.h"
//��ȡ���ʽ
Expression *getExp()
{
	Expression *exp=new Expression();
	cout<<"��������ʽ:";
	getline(cin,exp->expStr);
	return exp;
}

//�ж����ͣ��ֽ��ų��ж����͵Ĵ���
void getType(Expression *exp)
{
	bool eq=false;//�Ⱥų��ֱ�־
	bool lr=false;//����С�ںų��ֱ�־
	bool in=false;//�ж��Ƿ�Ϊ�Ϸ��ַ�
	char inlist[10]={'+','-','*','/','!','^','.','(',')',','};//�����֣���ĸ������С�ڵ��ں���ĺϷ��ַ�
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
				//���ݵȺ�ǰ���жϱ��ʽ����
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
				//����һ���Ⱥ�Ϊ����
				exp->errorType=moreThanOneEqualSign;
				break;
			}
		}else if (exp->expStr[i]=='>' || exp->expStr[i]=='<')
		{
			//�жϲ���ʽ����
			exp->expType=inequation;
			//�Ѿ�ȷ�����������벻�Ⱥţ�����
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
			//:��û��=�ŵĴ���
			if (i+1>=exp->expStr.length() || exp->expStr[i+1]!='=')
			{
				exp->errorType=noneEqualSignAfterColon;
				break;
			}
		}
		else if (exp->expStr[i]>='0' && exp->expStr[i]<='9' || ((exp->expStr[i]>='A' && exp->expStr[i]<='Z')||(exp->expStr[i]>='a' && exp->expStr[i]<='z')) || in==true)
		{
			//�Ϸ��ַ�
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
