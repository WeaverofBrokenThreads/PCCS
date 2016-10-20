#include "Literals.h"


int operator"" H(unsigned long long int integer)
{
	return integer * 100;
}

int operator"" K(unsigned long long int integer)
{
	return integer * 1'000;
}

int operator"" T(unsigned long long int integer)
{
	return integer * 10'000;
}

int operator"" X(unsigned long long int integer)
{
	return integer * 100'000;
}

int operator"" M(unsigned long long int integer)
{
	return integer * 1'000'000;
}
