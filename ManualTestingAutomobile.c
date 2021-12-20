#include "ManualTestingAutomobile.h"

typedef enum Menu Menu;
typedef enum ErrorCodes ErrorCodes;

int main()
{
    AutomoblieMenu();
    return 0;
}

void AutomobilePrintf(Automobile* automobile)
{
    AutomobileAssert(automobile);
    printf("Brand: %s \t| Owner: %-64s | Mileage: %4.3f\n", automobile->Brand, automobile->OwnerFullName, automobile->Mileage);
    // Magic number 64 = MAXNAMESIZE from Automobile.h
    // Magic number 5 = count of numbers in MAXMILEAGE + 1 from Automobile.h
}
Automobile* AutomobileScanf(size_t n, size_t m)
{
    Automobile* res = AutomobileNew();
    AutomobileAssert(res);

    printf("Print Brand %d char or less: ", BRANDSIZE - 1);
    scanf("%s", res->Brand);
    while (AutomobileAssertUI(res) == BadBrand)
    {
        printf("Incorrect input!\nPrint Brand %d char or less: ", BRANDSIZE - 1);
        scanf("%s", res->Brand);
    }
    printf("Print OwnerFullName: ");
    res->OwnerFullName = get_str();
    while (res->OwnerFullName == NULL)
    {
        printf("Incorrect input!\nPrint OwnerFullName: ");
        res->OwnerFullName = get_str();
    }
    printf("Print Mileage: ");
    scanf("%f", &(res->Mileage));
    while (AutomobileAssertUI(res) == BadMileage)
    {
        printf("Incorrect input!\nPrint Mileage: ");
        scanf("%f", &(res->Mileage));
    }

    if(AutomobileAssertUI(res) != OK)
    {
        printf("Fail to enter automobile");
        return NULL;
    }

    return res;
}
bool AutomobileBrendAssertUI(char* brand)
{
    bool res = true;
    for (int i = 0; i < BRANDSIZE; i++)
    {
        res &= IsCharBrand(brand + i);
        if(res == false)
        {
            return false;
        }
    }
    return true;

}
int AutomobileAssertUI(Automobile* automobile)
{
    if(automobile == NULL) 
    {
        return NoData;
    } 
    else if (AutomobileBrendAssertUI(automobile->Brand) == false)
    {
        return BadBrand;
    }
    else if (automobile->Mileage < 0.0 )
    {
        return BadMileage;
    }
    
    return OK;
}
void AutomobileArrayAssertUI(Automobile** arr, size_t n, const char* name)
{
    if(errorNoDataInAutomobileArray(arr) == NoData)
    {
        return;
    }

    ErrorCodes err;

    for (size_t i = 0; i < n; i++)
    {
        err = AutomobileAssertUI(arr[i]);
        if(err != OK)
        {
            printf("Ошибка среди автомобилей %s в позиции %ld не корректный автомобиль!\n", name, i);
            scanf("%*c");
            return;
        }

    }

}

void AutomoblieMenu()
{
    Menu menu = SHOW;
    int ui;
    Automobile** source = NULL, ** automobiles = NULL;
    size_t sourceN = 0, automobilesN = 0;
    time_t t0 = 0, t1 = 0;

    while (menu == SHOW)
    {
        printf("\nНажмите любую клавишу\n");
        scanf("%*c");
        system("clear");
        printf("***Выберите вариант***");
        printOptionsAutomoblieMenu();
        scanf("%d%*c", &ui);
        system("clear");
        t0 = time(NULL);
        switch (ui)
        {
        case RandomGenerate:
            source = deleteAutomobileArray(source, sourceN);
            source = RandomGenerateAutomobiles(&sourceN);
            break;
        case WriteSourceInConsole:
            WriteAutomobileArrayInConsole(source, sourceN, "исходная");
            break;
        case WriteResultInConsole:
            WriteAutomobileArrayInConsole(automobiles, automobilesN, "обработанная");
            break;
        case MenuBubbleSort:
            automobiles = deleteAutomobileArray(automobiles, automobilesN);
            automobiles = AutomobileBubbleSort(source, sourceN);
            automobilesN = sourceN;
            printf("Автомобили удачно отсортированны %s\n", "BubbleSort");
            break;
        case MenuInsertionSort:
            automobiles = deleteAutomobileArray(automobiles, automobilesN);
            automobiles = AutomobileInsertionSort(source, sourceN);
            automobilesN = sourceN;
            printf("Автомобили удачно отсортированны %s\n", "InsertionSort");
            break;
        case MenuSelectionSort:
            automobiles = deleteAutomobileArray(automobiles, automobilesN);
            automobiles = AutomobileSelectionSort(source, sourceN);
            automobilesN = sourceN;
            printf("Автомобили удачно отсортированны %s\n", "SelectionSort");
            break;
        case EXIT:
            menu = EXIT;
            break;
        default:
            printf("Нет такого варианта!\n");
            break;
        }
        t1 = time(NULL);
        printf("Операция заняла %ld секунд", t1 - t0);
    }
    automobiles = deleteAutomobileArray(automobiles, automobilesN);
    source = deleteAutomobileArray(source, sourceN);
    printf("\n");

}

void printOptionsAutomoblieMenu()
{
    printf("\n0. Выйти из программы\n");
    // printf("1. Ввести исходные автомобили из стандартного потока\n");
    // printf("2. Ввести исходные автомобили из бинарного файла\n");
    printf("1. Случайные исходные автомобили\n");

    printf("2. Исходные автомобили\n");
    printf("3. Результат\n");
    // printf("6. Сохранить исходные автомобили\n");
    // printf("7. Сохранить результат\n");

    printf("4. Пузырьковая сортировка\n");
    printf("5. Сортировка вставками\n");
    printf("6. Сортировка выбором\n");
}
// Automobile**  ReadAutomobilesFromConsole();
// Automobile**  ReadAutomobilesFromBinaryFile();
Automobile**  RandomGenerateAutomobiles(size_t* n)
{
    printf("Введите n: ");
    scanf("%u", (unsigned int*)n);

    return AutomobileArrayNewRand(*n);
}

void WriteAutomobileArrayInConsole(Automobile** arr, size_t n, const char* name)
{
    if(errorNoDataInAutomobileArray(arr) == NoData)
    {
        return;
    }

    AutomobileArrayAssertUI(arr, n, name);

    printf("Автомобили %s:\n", name);
    
    for (int i = 0; i < n; i++)
    {
        AutomobilePrintf(arr[i]);
    }
    
}
// void WriteAutomobileArrayInBinaryFile(Automobile** arr, size_t n, const char* name);
int errorNoDataInAutomobileArray(Automobile** arr)
{
    if (arr == NULL)
    {
        printf("Ошибка! Вы не ввели автомобили!\n");
        scanf("%*c");
        return NoData;
    }
    return OK;
}

void* deleteAutomobileArray(Automobile** arr, size_t n)
{
    if(arr != NULL)
    {
        AutomobileArrayFree(arr, n);
    }

    return NULL;
}
