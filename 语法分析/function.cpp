#include"function.h"


/*
scanner�ǽ��дʷ������õ�ÿ����һ�ξͻ����һ���ֱ�����syn ������token
*/

/*
���¸�������Ҫ�ȵ��� scanner()�������������Ȳ��� syn ��ֵ
����-->��-->���ʽ-->��ֵ���-->���-->����
��С��������װ����
*/
void factor()	//���� ��<����> ��=ID | NUM | ��<���ʽ>�� 
{
	if (syn == 10 || syn == 11)	//��ɨ��������ֻ�����ĸʱ������ɨ��
	{
		scanner();
	}
	else if (syn == 27)	//��ɨ�赽 '('ʱ������Ӧ��Ϊһ�����ʽ������ɨ��
	{
		scanner();
		expression();
		if (syn == 28)		//��ɨ����� ')'ʱ������ɨ��
			scanner();
		else
		{
			k = 1;	//���� 
			std::cout << "ERROR!ȱ��'��'" << std::endl;	//���ʽȱ ')'������ 
		}
	}
	else
	{
		k = 1;
		std::cout << "ERROR!������ź��治�ǳ�����'('���ʶ��" << std::endl;	//ɨ����ʽ �����ʽ������ '('��ͷ 
	}
}

void term()//�� : <��> ��=<����>{*<����> | /<����> } 
{
	factor();
	while (syn == 15 || syn == 16)	//����ͷɨ����� '*' ���� '/'ʱ('*'����'/'����������)������ɨ��
	{
		scanner();
		factor();
	}
}

void expression()//���ʽ : <���ʽ> ��=<��>{+<��> | -<��>}
{
	term();
	while (syn == 13 || syn == 14)	//����ͷɨ����� '+' ���� '-'ʱ('+'����'-'��������)������ɨ��
	{
		scanner();
		term();
	}
}

void statement()//��ֵ��� : ID = <���ʽ>
{
	if (syn == 10)	//����ͷɨ�������ĸʱ������ɨ��
	{
		scanner();
		if (syn == 18)		//ɨ����� ':='ʱ������ɨ��
		{
			scanner();
			expression();
		}
		else
		{
			k = 1;
			std::cout << "ERROR!ȱ�� ':=' " << std::endl;
		}
	}
	else
	{
		k = 1;
		std::cout << "ERROR!��ͷ���Ǳ�ʶ����" << std::endl;
	}
}

void sens()//��䴮 ��<��䴮>��=<���>{��<���>}
{
	statement();
	while (syn == 26)	//����ʼɨ����� ';'ʱ������ɨ��
	{
		scanner();
		statement();
	}
}

/*
����: <����> �� = begin<��䴮>end
�������ǽ����﷨�����õ�

*/
void lrparser()
{
	if (syn == 1)	//����ͷɨ����� 'begin'ʱ������ɨ��
	{
		scanner();
		sens();
		if (syn == 6) //ɨ�赽 'end'ʱ������ɨ�� 
		{
			scanner();
			if (syn == 0 && k == 0)	//�����ִ����ɨ����� '#'�������޳��������ɹ�
				std::cout << "success!" << std::endl;
			else if (syn != 0 || k == 1)
				std::cout << "error!" << std::endl;
		}
		else
		{
			std::cout << "ERROR!û�� 'end'" << std::endl;
		}
	}
	else
	{
		std::cout << "ERROR!û�� 'begin'" << std::endl;
	}
}