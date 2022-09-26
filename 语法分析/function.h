#pragma once
#include<iostream>
extern int syn;
extern char str[1000];
extern int ptr;
extern int k;
extern char token[20];
void expression();
void scanner();
void factor();
void term();
void statement();
void sens();
void lrparser();

