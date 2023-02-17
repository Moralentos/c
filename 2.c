#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

double x1 =1 , x2 = 3;
double x, y, sum = 0, sum_all = 0;
double f(double x, double alf)
{
	return pow(cos(alf * x), 2) - sqrt(fabs(alf * alf - log(x)));
}

double tb(double dx, double alf);

int main(void)
{
	tb(0.25, 1);
	tb(0.2, 1.2);
	_getch();
	return 0;
}

double tb(double dx, double alf)
{
	printf("  x    |    y\n");
	for (x = x1; x <= x2; x += dx)
	{
		y = f(x, alf);
		if (y < 0) {
            sum += y;
            
        }
        sum_all += y;
		printf("%6.2lf | %6.3lf\n", x, y);
	}
	printf("______________________________________________________\n");
    printf("Sum negativ number: %lf\n", sum);
    printf("Sum all number: %lf\n", sum_all);
}
