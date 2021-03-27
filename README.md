# seat-allotment-program-in-C
 
OBJECTIVES: 
    
To emulate a part of the seat allotment procedure and to understand the process through a code of C language.

DESCRIPTION:

 In the development of a code to mimic seat allotment process, the following steps are followed:
  
1) To begin with, we create a file which contains the list of colleges,opening and closing ranks and the total number of seats available for the admission in the given college.
Eg: A csv contains

      IIT MADRAS        //name of the institute
      1                          //starting rank
      200                      //ending rank
      200                      //number of seats
      // A sample csv file is attached for reference
       
2) The contents of the file are read and stored in an array for further references in the program.   
3) The student rank is taken as the input from the user and the program checks a condition according to which the students’ rank must be in the range of ranks provided by the college and then display the list of colleges the student is eligible for admission.   
4) The user is then asked to enter the college name among the displayed colleges in which he/she is eligible for admission.    
5) If the seat is available in that college, then the program will terminate displaying a message that the seat is allotted.    
6) But if there’s no seat available in the desired college, then the student will once again be asked to enter a college name among the other colleges displayed based on the eligibility.   
7) Finally, each time a seat gets allotted to a student, the total number of seats should be reduced from the array in whic was stored and then changed from the main file so that the data is not lost for subsequent seat allotment process in the program.
