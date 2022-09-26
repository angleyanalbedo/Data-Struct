#include "alx.h"
alx::alx() {
	key[0] = "begin";
	key[1] = "if";
	key[2] = "then";
	key[3] = "while";
	key[4] = "do";
	key[5] = "ebd";

}
int  alx::isKey(std::string str) {
	for (int i = 0; i < 6; i++) {
		if (str == key[i]) {
			return i + 1;
		}
	}
}
bool isNum(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] <'0' && str[i] > '9']) {
			return false;
		}
	}
}
bool isWord(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		
	}
}