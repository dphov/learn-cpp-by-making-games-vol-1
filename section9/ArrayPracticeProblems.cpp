#include <iostream>
#include <cctype>
#include <string.h>
#include <new>


using namespace std;

const int IGNORE_CHARS = 256;

void CStringReverser(char * cstring, int cstringLength);
int CStringLength(const char * aString);
void CopyFromTo(char *copyString, int copyStringLength, char *outputArray);
void InsertElementAtPositionInArray(int elem, int elemPos, int *arr, int arrLen);
void DeleteElementAtPositionInArray(int i, int *pInt, size_t i1);

int main()
{
    /*
     * Problem 1: Write a function that will reverse a C String.
     * For example if the string was "Hello" it should be reversed to "olleH"

     */
//    char input[] = "Hello";
//    char input[] = "D";
//    CStringReverser(input, CStringLength(input));

//    cout << "Reversed string is: " << input << endl;

    /*
     * Problem 2: Write a program to read element in array
     * and copy all elements of first array into second array
     */
//
//    char inputStr[] = "Hello";
//    char secondArray[] = {};
//    char *ptr = secondArray;
//
//    CopyFromTo(inputStr, CStringLength(inputStr), ptr);
//    cout << secondArray << endl;


    /*
     * Problem 3: Write a program to insert an element
     * in array at specified position.
     *
     * Example:
     * If the elements of array are: 10, 20, 30, 40, 50
     * After inserting 25 at position 3
     * Elements of array are: 10, 20, 25, 30, 40, 50
     */
//    cout << "example input: 10, 20, 30, 40, 50"<<  endl;
//    int arr[] = {10, 20, 30, 40, 50};
//    int *arrPtr = arr;
//
//    InsertElementAtPositionInArray(25, 2, arrPtr, sizeof(arr)/sizeof(*arr));
//    cout << "example output: 10, 20, 25, 30, 40, 50"<<  endl;

    /*
     *
     *  Problem 4: Write a program to delete an element from an array at specified position.
     *  The program should also print an error message if the delete position is invalid.
     *  There should be no empty elements between the numbers.
        Example:
        If the array elements are - 10, 20, 30, 40, 50
        After deleting element at position 2
        Elements of array - 10, 30, 40, 50
     */
    int arr[] = {10, 20, 30, 40, 50};
    int *arrPtr = arr;

    cout << "example input: 10, 20, 30, 40, 50"<<  endl;
    DeleteElementAtPositionInArray(2, arrPtr, sizeof(arr)/sizeof(*arr));

    cout << "example output: 10, 30, 40, 50"<<  endl;

    return 0;
}

void PrintArray(const int arr[], const int size)
// this function prints the contents of the array
{
    cout << "\nThe array:\n { ";
    for (int i = 0; i < size - 1; i++)	// print all but last item
        cout << arr[i] << ", ";
    cout << arr[size - 1] << " }\n";	// print last item
}

void DeleteElementAtPositionInArray(int indexToDelete, int *arr, size_t arrSize)
{
    if (indexToDelete > arrSize || indexToDelete < 0) {
        cout << "non existant index" << endl;
        return;
    }

    for (int i = indexToDelete; i < arrSize; ++i)
        arr[i]= arr[i+1];
    PrintArray(arr, arrSize-1);


}

void InsertElementAtPositionInArray(int elem, int elemPos, int *arr, int arrLen)
{
    int NEW_SIZE= arrLen + 1;
    int *newArr = new int[NEW_SIZE];
    memcpy(newArr, arr, (NEW_SIZE) * sizeof(int));

    for (int i = NEW_SIZE - 1; i > elemPos ; i--)
    {
        newArr[i] = arr[i-1];

    }
//    delete arr[];
    newArr[elemPos] = elem;
    PrintArray(newArr, NEW_SIZE);
}




//void CopyFromTo(char *copyString, int copyStringLength, char *outputArray)
//{
//    for(int i = 0; i < copyStringLength; i++)
//    {
//        outputArray[i] = copyString[i];
//    }
//}

//
//void CStringReverser(char * cstring, int cstringLength)
//{
//    char temp;
//    int optimalCalculationSteps = 0;
//    int isOdd = cstringLength % 2;
//    if (cstringLength < 2) {
//        return;
//    }
//    if (cstringLength == 2) {
//        temp = cstring[0];
//        cstring[0] = cstring[1];
//        cstring[1] = temp;
//    } else
//    {
//        for(int i = 0; i < (cstringLength) / 2 + isOdd; i++)
//        {
//            temp = cstring[i];
//            cstring[i] = cstring[cstringLength - (i + 1)];
//            cstring[cstringLength - (i + 1)] = temp;
//        }
//    }
//}
//
int CStringLength(const char * aString)
{
    int length = 0;
    const char* p = aString;

    if (aString != nullptr)
    {
        while (*p != '\0')
        {
            length++;
            p++;
        }
    }
    return length;
}
void CopyFromTo(char *input, int inputArrLen, char *&output)
{

}
