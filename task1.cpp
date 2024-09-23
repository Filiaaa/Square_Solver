/**
 * @brief including header file.
 */
#include "header.cpp"


/**
 * @brief Very small numb for comparison.
 */
const double very_small_double = 1e-8;



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
 * @struct Coefs
 * @brief Struct for equantion's coefs
 */
struct Coefs {
   double coef_a; /**< coef before x^2 */
   double coef_b; /**< coef before x */
   double coef_c; /**< free coef */
};


/**
 * @struct Roots
 * @brief Struct for equantion's roots
 */
struct Roots {
   double root_1; /**< first equantion's root */
   double root_2; /**< second equantion's root */
};

/**
 * @brief Function for finding descriminant.
 */
/**
 * @param double coef_a - coef before x^2.
 * @param double coef_b - coef before x.
 * @param double coef_b - free coef.
 * @return double - discriminant
 */
double Find_discriminant(Coefs input_coefs);
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
RootsNumb Find_roots(Coefs input_coefs, Roots* result_roots);
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
RootsNumb Solve_square_equation(Coefs input_coefs, struct Roots* result_roots);
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
RootsNumb Solve_linear_equation(Coefs input_coefs, struct Roots* result_roots);
/**
 * @brief Function that solves equation of the form c = 0
 */
/**
 * @param double coef_c - free coef.
 * @param double* root1 - pointer to first root.
 * @return RootsNumb - ammount of roots
 */
RootsNumb Solve_constant_equation(Coefs input_coefs);
/**
 * @brief Function that prints roots
 */
/**
 * @param double root_1 - first root.
 * @param root_2 - second root.
 * @param RootsNumb roots_cnt - ammount of roots.
 */
void PrintRoots(struct Roots result_roots, RootsNumb roots_cnt);
/**
 * @brief Function that scans input
 */
/**
 * @param double* coef_a pointer to coef_a(coef before x²).
 * @param double* coef_b pointer to coef_b(coef before x).
 * @param double* coef_c pointer to coef_c(free coef).
 */
void ScanInp(struct Coefs* input_coefs);

/**
 * @brief Function that prints result into file
 */
/**
 * @param struct Roots result_roots - program result.
 * @param RootsNumb roots_cnt - ammount of roots.
 * @param int expected_ammount_of_roots - ammount of roots in answer.
 * @param struct Roots input_roots - roots in answer.
 * @param FILE* result_file - output file.
 */
void PrintRootsIntoFile(struct Roots result_roots, RootsNumb roots_cnt, int expected_ammount_of_roots,
 struct Roots input_roots, FILE* result_file);

 /**
 * @brief Function that scans input file
 */
/**
 * @param struct Coefs* input_coefs - coefs from input.
 * @param int* expected_ammount_of_roots - ammount of roots in answer.
 * @param struct Roots* input_roots - roots in answer.
 * @param FILE* file - input file.
 * @param FILE* result_file - output file.
 * @return int - 0 if there are no strings after this input. 1 if there are strings after this input.
 */
 int ScanFile(struct Coefs* input_coefs, int* expected_ammount_of_roots, struct Roots* input_roots,  FILE* file, FILE* result_file);


 /**
 * @brief Function that open files and find solves for every string
 */
 void WorkWithFile();

  /**
 * @brief This function is responsible for dialogue with the user and outputting a solution.
 */
 void WorkWithConsole();

void ScanInp(struct Coefs* input_coefs)
{
    int inp = 0;

    while(scanf("%lg%lg%lg", &input_coefs->coef_a, &input_coefs->coef_b, &input_coefs->coef_c) != 3 && (inp = getchar()) != EOF)
    {
        printf("Bro, you introduced bullshit. Try again\n");
        while(inp != '\n')
        {
            inp = getchar();
        }
    }
}

void PrintRoots(struct Roots result_roots, RootsNumb roots_cnt)
{
    switch(roots_cnt)
    {
        case ZERO:
            printf("Your equation has no roots");
            break;
        case ONE:
            printf("Your equation has a single root x = %lg", result_roots.root_1);
            break;
        case TWO:
            printf("Your equation has two roots x1 = %lg, x2 = %lg", result_roots.root_1, result_roots.root_2);
            break;
        case INF:
            printf("Your equation has an infinite number of roots");
            break;
        default:
            break;
    }
}


void PrintRootsIntoFile(struct Roots result_roots, RootsNumb roots_cnt, int expected_ammount_of_roots,
 struct Roots input_roots, FILE* result_file)
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
            fprintf(result_file, "x1 = %lg - ", input_roots.root_1);
            if(expected_ammount_of_roots == 1 && result_roots.root_1 == input_roots.root_1)
            {
                fprintf(result_file, "correct\n");
            }
            else
            {
                fprintf(result_file, "not correct, expected root = %lg\n", input_roots.root_1);
            }
            break;
        case TWO:
            fprintf(result_file, "x1 = %lg x2 = %lg - " , input_roots.root_1, input_roots.root_2);
            if(expected_ammount_of_roots == 2 && (result_roots.root_1 == input_roots.root_1 && result_roots.root_2 == input_roots.root_2)
            || (result_roots.root_1 == input_roots.root_2 && result_roots.root_2 == input_roots.root_1))
            {
                fprintf(result_file, "correct\n");
            }
            else
            {
                fprintf(result_file, "not correct, expected first root = %lg expected first root = %lg\n", input_roots.root_1, input_roots.root_2);
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

int ScanFile(struct Coefs* input_coefs, int* expected_ammount_of_roots, struct Roots* input_roots,  FILE* file, FILE* result_file)
{
    int inp = 0;
    if(fscanf(file, "%lg%lg%lg%d%lg%lg", &input_coefs->coef_a, &input_coefs->coef_b, &input_coefs->coef_c, expected_ammount_of_roots, &input_roots->root_1, &input_roots->root_2) == 6)
    {
        fprintf(result_file, "%lg %lg %lg ", input_coefs->coef_a, input_coefs->coef_b, input_coefs->coef_c);
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

    struct Coefs input_coefs;
    struct Roots result_roots;
    struct Roots input_roots;

    int expected_ammount_of_roots = NAN;

    double expected_root1 = NAN;
    double expected_root2 = NAN;


    while(ScanFile(&input_coefs, &expected_ammount_of_roots, &input_roots, file, result_file))
    {

        double root_1 = 0;
        double root_2 = 0;

        RootsNumb roots_cnt = Find_roots(input_coefs, &result_roots);
        PrintRootsIntoFile(result_roots, roots_cnt, expected_ammount_of_roots, input_roots, result_file);
    }

    fclose(file);

}


double Find_discriminant(Coefs input_coefs)
{
    double coef_a = input_coefs.coef_a;
    double coef_b = input_coefs.coef_b;
    double coef_c = input_coefs.coef_c;

    double discriminant = coef_b* coef_b - 4* coef_a * coef_c;

    return discriminant;
}

RootsNumb Solve_square_equation(Coefs input_coefs, struct Roots* result_roots)
{
    double discriminant = Find_discriminant(input_coefs);
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

RootsNumb Solve_linear_equation(Coefs input_coefs, struct Roots* result_roots)
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

RootsNumb Solve_constant_equation(Coefs input_coefs)
{
    double coef_c = input_coefs.coef_c;
    return (coef_c == 0 ? INF : ZERO);
}

RootsNumb Find_roots(Coefs input_coefs, Roots* result_roots)
{
    double coef_a = input_coefs.coef_a;
    double coef_b = input_coefs.coef_b;
    double coef_c = input_coefs.coef_c;

    if(coef_a == 0 && coef_b == 0)
    {
        return Solve_constant_equation(input_coefs);
    }

    if(coef_a == 0)
    {
        return Solve_linear_equation(input_coefs, result_roots);

    }

    return Solve_square_equation(input_coefs, result_roots);
}


// TODO: add docs (doxygen) +
// TODO: add unit test
// TODO: read argc, argv arg_parse : task.exe -i stdin -o output.txt -t
// TODO: function pointer (callback)




void WorkWithConsole()
{
    printf("This program finds solutions to a quadratic equation of the form ax^2 + bx + c = 0\n");
    printf("Enter coefficients a, b, c separated by spaces\n");

    struct Coefs input_coefs;
    struct Roots result_roots;





    ScanInp(&input_coefs);


    RootsNumb roots_cnt = Find_roots(input_coefs, &result_roots);
    PrintRoots(result_roots, roots_cnt);

}

 /** Main function.
 *  In this function you can choose if you want to work with a file or with a console.
 */
int main()
{
    //This Works With File

    WorkWithFile();

    //This Works With Console

    //WorkWithConsole();




    return 0;
}

