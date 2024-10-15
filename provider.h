/* 
provider.h - header for provider interface 
written by Vi Pham on 04/18/2024
includes provider info collection, provider menu, appointment confirmation, display all patient info, 
display all patient feedback, and calculate weekly copay
using respective functions in authentication.h
*/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
#include <cstring> 

using namespace std;


class ProviderInformationCollection
{
    public :
        char providerName[20];
        int providerID;

        void getInfo()
        {
            cout << "Enter Provider's Name (all lowercase): ";
            cin.get();
            cin >> providerName; 

            cout << "Enter Provider ID: ";
            cin >> providerID;       
        }

        void disInfo(){
            
            cout.setf(ios::left);
            cout <<setw(15)<< providerName <<setw(20)<< providerID <<endl;

        }


};

void confirmAppontment() 
{
    // variables to store patient name, status, and balance 
   

    // open file in append mode
    ofstream outfile("completedAppts.txt", std::ios_base::app);

     // Get first and last name from the user
    string name, insuranceType, status;
    double balance = 0.00; 

    cout << endl;
    cout << "Enter patient name: ";
    cin >> name; 



   ifstream file("patientInfo.txt");
   
    
    string line;
    bool found = false;
 

    // Read each line from the file
    while (getline(file, line)) {
 
           
        istringstream iss(line);
        string searchName;
        string patientBalance;

        // Get the name from the line and convert it to lowercase
        if (getline(iss, searchName, ':')) {
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
            
            // retrieve insurance
            if (searchName == name) {

                // searching for card number 
                for (int i = 0; i < 4; i++) {
                    if (!getline(iss, searchName, ':')) {
                        cout << "Error: Unable to read data." << endl;
                       
                    }
                }

                // display output
                insuranceType = searchName;

            }
        }
    }

    // find copay depending on insurance type 
    if (insuranceType == "unicorn") {
            balance += 25.00;}

    else if (insuranceType == "alien") {
            balance += 50.00; }
    else {
        balance += 100.00;   }


    // ask about patient's status 
    cout << "Was the patient's appointment completed, late, or canceled?\n";
    cout << "Enter the patient's appointment status: ";
    cin >> status; 

    // add co-pay or late fee as needed 
    if (status == "late") {
        balance += 50.00;
    }
    else if (status == "canceled") {
        balance += 100.00;
    }


    // Append the first and last name to the file
    outfile << name << ":" << status << ":" << balance << ".00" << endl;
    
    // Close the file
    file.close();
    outfile.close();

    cout << "\nRecorded. Thanks, Doc!" << endl; 
    cout << endl; 


}


void displayAllPatients(){
    // Open the text file
    ifstream file("patientInfo.txt");
    string line;

    // Read each line
    while (getline(file, line)) {
        // Create a string stream to split the line
        stringstream ss(line);
        string item;
        vector<string> values;

        // Split the line by ":" delimiter
        while (getline(ss, item, ':')) {
            values.push_back(item);
        }

        // Display the values
        if (values.size() >= 5) {
            // Extract individual values
            string name = values[0];
            string id_number = values[1];
            string dob = values[2];
            string phone = values[3];
            string species = values[4];

            // Display the values
            cout << "Name: " << name << endl;
            cout << "ID Number: " << id_number << endl;
            cout << "Date of Birth: " << dob << endl;
            cout << "Credit Card Number: " << phone << endl;
            cout << "Insurance: " << species << endl;
        } else {
            cout << "Invalid line format" << endl;
        }

        // Add extra line for clarity
        cout << endl;
    }

    file.close();

}

void displayAllFeedback(){
    ifstream file("feedback.txt");
    string line;

    // Read each line
    while (getline(file, line)) {
        // Check if the line starts with "Name: "
        if (line.find("Name: ") == 0) {
            // Extract name
            string name = line.substr(6);

            // Read ID, Date, and Rating from the next three lines
            string id, date, rating;
            getline(file, line); // Read ID line
            id = line.substr(4);

            getline(file, line); // Read Date line
            date = line.substr(6);

            getline(file, line); // Read Rating line
            rating = line.substr(8);

            // Display the feedback
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Date: " << date << endl;
            cout << "Rating: " << rating << endl;
            cout << "---------------------------" << endl;
        }
    }

    // Close the file
    file.close();

}

void weeklyCopay(){
    ifstream file("weeklyCopay.txt");
    string line;
    int sum = 0;

    // Read each line
    while (getline(file, line)) {
        // Convert the line to an integer and add it to the sum
        sum += stoi(line);
    }

    // Close the file
    file.close();

    // Display the sum
    cout << "Th weekly copay is : $" << sum << ".00" << endl;
}

// provider interface 
void displayProviderMenu(){

     int choice;
    
start: 

    cout << endl;
    cout << "*********************************************************************\n";
    cout <<"....................... WELCOME TO CALENDOC .........................\n";
    cout <<"............................ Provider ...............................\n";
    cout << "*********************************************************************\n";
    cout<< endl;

        cout << "\tChoose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. View all Patients \n";
        cout << "\t2. View all Feedck\n";
        cout << "\t3. Check Weekly Copay\n";
        cout << "\t4. Confirm Appointment Status\n";
        cout << endl;
        cout << "Please Enter your Preferred Choice : ";
        cin >> choice;
        cout << endl; 

        // input validation
       while (!(choice > 1 || choice < 5))
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            cout << "Please Enter your Preferred Choice : ";
            cin >> choice;
         
        }

    switch (choice)
    {
        case 1:  
            {
                displayAllPatients();
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu(); 
            }
            break;

          case 2:
            {   
                displayAllFeedback();
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu(); 

            }
            break; 

        case 3:
            {    
                weeklyCopay();
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu(); 
            }
        break;

        case 4 : 
            {
                confirmAppontment(); 
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayProviderMenu();
            }
        break;

}
}