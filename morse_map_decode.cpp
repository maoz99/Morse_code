#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include <vector>
using namespace std;


bool CheckFile(ifstream & in, string file); //Function that stops program if file not found
void Decode(map<char, string> & morse_txt, string input);
void Encode(string input);

void main() {
	vector <vector<string>> Vec; //create a vector to store items by height on tree
	vector <string> v1, v2, v3, v4; //fill vector with vectors of items corresponding to items by height
	Vec.push_back(v1);
	Vec.push_back(v2);
	Vec.push_back(v3);
	Vec.push_back(v4);

	map<char, string> morse_txt; //create map
	ifstream istream; //create istream to read in morse.txt file
	istream.open("morse.txt");
	if (!CheckFile(istream, "morse.txt"))
		return;

	while (!istream.eof()) {
		string s1;
		getline(istream, s1); //read line and insert into string
		char key = s1[0]; //first index is the key or alphabetic letter
						  //cout << key;
		string val = s1.substr(1, s1.length()); //start from index 1 of string to the end to make value or morse code
		morse_txt[key] = val; //set key and value into map
							  //cout << morse_txt[key] << endl;
		
		int height = val.length() - 1;
		Vec[height].push_back(val+s1.substr(0,1));
	
	}


	string input;
	cout << "Enter string to be translated: ";
	cin>> input;

	if (input[0] == '.' || input[0] == '_') 
		Encode(input); //if they enter a code, encode it (output abc...)
	else 
		Decode(morse_txt, input); // if they enter a word, decode it (output ._...)
	

	cout << endl;
	istream.close();
	system("pause");
}


bool CheckFile(ifstream & in, string file)
{
	//if file not found, output message and end program 
	while (!in) {
		cout << "Could not open the " << file <<
			" file. Please check the file and try again.\n";
		system("pause");
		return false; 
	}
	return true;
}

void Decode(map<char, string> & morse_txt, string input) {
	
	map<char, string>::iterator iter; //create iterator to go through map
	cout << "Decoded message: ";
	for (int i = 0; i < input.length(); i++) {
		char lit = input[i];
		for (iter = morse_txt.begin(); iter != morse_txt.end(); iter++) { //iterate through map
			if (iter->first == lit) //iter->first calls key, if key = first index/alphabetic letter of inputted string:
				cout << iter->second; //cout the morse code associated to it 
		}
	}
	cout << endl;
}

void Encode(string input)
{
	cout << "Encoding output...\n";

}
