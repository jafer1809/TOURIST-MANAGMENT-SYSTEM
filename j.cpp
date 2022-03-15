#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class login1
{
    
   
    public:
     long no;
    char pass[10];
    void inp()
    {
        cin>>no;
        cin.ignore();
        gets(pass);
        
    }
    void disp(){
        cout<<no<<"  "<<pass;
    }
    
};
void login()
{
    long n;
    char s[10];
    cout<<"ENTER ID:";
    cin>>n;
    cin.ignore();
    cout<<"ENTER PASS:";
    gets(s);
    fstream file;
    file.open("login.txt",ios::in);
    login1 ob;
     file.read((char*)&ob,sizeof(ob));
     ob.disp();
    while(!file.eof())
    {
       
        if(ob.no==n)
        {
            if(strcmp(s,ob.pass)==0)
            cout<<"welcome";
            else
            {
                cout<<"wrong";
                break;
            }
            
        }
        else
        cout<<"wrong id";
         file.read((char*)&ob,sizeof(ob));
    }

file.close();
}
void signup()
{
    ofstream file;
    file.open("login.txt",ios::app|ios::binary);
    login1 ob;
    ob.inp();
    file.write((char*)&ob,sizeof(ob));
    cout<<"registered";
    file.close();
}
int main()
{
    int n;
    cout<<"1.login"<<endl<<"2.signup";
    cin>>n;
    if(n==1)
    login();
    else
    {
        signup();
    }
    
}