#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "check.h"
#include "input.h"
#include "data_select.h"
#include "func3.h"


int main(){
    float resistance[100] = {};
    int cnt = preparation(resistance);
    int res_of_data_select = data_select(cnt, resistance);

    float resistance_final = result(res_of_data_select, resistance);

    int res_of_check = check(res_of_data_select, resistance, resistance_final);
    return 0;
}
