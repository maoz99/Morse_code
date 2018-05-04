#pragma once
#include<iostream>
#include "Binary_Search_Tree.h"
#include "BTNode.h"
#include <fstream>
#include "Morse_Tree.h"
#include <map>
#include <vector>
using namespace std;
template<typename Item_Type>
class Morse_Tree : public Binary_Search_Tree<Item_Type> {
public:

	void Encode(map<string, string> & morse_txt, string input) {
	
		//Takes in a string of letters and prints out the dots/dashes
		map<string, string>::iterator iter; 
		cout << "Enocded message: ";
		for (int i = 0; i < input.length(); i++) { //iterate through string
			if (input[i] != ' ') { //Make sure its not a space
				for (iter = morse_txt.begin(); iter != morse_txt.end(); iter++) { //iterate through map
					if (iter->first[0] == input[i]) { //iter->first calls key, if key = first letter letter of:
						cout << iter->second; //cout the morse code (value) associated to it 
						break;
					}
				}
			}
			else
				cout << "\n"; //if its a space, create a new line 
		}
		cout << endl;
	} 


	void Decode(Binary_Search_Tree<string> binary_tree, string input) {
		//takes in a string of dots/dashes and outputs the string of letters
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
		//take in a vector of strings with both letter and code, sort it only by the code
		for (int fill = 0; fill != vec.size(); ++fill) {
			int pos_min = fill;
			for (int next = fill + 1; next != vec.size(); ++next) {
				//use substring to ignore the first index and only sort the code part of the string (dots/dashes)
				if (vec[next].substr(1, vec[next].length()) < vec[pos_min].substr(1, vec[pos_min].length()))
					pos_min = next;

			}
			if (fill != pos_min)
				swap(vec[pos_min], vec[fill]);

		}
	}





	Binary_Search_Tree<string> CreateTree(vector<string> the_vector) {
	
		this->selection_sort(the_vector);

		vector<string> BTVec; //Create new vector
		BTVec.push_back(""); //first item of vector will be the dummy node with no data
		for (int i = 0; i < the_vector.size(); i++) { //iterate through vector
			int length = the_vector[i].length();
			if ((length == 5 && the_vector[i + 1].length() == 5) || (length == 5 && the_vector[i - 1].length() == 5)) {
				//if the node should be a leaf node, push in the item followed by 2 nulls
				BTVec.push_back(the_vector[i]);
				BTVec.push_back("NULL");
				BTVec.push_back("NULL");
			}
			else if ((length == 5 && the_vector[i - 2].length() == 5) || (length == 5 && the_vector[i - 2].length() != 5)) {
				//if the node is a single child, push in the value followed by 3 NULLS (2 NULLS make it a leaf, 1 NULL makes the other child not exist
				BTVec.push_back(the_vector[i]);
				BTVec.push_back("NULL");
				BTVec.push_back("NULL");
				BTVec.push_back("NULL");
			}
			else //if the node has 2 children, just push it in.
				BTVec.push_back(the_vector[i]);
		}

		//use this new vector to create the binary tree
		Binary_Search_Tree<string> binary_tree;
		binary_tree.read_tree(BTVec);

		return binary_tree;
	
	}

	
};
