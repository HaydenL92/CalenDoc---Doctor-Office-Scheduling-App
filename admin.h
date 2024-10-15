/* 
admin.h - header for admin interface 
written by Vi Pham on 04/23/2024
includes functions to schedule an appointment, cancel an appointment, 
clear patient balance, charge patient, and reset weekday files 
*/

void displayAdminMenu();

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string> 
#include <sstream>
using namespace std;


void scheduleAppointments(){

start :
    cout << "Select an Appointment Day\n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int userChoice;

    cout << endl;
    cout << "Select a Day (1-5): ";
    cin >> userChoice;

    cout << "\n ----- Book Your Appointment -----\n";	
    cout << "\n -------- Availbale slots --------\n";	
    
    // opens file object
    ifstream read;
    
          if (userChoice == 1)
        {
            cout << "\n ------------- Monday ------------\n";
            read.open("Monday.txt");
        }

        else if (userChoice == 2)
        {
            cout << "\n ------------ Tuesday ------------\n";
            read.open("Tuesday.txt");
        }

        else if (userChoice == 3)
        {

            cout << "\n -------------Wednesday ---------\n";
            read.open("Wednesday.txt");
        }

        else if (userChoice == 4)
        {
            cout << "\n -------------Thursday ----------\n";
            read.open("Thursday.txt");
        }

        else 
        {
            cout << "\n ------------- Friday -----------\n";
            read.open("Friday.txt");
        }
   
        int numOfHours = 8;
        int recordFound = 0;
        int arr[numOfHours];

    // initialize array
    for (int j = 0; j < numOfHours; j++)
    {
        arr[j] = 0;
    }

    string line;
        
    

    if (read)
    {
        // loop to mark appointment was recordFound
        while (getline(read, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
            recordFound = 1; 
        }
        
    }
    
    read.close();
    
    char key = 'A';
    int hour = 8;
    
    // display availability 
    for (int i = 0; i < numOfHours; i++)
    {
        if (arr[i] == 1)
        {
            cout << "\n" << key << "->" << hour << ":00" << " - Booked";
           

        }
        else
            {
                cout << "\n" << key << "->" << hour << ":00" << " - Available";
            }
            
        key++;
        hour++;

    }

    char seeAnother;
    cout << endl;
    cout << "\n\nWould you like to see other appointments?\n" << endl;
    cout << "Enter y or n: ";
    cin >> seeAnother;

    while (seeAnother == 'y' || seeAnother == 'Y')
    {
        goto start;
    }

    char choice;
    cout<<"Input your desired appointment time: ";
    cin>>choice;

         // method to book the appointment 
        int index = (choice-65 );
        int isBooked = 1;

        // identies if the time slot is booked
        if(arr[index] == 0) 
            isBooked = 0;

        else
            { 
            cout << "\n Error : Appointment is already booked for this Hour";
            cout << "\n Please select different time !!";
            goto start;
            }

        string name;
        cout << "Enter patient's first name:";
        cin >> name;  

        ofstream out;

        if (userChoice == 1)
        {
            out.open("Monday.txt", ios::app);
        }

        else if (userChoice == 2)
        {
            out.open("Tuesday.txt", ios::app);
        }

        else if (userChoice == 3)
        {
            out.open("Wednesday.txt", ios::app);
        }

        else if (userChoice == 4)
        {
            out.open("Thursday.txt", ios::app);
        }

        else 
        {
            out.open("Friday.txt", ios::app);
        }

        if(out){
            out<<choice<<":"<<name.c_str()<<"\n";
            out.close();
            cout<<"\n Appointment booked for Hours : "<< (choice-65) + 8 <<" successfully !!"<<endl;
            
        }
        else{
            cout << endl;
            cout<<"\n Error while saving booking\n";
        }


        out.close();

        


}

void cancelTheAppointment() {

           string name;
           string day;
           int dayPlaceHolder;    

            // prompts user for name and appointment day 
            cout << "Enter patient's name to cancel appointment: ";
            cin >> name; 
            cout << "Enter the appointment day: ";
            cin >> day;

            ifstream inFile;
            ofstream outFile("temp.txt");

            // opens respective day file and a temp file
            if (day == "Monday" || day == "monday")
            {
                inFile.open("Monday.txt");
                dayPlaceHolder = 1;
               
            }
            else if (day == "Tuesday" || day == "tuesday")
            {
                inFile.open("Tuesday.txt");
                dayPlaceHolder = 2;
            }
            else if (day == "Wednesday" || day == "wednesday")
            {
                inFile.open("Wednesday.txt");
                dayPlaceHolder = 3;
            }
            else if (day == "Thursday" || day == "thursday")
            {
                inFile.open("Thursday.txt");
                dayPlaceHolder = 4;
            }
            else
            {
                inFile.open("Friday.txt");
                dayPlaceHolder = 5;
            }




            // input validation 
            if (!inFile) {
                cerr << "Error: Unable to open file." << endl;
                return;
            }

            // searches for name
            bool found = false;
            string line;

            // loop reads original day file 
            while (getline(inFile, line)) {
                size_t pos = line.find(":");

                // identifies if name appears in original day file 
                if (pos != string::npos) {
                    string appointmentName = line.substr(pos + 1);
                    if (appointmentName == name) {
                        found = true;
                        continue;
                    }
                }

                // writes all other appointments into temp.txt file 
                outFile << line << endl;
            }

            // closes all files 
            inFile.close();
            outFile.close();

            // method to update appointment files 
            switch(dayPlaceHolder)
            {
                case (1):
                {
                    // clears original file 
                    // reassign name of temp.txt with original day file name
                    // reassign name of original day file to "text.txt"
                    if (found) 
                    {
                        remove("Monday.txt");
                        rename("temp.txt", "Monday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    }
                    else
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break;
                
                case (2): 
                {
                    if (found) 
                    {
                        remove("Tuesday.txt");
                        rename("temp.txt", "Tuesday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 

                case 3: 
                {
                    if (found) 
                    {
                        remove("Wednesday.txt");
                        rename("temp.txt", "Wednesday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 

                case 4: 
                {
                    if (found) 
                    {
                        remove("Thursday.txt");
                        rename("temp.txt", "Thursday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 

                case 5: 
                {
                    if (found) 
                    {
                        remove("Thursday.txt");
                        rename("temp.txt", "Thursday.txt");
                        cout << "Appointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "Appointment not found for the given name." << endl;
                    }
                } break; 



            }


    
}

void clearBalance(string name)
{

    ifstream inputFile("completedAppts.txt");
    ofstream outputFile("appointmentstemp.txt");
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
        rename("appointmentstemp.txt", "completedAppts.txt");
        cout << "Patient successfully charged!" << endl;
    }
    else
        {
            remove("appointmentstemp.txt");
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
                for (int i = 0; i < 3; i++) {
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
    else 
    {
        displayAdminMenu();
    }

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

    cout <<"The weekly schedule has been cleared!\n"; 
}

void resetEarnings()
{
     std::ofstream ofs;
    ofs.open("weeklyCopay.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    cout <<"The weekly copay has been cleared!\n"; 
    
}



void displayAdminMenu(){


start: 
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
        cout << "\t2. Schedule Apppointment\n";
        cout << "\t3. Cancel Apppointment\n";
        cout << "\t4. Reset Schedule\n";
        cout << "\t5. Reset Weekly Earnings\n";
        cout << endl;


   

        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;

        if(choice<1 || choice >5)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }


    }while (k != 0);

     switch (choice)
    {
        case 1:  
            {
                chargePatient();
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayAdminMenu(); 

            }
        break;

        case 2:  
            {
                scheduleAppointments();
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayAdminMenu(); 

            } 
        break;

        case 3: 
        {       cancelTheAppointment();
                                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayAdminMenu(); 
        }
        break;

        case 4: 
        {
                resetAppointmentFiles(); 
                                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayAdminMenu(); 
        }
        break;

        case 5: 
        {
                resetEarnings(); 
                                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayAdminMenu(); 
        }
        break;




    }

}




