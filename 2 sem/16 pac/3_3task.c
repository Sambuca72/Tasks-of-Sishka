# pragma comment(linker, "/STACK:50000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 500005
const char *expr;
int pos = 0;
void skip() 
{
    while (isspace(expr[pos])) pos++;
}
double expression();
double number()
{
    skip();
    int start = pos;
    while (isdigit(expr[pos])) pos++;
    char buf[10];
    strncpy(buf, expr + start, pos - start);
    buf[pos - start] = '\0';
    return atof(buf);
}

double factor() 
{
    skip();
    if (expr[pos] == '(')
    { 
        pos++;
        double value = expression();
        skip();
        pos++;
        return value;
    } else if (expr[pos] == '-')
    {
        pos++;
        return -factor();
    } else 
    {
        return number();
    }
}

double term() 
{
    double value = factor();
    while (1) 
    {  
        skip();
        if (expr[pos] == '*')
        {         
            pos++;
            value *= factor();
        } else if (expr[pos] == '/') 
        {
            pos++;
            value /= factor();
        } else 
        {
            break;
        }
    }
    return value;
}
double expression() 
{
    double value = term();
    while (1) 
    {
        skip();
        if (expr[pos] == '+') 
        {
            pos++;
            value += term();
        } else if (expr[pos] == '-') 
        {
            pos++;
            value -= term();
        } else 
        {
            break;
        }
    }
    return value;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    static char input[MAX_LEN]; 
    fgets(input, MAX_LEN, stdin);
    expr = input;
    pos = 0;
    double result = expression();
    printf("%.20lf\n", result);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
