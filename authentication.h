// authentication.h - authentication header file 
// written by Maryam Dawood on 04/16/2024
// edited by Vi Pham on 04/25/2024
// authentication.h includes all functions related to the login page
// as well as taking either patient, provider, or admin to their 
// respective interface. The header file also includes 
// login functionality, registration, and password recovery. 


#include <iostream>
#include <fstream> 
#include <string> 
#include <random>

// must be included to retreive respective interface
#include "patient.h"
#include "admin.h"
#include "provider.h"

// redirects to perspective interface after entering login credentials 
void switchDisplays(int firstNum) {

        // if users id starts with 1 then display patient interface
        if (firstNum == 1) {
            displayMenuPatient(); 
        } 
        // if users id starts with 2 then display provider interface
        else if (firstNum == 2) {
            displayProviderMenu(); 
        } 
        // if users id starts with 3 then display admin interface
        else if (firstNum == 3) {
            displayAdminMenu(); 
        } 
}


//asking patient to enter their ID and Password 
//checking that the login info matches what's saved in records.txt
//if the login info matches what's saved then we can pass the first digit 
//of the id to switchDisplays() to display the respective interface. 
//ELSE: the info entered does not match and we display error message 
void login() {
start: 
    int count = 0;
    string  password, pass; 
    string userId, id; 
    cout << "\t\t\tPlease enter the username & password" << endl; 
    cout << "\t\t\tID: ";
    cin >> userId; 
    cout << "\t\t\tPASSWORD: ";
    cin >> password; 

    ifstream input("records.txt");
       while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << "\nSuccessufl login!\n" << endl; 
        int firstDigit = std::stoi(userId) / 10000;
        switchDisplays(firstDigit); 
    
    } else {
        cout << "\nLOGIN ERROR. Please check your username and password\n";
        goto start; 
    }
}

//allowing the user to register an account as a provider, admin, or patient
//it will ask what role the user falls in. If the user selects patient then the system will generate a 
//random five digit ID starting with 1. Provider ID starts with 2. Admin ID starts with 3. If 
//the user types a role that does not exist we display an error message saying that role does not exist and call the 
//registration function again. 
//Once the user has their ID they are prompted to enter the password. Both ID and password are then saved 
//to "records.txt" with a " " in between. 


void registration() {

    // OFFICE CREDENTIALS 
    string officePassword = "ChickenWing11"; 
    string userInput; 

    string role; 
    cout << "Are you a Patient, Provider, or Administrator? " << endl; 
    cin.ignore();
    cin >> role; 

    

    if(role == "Patient" | role == "patient"){
        string rpassword, rpass;

        random_device rd;
        mt19937 gen(rd());
        
        // Define the distribution for five-digit numbers starting with 1
        uniform_int_distribution<> dis(10000, 19999);
        
        // Generate a random five-digit ID
        int id = dis(gen);
        
        // Output the generated ID
        cout << "Generated five-digit ID: " << id << endl;
        
    
        cout << "\n\t\t\tCreate a password :";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << id << ' ' << rpassword << endl;

        cout << "\n\t\t\tRegistration was successful!\n";


    } else if (role == "Provider" | role == "provider"){

        // input validation so only the office can create a provider account 
        cout << endl; 
        cout << "Enter office password: ";
        cin.ignore();
        getline(cin, userInput); 

        while (userInput != officePassword)
        {
            cout << "Incorrect password. Please try again: ";
            cin.ignore();
            getline(cin, userInput);

        }

        string  rpassword, rpass;
        random_device rd;
        mt19937 gen(rd());
        
        // Define the distribution for five-digit numbers starting with 2
        uniform_int_distribution<> dis(20000, 29999);
        
        // Generate a random five-digit ID
        int id = dis(gen);
        
        // Output the generated ID
        cout << "Generated five-digit ID: " << id << endl;

        cout << "\n\t\t\tCreate a password: ";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << id << ' ' << rpassword << endl;

    } else if (role == "Admin" | role == "admin"){
        cout << endl; 
        cout << "Enter office password: ";
        cin.ignore();
        getline(cin, userInput); 
        

        while (userInput != officePassword)
        {
            cout << "Incorrect password. Please try again: ";
            getline(cin, userInput);
            cin.ignore();
            cout << endl;
        }

        string rpassword, rpass;
        random_device rd;
        mt19937 gen(rd());
        
        uniform_int_distribution<> dis(30000, 39999);
        
        int id = dis(gen);
        
        cout << "Generated five-digit ID: " << id << endl;
        cout << "\n\t\t\tCreate a password: ";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << id << ' ' << rpassword << endl;
    } else {
        cout << "\nNo such role exists, try again.\n" << endl; 
        registration(); 
    }
    


    

}

//If the user forgets their password we can look up their password using their username. 
//Tthe program will ask the user to enter their username and then check if the username matches anything we have in records.txt. 
//If it is found we set count to 1 followed by another if statement that checks if count is set to 1 or 0. 
//If count is set to 1 we display the password. If count is set to 0 that means the username does not exist 
//in records.txt and it will display a message saying that the account was not found. 

void forgot(){
    int option;

    cout << "\t\t\tYou forgot your password? No worries!\n";
    cout << "Search your id by username: " << endl;



            int count=0;
            string suserId,sId,spass;
            cout<<"\n\t\t\tEnter the username which you remembered: ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count=1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\n\n\tYour account is found.\n";
                cout<<"\n\tYour password is "<<spass << endl; 
            }
            else
            {
                cout<<"\n\tAccount not found! \n";
            }
    
}