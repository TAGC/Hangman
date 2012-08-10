// HangmanUtil.h - written by Tag.
// Provides utility functions / values.

#ifndef HANGMANUTIL_H
#define HANGMANUTIL_H

#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "LinkedList.h"
class LinkedList;

const char ALPHABET_START = 'a';

void readFile(string filename, LinkedList* stringList);
bool checkLowerCaseLetter(char character);

#endif

