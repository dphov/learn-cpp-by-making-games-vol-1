//
// Created by Dmitry Petukhov on 21/01/2020.
//

#include <iostream>
#include <cstring>

using namespace std;

struct DynamicArray_Untyped
{
  uint32_t count;
  uint32_t capacity;
  void *data;

};

template <typename T>
struct DynamicArray
{
  uint32_t count;
  uint32_t capacity;

  T *data;

  inline T& operator[](const int index) const
  {
      return data[index];
  }
};

template <typename T>
DynamicArray<T> MakeDynamicArray(uint32_t capacity = 0)
{
    DynamicArray<T> array = {};
    array.count = 0;
    array.capacity = capacity;

    if (capacity > 0)
        array.data = (T *)malloc(sizeof(T) * capacity);

    return  array;
}

template <typename T>
void DeallocateDynamicArray(DynamicArray<T> *array)
{
    if (array->capacity > 0)
        free(array->data);
    array->count = 0;
    array->capacity = 0;
    array->data = nullptr;
}

template <typename T>
DynamicArray<T> CopyDynamicArray(DynamicArray<T> *array)
{
    DynamicArray<T> result = MakeDynamicArray<T>(array->capacity);
    result.count = array->count;
    memcpy(result.data, array->data, sizeof(T) * array->capacity);

    return result;
}

inline void DynamicArrayEnsureCapacity(DynamicArray_Untyped *array, uint32_t capacity, uint32_t elementSize)
{
    if (array->capacity < capacity)
    {
        uint32_t nextCapacity = array->capacity;
        if (nextCapacity == 0)
            nextCapacity = 1;

        while (capacity > nextCapacity)
            nextCapacity *= 2;

        if (array->capacity == 0)
            array->data = malloc(elementSize * nextCapacity);
        else
            array->data = realloc(array->data, elementSize * nextCapacity);
        array->capacity = nextCapacity;
    }
}

template <typename T>
inline  void  DynamicArrayEnsureCapacity(DynamicArray<T> *array, uint32_t capacity)
{
    DynamicArrayEnsureCapacity((DynamicArray_Untyped *) array, capacity, sizeof(T));
}

// drop this here I'm tired and have to go next

int main()
{
    return 0;
}