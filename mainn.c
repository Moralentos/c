#include <stdio.h>
#include <math.h>

double x1 = 1.0, x2 = 3.0;
double a1 = 1.0, a2 = 2.0;
double step1 = 0.25, step2 = 0.2;
double y, S1 = 0, S2 = 0, negative_count1 = 0, negative_count2 = 0;

double function(double x, double a) {
return pow(cos(a * x), 2) - sqrt(fabs(a * a - log(x)));
}

void table1(double step, double a) {
double x;
printf("\nTable with a = %lf, step = %lf\n", a, step);
printf("x\ty\n");
for (x = x1; x <= x2; x += step) {
y = function(x, a);
if (y < 0) {
S1 += y;
negative_count1++;
}
printf("%.2lf\t%.2lf\n", x, y);
}
printf("Sum of negative values: %lf\n", S1);
printf("Number of negative values: %lf\n", negative_count1);
}

void table2(double step, double a) {
double x;
printf("\nTable with a = %lf, step = %lf\n", a, step);
printf("x\ty\n");
for (x = x1; x <= x2; x += step) {
y = function(x, a);
if (y < 0) {
S2 += y;
negative_count2++;
}
printf("%.2lf\t%.2lf\n", x, y);
}
printf("Sum of negative values: %lf\n", S2);
printf("Number of negative values: %lf\n", negative_count2);
}

int main(void) {
table1(step1, a1);
table2(step2, a2);
return 0;
}