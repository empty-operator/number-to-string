#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUMS 5
#define INDEX 3

void GenerateNumbers(int[]);
void PrintNumbers(int, ...);
char * NumberToWord(int, char *);

char *units[] = {"", "один", "два", "три", "чотири", "п\'ять", "шість", "сім", "вісім", "дев\'ять"};
char *dozens[] = {"", "десять ", "двадцять ", "тридцять ", "сорок ", "п\'ятдесят ", "шістдесят ", "сімдесят ", "вісімдесят ",
                  "дев\'яносто "};
char *twenties[] = {"", "одинадцять ", "дванадцять ", "тринадцять ", "чотирнадцять ", "п\'ятнадцять ", "шістнадцять ",
                    "сімнадцять ", "вісімнадцять ", "дев\'ятнадцять "};
char *hundreds[] = {"", "сто ", "двісті ", "триста ", "чотириста ", "п\'ятсот ", "шістсот ", "сімсот ", "вісімсот ",
                    "дев\'ятсот "};

int main() {
    system("chcp 65001");
    int numberArray[NUMS];
    GenerateNumbers(numberArray);
    PrintNumbers(numberArray[0], numberArray[1], numberArray[2], numberArray[3], numberArray[4]);
    PrintNumbers(0, 212, 313, 414, 101);
    return 0;
}

void GenerateNumbers(int array[]) {
    printf("Генерація %d трицифрових чисел:\n", NUMS);
    srand(time(NULL));
    for (int i = 0; i < NUMS; ++i)
        array[i] = rand() % 900 + 100;
}

void PrintNumbers(int element, ...) {
    int *pEl = &element;
    char number[INDEX * 100];
    printf("Вивід даних:\n\tЧисло\t\tСловесний запис\n");
    for (int i = 0; i < NUMS; ++i, pEl++)
        printf("| %5d    |    %-40s |\n", *pEl, NumberToWord(*pEl, number));
}

char * NumberToWord(int number, char *pStr) {
    strcpy(pStr, hundreds[number / 100]);
    if (number / 10 % 10 == 1)
        return strcat(pStr, twenties[number % 10]);
    strcat(pStr, dozens[number / 10 % 10]);
    return strcat(pStr, units[number % 10]);
}