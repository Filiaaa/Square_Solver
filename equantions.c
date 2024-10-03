#include "equantions.h"
double FindDiscriminant(Coefs input_coefs)
{
    double coef_a = input_coefs.coef_a;
    double coef_b = input_coefs.coef_b;
    double coef_c = input_coefs.coef_c;

    double discriminant = coef_b* coef_b - 4* coef_a * coef_c;

    return discriminant;
}

RootsNumb SolveSquareEquation(Coefs input_coefs, Roots* result_roots)
{
    double discriminant = FindDiscriminant(input_coefs);
    double coef_a = input_coefs.coef_a;
    double coef_b = input_coefs.coef_b;
    double coef_c = input_coefs.coef_c;

    if(discriminant < -very_small_double)
    {
        result_roots -> root_1 = -1;

        return ZERO;
    }

    if(-very_small_double <= discriminant && discriminant <= very_small_double)
    {
        result_roots -> root_1  = -coef_b / (2 * coef_a);

        return ONE;
    }

    if(discriminant > very_small_double)
    {
        double sqrt_discriminant = sqrt(discriminant);

        result_roots -> root_1 = (-coef_b + sqrt_discriminant) / (2 * coef_a);
        result_roots -> root_2 = (-coef_b - sqrt_discriminant) / (2 * coef_a);

        return TWO;
    }
}

RootsNumb SolveLinearEquation(Coefs input_coefs, Roots* result_roots)
{
    double coef_b = input_coefs.coef_b;
    double coef_c = input_coefs.coef_c;

    if(coef_c == 0)
    {
        result_roots -> root_1 = 0;
        return ONE;
    }

    result_roots -> root_1 = -coef_c / coef_b;

    return ONE;
}

RootsNumb SolveConstantEquation(Coefs input_coefs)
{
    double coef_c = input_coefs.coef_c;
    return (coef_c == 0 ? INF : ZERO);
}

RootsNumb FindRoots(Coefs input_coefs, Roots* result_roots)
{
    double coef_a = input_coefs.coef_a;
    double coef_b = input_coefs.coef_b;
    double coef_c = input_coefs.coef_c;

    if(coef_a == 0 && coef_b == 0)
    {
        return SolveConstantEquation(input_coefs);
    }

    if(coef_a == 0)
    {
        return SolveLinearEquation(input_coefs, result_roots);

    }

    return SolveSquareEquation(input_coefs, result_roots);
}
