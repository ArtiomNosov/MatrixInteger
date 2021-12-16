#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#ifndef MatrixIntegerH
#define MatrixIntegerH

#define ERROR_FILE_OPEN -3
 
typedef struct MatrixInteger {
    int** Rows;

    size_t RowCount;
    size_t ColumnCount;
} MatrixInteger;

int AssertOpenFile(FILE* file);

MatrixInteger* CreateMatrixInteger(size_t n, size_t m);
void AssertMatrixInteger(MatrixInteger* matrix);
void FreeMatrixInteger(MatrixInteger* matrix);

void MatrixIntegerPrintf(MatrixInteger* matrix);
MatrixInteger* MatrixIntegerScanf(size_t n, size_t m);

void MatrixIntegerFwrite(MatrixInteger* matrix, const char* fileName);
MatrixInteger* MatrixIntegerFread(const char* fileName);

MatrixInteger* MatrixIntegerRand(size_t n, size_t m);

MatrixInteger* InsertRowMatrixInteger(MatrixInteger* matrix, int* row, size_t m, size_t i);
MatrixInteger* InsertColumnMatrixInteger(MatrixInteger* matrix, int* column, size_t n, size_t j);

MatrixInteger* EraseRowMatrixInteger(MatrixInteger* matrix, size_t i);
MatrixInteger* EraseColumnMatrixInteger(MatrixInteger* matrix, size_t j);

#endif