#pragma once
#include"Structure.h"
#define ModifyList sl->Remove(i-1);sl->Remove(i-1);sl->Remove(i-1);sl->Insert(i-1,new Sign(s));to-=2;i--;
#define CheckNumber if (sl->at(i-1)->st!=SignType::numberst || sl->at(i+1)->st!=SignType::numberst){exp->errorType=ErrorType::noEnoughVariablesInOperator;return NULL;}
SignList *Solve(Expression *exp,int from,int to,map<string, double> VariableMap,map<string,SignList> FunctionMap,SignList *osl);
SignList* DefineFunction(Expression *exp,map<string, double> VariableMap,map<string,SignList> FunctionMap);
int MatchBracket(SignList *sl,int from);