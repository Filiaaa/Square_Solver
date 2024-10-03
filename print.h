#ifndef PRINT_H
#define PRINT_H

#include "squareEquantionStructs.h"
#include<stdio.h>
/**
 * @brief Function that prints roots
 */
/**
 * @param double root_1 - first root.
 * @param root_2 - second root.
 * @param RootsNumb roots_cnt - ammount of roots.
 */
void PrintRoots(Roots result_roots, RootsNumb roots_cnt);


/**
 * @brief Function that prints result into file
 */
/**
 * @param[in] struct Roots result_roots - program result.
 * @param RootsNumb roots_cnt - ammount of roots.
 * @param int expected_ammount_of_roots - ammount of roots in answer.
 * @param struct Roots input_roots - roots in answer.
 * @param[out] FILE* result_file - output file.
 */
void PrintRootsIntoFile(
    Roots result_roots,
    RootsNumb roots_cnt,
    int expected_ammount_of_roots,
    Roots input_roots,
    FILE* result_file);


void PrintCorrectionIntoFile(Roots input_roots, int error_situation, FILE* result_file);
#endif
