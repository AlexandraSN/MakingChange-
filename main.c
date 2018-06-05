/**
 * @file main.c
 * @brief Main file where all the functions are called from.
 *
 * @author Streata Nicoleta Alexandra
 *
 * Allows the user to select options based on what he wants from the program.
 */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
 /**
    * @fn int main()
    * @brief Main function that takes user input and generating output
    */
{ int choice;

    int *coins_value;
    int *coins_uses;
    int *sum_reached;
    int sum;
    int no_coins;
    int iterator;
    int iterator_sum;
    int iterator_coins;

    printf ("\n-----------------------------\n\n");
    printf ("\n--------MAKING CHANGE--------\n\n");
    printf ("\n-----------------------------\n\n");


    printf ("\n\nEnter the amount : ");
    scanf ("%d", &sum);

    if (sum < 1) {
        printf ("\nInvalid amount!\n");
        return 0;
    }

    printf ("\n\nEnter the number of coin types : ");
    scanf ("%d", &no_coins);

    if (no_coins < 1) {
        printf ("\nInvalid value!\n");
        return 0;
    }

    coins_value = malloc (no_coins * sizeof(int));

    sum_reached = malloc ((sum + 1) * sizeof(int));
    coins_uses = malloc ((sum + 1) * sizeof(int));

    memset (sum_reached, 0, (sum + 1) * sizeof(int));

    for (iterator = 0; iterator <= sum; iterator++) {
        coins_uses[iterator] = 999999;
    }

    printf ("\n\nEnter the distinct value of coins : \n");
    for (iterator = 0; iterator < no_coins; iterator++) {
        printf ("(%d) : ", iterator + 1);
        scanf ("%d", &coins_value[iterator]);
        if (coins_value[iterator] < 1) {
            printf ("\nInvalid value!\n");
            return 0;
        }
    }

    making_change (coins_value, coins_uses, no_coins, sum, sum_reached);
    print_coins(coins_uses, sum);
    return 0;
}
