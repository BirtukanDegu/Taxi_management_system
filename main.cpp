#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;


char first_name[100];
char last_name[100];
string full_name;
string username, username_login,password, password_login;
string initial_point, destination_point,initial_time, tariff;


fstream taxi_info;

void registr();
void login();
void display_taxi_details();
void add_user_details();
void add_taxi_details();
void admin_mode();
void user_mode();
void user_menu();
void admin_menu();

int main()
{
    system("cls");
    system("color 02");
    int ch;
    cout<<"\n\n\n\n\t\t----------------------------------------------------------------------\n";
    cout<<"\t\t                              WELCOME   \n";
    cout<<"\t\t----------------------------------------------------------------------\n";
	cin.get();
    system("cls");

    do
    {
         system("cls");

        cout<<"\n\n\t\t---------------------------------------------------------------------\n";
        cout<<"\t\t                         MAIN MENU\n";
        cout<<"\t\t---------------------------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t1.Admin mode\n\t\t\t\t\t2.User mode\n\t\t\t\t\t3.Exit\n\n";
        cout<<"\t\t---------------------------------------------------------------------\n";
        cout<<"\t\t\t\tEnter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)

        {
        case 1:
            admin_mode();
            break;
        case 2:
            user_mode();
            break;
        case 3:
            exit(0);

        }
    }
    while(ch<=3);
    return 0;
}


void admin_mode()
{
    cin.get();
    system("cls");
    string password;
    string pass="123";
    int i=0;
    int n=i+1;
    cout<<"\n\n\n\t\t\tYou have three attempts to login.\n\n";
    while(password!=pass, i<3)
    {
        cout<<"\t\t\tAttempt# "<<n<<endl;
        cout<<"\t\t\tEnter password: ";
        cin>>password;
        i++;
        n++;
        if(password!=pass)
        {
            cout<<"\t\t\tTry again...\n\n";
        }
        else
        {
            pass="123";
            i=3;
        }
    }
    if(password==pass)
    {
        cout<<"\n\t\t\tYou have successfully logged in\n";
        cout<<"\t\t\t"<<system("pause");
        admin_menu();
    }
    else
        cout<<"\t\t\tYou have finished your attempts.\n\t\t\tTry again later.";
        cin.get();
        cin.get();
        exit(0);

}


void admin_menu()
{
    int ch;
    do
        {
            system("cls");
            cout<<"\n\n\t\t---------------------------------------------------------------------\n";
            cout<<"\t\t                         ADMINISTRATOR MENU\n";
            cout<<"\t\t---------------------------------------------------------------------\n\n";
            cout<<"\t\t\t\t1.Add taxi details\n";
            cout<<"\t\t\t\t2.View taxi details\n";
            cout<<"\t\t\t\t3.Exit\n\n";
            cout<<"\t\t---------------------------------------------------------------------\n";
            cout<<"\t\t\t\tEnter your choice:";
            cin>>ch;


            cout<<endl;
            switch(ch)
            {
            case 1:
                cin.get();
                system("cls");
                add_taxi_details();
                break;
            case 2:
                display_taxi_details();
                cout<<"\n\n\t\t\t"<<system("pause");
                 break;
            case 3:
                exit(0);
                break;
            }
        }
        while(ch<=3);
}

void add_taxi_details()
{
    char c;
    int i=0;


        do
        {

            cout<<"\n\n\t\t---------------------------------------------------------------------\n";
            cout<<"\t\t                         ADD TAXI DETAILS\n";
            cout<<"\t\t---------------------------------------------------------------------\n\n";

            cout<<"\t\t\t\tEnter initial point: ";
            cin>>initial_point;
            cout<<"\t\t\t\tEnter destination point: ";
            cin>>destination_point;
            cout<<"\t\t\t\tEnter the initial time: ";
            cin>>initial_time;
            cout<<"\t\t\t\tEnter the tariff: ";
            cin>>tariff;
            cout<<endl;

            ofstream taxi_info;
            taxi_info.open("taxi_info.txt", ios::out|ios::app);
            taxi_info<<"["<<++i<<"]\t\t"<<initial_point<<"\t\t"<<destination_point<<"\t\t"<<initial_time<<"\t\t"<<tariff<<endl;
            taxi_info.close();

            cout<<"\t\t\t\tINFO: New taxi has been added successfully!\n\n";
            cout<<"\t\t\t\tDo you want to add one more record?\n";
            cout<<"\t\t\t\ty|Y-for Yes and\n\t\t\t\tAny key for No ";
            cin>>c;

            cin.get();
            system("cls");
          }
        while(c=='y' || c=='Y');

}


void user_mode()
{
        bool login_successful = false;
        int option, remain = 3;
        h:;
        system("cls");
        cout<<"\n\n\t\t---------------------------------------------------------------------\n";
        cout<<"\t\t                         USER MENU\n";
        cout<<"\t\t---------------------------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t1.Signup\n";
        cout<<"\t\t\t\t\t2.Login\n";
        cout<<"\t\t\t\t\t3.Forgot password\n";
        cout<<"\t\t\t\t\t4.Exit\n\n";
        cout<<"\t\t---------------------------------------------------------------------\n";
        cout<<"\t\t\t\tEnter your choice:";
        cin>>option;

        if(option==1)
        {
            cin.get();
            system("cls");
            cout<<"\n\n\t\t---------------------------------------------------------------------\n";
            cout<<"\t\t                         CREATE ACCOUNT\n";
            cout<<"\t\t---------------------------------------------------------------------\n\n";
            cout<<"\t\t\t\tEnter your first name: ";
            cin>>first_name;
            cout<<"\t\t\t\tEnter your last name: ";
            cin>>last_name;
            cout<<"\t\t\t\tEnter the user name of your choice: ";
            cin>>username;
            cout<<"\t\t\t\tEnter the password of your choice: ";
            cin>>password;
            cout<<endl;
            ofstream user_info;
        user_info.open("user_" + username + ".txt");
        user_info<<first_name<<"\t"<<last_name<<endl<<username<<endl<<password<<endl;
        user_info.close();

        cout<<"\t\t\t\tINFO: your account has been created successfully!\n\n";
        cout<<"\t\t\t\t"<<system("pause");
        goto h;
        }
            else if (option == 2)
    {
        do
        {

            system("cls");

            cout << "\n\n\n\t\t-----------------------------LOGIN-----------------------------\n\n";
            cout << "\t\t\t\tNow, log in your account" << endl;
            cout << endl << "\t\t\t\tType in your username: ";
            cin >> username_login;
            cout << "\t\t\t\tType in your password: ";
            cin >> password_login;
            ifstream find_account;
            find_account.open("user_" + username_login + ".txt");
            getline(find_account, full_name);
            getline(find_account, username);
            getline(find_account, password);
            if (username_login == username && password_login == password)
            {
                cin.get();
                system("cls");
                cout << endl << "\n\n\n\t\t\t\tYou have logged in successfully!" << endl << endl;
                login_successful = true;
                cout<<"\t\t\t\t"<<system("pause");
                user_menu();
            }
            else
            {

                cout << endl << "\t\t\t\tInvaild username or password \n\t\t\t\tYou have " << remain << " attempts left to try! \n\t\t\t\tPlease try again!" << endl;
                remain--;
                login_successful = false;
                cout<<"\t\t\t\t"<<system("pause");

            }
        }
        while (!login_successful && remain != 0);
        if (remain == 0)
        {

            cout << "\n\t\t\t\tYou have 0 attempts left to try" << endl << "\t\t\t\tThe program will now exit";
            cout<<"\n\n\t\t\t\t"<<system("pause");

        }
    }
        else if (option == 3)
    {
        cout << "\n\n\n\t\t\t\tType in your username: ";
        cin >> username;
        ifstream find_account("user_" + username + ".txt");
        if (find_account.is_open())
        {
            getline(find_account, full_name);
            getline(find_account, username);
            getline(find_account, password);
            cout << "\t\t\t\tYour password is: " << password << endl << endl;
            cout<<"\t\t\t\t"<<system("pause");
            goto h;
        }
        else
        {
            cout << "\t\t\t\tSorry,we couldn't find your account!" << endl << endl;
            cout<<"\t\t\t\t"<<system("pause");
            goto h;
        }
        main();
    }
    else if(option == 4)
        exit(0);
}

void user_menu()
{
    int ch2;
        do
        {
            system("cls");
            cout<<"\n\n\t\t---------------------------------------------------------------------\n";
            cout<<"\t\t                         USER MENU\n";
            cout<<"\t\t---------------------------------------------------------------------\n\n";
            cout<<"\t\t\t\t1.View taxi details\n";
            cout<<"\t\t\t\t2.Exit\n";
            cout<<"\t\t\t\t3.Return to the main menu\n\n";
            cout<<"\t\t---------------------------------------------------------------------\n";
            cout<<"\t\t\t\tEnter your choice:";
            cin>>ch2;
            cout<<endl;
            switch(ch2)
            {
            case 1:
                {
                display_taxi_details();
                ifstream taxi_info("taxi_info.txt",ios::in);
                if(!taxi_info)
                   break;

                 string line;
                 string srch;

                 cout<<"\n\t\t\tEnter your choice: ";
                 cin.ignore();
                 getline(cin, srch);

                bool found = false;
                while(getline(taxi_info,line)) {
                if(line.find(srch) != std::string::npos) {
                found = true;
                cout<<"\n\n\t\t\tYour choice is: \n\n";
                cout <<"\t\t\t\t"<< line << endl;

                break;
                }
                }
                if (found == false)
                    cout<<"Record Not Found!";
                    cout<<"\n\n\t\t\t"<<system("pause");
                }

                break;
            case 2:
                 exit(0);
                 break;

            }
        }
        while(ch2<=2);

}

void display_taxi_details()
{
    cin.get();
    system("cls");
    cout<<"\n\n\t\t\t-------------------------------------------------------------------------------\n";
    cout<<"\t\t\t\t                         AVAILABLE TAXIS\n";
    cout<<"\t\t\t-------------------------------------------------------------------------------\n\n";
    cout<<"\t\t\t\tinitial_point  |  destination_pont  |  initial_time  |  tariff\n";
    cout<<"\t\t\t-------------------------------------------------------------------------------\n\n";
    string line;
    ifstream taxi_info("taxi_info.txt",ios::in);
    if(!taxi_info)
    {
       cerr<<"\t\t\tFile not found!"<<endl;
       cout<<"\n\n\t\t\t"<<system("pause");
    }

    else
    {
        while(getline(taxi_info, line)){
        cout<<"\t\t\t\t"<<line<<endl;
        }
    }
}

