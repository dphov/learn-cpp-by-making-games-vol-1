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

int main()
{
	BookType aBook;

	aBook.bookId = 1000;
	strcpy(aBook.title, "A Tale of Two Cities");
	strcpy(aBook.author, "Charles Dickens");
	aBook.year = 1859;
	aBook.price = 19.99;

	BookType books[10];

	books[0].bookId = 1001;
	//...

    return 0;
}
