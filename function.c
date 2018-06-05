
/**
 * @file functions.c
 * @brief C library containing the functions used for making change.
 * @author Streata Nicoleta Alexandra
 */
#include <stdio.h>
#include "functions.h"
;    int *coins_value;
    int *coins_uses;
    int *sum_reached;
    int sum;
    int no_coins;
    int iterator_sum;
    int iterator_coins;

void making_change (int *coins_value, int *coins_uses, int no_coins, int sum, int *sum_reached)
{
/**
    * @fn making_change (int *coins_value, int *coins_uses, int no_coins, int sum, int *sum_reached)
    * @brief Find the total number of used coins.
    * @param *coins_value The coin values vector given by the user.
    * @param *coins_uses The coin vector that gives the total number of uses of each coin.
    * @param no_coins The total number of coins given by the user.
    * @param sum The total amount given by user.
    * @param *sum_reached The vector of the amount that shows how much it has in the course of the operations.
    *
    * The function calculates how many coins are used to form the amount of money using a dynamic programming.
    */
    int nr_iterations = 0;
    int nr_max_iterations = sum + 1;
    int iterator_sum;
    int iterator_coins;

    coins_uses[0] = 0;
    sum_reached[0] = 1;

    while (sum_reached[sum] == 0 && nr_iterations++ < nr_max_iterations) {
        for (iterator_sum = sum; iterator_sum >= 0; iterator_sum--) {
            for (iterator_coins = 0; iterator_coins < no_coins; iterator_coins++) {
                if (sum_reached[iterator_sum] == 1 && iterator_sum + coins_value[iterator_coins] <= sum) {
                    sum_reached[iterator_sum + coins_value[iterator_coins]] = 1;

                    if (coins_uses[iterator_sum] + 1 < coins_uses[iterator_sum + coins_value[iterator_coins]]) {
                        coins_uses[iterator_sum + coins_value[iterator_coins]] = coins_uses[iterator_sum] + 1;
                    }
                }
            }
        }
    }

    if (sum_reached[sum] == 0) {
        printf("\nSum can't be reached!");
    }

}

void print_coins(int *coins_uses, int sum)
{
/**
     * @fn void print_coins(int *coins_value, int *coins_uses, int no_coins)
     * @brief Prints out the number of used coins.
     * @param *coins_uses The coin vector that gives the total number of uses of each coin.
     * @param sum The total amount given by user.
     *
     * The function prints out the value of the total used coins.
     *
     */

    printf ("\nTotal of coins : %d \n", coins_uses[sum]);

    printf ("\n\n------------------------\n\n");
}




