/* 
login.cpp
written by Maryam Dawood & Vi Pham on 04/14/24
login interface that redirects to patient, provider, or admin interface
using respective functions in authentication.h
*/

#include<iostream>
#include <fstream> 
#include <string> 

using namespace std;
//login functions saved in this header file
#include "authentication.h"

int main()
{
        //display menu and get use choice 
        int c;   

        cout << endl;
        cout << "*********************************************************************\n";
        cout <<"....................... WELCOME TO CALENDOC .........................\n";
        cout <<"............................ Login Page .............................\n";
        cout << "*********************************************************************\n";
        cout<< endl;
        cout<<"  Press 1 to LOGIN                    "<<endl;
        cout<<"  Press 2 to REGISTER                 "<<endl;
        cout<<"  Press 3 if PASSWORD RECOVERY        "<<endl;
        cout<<"  Press 4 to EXIT                   \n "<<endl;
        cout<<"  Please Enter your choice: " ; 
        cin>>c;
        cout << endl; 

        //switch statements for user's choice 
        switch(c)
        {
        

                case 1: 
                {
                        login();
                } 
                break;
                case 2: 
                /*
                registers new user 
                patient id starts w/ "1", provider id starts w/ "2", and admin starts w/ "3"
                stores random generated id to records.txt in the format:
                id:password
                */

                {
                        registration();
                        main(); 
                }
                break;

                case 3:
                {
                        forgot();
                        main(); 

                }
                break;
                case 4:
                {
                        cout<<"  Thank you! Be well.\n\n";
                }
                break;

                default:
                {
                        cout<<"  Please select from the options given above. Please try again.\n"<<endl;
                        main();
                }
        }

}






      

