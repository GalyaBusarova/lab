#include <stdio.h>
#include <math.h>

#include "check.h"

int check(int k, float resistance[],float resistance_final){

    float sum2 = 0.0f;
    
    for(int i = 0 ;i < k; i++){
        sum2 = sum2 + resistance[i] - resistance_final / 1000.0f;
    }

    float result = sum2/(float)k;
    printf("среднее отклонение: %.12f\n", result * 1000.0f);

    const float ACCURACY = 1e-8f;


    if (fabs(result) < ACCURACY){
        return 1;
    }
    return 0;


}
