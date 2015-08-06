#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<windows.h>

using namespace std;

int main()
{
    fstream fp;
    char spass[25],lpass[25];

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;


    fflush(stdin);
    fp.open("spass.dat",ios::in);
    fp.read((char *)(&spass), 25);
    fp.close();

    fflush(stdin);
    fp.open("lpass.dat",ios::in);
    fp.read((char *)(&lpass), 25);
    fp.close();

    cout<<"\n\nThe student password is "<<spass;
    cout<<"\n\nThe librarian password is "<<lpass<<endl;
    getchar();

    return 0;
}

