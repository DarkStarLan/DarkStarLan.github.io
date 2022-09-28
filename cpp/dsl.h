#pragma once
#include <iostream>
using namespace std;
#include <string>
#include<stdlib.h>  //rand头文件 
#include<ctime>  //srand头文件 
#include<Windows.h>
#include<fstream>  //读写文件

string ssg(const string& str, const int& st, const int& en);
string sj(const string& str, const string& st, const string& en);
void syso(const string& str);
void syso(const string& str, const bool& mode);
void syso(const int& str);
void syso(const int& str, const bool& mode);
string ss_add(const string& str1, const string& str2);
void siof(const string& str, const string& goal, int& name);
void siof(const string& str, const string& goal, const int& add, int& name);
int siof(const string& str, const string& goal);
int siof(const string& str, const string& goal, const int& add);
int* sl(const string& str, const string& goal);
int slg(const string& str);
void slg(const string& str, int& name);
string strim(const string& str);
void sr(string str, const char& cha1, const char& cha2, string& name);
string sr(string str, const char& cha1, const char& cha2);
void sr(string& str, const char& cha1, const char& cha2);
int sran(const int& first, const int& last);
void sran(const int& first, const int& last, int& name);
void sranh();
void stop(const int& time);
void forsyso(const string& str);
void forsyso(const string& str, const bool& mode);
void isystem(const string& str_first, const string& str_last);
short numb(int num, const int& bit);
void HideWindow();
void BubbleSort(int* p, const int& len);
void PrintArray(const int* p, const int& len);
bool ifin(const string& str, const string& goal);
bool isInRange(const float& flo1, const float& flo2, const float& range);
float isInRange(const float& flo1, const float& flo2);
float isInRange(const float& flo1, const float& flo2, const bool& mode);
