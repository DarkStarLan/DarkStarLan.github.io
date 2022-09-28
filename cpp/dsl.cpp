#include"dsl.h"

string ssg(const string& str, const int& st, const int& en)
{
    string a;
    if (en - st < 2)
    {
        return "";
    }
    else if (en < str.length())
    {
        for (int i = 1; i < (en - st); ++i)
        {
            a += str[st + i];
        }
        cout << "ok" << endl;
    }
    else
    {
        return "";
    }
    return a;
}
string sj(const string& str, const string& st, const string& en)
{
    if (st == en) return "";
    int first = str.find_first_of(st);
    int last = str.find_last_of(en);
    if (last > first) return "";
    string a;
    for (int i = 1; i < (last - first); ++i)
    {
        a += str[first + i];
    }
    return a;
}
void syso(const string& str){
    cout << str << endl;
}
void syso(const string& str, const bool& mode) {
    if (mode) cout << str << endl;
    else cout << str;
}
void syso(const int& str) {
    cout << str << endl;
}
void syso(const int& str, const bool& mode) {
    if (mode) cout << str << endl;
    else cout << str;
}
string ss_add(const string& str1, const string& str2)
{
    return str1 + str2;
}
void siof(const string& str, const string& goal, int& name) {
    name = str.find(goal);
}
void siof(const string& str, const string& goal, const int& add, int& name) {
    if (str.find(goal) - add < 0) name = -1;
    name = str.find(goal) - add;
}
int siof(const string& str, const string& goal) {
    return str.find(goal);
}
int siof(const string& str, const string& goal, const int& add) {
    if (str.find(goal) - add < 0) return -1;
    return str.find(goal) - add;
}
int* sl(const string& str, const string& goal)
{
    int num = 0, i = 0;
    while (true)
    {
        num = str.find(goal, num + 1);
        if (num == -1) break;
        i++;
    }
    int* a = new int[str.length() - i];
    num = 0;
    while (true)
    {
        int temp = num;
        num = str.find(goal, num + 1);
        if (num == -1) break;
        for (int k = 0; k < temp - num; ++k)
        {
            *(a + i) = str[num * 2 - temp + k];
        }
    }
    return a;
}
int slg(const string& str) {
    return str.length();
}
void slg(const string& str, int& name) {
    name = str.length();
}
string strim(const string& str) {
    int i = 0, k = 0;
    for (; i < str.length(); ++i)
    {
        if (str[i] != ' ') break;
    }
    for (; k < str.length(); ++k)
    {
        if (str[str.length() - 1 - k] != ' ') break;
    }
    string a;
    cout << "ok" << i << k << endl;
    for (int j = 0; j < str.length() - k - i; ++j)
    {
        a += str[i + j];
    }
    return a;
}
void sr(string str, const char& cha1, const char& cha2, string& name) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == cha1) str[i] = cha2;
    }
    name = str;
}
string sr(string str, const char& cha1, const char& cha2) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == cha1) str[i] = cha2;
    }
    return str;
}
void sr(string& str, const char& cha1, const char& cha2) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == cha1) str[i] = cha2;
    }
}
int sran(const int& first, const int& last) {
    return rand() % last + 1 + first;
}
void sran(const int& first, const int& last, int& name) {
    name = rand() % last + 1 + first;
}
void sranh() {
    srand((unsigned int)time(NULL));
}
void stop(const int& time) {
    Sleep(time);
}
void forsyso(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        cout << str[i] << endl;
    }
}
void forsyso(const string& str, const bool& mode) {
    int len = str.length();
    if (mode) {
        for (int i = 0; i < len; ++i) {
            cout << str[i] << endl;
        }
    }
    else {
        for (int i = 0; i < len; ++i) {
            cout << str[len - 1 - i] << endl;
        }
    }
}
void isystem(const string& str_first, const string& str_last) {
    system((str_first + str_last).c_str());
}
short numb(int num, const int& bit) {
    int temp = num, len = 0;
    while (temp > 0) {
        temp /= 10;
        ++len;
    }
    if (len < bit) return -1;
    return num / short(pow(10, len - bit)) % 10;
}
void HideWindow() {
    HWND hwnd = GetForegroundWindow();
    if (hwnd) ShowWindow(hwnd, SW_HIDE);
    //#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
}
void BubbleSort(int * p, const int& len) {
    for (int i = 0; i < len; ++i) {
        for (int k = 0; k < len - i - 1; ++k) {
            if (*(p + k) > *(p + k + 1)) {
                int temp = *(p + k);
                *(p + k) = *(p + k + 1);
                *(p + k + 1) = temp;
            }
        }
    }
}
void PrintArray(const int* p, const int& len) {
    for (int i = 0; i < len; ++i) {
        cout << *p << endl;
        p++;
    }
}
bool ifin(const string& str, const string& goal) {
    if (str.find(goal) >= str.length()) return false;
    return true;
}
bool isInRange(const float& flo1, const float& flo2, const float& range) {
    if (flo1 - flo2 < 0 && flo2 - flo1 <= range + 0.00000005f) return true;
    else if (flo1 - flo2 > 0 && flo1 - flo2 <= range + 0.00000005f) return true;
    return false;
}
float isInRange(const float& flo1, const float& flo2) {
    if (flo1 - flo2 < 0) return flo2 - flo1 - 0.00000005f;
    return flo1 - flo2 - 0.00000005f;
}
float isInRange(const float& flo1, const float& flo2, const bool& mode) {
    if (flo1 - flo2 < 0) return flo2 - flo1 - mode * 0.00000005f;
    return flo1 - flo2 - mode * 0.00000005f;
}
void fw(const ifstream& ifs, const string& load, const string& str) {
    ifs.
}
