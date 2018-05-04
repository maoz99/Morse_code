#include<iostream>
#include "Binary_Search_Tree.h"
#include "BTNode.h"
#include <fstream>
#include "Morse_Tree.h"
#include <map>
#include <vector>
using namespace std;

bool CheckFile(ifstream & in, string file); //check if file opened correctly, if not warn user and stop program

int main() {
	//-------------------------------------------READ FILE & GET DATA--------------------------------------------------

	ifstream istream; 
	istream.open("morse.txt");
	if (!CheckFile(istream, "morse.txt"))
		return -1;


	vector<string> the_vector; 	//vector to store all data from file (use for building the tree & to decode)
	map<string, string> morse_txt; //Create map to store letters as keys, and morse codes as values (used for encoding)


	while (!istream.eof()) {
		string key;
		getline(istream, key); 
		string val = key.substr(1, key.length()); //save morse code value, excluding index 0
		morse_txt[key] = val; 
		the_vector.push_back(key);
	}
	istream.close();



	//---------------------------------------CREATE BINARY TREE---------------------------------------------------------

	Morse_Tree<string> MT;
	Binary_Search_Tree<string> binary_tree = MT.CreateTree(the_vector);


	//-----------------------------------USE TREE AND MAP TO DECODE & ENCODE--------------------------------------------
	

	//Enter any string to be encoded or decoded
	MT.Decode(binary_tree, "._ _... _._. _.. . .._. __. .... .. .___ _._ ._.. __ _. ___ .__. __._ ._. ... _ .._ ..._ .__ _.._ _.__ __..");
	MT.Encode(morse_txt, "abc def ghi jkl mno pqr stu vwx yz");


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


