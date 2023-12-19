#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;
int main()
{
    fstream f1;
    f1.open("Student.txt",ios::in);
    int ctr = 0;
    char ch;
    while( !f1.eof() )
    {
        f1.get(ch);
        if( ch == 'a' )
            ctr++;
    }
    cout<<ctr;
    f1.close();
    return 0;
}
