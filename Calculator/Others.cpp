#include"Others.h"

//��ӡ˵��
void printExplanation()
{
	cout<<"������㣺"<<endl<<"     ����Ⱥ��ұ�Ϊ�ջ�����Ⱥţ�֧��+-*/^()�ȣ��ɳ����Ѷ���ĺ����ͱ�����"<<endl<<"     ����� 10*a^2+f(10,g(a))"<<endl;
	//cout<<"��ⷽ�̣�"<<endl<<"     ����ʡ�Գ˺ţ����֧�ֶ��η���"<<endl<<"     �� 10*a^2+20=25^2"<<endl;
	//cout<<"��ⲻ��ʽ��"<<endl<<"     ֧��>��<��>=��<=��<>�����Ⱥţ��ȣ�����ʡ�Գ˺�"<<endl<<"     �� 10*a^2-25^(0.5)<>25^2"<<endl;
	cout<<"������ֵ��"<<endl<<"     ������=�������ʽ����������ĸ��ͷ�����԰������֣����ִ�Сд"<<endl<<"     �� a1=-10*20"<<endl;
	cout<<"���庯��: "<<endl<<"      ������(������)=�������ʽ����������ĸ��ͷ�����԰������֣����ִ�Сд"<<endl<<"      �� f(a,b)=a^b+b^a"<<endl;
	cout<<"��ʹ��Ӣ������"<<endl;
	//cout<<"����?����ϸ����������$��ʾ�����ͺ�����";
	cout<<"����$��ʾ�����ͺ���������#����������~����"<<endl<<endl;
}

//�������
void reportError(Expression *exp)
{
	cout<<"���ʽ���ִ���"<<endl;
	cout<<"��������: ";
	switch (exp->errorType)
	{
	case moreThanOneEqualSign:
		cout<<"����һ���Ⱥ�";
		break;
	case noneEqualSignAfterColon:
		cout<<"��ֵȱ�ٵȺ�";
		break;
	case ineqautionError:
		cout<<"����ʽ������";
		break;
	case bracketsNotMatch:
		cout<<"���Ų�ƥ��";
		break;
	case unknownSign:
		cout<<"δ֪����";
		break;
	case unknownVariable:
		cout<<"ʹ��δ��ֵ�ı���";
		break;
	case unknownFunction:
		cout<<"ʹ��δ����ĺ���";
		break;
	case noEnoughVariablesInFunction:
		cout<<"������������";
		break;
	case tooManyVariablesInFunction:
		cout<<"������������";
		break;
	case noEnoughVariablesInOperator:
		cout<<"�����ȱ�ٲ���";
		break;
	case operatorIsNeeded:
		cout<<"�����ȱʧ";
		break;
	case DivisorIsZero:
		cout<<"������";
		break;
	case VagueVariables:
		cout<<"�޷��ж�������";
		break;
	case LeftVariablesOrFunctionIsNeeded:
		cout<<"��ֵ�����Ϊ��������";
		break;
	case WrongVariablestInFunction:
		cout<<"���庯������ʽ��������";
		break;
	}
	cout<<endl<<endl;
}