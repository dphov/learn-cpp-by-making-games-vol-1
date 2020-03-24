#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;
/*
 * Problem: Pig Latin takes the first consonant (or consonant cluster) of an English word,
 * moves it to the end of the word and suffixes an ay,
 * or if a word begins with a vowel you just add way to the end.
 * For example,
 * pig becomes igpay,
 * banana becomes ananabay,
 * and aadvark becomes aadvarkway.
 * Write a function that uses strings called PigLatinify
 * that takes in a c++ string and returns the Pig Latin version.
 *
 *
 * why pig blaster
 * ywhay igpay asterblay
 *
 * For words that begin with consonant sounds, all letters before the initial vowel are placed at the end of the word sequence.
 * Then, "ay" is added, as in the following examples:[12]

    "pig" = "igpay"
    "latin" = "atinlay"
    "banana" = "ananabay"
    "happy" = "appyhay"
    "duck" = "uckday"
    "me" = "emay"
    "too" = "ootay"
    ”bagel” = “agelbay”

When words begin with consonant clusters (multiple consonants that form one sound), the whole sound is added to the end when speaking or writing.[13]

    "smile" = "ilesmay"
    "string" = "ingstray"
    "stupid" = "upidstay"
    "glove" = "oveglay"
    "trash" = "ashtray"
    "floor"= "oorflay"
    "store"= "orestay"

For words that begin with vowel sounds, one just adds "way" or "yay" to the end (or just "ay"). Examples are:

    "eat" = "eatway" or "eatay"
    "omelet" = "omeletway" or "omeletay"
    "are" = "areway" or "areay"
    "egg" = "eggway" or "eggay"
    "explain" = "explainway"
    "always" = "alwaysway" or "alwaysay"
    "ends" = "endsway" or "endsay"
    "honest" = "honestway"
    "I"= "Iway"

An alternative convention for words beginning with vowel sounds, one removes the initial vowel(s) along with the first consonant or consonant cluster.
 [citation needed] This usually only works for words with more than one syllable and offers a variant of the words in keeping with the mysterious,
 unrecognizable sounds of the converted words. Examples are:

    "every" = "eryevay"
    "another" = "otheranay"
    "under" = "erunday"
    "island" = "andislay"
    "elegant" = "egantelay"

Sentence structure remains the same as it would in English. Pronunciation of some words may be a little difficult for beginners, but people can easily understand Pig Latin with practice.
 */
string PigLatinify(string & nonPigLatinString);
int main()
{

    string myString;

    GetString("Please enter english word: ", "Error, please try again", myString);
    PigLatinify(myString);
    if(myString.size() > 0 )
    {
        cout << "Pig latin Equivalent is: " << myString << endl;
    }

    return 0;
}

string PigLatinify(string & nonPigLatinString)
{
    char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };

    for( int i = 0; i < nonPigLatinString.size(); i++)
    {

    }

    return nonPigLatinString;
}