#include <stdio.h>
#include <stdlib.h>

#include "machine.h"


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

/////////////////////////////////////////////////////////////////////////////////////

/***********************************************************************************/
/**********************************dot stuff****************************************/



//template <typename T, int DIMdot,int NUMBVECTORS, int Iter>
//float SVM(T FV[NUMBVECTORS][DIMdot],T Input[DIMdot],T Alpha[NUMBVECTORS], T Sigma)





void DOT_Full_Algorithm_accel (AXI_VAL INPUT_STREAM[3*MCR_SIZE+2*MCR_SIZE*MCR_SIZE], AXI_VAL OUTPUT_STREAM[2])
{
	#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
	#pragma HLS INTERFACE axis      port=OUTPUT_STREAM
	#pragma HLS INTERFACE axis      port=INPUT_STREAM
	//NOTE: changed from float function to void function
	//wrapped_dot first < length a/b,numb Iterations, other junk not sure pls help>
	wrapped_DOT_Full_Algorithm <float, 6, 16, 4, 5, 5>(INPUT_STREAM, OUTPUT_STREAM);

	return;
}



