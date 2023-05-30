#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool isLoggedIn(){
    string username, pwd, un, pw;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> pwd;

    ifstream file(username + ".txt");
    getline(file, un);
    getline(file, pw);
    file.close();
    if(un == username && pw == pwd){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string username, pwd;
    int choice;
    cout << "1. Sign in\n2. Sign Up\n"; cin >> choice;
    switch(choice){
        case 1:{
            bool isUser = isLoggedIn();
            if(!isUser){
                cout << "Sorry User is not registered!\n";
                system("pause");
            } else {
                cout << "You're in!\n";
                exit(1); 
            }
            break;
        } case 2:{
            system("cls");
            cout << "Create account\nEnter Username: "; cin >> username; cout << "Enter password: "; cin >> pwd;
            ofstream write;
            write.open(username + ".txt");
            write << username << "\n" << pwd;
            write.close();
            break;
        }
    }
    system("cls");
    main();
}