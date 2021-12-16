#include "LW5Y1S1.h"

#define MaxFileNameSize 80

typedef enum Menu Menu;
typedef enum LW5Y1S1Codes LW5Y1S1Codes;
typedef enum ErrorCodes ErrorCodes;
typedef struct MatrixInteger MatrixInteger;

int main()
{
    LW5Y1S1();
    return 0;
}

void LW5Y1S1()
{
    Menu menu = SHOW;
    int ui;
    MatrixInteger* source = NULL, * matrix = NULL;

    while (menu == SHOW)
    {
        printf("\nНажмите любую клавишу\n");
        scanf("%*c");
        system("clear");
        printf("***Выберите вариант***");
        printOptionsLW5Y1S1();
        scanf("%d%*c", &ui);
        system("clear");
        switch (ui)
        {
        case ReadFromConsole:
            source = delOldMatrixInteger(source);
            source = ReadMatrixIntegerFromConsole();
            break;
        case ReadFromBinaryFile:
            source = delOldMatrixInteger(source);
            source = ReadMatrixIntegerFromBinaryFile();
            break;
        case RandomGenerate:
            source = delOldMatrixInteger(source);
            source = RandomGenerateMatrixInteger();
            break;
        case WriteSourceInConsole:
            WriteMatrixIntegerInConsole(source, "исходная");
            break;
        case WriteResultInConsole:
            WriteMatrixIntegerInConsole(matrix, "обработанная");
            break;
        case WriteSourceInBinaryFile:
            WriteMatrixIntegerInBinaryFile(source, "исходная");
            break;
        case WriteResulInBinaryFile:
            WriteMatrixIntegerInBinaryFile(source, "обработанная");
            break;
        case InsertRow:
            matrix = delOldMatrixInteger(matrix);
            matrix = InsertRowMenu(source);
            break;
        case InsertColumn:
            matrix = delOldMatrixInteger(matrix);
            matrix = InsertColumnMenu(source);
            break;
        case EraseRow:
            matrix = delOldMatrixInteger(matrix);
            matrix = EraseRowMenu(source);
            break;
        case EraseColumn:
            matrix = delOldMatrixInteger(matrix);
            matrix = EraseColumnMenu(source);
            break;
        case EXIT:
            menu = EXIT;
            break;
        default:
            printf("Нет такого варианта!\n");
            break;
        }
    }

    matrix = delOldMatrixInteger(matrix);
    source = delOldMatrixInteger(source);

    
}

void printOptionsLW5Y1S1()
{
    printf("\n0. Выйти из программы\n");
    printf("1. Ввести исходную матрицу из стандартного потока\n");
    printf("2. Ввести исходную матрицу из бинарного файла\n");
    printf("3. Случайная исходная матрица\n");

    printf("4. Исходная матрица\n");
    printf("5. Результат\n");
    printf("6. Сохранить исходную матрицу\n");
    printf("7. Сохранить результат\n");

    printf("8. Вставить строку\n");
    printf("9. Вставить столбец\n");
    printf("10. Удалить строку\n");
    printf("11. Удалить столбец\n");

}
MatrixInteger*  ReadMatrixIntegerFromConsole()
{
    int n, m;
    printf("Введите n: ");
    scanf("%u", &n);
    printf("\nВведите m: ");
    scanf("%u", &m);

    if(errorSizeMatrix(n, m) == BadSize)
    {
        return NULL;
    }

    printf("\nВведите матрицу: ");
    return MatrixIntegerScanf(n, m);
}
MatrixInteger*  ReadMatrixIntegerFromBinaryFile()
{
    char nameOfFile[MaxFileNameSize];
    printf("Введите название файла: ");
    scanf("%s", nameOfFile);
    return MatrixIntegerFread(nameOfFile);
}
MatrixInteger*  RandomGenerateMatrixInteger()
{
    int n, m;
    printf("Введите n: ");
    scanf("%u", &n);
    printf("\nВведите m: ");
    scanf("%u", &m);

    if(errorSizeMatrix(n, m) == BadSize)
    {
        return NULL;
    }

    return MatrixIntegerRand(n, m);
}

void WriteMatrixIntegerInConsole(MatrixInteger* matrix, const char* matrixName)
{
    if(errorNoData(matrix) == NoData)
    {
        return;
    }

    printf("Матрица %s:\n", matrixName);
    MatrixIntegerPrintf(matrix);

}
void WriteMatrixIntegerInBinaryFile(MatrixInteger* matrix, const char* matrixName)
{
    if(errorNoData(matrix) == NoData)
    {
        return;
    }
    
    char nameOfFile[MaxFileNameSize];

    printf("Введите название файла: ");
    scanf("%s", nameOfFile);

    MatrixIntegerFwrite(matrix, nameOfFile);
    printf("Матрица %s успешно сохранена в файл %s\n", matrixName, nameOfFile);
}

MatrixInteger*  InsertRowMenu(MatrixInteger* matrix)
{
    if(errorNoData(matrix) == NoData)
    {
        return NULL;
    }

    int i;
    int* row = NULL;
    size_t m = matrix->ColumnCount;
    printf("Введите индекс строки: ");
    scanf("%d", &i);
    i--;

    if(errorNoIndex(i, matrix->RowCount) == NotIndex)
    {
        return NULL;
    }

    row = (int*) malloc(sizeof(int) * m);
    if(errorNoMemory(row) == NoMemory)
    {
        return NULL;
    }

    printf("\nВведите строку матрицы: ");
    fillArray(row, m);

    return InsertRowMatrixInteger(matrix, row, m, i);
}
MatrixInteger*  InsertColumnMenu(MatrixInteger* matrix)
{
    if(errorNoData(matrix) == NoData)
    {
        return NULL;
    }

    int j;
    int* column = NULL;
    size_t n = matrix->RowCount;
    printf("Введите индекс столбца: ");
    scanf("%d", &j);
    j--;

    if(errorNoIndex(j, matrix->ColumnCount) == NotIndex)
    {
        return NULL;
    }

    column = (int*) malloc(sizeof(int) * n);
    if(errorNoMemory(column) == NoMemory)
    {
        return NULL;
    }

    printf("\nВведите столбец матрицы: ");
    fillArray(column, n);

    return InsertColumnMatrixInteger(matrix, column, n, j);
}
MatrixInteger*  EraseRowMenu(MatrixInteger* matrix)
{
    if(errorNoData(matrix) == NoData)
    {
        return NULL;
    }

    int i;
    size_t m = matrix->ColumnCount;
    printf("Введите индекс строки: ");
    scanf("%d", &i);
    i--;

    if(errorNoIndex(i, matrix->RowCount) == NotIndex)
    {
        return NULL;
    }

    return EraseRowMatrixInteger(matrix, i);
}
MatrixInteger*  EraseColumnMenu(MatrixInteger* matrix)
{
    if(errorNoData(matrix) == NoData)
    {
        return NULL;
    }

    int j;
    size_t n = matrix->RowCount;
    printf("Введите индекс столбца: ");
    scanf("%d", &j);
    j--;

    if(errorNoIndex(j, matrix->ColumnCount) == NotIndex)
    {
        return NULL;
    }

    return EraseColumnMatrixInteger(matrix, j);
}

int errorNoData(MatrixInteger* matrix)
{
    if (matrix == NULL)
    {
        printf("Ошибка! Вы не ввели матрицу!\n");
        scanf("%*c");
        return NoData;
    }
    return OK;
}
int errorNoIndex(size_t index, size_t max)
{
    if (index >= 0 && index > max)
    {
        printf("Ошибка! Вы ввели не существующий индекс!\n");
        scanf("%*c");
        return NotIndex;
    }
    return OK;
}
int errorNoMemory(void* ptr)
{
    if (ptr == NULL)
    {
        printf("Ошибка! Недостаточно памяти!\n");
        scanf("%*c");
        return NoMemory;
    }
    return OK;
}
int errorSizeMatrix(int n, int m)
{
    if (n < 0 || m < 0)
    {
        printf("Ошибка! Количестов строк и столюбцов должны быть не отрицательными!\n");
        scanf("%*c");
        return BadSize;
    }
    return OK;
}

void fillArray(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }

}

void* delOldMatrixInteger(MatrixInteger* matrix)
{
    if(matrix != NULL)
    {
        FreeMatrixInteger(matrix);
    }

    return NULL;
}