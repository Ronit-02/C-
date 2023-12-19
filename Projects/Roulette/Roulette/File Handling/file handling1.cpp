#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

struct student
{
    int admno;
    char name[20];
    int rno;
};
int main()
{
    student s1;
    ofstream write;
    int noOfstudent = 0;
    write.open("Student.txt",ios::app);
    char choice = 'y';
    do
    {
        cout<<"\nEnter the admission no of the student: ";
        cin>>s1.admno;
        cout<<"Enter the name of the student: ";
        cin>>s1.name;
        cout<<"Enter the roll no of the student: ";
        cin>>s1.rno;
        write<<s1.admno<<"\n"<<s1.name<<"\n"<<s1.rno<<"\n";
        cout<<"\nWant to enter more: ";
        cin>>choice;
        noOfstudent++;

    }while(choice == 'y');
    write.close();

    ifstream read;
    read.open("Student.txt");
    cout<<"Details in the file are as follows";
    for ( int i=0; i<noOfstudent; i++ )
    while( read.good() )
    {
        read>>s1.admno;
        read>>s1.name;
        read>>s1.rno;
        cout<<"\nAdmission no: "<<s1.admno<<"\nName :"<<s1.name<<"\nRoll no: "<<s1.rno;
        cout<<endl;
    }
    read.close();
    return 0;
}
