
/**
 * @file functions.h
 * @brief C library containing the functions used by the program.
 */
#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

void making_change (int *coins_value, int *coins_uses, int no_coins, int sum, int *sum_reached);
void print_coins(int *coins_uses, int sum);

#endif // MAIN_FUNCTIONS_H


