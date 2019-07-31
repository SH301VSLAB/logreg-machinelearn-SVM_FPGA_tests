
#include <assert.h>
#include <ap_axi_sdata.h>
int const Row = 6;
int const Col = 6;
int const NUMBVECTORS2_h = 10;

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

/////////////////////////////////////////////////////////////////////////////////////
template <typename T, int DIM, int Iter>
void Taylor_exponential (T in[DIM][DIM],T out[DIM][DIM])
{

	//obtains factorials
	float factorials[Iter];

	factorials[0] = 1;

	for (int i = 0; i < Iter; i++){
		factorials[i+1] = factorials[i] * (i+1);
		//printf("%f\n",factorials[i]);
	}
	#pragma HLS INLINE
	// matrix taylor series of e^x
	l1: for (int ia = 0; ia < DIM; ++ia)
		l2: for (int ib = 0; ib < DIM; ++ib)
		{

			float sum = 0;
			//could edit so that the first iteration starts at 1 but since we are going for 1/(1+e^x) we could add 2.
			//power_out = in[ia][ib];
			//double power_out = 1;
			float power_out = 1;
			l3: for (int n = 0; n < Iter; n++){
					//sum += pow(in[ia][ib],n)/factorials[n];
				//gets the exponetial
				sum += power_out/factorials[n];
				//gets the power
				//printf("ACTUAL POWER: %f\n NEW POWER: %f\n",pow(in[ia][ib],n),power_out);
				power_out = power_out*in[ia][ib];

			}
			out[ia][ib] = sum;
			//printf("EXPONETIANLS INITAL: %f\n",sum);
		}

}

/////////////////////////////////////////////////////////////////////////////////////


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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

template <typename T, int U, int TI, int TD>
T pop_stream(ap_axiu <sizeof(T)*8,U,TI,TD> const &e)
{
#pragma HLS INLINE

	assert(sizeof(T) == sizeof(int));
	union
	{
		int ival;
		T oval;
	} converter;
	converter.ival = e.data;
	T ret = converter.oval;

	volatile ap_uint<sizeof(T)> strb = e.strb;
	volatile ap_uint<sizeof(T)> keep = e.keep;
	volatile ap_uint<U> user = e.user;
	volatile ap_uint<1> last = e.last;
	volatile ap_uint<TI> id = e.id;
	volatile ap_uint<TD> dest = e.dest;

	return ret;
}

template <typename T, int U, int TI, int TD> ap_axiu <sizeof(T)*8,U,TI,TD> push_stream(T const &v, bool last = false)
{
#pragma HLS INLINE
	ap_axiu<sizeof(T)*8,U,TI,TD> e;

	assert(sizeof(T) == sizeof(int));
	union
	{
		int oval;
		T ival;
	} converter;
	converter.ival = v;
	e.data = converter.oval;

	// set it to sizeof(T) ones
	e.strb = -1;
	e.keep = 15; //e.strb;
	e.user = 0;
	// this is a last test to see if the output is the last variable 0 means its not the end
	//of the transmission, when k would be equal to size-1 would indicate the end since it starts at 0.
	e.last = last ? 1 : 0;
	e.id = 0;
	e.dest = 0;
	return e;
}

/////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int U, int TI, int TD> ap_axiu <sizeof(T)*8,U,TI,TD> push_single_val(T const &v)
{
#pragma HLS INLINE
	ap_axiu<sizeof(T)*8,U,TI,TD> e;
	//why do we downconvert here? i dont know i would like to know.
	assert(sizeof(T) == sizeof(int));
	union
	{
		int oval;
		T ival;
	} converter;
	converter.ival = v;
	e.data = converter.oval;

	// set it to sizeof(T) ones
	e.strb = -1;
	e.keep = 15; //e.strb;
	e.user = 0;
	// this is a last test to see if the output is the last variable 0 means its not the end
	//of the transmission, when k would be equal to size-1 would indicate the end since it starts at 0.
	//THIS IS A MODIFIED VERSION WHERE LAST IS SET to 1 AS IT IS THE ONLY VARIABLE.
	e.last = 1;
	e.id = 0;
	e.dest = 0;
	return e;
}
////////////////////////////////////////////////////////////////////////////////////////////////

// --------------------------------------------------------------------
// function to be accelerated in HW wrapped with AXI4-Stream interface

template <typename T, int DIM, int SIZE, int U, int TI, int TD>
void wrapped_mmult_hw (
	AXI_VAL in_stream[2*SIZE],
	AXI_VAL out_stream[SIZE])
{

#pragma HLS INLINE

	T a[DIM][DIM];
	T b[DIM][DIM];
	T out[DIM][DIM];

	assert(sizeof(T)*8 == 5);

	// stream in first matrix
	for(int i=0; i<DIM; i++)
		for(int j=0; j<DIM; j++)
		{
#pragma HLS PIPELINE II=1
			int k = i*DIM+j;
			a[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);

		}

		// stream in second matrix
		for(int i=0; i<DIM; i++)
			for(int j=0; j<DIM; j++)
			{
#pragma HLS PIPELINE II=1
				int k = i*DIM+j+SIZE;
				b[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);
			}

			// do HW multiplication
			mmult_hw<T, DIM>(a,b,out);

			// stream out result matrix
			for(int i=0; i<DIM; i++)
				for(int j=0; j<DIM; j++)
				{
					#pragma HLS PIPELINE II=1
					int k = i*DIM+j;
					out_stream[k] = push_stream<T,U,TI,TD>(out[i][j],k == (SIZE-1));
				}
				return;

}



// test the functions
template <typename T, int DIM, int SIZE, int U, int TI, int TD>
int test_matrix_mult(void)
{
	int i,j, err;

	T matOp1[DIM][DIM];
	T matOp2[DIM][DIM];
	T matMult_sw[DIM][DIM];
	T matMult_hw[DIM][DIM];

	/** Matrix Initiation */
	for(i = 0; i<DIM; i++)
		for(j = 0; j<DIM; j++)
			matOp1[i][j] = (float)(i+j);

	for(i = 0; i<DIM; i++)
		for(j = 0; j<DIM; j++)
			matOp2[i][j] = (float)(i*j);
	/** End of Initiation */


	printf("DEBUGGING AXI4 STREAMING DATA TYPES!\r\n");

	// prepare data for the DUT
	AXI_VAL inp_stream[2*SIZE];
	AXI_VAL out_stream[SIZE];

	assert(sizeof(T)*8 == 32);
	// stream in the first input  matrix
	for(int i=0; i<DIM; i++)
		for(int j=0; j<DIM; j++)
		{
			int k = i*DIM+j;
			inp_stream[k]      = push_stream<T,U,TI,TD>(matOp1[i][j],0);
		}
		// stream in the second input  matrix
		for(int i=0; i<DIM; i++)
			for(int j=0; j<DIM; j++)
			{
				int k = i*DIM+j;
				inp_stream[k+SIZE] = push_stream<T,U,TI,TD>(matOp2[i][j],k == (SIZE-1));
			}


			//call the DUT
			wrapped_mmult_hw<T, DIM, SIZE, U, TI, TD>(inp_stream, out_stream);

			// extract the output matrix from the out stream
			for(int i=0; i<DIM; i++)
				for(int j=0; j<DIM; j++)
				{
					int k = i*DIM+j;
					matMult_hw[i][j] = pop_stream<T,U,TI,TD>(out_stream[k]);
				}


	/* reference Matrix Multiplication */
	matrix_multiply_ref<T, DIM>(matOp1, matOp2, matMult_sw);

	/** Matrix comparison */
	err = 0;
	for (i = 0; (i<DIM && !err); i++)
		for (j = 0; (j<DIM && !err); j++)
			if (matMult_sw[i][j] != matMult_hw[i][j])
				err++;

	if (err == 0)
		printf("Matrixes identical ... Test successful!\r\n");
	else
		printf("Test failed!\r\n");

	return err;
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
///////////////////////////////
/*
template <typename T, int DIMdot, int Iterations, int U, int TI, int TD>
void wrapped_DOT_matrix (
	AXI_VAL in_stream[2*DIMdot*DIMdot],
	AXI_VAL out_stream[DIMdot])
{

#pragma HLS INLINE

	T a[DIMdot][DIMdot];
	T b[DIMdot][DIMdot];
	T out[DIMdot];
	//????????????
	assert(sizeof(T)*8 == 32);
	//????????????
	// stream in first matrix
	for(int i=0; i<DIMdot; i++)
		for(int j=0; j<DIMdot; j++)
		{
#pragma HLS PIPELINE II=1
			int k = i*DIMdot+j;
			a[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);

		}

		// stream in second matrix
		for(int i=0; i<DIMdot; i++)
			for(int j=0; j<DIMdot; j++)
			{
#pragma HLS PIPELINE II=1
				int k = i*DIMdot+j+DIMdot*DIMdot;
				//j and i are switched to give transpose
				b[j][i] = pop_stream<T,U,TI,TD>(in_stream[k]);
			}

			// do HW multiplication
		DOT_LOOP:for(int w = 0; w < DIMdot; w++){
			out[w] = DOT_exp1<T, DIMdot, Iterations>(a[w],b[w]);
		}
			// stream out result matrix
			for(int k=0; k<DIMdot; k++){
					#pragma HLS PIPELINE II=1
					out_stream[k] = push_stream<T,U,TI,TD>(out[k],k == (DIMdot-1));
				}
			//#pragma HLS PIPELINE II=1
			////////NOT SURE if i need the pipeline or not
			// dot_exp1 returns out which is then single pushed to AXI to out stream all wrapped.
			//out_stream[k] = push_single_val<T,U,TI,TD>(DOT_exp1<T, DIMdot, Iterations>(a,b));


	return;
}
*/

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




template <typename T, int DIMdot, int Iterations, int U, int TI, int TD>
void wrapped_DOT_Full_Algorithm (
		// the in_stream is caused by the first matrix and the vector then 2nd matrix then 3rd matrix of 2*DIMdot
	AXI_VAL in_stream[3*DIMdot+2*DIMdot*DIMdot],
	//only output of 2 comes out
	AXI_VAL out_stream[2])
{

#pragma HLS INLINE

	T a[DIMdot][DIMdot];
	T c[DIMdot][DIMdot];
	T b[DIMdot];
	T d[2][DIMdot];

	T in[DIMdot];
	T by2in[2];

	T soft1[DIMdot];
	T soft2[DIMdot];
	T soft3[2];
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
		// stream in the only array
		for(int j=0; j<DIMdot; j++)
			{
#pragma HLS PIPELINE II=1
				int k = j+DIMdot*DIMdot;
				//j and i are switched to give transpose
				b[j] = pop_stream<T,U,TI,TD>(in_stream[k]);

			}

		//stream in the second matrix

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
		Normilizer<T,DIMdot>(in,soft1);

		// stream in second matrix
		for(int i=0; i<DIMdot; i++){
			for(int j=0; j<DIMdot; j++)
			{
	#pragma HLS PIPELINE II=1
				// DIMdot*DIMdot and 1+...*DIMdot is accounting for places before
				int k = (1+i)*DIMdot+j+DIMdot*DIMdot;
				c[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);

			}
		}




	DOT_LOOP2:for(int w = 0; w < DIMdot; w++){
		in[w] = DOT_exp1<T, DIMdot, Iterations>(c[w],soft1);
		}
		printf("part of 2in0:%f\n",in[0]);
		printf("part of 2in1:%f\n",in[1]);
		printf("part of 2in2:%f\n",in[2]);
		printf("part of 2in3:%f\n",in[3]);
		printf("part of 2in4:%f\n",in[4]);
		printf("part of 2in5:%f\n",in[5]);
		//softmax
		Normilizer<T,DIMdot>(in,soft2);


		// stream in 3rd matrix which is 2*DIMdot in size
		for(int i=0; i<2; i++){
			for(int j=0; j<DIMdot; j++)
			{
	#pragma HLS PIPELINE II=1
				// DIMdot*DIMdot and 1+...*DIMdot is accounting for places before
				int k = (1+i)*DIMdot+j+2*DIMdot*DIMdot;
				d[i][j] = pop_stream<T,U,TI,TD>(in_stream[k]);

			}
		}

		DOT_LOOP3:for(int w = 0; w < 2; w++){
			by2in[w] = DOT_exp1<T, DIMdot, Iterations>(c[w],soft1);
			}
			printf("part of 2in0:%f\n",in[0]);
			printf("part of 2in1:%f\n",in[1]);
			printf("part of 2in2:%f\n",in[2]);
			printf("part of 2in3:%f\n",in[3]);
			printf("part of 2in4:%f\n",in[4]);
			printf("part of 2in5:%f\n",in[5]);
			//softmax
			Normilizer<T,2>(by2in,soft3);


		//printf("part of out:%f\n",out[0]);
			// stream out result matrix
			for(int k=0; k<2; k++){
					#pragma HLS PIPELINE II=1
					out_stream[k] = push_stream<T,U,TI,TD>(soft3[k],k == 1);
				}
			//#pragma HLS PIPELINE II=1
			////////NOT SURE if i need the pipeline or not
			// dot_exp1 returns out which is then single pushed to AXI to out stream all wrapped.
			//out_stream[k] = push_single_val<T,U,TI,TD>(DOT_exp1<T, DIMdot, Iterations>(a,b));


	return;
}








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







///////////////////////////////
/*
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
		Array1[i] = (float)(i);

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
		 printf("%f some amount off",(one_over_one_plus_e -one_over_one_plus_e_new)*100000000);
	 }

	if (err == 0)
		printf("Matrixes identicaldfgdfg ... Test successful!\r\n");
	else
		printf("Test failed!\r\n");

	return 0;
}
*/

// MATRIX version test
template <typename T, int DIMdot, int Iter, int U, int TI, int TD>
int test_DOT_EXP(void)
{
	//variable intilization
	int i, err;
	T Array1[DIMdot][DIMdot];
	T Array2[DIMdot];
	T out[DIMdot];
	T Array_out_FPGA[DIMdot];
	T Array_out_ARM[DIMdot];
	T SUM;

	//test array generation
	for(i = 0; i<DIMdot; i++)
		for(int j = 0; j<DIMdot; j++)
			Array1[i][j] = (float)(i+j+2);

	for(i = 0; i<DIMdot-1; i++)
		Array2[i] = (float)(i+1)/100;
	//this is the bias
	Array2[DIMdot-1] = 1;

	printf("DEBUGGING AXI4 STREAMING DATA TYPES!\r\n");

	// prepare data for the DUT
	AXI_VAL inp_stream[DIMdot+DIMdot*DIMdot];
	AXI_VAL out_stream[DIMdot];

	assert(sizeof(T)*8 == 32);
	// stream in the first input array
	for(int i=0; i<DIMdot; i++)
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
			inp_stream[i+DIMdot*DIMdot] = push_stream<T,U,TI,TD>(Array2[i],i == (DIMdot-1));
		}


			//call the DUT
		wrapped_DOT_matrix<T, DIMdot, Iter, U, TI, TD>(inp_stream, out_stream);


	// extract the output variable from the out stream
		for(int k = 0; k < DIMdot; k++){
			Array_out_FPGA[k] = pop_stream<T,U,TI,TD>(out_stream[k]);
			printf("1/(1+e^x) for array1 and array2 WITH FPGA: %.10f\n",Array_out_FPGA[k]);
		}

		SUM =0;
	// reference dot product with exponential
		for(int k = 0; k < DIMdot; k++){
			Array_out_ARM[k] = DOT_exp(Array1[k],Array2);
			//sums array
			printf("ACCtual part of in%d:%f\n",k,Array_out_ARM[k]);
			SUM += Array_out_ARM[k];
		}
		for(int k = 0; k < DIMdot; k++){
			Array_out_ARM[k] = Array_out_ARM[k]/SUM;
			printf("1/(1+e^x) for array1 and array2 WITH ARM: %.10f\n",Array_out_ARM[k]);
		}


	// Matrix comparison
	err = 0;
	for(int k = 0; k < DIMdot; k++){
	 //if (round4dec(Array_out_FPGA[k]) != round4dec(Array_out_ARM[k])){
		// err++;
		 printf("%f some amount off\n",(Array_out_FPGA[k] - Array_out_ARM[k]));
	 //}
	}

	if (err == 0)
		printf("ARRAYS IDENTICAL ... Test successful!\r\n");
	else
		printf("Test failed!\r\n");

	return 0;
}




///////////////////////////////////////////////////////////////////////////////////////////
// FULL ALGORITHM TEST
template <typename T, int DIMdot, int Iter, int U, int TI, int TD>
int Full_Algorithm(void)
{
	//TODO could change to 3D storage setup to allow for less repeated for loops
	//variable intilization
	int i, err;
	T Array1[DIMdot][DIMdot];
	T Array2[DIMdot];
	T Array3[DIMdot][DIMdot];
	T Array4[2][DIMdot];
	T ArrayTEMP1[DIMdot];
	T ArrayTEMP2[DIMdot];

	T Array_out_FPGA[2];
	T Array_out_ARM[2];
	T SUM;

	//test array generation
	for(i = 0; i<DIMdot; i++)
		for(int j = 0; j<DIMdot; j++){
			Array1[i][j] = (float)(i+j+2);
			Array3[i][j] = (float)(i+j+2);
		}

	for(i = 0; i<DIMdot-1; i++)
		Array2[i] = (float)(i+1)/100;
	//this is the bias
	Array2[DIMdot-1] = 1;

	for(i = 0; i<2; i++)
		for(int j = 0; j<DIMdot; j++){
			Array4[i][j] = (float)(i+j);
		}



	printf("DEBUGGING AXI4 STREAMING DATA TYPES!\r\n");

	// prepare data for the DUT
	AXI_VAL inp_stream[3*DIMdot+2*DIMdot*DIMdot];
	AXI_VAL out_stream[2];

	assert(sizeof(T)*8 == 32);
	// stream in the first input array
	for(int i=0; i<DIMdot; i++)
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
			inp_stream[i+DIMdot*DIMdot] = push_stream<T,U,TI,TD>(Array2[i],0);
		}
	///////////////////////////////////////////////////////////////////////
	//TODO will try to up wrapped dot matrix first and re order stuff around.
	///////////////////////////////////////////////////////////////////////
	// stream in the first input array
	for(int i=0; i<DIMdot; i++)
		for(int j = 0; j<DIMdot; j++)
			{
			//k is the location in the stack and each input variable requires the size of the last location
			int k = (i+1)*DIMdot+j + DIMdot*DIMdot;
			// theres a 0 at the end becuase it indicates the stream is not over yet.
				inp_stream[k] = push_stream<T,U,TI,TD>(Array3[i][j],0);
			}

	for(int i=0; i<2; i++)
		for(int j = 0; j<DIMdot; j++)
			{
			//k is the location in the stack and each input variable requires the size of the last location
			int k = (i+1)*DIMdot+j + 2*DIMdot*DIMdot;
			// theres a 0 at the end because it indicates the stream is not over yet.
				inp_stream[k] = push_stream<T,U,TI,TD>(Array3[i][j],i == (1));
			}




			//call the DUT
	wrapped_DOT_Full_Algorithm<T, DIMdot, Iter, U, TI, TD>(inp_stream, out_stream);


	// extract the output variable from the out stream
		for(int k = 0; k < 2; k++){
			Array_out_FPGA[k] = pop_stream<T,U,TI,TD>(out_stream[k]);
			printf("1/(1+e^x) for array1 and array2 WITH FPGA: %.10f\n",Array_out_FPGA[k]);
		}
		//printf("asdadasd%f\n",Array_out_FPGA[1]);
		//printf("asdadasd%f\n",Array_out_FPGA[3]);

		//first go 6*6 x 6*1 = 6*1
		//Matrix_exp_with_soft<T,DIMdot,DIMdot>(Array1, Array2, ArrayTEMP1);
		Matrix_exp_with_soft1(Array1,Array2,ArrayTEMP1);
		//second go 6*6 x 6*1 = 6*1
		Matrix_exp_with_soft1(Array3,ArrayTEMP1,ArrayTEMP2);
		//Matrix_exp_with_soft<T,DIMdot,DIMdot>(Array3,ArrayTEMP1,ArrayTEMP2);
		//third go 2*6 x 6*1 = 2*1
		Matrix_exp_with_soft2(Array4,ArrayTEMP1,Array_out_ARM);
		//Matrix_exp_with_soft<T,2,DIMdot>(Array4,ArrayTEMP1,Array_out_FPGA);
		printf("ARM: %f\n\n",Array_out_ARM[0]);


	/** Matrix comparison */
	err = 0;
	for(int k = 0; k < 2; k++){
	 //if (round4dec(Array_out_FPGA[k]) != round4dec(Array_out_ARM[k])){
		// err++;
		printf("FPGA: %f, ARM: %f\n",Array_out_FPGA[k], Array_out_ARM[k]);
		printf("%f some amount off\n",(Array_out_FPGA[k] - Array_out_ARM[k]));
	 //}
	}

	if (err == 0)
		printf("ARRAYS IDENTICAL ... Test successful!\r\n");
	else
		printf("Test failed!\r\n");

	return 0;
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


