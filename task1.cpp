#include <TXLib.h>
#include<stdio.h>
#include <assert.h>
#include <math.h>
/**
 * @brief Very small numb for comparison.
 */
const double very_small_double = 1e-8;


//Какие есть случаи:
//1) оно квадратное
//    1.1) один корень +
//    1.2) два корня +
//    1.3) нет корней +
//2) оно выраждается в линейное +
//3) оно выраждается в константа = 0
//    3.1) константа = 0 => каждый x подходит
//    3.2) константа != 0 => нет решений

/**
 * @mainpage Square_Solver
 *
 * @section Introduction
 *
 * This program prints roots of the equantion if they exist.
 */

/**
 * @brief Enumeration for the ammount of roots
 */
/**
 * @param ZERO - If there are no roots.
 * @param ONE - If there is only one root.
 * @param TWO - If there are two roots.
 * @param INF - If every x is root for the equation.
 */
enum RootsNumb : int

{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    INF = 3
};

/**
 * @brief Function for finding descriminant.
 */
/**
 * @param double coef_a - coef before x².
 * @param double coef_b - coef before x.
 * @param double coef_b - free coef.
 * @return double - discriminant
 */
double Find_discriminant(double coef_a, double coef_b, double coef_c);
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
RootsNumb Find_roots(double coef_a, double coef_b, double coef_c, double* root_1, double* root_2);
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
RootsNumb Solve_square_equation(double coef_a, double coef_b, double coef_c, double* root_1, double* root_2);
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
RootsNumb Solve_linear_equation(double coef_b, double coef_c, double* root_1);
/**
 * @brief Function that solves equation of the form c = 0
 */
/**
 * @param double coef_c - free coef.
 * @param double* root1 - pointer to first root.
 * @return RootsNumb - ammount of roots
 */
RootsNumb Solve_constant_equation(double coef_c);
/**
 * @brief Function that prints roots
 */
/**
 * @param double root_1 - first root.
 * @param root_2 - second root.
 * @param RootsNumb roots_cnt - ammount of roots.
 */
void PrintRoots(double root_1, double root_2, RootsNumb roots_cnt);
/**
 * @brief Function that scans input
 */
/**
 * @param double* coef_a pointer to coef_a(coef before x²).
 * @param double* coef_b pointer to coef_b(coef before x).
 * @param double* coef_c pointer to coef_c(free coef).
 */
void ScanInp(double* coef_a, double* coef_b, double* coef_c);


void ScanInp(double* coef_a, double* coef_b, double* coef_c)
{
    int inp = 0;

    while(scanf("%lg%lg%lg", coef_a, coef_b, coef_c) != 3 && (inp = getchar()) != -1)
    {
        printf("Bro, you introduced bullshit. Try again\n");
        while(inp != '\n')
        {
            inp = getchar();
        }
    }
}

void PrintRoots(double root_1, double root_2, RootsNumb roots_cnt)
{
    switch(roots_cnt)
    {
        case ZERO:
            printf("Your equation has no roots");
            break;
        case ONE:
            printf("Your equation has a single root x = %lg", root_1);
            break;
        case TWO:
            printf("Your equation has two roots x1 = %lg, x2 = %lg", root_1, root_2);
            break;
        case INF:
            printf("Your equation has an infinite number of roots");
            break;
        default:
            break;
    }
}


void PrintRootsIntoFile(double root_1, double root_2, RootsNumb roots_cnt, int expected_ammount_of_roots, double expected_root1,
 double expected_root2, FILE* result_file)
{

    switch(roots_cnt)
    {
        case ZERO:
            fprintf(result_file, "no roots - ");
            if(expected_ammount_of_roots == 0)
            {
                fprintf(result_file, "correct\n");
            }
            else
            {
                fprintf(result_file, "not correct, equantion has no rules\n");
            }
            break;
        case ONE:
            fprintf(result_file, "x1 = %lg - ", root_1);
            if(expected_ammount_of_roots == 1 && root_1 == expected_root1)
            {
                fprintf(result_file, "correct\n");
            }
            else
            {
                fprintf(result_file, "not correct, expected root = %lg\n", expected_root1);
            }
            break;
        case TWO:
            fprintf(result_file, "x1 = %lg x2 = %lg - " , root_1, root_2);
            if(expected_ammount_of_roots == 2 && (root_1 == expected_root1 && root_2 == expected_root2)
            || (root_1 == expected_root2 && root_2 == expected_root1))
            {
                fprintf(result_file, "correct\n");
            }
            else
            {
                fprintf(result_file, "not correct, expected first root = %lg expected first root = %lg\n", expected_root1, expected_root2);
            }
            break;
        case INF:
            fprintf(result_file, "every x - ");
            if(expected_ammount_of_roots == 3)
            {
                fprintf(result_file, "correct\n");
            }
            else
            {
                fprintf(result_file, "not correct, every x is root\n");
            }
            break;
        default:
            break;
    }
}

int ScanFile(double* coef_a, double* coef_b, double* coef_c, int* expected_ammount_of_roots, double* expected_root1, double* expected_root2,  FILE* file, FILE* result_file)
{
    int inp = 0;
    if(fscanf(file, "%lg%lg%lg%d%lg%lg", coef_a, coef_b, coef_c, expected_ammount_of_roots, expected_root1, expected_root2) == 6)
    {
        fprintf(result_file, "%lg %lg %lg ", *coef_a, *coef_b, *coef_c);
        return 1;
    }
    else
    {
        return 0;
    }
}

void WorkWithFile()
{

    FILE* file = fopen("TestS.txt", "rb");
    FILE* result_file = fopen("TestsResult.txt", "w");
    int fd = _fileno(result_file);
    _chsize(fd, 0);
    if (file == NULL)
    {
        fprintf(result_file, "FileReadError");
    }
    //file = ("Test.txt", "rb");


    double coef_a = NAN;
    double coef_b = NAN;
    double coef_c = NAN;
    int expected_ammount_of_roots = NAN;
    double expected_root1 = NAN;
    double expected_root2 = NAN;


    while(ScanFile(&coef_a, &coef_b, &coef_c, &expected_ammount_of_roots,&expected_root1, &expected_root2, file, result_file))
    {
        //ScanFile(&coef_a, &coef_b, &coef_c, &expected_ammount_of_roots,&expected_root1, &expected_root2, file, result_file);
        //ScanInp(&coef_a, &coef_b, &coef_c);

        double root_1 = 0;
        double root_2 = 0;

        RootsNumb roots_cnt = Find_roots(coef_a, coef_b, coef_c, &root_1, &root_2);
        PrintRootsIntoFile(root_1, root_2, roots_cnt, expected_ammount_of_roots, expected_root1, expected_root2, result_file);
    }

    fclose(file);

}


double Find_discriminant(double coef_a, double coef_b, double coef_c)
{
    double discriminant = coef_b*coef_b - 4*coef_a*coef_c;

    return discriminant;
}

RootsNumb Solve_square_equation(double coef_a, double coef_b, double coef_c, double* root_1, double* root_2)
{
    double discriminant = Find_discriminant(coef_a, coef_b, coef_c);

    if(discriminant < -very_small_double)
    {
        *root_1 = -1;

        return ZERO;
    }

    if(-very_small_double <= discriminant && discriminant <= very_small_double)
    {
        *root_1 = -coef_b / (2 * coef_a);

        return ONE;
    }

    if(discriminant > very_small_double)
    {
        double sqrt_discriminant = sqrt(discriminant);

        *root_1 = (-coef_b + sqrt_discriminant) / (2 * coef_a);
        *root_2 = (-coef_b - sqrt_discriminant) / (2 * coef_a);

        return TWO;
    }
}

RootsNumb Solve_linear_equation(double coef_b, double coef_c, double* root)
{
    if(coef_c == 0)
    {
        *root = 0;
        return ONE;
    }

    *root = -coef_c / coef_b;

    return ONE;
}

RootsNumb Solve_constant_equation(double coef_c)
{
    return (coef_c == 0 ? INF : ZERO);
}

RootsNumb Find_roots(double coef_a, double coef_b, double coef_c, double* root_1, double* root_2)
{
    if(coef_a == 0 && coef_b == 0)
    {
        return Solve_constant_equation(coef_c);
    }

    if(coef_a == 0)
    {
        return Solve_linear_equation(coef_b, coef_c, root_1);

    }

    return Solve_square_equation(coef_a, coef_b, coef_c, root_1, root_2);
}


// TODO: add docs (doxygen) +
// TODO: add unit test
// TODO: read argc, argv arg_parse : task.exe -i stdin -o output.txt -t
// TODO: function pointer (callback)
//обработку ввода в функцию обвернуть




 /** Main function.
 *  This function is responsible for dialogue with the user and outputting a solution.
 */
int main()
{
    WorkWithFile();

//    printf("This program finds solutions to a quadratic equation of the form ax^2 + bx + c = 0\n");
//    printf("Enter coefficients a, b, c separated by spaces\n");
//
//    double coef_a = NAN;
//    double coef_b = NAN;
//    double coef_c = NAN;
//
//
//
//
//
//    ScanInp(&coef_a, &coef_b, &coef_c);
//
//    double root_1 = 0;
//    double root_2 = 0;
//
//    RootsNumb roots_cnt = Find_roots(coef_a, coef_b, coef_c, &root_1, &root_2);
//    PrintRoots(root_1, root_2, roots_cnt);



    return 0;
}

