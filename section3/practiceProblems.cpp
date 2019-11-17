//
// Created by Dmitry Petukhov on 2019-08-20.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>


using namespace std;

// Problem 1: Write a program to input number of days from user
// and convert it to years, weeks and days. Ignore leap years.
void problem1()
{
  int theDays;

  cout << "Please enter number of days: ";
  cin >> theDays;
  cout << "The Number of years: " << theDays / 365 << endl;
  cout << "The Number of weeks: " << theDays / 7 << endl;
  cout << "The number of days: " << theDays % 365 << endl;
}

// Problem 2: Write a program that takes a floating point number
// and outputs the minimum amount of currency denominations
// needed to make up that number.
// Eg. If the user input 45.78 then the output would be:
//
//4 ten dollar bills
//1 five dollar bills
//0 two dollar bills
//0 one dollar bills
//3 twenty five cent pieces
//0 ten cent pieces
//0 five cent pieces
//3 one cent pieces
void problem2()
{
  float input = 45.78;
  float calcF;

  std::vector<int> v(8);

  calcF = int(floor(input)) / 10 ;
  input -= calcF * 10;
  v[0] = calcF;
  calcF = 0;
  cout << (v[0]) << " ten dollar bills" << endl;

  calcF = int(floor(ceilf(input *100)/100)) / 5 ;//int(floor(input)) / 5 ;
  input -= calcF * 5;
  v[1] = (calcF);
  calcF = 0;
  cout << (v[1]) << " five dollar bills" << endl;

  calcF = int(floor(ceilf(input * 100)/100)) / 2 ;
  input -= calcF * 2;
  v[2] = (calcF);
  calcF = 0;
  cout << (v[2]) << " two dollar bills" << endl;

  calcF = int(floor(ceilf(input * 100)/100));
  input -= calcF;
  v[3] = (calcF);
  calcF = 0;
  cout << (v[3]) << " one dollar bills" << endl;

  calcF = floor(ceilf(input * 100)/100 / 0.25) ;
  input -= calcF * 0.25 ;
  v[4] = (calcF);
  calcF = 0;
  cout << (v[4]) << " twenty five cent pieces" << endl;

  calcF = floor(ceilf(input * 100)/100 / 0.10);
  input -= calcF * 0.10;
  v[5] = (calcF);
  calcF = 0;
  cout << (v[5]) << " ten cent pieces" << endl;

  calcF = floor(ceilf(input * 100)/100 / 0.05);
  input -= calcF * 0.05;
  v[6] = (calcF);
  calcF = 0;
  cout << (v[6]) << " five cent pieces" << endl;

  calcF = ceilf(input * 100)/100 / 0.01;
  input -= calcF;
  v[7] = (calcF);
  calcF = 0;
  cout << (v[7]) << " one cent pieces" << endl;
}

// Problem 3: Write a program that takes in a number of seconds
// and outputs the time in this format:
// hh::mm::ss where
// hh is the hours,
// mm is the minutes,
// and ss is the seconds.
void problem3()
{
  int seconds = 86400;

  std::vector<int> time(2);

  if (seconds > 3600) {
    time[0] = (seconds / 3600);
    seconds -= time[0] * 3600;
  }

  if (seconds > 60) {
    time[1] = (seconds / 60);
    seconds -= time[1] * 60;
  }

  time[2] = seconds;

  cout << setw(2) << setfill('0') << time[0] << ":";
  cout << setw(2) << setfill('0') << time[1] << ":";
  cout << setw(2) << setfill('0') << time[2] << endl;

}

int main()
{
  problem3();
  return 0;
}
