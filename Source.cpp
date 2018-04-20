#include<iostream>
#include "Binary_Search_Tree.h"
#include "BTNode.h"
#include <fstream>
using namespace std; 

void selection_sort(vector<string>& vec);
int main() {
	//vector<std::string> BinarySearchData_2{"", "e", "t"};
	////,"i","e","h","f","g"
	ifstream istream; //create istream to read in morse.txt file
	vector<string> the_vector;
	//string letter, code;
	//ifstream morse_file;
	//morse_file.open("morse.txt");
	//while (!morse_file) {
	//	morse_file >> letter>>code;
	//	the_vector.push_back(letter);
	//}
	//morse_file.close();
	istream.open("morse.txt");
	while (!istream.eof()) {
		string s1;
		getline(istream, s1); //read line and insert into string
		string key = s1.substr(0); //first index is the key or alphabetic letter
						  //cout << key;
		the_vector.push_back(key);
	}

	Binary_Search_Tree<std::string> binary_tree;
	selection_sort(the_vector);
	vector<string>::iterator iter = the_vector.begin();
	for (iter; iter < the_vector.end(); ++iter) {
		if (iter != the_vector.end()) {
			if (iter->length() < (++iter)->length()) {
				the_vector.insert(iter, "NULL");
				the_vector.insert(iter, "NULL");
			}
		}

	}
	binary_tree.read_tree(the_vector);

	system("pause");
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
