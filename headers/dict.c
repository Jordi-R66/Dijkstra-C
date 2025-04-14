#include "dict.h"

void initDict(Dict* dict, size_t keySize, size_t valSize, size_t initCapacity) {
	initializeList(&dict->pairs, initCapacity, sizeof(KeyValuePair_t));

	dict->keySize = keySize;
	dict->valSize = valSize;
}


void setPair(Dict* dict, void* currentKey, KeyValuePair_t newKvp) {
	for (size_t i=0; i < dict->pairs.n_elements; i++) {
		KeyValuePair_t* kvp_ptr = (KeyValuePair_t*)getElement(&dict->pairs, i);

		if (memcmp(currentKey, kvp_ptr->key, dict->keySize)) {
			kvp_ptr->key = newKvp.key;
			kvp_ptr->value = newKvp.value;
			break;
		}
	}
}

void setValue(Dict* dict, void* key, void* newValue) {
	KeyValuePair_t kvp = {key, newValue};

	setPair(dict, key, kvp);
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

void addPair(Dict* dict, KeyValuePair_t kvp) {
	addElement(&dict->pairs, &kvp);
}

void addValue(Dict* dict, void* key, void* value) {
	KeyValuePair_t kvp;

	kvp.key = key;
	kvp.value = value;

	addPair(dict, kvp);
}

void removePair(Dict* dict, void* key) {
	for (size_t i=0; i < dict->pairs.n_elements; i++) {
		KeyValuePair_t* kvp_ptr = (KeyValuePair_t*)getElement(&dict->pairs, i);

		if (memcmp(key, kvp_ptr->key, dict->keySize)) {
			removeElement(&dict->pairs, i, true);
			break;
		}
	}
}

void freeDict(Dict* dict, bool freeKeys, bool freeValues) {
	for (size_t i=0; (i < dict->pairs.n_elements) && ((freeKeys) || (freeValues)); i++) {
		KeyValuePair_t* kvp_ptr = (KeyValuePair_t*)getElement(&dict->pairs, i);

		if (freeKeys) {
			free(kvp_ptr->key);
		}

		if (freeValues) {
			free(kvp_ptr->value);
		}
	}

	freeList(&dict->pairs);
}