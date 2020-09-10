#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/* Author: Joseph Pietroluongo
  PID: 5901749
  I affirm that I wrote this program myself without any help
  from any other people or sources from the internet
  Summary: Calculator for simple command line uses for 
  addition, subtraction, multiplication, division and exponents 
*/

//Error message if starting value is not within parameters
void errorMessage()
{
  printf("Number must be between 1 and 50 inclusive\n");
}

//Shows useage of program and its command line operators 
void useageStatement()
{
  printf("Useage: calculator [-a num] [-d num] [-m num] [-s num] [-x] values\n");
}

//Standard line for passing arguements in main
int main(int argc, char *argv[])
{
  //Sets the starting value to 0. value variable used per instructions
  int value = 0;

  //Sets value to arguement count -1
  value = atof(argv[argc - 1]);

  //Sets Operation[] equal to arguements
  char operation[argc - 1];

  //Sets num as float and arguement count -1, num variable used per instructions
  float num[argc - 1];

  
  //Float to be used as result, result value needs to be 2 decimal places, defined in result line.
  float resultValue = 0.00;

  //Option number set to 0 initially, changes with op
  int caseNum = 0;

  //Assigns i since it must be assigned outside for ocelot.
  int i = 0;

/*Case statements for each parameter start here
  getopt used to assign in examples given and connect meeting recording
*/
  while ((caseNum = getopt(argc - 1, argv, ":a:s:d:m:x")) != -1){
    switch (caseNum){

      //Add 
      //Exta comments only on case this but apply to all cases.
      //Case for each [-a num] [-d num] [-m num] [-s num] [-x], with checks if within range 
      //if statement takes num[i] and assigns it the value. Then it is checked to see if it is false.
      //if it is false the error message and useage display.
      case 'a': operation[i] = 'a';
        if ((num[i] = atof(optarg)) == 0){
          exit(EXIT_FAILURE);
        }

      //Loop checks for the -a or -s option num should be a positive integer between 1 and 500 inclusive.
        if (num[i] < 1 || num[i] > 500){
          printf("Number must be between 1 and 500 inclusive.\n");
          exit(EXIT_FAILURE);
        }
        break;

      //Sub
      case 's': operation[i] = 's';
        if ((num[i] = atof(optarg)) == 0){
          exit(EXIT_FAILURE);
        }

      //Loop checks for the -a or -s option num should be a positive integer between 1 and 500 inclusive.
        if (num[i] < 1 || num[i] > 500){
          printf("Number must be between 1 and 500 inclusive.\n");
          exit(EXIT_FAILURE);
        }
        break;

      //Multiply
      case 'm': operation[i] = 'm';
        if ((num[i] = atof(optarg)) == 0){
          exit(EXIT_FAILURE);
        }
        
      //Loop checks for the -m or -d option num should be a positive integer between 1 and 5 inclusive.
        if (num[i] < 1 || num[i] > 5){
          printf("Number must be between 1 and 5 inclusive.\n");
          exit(EXIT_FAILURE);
        }
        break;

      //Divide
      case 'd': operation[i] = 'd';
        if ((num[i] = atof(optarg)) == 0){
          exit(EXIT_FAILURE);
        }
        
      //Loop checks for the -m or -d option num should be a positive integer between 1 and 5 inclusive.
        if (num[i] < 1 || num[i] > 5){
          printf("Number must be between 1 and 5 inclusive.\n");
          exit(EXIT_FAILURE);
        }
        break;

      //Exponent
      case 'x':
        operation[i] = 'x';
        num[i] = 0.0;
        break;

      //Default if [-a num] [-d num] [-m num] [-s num] [-x] is not selected
      //or if an incorrect case is selected [-r num] for example
      case ':': 
        printf("Error, please check useage and ensure it has been entered correctly\n"); 
        useageStatement(); 
        exit(EXIT_FAILURE);
    }
  //End of switch case, standard i incrementation to check for all values input.
  i++;
  }
  
  //Checks the condition for the error message to be displayed and the useageStatement message
  if (value < 1 || value > 50){
    errorMessage();
    useageStatement();
    exit(EXIT_FAILURE);
  }
  
  //defining the order of operations characters
  char orderOfOperations[] = {'x','m','d','a','s'};

  //Storing result with value before entering the loop. Result will hold the final value
  resultValue = value;

  //Store variables to be used for loop below since they cannot be instanced inside the loop in ocelot
  //
  //Does anyone read my comments? Why doesnt this work on ocelot?
  //
  int j = 0;
  int k = 0;

  /*Loop that checks order of operations 1st x, 2nd m or d, 3rd a or s
    Uses nested loops to incriment all instances of suitable conditions for
    order of operatios. 
  */

  for (j = 0; j < 5; j++){

    int orderofOperationsIndex = 0;
    while (orderofOperationsIndex != -1){

      orderofOperationsIndex = -1;
      //Inner loop for order of operations
      for (k = 0; k < i; k++) { 
        if (orderOfOperations[j] == operation[k]){
          orderofOperationsIndex = k;
          break;
        }
      }

      //If statement that gives the correct order of operations case to be used.
      //Nested inside loop of orderofOperationsIndex to increment correctly.
      if (orderofOperationsIndex != -1){
        
        //-x squares value. (Note: no num is needed.)
        if (operation[orderofOperationsIndex] == 'x'){
          resultValue = resultValue * resultValue;       
        }

      //-a adds num to value.
        else if (operation[orderofOperationsIndex] == 'a'){
          resultValue = resultValue + num[orderofOperationsIndex];
        }
        
      //-s subtracts num from value
        else if (operation[orderofOperationsIndex] == 's'){
          resultValue = resultValue - num[orderofOperationsIndex];
        }

      //-m multiplies value by num.
        else if (operation[orderofOperationsIndex] == 'm'){
          resultValue = resultValue * num[orderofOperationsIndex];
        }

      //-d divides value by num.
        else if (operation[orderofOperationsIndex] == 'd'){
          resultValue = resultValue / (float) num[orderofOperationsIndex];
         }

      //Stores operations that are carried out.
        operation[orderofOperationsIndex] = '*';
        num[orderofOperationsIndex] = 0;
      
      }
    }
  }

//Output should have exactly 2 decimal places no matter what the starting values are.
  printf("Result = %0.2f\n", resultValue);
}