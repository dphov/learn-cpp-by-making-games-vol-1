//
// Created by Dmitry Petukhov on 29/11/2019.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
 * Problem: Create a dynamic array of integers 
 */
int * CreateDynamicArray(int capacity, int &size);
void DeleteDynamicArray(int *dynamicArray, int &size);
void InsertElement(int *dynamicArray, int element, int &size, int capacity);
void DeleteElement(int *dynamicArray, int elementIndex, int &size);
void ResizeDynamicArray(int **dynamicArray, int newCapacity);

// Make sure there are no memory leaks anywhere in the code!

int main()
{
    int size = 0;

    int * nopArr = CreateDynamicArray(5, size);
    cout << &nopArr[0] << endl;
    cout << &nopArr[1] << endl;
    cout << &nopArr[2] << endl;
    cout << &nopArr[3] << endl;
    InsertElement(nopArr, 42, size, 4);
    InsertElement(nopArr, 41, size, 4);
    InsertElement(nopArr, 1337, size, 4);
    InsertElement(nopArr, 444, size, 4);
    InsertElement(nopArr, 999, size, 4);
    InsertElement(nopArr, 1000, size, 4);

    cout << nopArr[0] << endl;
    cout << nopArr[1] << endl;
    cout << nopArr[2] << endl;
    cout << nopArr[3] << endl;
    cout << nopArr[4] << endl;
    cout << nopArr[5] << endl;

    DeleteElement(nopArr, 4, size);
    DeleteElement(nopArr, 3, size);
    DeleteElement(nopArr, 2, size);
    DeleteElement(nopArr, 0, size);
    DeleteElement(nopArr, 0, size);
    DeleteElement(nopArr, 0, size);
    cout << nopArr[0] << endl;
    cout << nopArr[1] << endl;
    cout << nopArr[2] << endl;
    cout << nopArr[3] << endl;
    cout << nopArr[4] << endl;
    cout << nopArr[5] << endl;
    DeleteDynamicArray(nopArr, size);

    return 0;
}
/*
 * This will do the first creation of the dynamic array
 * based on the capacity passed in to the CreateDynamicArray function.
 * Size should be set to 0
 */
int *CreateDynamicArray(int capacity, int &size)
{

    int * opArr = new int[capacity];
    cout << "CreateDynamicArray: " << opArr << " with capacity: " << capacity << " and size: " << size << endl;

    return opArr;
}
/*
 * DeleteDynamicArray will actually delete the memory
 * created by CreateDynamicArray. Size should be set to 0
 */
void DeleteDynamicArray(int *dynamicArray, int &size)
{
    cout << "DeleteDynamicArray: " << dynamicArray << " with size: " << size  << endl;
    delete [] dynamicArray;
    dynamicArray = nullptr;
    size = 0;
}
/*
 * InsertElement will add a new element to the end of the array
 * and increase the size by 1.
 * If the size is greater than the capacity before we insert the element,
 * then we should call ResizeDynamicArray to increase the capacity by 2.
 * Then the element should be added.
 */
void InsertElement(int *dynamicArray, int element, int &size, int capacity)
{
    cout << "InsertElement " << element
        << " to: " << dynamicArray
        << " with size: "
        << size << " and capacity "
        << capacity << endl;

    if (size > capacity)
    {
        ResizeDynamicArray(&dynamicArray, capacity + 2);
    }
    cout << &dynamicArray << endl;
    dynamicArray[size] = element;
    cout << "InsertElement new element is added: " << dynamicArray[size];
    size += 1;
    cout << " new size " << size << endl;

}
/*
 * DeleteElement will remove the element at elementIndex.
 * There should be no empty spaces between elements.
 * The dynamic array should not be resized.
 */
void DeleteElement(int *dynamicArray, int elementIndex, int &size)
{
    if (size < 1)
        return;
    cout << "inside DeleteDynamicArray: " << dynamicArray
    << " delete by index: " << elementIndex
    << " with size: " << size << ". "
    << dynamicArray[elementIndex] << " will be deleted. ";

    dynamicArray[elementIndex] = 0;

    for (int i = 0; i < size; i++ )
    {
        if (i >= elementIndex)
            dynamicArray[i] = dynamicArray[i+1];
    }
    size -= 1;
    cout << size << " will be a new size" << endl;
}

/*
 * ResizeDynamicArray should resize the array to be newCapacity.
 * All the previous elements in the dynamic array should remain
 * in tact and in the order they were in beforehand.
 */
void ResizeDynamicArray(int **dynamicArray, int newCapacity)
{
    cout << "ResizeDynamicArray " << dynamicArray
         << " to newCapacity: " << newCapacity << endl;
    int * opArr = new int[newCapacity];
    memcpy(opArr, *dynamicArray, newCapacity * sizeof(int));

    dynamicArray = &opArr;
}
