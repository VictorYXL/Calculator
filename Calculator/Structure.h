#pragma once

#include<string>
#include<map>
#include<list>
#include"SignList.h"
#include"Define.h"
#define MAXVAR 10
#define MAXLENGTH 100
//
//���ʽ�ṹ��
struct Expression
{
	string expStr;//���ʽ�ַ���
	ExpType expType;//���ʽ����
	InequaitonType inequaitonType;//����ʽ����
	ErrorType errorType;//
	SignList signList;//�ʷ���Ԫ����
	int typePos;//���ʽ���ͷ��ڴʷ���Ԫ�е�λ��
};
