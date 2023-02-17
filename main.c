#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void text(char* PATH)
{
	char symbol;
	FILE* fd = fopen(PATH, "r");
	while ((symbol = fgetc(fd)) != EOF) 
	{
		putchar(symbol);
	}
	printf("\n");
	fclose(fd);
}

int sentencesCount(char* PATH)
{
	FILE* fd = fopen(PATH, "r");
	int sentences = 0;
	char symbol;
	while ((symbol = fgetc(fd)) != EOF)
	{
		if (symbol == '?' || symbol == '!' || symbol == '.')
		{
			sentences += 1;
			continue;
		}
	}
	fclose(fd);
	return sentences;
}

int wordsCount(char* PATH)
{
	FILE* fd = fopen(PATH, "r");
	int words = 0;
	char symbol;
	int state = 0;
	while ((symbol = fgetc(fd)) != EOF) 
	{
		if (state == 0 && !(symbol == ' ' || symbol == '\t' || symbol == '\n' || symbol == '-')) 
		{
			state = 1;
			continue;
		}
		if (state == 1 && (symbol == ' ' || symbol == '\t' || symbol == '\n' || symbol == '-')) 
		{
			words += 1;
			state = 0;
		}
	}
	if (state == 1) 
	{
		words += 1;
	}

	fclose(fd);
	return words;
}

int hasD(char* word) 
{
	int i = 0;
	while (word[i] != '\0') 
	{
		if (word[i] == 'd') 
		{
			return 1;
		}
		i += 1;
	}
	return 0;
}

int endWithVowel(char* word)
{
	int len = strlen(word);
	int i = len - 1;
	while (word[i] == '.' || word[i] == ',' || word[i] == '!' || word[i] == '?') 
	{
		i -= 1;
	}
	if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y') 
	{
		return 1;
	}
	return 0;
}

void printlnWithoutPunct(char* word)
{
	int i = 0;
	while (!(word[i] == '\0' || word[i] == '.' || word[i] == ',' || word[i] == '!' || word[i] == '?')) 
	{
		putchar(word[i]);
		i += 1;
	}
	putchar('\n');
	return;
}

int specialWordsCount(char* PATH) 
{
	FILE* fd = fopen(PATH, "r");
	int specialWords = 0;
	char buf[1000];
	while (fscanf(fd, "%s", buf) > 0)
	{
		if (hasD(buf) && endWithVowel(buf))
		{
			specialWords += 1;
			printlnWithoutPunct(buf);
		}
	}
	fclose(fd);
	return specialWords;
}

int main() 
{
	setlocale(0, "Rus");
	const char* Path = "E:\\T.txt";
	text(Path);
	printf("\n");
	_getch();
	printf("����� ���������� ����: %d\n", wordsCount(Path));
	printf("\n");
	_getch();
	printf("����� ���������� �����������: %d\n", sentencesCount(Path));
	printf("\n");
	_getch();
	printf("���������� ����, ������� ������������� ��������: %d\n", specialWordsCount(Path));
	_getch();

	return 0;
}