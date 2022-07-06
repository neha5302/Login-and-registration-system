#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t_________________________________________________\n\n\n";
    cout<<"\t\t\t______     Welcome to the login page      _______\n\n\n";
    cout<<"\t\t\t______               Menu                 _______\n\n\n";
    cout<<"\n\n";
    cout<<"\t\t\t|  Press 1 to LOGIN                              |"<<endl;
    cout<<"\t\t\t|  Press 2 to REGISTER                           |"<<endl;
    cout<<"\t\t\t|  Press 3 to FORGOTTEN PASSWORD                 |"<<endl;
    cout<<"\t\t\t|  Press 4 to EXIT                               |"<<endl;
    cout<<endl;
    cout<<"\t\t\t______     Please enter your choice       _______\n\n\n";
    cin>>c;
    cout<<endl;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot(); 
        break;
    case 4:
        system("cls");
        cout<<"\t\t\t______      >>>Thank-you!<<<       _______\n\n\n";
        break;
    default:
        cout<<"Please enter a valid number."<<endl;
        main();
    }
}
void login(){
    int count;
    string userId, password, id, pass;
    // system("cls");
    cout<<"\t\t\t|  Please enter username and password             |"<<endl;
    cout<<">>Username: ";
    cin>>userId;
    cout<<">>Password: ";
    cin>>password;

    ifstream input("records.txt");
    while (input>>id>>pass)
    {
        if (id==userId && pass==password)
        {
            count = 1;
            // system("cls");
        }
        
    }input.close();
    if (count==1)
    {
        cout<<userId<<"\n Login is succesfull ! \n";
        main();
    }
    else{
        cout<<"\n\t\t\t\t    LOGIN ERROR ! \n"<<userId<<" is not registered.\n\n";
        main();
    }
}
void registration(){
    string rUserId, rPassword, rId, rPass;
    // system("cls");
    cout<<">>Enter the username: "<<endl;
    cin>>rUserId;
    cout<<">>Enter the password: "<<endl;
    cin>>rPassword;

    ofstream f1("records.txt", ios::app);
    f1<<rUserId<<' '<<rPassword<<endl;
    // system("cls");
    cout<<"\t\t\t____________ Registration is successfull !!____________\n";
}
void forgot(){
    int option;
    cout<<">>Press 1 to search your ID by username "<<endl;
    cout<<">>Press 2 to go back to the main menu "<<endl;
    cout<<">>Enter your choice "<<endl;
    cin>>option;
    switch (option)
    {
    case 1:
        {
            int count = 0;
            string sUserId, sId, sPass;
            cout<<"\n>>Enter the username which you remember: ";
            cin>>sUserId;

            ifstream f2("records.txt");
            while (f2>>sId>>sPass)
            {
                if (sId==sUserId)
                {
                    count = 1;
                }
                
            }
            f2.close();
            if (count==1)
            {
                cout<<"\n\n\n Your account is found !\n";
                cout<<"\n\n\n Your password is:"<<sPass<<endl;
                main();
            }else{
                cout<<"\n\n\n Account not found \n";
                main();
        
            }
        }
        break;    
        case 2:
            {main();}
            break;
        default:
        cout<<"\t\t\t Wrong choice \n\n"<<endl;
        forgot();
    }
}