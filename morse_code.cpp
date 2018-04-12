#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

map<char,string> morse_map;
//map<string, char> m_map;
map<char,string>::iterator i;

void morsecode()
{
    morse_map['a'] = ".-";
    morse_map['b'] = "-...";
    morse_map['c'] = "-.-.";
    morse_map['d'] = "-..";
    morse_map['e'] = ".";
    morse_map['f'] = "..-.";
    morse_map['g'] = "--.";
    morse_map['h'] = "....";
    morse_map['i'] = "..";
    morse_map['j'] = ".---";
    morse_map['k'] = "-.-";
    morse_map['l'] = ".-..";
    morse_map['m'] = "--";
    morse_map['n'] = "-.";
    morse_map['o'] = "---";
    morse_map['p'] = ".--.";
    morse_map['q'] = "--.-";
    morse_map['r'] = ".-.";
    morse_map['s'] = "...";
    morse_map['t'] = "-";
    morse_map['u'] = "..-";
    morse_map['v'] = "...-";
    morse_map['w'] = ".--";
    morse_map['x'] = "-..-";
    morse_map['y'] = "-.--";
    morse_map['z'] = "--..";
    //store morese code,from the input file, into the map
    /*
     string letter,code;
     ifstream morse_file
     morse_file.open("morse.txt");
     while(!morse_file){
     morse_file<<letter<<code;
     morse_map[letter]=code;
     }
     morse_file.close();
     
     */
    
    /*for (i = morse_map.begin(); i != morse_map.end(); i++) {
        m_map[i -> second] = i -> first;
    }*/
}
