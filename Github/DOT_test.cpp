#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DOT.h"

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
/*
//old
float DOT_exp(T a[DIMdot],T b[DIMdot])
{
	float factorials[Iter];
	float x = 0;
	//float out;
	factorials[0] = 1;

	for (int i = 0; i < Iter; i++){
		factorials[i+1] = factorials[i] * (i+1);
		//printf("%f\n",factorials[i]);
	}
	// matrix multiplication of a A*B matrix
	for (int j = 0; j < DIMdot; ++j)
		{
		x += a[j]*b[j];
		//printf("x: %f\n", x);
		}
	// This function uses the fact that we know 1/(1+e^x) therfor 1+e^x can be written as 1 + 1 + x/1! + ..ect therfor 2 + x/1! + ... is true.
	// more optimizations can be made to factorial and dividing by 1 is a waste.
	// next optimization would be that the next step would be dividing by 2 but since we know that dividing by 2 is accually a logical shift it can be improved
	//

		float sum = 2;
		/*
		float power_out = x;
		for (int n = 1; n < Iter; n++){
			//pow is accually a double we are using power which is new function for floats.
			//sum += pow(in[ia][ib],n)/factorials[n];
			sum += power_out/factorials[n];
			//printf("PRE CALCUATED %.11f, powerval:%.11f n:%d\n",(power_out/factorials[n]),power_out,n);
			power_out = power_out*x;

			//printf("PRE CALCUATED %f\n",(power_out/factorials[n]));

			//out = sum;
			//printf("EXPONETIANLS INITAL: %.11f\n",sum);

		}
		//missing star/
		sum = exp(x)+1;
		//will try to see if returning out or 1/sum is more efficent.
		return 1/sum;
		//return out;
		//printf("1/sum: %f\n",1/sum);
}
*/
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
	// uncomment for chosen algorithm

	//runs the tests for each algorithm

	//too run synthesis on Dot product use DOT_matrix_accel in DOT_accel.h
	ret_val = test_DOT_EXP<T, DIMdot, Iter, 4,5,5>();

	//too run synthesis on machine learning algorithm use DOT_Full_Algorithm_accel in DOT_accel.h
	ret_val = Full_Algorithm<T, DIMdot, Iter, 4,5,5>();

	//too run synthesis on SVM use KBF_accel in DOT.h
	ret_val = Full_SVM_TEST<T, DIMdot, Iter, 4,5,5>();


	//DOT_accel<T, DIMdot, Iter, 4,5,5>;
	return ret_val;

}

// This code used to be int main but is no longer used and has been placed instead into dot.h
//TODO depending on how the code should be placed it might be moved back.
/*
int dog(void)
{

	int ret_val = 0;
	float one_over_one_plus_e,one_over_one_plus_e_new;
	int i,j, err,err_exp;

	T matOp1[DIM][DIM];
	T matOp2[DIM][DIM];
	T matMult_sw[DIM][DIM];
	T matMult_hw[DIM][DIM];

	T MATRIX_e_EXACT[DIM][DIM];
	T MATRIX_e[DIM][DIM];
	T TEST_matrix[DIM][DIM];

	T Array1[DIMdot];
	T Array2[DIMdot];
	// Matrix Initiation
	for(i = 0; i<DIM; i++)
		for(j = 0; j<DIM; j++)
			matOp1[i][j] = (float)(i+j)/100;

	for(i = 0; i<DIM; i++)
		for(j = 0; j<DIM; j++)
			matOp2[i][j] = (float)(i*j)/100;

	//*************************************************
	//				dot stuff
	for(i = 0; i<DIMdot; i++)
		Array1[i] = (float)(i);

	for(i = 0; i<DIMdot; i++)
		Array2[i] = (float)(i)/100;

	 //DOT_exp(Array1,Array2,one_over_one_plus_e);
	one_over_one_plus_e = DOT_exp(Array1,Array2);

	 printf("1/(1+e^x) for array1 and array2: %f\n",one_over_one_plus_e);

	 one_over_one_plus_e_new = DOT_WITH_EXP (Array1,Array2);
	 printf("1/(1+e^x) for array1 and array2 NEW: %f\n",one_over_one_plus_e_new);

	 if (one_over_one_plus_e == one_over_one_plus_e_new)
		 err++;










	// End of Initiation

	printf("NORMAL MODE\r\n");
	//standalone_mmult(matOp1, matOp2, matMult_hw);

	//mmult_sw(matOp1, matOp2, matMult_sw);

	//reference Matrix Multiplication
	//mmult_sw(matOp1, matOp2, matMult_sw);
	/////////////////////////////////////////////////////////////////////////
	// MATRIX Exponential
	//MATRIX_exp <Iterations>(matMult_sw,MATRIX_e_EXACT);
	//MATRIX_exp(matMult_sw,MATRIX_e_EXACT);

	//test matrix
	float w = -6;
	for(i = 0; i<DIM; i++){
		for(j = 0; j<DIM; j++)
		{
			TEST_matrix[i][j] = w;
			w += .52;
		}
}
	//reference Matrix exponential
	MATRIX_exp(TEST_matrix,MATRIX_e_EXACT);
	//Matrix exponential
	exponential(TEST_matrix,MATRIX_e);


	/////////////////////////////////////////////////////////////////////////
	// Matrix comparison
	err = 0;
	err_exp = 0;

	//for (i = 0; (i<DIM && !err); i++)
	//	for (j = 0; (j<DIM && !err); j++)
	//		if (matMult_sw[i][j] != matMult_hw[i][j])
		//		err++;

	for (i = 0; (i<DIM && !err); i++){
		for (j = 0; (j<DIM && !err); j++)
		{
			//printf("EXPONETIANLS: %f\n",MATRIX_e_EXACT[i][j]);
			if (MATRIX_e_EXACT[i][j] != MATRIX_e[i][j])
				err_exp++;
		}
	}

	if (err == 0 && err_exp == 0)
	{
		printf("Matrixes identical ... Test successful!\r\n");
		printf("Expontential Matrixes identical ... Test successful!\r\n");
	}
	else
		printf("Test failed!\r\n");


	return err;

}

*/

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
