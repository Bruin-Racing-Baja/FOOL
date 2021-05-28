#ifndef FILTER_H
#define FILTER_H
#include <vector>
#include <iostream>

class filter {
public:
	filter(double* coeff, int size, double* input, int i_size);
	std::vector<double> output(); //outputs a double of based on the filter coefficients and input data
private:
	double* Coeff;
    double* Input;
	int C_Size;
    int I_Size;

};

class lowpass_butterworth : public filter {
public:
	lowpass_butterworth(int order, int size, double cutoff_frequency, double* input, int i_size); //should set A_Coeff and B_Coeff
	virtual std::vector<double> output(); //based on formula y(n)  =  b0.x(n) + b1.x(n-1) + b2.x(n-2) +bi.x(n-i) + a1.y(n-1) + a2.y(n-2) + ai.y(n-i)
private:
	//double* A_Coeff;
	//double* B_Coeff;
	//double* Input;
	//int C_Size;
	//int I_Size;


}






#endif // !FILTER_H