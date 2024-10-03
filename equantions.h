#include "squareEquantionStructs.h"

/**
 * @brief Very small numb for comparison.
 */
const double very_small_double = 1e-8;
/**
 * @brief Function for finding descriminant.
 */
/**
 * @param double coef_a - coef before x^2.
 * @param double coef_b - coef before x.
 * @param double coef_b - free coef.
 * @return double - discriminant
 */
double FindDiscriminant(Coefs input_coefs);
/**
 * @brief Function that find roots.
 */
/**
 * @param double coef_a - coef before x².
 * @param double coef_b - coef before x.
 * @param double coef_b - free coef.
 * @param double* root1 - pointer to first root.
 * @param double* root2 - pointer to second root.
 * @return RootsNumb - ammount of roots
 */
RootsNumb FindRoots(Coefs input_coefs, Roots* result_roots);
/**
 * @brief Function that solves square equation
 */
/**
 * @param double coef_a - coef before x².
 * @param double coef_b - coef before x.
 * @param double coef_c - free coef.
 * @param double* root1 - pointer to first root.
 * @param double* root2 - pointer to second root.
 * @return RootsNumb - ammount of roots
 */
RootsNumb SolveSquareEquation(Coefs input_coefs, struct Roots* result_roots);
/**
 * @brief Function that solves linear equation
 */
/**
 * @param double coef_a - coef before x².
 * @param double coef_b - coef before x.
 * @param double coef_c - free coef.
 * @param double* root1 - pointer to first root.
 * @param double* root1 - pointer to second root.
 * @return RootsNumb - ammount of roots
 */
RootsNumb SolveLinearEquation(Coefs input_coefs, Roots* result_roots);
/**
 * @brief Function that solves equation of the form c = 0
 */
/**
 * @param double coef_c - free coef.
 * @param double* root1 - pointer to first root.
 * @return RootsNumb - ammount of roots
 */
RootsNumb SolveConstantCquation(Coefs input_coefs);



