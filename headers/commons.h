#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* string;
typedef int64_t s_id_t;

void freeAll(void** __ptrs, size_t __n_ptrs);