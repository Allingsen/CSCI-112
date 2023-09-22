#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    int sign;
    double mantissa;
    int exponent;
} float_pt_t;

void scan_float_pt_t(float_pt_t *x) {
    char pos;
    
    //Gets the inputted numbers and coverts them into a float
    scanf(" %c,%lf,%d", &pos, &x->mantissa, &x->exponent);

    //Changes the + or - sign into a binary digit
    if (pos == '+') {
        x->sign = 0;
    }
    else{
        x->sign = 1;
    }
}

double float_pt_t_to_double(float_pt_t x) {
    double power;
    double floating;
    double return_val;

    //Converts the exponent into 10 to the power of n
    power = pow(10, x.exponent);

    //Makes the float a true floating number
    floating = x.mantissa * power;

    //Changes the sign
    if (x.sign == 1) {
        return_val = -floating;
    }
    else {
        return_val = floating;
    }

    return return_val;
}

void print_float_pt_t(float_pt_t x) {

    //Prints the number depending on if its positive or negative
    if (x.sign == 1) {
        printf("-%lfx10^%d", x.mantissa, x.exponent);
    }
    else {
        printf("%lfx10^%d", x.mantissa, x.exponent);
    }
}

float_pt_t add(float_pt_t a, float_pt_t b) {
    float_pt_t return_val;
    double true_a;
    double true_b;
    int difference;
    double total;
    double pikachu;

    //Checks if a and b are negative
    if (a.sign == 1) {
        true_a = -a.mantissa;
    }
    else {
        true_a = a.mantissa;
    }
    if (b.sign ==1) {
        true_b = -b.mantissa;
    }
    else {
        true_b = b.mantissa;  
    }

    //Converts the lower number to have the same exponent as the higher
    difference = a.exponent - b.exponent;
    total = (true_a * pow(10, a.exponent)) + (true_b * pow(10, b.exponent));

    if (difference >= 0) {
        pikachu=total/pow(10,a.exponent);
        if (fabs(pikachu) > .1 && fabs(pikachu) < 1) {
            return_val.mantissa = pikachu;
            return_val.exponent= a.exponent;
        }
        else {
            return_val.mantissa = pikachu/10;
            return_val.exponent = a.exponent+1;
        }
        if (total >= 0) {
            return_val.sign = 0;
        }
        else {
            return_val.sign = 1;
        }

    }
     else {
        pikachu =total/pow(10,b.exponent);
        if (fabs(pikachu) > .1 && fabs(pikachu) < 1) {
            return_val.mantissa = pikachu;
            return_val.exponent= b.exponent;
        }
        else {
            return_val.mantissa = pikachu/10;
            return_val.exponent = b.exponent+1;
        }
        if (total >= 0) {
            return_val.sign = 0;
        }
        else {
            return_val.sign = 1;
        }
    }
    

    return return_val;
}

