/*getbits: gets n bits from the poistion p */

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	    return (x & ~(~(~0U << n) << (p - n + 1))) | ((y & ~(~0U << n)) << (p - n + 1));
}
//Basic Exp: First abomination creates a pocket of 0s starting from p to p-(n-1) then the second abomination moves the last part of y till nth digit and places it there

