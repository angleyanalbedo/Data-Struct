#pragma once
#include<iostream>
#include<vector>


class alx
{
public:
	alx();
	void scanner();
private:
	std::string key[6];
	bool isNum(std::string);
	int isKey(std::string);
	bool isWord(std::string);
};

