
#include <assert.h>
#include <ap_axi_sdata.h>
int const Row = 6;
int const Col = 6;
int const NUMBVECTORS2_h = 10;
#include "pushpop.h"

// this is not needed the compiler is smart enough to already do this!
//const float factorials[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000};
//#define DB_DEBUG


#define MCR_SIZE 6
typedef ap_axiu<32,4,5,5> AXI_VAL;

// function prototypes WHY
void exponential (float in[5][5],float out[5][5]);

float DOT_WITH_EXP (float a[6],float b[6]);

void DOT_accel (AXI_VAL INPUT_STREAM[2*MCR_SIZE], AXI_VAL OUTPUT_STREAM[1]);

void standalone_mmult (float A[5][5], float B[5][5], float C[5][5]);
void HLS_accel (AXI_VAL in_stream[2*MCR_SIZE], AXI_VAL out_stream[MCR_SIZE]);



/* ****************************** C++ TEMPLATES ************************************** */


/***********************************************************************************/
/**********************************dot stuff****************************************/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//just the exponential optimized for 16 iterations takes
//TODO make dot_exp1 use this function instead of having it directly in the function
template <typename T, int Iter>
float EXP16(T x)
{


	float factorials[Iter];

	factorials[0] = 1;
	//  all the factorial are pre-saved.
	Factorial:for (int i = 0; i < Iter; i++){
		factorials[i+1] = factorials[i] * (i+1);
		//printf("%f\n",factorials[i]);
	}

	float sum,inital;
	float pre_exp[Iter];
	float pre2_exp[8];
	float pre3_exp[4];
	float pre4_exp[2];
	int n;
#pragma HLS INLINE
	float power_out[Iter];
	//float power_out1[Iter];
	float pow_2,pow_4,pow_8;
	power_out[0] = 1;
	power_out[1] = x;
	pow_2 = x*x;
	power_out[2] = pow_2;

	inital = x + 1;
	//pow_3 = pow_2*x;
	//power_out[3] = pow_3;
	//pow_4 = pow_3*x;
	//power_out[4] = pow_4;

	//x+2 is 1st is 1 2nd is x so 1+x and 1+1+x is part of 1/(1+e^x)
	//pre2_exp[0] = x + 2;

	power_loop2:for(int j = 2; j< Iter/4; j = j + 2){
		// leapfrog 1 3...
		power_out[j+1] = power_out[j-1]*pow_2;
		// leapfrog 2 4...
		power_out[j+2] = power_out[j]*pow_2;
	}
	pow_4 = power_out[4];
	//each iteration of a power loop
	power_loop:for(int j = 0; j< Iter; j = j + 4){
		// leapfrog 1 5 9 13...
		power_out[j+4] = power_out[j]*pow_4;
		// leapfrog 2 6 10 14...
		power_out[j+5] = power_out[j+1]*pow_4;
		// leapfrog 3 7 11 15...
		power_out[j+6] = power_out[j+2]*pow_4;
		// leapfrog 4 8 12 16...
		power_out[j+7] = power_out[j+3]*pow_4;

		//printf("powerout: %.11f\n",power_out[j+1]);
	}
	/*
	pow_8 = power_out[8];
	power_loop8:for(int j = 0; j< Iter; j = j + 8){
		// leapfrog 1 5 9 13...
		power_out[j+8] = power_out[j]*pow_8;
		// leapfrog 2 6 10 14...
		power_out[j+9] = power_out[j+1]*pow_8;
		// leapfrog 3 7 11 15...
		power_out[j+10] = power_out[j+2]*pow_8;
		// leapfrog 4 8 12 16...
		power_out[j+11] = power_out[j+3]*pow_8;
		// leapfrog 1 5 9 13...
		power_out[j+12] = power_out[j+4]*pow_8;
		// leapfrog 2 6 10 14...
		power_out[j+13] = power_out[j+5]*pow_8;
		// leapfrog 3 7 11 15...
		power_out[j+14] = power_out[j+6]*pow_8;
		// leapfrog 4 8 12 16...
		power_out[j+15] = power_out[j+7]*pow_8;

		//printf("powerout: %.11f\n",power_out[j+1]);
	}
	*/


	//for(int j = 2; j< Iter; j++){
	//	printf("powerout: %.11f N: %d\n",power_out[j],j);
	//}

	DOT_exp1_label1:for (n = 2; n < Iter; n++){

		pre_exp[n] = power_out[n]/factorials[n];

		//printf("pre:%f with %d\n",pre_exp[n],n);
	}

	pre2_exp[0] = inital;
	//printf("post1:%f\n",pre2_exp[0]);
	//printf("should:%f\n",x + 2);

	ADD1_loop:for(n = 2; n < Iter; n = n + 2){
		pre2_exp[n/2] = pre_exp[n] + pre_exp[n+1];
	}
	sum = 0;
	ADD2_loop:for(int l = 0; l < 8; l = l + 2){
		sum += pre2_exp[l] + pre2_exp[l+1];
	}
return sum;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//just the exponential optimized for 16 iterations for 1/1+e^x

template <typename T, int Iter>
float EXP16_linear_reg(T x)
{


	float factorials[Iter];

	factorials[0] = 1;
	//  all the factorial are pre-saved.
	Factorial:for (int i = 0; i < Iter; i++){
		factorials[i+1] = factorials[i] * (i+1);
		//printf("%f\n",factorials[i]);
	}

	float sum,inital;
	float pre_exp[Iter];
	float pre2_exp[8];
	float pre3_exp[4];
	float pre4_exp[2];
	int n;
#pragma HLS INLINE
	float power_out[Iter];
	//float power_out1[Iter];
	float pow_2,pow_4,pow_8;
	power_out[0] = 1;
	power_out[1] = x;
	pow_2 = x*x;
	power_out[2] = pow_2;

	inital = x + 2;
	//pow_3 = pow_2*x;
	//power_out[3] = pow_3;
	//pow_4 = pow_3*x;
	//power_out[4] = pow_4;

	//x+2 is 1st is 1 2nd is x so 1+x and 1+1+x is part of 1/(1+e^x)
	//pre2_exp[0] = x + 2;

	power_loop2:for(int j = 2; j< Iter/4; j = j + 2){
		// leapfrog 1 3...
		power_out[j+1] = power_out[j-1]*pow_2;
		// leapfrog 2 4...
		power_out[j+2] = power_out[j]*pow_2;
	}
	pow_4 = power_out[4];
	//each iteration of a power loop
	power_loop:for(int j = 0; j< Iter; j = j + 4){
		// leapfrog 1 5 9 13...
		power_out[j+4] = power_out[j]*pow_4;
		// leapfrog 2 6 10 14...
		power_out[j+5] = power_out[j+1]*pow_4;
		// leapfrog 3 7 11 15...
		power_out[j+6] = power_out[j+2]*pow_4;
		// leapfrog 4 8 12 16...
		power_out[j+7] = power_out[j+3]*pow_4;

		//printf("powerout: %.11f\n",power_out[j+1]);
	}
	/*
	pow_8 = power_out[8];
	power_loop8:for(int j = 0; j< Iter; j = j + 8){
		// leapfrog 1 5 9 13...
		power_out[j+8] = power_out[j]*pow_8;
		// leapfrog 2 6 10 14...
		power_out[j+9] = power_out[j+1]*pow_8;
		// leapfrog 3 7 11 15...
		power_out[j+10] = power_out[j+2]*pow_8;
		// leapfrog 4 8 12 16...
		power_out[j+11] = power_out[j+3]*pow_8;
		// leapfrog 1 5 9 13...
		power_out[j+12] = power_out[j+4]*pow_8;
		// leapfrog 2 6 10 14...
		power_out[j+13] = power_out[j+5]*pow_8;
		// leapfrog 3 7 11 15...
		power_out[j+14] = power_out[j+6]*pow_8;
		// leapfrog 4 8 12 16...
		power_out[j+15] = power_out[j+7]*pow_8;

		//printf("powerout: %.11f\n",power_out[j+1]);
	}
	*/


	//for(int j = 2; j< Iter; j++){
	//	printf("powerout: %.11f N: %d\n",power_out[j],j);
	//}

	DOT_exp1_label1:for (n = 2; n < Iter; n++){

		pre_exp[n] = power_out[n]/factorials[n];

		//printf("pre:%f with %d\n",pre_exp[n],n);
	}

	pre2_exp[0] = inital;
	//printf("post1:%f\n",pre2_exp[0]);
	//printf("should:%f\n",x + 2);

	ADD1_loop:for(n = 2; n < Iter; n = n + 2){
		pre2_exp[n/2] = pre_exp[n] + pre_exp[n+1];
	}
	sum = 0;
	ADD2_loop:for(int l = 0; l < 8; l = l + 2){
		sum += pre2_exp[l] + pre2_exp[l+1];
	}
return 1/sum;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`````
template <typename T, int DIMdot, int Iter>
float DOT_exp1(T a[DIMdot],T b[DIMdot])
{


	T x = 0;
	T Ans = 0;


	#pragma HLS INLINE

	//new new NEW modified version! 15 clock cycle total improvement!
	// dot product of a A*B matrix
	x = a[0]*b[0] + a[1]*b[1];
	DOT_product:for (int j = 2; j < DIMdot; j = j+2)
		{
		x += a[j]*b[j] + a[j+1]*b[j+1];
		}
	/*
	//printf("Xval:%.11f\n",x);
	//this is the case for 16 iteration where the value goes negative after -5.036565 and e^x effectivly is set to 0 thus 1/(1+0) = 1;
	if (x <= -5.03657){
		return 1;
	}
	*/
	//this is the case for 16 iteration where the value goes negative after -5.036565 and e^x effectivly is set to 0 thus e^-5.036565 = 0;
	if (x <= -5.03657){
		return 0;
	}
	//inital = x + 2;


		//return 1/sum; would be for 1/(1+e^x)
		//return 1/sum;
	Ans = EXP16<float, Iter>(x);
	return Ans;

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Softmax_handler
template <typename T, int DIMdot>
void Normilizer(T in1[DIMdot],T out1[DIMdot]){
	//only works for even dim sizes
	T Temp_array[DIMdot/2];
	T sum;
	//sums up so only 3 more adds are left for most efficient for size of array of 6.
	sum_loop1:for(int i = 0; i < DIMdot; i = i + 2){
		Temp_array[i/2] = in1[i]+in1[i+1];
	}
	sum = Temp_array[0];
	sum_loop2:for(int i = 1; i < DIMdot/2; i++){
		sum += Temp_array[i];
	}
	Div_loop:for(int j = 0; j < DIMdot; j++){
		out1[j] = in1[j]/sum;
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// --------------------------------------------------------------------
// function to be accelerated in HW wrapped with AXI4-Stream interface
///dont know if i need a wrapper on not
template <typename T, int DIMdot, int Iterations, int U, int TI, int TD>
void wrapped_DOT (
	AXI_VAL in_stream[2*DIMdot],
	AXI_VAL out_stream[1])
{

#pragma HLS INLINE

	T a[DIMdot];
	T b[DIMdot];
	//T out;
	//????????????
	assert(sizeof(T)*8 == 32);
	//????????????

	// stream in first matrix
	for(int i=0; i<DIMdot; i++)
		{
#pragma HLS PIPELINE II=1
			a[i] = pop_stream<T,U,TI,TD>(in_stream[i]);
		}

		// stream in second matrix
		for(int i=0; i<DIMdot; i++)
				{
	#pragma HLS PIPELINE II=1
					b[i] = pop_stream<T,U,TI,TD>(in_stream[i+DIMdot]);
				}

			// stream out result matrix

			//#pragma HLS PIPELINE II=1
			////////NOT SURE if i need the pipeline or not
			// dot_exp1 returns out which is then single pushed to AXI to out stream all rapped.
			out_stream[0] = push_single_val<T,U,TI,TD>(DOT_exp1<T, DIMdot, Iterations>(a,b));
				return;

}

 ////////////////////////////////////////////////////////////////////////////
//version 2 handling certain cases specific 1 iterations

template <typename T, int DIMdot, int Iterations, int U, int TI, int TD>
void wrapped_DOT_matrix (
	AXI_VAL in_stream[DIMdot+DIMdot*DIMdot],
	AXI_VAL out_stream[DIMdot])
{

#pragma HLS INLINE

	T a[DIMdot][DIMdot];
	T b[DIMdot];
	T in[DIMdot];
	T out[DIMdot];
	//????????????
	assert(sizeof(T)*8 == 32);
	//????????????
	// stream in first matrix
	for(int i=0; i<DIMdot; i++){
		for(int j=0; j<DIMdot; j++)
		{
#pragma HLS PIPELINE II=1
			int k = i*DIMdot+j;
			a[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);

		}
	}
		// stream in second matrix
		for(int j=0; j<DIMdot; j++)
			{
#pragma HLS PIPELINE II=1
				int k = j+DIMdot*DIMdot;
				//j and i are switched to give transpose
				b[j] = pop_stream<T,U,TI,TD>(in_stream[k]);

			}

		//first part of algorithm
			// do HW multiplication
	DOT_LOOP:for(int w = 0; w < DIMdot; w++){
		in[w] = DOT_exp1<T, DIMdot, Iterations>(a[w],b);
		}
		printf("part of in0:%f\n",in[0]);
		printf("part of in1:%f\n",in[1]);
		printf("part of in2:%f\n",in[2]);
		printf("part of in3:%f\n",in[3]);
		printf("part of in4:%f\n",in[4]);
		printf("part of in5:%f\n",in[5]);
		//softmax
		Normilizer<T,DIMdot>(in,out);



		//printf("part of out:%f\n",out[0]);
			// stream out result matrix
			for(int k=0; k<DIMdot; k++){
					#pragma HLS PIPELINE II=1
					out_stream[k] = push_stream<T,U,TI,TD>(out[k],k == (DIMdot-1));
				}
			//#pragma HLS PIPELINE II=1
			////////NOT SURE if i need the pipeline or not
			// dot_exp1 returns out which is then single pushed to AXI to out stream all rapped.
			//out_stream[k] = push_single_val<T,U,TI,TD>(DOT_exp1<T, DIMdot, Iterations>(a,b));


	return;
}



// test the function for logistic regression
template <typename T, int DIMdot, int Iter, int U, int TI, int TD>
int test_DOT_EXP(void)
{
	//variable intilization
	int i, err;
	T Array1[DIMdot];
	T Array2[DIMdot];
	T one_over_one_plus_e,one_over_one_plus_e_new;

	//test array generation
	for(i = 0; i<DIMdot; i++)
		Array1[i] = (float)(i)/100;

	for(i = 0; i<DIMdot; i++)
		Array2[i] = (float)(i)/10;


	printf("DEBUGGING AXI4 STREAMING DATA TYPES!\r\n");

	// prepare data for the DUT
	AXI_VAL inp_stream[2*DIMdot];
	AXI_VAL out_stream[1];

	assert(sizeof(T)*8 == 32);
	// stream in the first input array
	for(int i=0; i<DIMdot; i++)
		{
		// theres a 0 at the end becuase it indicates the stream is not over yet.
			inp_stream[i] = push_stream<T,U,TI,TD>(Array1[i],0);
		}
	// stream in the second input array
	for(int i=0; i<DIMdot; i++)
		{
			// IT checks to see when i is DIMdot-1 so it indicates the end of the stream
			inp_stream[i+DIMdot] = push_stream<T,U,TI,TD>(Array2[i],i == (DIMdot-1));
		}


			//call the DUT
			wrapped_DOT<T, DIMdot, Iter, U, TI, TD>(inp_stream, out_stream);


	// extract the output variable from the out stream
	one_over_one_plus_e_new = pop_stream<T,U,TI,TD>(out_stream[0]);
	printf("1/(1+e^x) for array1 and array2 WITH AXI: %.10f\n",one_over_one_plus_e_new);

	// reference dot product with exponential
	one_over_one_plus_e = DOT_exp(Array1,Array2);

	printf("1/(1+e^x) for array1 and array2: %.10f\n",one_over_one_plus_e);
	// Matrix comparison
	err = 0;
	 if (round4dec(one_over_one_plus_e) != round4dec(one_over_one_plus_e_new)){
		 err++;
		 printf("%f some amount off",(one_over_one_plus_e -one_over_one_plus_e_new));
	 }

	if (err == 0)
		printf(" Test successful!\r\n");
	else
		printf("Test failed!\r\n");

	return 0;
}
