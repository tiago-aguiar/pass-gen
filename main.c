#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random()
{
    time_t t = time(NULL);
    srand(t);
}

int main(void)
{
    init_random();
    /* printf("Hello world %d\n", rand() % 10); */

    int numbers_max = 10;
    int letter_max = 26;

    int numbers_start = 48;
    int upper_start = 65;
    int lower_start = 97;

    char special[] = "!#$@_-*";

    /*
    for (int i = numbers_start; i < numbers_start + numbers_max; i++) {
        printf("%c", i);
    }
    printf("\n");
    for (int i = upper_start; i < upper_start + letter_max; i++) {
        printf("%c", i);
    }
    printf("\n");
    for (int i = lower_start; i < lower_start + letter_max; i++) {
        printf("%c", i);
    } 
    printf("\n");
    for (int i = 0; i < sizeof(special) - 1; i++) {
        printf("%c", special[i]);
    }
    */
    printf("\n");

    int length = 12;
    int len_group = length / 4;

    char buf[length + 1] = {};
    for (int i = 0; i < len_group; i++) {
        buf[i] = numbers_start + (rand() % numbers_max);
    }
    for (int i = len_group; i < len_group*2; i++) {
        buf[i] = upper_start + (rand() % letter_max);
    }
    for (int i = len_group*2; i < len_group*3; i++) {
        buf[i] = lower_start + (rand() % letter_max);
    }
    for (int i = len_group*3; i < len_group*4; i++) {
        int index = rand() % (sizeof(special) - 1);
        buf[i] = special[index];
    }
    puts(buf);

    for (int i = length - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        char current_char = buf[i];
        char random_char  = buf[j];

        buf[i] = random_char;
        buf[j] = current_char;
    }
    puts(buf);
    
    FILE *command = popen("pbcopy", "w");
    if (!command) {
        pclose(command);
        return 1;
    }
    fputs(buf, command);
    pclose(command);

    // TODO: free-bias random index

    return 0;
}
