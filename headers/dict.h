#pragma once

#include "list.h"

typedef struct {
	void* key;
	void* value;
} KeyValuePair_t;

typedef struct {
	List pairs; // List of KeyValuePair_t

	size_t keySize; // Size of the key in bytes
	size_t valSize; // Size of the value in bytes
} Dict;

void initDict(Dict* dict, size_t keySize, size_t valSize, size_t n_records);
void* getValue(Dict* dict, void* key);
void addPair(Dict* dict, KeyValuePair_t kvp);
void addValue(Dict* dict, void* key, void* value);
void removeValue(Dict* dict, void* key);