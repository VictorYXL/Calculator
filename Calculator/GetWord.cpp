#include"GetWord.h"
//提取数字
double getNumber(string str,int *from)
{
	double s=0;
	char c;
	double k=0;
	while (true)
	{
		if ((*from)>=str.length())
			break;
		c=str[*from];
		if (c>='0' && c<='9')
		{
			if (k<=0)
				s=s*10+(c-'0');
			else 
			{
				k=k*10.0;
				s=s+(c-'0')*1.0/k;
			}
		}else if (c=='.')
			k=1.0;
		else break;
		(*from)++;
	}
	return s;
}

//提取字符串，判断变量或者函数
string getString(string str,int *from,bool *var)
{
	string nstr="";
	char c;
	*var=true;
	while (true)
	{
		if ((*from)>str.length())
			break;
		c=str[*from];
		if (c=='(')
		{
			*var=false;
			break;
		}else if ((c>='a' && c<='z')||(c>='A' && c<='Z') || (c>='0' && c<='9'))
			nstr=nstr+c;
		else break;
		(*from)++;
	}
	return nstr;
}

//提取词法单元
void getWord(Expression *exp)
{
	char c;
	int from=0;
	Sign *sign;
	string str;
	bool k=true;
	exp->typePos=-1;

	while (from<exp->expStr.length())
	{
		c=exp->expStr[from];
		if ((c>='0' && c<='9') || c=='.')
		{
			sign=new Sign(getNumber(exp->expStr,&from));
		}
		else if ((c>='a' && c<='z')|| (c>='A' && c<='Z'))
			{
				str=getString(exp->expStr,&from,&k);
				if (k)
					sign=new Sign(str);
				else sign=new Sign(str,-1);
			}
		else if (c=='=' || c=='<' || c=='>' || c==':') //记录表达式类型符在词法单元中的位置
		{
			exp->typePos=exp->signList.Count();
			from++;
			if (from<exp->expStr.length() && (exp->expStr[from]=='=' || exp->expStr[from]=='>'))
					from++;
			sign=new Sign('&');
		}else if (c==' ') //跳过空格
		{
			from++;
			continue;
		}
		else
		{
			if (c=='-' && (exp->signList.Count()==0 || (exp->signList.at(exp->signList.Count()-1)->st==SignType::operatorst && exp->signList.at(exp->signList.Count()-1)->operators=='(')))
			{
				sign=new Sign(0);
				exp->signList.add(sign);
			}
			sign=new Sign(c);
			from++;
		}

		exp->signList.add(sign);
	}
	if (exp->typePos<0)
	{
		exp->typePos=exp->signList.Count();
		exp->signList.add(new Sign('&'));
	}
}