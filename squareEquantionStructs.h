#ifndef SQUARE_EQUATION_STRUCTS_H
#define SQUARE_EQUATION_STRUCTS_H
/**
 * @brief Enumeration for the ammount of roots
 */
/**
 * @param ZERO - If there are no roots.
 * @param ONE - If there is only one root.
 * @param TWO - If there are two roots.
 * @param INF - If every x is root for the equation.
 */
typedef enum
{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    INF = 3
} RootsNumb;

/**
 * @struct Coefs
 * @brief Struct for equantion's coefs
 */
struct Coefs{
   double coef_a; /**< coef before x^2 */
   double coef_b; /**< coef before x */
   double coef_c; /**< free coef */
};


/**
 * @struct Roots
 * @brief Struct for equantion's roots
 */
struct Roots{
   double root_1; /**< first equantion's root */
   double root_2; /**< second equantion's root */
};
#endif
