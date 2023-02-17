#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int m[6][6];
int n=6;

void init(int a, int b);
void show(void);
void lt(void);
void ut(void);
void d(void);

int productOfPositiveElements(int n) {
    int i, j;
    int product = 1;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (m[i][j] > 0) {
                product *= m[i][j];
            }
        }
    }
    return product;
}

int findMinOddColumn(int n, int value) {
    int i, j;
    int minCount = n;
    int minColumn = -1;
    for (j = 0; j < n; j++) {
        if (j % 2 == 1) {
            int count = 0;
            for (i = 0; i < n; i++) {
                if (m[i][j] > value) {
                    count++;
                }
            }
            if (count < minCount) {
                minCount = count;
                minColumn = j;
            }
        }
    }
    return minColumn;
}


int main(void)
{
    init(-9,9);
    show();
    getch();
    lt();
    getch();
    ut();
    getch();
    d();
    getch();
    return 0;
}

void init(int a, int b)
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            m[i][j]=a+rand()%(b-a);
    return;
}

void show(void)
{
    int i,j;
    HANDLE hStd;
    hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (i>j)
                SetConsoleTextAttribute(hStd,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            else
                if (i<j)
                    SetConsoleTextAttribute(hStd,FOREGROUND_RED|FOREGROUND_INTENSITY);
                else
                    SetConsoleTextAttribute(hStd,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            printf(" %2d |",m[i][j]);
        }
        printf ("\n______________________________\n");
    }
    return;
}

void lt(void)
{
    HANDLE hStd;
    hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStd,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    int i,j;
    for (i=1;i<n;i++)
    {
        for (j=0;j<i;j++)
            printf("%2d ",m[i][j]);
        printf ("\n");
    }
    return;
}

void ut(void)
{
    HANDLE hStd;
    hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStd,FOREGROUND_RED|FOREGROUND_INTENSITY);
    int i,j;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<i;j++)
            printf("   ");
        for (j=i+1;j<n;j++)
            printf("%2d ",m[i][j]);
        printf ("\n");
    }
    return;
}

void d(void)
{
    HANDLE hStd;
    hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStd,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    int i;
    for (i=0;i<n;i++)
        printf("%2d ",m[i][i]);
        printf ("\n");
    return;
}
