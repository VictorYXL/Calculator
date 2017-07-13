#include "SignList.h"


SignList::SignList()
{
	signList=new list<Sign>();
}
SignList::SignList (SignList* sl)
{
	//SignList p = sl;
	signList=new list<Sign>();
	for (int i = 0; i < sl->Count(); i++)
		this->add(sl->at(i));
}
void SignList::add(Sign *s)
{
	signList->push_back(*s);
}

int SignList::Count()
{
	return signList->size();
}
Sign *SignList::at(int index)
{
	list<Sign>::iterator p=signList->begin();
	if (index>=Count())
		return NULL;
	for (int i=0;i<index;i++)
		p++;
	return &*p;
}
bool SignList::Modify(int index,Sign *s)
{
	if (Remove(index)==false)
		return false;
	Insert(index,s);
	return true;
		
}
bool SignList::Remove(int index)
{
	int p1=Count();
	if (index>=p1)
		return false;
	list<Sign>::iterator p=signList->begin();
    advance(p, index); // 这里修改迭代器的位置
    signList->erase(p); // 这里删除
	return true;
}
void SignList::Insert(int index,Sign *s)
{
	int p1=Count();
	if (index>=p1)
	{
		add(s);
		return;
	}
	list<Sign>::iterator p = signList->begin();
	for(int i = 0; i < index && p!= signList->end(); ++i)
		++p;
	signList->insert(p,1,*s);
}
int SignList::Find(Sign *s)
{
	for (int i=0;i<Count();i++)
	{
		if (at(i)->st==s->st)
			switch(s->st)
			{
			case SignType::numberst:
				if (at(i)->numbers==s->numbers)
					return i;
				break;
			case SignType::variablest:
				if (at(i)->variables==s->variables)
					return i;
				break;
			case SignType::operatorst:
				if (at(i)->operators==s->operators)
					return i;
				break;
			case SignType::functionst:
				if (at(i)->functions==s->functions)
					return i;
				break;
			}
	}
	return -1;
}
SignList::~SignList(void)
{
}