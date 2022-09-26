// 语法分析.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
使用有穷自动机来进行标识符 数字的判断

*/
#define Print 1
//是否在运行过程中打印种别码
#define Store 0
//是否存储种别码
#include<stdio.h>
#include<string.h>
#include<iostream>
#include"base.h"
#include"function.h"
//定义几个全局变量 
int syn;// 这个是定义种别号
char str[1000];//定义的字符串
int ptr = 0;
int k = 0;// 定义 k 作为一个标记符，记录是否出错，若 k=0 ，则说明没有出错，否则发生错误 

char token[20];	//存放字符（单词） 




void scanner()
{
	int count = 0;
	if (str[ptr] == ' ') ptr++;
	/*
	开头是字母
	只有两种情况就是
	标识符 或则关键字
	*/
	if (isChar(str[ptr]))
	{   /*
		这下面是标识符的有穷自动机
		*/
		while (isNum(str[ptr]) || isChar(str[ptr]))
		{
			token[count++] = str[ptr];
			ptr++;
		}
		token[count] = '\0';	//'\0'作为结束符 ,将单词分隔开 
		syn = isKey(token);
		if (syn == -1)
		{
			syn = 10;//标识符letter(letter|digit) *

		}

		/*
		开头是数字
		开头是数字只能是数字
		下面是判断数字的有穷自动机
		当然可以改进isNum直接判断是不是数字
		*/
		else if (isNum(str[ptr]))
		{
			while (isNum(str[ptr]))
			{
				token[count++] = str[ptr];
				ptr++;
			}
			token[count] = '\0';//结束标识 
			syn = 11;	//数字digit(digit) *
		}

		//如果是运算符或者界符
		else
		{
			//先处理没有争议的字符 
			switch (str[ptr])
			{
			case '+': syn = 13; token[0] = str[ptr]; token[1] = '\0'; break;
			case '-': syn = 14; token[0] = str[ptr]; token[1] = '\0'; break;
			case '*': syn = 15; token[0] = str[ptr]; token[1] = '\0'; break;
			case '/': syn = 16; token[0] = str[ptr]; token[1] = '\0'; break;
			case '=': syn = 25; token[0] = str[ptr]; token[1] = '\0'; break;
			case ';': syn = 26; token[0] = str[ptr]; token[1] = '\0'; break;
			case '(': syn = 27; token[0] = str[ptr]; token[1] = '\0'; break;
			case ')': syn = 28; token[0] = str[ptr]; token[1] = '\0'; break;
			case '#': syn = 0; token[0] = str[ptr]; token[1] = '\0'; break;
			}


			//处理有争议的
			//: :=
			/*
			在pascal语言中::=是问腿的
			因为其实也可以从文法上来说具有二义性
			*/
			if (str[ptr] == ':')
			{
				token[count++] = str[ptr];
				if (str[ptr + 1] == '=')
				{
					ptr++;
					token[count++] = str[ptr];
					syn = 18;
				}
				else
				{
					syn = 17;
				}
				token[count] = '\0';
			}

			//< <> <=
			if (str[ptr] == '<')
			{
				token[count++] = str[ptr];
				if (str[ptr + 1] == '>')
				{
					ptr++;
					token[count++] = str[ptr];
					syn = 21;
				}
				else if (str[ptr + 1] == '=')
				{
					ptr++;
					token[count++] = str[ptr];
					syn = 22;
				}
				else
				{
					syn = 20;
				}
				token[count] = '\0';
			}

			//> >=
			if (str[ptr] == '>')
			{
				token[count++] = str[ptr];
				if (str[ptr + 1] == '=')
				{
					ptr++;
					token[count++] = str[ptr];
					syn = 24;
				}
				else
				{
					syn = 23;
				}
				token[count] = '\0';
			}

			//后移 
			ptr++;	//判断运算符和界符的这部分由于指针 ptr 没有向后指，所以需要将指针 ptr 向后移一位 
		}

	
	}
	/*
	如果你不想看到种别码打印定义Print为0
	*/
#if Print
	std::cout << "种别码  " << syn << std::endl;
	std::cout << "单词" << token << std::endl;
#endif
}



int main()
{
	char ch;
	while (true)
	{
		std::cout << "输入语句  " << std::endl;
		std::cin.getline(str, 1000);
		ptr = 0;
		scanner();
		lrparser();
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
