#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<windows.h>

using namespace std;

int main()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    string s;

        cout<<"Enter the string \n";
        getline(cin, s);
        cout<<endl<<s;

	getchar();	
    return 0;
}
