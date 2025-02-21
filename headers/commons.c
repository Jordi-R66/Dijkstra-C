#include "commons.h"

void freeAll(void** __ptrs, size_t __n_ptrs) {
	for (size_t i = 0; i < __n_ptrs; i++) {
		void* ptr = __ptrs[i];

		if (ptr != NULL) {
			free(__ptrs[i]);
		}
	}
}

bool validChar(char c) {
	char* validChars = " -+.0123456789azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN_{}[]()'\"";

	for (int i = 0; i < strlen(validChars); i++) {
		if (validChars[i] == c) {
			return true;
		}
	}

	return false;
}