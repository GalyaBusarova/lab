#include <stdio.h>
#include <math.h>
#include "func3.h"

float squareRoot(float a) {

    float i = 0;
    float j = a / 2;

    while (j != i)
    {
        i = j;
        j = (a / i + i) / 2;
    }
    return j;

}


float result(int K, float *resistance)
{

    float amount_resistances = 0.0f;
    float amount_resistances2 = 0.0f;

    for (int i = 0; i < K; i++)
    {
        amount_resistances = amount_resistances + resistance[i] * 1000;
        amount_resistances2 = amount_resistances2 + resistance[i];
    }


    float resistance_final = amount_resistances/ (float)K;
    float resistance_final2 = amount_resistances2 / (float)K;

    float amount_square_diff = 0.0f;



    for (int i = 0; i < K; i++)
    {
        amount_square_diff = amount_square_diff + (resistance[i] - resistance_final2) * (resistance[i] - resistance_final2);
    }

    float deviation = (squareRoot(amount_square_diff * 1000)) / (float)K;

    printf("%f+-%f  (cопротивление +- среднеквадратичное отклонение)\n", resistance_final, deviation);


    return resistance_final;
}
