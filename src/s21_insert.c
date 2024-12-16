#include "s21_string.h"

void preparing_to_insert(const char* str, const char* src,
                         s21_size_t start_index, char* new_str) {
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_src = s21_strlen(src);
  for (s21_size_t i = len_src - 1; i >= start_index; i--) {
    char tmp = src[i];
    for (s21_size_t j = 0; j < (len_str); j++) {
      new_str[i + j] = ' ';
    }
    new_str[i + len_str] = tmp;
    if (i == 0) {
      break;
    }
  }
}

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_src = s21_strlen(src);
  char* new_str = s21_NULL;
  if (start_index <= len_src) {
    new_str = calloc(2056, sizeof(char));
    s21_strncpy(new_str, src, len_src);
    if (len_src != 0) {
      preparing_to_insert((char*)str, (char*)src, start_index, new_str);
    }

    int j = 0;
    for (s21_size_t i = start_index; i < (start_index + len_str); i++) {
      new_str[i] = str[j];
      j++;
    }
    new_str[s21_strlen(new_str)] = '\0';
  }

  return new_str;
}