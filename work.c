#include "squareEquantionStructs.h"
#include "print.c"
#include "header.h"
#include "equantions.c"
#include "scan.c"
#include "header.h"

const char* greeting_string = "This program finds solutions to a quadratic equation of the form ax^2 + bx + c = 0\nEnter coefficients a, b, c separated by spaces\n";

void WorkWithFile(FILE* file, FILE* result_file)
{

    Coefs input_coefs = {NAN, NAN, NAN};
    Roots result_roots = {NAN, NAN};
    Roots input_roots = {NAN, NAN};

    int expected_ammount_of_roots = NAN;

    double expected_root1 = NAN;
    double expected_root2 = NAN;


    while(ScanFile(&input_coefs, &expected_ammount_of_roots, &input_roots, file, result_file))
    {
        RootsNumb roots_cnt = FindRoots(input_coefs, &result_roots);
        PrintRootsIntoFile(result_roots, roots_cnt, expected_ammount_of_roots, input_roots, result_file);
    }
}





void WorkWithConsole()
{
    printf("%s", greeting_string);

    Coefs input_coefs;
    Roots result_roots;

    ScanInp(&input_coefs);

    RootsNumb roots_cnt = FindRoots(input_coefs, &result_roots);
    PrintRoots(result_roots, roots_cnt);

}
