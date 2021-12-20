#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#ifndef ALGORITHM
#define ALGORITHM

void bubbleSort(intptr_t* a, size_t n, bool (*greaterThanSign) (void*, void*) );
void insertionSort(intptr_t* a, size_t n, bool (*greaterThanSign) (void*, void*) );
void selectionSort(intptr_t* arr, size_t n, bool (*greaterThanSign) (void*, void*) );

#endif