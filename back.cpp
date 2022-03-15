#include<iostream>
#include<unistd.h>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class login1
{
    
   
    public:
    long no;
    char pass[20],name[20],gmail[50];
    void inp()
    {
        cout<<setw(40)<<"ENTER DETAILS\n\n";
        cout<<setw(40)<<"NAME:";
        cin.ignore();
        gets(name);
        cout<<setw(40)<<"GMAIL:";
        cin.ignore();
        gets(gmail);
        cout<<setw(40)<<"PASSWORD:";
        cin.ignore();
        gets(pass);
        static int n=100000;
        no=n;
        n++;
    }
    
    
};
class pack
{
    public:
     int num;
    char destination[30],include[100],duration[100];
    long price;
    void inp()
    {
        cout<<setw(50)<<"ENTER DETAILS\n\n\n";
        static int ser_no=0;
        ser_no++;
        num=ser_no;
        cout<<setw(40)<<"ENTER PRICE:";
        cin>>price;
        cout<<setw(40)<<"ENTER INCLUDE:";
        cin.ignore();
        gets(include);
        cout<<setw(40)<<"ENTER DESTINATION:";
        cin.ignore();
        gets(destination);
        cout<<setw(40)<<"ENTER DURATION:";
        cin.ignore();
        gets(duration);
    }
    void disp()
    {
        cout<<setw(80)<<"********************************\n\n";
        cout<<setw(32)<<num<<endl;
        cout<<setw(40)<<"DESTINATION:"<<destination<<endl;
        cout<<setw(40)<<"DURATION:"<<duration<<endl;
        cout<<setw(40)<<"INCLUDES:";
        int i=0;
        for(i=0;include[i]!='\0';i++)
        {
            if(include[i]==' ')
            {
                cout<<endl;
                cout<<setw(40);
            }
            else
            {
                cout<<include[i];
            }
        }
        cout<<endl<<setw(40)<<"price:"<<price;
    }

};
void bling(char ch[])
{
    
    int i;
    
    for(i=0;ch[i]!='\0';i++)
    {
        cout<<ch[i];
        //sleep(1);
    }
}
void begin1();
void front();
void admin();
void login()
{
    system("cls");
    cout<<setw(40)<<"HOLIDAY TARVELS\n\n\n\n\n\n\n";
    long num;
    char passw[20];
    cout<<setw(40)<<"LOGINID:";
    cin>>num;
    cout<<setw(40)<<"PASSWORD:";
    cin.ignore();
    gets(passw);
    fstream file;
    file.open("login.txt",ios::in|ios::binary);
    login1 ob;
    file.read((char*)&ob,sizeof(ob));
    int flag=0;
    while(!file.eof())
    {
        if(num==ob.no)
        {
            if(strcmp(ob.pass,passw)==0)
            {
                flag=1;
                if(num==100000)
                admin();
                else
                front();
            }
        }
        file.read((char*)&ob,sizeof(ob));
    }
    if(flag==0)
    {
        cout<<setw(40)<<"WRONG ID OR PASSWORD TRY AGAIN";
        sleep(2);
        login();
    }
    file.close();
}
void disp(login1 ob)
{
    int n;
    cout<<setw(40)<<"NAME: "<<ob.name<<"\n\n";
    cout<<setw(40)<<"GMAIL: "<<ob.gmail<<"\n\n";
    cout<<setw(40)<<"LOGINID: "<<ob.no<<"\n\n";
    cout<<setw(40)<<"PRESS ENTER TO CONTINUE";
    char ch[10]="......";
    bling(ch);
    cin>>n;
}
void signup()
{
    system("cls");
    cout<<setw(40)<<"HOLIDAY TARVELS\n\n\n\n\n\n\n";
    ofstream file;
    file.open("login.txt",ios::app|ios::binary);
    login1 ob;
    ob.inp();
    file.write((char*)&ob,sizeof(ob));
    cout<<"\n\n";
    disp(ob);
    cout<<setw(40)<<"REGISTERED";
    sleep(2);
    file.close();
    begin1();
    

}
void show_pack();
void inp_pack();
void change_passw();
int main()
{
    system("color FB");
    begin1();
    
    return 0;
}
void inp_pack()
{
    system("cls");
    pack ob;
    ob.inp();
    fstream file;
    file.open("packages.txt",ios::app|ios::binary);
    file.write((char*)&ob,sizeof(ob));
    file.close();
}
void show_pack()
{
    cout<<setw(40)<<"PACKAGES\n\n";
    fstream file;
    file.open("packages.txt",ios::in|ios::binary);
    pack ob;
    file.read((char*)&ob,sizeof(ob));
    while(!file.eof())
    {
        ob.disp();
        file.read((char*)&ob,sizeof(ob));
    }
    sleep(20);
    file.close();
}
void begin1()
{
    system("cls");
    char ch[100]="WELCOME TO HOLIDAY TRAVELS";
    cout<<setw(20);
    bling(ch);
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<setw(50);
    cout<<"1.LOGIN(already have account\n\n\n";
    cout<<setw(50);
    cout<<"2.SIGNUP(create new account)\n\n\n";
    cout<<setw(36);
    cout<<"ENTER YOUR CHOICE";
    char a[100]=".....";
    bling(a);
    cout<<"\b\b\b\b\b";
    bling(a);
    cout<<"       ";
    int n;
    cin>>n;
    if(n==1)
    login();
    else
    signup();
}
void front()
{
    system("cls");
    cout<<"welcome";
}
void admin()
{
    system("cls");
    cout<<setw(40)<<"welcome to admin pannel";
    int n=0;
    while(n!=6)
    {
        system("cls");
    cout<<setw(40)<<"1.INPUT PACKAGES\n\n";
    cout<<setw(40)<<"2.UPDATE PACKAGES\n\n";
    cout<<setw(40)<<"3.DELETE PACKAGES \n\n";
    cout<<setw(40)<<"4.CHANGE PASSWWORD \n\n";
    cout<<setw(40)<<"5.SHOW PACKAGES \n\n";
    cout<<setw(40)<<"6.EXIT \n\n";
    cout<<setw(40)<<"ENTER YOUR CHOICE...";
    cin>>n;
    switch(n)
    {
        case 1:inp_pack();
                break;
        case 5: show_pack();
                break;
        case 4: change_passw();
                break;
    }
    }
}
void change_passw()
{
    int n;
    system("cls");
    cout<<setw(50)<<"CHANGE YOUR PASSWORD\n\n";
    cout<<"\n\n\n";
    cout<<setw(30)<<"ENTER LOGIN ID:";
    cin>>n;
    char num[50];
    cout<<setw(30)<<"ENTER NEW PASSWORD:"'
    
    fstream file;
    file.open("login.txt",ios::app|ios::binary|ios::in);
    login1 ob;
    file.read((char*)&ob,sizeof(ob));
    fstream file1;
    file1.open("xyz.txt",ios::app|ios::binary);
    while(!file.eof())
    {
        if(ob.no!=n)
        {

        }
    }
}