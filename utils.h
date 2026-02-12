#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

void mostrarMenu(void);

int lerInteiro(const char* prompt, int* out);
void lerString(const char* prompt, char* out, size_t tam);

#endif
