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

int main() {
    double coeff[4] = {1,2.51,3,4}; //some tests
    double input[4] = {1.2,2,3.6,4};
    filter tommy(coeff, 4, input, 4);
    filter tommy1(coeff, 4, input, 3);
    std::cout << tommy.output() << std::endl;
    std::cout << tommy1.output() << std::endl;
}