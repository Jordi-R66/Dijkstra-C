#pragma once

#include "list.h"

typedef struct {
	List keys;
	List values;
	size_t capacity;
} Dict;

void initDict(Dict* dict, size_t keySize, size_t valSize, size_t n_records);
void* getValue(void* key);
void addValue(void* key, void* value);
void removeValue(void* key);