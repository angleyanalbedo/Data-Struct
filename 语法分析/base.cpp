#include"base.h"
char key[6][20] = { "begin","if","then","while","do","end" };
int isKey(char s[])
{
	for (int i = 0; i < 6; i++)
	{
		if (strcmp(s, key[i]) == 0)
		{
			return i + 1;	//关键字的种别码依次为 begin=1,if=2,then=3,while=4,do=5,end=6即为 i+1 的值 
		}
	}
	return -1;
}
//判断是不是字母 
bool isChar(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else
		return false;
}
//判断是不是数字 
bool isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}