#include <stdio.h>
#include <math.h>
#include <conio.h>

#define MAX_ERROR 0.01

double f(double x)
{
    double value = pow(x,3) - 5*pow(x,2) + 7*x - 3;
    return value;
}

double fdash(double x)
{
    double value = 3*pow(x,2) - 10*x + 7;
    return value;
}

int main()
{
    double x,x_new,root,f_val,fdash_val,diff;

    printf("Initial x: ");
    scanf("%lf",&x);

    printf("\n\n");

    while(1)
    {
        f_val = f(x);
        fdash_val = fdash(x);
        x_new = x - (f_val/fdash_val);
        diff = x_new - x;

        printf("f(x) = %lf \n",f_val);
        printf("f'(x) = %lf \n",fdash_val);
        printf("New x: %lf \n\n\n",x_new);

        //2getch();

        if(f_val == 0.0)
        {
            root = x_new;
            break;
        }

        if(abs(diff)<2*MAX_ERROR)
        {
            root = (x_new + x)/2;
            break;
        }

        x = x_new;

    }

    printf("\n--> Estimated Root at %lf \n\n",root);
}
