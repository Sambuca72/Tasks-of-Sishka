#include <math.h>
extern double Function(double x);
double deriv(double x, double h) 
{
    if (x - h < 0) 
    {
        return (Function(x + h) - Function(x)) / h;
    } else if (x + h > 1) 
    {
        return (Function(x) - Function(x - h)) / h; 
    } else 
    {
        return (Function(x + h) - Function(x - h)) / (2 * h); 
}
