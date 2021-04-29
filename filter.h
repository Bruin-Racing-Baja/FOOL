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







#endif // !FILTER_H