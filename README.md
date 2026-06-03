# C23-Monte_Carlo_Dice_Simulation
A Simple program that solves the Monte Carlo for a number of user-selected dice, where the number of trials is one billion.

## compiling with GCC
gcc -std=c23 -o monte_carlo_dice monte_carlo_dice.c

##using the program
./monte_carlo_dice.exe [dice1faces] [dice2faces] ...

## example
./monte_carlo_dice.exe 6 6 6 6

## output
- shows faces per die
- calculates theoretical mean
- runs 1 billion Monte Carlo iterations
- outputs simulated mean

## notes and things I've ran into while making this

-- notes --
- uses XOR shift for RNG performance within the dice loop
 
-- things I've ran into --
- when using rand() in the innermost loop, it made the program 7x slower, hence why it is not there
- ran into an overflow when the sum was 32 bits, so _BitInt(128) was used to guarantee no overflow within reason
- the XOR shift was added to the innermost loop to add a little more randomness without sacrificing much performance
- it initially had a fixed array, but now it has a VLA that is initialized and obtains values from argc and argv

## potential future updates
- the ability to choose number of trials N
- calucate the standard deviation sigma for the Monte Carlo
