#pragma once

#include<list>
#include"define.h"
using namespace std;
class SignList
{
	private:
		list<Sign> *signList;
	public:
		SignList();
		SignList(SignList* sl);
		void add(Sign *s);
		void Insert(int index,Sign *s);
		int Count();
		bool Modify(int index,Sign *s);
		Sign *at(int index);
		bool Remove(int index);
		int Find(Sign *s);
		~SignList(void);
};

