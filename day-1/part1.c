
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    printf("starting...\n");

    printf("opening file...\n");
    FILE *input = fopen("./data/input1.txt", "r");

    int32_t position = 50;
    uint32_t count = 0;

    char direction;
    int32_t turns;

    while (fscanf(input, "%c%i\n", &direction, &turns) != EOF){
        
        // left is the 'negative' direction (interpreting left as anticlockwise turn of dial).
        if (direction == 'L'){
            turns = turns * -1;
        }
        printf("direction is: %c. turns are: %i.\n", direction, turns);

        position += turns;

        position = position%100;

        if (position == 0){
            count++;
        }

        printf("position: %i\n", position);
        printf("count: %i\n", count);

    }

    printf("closing file & finishing up \n");
    fclose(input);

    return 0;
}

