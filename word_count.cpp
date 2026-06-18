#include <iostream> // input and output library 'cout << '
#include <string> // string library
#include <map> // keeping data in order. -- sorted key value container
#include <sstream> // std::stringstream
#include <cctype> // std::tolower

using namespace std;

// read a line of text or paragraph from the user.
// removes punctuation while utilizing the function tolower
string theWord(string word) { // each word is a token
	string read = "";	// storing the characters that are read.
	for (char ch : word) {  // walking through and reading each character, one at a time.
		if (isalnum(ch)) { // is the character a letter or a digit?
			read += tolower(ch); // tolower modifies all letters to lowercase.
		}
	}
	return read;
}

// how many times does a single word appear in a sentence or line of text?
map<string, int> countingWords(string text) { // ruturns each word
	map<string, int> theCount; // each word is a key while each value is the words frequency
	stringstream ss(text); // wraps the sentance (words) into the stringstream
	string word; // sentance becomes individual words


	while (ss >> word) { // word = each token, or each word in a sentence.
		word = theWord(word); // theWord() strips puncutation
		if (!word.empty()) { 

			theCount[word]++;
		}
	}
	return theCount;
}


void displayFrequency(const map<string, int>& read) { // in c++ void prints as part of the function
	
	cout << "\nWord Count:\n"; 
	cout << "=============\n";
	
	for (auto pair : read) { //pair.first = the word || pair.second = the word count
		cout << pair.first << ": " << pair.second << endl; // the map function automatically
								   // keeps everything in alphabetical
								   // order
	}


}
// Displays the most frequently used word(s).
void displayFrequent(const map<string, int>& read) {
	int maxCount = 0;

	for (auto pair : read) {
		if (pair.second > maxCount) {
			maxCount = pair.second;
		}
	}

	cout << "\nThe Popular Word(s):\n";
	cout << "======================\n";
	
	for (auto pair : read) {
		if (pair.second == maxCount) {
			cout << pair.first << " ";
		}
	}
	cout << "\nCount: " << maxCount << endl;
}



int main() {
	string text;

	cout << "Write some text in the text field:\n";
	
	getline(cin, text); // getline reads the sentences and collects the words.

	map<string, int> theCount = countingWords(text);

	if (theCount.empty()) {
		cout << "\nNothing was Entered.\n";
		return 0;
	}
// final display of the words and their most frequent uses.
displayFrequency(theCount);
displayFrequent(theCount);
return 0;
}
