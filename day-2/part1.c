#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
    printf("starting...\n");

    printf("opening file...\n");
    FILE *input = fopen("./data/test.txt", "r");

    unsigned long lower;
    unsigned long upper;

    unsigned long sum;

    unsigned long tryroot;
    unsigned long tryfull;

    int32_t dechalf;

    while (fscanf(input, "%li-%li,", &lower, &upper) != EOF){

        printf("lower is: %li. Upper is %li.\n", lower, upper);

        int ndigits = log10(lower) + 1;

        //printf("digits: %i\n", ndigits);

        dechalf = ndigits + 1 / 2;

        tryroot = lower / pow(10, dechalf);

        //printf("tryroot: %li\n", tryroot);

        int rootndigits = log10(tryroot) + 1;        
        tryfull = tryroot * pow(10, rootndigits) + tryroot;

        while (tryfull <= upper){
            if (tryfull >= lower){
                //printf("tryfull: %li\n", tryfull);
                sum += tryfull;
            }
            tryroot++;
            rootndigits = log10(tryroot) + 1;        
            tryfull = tryroot * pow(10, rootndigits) + tryroot;
        }
        printf("\n");
    }


    printf("Final score: %li.\n", sum);
    printf("closing file & finishing up \n");
    fclose(input);

    return 0;
}