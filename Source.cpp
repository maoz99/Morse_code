#include<iostream>
#include "Binary_Search_Tree.h"
#include "BTNode.h"
#include <fstream>
#include <map>
using namespace std;

bool CheckFile(ifstream & in, string file); //Function that stops program if file not found
void Encode(map<string, string> & morse_txt, string input); //Letters to dots/dash
void Decode(Binary_Search_Tree<string> binary_tree, string input);//dots/dash
void selection_sort(vector<string>& vec);

int main() {
	
	//-------------------------------------------READ FILE & GET DATA--------------------------------------------------

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


	selection_sort(the_vector);

	istream.close();


	//-------------------------------------------CREATE BINARY TREE--------------------------------------------------


	//Iterate through vectors and enter nulls where necessary
	vector<string> BTVec;
	BTVec.push_back("");
	for (int i = 0; i < the_vector.size(); i++) {	
		int length = the_vector[i].length();
		if ((length == 5 && the_vector[i + 1].length() == 5) || (length ==5 && the_vector[i-1].length()==5)) {
			BTVec.push_back(the_vector[i]);
			BTVec.push_back("NULL");
			BTVec.push_back("NULL");
		}
		else if ((length == 5 && the_vector[i - 2].length() == 5)||(length== 5 && the_vector[i - 2].length() != 5)) {
			BTVec.push_back(the_vector[i]);
			BTVec.push_back("NULL");
			BTVec.push_back("NULL");
			BTVec.push_back("NULL");
		}
		else
			BTVec.push_back(the_vector[i]);
	}


	//Create binary tree from the vector
	Binary_Search_Tree<string> binary_tree;
	binary_tree.read_tree(BTVec);
	

	//-------------------------------------------USE TREE AND MAP TO DECODE & ENCODE--------------------------------------------------
	Decode(binary_tree, "._ _... _._. _.. . .._. __. .... .. .___ _._ ._.. __ _. ___ .__. __._ ._. ... _ .._ ..._ .__ _.._ _.__ __..");
	Encode(morse_txt, "abc def ghi jkl mno pqr stu vwx yz");


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
		if (input[i] != ' ') {
			for (iter = morse_txt.begin(); iter != morse_txt.end(); iter++) { //iterate through map
				if (iter->first[0] == input[i]) { //iter->first calls key, if key = first index/alphabetic letter of inputted string:
					cout << iter->second; //cout the morse code associated to it 
					break;
				}
			}
		}
		else
			cout << "\n";
	}
	cout << endl;
}

void Decode(Binary_Search_Tree<string> binary_tree, string input)
{
	//dots to letters
	cout << "Decoding output...";
	Binary_Tree<string> bt;
	bool change = false;
	for (int i = 0; i < input.length(); i++) { //for each character in the input string 
		if (input[i] == ' ') {
			cout << bt.get_data()[0]; //cout the letter corresponding to the code beforehand
			bt = binary_tree; //restart binary tree
			change = false; //restart change
		}
		else if (input[i] == '.') {
			if (change) { //if change == true or we are already looking through the tree
				bt = bt.get_left_subtree(); //move left 
			}
			else { //just look at the first left node
				bt = binary_tree.get_left_subtree();
				change = true; //we are moving further into tree
			}
		}
		else if (input[i] == '_') { // ^same
			if (change) {
				bt = bt.get_right_subtree();
			}
			else {
				bt = binary_tree.get_right_subtree();
				change = true;
			}
		}

	}
	cout << bt.get_data()[0];
	cout << endl << endl;
}

void selection_sort(vector<string>& vec) {

	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {

			if (vec[next].substr(1, vec[next].length()) < vec[pos_min].substr(1, vec[pos_min].length()))
				pos_min = next;

		}
		if (fill != pos_min)
			swap(vec[pos_min], vec[fill]);

	}
}
