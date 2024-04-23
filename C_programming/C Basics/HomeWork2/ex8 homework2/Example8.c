/*
 * Example1.c : simple calculator
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> //calling stander input output lib
int main ()
{
	float num1,num2 ; // declaring a variables to read the values from user
	char ch; // declaring a variable read the operator from user
	printf("enter operator (*,+,-,/) "); // asking user to enter the operator
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%c",&ch); // reading the operator form user
	printf("enter two numbers  :"); // asking user to enter the values
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%f%f",&num1,&num2); // reading  values form user
	switch (ch){ // making a switch on the ch variable to check if the user entered a value of {* or + or - or /}
	case '+' :  // in the case of '+'
	{
		printf(" %f+%f = %f .",num1,num2,num1+num2); // print to user the sum
	}
	break; // breaking from the switch
	case '-' :  // in the case of '-'
	{
		printf(" %f-%f = %f .",num1,num2,num1-num2); // print to user the sub
	}
	break;// breaking from the switch
	case '*' :  // in the case of '*'
	{
		printf(" %f*%f = %f .",num1,num2,num1*num2); // print to user the multi
	}
	break;// breaking from the switch
	case '/' :  // in the case of '/'
	{
		printf(" %f/%f = %f .",num1,num2,num1/num2); // print to user the div
	}
	break;// breaking from the switch
	default : // if the user entered another value
	{
		printf(" %c is not an operator.",ch); // print to user that the operator is not correct
	}
	}
	return 0;
}
