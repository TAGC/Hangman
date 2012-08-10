// Hangman.h - written by Tag.

#include "HangmanUtil.h"
#include "LinkedList.h"

const int MAX_CHANCES = 6;

class Hangman
{
public:
	Hangman();
	~Hangman();

	int  getChances()const;
	void getLettersGuessed(bool out[26])const;
	bool checkGameOver()const;
	void guessLetter(char letter);
	void run();
	
private:
	void printHangman()const;
	void printWord()const;
	bool letterInHiddenWord(char letter)const;
	void chooseHiddenWord();
	void decrementChances();
	bool isLetterGuessed(char letter)const;

	int  chances; // Initially should be MAX_CHANCES.
	bool lettersGuessed[26];
	string hiddenWord;
};