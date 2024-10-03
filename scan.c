#include "squareEquantionStructs.h"
#include "header.h"

void ScanInp(Coefs* input_coefs)
{
    int inp = 0;

    while(scanf("%lg%lg%lg", &input_coefs->coef_a, &input_coefs->coef_b, &input_coefs->coef_c) != 3 && (inp = getchar()) != -1)
    {
        printf("Bro, you entered bullshit. Try again\n");

        while(inp != '\n')
        {
            inp = getchar();
        }
    }
}

int ScanFile(Coefs* input_coefs, int* expected_ammount_of_roots, Roots* input_roots,  FILE* file, FILE* result_file)
{
    int inp = 0;

    if(fscanf(file, "a: %lg b: %lg c: %lg ammount: %d x1: %lg x2: %lg\n", &input_coefs->coef_a, &input_coefs->coef_b, &input_coefs->coef_c, expected_ammount_of_roots, &input_roots->root_1, &input_roots->root_2) == 6)
    {
        fprintf(result_file, "%lg %lg %lg ", input_coefs->coef_a, input_coefs->coef_b, input_coefs->coef_c);
        return 1;
    }
    else
    {
        return 0;
    }
}
