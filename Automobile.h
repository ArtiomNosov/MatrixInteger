#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <stdio.h>
#include "../Algorithm/Algorithm.h"

#ifndef AUTOMOBILE
#define AUTOMOBILE

#define MINNAMESIZE 2
#define MAXNAMESIZE 64
#define MAXMILEAGE 5000.0
#define BRANDSIZE   17
#define DASH        '-'
#define SPACE       ' '
#define BRANDSYMBOLCOUNT ( 'Z' - 'A' + 1 + 'z' - 'a' + 1 + (1 + 1) )
#define ALPHABETSIZE ( 'Z' - 'A' + 1 + 'z' - 'a' + 1 )

typedef struct Automobile {
    char Brand[BRANDSIZE];
    char* OwnerFullName;
    float Mileage; // In thousands of kilometers
} Automobile;

Automobile* AutomobileNew();
char alphabetRand(int seed);
void brandRand(char* brand);
Automobile* AutomobileNewRand();
Automobile** AutomobileArrayNewRand(size_t n);
Automobile* AutomobileNewFromData(char* brand, char* ownerFullName, float mileage);
Automobile* AutomobileNewFromAutomobile(Automobile* automobile);
bool IsCharBrand(char* ch);
void AutomobileAssert(Automobile* automobile);
void AutomobileArrayAssert(Automobile** arr, size_t n);
void AutomobileFree(Automobile* automobile);
void AutomobileArrayFree(Automobile** arr, size_t n);

bool AutomobileGreaterThanSign(Automobile* automobileLeft, Automobile* automobileRight);
bool AutomobileGreaterThanSignVoid(void* automobileLeft, void* automobileRight);

Automobile** AutomobileSort(Automobile** arr, size_t n, void (*sort) (intptr_t* arr, size_t n, bool (*greaterThanSign) (void*, void*) ) );
Automobile** AutomobileBubbleSort(Automobile** arr, size_t n);
Automobile** AutomobileInsertionSort(Automobile** arr, size_t n);
Automobile** AutomobileSelectionSort(Automobile** arr, size_t n);

#endif
