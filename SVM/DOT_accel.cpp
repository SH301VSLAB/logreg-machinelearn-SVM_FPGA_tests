#include <stdio.h>
#include <stdlib.h>

#include "SVM.h"


// THIS IS THE TOP LEVEL DESIGN THAT WILL BE SYNTHESIZED
//#define MCR_SIZE 6
//i dont know the size assumming its 6
#define MCR_SIZE 6
#define TENSIZE 10

#define SCALESIZE 10


float KBF (float a[10][6],float b[6], float Alp[10],float sig[1])
{

	return SVM<float, 6, 10, 16>(a,b,Alp,sig);

}

//work in progress
float KBF_scalable (float a[SCALESIZE][6],float b[6], float Alp[SCALESIZE],float sig[1])
{

	return SVM_scale<float, 6, SCALESIZE, 16>(a,b,Alp,sig);

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

