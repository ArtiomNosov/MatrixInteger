#include "MatrixInteger.h"

typedef struct MatrixInteger MatrixInteger;

int AssertOpenFile(FILE* file)
{
    if (file == NULL) 
    {
        printf("Ошибка открытия файла. Попробуйте другое имя файла.\n");
        scanf("%*c");
        return ERROR_FILE_OPEN;
    }
}

MatrixInteger* CreateMatrixInteger(size_t n, size_t m) // not test
{
    MatrixInteger* res = (MatrixInteger*) malloc(sizeof(MatrixInteger));
    res->Rows = (int**) malloc(sizeof(int*) * n);
    for (size_t i = 0; i < n; i++)
    {
        (res->Rows)[i] = (int*) malloc(sizeof(int) * m);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            ( (res->Rows)[i] )[j] = (int) 0;
        }
        
    }
    res->RowCount = n;
    res->ColumnCount = m;
    
    return res;
}
void AssertMatrixInteger(MatrixInteger* matrix)
{
    assert(matrix);
    assert(matrix->Rows);
    
}
void FreeMatrixInteger(MatrixInteger* matrix) // not test
{
    for (size_t i = 0; i < matrix->RowCount; i++)
    {
        free((matrix->Rows)[i]);
    }
    free(matrix->Rows);

}

void MatrixIntegerPrintf(MatrixInteger* matrix)
{
    AssertMatrixInteger(matrix);

    for (size_t i = 0; i < matrix->RowCount; i++)
    {
        for (size_t j = 0; j < matrix->ColumnCount; j++)
        {
            printf("%d \\ ", *((matrix->Rows)[i] + j));
        }
        printf("\n");
    }
    
}
MatrixInteger* MatrixIntegerScanf(size_t n, size_t m)
{
    MatrixInteger* res = CreateMatrixInteger(n, m);
    AssertMatrixInteger(res);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            scanf("%d", (res->Rows)[i] + j);
        }
    }
    
    return res;
}

void MatrixIntegerFwrite(MatrixInteger* matrix, const char* fileName)
{
    AssertMatrixInteger(matrix);

    FILE *output = NULL;
    output = fopen(fileName, "wb");
    if(AssertOpenFile(output) == ERROR_FILE_OPEN)
    {
        return;
    }
 
    fwrite(&(matrix->RowCount), sizeof(size_t), 1, output);
    fwrite(&(matrix->ColumnCount), sizeof(size_t), 1, output);
    for (size_t i = 0; i < matrix->RowCount; i++)
    {
        fwrite((matrix->Rows)[i], sizeof(int), matrix->ColumnCount, output);
    }
 
    fclose(output);

}
MatrixInteger* MatrixIntegerFread(const char* fileName)
{
    size_t n = 0, m = 0;
    MatrixInteger* res = NULL;
    FILE *input = NULL;

    input = fopen(fileName, "rb");
    if(AssertOpenFile(input) == ERROR_FILE_OPEN)
    {
        return NULL;
    }
 
    fread(&n, sizeof(size_t), 1, input);
    fread(&m, sizeof(size_t), 1, input);
    res = CreateMatrixInteger(n, m);

    AssertMatrixInteger(res);

    for (size_t i = 0; i < n; i++)
    {
        fread((res->Rows)[i], sizeof(int), m, input);
    }
 
    fclose(input);

    return res;
}

MatrixInteger* MatrixIntegerRand(size_t n, size_t m)
{
    MatrixInteger* res = CreateMatrixInteger(n, m);
    AssertMatrixInteger(res);

    srand(time(NULL));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            *( (res->Rows)[i] + j ) = rand() - RAND_MAX / 2;
        }
    }

    return res;
}

MatrixInteger* InsertRowMatrixInteger(MatrixInteger* matrix, int* row, size_t m, size_t i)
{
    AssertMatrixInteger(matrix);

    assert(row);
    assert(matrix->ColumnCount == m);
    assert(i <= matrix->RowCount + 1);

    MatrixInteger* res = CreateMatrixInteger(matrix->RowCount + 1, m);
    AssertMatrixInteger(res);

    for (size_t j = 0, k = 0; j < matrix->RowCount; j++, k++)
    {
        if (j == i)
        {
            memcpy((res->Rows)[k], row, sizeof(int) * m);
            k++;
        }
        memcpy((res->Rows)[k], (matrix->Rows)[j], sizeof(int) * m);
    }
    
    return res;
}
MatrixInteger* InsertColumnMatrixInteger(MatrixInteger* matrix, int* column, size_t n, size_t j)
{
    AssertMatrixInteger(matrix);

    assert(column);
    assert(matrix->RowCount == n);
    assert(j <= matrix->ColumnCount + 1);

    MatrixInteger* res = CreateMatrixInteger(n, matrix->ColumnCount + 1);
    AssertMatrixInteger(res);

    for (size_t i = 0; i < res->RowCount; i++)
    {
        memcpy((res->Rows)[i], (matrix->Rows)[i], sizeof(int) * j);
        memcpy((res->Rows)[i] + j, column + i, sizeof(int));
        memcpy((res->Rows)[i] + j + 1, (matrix->Rows)[i] + j, sizeof(int) * (matrix->ColumnCount - j) );
    }
    
    return res;
}

MatrixInteger* EraseRowMatrixInteger(MatrixInteger* matrix, size_t i)
{
    AssertMatrixInteger(matrix);
    assert(i < matrix->RowCount);

    MatrixInteger* res = CreateMatrixInteger(matrix->RowCount - 1, matrix->ColumnCount);
    AssertMatrixInteger(res);

    for (size_t j = 0, k = 0; j < res->RowCount; j++, k++)
    {
        if (j == i)
        {
            k++;
        }
        memcpy((res->Rows)[j], (matrix->Rows)[k], sizeof(int) * matrix->ColumnCount);
    }
    
    return res;
}
MatrixInteger* EraseColumnMatrixInteger(MatrixInteger* matrix, size_t j)
{
    AssertMatrixInteger(matrix);
    assert(j < matrix->ColumnCount);

    MatrixInteger* res = CreateMatrixInteger(matrix->RowCount, matrix->ColumnCount - 1);
    AssertMatrixInteger(res);

    for (size_t i = 0; i < res->RowCount; i++)
    {
        memcpy((res->Rows)[i], (matrix->Rows)[i], sizeof(int) * j);
        memcpy((res->Rows)[i] + j, (matrix->Rows)[i] + j + 1, sizeof(int) * (matrix->ColumnCount - j - 1) );
    }
    
    return res;
}