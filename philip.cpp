 /*
  * Homework 4 Program, Fibonacci Sequence
  * Finds the nth Fibonacci number 
  * Uses this algorithm: Fib(n) = fib(n-1) + fib(n-2) 
  * Goal: Use of github and Use of Functions
  * Author: Luke Philip Ogweno
  * 24 Feb 2015
  * Github account: https://github.com/PhilipOgweno/HMWK4.git
  */


#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <iomanip>



using namespace std;

string message1, message2;

// Open the output file to write in 

void openoutput(ofstream& outputFile, string fileName)
{

     outputFile.open(fileName.c_str());
     
}

// Function to print out the output
void printoutput(ofstream& outputFile, int number, long double* fibArray, int len)
{

   int colNumber;
   switch (number)
   {
     case 1 :
         colNumber = 1;
     for (int i = 0; i < len; i++)
     {

       if ((colNumber%10) == 0) 
       {
          outputFile << fibArray[i] <<left<< setw(20) <<endl;
          colNumber++;

       }else
       {
          outputFile << fibArray[i] <<left<< setw(20);
          colNumber++;
       }
     }
     break;
   case 2 : 
       colNumber = 1;
       for (int i = 0; i < len; i++)
       {
          if ((colNumber%10) == 0) 
          {
             cout << fibArray[i] <<left<< setw(20) <<endl;
             colNumber++;
          }
          else 
          {
             cout << fibArray[i] <<left<< setw(20);
             colNumber++;
          }
       } 
    break;
    
    }
}



void printoutput(ofstream& outputFile, string message)
{
	outputFile << message << endl; 
	cout << message << endl;
	
}



// Function to open input file 

void openinput(ifstream& inputFile, string inputFileName)
{
   
   inputFile.open(inputFileName.c_str());

   if (inputFile.fail()) 
   {
      cout << "File does not exist!!  " << inputFileName << endl;
      exit(EXIT_FAILURE);
   }
}

// Function to print error to error output file
void err_write(int errN, string name)
{

    ofstream erroutFile;
    erroutFile.open("philip.err", ofstream::out | ofstream::app);
    switch (errN) 
    {
      case 1 : 
          erroutFile << "File does not exist!! " << endl; 
          break;
      case 2 :
          erroutFile << "Invalid input" << endl; 
          break;
    }
}
// Reading the input file line by line 

int getNumber(ifstream& inputFile )
{
    
    string line;
    int len;
    getline(inputFile, line);
    istringstream number (line);
    number >> len;    
    return len; 
}


// Begin the Main program 

int main () 
{


    
	message1 = "I was able to compile this code using the HPC at the University of Memphis."
	"When I compiled it there, it did not produce any warning message. The HPC uses a GNU"
	" C++ compiler that can be considered a good up-to-date standard. I also version-controlled"
	" this code using git, and used a remote repository hosted by github. If I can do this, so can you!!!";
	message2 = "I am so cool, that I was also able to write a code that produces the first M numbers of the Fibonacci sequence. Here they are:";
    
	// open input file 
    string inputFileName = "philip.in" ;
    ifstream inputFile;
    openinput(inputFile, inputFileName);
    
   

    // Read from the input file
    int len = getNumber(inputFile);
     inputFile.close();
    
    if (len < 1)
    {
       string name = " ";

       cout << "Invalid input " << endl;
       err_write(2,name);
       exit(EXIT_FAILURE);

    }
   
    // Generating the Fibonacci Sequence
    
     int arraylen = 10*len;
     long double fibArray[arraylen];

     long double  fib1 = 0;
     long double  fib2 = 1;
     fibArray[0] = fib1 ;
     fibArray[1] = fib2 ;
     
     int i = 2;
     while(i <= arraylen)
     {
     
       long double fib = fib1 + fib2;
       fibArray[i] = fib ;
       fib1  = fib2;
       fib2 = fib;
       i++ ;
     }
    
    // open output file
    
    ofstream outputFile;
    string outputFileName = "philip.out";
    openoutput(outputFile, outputFileName);

    // Write out results to terminal and  output file
    
    int file = 1; int  terminal = 2;
    printoutput(outputFile, message1);
    printoutput(outputFile, "\n");
    printoutput(outputFile, message2);
    printoutput(outputFile, file, fibArray, arraylen);
    
    printoutput(outputFile, terminal, fibArray, arraylen);
}
    
	    
