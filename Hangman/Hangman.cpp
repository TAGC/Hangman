#include "Hangman.h"

Hangman::Hangman()
{
	chances = MAX_CHANCES;
	for(int i=0; i < 26; i++)
	{
		lettersGuessed[i] = false;
	}
}

Hangman::~Hangman()
{
	delete[] &lettersGuessed;
}

int Hangman::getChances()const
{
	return chances;
}

void Hangman::getLettersGuessed(bool out[26])const
{
	for(int i=0; i < 26; i++)
	{
		out[i] = lettersGuessed[i];
	}
}

// Incomplete.
bool Hangman::checkGameOver()const
{
	if(!chances)
	{
		printHangman();
		cout << "Unlucky, you lost this round. ";
		cout << "The word was " << hiddenWord << endl;
		return true;
	}
	
	for(int i=0; i < (int)hiddenWord.length(); i++)
	{
		if(!isLetterGuessed(hiddenWord[i])) 
		{
			return false;
		}
	}

	cout << "Congratulations, you win!\n";
	return true;
}

// PRE: 'letter' is an actual lower-case letter from the alphabet.
bool Hangman::isLetterGuessed(char letter)const
{
	return lettersGuessed[letter-ALPHABET_START];
}

//POST: 'chances' >= 0
void Hangman::decrementChances()
{
	chances <= 0 ? chances = 0 : chances--;
}

//PRE: 'letter' is a valid lower-case letter from the alphabet.
void Hangman::guessLetter(char letter)
{
	int chancesLeft;

	if(isLetterGuessed(letter))
	{
		cout << letter << " has already been guessed.\n";
		return;
	}

	// Reflect that letter has now been guessed.
	lettersGuessed[letter-ALPHABET_START] = true;

	if(!letterInHiddenWord(letter))
	{
		decrementChances();
		
		chancesLeft = getChances();
		
		if(chancesLeft > 0)
		{
			cout << "You have " << chancesLeft << " chances remaining.\n";
		}
	}
}

void Hangman::chooseHiddenWord()
{
	LinkedList* wordlist = new LinkedList();
	readFile("wordlist.txt", wordlist);
	hiddenWord = wordlist->getRandomNodeValue();
}

bool Hangman::letterInHiddenWord(char letter)const
{
	for(int i=0; i < (int)hiddenWord.length(); i++)
	{
		if(letter == hiddenWord[i]) return true;
	}

	return false;
}

// Incomplete.
void Hangman::printHangman()const
{
	cout << endl;

	switch(getChances())
	{
	case 6:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |       " << endl;
		cout << "       |       " << endl;
		cout << "       |       " << endl;
		cout << "       |       " << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	case 5:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |     O " << endl;
		cout << "       |       " << endl;
		cout << "       |       " << endl;
		cout << "       |       " << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	case 4:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |     O " << endl;
		cout << "       |     I " << endl;
		cout << "       |     o " << endl;
		cout << "       |       " << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	case 3:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |     O " << endl;
		cout << "       |    \\I" << endl;
		cout << "       |     o " << endl;
		cout << "       |       " << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	case 2:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |     O " << endl;
		cout << "       |    \\I/" << endl;
		cout << "       |     o " << endl;
		cout << "       |       " << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	case 1:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |     O " << endl;
		cout << "       |    \\I/" << endl;
		cout << "       |     o " << endl;
		cout << "       |    /  " << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	case 0:
		cout << "       ______  " << endl;
		cout << "       |     | " << endl;
		cout << "       |     O " << endl;
		cout << "       |    \\I/" << endl;
		cout << "       |     o " << endl;
		cout << "       |    / \\" << endl;
		cout << "  _____|______ " << endl;
		cout << " /_____=_____/ " << endl;
		break;

	default:
		cout << "Unexpected value of chance\n";
	}
}

void Hangman::printWord()const
{
	char letter;

	for(int i=0; i < (int)hiddenWord.length(); i++)
	{
		if(isLetterGuessed(hiddenWord[i]))
		{
			letter = hiddenWord[i];
		}
		else
		{
			letter = '_';
		}

		cout << letter << " ";
	}

	cout << endl;
}

void Hangman::run()
{
	char letter;

	chooseHiddenWord();
	
	while(!checkGameOver())
	{
		printWord();
		printHangman();

		do {
			cout << "\nGuess a letter (a-z): ";
			letter = getchar();
		} while(!checkLowerCaseLetter(letter));

		getchar();

		cout << endl;
		guessLetter(letter);
	}
}

int main(int argc, char argv[])
{
	Hangman* game = new Hangman();
	game->run();
	system("PAUSE");
	return 0;
}