#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[argc + 1])
{
    unsigned _BitInt(128) S = 0;
    double mean = 0;
    unsigned long long int N = 1e9;
    
    unsigned int dice_array[argc-1] = {};
    
    
    
    for(int i = 1; argv[i]; i++)
    {
        char *end;
        dice_array[i-1] = strtoul(argv[i],&end, 10);
        
        
        if (*end != '\0')
        {
        printf("Error: '%s' is not a number\n", argv[i]);
        return EXIT_FAILURE;
        }
        
        if(!dice_array[i-1])
        {
            printf("Error: Dice cannot have 0 faces\n");
            return EXIT_FAILURE;
        }
        
        if(argv[i][0] == '-')
        {
            printf("Error: Dice cannot have negative faces\n");
            return EXIT_FAILURE;
        }
    
    
        printf("The Number of faces on die %d is: %u\n", i, dice_array[i-1]);
    }
    
    unsigned int number_of_dice = argc-1;
    
    
    //solve for the theoretical mean
    unsigned _BitInt(128) S_theo = 0;
    double mean_theo = 0;
    
    for(int i = 0; i < number_of_dice; i++)
    {
        S_theo += dice_array[i] + 1;
    }
    mean_theo = (double)S_theo/2;
    
    printf("The theoretical mean is: %f\n", mean_theo);
    
    //initialize randomizer
    srand(time(nullptr));
    
    for(int i = 0; i < N; i++)
    {
        unsigned int rand_value = rand();
        for(int j = 0; j < number_of_dice; j++)
        {
            S += 1 + (rand_value % dice_array[j]);
            rand_value ^= rand_value << (dice_array[j] >= 32? 31 : dice_array[j]);
        }
    }
    
    mean = (double)S/(double)N;
    
    printf("The Monte Carlo mean value is: %f\n", mean);
    
    
    
    return EXIT_SUCCESS;
}
