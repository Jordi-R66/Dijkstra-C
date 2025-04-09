#include "dict.h"

void initDict(Dict* dict, size_t keySize, size_t valSize, size_t initCapacity) {
	initializeList(&dict->keys, initCapacity, keySize);
	initializeList(&dict->values, initCapacity, valSize);

	dict->capacity = initCapacity;
}

void* getValue(Dict* dict, void* key) {
	void* val = NULL;

	size_t DeltaKeys = dict->keys.elementSize;
	size_t DeltaVals = dict->values.elementSize;

	for (size_t i=0; i < dict->keys.n_elements; i++) {
		void* keyIndex = getElement(&dict->keys, i);

		if (memcmp(key, keyIndex, DeltaKeys)) {
			val = getElement(&dict->values, i);
		}
	}

	return val;
}