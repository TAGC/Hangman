#include "HangmanUtil.h"

void readFile(string filename, LinkedList* stringList)
{
	string input;
	ifstream infile;
	infile.open(filename);
	while(!infile.eof())
	{
		getline(infile, input);
		stringList->addValue(input);
	}	
	infile.close();
}

bool checkLowerCaseLetter(char character)
{
	int charDif = character - ALPHABET_START;
	return charDif >= 0 && charDif <= 25;
}