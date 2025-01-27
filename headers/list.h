#pragma once

#include "commons.h"

struct List {
	size_t capacity;
	size_t n_elements;
	size_t elementSize;

	void* elements;
};

typedef struct List List;

