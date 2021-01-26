#pragma once
#include <fstream>
using std::string;

class Probability_Functions
{
	// union 

public:
	// Dirac Delta and Unit Step Functions
	int dirac_delta(float x);
	int unit_step(float x);

	// Mathematical Functions
	int factorial(int num);

};


class Bernoulli : public Probability_Functions // public?
{
	private:
		int sample_size;   // n
		float successrate; // p
	public:
		Bernoulli();
		Bernoulli(int n, int p);
		~Bernoulli();
		float regular_bernoulli(int x, int n, float p);  // Calculates the probability of # of successes in a sample size.
		float bernoulli_density(int x, int n, float p, int val);  // Calculates bernoulli probability using dirac delta method.
		float bernoulli_distribution(int n, float p, float a, float b, bool negate); // Can take in a range, but if 'a' is only present, percentile less than 'a' is calculated.
																	// Note: If negate == true, function calculates F_x(X > a)/at least 'a'.
};

class Conditional : public Probability_Functions // public?
{
	private:
	public:

};

class Exponential : public Probability_Functions // public?
{
	private:

	public:
		float exp_density(float b_e);
		float exp_distribution(float b_e);
};

class Poisson : public Probability_Functions // public?
{
	private:

	public:
		float poisson_density(float t, float lambda);
		float poisson_distribution(float t, float lambda);

};

class Uniform : public Probability_Functions // public?
{
	private:
	public:
		float uniform_density(float a, float b);
		// float uniform_distribution
};