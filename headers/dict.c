#include "dict.h"

void initDict(Dict* dict, size_t keySize, size_t valSize, size_t initCapacity) {
	initializeList(&dict->keys, initCapacity, keySize);
	initializeList(&dict->values, initCapacity, valSize);

	dict->capacity = initCapacity;
}