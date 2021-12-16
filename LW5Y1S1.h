#include "MatrixInteger.h"
#include "UI.h"

#ifndef LW5Y1S1H
#define LW5Y1S1H

typedef struct MatrixInteger MatrixInteger;

enum LW5Y1S1Codes {
    ReadFromConsole = 1,
    ReadFromBinaryFile,
    RandomGenerate,
    WriteSourceInConsole,
    WriteResultInConsole,
    WriteSourceInBinaryFile,
    WriteResulInBinaryFile,
    InsertRow,
    InsertColumn,
    EraseRow,
    EraseColumn,
    Count
};
enum ErrorCodes {
    OK = 0,
    NoData = -1,
    NotIndex = -2,
    NoMemory = -3,
    BadSize = -4
};

void printOptionsLW5Y1S1();
void LW5Y1S1();

MatrixInteger*  ReadMatrixIntegerFromConsole();
MatrixInteger*  ReadMatrixIntegerFromBinaryFile();
MatrixInteger*  RandomGenerateMatrixInteger();

void WriteMatrixIntegerInConsole(MatrixInteger* matrix, const char* matrixName);
void WriteMatrixIntegerInBinaryFile(MatrixInteger* matrix, const char* matrixName);

MatrixInteger*  InsertRowMenu(MatrixInteger* matrix);
MatrixInteger*  InsertColumnMenu(MatrixInteger* matrix);
MatrixInteger*  EraseRowMenu(MatrixInteger* matrix);
MatrixInteger*  EraseColumnMenu(MatrixInteger* matrix);

int errorNoData(MatrixInteger* matrix);
int errorNoIndex(size_t index, size_t max);
int errorNoMemory(void* ptr);
int errorSizeMatrix(int n, int m);

void fillArray(int* array, int n);

void* delOldMatrixInteger(MatrixInteger* matrix);

#endif