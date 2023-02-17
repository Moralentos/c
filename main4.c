#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int m[6][6];
int n = 6;

void init(int a, int b);
void show(void);
void lt(void);
void mn(void);
void mx(void);

int main(void)
{
	setlocale(0, "Ru");
	init(-9, 9);
	show();
	_getch();
	mn();
	_getch();
	mx();
	_getch();
	lt();
	_getch();
	return 0;
}

void init(int a, int b)//Задает область чисел, из которых будет состоять матрица
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			m[i][j] = a + rand() % (b-a);
	return;
}

void show(void)//Строит матрицу
{
	int i, j;
	HANDLE hStd;
	hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i > j)
				SetConsoleTextAttribute(hStd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			else
				if (i < j)
					SetConsoleTextAttribute(hStd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				else
					SetConsoleTextAttribute(hStd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf(" %2d |", m[i][j]);
		}
		printf("\n_______________________________\n");
	}
	return;
}

void lt(void)//Выводит нижний треугольник и считает среднее арифметическое из этих элементов
{
	HANDLE hStd;
	hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	int i, j, counter = 0, sum = 0;
	float sr = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++) 
		{
			sum += m[i][j];
			printf(" %2d ", m[i][j]);
			counter += 1;
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hStd, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	sr = (float)sum / counter;
	printf("Среднее арифметическое элементов нижнего треугольника матрицы: %d / %d = % .2f \n", sum, counter, sr);
	return;
}

void mx(void)//Наибольший элемент из нечетных строчек матрицы
{
	HANDLE hStd;
	hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStd, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	double max = m[0][0];
	for (int i = 0; i < 6; i += 2) 
	{
		for (int j = 0; j < 6; ++j) 
		{
			if (max < m[i][j]) 
			{
				max = m[i][j];
			}
			printf(" %2d ", m[i][j]);
		}
		printf("\n");
	}
	printf("max: %lf \n", max);
	printf("----------------\n");
	return;
}

void mn(void)//Наименьший элемент из четных строчек матрицы
{
	HANDLE hStd;
	hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStd, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	double min = m[1][0];
	for (int i = 1; i < 6; i += 2) 
	{
		for (int j = 0; j < 6; ++j) 
		{
			if (min > m[i][j]) 
			{
				min = m[i][j];
			}
			printf(" %2d ", m[i][j]);
		}
		printf("\n");
	}
	printf("min: %lf \n", min);
	printf("----------------\n");
	return;
}