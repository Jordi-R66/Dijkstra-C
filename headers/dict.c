#include "dict.h"

void initDict(Dict* dict, size_t keySize, size_t valSize, size_t initCapacity) {
	initializeList(&dict->pairs, initCapacity, sizeof(KeyValuePair_t));

	dict->keySize = keySize;
	dict->valSize = valSize;
}

void* getValue(Dict* dict, void* key) {
	void* val = NULL;

	for (size_t i=0; i < dict->pairs.n_elements; i++) {
		KeyValuePair_t* kvp_ptr = (KeyValuePair_t*)getElement(&dict->pairs, i);

		if (memcmp(key, kvp_ptr->key, dict->keySize)) {
			val = kvp_ptr->value;
			break;
		}
	}

	return val;
}