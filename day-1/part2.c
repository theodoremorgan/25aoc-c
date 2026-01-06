
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    printf("starting...\n");

    printf("opening file...\n");
    FILE *input = fopen("./data/input2.txt", "r");

    int32_t position = 50;
    uint32_t count = 0;

    char direction;
    int32_t turns;
    int32_t fullies;

    while (fscanf(input, "%c%i\n", &direction, &turns) != EOF){

        printf("position at start %i\n", position);

        fullies = turns/100;

        // left is the 'negative' direction (interpreting left as anticlockwise turn of dial).
        if (direction == 'L'){
            turns = turns * -1;
        }

        printf("direction is: %c. turns are: %i.\n", direction, turns);
        printf("fullies: %i\n", fullies);

        count += fullies;

        turns = turns % 100;

        if ((direction == 'L' && position != 0) && turns + position < 0){
            count++;
        }

        if ((direction == 'R' && position != 0) && turns + position > 100){
            count++;
        }

        if ( (turns + position) % 100 == 0){
            count++;
        }

        // set new position (always positive at end of iteration)

        position += turns;
        position = position%100;

        if (position < 0){
            position = 100 + position;
        }

        printf("position at end: %i\n", position);
        printf("count: %i\n", count);

    }

    printf("closing file & finishing up \n");
    fclose(input);

    return 0;
}

