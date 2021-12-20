#include "Algorithm.h"

#define Swap(A, B) { intptr_t t = A; A = B; B = t; }

void bubbleSort(intptr_t* a, size_t n, bool (*greaterThanSign) (void*, void*) )
{
  int i, j;

  for (i = n - 1; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if ( greaterThanSign((void*)(a[j]), (void*)(a[j+1])) ) 
      {
        Swap(a[j], a[j+1]);
      }
    }
  }

}
void insertionSort(intptr_t* a, size_t n, bool (*greaterThanSign) (void*, void*) )
{
  int location;
  intptr_t newElement = 0;

  for (int i = 1; i < n; i++)
  {
    newElement = a[i];
    location = i - 1;
    while(location >= 0 && greaterThanSign((void*)(a[location]), (void*)(newElement)) )
    {
      a[location+1] = a[location];
      location = location - 1;
    }
    a[location+1] = newElement;
  }

}
void selectionSort(intptr_t* arr, size_t n, bool (*greaterThanSign) (void*, void*) )
{
  int min; // для поиска минимального элемента и для обмена
  intptr_t temp = 0;

  for (int i = 0; i < n - 1; i++) 
  {
    min = i; // запоминаем индекс текущего элемента
    // ищем минимальный элемент чтобы поместить на место i-ого
    for (int j = i + 1; j < n; j++)  // для остальных элементов после i-ого
    {
      if ( greaterThanSign((void*)(arr[min]), (void*)(arr[j])) ) // если элемент меньше минимального,
      {
        min = j;   // запоминаем его индекс в min
      }    
    }
    Swap(arr[min], arr[i]); // меняем местами i-ый и минимальный элементы
  }

}
