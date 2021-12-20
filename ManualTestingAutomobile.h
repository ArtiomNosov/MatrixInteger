#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Automobile.h"
#include "../UI/UI.h"

#ifndef MANUALTESTINGAUTOMOBILE
#define MANUALTESTINGAUTOMOBILE

typedef struct Automobile Automobile;

enum MenuAutomobileCodes {
    // ReadFromConsole = 1,
    // ReadFromBinaryFile,
    RandomGenerate = 1,
    WriteSourceInConsole,
    WriteResultInConsole,
    // WriteSourceInBinaryFile,
    // WriteResulInBinaryFile,
    MenuBubbleSort,
    MenuInsertionSort,
    MenuSelectionSort,
    MenuCount
};
enum ErrorCodes {
    NoData = -1,
    NotIndex = -2,
    BadSize = -4,
    BadBrand = -5, 
    BadMileage = -6
};

void AutomobilePrintf(Automobile* automobile);
Automobile* AutomobileScanf(size_t n, size_t m);
bool AutomobileBrendAssertUI(char* brand);
int AutomobileAssertUI(Automobile* automobile);
void AutomobileArrayAssertUI(Automobile** arr, size_t n, const char* name);

void AutomoblieMenu();

void printOptionsAutomoblieMenu();
// Automobile**  ReadAutomobilesFromConsole();
// Automobile**  ReadAutomobilesFromBinaryFile();
Automobile**  RandomGenerateAutomobiles(size_t* n);

void WriteAutomobileArrayInConsole(Automobile** arr, size_t n, const char* name);
// void WriteAutomobileArrayInBinaryFile(Automobile** arr, size_t n, const char* name);
int errorNoDataInAutomobileArray(Automobile** arr);

void* deleteAutomobileArray(Automobile** arr, size_t n);

#endif
