#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if defined __STDC_VERSION__ && __STDC_VERSION__ > 201710L
/* bool, true and false are keywords.  */
#else
#include <stdbool.h>
#endif

typedef char* string;
typedef int64_t s_id_t;

void freeAll(void** __ptrs, size_t __n_ptrs);
bool validChar(char c);