#include <TXLib.h>
#include<stdio.h>
#include <assert.h>
#include <math.h>

const double very_small_double = 1e-8;

//����� ���� ������:
//1) ��� ����������
//    1.1) ���� ������ +
//    1.2) ��� ����� +
//    1.3) ��� ������ +
//2) ��� ����������� � �������� +
//3) ��� ����������� � ��������� = 0
//    3.1) ��������� = 0 => ������ x ��������
//    3.2) ��������� != 0 => ��� �������

/**
 * @file main.c
 * @brief �������� ���� ���������.
 */

/**
 * @brief �������� ������� ���������.
 *
 * @param argc ���������� ���������� ��������� ������.
 * @param argv ������ ���������� ��������� ������.
 * @return ��� �������� ���������.
 */
enum RootsNumb : int

{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    INF = 3
};

double Find_discriminant(double coef_a, double coef_b, double coef_c);
RootsNumb Find_roots(double coef_a, double coef_b, double coef_c, double* root_1, double* root_2);
RootsNumb Solve_square_equation(double coef_a, double coef_b, double coef_c, double* root_1, double* root_2);
RootsNumb Solve_linear_equation(double coef_b, double coef_c, double* root_1);
RootsNumb Solve_constant_equation(double coef_c);
void PrintRoots(double root_1, double root_2, RootsNumb roots_cnt);
void ScanInp(double* coef_a, double* coef_b, double* coef_c);


void ScanInp(double* coef_a, double* coef_b, double* coef_c)
{
    int inp = 0;

    while(scanf("%lg%lg%lg", coef_a, coef_b, coef_c) != 3 && (inp = getchar()) != -1)
    {
        printf("���, �� ��� �����. �������� ��� ���\n");
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
            printf("���� ��������� �� ����� ������");
            break;
        case ONE:
            printf("���� ��������� ������ ������������ ������ x = %lg", root_1);
            break;
        case TWO:
            printf("���� ��������� ����� ��� ����� x1 = %lg, x2 = %lg", root_1, root_2);
            break;
        case INF:
            printf("���� ��������� ����� ����������� ���-�� ������");
            break;
        default:
            break;
    }
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


// TODO: add docs (doxygen)
// TODO: add unit test
// TODO: read argc, argv arg_parse : task.exe -i stdin -o output.txt -t
// TODO: function pointer (callback)
//��������� ����� � ������� ���������


int main()
{
    printf("������ ��������� ������� ������� ����������� ���������, �������� ��� ax^2 + bx + c = 0\n");
    printf("������� ������������ a, b, c ����� ������\n");

    double coef_a = NAN;
    double coef_b = NAN;
    double coef_c = NAN;

    ScanInp(&coef_a, &coef_b, &coef_c);

    double root_1 = 0;
    double root_2 = 0;

    RootsNumb roots_cnt = Find_roots(coef_a, coef_b, coef_c, &root_1, &root_2);
    PrintRoots(root_1, root_2, roots_cnt);


    return 0;
}

