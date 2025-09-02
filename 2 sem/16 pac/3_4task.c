#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
typedef struct
{
    double l, r;
    double cx[4], cy[4], cz[4];
} Span;

double deriv(double c1, double c2, double c3, double t_shift) 
{
    return c1 + 2 * c2 * t_shift + 3 * c3 * t_shift * t_shift;
}

double expr(Span s, double t) 
{
    double shift = t - s.l;
    double dx = deriv(s.cx[1], s.cx[2], s.cx[3], shift); 
    double dy = deriv(s.cy[1], s.cy[2], s.cy[3], shift);
    double dz = deriv(s.cz[1], s.cz[2], s.cz[3], shift);
    return sqrt(dx * dx + dy * dy + dz * dz);

}

double simpson_r(Span s, double a, double b) 
{
    double c = (a + b) / 2.0;
    double fa = expr(s, a);
    double fb = expr(s, b);
    double fc = expr(s, c);
    return (b - a) / 6.0 * (fa + 4.0 * fc + fb);
}

double simpv2(Span s, double a, double b, double eps, double whole)
{
    double c = (a + b) / 2.0;
    double left = simpson_r(s, a, c);
    double right = simpson_r(s, c, b); 

    if (fabs(left + right - whole) <= 15 * eps)
        return left + right + (left + right - whole) / 15.0;
    return simpv2(s, a, c, eps / 2.0, left) + simpv2(s, c, b, eps / 2.0, right);
}

double simp_orig(Span s) 
{
    double a = s.l, b = s.r;
    double initial = simpson_r(s, a, b);
    return simpv2(s, a, b, 1e-9, initial);
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; // Количество спанов
    scanf("%d", &N);

    Span spans[1000];
    for (int i = 0; i < N; i++) 
    {
        scanf("%lf %lf", &spans[i].l, &spans[i].r);
        for (int j = 0; j < 4; j++) 
            scanf("%lf", &spans[i].cx[j]);
        for (int j = 0; j < 4; j++) 
            scanf("%lf", &spans[i].cy[j]);
        for (int j = 0; j < 4; j++) 
            scanf("%lf", &spans[i].cz[j]);
    }

    double length = 0.0;
    for (int i = 0; i < N; i++) 
    {
        length += simp_orig(spans[i]);
    }
    printf("%.20lf\n", length);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

