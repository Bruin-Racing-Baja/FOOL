#include "filter.h"
#include <iostream>

filter::filter(double* coeff, int size, double* input, int i_size) {
	Coeff = coeff;
    Input = input;
	Size = size;
    I_size = i_size;
}

double filter::output() { //i'm not sure what's supposed to happen with an inputted value
    if (Size != I_size) {return -1;}
    double result = 0;
    for (int i = 0; i < Size; i++){
        result += Coeff[i] * Input[i];
    }
    return result;
}
