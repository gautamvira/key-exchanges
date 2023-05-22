#include <iostream>
#include <string>
using namespace std;

//This program only encrypts text using the key given
//Use diffiehellman.py to compute the key

string decToBin(int dec) {										//function to convert decimal value to binary
	int i, bin;
	string binary;
	for (i = 0; dec > 0; i++) {
		bin = dec % 2;												//getting remainder from decimal/2 as 0 or 1
		bin == 1 ? binary += '1' : binary += '0';
		dec = dec / 2;
	}
	if (i < 15) {														//filling remainder bits with 0
		for (int j = i; j < 15; j++)
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
		else if (text[i] == '?')
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
	char chr[6];
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
			plaintext += '?';
		else if (strcmp(chr, "11110") == 0)
			plaintext += '(';
		else if (strcmp(chr, "11111") == 0)
			plaintext += ')';
	}
	return plaintext;
}

int main() {
	int key, len, block, x = 0, ch= 3, z;																				//initializing variables
	string ciphertext, entext, binkey, bitstring, text = "my name is gautam. how are you?";	// string to encrypt
	char ablock[15];
	while ((text.length() * 5) % 15 != 0)																				//padding for block length = 15
		text += " ";

	do {
		cout << "1.Encrypt\n2.Decrypt\n3.Exit\nEnter a choice: ";														//menu
		cin >> ch;
		if (ch == 1) {
			cout << "Enter your common key: ";																			//if encrypting
			cin >> key;
			binkey = decToBin(key);																						//converting key to binary
			bitstring = toBinary(text);																					//converting text to binary
			x = 0;
			block = bitstring.length() / 15;																			//calculating number of blocks
			entext = "";
			for (int i = 0; i < block; i++) {																			//for each block
				z = 14;
				for (int j = 0; j < 15; j++) {																			//copying blocks of bitstring
					ablock[j] = bitstring[x];
					x++;
				}
				for (int a = 0; a < 15; a++) {																			//Xoring each block with key
					if (ablock[a] == binkey[z])
						entext += '0';
					else
						entext += '1';
					z--;
				}
			}
			cout << "The encrypted text is: " << toText(entext) << endl;												//Displaying encrypted text
		}
		else if (ch == 2) {
			cin.ignore();
			cout << "Enter ciphertext: ";
			getline(cin, ciphertext);
			cout << "Enter your common key: ";
			cin >> key;
			binkey = decToBin(key);																						//converting key to binary
			bitstring = toBinary(ciphertext);																					//converting text to binary
			x = 0;
			block = bitstring.length() / 15;																			//calculating number of blocks
			entext = "";
			for (int i = 0; i < block; i++) {																			//for each block
				z = 14;
				for (int j = 0; j < 15; j++) {																			//copying blocks of bitstring
					ablock[j] = bitstring[x];
					x++;
				}
				for (int a = 0; a < 15; a++) {																			//Xoring each block with key
					if (ablock[a] == binkey[z])
						entext += '0';
					else
						entext += '1';
					z--;
				}
			}
			cout << "The plain text is: " << toText(entext) << endl;
		}
	} while (ch != 3);																									//exit if 3
	return 0;
}