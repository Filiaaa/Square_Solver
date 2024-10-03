#include "squareEquantionStructs.h"
#include "print.h"
void PrintRoots(Roots result_roots, RootsNumb roots_cnt)
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

void PrintCorrectionIntoFile(Roots input_roots, int error_situation, FILE* result_file)
{
    switch(error_situation)
    {
        case 0:
            fprintf(result_file, "not correct, equantion has no rules\n");
            break;
        case 1:
            fprintf(result_file, "not correct, expected root = %lg\n", input_roots.root_1);
            break;
        case 2:
            fprintf(result_file, "not correct, expected first root = %lg expected first root = %lg\n", input_roots.root_1, input_roots.root_2);
            break;
        case 3:
            fprintf(result_file, "not correct, every x is root\n");
        default:
            printf("Fuck");
            break;
    }

}


void PrintRootsIntoFile(Roots result_roots, RootsNumb roots_cnt, int expected_ammount_of_roots,
 Roots input_roots, FILE* result_file)
{
    int is_correct = 1;
    int error_situation = 0;
    switch(roots_cnt)
    {
        case ZERO:
            fprintf(result_file, "no roots - ");
            if(expected_ammount_of_roots != 0)
            {
                is_correct = 0;
                error_situation = 0;
            }
            break;

        case ONE:
            fprintf(result_file, "x1 = %lg - ", input_roots.root_1);
            if(expected_ammount_of_roots != 1 || result_roots.root_1 != input_roots.root_1)
            {
                is_correct = 0;
                error_situation = 1;
            }
            break;

        case TWO:
            fprintf(result_file, "x1 = %lg x2 = %lg - " , input_roots.root_1, input_roots.root_2);
            if(expected_ammount_of_roots != 2 || (result_roots.root_1 != input_roots.root_1 || result_roots.root_2 != input_roots.root_2)
            && (result_roots.root_1 != input_roots.root_2 || result_roots.root_2 != input_roots.root_1))
            {
                is_correct = 0;
                error_situation = 2;
            }
            break;

        case INF:
            fprintf(result_file, "every x - ");
            if(expected_ammount_of_roots != 3)
            {
                is_correct = 0;
                error_situation = 3;
            }
            break;

        default:
            printf("Fuck");
            break;

    }
    if(is_correct == 1)
    {
        fprintf(result_file, "correct\n");
    }
    else
    {
        PrintCorrectionIntoFile(input_roots, error_situation, result_file);
    }
}
