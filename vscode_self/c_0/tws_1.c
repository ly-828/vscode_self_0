#include <stdio.h>
#include <math.h>
int main()
{
    int n = 1000;
    double ac = -1, bc = 1, ae = 0, be = 2, c, (*p)();
    double jiff();
    /*double jiff(double a,double b, int n, double (*p)());*/
    p = cos;
    c = jiff(ac, bc, n, p);
    printf("the definite integral of cosx %g to %g is: %.8f\n", ac, bc, c);
    p = exp;
    c = jiff(ae, be, n, p);
    printf("the definite integral of exp %g to %g is：%.8f\n", ae, be, c);
    return 0;
}
double jiff(double a, double b, int n, double (*p)())
{

    int i;
    double x, h, area;
    
    h = (b - a) / n;
    x = a;
    area = 0;
    for (i = 0; i < n; i++)
    {
        if (x==0)
            x=x+0.00001;
        
        area += (*p)(x)*h;
        x = x + h;
    }
    return area;
}