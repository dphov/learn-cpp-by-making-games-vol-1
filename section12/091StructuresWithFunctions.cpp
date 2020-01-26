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

	cout << "The size of an integer is: " << sizeof(int) << endl;
	cout << "The size of BookType: " << sizeof(BookType) << endl;

	Func(aBook);

    return 0;
}

void Func(const BookType& book)
{

}
