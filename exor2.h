#pragma once

#include "systemc.h"
#include "nand2.h"

// TODO: implement EXOR module here using only nand2 components
// inputs: bool A, B
// output bool F

SC_MODULE(exor2)
{
	sc_in <bool> A, B;
	sc_out <bool> F;


	void do_exor2()
	{
	}

	SC_CTOR()
	{
		nand2 n1("n1"),
			  n2("n2"),
			  n3("n3"),
			  n4("n4");

		sc_signal <bool> n1n2n3_sig, n2n4_sig, n3n4_sig;
		
		n1.A(A);
		n1.B(B);
		n1.F(n1n2n3_sig);

		n2.A(A);
		n2.B(n1n2n3_sig);
		n2.F(n2n4_sig);

		n3.A(n1n2n3_sig);
		n3.B(B);
		n3.F(n3n4_sig);

		n4.A(n2n4_sig);
		n4.B(n3n4_sig);
		n4.F(F);

		//SC_METHOD(do_exor2);
		//sensitive << A << B;
	}
};

