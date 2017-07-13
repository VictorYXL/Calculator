#pragma once

#include<string>
using namespace std;

//��������
enum ErrorType
{
	OK,//û�д���
	moreThanOneEqualSign,//����һ���Ⱥ�
	noneEqualSignAfterColon,//ð�ź�û�еȺ�
	ineqautionError,//����ʽ������
	bracketsNotMatch,//���Ų�ƥ��
	unknownSign,//δ֪����
	unknownVariable,//δ��ֵ�ı���
	unknownFunction,//δ֪����ĺ���
	noEnoughVariablesInFunction,//������������
	tooManyVariablesInFunction,//������������
	noEnoughVariablesInOperator,//�����ȱ�ٲ���
	operatorIsNeeded,//ȱ�������
	DivisorIsZero,//����Ϊ0
	VagueVariables,//�޷��ж�������
	LeftVariablesOrFunctionIsNeeded,//��ֵ�����Ϊ��������
	WrongVariablestInFunction,//������������
	//....
};

//����ʽ����
enum InequaitonType
{
	none,//���ǲ���ʽ
	notEqual,//������
	bigger,//����
	biggerEqual,//���ڵ���
	smaller,//С��
	smallerEqual,//С�ڵ���
};

//���ʽ����
enum ExpType
{
	calculate,//����ʽ
	inequation,//����ʽ
	equation,//����
	assignment,//��ֵ
	function,//����
	over,//����
	clean,//����
	showVF,//��ʾ�����ͺ���
	Help,//����
};

//�ʷ���Ԫ����
enum SignType
{
	numberst,//����
	operatorst,//�����
	variablest,//����
	functionst,//����
};

//�ʷ���Ԫ
struct Sign 
{
	SignType st;//����
	double numbers;//����
	char operators;//�����
	string variables;//����
	string functions;//����
	int variablesCounts;//�����Ĳ�������
	Sign(){};
	Sign (double number)
	{
		this->numbers=number;
		this->st=numberst;
	}
	Sign (int number)
	{
		this->numbers=number;
		this->st=numberst;
	}
	Sign (char operatorc)
	{
		this->operators=operatorc;
		this->st=operatorst;
	}
	Sign (string variable)
	{
		this->variables=variable;
		this->st=variablest;
	}
	Sign (string function,int variablesCount)//variablesCountΪ-1��ʾ��δ��ȡ��������
	{
		this->functions=function;
		this->variablesCounts=variablesCount;
		this->st=functionst;
	}
};