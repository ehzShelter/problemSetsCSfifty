#include <cs50.h>
#include <math.h>
#include <stdio.h>

// #define CENTS_PER_DOLLAR 100
// #define QUARTER 25
// #define DIME 10
// #define NICKEL 5
// #define PENNY 1

enum money {
    CENTS_PER_DOLLAR = 100, QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1
};

int main(void)
{
    float dollars;

    do
    {
        printf("O hai! How much change is owed? \n");
        dollars = GetFloat();
    }
    while (dollars < 0);

    int cents = round(dollars * CENTS_PER_DOLLAR);

    int coins = 0;

    while (cents >= QUARTER)
    {
        coins++;
        cents -= QUARTER;
    }

    while (cents >= DIME)
    {
        coins++;
        cents -= DIME;
    }

    while (cents >= NICKEL)
    {
        coins++;
        cents -= NICKEL;
    }

    while (cents >= PENNY)
    {
        coins++;
        cents -= PENNY;
    }

    printf("%d\n",coins);
}
