#include"function.h"


/*
scanner是进行词法分析用的每调用一次就会产生一个种别码在syn 单词在token
*/

/*
以下各函数均要先调用 scanner()函数，用于首先产生 syn 的值
因子-->项-->表达式-->赋值语句-->语句-->程序
由小到大逐层封装函数
*/
void factor()	//因子 ：<因子> ：=ID | NUM | （<表达式>） 
{
	if (syn == 10 || syn == 11)	//当扫描的是数字或者字母时，继续扫描
	{
		scanner();
	}
	else if (syn == 27)	//当扫描到 '('时，后面应该为一个表达式，继续扫描
	{
		scanner();
		expression();
		if (syn == 28)		//当扫描的是 ')'时，继续扫描
			scanner();
		else
		{
			k = 1;	//出错 
			std::cout << "ERROR!缺少'）'" << std::endl;	//表达式缺 ')'，出错 
		}
	}
	else
	{
		k = 1;
		std::cout << "ERROR!运算符号后面不是常数或'('或标识符" << std::endl;	//扫描表达式 ，表达式不是以 '('开头 
	}
}

void term()//项 : <项> ：=<因子>{*<因子> | /<因子> } 
{
	factor();
	while (syn == 15 || syn == 16)	//当开头扫描的是 '*' 或者 '/'时('*'或者'/'后面是因子)，继续扫描
	{
		scanner();
		factor();
	}
}

void expression()//表达式 : <表达式> ：=<项>{+<项> | -<项>}
{
	term();
	while (syn == 13 || syn == 14)	//当开头扫描的是 '+' 或者 '-'时('+'或者'-'后面是项)，继续扫描
	{
		scanner();
		term();
	}
}

void statement()//赋值语句 : ID = <表达式>
{
	if (syn == 10)	//当开头扫描的是字母时，继续扫描
	{
		scanner();
		if (syn == 18)		//扫描的是 ':='时，继续扫描
		{
			scanner();
			expression();
		}
		else
		{
			k = 1;
			std::cout << "ERROR!缺少 ':=' " << std::endl;
		}
	}
	else
	{
		k = 1;
		std::cout << "ERROR!开头不是标识符！" << std::endl;
	}
}

void sens()//语句串 ：<语句串>：=<语句>{；<语句>}
{
	statement();
	while (syn == 26)	//当开始扫描的是 ';'时，继续扫描
	{
		scanner();
		statement();
	}
}

/*
程序: <程序> ： = begin<语句串>end
接下来是进行语法分析用的

*/
void lrparser()
{
	if (syn == 1)	//当开头扫描的是 'begin'时，继续扫描
	{
		scanner();
		sens();
		if (syn == 6) //扫描到 'end'时，继续扫描 
		{
			scanner();
			if (syn == 0 && k == 0)	//当数字串最后扫描的是 '#'，而且无出错，分析成功
				std::cout << "success!" << std::endl;
			else if (syn != 0 || k == 1)
				std::cout << "error!" << std::endl;
		}
		else
		{
			std::cout << "ERROR!没有 'end'" << std::endl;
		}
	}
	else
	{
		std::cout << "ERROR!没有 'begin'" << std::endl;
	}
}