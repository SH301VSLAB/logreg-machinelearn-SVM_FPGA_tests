#include <stdio.h>
#include <stdlib.h>

#include "DOT.h"


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
void exponential (float in[5][5],float out[5][5])
{

	Taylor_exponential <float, 5, 16>(in,out);

}
/////////////////////////////////////////////////////////////////////////////////////

/***********************************************************************************/
/**********************************dot stuff****************************************/
float DOT_WITH_EXP (float a[6],float b[6])
{

	return DOT_exp1 <float, 6, 16>(a,b);

}

float KBF (float a[10][6],float b[6], float Alp[10],float sig[1])
{

	return SVM<float, 6, 10, 16>(a,b,Alp,sig);

}





float KBF_scalable (float a[SCALESIZE][6],float b[6], float Alp[SCALESIZE],float sig[1])
{

	return SVM_scale<float, 6, SCALESIZE, 16>(a,b,Alp,sig);

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
//(1+TENSIZE)*MCR_SIZE+TENSIZE+1

void KBF_accel (AXI_VAL INPUT_STREAM[77], AXI_VAL OUTPUT_STREAM[1])
{
	#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
	#pragma HLS INTERFACE axis      port=OUTPUT_STREAM
	#pragma HLS INTERFACE axis      port=INPUT_STREAM
	//NOTE: changed from float function to void function
	//wrapped_dot first < length a/b,numb, supportof10, Iterations, other junk not sure pls help>
	wrapped_SVM <float, 6, 10, 16, 4, 5, 5>(INPUT_STREAM, OUTPUT_STREAM);

	return;
}

/**********************************dot stuff****************************************/
/***********************************************************************************/


//void HLS_accel (AXI_VAL in_stream[2*MCR_SIZE], AXI_VAL out_stream[MCR_SIZE])
void HLS_accel (AXI_VAL INPUT_STREAM[2*MCR_SIZE], AXI_VAL OUTPUT_STREAM[MCR_SIZE])
{
#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
#pragma HLS INTERFACE axis      port=OUTPUT_STREAM
#pragma HLS INTERFACE axis      port=INPUT_STREAM

// HLS DEPRECATED MODE
//	// Map ports to Vivado HLS interfaces 
//	#pragma HLS INTERFACE ap_fifo port=in_stream
//	#pragma HLS INTERFACE ap_fifo port=out_stream
//	// Map HLS ports to AXI interfaces
//	#pragma HLS RESOURCE variable=in_stream  core=AXIS metadata="-bus_bundle INPUT_STREAM"
//	#pragma HLS RESOURCE variable=out_stream core=AXIS metadata="-bus_bundle OUTPUT_STREAM"
//	#pragma HLS RESOURCE variable=return core=AXI4LiteS metadata="-bus_bundle CONTROL_BUS"

	wrapped_mmult_hw <float, 5, 5*5, 4, 5, 5>(INPUT_STREAM, OUTPUT_STREAM);

	return;
}

