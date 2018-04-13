#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std; 

void main() {
	map<char,string> morse_txt; //create map
	ifstream istream; //create istream to read in morse.txt file
	istream.open("morse.txt");

	while (!istream.eof()) {
		string s1; 
		getline(istream, s1); //read line and insert into string
		char key = s1[0]; //first index is the key or alphabetic letter
		//cout << key;
		string val = s1.substr(1,s1.length()); //start from index 1 of string to the end to make value or morse code
		morse_txt[key] = val; //set key and value into map
		//cout << morse_txt[key] << endl;
	}

	//DECODING:
	string input; 
	cout << "Enter string to be translated: ";
	cin >> input; 
	map<char, string>::iterator iter; //create iterator to go through map
	cout << "Decoded message: ";
	for (int i = 0; i < input.length(); i++) {
		char lit = input[i]; 
		for (iter = morse_txt.begin(); iter != morse_txt.end(); iter++) { //iterate through map
			if (iter->first == lit) //iter->first calls key, if key = first index/alphabetic letter of inputted string:
				cout <<iter->second; //cout the morse code associated to it 
		}
	}
	cout << endl;
	istream.close();
	system("pause");
}