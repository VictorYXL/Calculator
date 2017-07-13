#pragma once
#include"Structure.h"
int SeparateNomial(SignList *ssl,SignList *dsl[],bool dAOS[],int dc);
void RemovePow(SignList *dsl[],bool dAOS[],int dc);
void RemoveDevide(SignList *dsl[],bool dAOS[],int dc);
void RemoveTimes(SignList *ssl[],bool sAOS[],int sc,SignList *dsl[],bool dAOS[],int dc);
SignList* Solve(Expression *exp);