/*
 ============================================================================
 Name        : Aaron_Roche_HW2.c
 Author      : Aaron Roche
 Version     : 1
 Description : C program that calculates the value of a polynomial.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float raiseIt(float base, int exponent);

int main(int argc, char* argv[])  
{  
	int numOfArgs = argc - 2;
	float x = atof(argv[1]);
	float sum = 0;

	for(int i = 0; i < numOfArgs; i++)
	{
		float arg = atof(argv[i]);
		sum += arg * raiseIt(x,i);
	}
}

float raiseIt(float base, int exponent)
{
	float answer = 0;
	answer = (int)base ^ exponent;
	return answer;
}