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

    int ldigits, udigits, ndigits;
    int dfactor, dquotient;

    int i;
    int rootndigits;

    int32_t dechalf;

    while (fscanf(input, "%li-%li,", &lower, &upper) != EOF){

        printf("lower is: %li. Upper is %li.\n", lower, upper);

        int ldigits = log10(lower) + 1;
        int udigits = log10(upper) + 1;

        printf("lower digits: %i\n", ldigits);
        printf("upper digits: %i\n", udigits);

        // make sure all numbers of different lengths of digits are calculated within range
        for (ndigits = ldigits; ndigits <= udigits; ndigits++){

            // loop over the multiple factor constructs for numbers of a certain length
            for (dfactor=1; dfactor <=ndigits/2; dfactor++){
                if (ndigits % dfactor == 0){
                    dquotient = ndigits / dfactor;
                    printf("factor: %i, quotient: %i\n", dfactor, dquotient);

                    tryroot = pow(10,dfactor-1);
                    //printf("first tryroot is: %li\n", tryroot);

                    while (floor(log10(tryroot)) + 1 <= dfactor){
                        //printf("tryroot = %li\n", tryroot);
                        // form the test candidate
                        tryfull = tryroot;
                        for (i=1; i<dquotient; i++) {
                            tryfull = tryfull * pow(10, dfactor) + tryroot;
                        }
                        //printf("tryfull = %li\n", tryfull);
                        // if its in range, add to sum
                        if (tryfull >= lower && tryfull <= upper){
                            // ADD CONDITION HERE. IF root is a repeat of 2 little number then dont count (again).
                            printf("success! %li\n", tryfull);
                            sum += tryfull;
                        }
                        // increment the root
                        if (tryfull > upper){
                            break;
                        }
                        tryroot++;
                            //printf("tryroot = %li\n", tryroot);
                    }
                }
            }
        }


        printf("\n");
    }


    printf("Final score: %li.\n", sum);
    printf("closing file & finishing up \n");
    fclose(input);

    return 0;
}








/*

        for (factor=1; factor <= (ldigits+1)/2; factor++){
            if (ldigits % factor == 0){

                quotient = ndigits / factor;

                tryroot = lower / pow(10, quotient);
                rootndigits = log10(tryroot) + 1;

                for (i=0; i < quotient; i++) {
                    tryfull = tryroot * pow(10, rootndigits) + tryroot;
                }
                printf("first tryroot: %li\n", tryroot);
                printf("first tryfull: %li\n\n", tryfull);


                while (tryfull <= upper){

                    if (tryfull >= lower) {
                        printf("tryfull: %li\n", tryfull);
                        sum += tryfull;
                    }
                    tryroot++;
                    rootndigits = log10(tryroot) + 1;
                    
                    for (i=0; i < quotient; i++) {
                        tryfull = tryroot * pow(10, rootndigits) + tryroot;
                    }
                }
            }
        }

        printf("\n");
    }


    printf("Final score: %li.\n", sum);
    printf("closing file & finishing up \n");
    fclose(input);

    return 0;
}
    */