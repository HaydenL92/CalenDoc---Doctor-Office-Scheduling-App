# CalenDoc

Calendoc is an appointment booking system designed for patients, doctors, and administrators, developed using C++. It streamlines the appointment management process and enhances communication between users. <br> <br> 


# Key Features

**1. Appointment Booking:** <br> 
- Patients can add, delete, modify, and view their appointments. <br> 
- Providers can view their booked appointments and confirm patient attendance status (on time, late, or canceled).<br> 
- Admins have the ability to book and cancel appointments.<br> <br> 

**2. Co-Pay Calculation:** <br> 
- Providers can access their weekly co-pay information, simplifying financial tracking.<br> <br>


**3. Feedback System:** <br> 
- Patients can submit feedback on their appointments. <br> 
- Providers can review feedback to improve their services. <br> <br> 

**4. Insurance Validation:** <br> 
- Patients can enter their insurance information to check if it is accepted by the medical office.<br> <br> 

**5. Account Creation:** <br> 
- Users can create accounts upon initial login, with roles assigned by the medical office (patients, providers, or admins). <br> 
- Providers and admins receive passwords for role verification during sign-in.<br> <br> 

# Technologies Used 
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
<br>
<br>


# Duration
January 17th to May 3rd, 2024 
<br>
<br>


# Team
4 Undergraduate Students 
<br>
<br>

# Documentation
https://docs.google.com/document/d/1-DBjW2hpUN0ijce85vhF0Tq3Z-3lhSta1WyIQ5YmsPM/edit?usp=sharing  <br>  <br> 
**1. Overview:** Page 2 <br> 
**2. Use Cases:** Page 4 <br> 
**3. Class Diagram:** Page 6 <br> 
**4. Statechart:** Page 7 <br> 
**5. Case Realization:** Page 8 <br> 
**6. Detailed Design of Control, Entity, and Boundary classes:** Page 14 <br> 
**7. Implementation:** Page 30 <br> 
**8. Test Case and Results:** Page 30 <br> 
**9. Test Cases:** Page 31 <br> 
**10. User Documentation:** Page 32 <br> 
**11. Code Screenshots:** Page 33 <br>

<br>
<br>

# Patient Functions
<h3>Registration</h3>
Patient's random generated ID starts with 1, Provider's starts with 2, Admin's starts with 3
<img width="480" alt="1060x700 png 5ec0eb8a1ec54f6cbd829463794c800e" src="https://github.com/mdawood832/CalenDoc/assets/101743220/eb121027-e3de-4382-aae6-700e9c3faaba">


<br>
<br>
<h3>Login</h3>
<img width="480" alt="1028x348 png c7b3c058356c4a1ea8df5083993756f4" src="https://github.com/mdawood832/CalenDoc/assets/101743220/87cebd23-8a48-4391-a4fb-f88facbb5e3f">
<br>
<br>
<img width="480" alt="1026x692 png ff00807a86f34efa937b906b1d23e6e2" src="https://github.com/mdawood832/CalenDoc/assets/101743220/a0c738f9-8367-4d94-b6d9-25c6002ca868">



<br>
<br>
<h3>Password Recovery</h3>
<img width="480" alt="1134x632 png b42f0976e22a47168391522acc76a28b" src="https://github.com/mdawood832/CalenDoc/assets/101743220/38da0d57-026a-4fa0-897f-c60d75051142">

<br>
<br>
<h3>Exit Login Page</h3>
<img width="480" alt="Screenshot 2024-05-04 at 7 54 34 PM" src="https://github.com/mdawood832/CalenDoc/assets/101743220/30961fb1-6535-4475-b3a9-0cbb1e4fc948">


<br>
<br>
<h3>Patient Information Collection for NEW patients</h3>
<img width="480" alt="1588x982 png 3044e941dbbb4fedb58297c4a639c94c" src="https://github.com/mdawood832/CalenDoc/assets/101743220/f643d963-3291-4a18-8bac-319bf90138a1">

<br>
<br>
<h3>Patient Information Collection for EXISTING patients</h3>
<img width="480" alt="Screenshot 2024-05-04 at 8 18 50 PM" src="https://github.com/mdawood832/CalenDoc/assets/101743220/b3c111ed-45c5-4286-ae7d-daa5cb19daa1">


<br>
<br>
<h3>Schedule An Appointment</h3>
<img width="480" alt="1636x1312 png d0271ad5f00144739e3ab32135598824" src="https://github.com/mdawood832/CalenDoc/assets/101743220/b1d02e01-6df1-429b-b1df-366668cc8a17">

<br>
<br>
<h3>Cancel An Appointment</h3>
<img width="480" alt="1016x566 png e14bfb54e0a74350a12706f9e8a8a0b6" src="https://github.com/mdawood832/CalenDoc/assets/101743220/3c6c8cc9-9cf2-4899-9a49-6024f30970ba">

<br>
<br>
<h3>Feedback Collection</h3>
The patient's feedback is saved to a txt file called "feedback.txt"
<br>
<img width="480" alt="1192x846 png 01cf2fff3d9d4adf83efb1a475514b8c" src="https://github.com/mdawood832/CalenDoc/assets/101743220/5045f987-763f-46f2-b23a-b313651d6076">


<br>
<br>
<h3>Insurance Validation</h3>
The accepted insurances at the clinic are Alien, Zombie, and Unicorn. If the patient enters an accepted insurance name the program will 
print that the insurance is accepted. If not, it will print that the insurance is not accepted. 
<img width="480" alt="1030x584 png ce69203dd8374955931affe2b6bfd8f0" src="https://github.com/mdawood832/CalenDoc/assets/101743220/9574c043-e7cb-4f5a-a636-d1d1e86c823a">

<br>
<br>

# Provider Functions
<h3>Registration</h3>
<h4>The Provider must enter the office password to register a new login, the ID randomly generated starts with 2</h4>
<img width="480" alt="1014x586 png f8a1d1edb85f4927980623699e2471f3" src="https://github.com/mdawood832/CalenDoc/assets/101743220/32790d2c-5f04-4f69-81ac-ff60bc08d1ce">


<br>
<br>
<h3>Login</h3>
<img width="480" alt="Screenshot 2024-05-04 at 7 49 32 PM" src="https://github.com/mdawood832/CalenDoc/assets/101743220/130a4a33-f22a-4e0c-8490-201f19df7eab">


<br>
<br>
<h3>Confirm Appointment Status</h3>
<img width="480" alt="1016x630 png 98484a73adcf49608b716c956062383e" src="https://github.com/mdawood832/CalenDoc/assets/101743220/5c8bbb1b-362d-400b-8f63-28496af81b44">

<br>
<br>
<h3>View all Patients</h3>
<img width="480" alt="1090x1276 png 8e0f3fc1b4374026a42811d97a121e56" src="https://github.com/mdawood832/CalenDoc/assets/101743220/9a74456d-7c7e-4324-ba2d-ecd5ae78db1b">



<br>
<br>
<h3>View all Feedback</h3>
<img width="480" alt="1026x1250 png d2e45746beb84013a9b77dbf896275fa" src="https://github.com/mdawood832/CalenDoc/assets/101743220/94f6e23f-e49c-4e02-b6d4-4e8149004276">



# Admin Functions
<h3>Registration</h3>
<img width="480" alt="Screenshot 2024-05-04 at 8 14 46 PM" src="https://github.com/mdawood832/CalenDoc/assets/101743220/eb2b12a6-cdab-47a1-904c-ed632f143fb2">


<br>
<br>
<h3>Login</h3>
<img width="480" alt="1020x896 png 4f18c99563b945b691e1c90519d740f2" src="https://github.com/mdawood832/CalenDoc/assets/101743220/ed7518c9-bf08-4581-857b-42cff6f612e4">



<br>
<br>
<h3>Charge Patient Copay</h3>
<img width="480" alt="1022x638 png 977a075ee0b642d3a3db87b9bb2f4b73" src="https://github.com/mdawood832/CalenDoc/assets/101743220/eb2dd5d4-3110-44cc-9b36-9432b54e0729">

<br>
<br>
<h3>Schedule an Appointment for a Patient</h3>
<img width="480" alt="1028x1314 png 104f963046a2479e8a03706d77e4033f" src="https://github.com/mdawood832/CalenDoc/assets/101743220/41e61d60-e17a-4724-85d1-9a8ea65c3e24">


<br>
<br>
<h3>Cancel an Appointment for a Patient</h3>
<img width="480" alt="1046x472 png 8b1284a33d29441d84d557e12f96587f" src="https://github.com/mdawood832/CalenDoc/assets/101743220/9713ec34-7638-4eb8-a6cf-610833e6a2e7">


<br>
<br>
<h3>Reset Schedule for Provider</h3>
<img width="480" alt="1072x408 png 198c58ab89604d069427e35e15f82904" src="https://github.com/mdawood832/CalenDoc/assets/101743220/f928cdf3-af1f-4630-93f7-d036fe22eefb">


<br>
<br>
<h3>Reset Weekly Earnings for Provider</h3>
<img width="480" alt="1050x404 png 6a56e948ca2a4f3099773fed82ce15b6" src="https://github.com/mdawood832/CalenDoc/assets/101743220/a5b33807-9592-4ac2-9bea-0dc285b9a252">





























