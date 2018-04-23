#include<iostream>
#include "Binary_Search_Tree.h"
#include "BTNode.h"
#include <fstream>
#include <map>
using namespace std; 

bool CheckFile(ifstream & in, string file); //Function that stops program if file not found
void Encode(map<string, string> & morse_txt, string input); //Letters to dots/dash
void Decode(string input); //dots/dash to letters
void selection_sort(vector<string>& vec);

int main() {
	
	//This is what the Binary tree vector should look like
	//vector<string> Binary_Tree_Ye{ "","e","i","s","h","NULL","NULL","v","NULL","NULL","u","f","NULL","NULL","NULL","a","r","l","NULL","NULL","NULL","w","p","NULL","NULL","j","NULL","NULL","t","n","d","b","NULL","NULL","x","NULL","NULL","k","c","NULL","NULL","y","NULL","NULL","m","g","z","NULL","NULL","q","NULL","NULL","o","NULL","NULL" };
	
	
	//Open & Check file
	ifstream istream; //create istream to read in morse.txt file
	istream.open("morse.txt");
	if (!CheckFile(istream, "morse.txt"))
		return -1;
	
	//Create map & vector to store data
	vector<string> the_vector;
	map<string, string> morse_txt; //create map

	//read file and store data
	while (!istream.eof()) {
		string s1;
		getline(istream, s1); //read line and insert into string
		string key = s1.substr(0); //first index is the key or alphabetic letter
						  //cout << key;
		string val = s1.substr(1, s1.length()); //start from index 1 of string to the end to make value or morse code
		morse_txt[key] = val; //set key and value into map
							  //cout << morse_txt[key] << endl;
		the_vector.push_back(key);
	}

	//Sort the vector by values in morse code (._)
	selection_sort(the_vector);
	
	//Iterate through vectors and enter nulls where necessary
	string next;
	int i = 2;
	the_vector.insert(the_vector.begin(), "");
	for (vector<string>::iterator iter = the_vector.begin() + 1; iter != the_vector.end(); ++iter) {
		next = the_vector[i];
		if (i >= the_vector.size())
			break;

		while (next == "") {
			i++;
			next = the_vector[i];
		}
		while (*iter == "") {
			iter++;
		}

		if (iter->data() == next) {
			the_vector.insert(iter+1, "");
		}
		else if (iter->length() == next.length())
			the_vector.insert(iter + 1, "");

		i++;
	}
	


	//Create binary tree and store values from the vector
	Binary_Search_Tree<std::string> binary_tree;
	binary_tree.read_tree(the_vector);

	//Get input and Encode/decode it
	string input;
	cout << "Enter string to be translated: ";
	cin >> input;

	if (input[0] == '.' || input[0] == '_')
		Decode(input); //if they enter a code, encode it (output abc...)
	else
		Encode(morse_txt, input); // if they enter a word, decode it (output ._...)


	cout << binary_tree.height() << endl;

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

void Encode(map<string, string> & morse_txt, string input) {
	//Letters to dots
	map<string, string>::iterator iter; //create iterator to go through map
	cout << "Enocded message: ";
	for (int i = 0; i < input.length(); i++) {
		for (iter = morse_txt.begin(); iter != morse_txt.end(); iter++) { //iterate through map
			if (iter->first[0] == input[i]) { //iter->first calls key, if key = first index/alphabetic letter of inputted string:
				cout << iter->second; //cout the morse code associated to it 
				break;
			}
	
		}
	}
	cout << endl;
}

void Decode(string input)
{
	//dots to letters
	cout << "Decoding output...\n";

}


void selection_sort(vector<string>& vec) {

	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {

			if (vec[next].substr(1, vec[next].length()) < vec[pos_min].substr(1,vec[pos_min].length()))
				pos_min = next;

		}
		if (fill != pos_min)
			swap(vec[pos_min], vec[fill]);

	}
}
