/*
 Carter Fluckiger
 C++ Fall 2019
 Due: November 14,2019
 Lab:Write a C++ program that reads characters representing binary (base 2)
 numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
 numbers. The binary and decimal numbers should be output in two columns with
 appropriate headings.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
//standard is the namespace used throughout
using namespace std;
//Pre condition-To enter the outline void it must enter the main function
//Post condition-the outline outputs the displays at the top of the output
void outline();
//Pre condition-to enter this function it has to run through the main
//Post condition- this function returns both the binary and decimal values and outputs them to
//the screen and decifers whether the inputs meet the criteria of the lab
void compiler();
//Pre condition- to enter this function the stream must be valid and the input must also be valid
//als modular division is done on the valid numbers to determine if they are negative
//Post condition- opens both infiles and dicifers if the inputs are valid and sends values to
//other functions and couts the return values from them that calculate the spacing
void binspacing(int spaces_);
//Pre condition- if the infile is valid and the input is within the parameters
//Post condition- This function determines how long the decimal numbers is and using that number
//calculates the spacing and outputs it to the screen
void decspacing(int decnum_);
int main()
{
//the calls for the voids outline and compiler
    outline();
    compiler();
//the return ends the program with no errors
    return 0;
}
//definition for the void defintion
void outline()
{
//display for the top of the screen on the output
    cout<<"\t\t\t Binary\t\t\t              "<<"Decimal Equivalent\n";
}
//defintion for void compiler
void compiler()
{
//defining inputs as a char
    char numbers;
//finding the input file and opening it
    string fileinput="/Users/tag1/Desktop/Lab6/Lab6/BinaryIn.dat";
    ifstream infile;
    infile.open(fileinput);
    ifstream infilecout;
    infilecout.open(fileinput);
    //priming read
    infile.get(numbers);
    //while loop to make sure the the file exists
    while(infile)
    {
       //while look to make get past any spaces at the beginning of the binary number and
        // making sure to not use the spaces as they have no purpose
        while(infile && numbers ==' ')
        {
            infile.get(numbers);
        }
//defining variable inside the while loop so they get a fresh start every endline
        int spaces = 1;
        bool accepted=true;
        int decnum=0;
        //this while loop is to dismiss any zeros that prelude the first 1
        while(infile && numbers =='0')
        {
            infile.get(numbers);
        }
        //This while is use to define the numbers by the lines they are on and makes sure not to
        // mix them with each other
        while(infile && numbers!= '\n')
        {
            //spaces++ adds a 1 for every valid number to get the length of the entire binary
            //number to be use in later calculations for spacing
            spaces++;
//This switch statement is used to do calculations for line spacing on only valid numbers
        switch(numbers)
        {
            case '0':decnum =(decnum *2)+0; break;
            case '1':decnum =(decnum *2)+1; break;
            //Default turns the bool false which makes the binary number an invalid input
            default: accepted=false;
        }
            //second read get the next number for the switch statement
           infile.get(numbers);
        }
        //used to calculate if the binary number is an even number
        if(spaces % 2 == 0 && accepted)
        {
        //call for function and sends spaces value to it
            binspacing(spaces);
        }
        //else if used to calculate if the lenght of binary number is odd and adds an extra
        //space to correct line spacing
        else if(spaces % 2 != 0 && accepted)
        {
            //call for function and sends spaces value
            binspacing(spaces);
            //cout used to correct line spacing in odd lengths of numbers
            cout<<" ";
        }
        //priming read for second infile that couts the results
    infilecout.get(numbers);
        //while loops that checks for valid inputs and skips spaces and zeros
        while(infilecout && numbers ==' ')
        {
            infilecout.get(numbers);
        }
         while(infilecout && numbers == '0')
               {
                   infilecout.get(numbers);
                   
               }
        //while function used to make sure second stream is valid and there are values on the //line that has been read from the file
    while(infilecout && numbers != '\n')
    {
        //if statement checking to see if bool is true based on if the input is vWrite a C++ program that reads characters representing binary (base 2)
        
        if(accepted)
        {
            //couts binary numbers if valid
            cout<<numbers;
        }
        // second read to get next value from file
         infilecout.get(numbers);
    }
        //if statement the checks if input is valid
        if(accepted)
        {
            //if statement that does modular division to see if the value is even
            if(spaces % 2 == 0 && accepted)
                 {
                     //call for function that does spacing for binary number
                     binspacing(spaces);
                 }
            //if statement that does modular division to see if the value is odd
                 else if(spaces % 2 != 0 && accepted)
                 {
                     //call for function that does spacing for binary number
                     binspacing(spaces);
                 }
            //cout used for spacing purposes
            cout<<"\t\t";
            //call for function that does spacing for the specific length of the decimal number
            //
            decspacing(decnum);
            //cout for decimal number
            cout<<decnum<<endl;
        }
        //if statment for if the bool is false and the input as a whole is invalid
        else if(!accepted)
        {
            //cout error message
            cout<<"      Bad digit on input"<<endl;
        }
        //second read for first infile
        infile.get(numbers);
    }
//end of compiler void function
}
//defintion of binspacing function
void binspacing (int spaces_)
{
   //mathmatical calculations to find the needs spaces for the given length of the binary number
    //
    spaces_= ((32-spaces_)/2);
    //for loop used to use previos calculations to output the necessary spaces
    for(int count=1 ;count<= spaces_ ; count++)
    {
        cout<<" ";
    }
}
//definition for void function that is used to find spacing for decimal spacing
 void decspacing (int decnum_)
{
    //defines decspace as an int
    int decspace=0;
    //do while loop that makes sure the loop runs at least once.  This makes it easier to format
    //giving all number under 10 one space
   do
   {
       //for loop used to find lenght of binary number to determine spacing
    for(int count=10;decnum_>=count;decnum_=decnum_/10)
    {
        //adds one for every number in lenght the binary number is
        decspace++;
    }
       //exits the loop after the binary number is under 10 as long as it has run once
   }while(decnum_>=10);
    //math used to find spacing and for each separate number using the lenght of it
    decspace=(32-decspace)/2;
    //for loop used to make spaces if the binary number is bigger or smaller
    for(int count=1;count<decspace;count++)
    {
        //couts spaces for before the binary number is output
        cout<<" ";
    }
}
