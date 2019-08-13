#include <stdio.h>
#include <stdlib.h>

#include "reg.h"


// THIS IS THE TOP LEVEL DESIGN THAT WILL BE SYNTHESIZED
//#define MCR_SIZE 6
//i dont know the size assumming its 6
#define MCR_SIZE 6
#define TENSIZE 10

#define SCALESIZE 10
/*
void standalone_mmult (float A[5][5], float B[5][5], float C[5][5])
{

	mmult_hw <float, 5>(A, B, C);

}
*/
/////////////////////////////////////////////////////////////////////////////////

/***********************************************************************************/
/**********************************dot stuff****************************************/
float DOT_WITH_EXP (float a[6],float b[6])
{

	return DOT_exp1 <float, 6, 16>(a,b);

}



//template <typename T, int DIMdot,int NUMBVECTORS, int Iter>
//float SVM(T FV[NUMBVECTORS][DIMdot],T Input[DIMdot],T Alpha[NUMBVECTORS], T Sigma)









/////////////////
void DOT_accel (AXI_VAL INPUT_STREAM[2*MCR_SIZE], AXI_VAL OUTPUT_STREAM[1])
{
	#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
	#pragma HLS INTERFACE axis      port=OUTPUT_STREAM
	#pragma HLS INTERFACE axis      port=INPUT_STREAM
	//NOTE: changed from float function to void function
	//wrapped_dot first < length a/b,numb Iterations, other junk not sure pls help>
	wrapped_DOT <float, 6, 16, 4, 5, 5>(INPUT_STREAM, OUTPUT_STREAM);

	return;
}



void DOT_matrix_accel (AXI_VAL INPUT_STREAM[MCR_SIZE+MCR_SIZE*MCR_SIZE], AXI_VAL OUTPUT_STREAM[MCR_SIZE])
{
	#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
	#pragma HLS INTERFACE axis      port=OUTPUT_STREAM
	#pragma HLS INTERFACE axis      port=INPUT_STREAM
	//NOTE: changed from float function to void function
	//wrapped_dot first < length a/b,numb Iterations, other junk not sure pls help>
	wrapped_DOT_matrix <float, 6, 16, 4, 5, 5>(INPUT_STREAM, OUTPUT_STREAM);

	return;
}


