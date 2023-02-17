#include <stdio.h>
#include <string.h>

int main() {
    int totalWords = 0, totalSentences = 0;
    int pWords = 0, aWords = 0, oWords = 0;
    char text[1000];
    FILE *file = fopen("H:\\T.txt", "r");

    if (file == NULL) {
        printf("Error");
        return 1;
    }

    while (fgets(text, 1000, file) != NULL) {
        int i;
        int length = strlen(text);
        int wordStart = 1;

        for (i = 0; i < length; i++) {
            if (text[i] == ' ' || text[i] == '.' || text[i] == '!' || text[i] == '?') {
                totalWords++;
                wordStart = 1;

                if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
                    totalSentences++;
                }
            } else {
                if (wordStart == 1) {
                    wordStart = 0;
                    if (text[i] == 'A' || text[i] == 'a') {
                        aWords++;
                    } else if (text[i] == 'O' || text[i] == 'o') {
                        oWords++;
                    }
                }

                if (text[i] == 'P' || text[i] == 'p') {
                    pWords++;
                }
            }
        }
    }

    fclose(file);

    printf("Всего слов: %d\n", totalWords);
    printf("Всего предложений: %d\n", totalSentences);
    printf("Количество слов, содержащих букву P и начинающихся буквой А или буквой О: %d\n", aWords + oWords);

    return 0;
}
