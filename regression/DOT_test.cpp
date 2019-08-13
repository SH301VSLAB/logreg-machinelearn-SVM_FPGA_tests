#include <stdio.h>
#include <stdlib.h>
#include "reg.h"
#include <math.h>

//#include "reg.h"

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
void MATRIX_exp(T in[DIM][DIM],T out[DIM][DIM])
{
	float factorials[Iter];
	factorials[0] = 1;

	for (int i = 0; i < Iter; i++){
		factorials[i+1] = factorials[i] * (i+1);
		printf("%f\n",factorials[i]);
	}
	// matrix multiplication of a A*B matrix
	for (int ia = 0; ia < DIM; ++ia)
		for (int ib = 0; ib < DIM; ++ib)
		{

			float sum = 0;
			float power_out = 1;
			for (int n = 0; n < Iter; n++){
				//pow is accually a double we are using power which is new function for floats.
				//sum += pow(in[ia][ib],n)/factorials[n];
				sum += power_out/factorials[n];
				power_out = power_out*in[ia][ib];
				//printf("POWER %f\n",in[ia][ib]);
			}
			out[ia][ib] = sum;
			//printf("EXPONETIANLS INITAL: %f\n",sum);
		}
}

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

int main(void)
{

	int ret_val = 0;
	// uncomment for chosen algorithm

	//runs the tests for each algorithm

	//too run synthesis on Dot product use DOT_matrix_accel in DOT_accel.cpp
	ret_val = test_DOT_EXP<T, DIMdot, Iter, 4,5,5>();

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
