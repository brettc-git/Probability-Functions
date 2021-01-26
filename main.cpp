#include <iostream>
#include "Probability_Functions.h"
using std::cout;
using std::endl;



int main()
{
	Bernoulli b;
	int successfultests, totaltests;

	cout << "Bernoulli Trials Test 1: A 12 sided die." << endl;
	cout << "n = 12 (Sample Size)" << endl;
	cout << "p = 1/12 (Success Probability)" << endl;
	
	cout << "\n";
	cout << "Calculating with regular Bernoulli Equation: " << endl;
	for (int i = 0; i <= 12; i++)
	{
		cout << "f_x(" << i << ") = " << b.regular_bernoulli(i, 12, 0.083333f) << endl;
	}

	cout << "\n";

	cout << "Verifying with Dirac Delta Calculation Method: " << endl;
	for (int i = 0; i <= 12; i++)
	{
		cout << "f_x(" << i << ") = " << b.bernoulli_density(i, 12, 0.083333f, i) << endl;
	}

	cout << "\n";

	b.bernoulli_distribution(12, 0.083333f, 0.0f, 0.0f, false);


	cout << "\n";
	cout << "Bernoulli Trials Test 2: A Three Color Roulette Wheel." << endl;
	cout << "\n";
	cout << "n = 10 (Sample Size for Red Sections)" << endl;
	cout << "p = 1/2 (Success Probability)" << endl;

	for (int i = 0; i <= 10; i++)
	{
		cout << "f_x(" << i << ") = " << b.regular_bernoulli(i, 10, 0.5f) << endl;
	}

	for (int i = 0; i <= 10; i++)
	{
		cout << "f_x(" << i << ") = " << b.bernoulli_density(i, 10, 0.5f, i) << endl;
	}


	cout << "\n";
	cout << "n = 8 (Sample Size for Blue Sections)" << endl;
	cout << "p = 2/5 (Success Probability)" << endl;
	cout << "\n";
	cout << "n = 2 (Sample Size for Yellow Sections)" << endl;
	cout << "p = 1/10 (Success Probability)" << endl;



	/*cout << successfultests << " out of " << totaltests << "tests passed" << endl;*/

	
	return 0;
}

// References
// https://www.ztable.net/