#include <iostream>
#include <fstream>
#include <cmath>
#include "Probability_Functions.h"
using std::cout;
using std::endl;
using std::ifstream;


int Probability_Functions::dirac_delta(float x)
{
	if (x == 0)
		return 1;
	else
		return 0;
}

int Probability_Functions::unit_step(float x)
{
	if (x >= 0)
		return 1;
	else
		return 0;
}

int Probability_Functions::factorial(int num)
{
	int factorial = 1;
	for (int i = 1; i <= num; i++)
		factorial *= i;

	return factorial;
}



Bernoulli::Bernoulli()
{
}

Bernoulli::Bernoulli(int n, int p)
{
	sample_size = n;
	successrate = p;
}

Bernoulli::~Bernoulli() {}


float Bernoulli::regular_bernoulli(int x, int n, float p)
{
	int nCx = factorial(n) / (factorial(n - x) * factorial(x));
	return (nCx * pow(p, x) * pow(1-p, n-x)) ;
}

float Bernoulli::bernoulli_density(int x, int n, float p, int val) // Revise if possible
{
	float f_x;
	
	f_x = regular_bernoulli(x, n, p) * Probability_Functions::dirac_delta(val-x);

	return f_x;
}
															   // Bounds a & b   // If true == X >= a
float Bernoulli::bernoulli_distribution(int n, float p, float a, float b, bool negate)
{
	// Case : a and b are 0, calculate the probability for all values of x.
	// Case : b is 0, calculate probability less than a
	// Case : b is 0, but negate == true. Calculate probability greater than a.
	// Case : a and b are two non zero numbers, return probability.
	// Case : a and b are the same but not 0, return 0.

	float F_x = 0;
	int x = 0;
	a = floor(a);
	b = floor(b);
	if (a == 0 && b == 0)
	{
		for (int i = 0; i <= n; i++) { // values of F_x(x)
			for (; x <= n; x++) {// values in sigma  
				F_x += (regular_bernoulli(x, n, p) * Probability_Functions::unit_step(i - x));
			}
			x = 0;
			cout << "F_x(" << i << ") = " << F_x << endl;
		}
	}

	else if (b == 0) {
			if (negate == true)
				return 1 - F_x;
			else
				return F_x;
	}
	else if (b != 0)
	{

	}
	else
		return 0;

}


float Exponential::exp_density(float b_e)
{

	return 0.0f;
}

float Exponential::exp_distribution(float b_e)
{

	return 0.0f;
}

float Poisson::poisson_density(float t, float lambda)
{
	return 0.0f;
}

float Poisson::poisson_distribution(float t, float lambda)
{
	float b = t * lambda;
	return 0.0f;
}


float Uniform::uniform_density(float a, float b)
{
	return 1/(b-a);
}

