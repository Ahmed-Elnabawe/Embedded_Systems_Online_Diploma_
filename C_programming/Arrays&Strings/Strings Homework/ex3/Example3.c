/*
 * Example3.c : reverse string
 *
 *  Created on: Apr 14, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> // including stander input output lib
#include <string.h>// including string lib
int main ()
{
	char c[50]; // array of character (string)

	char temp ; // variable to be use in reversing
	int i,j ; // counters for loop
	printf("enter the string :"); //asking user to enter the string
	fflush(stdin);fflush(stdout);// clearing the buffer
	gets(c);//reading string from user
	i=0; // set i with zero value to implement the first character in array
	j=strlen(c)-1;// set j with length-1  to implement the last character in array
	while(i<j) //
	{
		// swapping
		temp = c[i];
		c[i]=c[j];
		c[j]=temp;
		i++;//increment i to be compared with j in the while condition
		j--;//decrement j to be compared with i in the while condition
	}
	printf("the reversed string  is : %s ",c); // print the reversed string to user
	return 0;
}

