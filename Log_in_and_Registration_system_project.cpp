#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;
    cout << "\t\t\t______________________________________________________\n\n\n";
    cout << "\t\t\t             Welcome to the Login page                \n\n\n";
    cout << "\t\t\t_________________     MENU     ________________________\n\n";
    cout << "                                                                       \n\n";
    cout << "\t| Press 1 to LOGIN                    |" << endl;
    cout << "\t| Press 2 to to REGISTER              |" << endl;
    cout << "\t| Press 3 if you forgot your PASSWORD |" << endl;
    cout << "\t| Press 4 to EXIT                     |" << endl;
    cout << "\n\t\t\t Please Enter Your choice : ";
    cin >> choice;
    cout << endl;

    switch(choice)
    {
        case 1 :
            login();
            break;
        case 2 :
            registration();
            break;
        case 3 :
            forgot();
            break;
        case 4 :
            cout << "\t\t\tThank You \n\n";
            break;
        default :
            system("cls");
            cout << "\t\t\t Please select from the options given above \n" << endl;
            main();
    }

}

void login()
{
    int cnt;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");
    while(input >> id >> pass)
    {
        if(id==userId && pass == password)
        {
            cnt=1;
            system("cls");

        }

    }
    input.close();
    if(cnt ==1)
    {
        cout << userId << " \n Your LOGIN is successfull \n Thanks for logging in \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your user name and password";
        main();
    }

}

void registration()
{
    string ruserId, rpassword, rid,rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password ; ";
    cin >> rpassword;

    ofstream f1("records.txt",ios::app);
    f1 << ruserId << " " << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful \n";

    main();

}
void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password ? No worries " <<endl;
    cout << "Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> option;

    switch(option)
    {
    case 1 :
        {
            int cnt =0;
            string suserId,sId,spass;
            cout << "\n\t\t\t Enter the username which you remembered :";
            cin >> suserId;

            ifstream f2("records.txt");
            while(f2 >> sId >> spass)
            {
                if(sId ==suserId) cnt=1;
            }
            f2.close();
            if(cnt==1)
            {
                system("cls");
                cout << "\n\n Your account is found \n";
                cout << "\n\n Your password is : " << spass;
                main();
            }
            else
            {
                system("cls");
                cout << "Your account is not found \n";

                main();
            }break;
        }

    case 2:
        {
            main ();
            break;
        }
    default : cout << "\t\t\t Wrong choice ! Please try again " << endl;
            forgot();
    }
}
