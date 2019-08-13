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