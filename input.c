#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int preparation(float resistance[]){
    FILE *file_pointer = fopen("input.txt", "r");
    char buffer[50] = {};
    int cnt_of_researchers = 0;
    while (fgets(buffer, 50, file_pointer) != NULL)
    {
        float v = 0.0f;
        float i = 0.0f;
        int j = 0;
        char volt[30] = {};
        char amper[30] = {};
        for (; buffer[j] != '/'; j++){
            volt[j] = buffer[j];
        }
        j++;
        int k = 0;
        for (; buffer[j] != '\0'; j++, k++){
            amper[k] = buffer[j];
        }
        v = strtof(volt, NULL);
        i = strtof(amper, NULL);
        resistance[cnt_of_researchers] = v / i;
        cnt_of_researchers++;
    }


    return cnt_of_researchers;
}

