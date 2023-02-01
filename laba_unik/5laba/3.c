#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// double F3(double x)
// {
//     double F = 2 * pow(x, 2);
//     return F;   
// }

double F2(double x)
{
    double F = (cos(5 * x));
    return F;   
}

double F1(double x)
{
    double F = (1 / sqrt(5 - pow(x, 3)));
    return F;
}

double Integral(int a, int b, double (*F)(double))
{
    double N = 15;
    double x_values[16];
    double pointer = a;
    double step = (b - a) / N;
    double f_from_x_values[16];
    for (int i = 0; i <= N; i++)
    {
        x_values[i] = pointer;
        pointer += step;
    }
    for (int k = 0; k <= N; k++)
    {
        f_from_x_values[k] = F(x_values[k]);
    }
    // for (int j = 0; j < N; j++)
    // {
    //     printf("%g ", f_from_x_values[j]);
    // }
    double multiplier1, multiplier2 = 0, multiplier2_1[3] = {3, 3, 2}, summand;
    int multiplier2_1_index = -1;
    multiplier1 = (3 * (b - a)) / (8 * N);
    for (int m = 0; m <= N; m++)
    {
        if (m == 0 || m == (N - 1)) {
            summand = f_from_x_values[m];
            // printf("%f ", summand);
            multiplier2 += summand;
            // printf("%f ", multiplier2);
            // printf("1 ");
        } else {
            multiplier2_1_index++;
            summand = multiplier2_1[multiplier2_1_index] * f_from_x_values[m];
            multiplier2 += summand;
            // printf("%f ", summand);
            // printf("%f ", multiplier2);
            // printf("%f      ", multiplier2_1[multiplier2_1_index]);
            if (multiplier2_1_index == 2) {
                multiplier2_1_index = -1;
            }
        }
    }
    double integral = multiplier1 * multiplier2;
    printf("%f\n", integral);
}

void main(void)
{   
    // double result = Integral(0, 100, F1, 1);
    // printf("\n%f", result);
    Integral(-2, 1, F1);
    Integral(-2, 3, F2);
    // Integral(1, 2, F3);
}