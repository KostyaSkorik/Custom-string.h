#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

// Предполагается, что s21_sprintf реализована и объявлена в соответствующем заголовочном файле
// Например, #include "s21_sprintf.h"

// Пример объявления s21_sprintf, замените на актуальное при необходимости
int s21_sprintf(char *str, const char *format, ...);

// Функция для сравнения и вывода результатов
void compare_and_print(const char *description, const char *buffer_std, const char *buffer_s21) {
    bool match = strcmp(buffer_std, buffer_s21) == 0;
    printf("%s:\n", description);
    printf("sprintf:       |%s|\n", buffer_std);
    printf("s21_sprintf:   |%s|\n", buffer_s21);
    if (match) {
        printf("Результаты совпадают.\n\n");
    } else {
        printf("Результаты отличаются!\n\n");
    }
}

int main() {
    char buffer_sprintf[1024];
    char buffer_s21_sprintf[1024];
    
    // Переменные для всех спецификаторов
    int d = -42;
    unsigned int u = 3000000000;
    float f = 3.14159f;
    double df = 2.718281828459;
    char c = 'A';
    char *s = "Hello, World!";
    void *p = &c;
    int n_sprintf = 0;
    int n_s21 = 0;
    char percent = '%';

    // Форматная строка с использованием всех основных спецификаторов
    const char *format = "%%: %% | %%c: %c | %%s: %s | %%d: %d | %%u: %u | %%f: %.2f | %%e: %.3e | %%E: %.3E | %%g: %.4g | %%G: %.4G | %%x: %#x | %%X: %#X | %%o: %#o | %%p %p |";

    // Вызов стандартной функции sprintf

    // Вызов пользовательской функции s21_sprintf
    s21_sprintf(buffer_s21_sprintf, format,c, s, d, u, f, df, df, f, f, d, d, d, p);
    // printf("%p", &c);

    sprintf(buffer_sprintf, format, c, s, d, u, f, df, df, f, f, d, d, d, p);


    // Сравнение результатов
    compare_and_print("Тест всех спецификаторов в одной строке", buffer_sprintf, buffer_s21_sprintf);

    // Дополнительный вывод для спецификатора %n
    printf("Спецификатор %%n:\n");
    printf("sprintf:       Количество символов: %d\n", n_sprintf);
    printf("s21_sprintf:   Количество символов: %d\n\n", n_s21);

    return 0;
}
