#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SVM.h"

typedef float T;
int const DIM = 5;
int const DIMdot = 6;
int const SIZE = DIM*DIM;
//this is number of vectors in the Support vector machine
int const NUMBVECTORS = 10;

//number of iterations that will be used for exp
#define Iter 16


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


//This code simply tests first iteration of the neural network aka matrix multi algorithm and the neural network.
int main(void)
{

	int ret_val = 0;

	//too run synthesis on SVM use KBF_accel in DOT_accel.cpp
	ret_val = Full_SVM_TEST<T, DIMdot, Iter, 4,5,5>();


	//DOT_accel<T, DIMdot, Iter, 4,5,5>;
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






//<T, DIMdot, NUMBVECTORS2_h>
float ARM_SVM(T Array1[NUMBVECTORS][DIMdot],T Array2[DIMdot],T Array3[NUMBVECTORS],T sig[1]){
	// using unsigned floats may be benificitial as the sign is not relevant.
	float Dif[NUMBVECTORS][DIMdot];
	float Pre_Sum[NUMBVECTORS][DIMdot];
	float Sum[NUMBVECTORS];
	float To_DOT[NUMBVECTORS];
	float divterm;


	float result;
	int i,j;

	Dif1:for(i = 0; i < NUMBVECTORS; i++){
		//sum has to be initally zero
		Sum[i] = 0;
		Dif2:for(j = 0; j < DIMdot; j++){
			// obtains differential
			Dif[i][j] = Array1[i][j] - Array2[j];
			// obtains the square;
			Pre_Sum[i][j] = Dif[i][j]*Dif[i][j];
			//summing of each 6*1 total of 10 times
			Sum[i] += Pre_Sum[i][j];
		}
	}

	// this term can be placed anywhere before exp is done.
	divterm = 2*sig[0]*sig[0];
	result = 0;
	EXP:for(i = 0; i < NUMBVECTORS; i++){
		// old result += -1*Array3[i]*exp(Sum[i])/divterm;
		result += Array3[i]*exp(-1*Sum[i]/divterm);
	}
	return result;

}
