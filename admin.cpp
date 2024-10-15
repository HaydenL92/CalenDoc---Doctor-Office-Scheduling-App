#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;

//charge patient copay 
//reset weekly earnings 
//admin cancel app. (copy)
//admin schedule app. (copy)
//clears day and completed appointments text files 
//search for outstanding balance



void clearBalance(string name)
{

    ifstream inputFile("completedAppts.txt");
    ofstream outputFile("records.txt");
    string line;

    bool nameFound = false;

    while (getline(inputFile, line)) {
        string currentName;
        istringstream iss(line);
        if (getline(iss, currentName, ':')) {
            transform(currentName.begin(), currentName.end(), currentName.begin(), ::tolower);
            if (currentName != name) {
                outputFile << line << endl;
            } else {
                nameFound = true;
            }
        }
    }

     if (nameFound) 
     {
        remove("completedAppts.txt");
        rename("records.txt", "completedAppts.txt");
        cout << "Patient successfully charged!" << endl;
    }
    else
        {
            remove("records.txt");
            cout << "Appointment not found for the given name." << endl;
        }

    inputFile.close();
    outputFile.close();

    
}

void chargePatient() {

    string name;
    
    // Ask the user to input a name
    cout << "Enter a name to search for: ";
    cin.ignore();
    getline(cin, name);
    
    // Convert the user input to lowercase
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    
    // Open the file
    ifstream file("patientInfo.txt");
   
    
    string line;
    string anotherLine;
    bool found = false;
 

    // Read each line from the file
    while (getline(file, line)) {
 
           
        istringstream iss(line);
        string searchName;
        string patientBalance;
        // Get the name from the line and convert it to lowercase
        if (getline(iss, searchName, ':')) {
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
            
            // retrieve patient info if name matches 
            if (searchName == name) {

                // searching for card number 
                for (int i = 0; i < 4; i++) {
                    if (!getline(iss, searchName, ':')) {
                        cout << "Error: Unable to read data." << endl;
                       
                    }
                }

                // display output
                cout << "\nCard Number: " << searchName << endl;
                cout << name << " has been charged.\n"; 
                found = true;

            }
        }
    }

    file.close();

   ifstream infile("completedAppts.txt");
    ofstream outfile("temp.txt");


        // Read each line from the file
    while (getline(infile, anotherLine)) {
                istringstream iss(anotherLine);
                string search;
    

        
        // Get the name from the line and convert it to lowercase
        if (getline(iss, search, ':')) 
        {
            transform(search.begin(), search.end(), search.begin(), ::tolower);

            
            // retrieve patient info if name matches 
            if (search == name) {

                found = true;
                // searching for balance 
                for (int j = 0; j < 2; j++) {
                    if (!getline(iss, search, ':')) {
                        cout << "Error: Unable to read data." << endl;
                        
                    }

                }

                // display output
                cout << "Balance Paid: $" << search << "\n" << endl;
                

            }

     

            
        }
            

       
    }

   
    //input validation
        if (!found)
        {
            cout << "No charges found.\n";
        }
    
    // Close the file
    infile.close();

    char answer;
    cout << "Would you like to clear the patient's balance? (y or n)\n";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        clearBalance(name);
    }
// Maraym: else returns back to menu 
    

    

}




void resetAppointmentFiles() 
{
    std::ofstream ofs;
    ofs.open("Monday.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("Tuesday.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("Wednesday.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("Thursday.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("Friday.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void resetEarnings()
{

}


int main()
{
    cout << "*********************************************************************\n";
    cout <<"..............CalenDoc Admin Interface ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;
    do
    {
        cout << "\tChoose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. Charge Patient Copay\n";
        cout << "\t2. View Patient Balances\n";
        cout << "\t3. Schedule Apppointment\n";
        cout << "\t4. Cancel Apppointment\n";
        cout << "\t5. Reset Schedule\n";
        cout << "\t6. Reset Weekly Earnings\n";
        cout << endl;

   

        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;


    }while (k != 0);

     switch (choice)
    {
        case 1:  
            {
                chargePatient();

            }
            break;

        case 2:  
            {
        

            } break;

        case 5: 
        {
            resetAppointmentFiles();
        }

    }

    return 0;
}

