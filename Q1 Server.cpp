#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

string decToBin(int dec) {										//function to convert decimal value to binary
	int i, bin;
	string binary;
	for (i = 0; dec > 0; i++) {
		bin = dec % 2;												//getting remainder from decimal/2 as 0 or 1
		bin == 1 ? binary += '1' : binary += '0';
		dec = dec / 2;
	}
	if (i < 18) {														//filling remainder bits with 0
		for (int j = i; j < 18; j++)
			binary += '0';
	}
	return binary;
}

string toBinary(string text) {
	string key, invert, bitstring;										//function to convert text to binary
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'a' || text[i] == 'A')							//checking for each character to add particular bitstring block
			bitstring += "00000";
		else if (text[i] == 'b' || text[i] == 'B')
			bitstring += "00001";
		else if (text[i] == 'c' || text[i] == 'C')
			bitstring += "00010";
		else if (text[i] == 'd' || text[i] == 'D')
			bitstring += "00011";
		else if (text[i] == 'e' || text[i] == 'E')
			bitstring += "00100";
		else if (text[i] == 'f' || text[i] == 'F')
			bitstring += "00101";
		else if (text[i] == 'g' || text[i] == 'G')
			bitstring += "00110";
		else if (text[i] == 'h' || text[i] == 'H')
			bitstring += "00111";
		else if (text[i] == 'i' || text[i] == 'I')
			bitstring += "01000";
		else if (text[i] == 'j' || text[i] == 'J')
			bitstring += "01001";
		else if (text[i] == 'k' || text[i] == 'K')
			bitstring += "01010";
		else if (text[i] == 'l' || text[i] == 'L')
			bitstring += "01011";
		else if (text[i] == 'm' || text[i] == 'M')
			bitstring += "01100";
		else if (text[i] == 'n' || text[i] == 'N')
			bitstring += "01101";
		else if (text[i] == 'o' || text[i] == 'O')
			bitstring += "01110";
		else if (text[i] == 'p' || text[i] == 'P')
			bitstring += "01111";
		else if (text[i] == 'q' || text[i] == 'Q')
			bitstring += "10000";
		else if (text[i] == 'r' || text[i] == 'R')
			bitstring += "10001";
		else if (text[i] == 's' || text[i] == 'S')
			bitstring += "10010";
		else if (text[i] == 't' || text[i] == 'T')
			bitstring += "10011";
		else if (text[i] == 'u' || text[i] == 'U')
			bitstring += "10100";
		else if (text[i] == 'v' || text[i] == 'V')
			bitstring += "10101";
		else if (text[i] == 'w' || text[i] == 'W')
			bitstring += "10110";
		else if (text[i] == 'x' || text[i] == 'X')
			bitstring += "10111";
		else if (text[i] == 'y' || text[i] == 'Y')
			bitstring += "11000";
		else if (text[i] == 'z' || text[i] == 'Z')
			bitstring += "11001";
		else if (text[i] == ' ')
			bitstring += "11010";
		else if (text[i] == '.')
			bitstring += "11011";
		else if (text[i] == ',')
			bitstring += "11100";
		else if (text[i] == '\n')
			bitstring += "11101";
		else if (text[i] == '(')
			bitstring += "11110";
		else if (text[i] == ')')
			bitstring += "11111";
	}
	return bitstring;													//returning corresponding bitstring
}

string toText(string text) {											//function to convert bitstring to text
	string plaintext;
	char chr[7];
	int block = 0;
	const char* c;
	int count = 0;
	block = text.length() / 5;											//dividing string into blocks of 5
	for (int i = 0; i < block; i++) {									//looping for each block to check which character the block corresponds to
		c = text.c_str();
		strncpy_s(chr, c + count, 5);
		count += 5;

		if (strcmp(chr, "00000") == 0)									//checking for each block
			plaintext += 'a';
		else if (strcmp(chr, "00001") == 0)
			plaintext += 'b';
		else if (strcmp(chr, "00010") == 0)
			plaintext += 'c';
		else if (strcmp(chr, "00011") == 0)
			plaintext += 'd';
		else if (strcmp(chr, "00100") == 0)
			plaintext += 'e';
		else if (strcmp(chr, "00101") == 0)
			plaintext += 'f';
		else if (strcmp(chr, "00110") == 0)
			plaintext += 'g';
		else if (strcmp(chr, "00111") == 0)
			plaintext += 'h';
		else if (strcmp(chr, "01000") == 0)
			plaintext += 'i';
		else if (strcmp(chr, "01001") == 0)
			plaintext += 'j';
		else if (strcmp(chr, "01010") == 0)
			plaintext += 'k';
		else if (strcmp(chr, "01011") == 0)
			plaintext += 'l';
		else if (strcmp(chr, "01100") == 0)
			plaintext += 'm';
		else if (strcmp(chr, "01101") == 0)
			plaintext += 'n';
		else if (strcmp(chr, "01110") == 0)
			plaintext += 'o';
		else if (strcmp(chr, "01111") == 0)
			plaintext += 'p';
		else if (strcmp(chr, "10000") == 0)
			plaintext += 'q';
		else if (strcmp(chr, "10001") == 0)
			plaintext += 'r';
		else if (strcmp(chr, "10010") == 0)
			plaintext += 's';
		else if (strcmp(chr, "10011") == 0)
			plaintext += 't';
		else if (strcmp(chr, "10100") == 0)
			plaintext += 'u';
		else if (strcmp(chr, "10101") == 0)
			plaintext += 'v';
		else if (strcmp(chr, "10110") == 0)
			plaintext += 'w';
		else if (strcmp(chr, "10111") == 0)
			plaintext += 'x';
		else if (strcmp(chr, "11000") == 0)
			plaintext += 'y';
		else if (strcmp(chr, "11001") == 0)
			plaintext += 'z';
		else if (strcmp(chr, "11010") == 0)
			plaintext += ' ';
		else if (strcmp(chr, "11011") == 0)
			plaintext += '.';
		else if (strcmp(chr, "11100") == 0)
			plaintext += ',';
		else if (strcmp(chr, "11101") == 0)
			plaintext += '\n';
		else if (strcmp(chr, "11110") == 0)
			plaintext += '(';
		else if (strcmp(chr, "11111") == 0)
			plaintext += ')';
	}
	return plaintext;
}

string encrypt(string text) {												//function to encrypt or decrypt data
	int key = 2122, block, x = 0;
	string ciphertext, entext, binkey, bitstring;
	char ablock[15];
	while ((text.length() * 5) % 15 != 0)									//block length of 15
		text += " ";
	binkey = decToBin(key);													//converting key to binary
	bitstring = toBinary(text);												//converting text to binary
	block = bitstring.length() / 15;

	for (int i = 0; i < block; i++) {										//for each block
		for (int j = 0; j < 15; j++) {
			ablock[j] = bitstring[x];
			x++;
		}
		for (int a = 0; a < 15; a++) {										//XORing block with key
			if (ablock[a] == binkey[a])
				entext += '0';
			else
				entext += '1';
		}
	}
	ciphertext = toText(entext);											//converting bitstring to text
	return ciphertext;
}

bool createFile() {																	// function to create a file
	ofstream file;
	ifstream check;
	string fileName = "server.txt";
	
	check.open(fileName);
	if (check.is_open()) {																		// check if file already exists
		return false;																					// display error and return
	}

	try {
		file.open(fileName);																	// try creating file
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;
		return false;
	}
	cout << "Server is open for data" << endl;
	file.close();
	return true;																						// return after creating file
}

void appendText(string ltext) {													// function to append text to a file
	ofstream file;
	ifstream check;
	string fileName, text;
	fileName = "server.txt";
	check.open(fileName);																		// check if file exists
	if (!check.is_open()) {
		cout << "Data not available." << endl;
		return;																					// display error and return if does not
	}
	file.open(fileName, ios::app);																// open file to write in append mode
	file << ltext;
	cout << "Text added." << endl;													// write text to the file and return
	check.close();
	return;
}


void showFile(string file) {														// function to show contents of a file
	string FileName, text, data, plaintext;
	ifstream check;
	FileName = file;
	check.open(FileName);
	if (!check.is_open()) {																		// check if file exists
		cout << "Cannot locate data." << endl;
		return;																					// display error and return if does not exist
	}

	try {
		// print line by line
		for (int i = 0; (getline(check, text)); i++) {                                          //for each line
			if (i == 0) {
				const char * h = text.c_str();
				if (strcmp(h, "zqrxy") != 0) {													//confirms the user's hashed password
					cout << "Invalid user" << endl;
				}
			}
			else if (i == 1) {
				cout << "User: " << text << endl;
			}
			else if (i > 1) {																	//gets local data
				data += text;
				data += '\n';																	//storing complete encrypted text line by line
			}
		}
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;													// display error and return if any exception
		return;
	}

	plaintext = encrypt(data);																		//decrypting and printing
	appendText(data);																				//appends local data to server
	check.close();
	return;
}


int main() {
	char ch;
	createFile();
	showFile("local.txt");

	return 0;
}
