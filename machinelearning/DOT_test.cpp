#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "machine.h"

typedef float T;
int const DIM = 5;
int const DIMdot = 6;
int const SIZE = DIM*DIM;
//this is number of vectors in the Support vector machine
int const NUMBVECTORS = 10;

//number of iterations that will be used for exp
#define Iter 16

/////////////////////////////////////////////////////////////////////////
//this function simply gets the exp to be used to test against the values
//template <int Iter>


//This function is just the dot product with exponential at the end.
float DOT_exp(T a[DIMdot],T b[DIMdot])
{
	float x = 0;
	for (int j = 0; j < DIMdot; ++j)
		{
		x += a[j]*b[j];
		//printf("x: %f\n", x);
		}
		return (exp(x));

}



//////////////////////////////////////////////////////////////////////////


//This code simply tests
int main(void)
{

	int ret_val = 0;

	//too run synthesis on machine learning algorithm use DOT_Full_Algorithm_accel in DOT_accel.cpp
	ret_val = Full_Algorithm<T, DIMdot, Iter, 4,5,5>();

	return ret_val;

}



// This is a function is a simple way of comparing results by first printing them then pulling
// part of the string from the print to compare each other too.
float round4dec(float var)
{
    // we use array of chars to store number
    // as a string.
    char str[40];

    // Print in string the value of var
    // with 4 decimal point
    sprintf(str, "%.4f", var);

    // scan string value in var
    sscanf(str, "%f", &var);

    return var;
}



void Matrix_exp_with_soft1(T Array1[DIMdot][DIMdot], T Array2[DIMdot], T out[DIMdot])
{
	T SUM;

	SUM = 0;
	// reference dot product with exponential
		for(int k = 0; k < DIMdot; k++){
			out[k] = DOT_exp(Array1[k],Array2);
			//sums array
			printf("ACCtual part of in%d:%f\n",k,out[k]);
			SUM += out[k];
		}
		for(int k = 0; k < DIMdot; k++){
			out[k] = out[k]/SUM;
			printf("1/(1+e^x) for array1 and array2 WITH ARM: %.10f\n",out[k]);
		}
		//return;
}

void Matrix_exp_with_soft2(T Array1[2][DIMdot], T Array2[DIMdot], T out[2])
{
	T SUM;

	SUM = 0;
	// reference dot product with exponential
		for(int k = 0; k < 2; k++){
			out[k] = DOT_exp(Array1[k],Array2);
			//sums array
			printf("ACCtual part of in%d:%f\n",k,out[k]);
			SUM += out[k];
		}
		for(int k = 0; k < 2; k++){
			out[k] = out[k]/SUM;
			printf("1/(1+e^x) for array1 and array2 WITH ARM: %.10f\n",out[k]);
		}
		//return;
}
