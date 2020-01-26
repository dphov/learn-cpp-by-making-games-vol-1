//
// Created by Dmitry Petukhov on 19/01/2020.
//

#include <iostream>
#include <cstring>
using namespace std;

struct BookType
{
    int bookId;
    char title[256];
    char author[256];
    int year;
    float price;
};

void Func(const BookType& book);
int main()
{
	BookType aBook;

	BookType * bookPtr = &aBook;

	BookType * optrBook = new BookType;


//    (*bookPtr).year = 1999;
    bookPtr->year = 1999;


	delete optrBook;

    return 0;
}

void Func(const BookType& book)
{

}
