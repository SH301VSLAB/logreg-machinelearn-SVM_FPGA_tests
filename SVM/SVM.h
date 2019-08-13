
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

//Radial Basis Function
// for 10*6

template <typename T, int DIMdot,int NUMBVECTORS, int Iter>
float SVM(T FV[NUMBVECTORS][DIMdot],T Input[DIMdot],T Alpha[NUMBVECTORS], T Sigma[1]){

	float Dif[NUMBVECTORS][DIMdot];
	float Pre_Sum[NUMBVECTORS][DIMdot];
	float Sum[NUMBVECTORS];
	float To_DOT[NUMBVECTORS];
	float divterm;

	float Last_Added;
	float DOT_pre_sum1[(NUMBVECTORS-2)/2];
	float DOT_pre_sum2[(NUMBVECTORS-2)/4];
	//float DOT_pre_sum3[2];

	float result;
	int i,j;
#pragma HLS INLINE
	// using unsigned floats may be beneficial as the sign is not relevant.
	Dif1:for(i = 0; i < NUMBVECTORS; i++)
		Dif2:for(j = 0; j < DIMdot; j++){
			// obtains differential
			Dif[i][j] = FV[i][j] - Input[j];
			// obtains the square;
			Pre_Sum[i][j] = Dif[i][j]*Dif[i][j];
		}
	//an optimization of the summing process
	Sum1:for(i = 0; i < NUMBVECTORS; i++){
		Sum[i] = Pre_Sum[i][0] + Pre_Sum[i][1];
		Sum2:for(j = 2; j < DIMdot-1; j = j + 2){
			// j + 1 was added there was a mistake
			Sum[i] += Pre_Sum[i][j] + Pre_Sum[i][j+1];
		}
	}
	// this term can be placed anywhere before EXP16 is done.
	divterm = 2*Sigma[0]*Sigma[0];

	EXP:for(i = 0; i < NUMBVECTORS; i++){
		//changed from To_DOT[i] = -1*EXP16<T, Iter>(Sum[i]/divterm);
		To_DOT[i] = EXP16<T, Iter>(-1*(Sum[i])/divterm);
	}
	//DOT10 section
	// the first addition is done here so that then a cascade of 8 adds into 4 adds into 2 adds
	result = To_DOT[0]*Alpha[0] + To_DOT[1]*Alpha[1];
	// these loops could be put into a single for loop but for now are split up for modularity
	DOT10:for (int j = 0; j < NUMBVECTORS-2; j = j+2)
		{
		DOT_pre_sum1[j/2] = To_DOT[j+2]*Alpha[j+2] + To_DOT[j+3]*Alpha[j+3];
		}

	ADD_loop1:for (int j = 0; j < (NUMBVECTORS-2)/2; j = j+2)
		{
		DOT_pre_sum2[j/2] = DOT_pre_sum1[j] + DOT_pre_sum1[j+1];
		}

	result += DOT_pre_sum2[0] + DOT_pre_sum2[1];

	return result;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Radial Basis Function
template <typename T, int DIMdot,int NUMBVECTORS, int Iter>
float SVM_scale(T FV[NUMBVECTORS][DIMdot],T Input[DIMdot],T Alpha[NUMBVECTORS], T Sigma[1]){

	float Dif[NUMBVECTORS][DIMdot];
	float Pre_Sum[NUMBVECTORS][DIMdot];
	float Sum[NUMBVECTORS];
	float To_DOT[NUMBVECTORS];
	float divterm;

	float Last_Added;
	float DOT_pre_sum1[(NUMBVECTORS-2)/2];
	float DOT_pre_sum2[(NUMBVECTORS-2)/4];
	//float DOT_pre_sum3[2];

	float result;
	int i,j;
#pragma HLS INLINE
	// using unsigned floats may be benificitial as the sign is not relevant.
	Dif1:for(i = 0; i < NUMBVECTORS; i++)
		Dif2:for(j = 0; j < DIMdot; j++){
			// obtains differential
			Dif[i][j] = FV[i][j] - Input[j];
			// obtains the square;
			Pre_Sum[i][j] = Dif[i][j]*Dif[i][j];
		}
	//an optimization of the summing process
	Sum1:for(i = 0; i < NUMBVECTORS; i++){
		Sum[i] = Pre_Sum[i][0] + Pre_Sum[i][1];
		Sum2:for(j = 2; j < DIMdot-1; j = j + 2){
			// j + 1 was added there was a mistake
			Sum[i] += Pre_Sum[i][j] + Pre_Sum[i][j+1];
		}
	}
	// this term can be placed anywhere before EXP16 is done.
	divterm = 2*Sigma[0]*Sigma[0];

	EXP:for(i = 0; i < NUMBVECTORS; i++){
		To_DOT[i] = EXP16<T, Iter>(-1*(Sum[i])/divterm);
	}
	//DOT10 section
	// the first addition is done here so that then a cascade of 8 adds into 4 adds into 2 adds
	result = To_DOT[0]*Alpha[0] + To_DOT[1]*Alpha[1];
	// these loops could be put into a single for loop but for now are split up for modularity
	DOT10:for (int j = 0; j < NUMBVECTORS-2; j = j+2)
		{
		DOT_pre_sum1[j/2] = To_DOT[j+2]*Alpha[j+2] + To_DOT[j+3]*Alpha[j+3];
		}

	ADD_loop1:for (int j = 0; j < (NUMBVECTORS-2)/2; j = j+2)
		{
		DOT_pre_sum2[j/2] = DOT_pre_sum1[j] + DOT_pre_sum1[j+1];
		}

	loop_final:for (int j = 0; j < (NUMBVECTORS-2)/4; j = j+2)
	result += DOT_pre_sum2[j] + DOT_pre_sum2[j+1];

	return result;
}


/**********************************dot stuff****************************************/
/***********************************************************************************/

// reference function
template <typename T, int DIM>
void matrix_multiply_ref(T a[DIM][DIM], T b[DIM][DIM], T out[DIM][DIM])
{

	// matrix multiplication of a A*B matrix
	for (int ia = 0; ia < DIM; ++ia)
		for (int ib = 0; ib < DIM; ++ib)
		{

			float sum = 0;

			for (int id = 0; id < DIM; ++id)

				sum += a[ia][id] * b[id][ib];

			out[ia][ib] = sum;
		}

		return;
}

// --------------------------------------------------------
// function to be accelerated in HW
template <typename T, int DIM>
void mmult_hw(T a[DIM][DIM], T b[DIM][DIM], T out[DIM][DIM])
{

	int const FACTOR = DIM;
	#pragma HLS INLINE
	//#pragma HLS array_partition variable=a block factor=FACTOR dim=2
	//#pragma HLS array_partition variable=b block factor=FACTOR dim=1

	// matrix multiplication of a A*B matrix
	L1:for (int ia = 0; ia < DIM; ++ia)
		L2:for (int ib = 0; ib < DIM; ++ib)
		{
			//#pragma HLS PIPELINE II=1
			T sum = 0;
			L3:for (int id = 0; id < DIM; ++id)
				sum += a[ia][id] * b[id][ib];
			out[ia][ib] = sum;
		}

		return;
}

// --------------------------------------------------------
// functions to insert and extract elements from an axi stream
// includes conversion to correct data type


// 10*6 + 1*6 + 1*10 + 1;
// only 1 value out;
template <typename T, int DIMdot, int NUMBVECTORS, int Iterations, int U, int TI, int TD>
void wrapped_SVM (
	AXI_VAL in_stream[77],
	AXI_VAL out_stream[1])
{
//(NUMBVECTORS+1)*DIMdot+NUMBVECTORS+1
#pragma HLS INLINE

	T a[NUMBVECTORS][DIMdot];
	T b[DIMdot];
	T c[NUMBVECTORS];
	T d[1];

	T out;
	//????????????
	assert(sizeof(T)*8 == 32);
	//????????????
	// stream in first matrix
	// k++ method works as does the int k = some number + i*asdasd
int k = 0;
	for(int i=0; i<NUMBVECTORS; i++){
		for(int j=0; j<DIMdot; j++)
		{
#pragma HLS PIPELINE II=1
			//int k = i*DIMdot+j;
			a[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);
			//a[i][j] = 1;
			k++;
		}
	}

		// stream in second matrix
		for(int j=0; j<DIMdot; j++)
			{
#pragma HLS PIPELINE II=1
				//int k = j+NUMBVECTORS*DIMdot;
				//j and i are switched to give transpose
				b[j] = pop_stream<T,U,TI,TD>(in_stream[k]);
				k++;
				//b[j] = 1;

			}


		// stream in third matrix
		for(int j=0; j<NUMBVECTORS; j++)
			{
#pragma HLS PIPELINE II=1
				//int k = j+(1+NUMBVECTORS)*DIMdot;
				//j and i are switched to give transpose
				c[j] = pop_stream<T,U,TI,TD>(in_stream[k]);
				k++;
				//c[j] = 1;
			}
			//d = pop_stream<T,U,TI,TD>(in_stream[(1+NUMBVECTORS)*DIMdot+NUMBVECTORS]);
			d[0] = pop_stream<T,U,TI,TD>(in_stream[76]);

		//float SVM(T FV[NUMBVECTORS][DIMdot],T Input[DIMdot],T Alpha[NUMBVECTORS], T Sigma)
			//#pragma HLS PIPELINE II=1
			////////NOT SURE if i need the pipeline or not
			// SVM returns out which is then single pushed to AXI to out stream all wrapped.
			//out  = 234234;
		out = SVM<T, DIMdot, NUMBVECTORS, Iterations>(a,b,c,d);
		out_stream[0] = push_single_val<T,U,TI,TD>(out);
			//out_stream[0] = push_stream<T,U,TI,TD>(out,1);


	//return;
}

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// FULL SVM
template <typename T, int DIMdot, int Iter, int U, int TI, int TD>
int Full_SVM_TEST(void)
{


	//TODO could change to 3D storage setup to allow for less repeated for loops
	//variable initialization
	int i, err;
	T Array1[NUMBVECTORS2_h][DIMdot];
	T Array2[DIMdot];
	T Array3[NUMBVECTORS2_h];
	T sig[1];

	sig[0] = 1;
	T Array_out_FPGA[1];
	T Array_out_ARM[1];
	T SUM;

	//test array generation
	for(i = 0; i<NUMBVECTORS2_h; i++){
		for(int j = 0; j<DIMdot; j++){
			Array1[i][j] = ((float)(i+j+2))/100;
			Array2[j] = ((float)(i+j+2))/100;

		}
		Array3[i] = ((float)(i+2))/20;
	}


	printf("DEBUGGING AXI4 STREAMING DATA TYPES!\r\n");

	// prepare data for the DUT
	AXI_VAL inp_stream[77];
	AXI_VAL out_stream[1];

	assert(sizeof(T)*8 == 32);
	// stream in the first input array
	for(int i=0; i<NUMBVECTORS2_h; i++)
		for(int j = 0; j<DIMdot; j++)
			{
			int k = i*DIMdot+j;
			// theres a 0 at the end becuase it indicates the stream is not over yet.
				inp_stream[k] = push_stream<T,U,TI,TD>(Array1[i][j],0);
			}
	// stream in the second input array
	for(int i=0; i<DIMdot; i++)
		{
			// IT checks to see when i is DIMdot-1 so it indicates the end of the stream
			inp_stream[i+NUMBVECTORS2_h*DIMdot] = push_stream<T,U,TI,TD>(Array2[i],0);
		}
	///////////////////////////////////////////////////////////////////////
	//TODO will try to up wrapped dot matrix first and re order stuff around.
	///////////////////////////////////////////////////////////////////////
	// stream in the first input array
		for(int j = 0; j<NUMBVECTORS2_h; j++)
			{
			//k is the location in the stack and each input variable requires the size of the last location
			int k = j+(NUMBVECTORS2_h+1)*DIMdot;
			// theres a 0 at the end becuase it indicates the stream is not over yet.
				inp_stream[k] = push_stream<T,U,TI,TD>(Array3[j],0);
			}


				inp_stream[76] = push_stream<T,U,TI,TD>(sig[0],1);

	wrapped_SVM<T, DIMdot, NUMBVECTORS2_h,Iter, U, TI, TD> (inp_stream, out_stream);




	// extract the output variable from the out stream
			Array_out_FPGA[0] = pop_stream<T,U,TI,TD>(out_stream[0]);
			printf("WITH FPGA: %.10f\n",Array_out_FPGA[0]);

			Array_out_ARM[0] = ARM_SVM(Array1,Array2,Array3,sig);
			printf("WITH ARM: %.10f\n",Array_out_ARM[0]);



	return 0;
}


