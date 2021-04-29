#include "filter.h"

filter::filter(double* coeff, int size, double* input, int i_size) {
	Coeff = coeff;
    Input = input;
	C_Size = size;
    I_Size = i_size;
}

std::vector<double> filter::output() { //i'm not sure what's supposed to happen with an inputted value
    std::vector<double> result;
    if (C_Size > I_Size) {return result;}
    for (int i = 0; i < I_Size; i++) {
        double output = 0;
        for (int j = 0; j < C_Size; j++) {
            if (i - j >= 0) {
                output += Input[i - j] * Coeff[j];
            }
        }
        result.push_back(output);
    }
    return result;
}
