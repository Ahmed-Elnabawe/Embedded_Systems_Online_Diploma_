/*
 * Example1.c : find frequency of characters in strings
 *
 *  Created on: Apr 14, 2024
 *      Author: Lenovo
 */
#include <stdio.h> // including stander input output lib
#include <string.h>
void main ()
{
	char c[50]; // array of character (string)
	char ch ; // variable to read character from user to find the frequency of it
	int counter =0; // counter to save the frequency of the character
	int i ; // counter for loop
	printf("enter the string :"); //asking user to enter the string
	fflush(stdin);fflush(stdout);// clearing the buffer
	gets(c);//reading string from user
	printf("enter the character :"); // asking user to enter the character
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%c",&ch);// scanning the character from user
	for(i=0;c[i]!='\0';i++) // if we did not reach the end of string
	{
		if(ch==c[i])// compare each character of the string with searched character
		{
			counter++;// increment counter if the condition is true
		}
	}
	printf("the frequency is : %d ",counter); // print frequency to user
}
