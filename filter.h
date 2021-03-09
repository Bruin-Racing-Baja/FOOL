#ifndef FILTER_H
#define FILTER_H
#include <vector>

class filter {
public:
	filter(double* coeff, int size, double* input, int i_size);
	double output(); //outputs a vector of based on the filter coefficients and input data
private:
	double* Coeff;
    double* Input;
	int Size;
    int I_size;

};







#endif // !FILTER_H