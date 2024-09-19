#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "data_select.h"

int data_select (int M, float resistance[])
{
    float resistance_help[100] = {};
    float sr_ar = 0;
    float amount_of_res = 0;

    int i = 0;
    for (i = 0; i < M; i++)
    {
        amount_of_res = amount_of_res + resistance[i];
        resistance_help[i] = resistance[i];
    }
    sr_ar = amount_of_res / (float)M;

    int not_broken_elem_quant = M;
    for (i = 0; i < M; i++)
    {
        if (fabs(resistance[i] - sr_ar) > (float)0.03 * sr_ar)
        {
            not_broken_elem_quant--;
            resistance_help[i] = 0;
        }
    }


    for (i = 0; i < M; i++)
    {
        if (resistance_help[i] != 0)
        {
            resistance[i] = resistance_help[i];
        }
    }

    for (i = not_broken_elem_quant; i < M; i++)
    {
        resistance[i] = 0;
    }

    for (int i = 0; i < not_broken_elem_quant; i++)
    {
        printf("%lf\n", resistance[i]);
    }

    return not_broken_elem_quant;
}

