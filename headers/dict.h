#pragma once

#include "list.h"

typedef struct {
	List keys;
	List values;
} Dict;

void* getValue(void* key);
void addValue(void* key, void* value);
void removeValue(void* key);