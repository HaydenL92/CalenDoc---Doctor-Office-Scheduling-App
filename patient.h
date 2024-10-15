/*
patient.h - patient header file
written by Maryam Dawood & Vi Pham on 04/14/2024
patient.h includes all functions related to the patient interface 
includes: information collection, scheduling an appointment, 
cancelling an appointment, submitting feedback and validating insurance. 
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

// PatientInfomationCollection: hold new patient infomation after registration 
class PatientInformationCollection
{
    private:
        string patientName;
        int patientID;
        string dateOfBirth;
        string patientPayment;
        string insuranceType; 

    public: 
   // function prompting user for patient information and stores into patientInfo.txt
    void getInfo()
    {
            cout << "Enter Patient's Name: "; 
            cin.get();
            cin >> patientName; 

            cout << "Enter Patient ID: ";
            cin >> patientID;

            cout << "Date of Birth(DDMMYYYY): ";
            cin >> dateOfBirth; 

            cout << "Enter your Credit Card Number: ";
            cin >> patientPayment; 

            cout <<"Enter your Insurance Type (alien, zombie, unicorn): ";  
            cin >> insuranceType; 

            ofstream out; 
            out.open("patientInfo.txt", ios::app); 

            /* 
            
            format requirement for patientInfo.txt

            name:id:dob:cardNumber 
            NOTE: booking and canceling appointments will not work without this format

            */

            out << patientName.c_str()<< ":" << patientID << ":" << dateOfBirth << ":" << patientPayment << ":" <<
            insuranceType << "\n";

            out.close();
        
    }

    //display the information user entered 
        void disInfo()
        {
            cout.setf(ios::left);
            cout <<setw(15)<< patientName <<setw(20)<< patientID <<setw(30)<<dateOfBirth <<setw(20)<<patientPayment <<setw(30)<< insuranceType<<setw(30)<<endl;
        }




};

//creates an instance of class patientinformation collection and opens patientInfo.txt
//calls getInfo() from patientInformationCollection to get user's information. 
//uses disInfo() from patientInformationCollection to display patients details in structured format
//displays to the user that their information was saved 
void patientInformationCollection () {
               PatientInformationCollection b;
                fstream f1;
                
                cout << "\t\tWelcome to Patient Information Collection\n";
                cout << "\t\t---------------------------\n";


                // input validation
                f1.open("patientInfo.txt", ios::out | ios::app);
                if (!f1.is_open()) {
                    cerr << "Error: Unable to open file for writing!" << endl;
                }

                bool tag = true; 
                do {
                    b.getInfo();
  
                    //printing details to screen 
                    cout << "\n\t\tPatient Details are following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout << setw(15) << "patientName" << setw(20) << "patientID" << setw(30) << "dateOfBirth" << setw(20) << "patientPayment" << setw(12) << "insuranceType" << setw(12) << "Balance" << endl;
                    b.disInfo();

                    cout << "\n\t..........Information Saved...............\n";
                    tag = false;
      
                } while (tag);

                
            }


//class feedback that collects the user's feedback information: name, ID, date, and rating. 
class Feedback
{
    public :
        char patientName[20];
        int  patientID;
        char date[10];
        string rating; 
        

        void getFeedback()
        {
            cout << "Enter Name: ";
            cin >> patientName; 

            cout << "Enter Patient ID: ";
            cin >> patientID;

            cout << "Enter Today's Date (DDMMYYYY): ";
            cin >> date;

            cout << "Enter Provider Rating (1-5): " ;
            cin >> rating;

        }

        //displays attributes 
        void disInfo(){
            cout <<setw(15)<< patientName <<setw(20)<< patientID <<setw(30)<< date <<setw(20)<< rating <<endl;
        }
};

void viewAppointments() {


    int userChoice;    // day selected 
    char bookAnother;  // another day selected 
    string line;       // temp variable while reading while 

    // appointment availability menu
    start : 
    cout << endl; 
    cout << "Select an Appointment Day\n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    // prompts for a weekday 
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
            cout << "\n ------------- Tuesday -----------\n";
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

    // initialize array to default zeros = available
    for (int j = 0; j < numOfHours; j++)
    {
        arr[j] = 0;
    }
    
    if (read)
    {
        // loop to flag recordFound = booked
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
    
    // display availability using updated array
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

    cout << endl;
    cout << "\n\nWould you like to see other appointments?\n" << endl;
    cout << "Enter y or n: ";
    cin >> bookAnother;

    while (bookAnother == 'y' || bookAnother == 'Y')
{
    goto start;
}

return; 

};

//prompts the user to select an appointment day from monday-tuesday
void bookAppointments(){
start :
    cout << "Select an Appointment Day \n";
    cout << "-------------------------\n";
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int userChoice;

    cout << endl;
    cout << "Select a Day (1-5): ";
    //input validation for day selection 
    cin >> userChoice;
        if(userChoice<1 || userChoice >5)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            goto start; 
        }

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
    
    // variables that are incremented after display each appointment time
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

    // loop to see another appointmnet 
    char seeAnother;
    //input validation for yes or no question 
     do {
        cout << "\n\nWould you like to see other appointments?\n" <<endl;
        cout << "Enter y or n: ";
        cin >> seeAnother;


        if (seeAnother != 'Y' && seeAnother != 'N' && seeAnother != 'n' && seeAnother != 'y' ) {
            cout << "Invalid input. Please enter 'Y' or 'N'." <<endl;
        }
    } while (seeAnother != 'Y' && seeAnother != 'N' && seeAnother != 'n' && seeAnother != 'y' );
    cout << endl;

//if the user wants to see other appointments display appointments 
    if(seeAnother == 'y' || seeAnother == 'Y')
{
    goto start;
}

    //input validation for appointment time 
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
        cout << "Enter your first name: ";
        cin >> name;  
        cout << endl;

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
            cout<<"\n Appointment booked for Hours : "<< (choice-65) + 8 <<" successfully !!";
           
        }
        else{
            cout<<"\nError while saving booking";
        }

        out.close();

}

// function allow patient to cancel appointment 
void cancelAppointment() {

           string name;
           string day;
           int dayPlaceHolder;    

            // prompts user for name and appointment day 
            cout << "Enter your name to cancel appointment: ";
            cin >> name; 
            cout << "Enter your appointment day: ";
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
                        cout << "\nAppointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "\nAppointment not found for the given name." << endl;
                    }
                } break; 

                case 3: 
                {
                    if (found) 
                    {
                        remove("Wednesday.txt");
                        rename("temp.txt", "Wednesday.txt");
                        cout << "\nAppointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "\nAppointment not found for the given name." << endl;
                    }
                } break; 

                case 4: 
                {
                    if (found) 
                    {
                        remove("Thursday.txt");
                        rename("temp.txt", "Thursday.txt");
                        cout << "\nAppointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "\nAppointment not found for the given name." << endl;
                    }
                } break; 

                case 5: 
                {
                    if (found) 
                    {
                        remove("Thursday.txt");
                        rename("temp.txt", "Thursday.txt");
                        cout << "\nAppointment cancelled successfully." << endl;
                    } 
                    else 
                    {
                        remove("temp.txt");
                        cout << "\nAppointment not found for the given name." << endl;
                    }
                } break; 



            }


    
}

// function that allows patient to book appointments 
int bookAppointment(){
    cout << "\n ----- Book Your Appointment -----\n";	
    cout << "\n -------- Availbale slots --------\n"; 

    //check if record already exist..
     ifstream read;
    read.open("appointments.txt");
                
    int hoursbook = 8;
                
    // array initialized to zeros = available
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
                
        if(read)
            {     
            string line;
            char key = 'A';
            int i = 9;
	       
            while(getline(read, line)) {
                char temp = line[0];
                int index = (temp - 65);
                arr[index]=1;  
                recordFound = 1;
                }
            if(recordFound == 1)
                {
                cout<<"\n Appointment Summary by hours:";
                char key = 'A';
                int hours = 9;
                for(int i = 0; i<=12; i++)
                            {
                            if(i == 0){
                                if(arr[i] == 0) 
                                    cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
                                else
                                    cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
                            }
                            
                            else
                            {								           	
                                if(arr[i] == 0) 
                                    cout<<"\n "<<key<<"->"<<hours<<" - Available";
                                else
                                    cout<<"\n "<<key<<"->"<<hours<<" - Booked";
                            }

                            hours++; key++;
                        }
                            
                    }
                        
                    read.close();
                }

                if(recordFound == 0){
                    cout<<"\n Appointment Available for following hours :";
                    char key = 'A';

                for(int i = 9; i<=21; i++)
                {
                    if(i==9)
                        cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
                    else
                        cout<<"\n "<<key<<" -> "<<i<<" - Available";
                        key++;
                }
                
                }
   
            char choice;
            cout<<"\n\n Input your choice : ";
            cin>>choice;
        
            // input validation
            if( !(choice >= 'A' && choice <='Z'))
            {
            cout<<"\n Error : Invalid Selection";
            cout<<"\n Please selction correct value from menu A- Z";
            cout<<"\n Press any key to continue";
            getchar();getchar();
            system("cls");
            bookAppointment();
             }


        // index takes choice (letter in ASCII) and minuses 65
        // A = 65 so 65-65 = 0
        int index = (choice-65 );
        int isBooked = 1;
        if(arr[index] == 0) 
            isBooked = 0;
      
        if(isBooked ==1)
        {
            cout<<"\n Error : Appointment is already booked for this Hour";
            cout<<"\n Please select different time !!";
            cout<<"\n Press any key to continue!!";
            cout << endl;
            getchar();getchar();
            system("cls");
            bookAppointment();
        }
        
        string name;
        cout<<"\n Enter your first name:";
        cin>>name;  
        
        ofstream out;
        out.open("appointments.txt", ios::app);

        if(out){
            out<<choice<<":"<<name.c_str()<<"\n";
            out.close();
            cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
            cout << endl;
        }
        else{
            cout<<"\n Error while saving booking";
        }

        return 0;
}

//Creates an instance of the class Feedback called b. Opens the file called feedback.txt.
//Call getFeedback function from class Feedback to collect the user's information. 
//Write the feedback to feedback.txt in the structured format. Print the feedback to the user. 
//Display to the user that their feedback was saved. 

void getFeedback(){
            //read all feedback info. read every single line
            Feedback b;
                fstream f1;
                char ch;
                int book_id = 1;
                f1.open("feedback.txt",ios::out | ios::app);

                cout << endl; 
                cout << "\t\tWelcome to Feedback Collection\n";
                cout << "\t\t---------------------------\n";

                    b.getFeedback();
        
                    // Write feedback information as a structured record in the file
                    f1 << "Name: " << b.patientName << endl;
                    f1 << "ID: " << b.patientID << endl;
                    f1 << "Date: " << b.date << endl;
                    f1 << "Rating: " << b.rating << endl;
                    f1 << "---------------------------" << endl;


                    cout << "\n\t\tFeedback Details are the following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout <<setw(15)<< "patientName" <<setw(20)<< "patientID" <<setw(30)<< "date" <<setw(20)<< "rating" <<endl;
                    b.disInfo();
                    
                cout << "\n\t..........Information Saved...............\n";

                // Clear input buffer before prompting for further input
                cin.clear(); // Clear any errors
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the input buffer
}


//will ask the user to enter what type of insurance they have. Will go 
//through the accepted insurances array and compare input with the array items. 
//If the input matches one of the insurance types we set count to 1. 
//If count = 1, we print "insurance is accpeted"
//If count - 0, we print "your insurance is NOT accepeted"
void validateInsurance(){
        cout << "\t\tWelcome to Insurance Validation \n";
        cout << "\t\t---------------------------\n";

        string insuranceType; 
        cout << "Enter your insurance type (lowercase): " << endl; 
        cin >> insuranceType;
        string acceptedInsurances[3] = {"alien", "zombie","unicorn"};
                    int count = 0; 
                    for (int i = 0; i < 3; i++) {
                        if (insuranceType == acceptedInsurances[i]){
                            count = 1; 
                        }          
                    }

                    if(count ==1){
                        cout << "Your insurance is accepted." << endl; 
                    } else {
                        cout << "Your insurance is NOT accepted." << endl; 
                    }
}



//displays the menu for the patient. First prints out menu items then prompts the user to enter their choice. 
//if the user does not enter a number between 1 and 5 then the program will prompt the user to enter a valid choice. 
//We used a switch statement to manuver between menu options. 
void displayMenuPatient(){
start: 

        cout << endl;
        cout << "*********************************************************************\n";
        cout <<"....................... WELCOME TO CALENDOC .........................\n";
        cout <<"............................. Patient ...............................\n";
        cout << "*********************************************************************\n";
        cout<< endl;

    int k = 0;
    int choice;
    do
    {
        cout << "\t Choose Option From Menu (1-5) \n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. Complete patient profile (new users only)\n";
        cout << "\t2. Schedule an Appointment\n";
        cout << "\t3. Cancel an Appointment\n";
        cout << "\t4. Submit Feedback\n";
        cout << "\t5. Insurance Validation\n";

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
        //calling patientInformation collection function. Followed by the choice to quit entirely or to go 
        //back to the patient menu. 
        case 1:  
            {
                int answer; 
                cout << "\nPress 1 for NEW PATIENTS\n";
                cout << "Press 2 for EXISTING PATIENTS\n";
                cout << endl;
                cout << "Enter: ";
                cin >> answer;

                if (answer == 1)
                {
                 
                    patientInformationCollection(); 
                    char c;
                    cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                    cin >> c;

                    if(c == 'q'|| c == 'Q')
                        exit(EXIT_FAILURE);
                    else
                        displayMenuPatient();  
                }
                else 
                {
                    cout << endl;
                    cout << "If you are an existing patient, please contact the office at 832-000-0000 for any profile modifications.\n";
                    cout << "\nOur Office Hours:\n";
                    cout << "Monday-Friday: 8pm-5pm\n";
                    cout << "Saturday-Sunday: CLOSED\n";
                    cout << endl;
                    char c;
                    cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                    cin >> c;

                    if(c == 'q'|| c == 'Q')
                        exit(EXIT_FAILURE);
                    else
                        displayMenuPatient();  

                }

                }

            break;
        //calling bookAppointments function. Followed by the choice to quit entirely or to go 
        //back to the patient menu. 
          case 2:
            {   
                bookAppointments(); 
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayMenuPatient();  

            }
            break; 

        //calling cancelAppointments function. Followed by the choice to quit entirely or to go 
        //back to the patient menu. 
        case 3:
            {    
                cancelAppointment(); 
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayMenuPatient();  
            }
        break;

        //calling getFeedback function. Followed by the choice to quit entirely or to go 
        //back to the patient menu.
        case 4 : 
            {

                getFeedback(); 
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayMenuPatient();  
            }
        break;
        //calling validateInsurance function. Followed by the choice to quit entirely or to go 
        //back to the patient menu.
        case 5 : 
            {

                validateInsurance(); 
                char c;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c;

                if(c == 'q'|| c == 'Q')
                    exit(EXIT_FAILURE);
                else
                    displayMenuPatient();  
            }
        break; 

    }
}