#include<iostream>
#include<fstream>
#include<string>

using namespace std;
bool IsloggedIn(){
    string username,password,un,pw;
    cout<<"enter username:"; cin>>username;
    cout<<"enter password:"; cin>>password;
    
    ifstream read("c:\\"+username+".txt");
    getline(read,un);
    getline(read,pw);

    if(un==username && pw==password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(){
    int choice;
    cout<<"1:register\n2:login\nyour choice:"; cin>>choice;
    if(choice==1)
    {
        string username,password;
        cout<<"select a username:"; cin>>username;
        cout<<"select a password:"; cin>>password;

        ofstream file;
        file.open("c:\\"+username+".txt");
        file<<username<<endl<<password;
        file.close();
        main();

    }
    else if (choice==2){
        bool status = IsloggedIn();
        if (!status)
        {
            cout<< "false login!"<< endl;
            system("pause");
            return 0;
        }
        else
        {
            cout<<"succesfully logged in!"<<endl;
            system("pause");
            return 1;
        }
    }
}
