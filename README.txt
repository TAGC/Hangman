Hangman

Simulates a game of Hangman by drawing words pseudo-randomly from a text file.

Uses a linked-list data structure approach to optimise heap memory usage.

In addition to the C++ code above, the following simple python script was used to extract words from an online webpage, which others reading may find useful:

#######

import urllib2
import re

def getWords():
    url = "http://www2.elc.polyu.edu.hk/cill/common2-5000words.htm"
    data = urllib2.urlopen(url).read()
    matches = re.findall('(?<=\')[a-zA-Z]+(?=\')', data)
    words = filter(lambda x:len(x) > 7, matches)
    return words

def saveWords(words, filepath):
    fo = open(filepath, "w");
    for word in words:
        word += "\n"
        fo.write(word.lower())
    fo.close()

def main():
    words = getWords()
    saveWords(words, "wordlist.txt")

if __name__ == '__main__':
    main()


########

Replace the url given with a different one to get a different set of words.