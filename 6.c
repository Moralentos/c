#include <stdio.h>
#include <string.h>

int main()
{
    char message[100], key[10];
    int i, j;

    printf("Text: ");
    gets(message);
    printf("Key: ");
    gets(key);

    for(i = 0, j = 0; message[i] != '\0'; ++i, ++j)
    {
        if(j == strlen(key))
        {
            j = 0;
        }

        message[i] = message[i] ^ key[j];
    }

    printf("Shifr text: %s\n", message);

    for(i = 0, j = 0; message[i] != '\0'; ++i, ++j)
    {
        if(j == strlen(key))
        {
            j = 0;
        }

        message[i] = message[i] ^ key[j];
    }

    printf("Rasshifr text: %s\n", message);

    return 0;
}
