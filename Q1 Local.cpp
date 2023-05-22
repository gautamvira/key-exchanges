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

void toGrid(char arr[], int grid[5][5]) {										//function to convert block to grid(2-d array)
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[count] == 'a' || arr[count] == 'A')							//checking for character to convert to the particular binary block
				grid[i][j] = 0;
			else if (arr[count] == 'b' || arr[count] == 'B')
				grid[i][j] = 1;
			else if (arr[count] == 'c' || arr[count] == 'C')
				grid[i][j] = 2;
			else if (arr[count] == 'd' || arr[count] == 'D')
				grid[i][j] = 3;
			else if (arr[count] == 'e' || arr[count] == 'E')
				grid[i][j] = 4;
			else if (arr[count] == 'f' || arr[count] == 'F')
				grid[i][j] = 5;
			else if (arr[count] == 'g' || arr[count] == 'G')
				grid[i][j] = 6;
			else if (arr[count] == 'h' || arr[count] == 'H')
				grid[i][j] = 7;
			else if (arr[count] == 'i' || arr[count] == 'I')
				grid[i][j] = 8;
			else if (arr[count] == 'j' || arr[count] == 'J')
				grid[i][j] = 9;
			else if (arr[count] == 'k' || arr[count] == 'K')
				grid[i][j] = 10;
			else if (arr[count] == 'l' || arr[count] == 'L')
				grid[i][j] = 11;
			else if (arr[count] == 'm' || arr[count] == 'M')
				grid[i][j] = 12;
			else if (arr[count] == 'n' || arr[count] == 'N')
				grid[i][j] = 13;
			else if (arr[count] == 'o' || arr[count] == 'O')
				grid[i][j] = 14;
			else if (arr[count] == 'p' || arr[count] == 'P')
				grid[i][j] = 15;
			else if (arr[count] == 'q' || arr[count] == 'Q')
				grid[i][j] = 16;
			else if (arr[count] == 'r' || arr[count] == 'R')
				grid[i][j] = 17;
			else if (arr[count] == 's' || arr[count] == 'S')
				grid[i][j] = 18;
			else if (arr[count] == 't' || arr[count] == 'T')
				grid[i][j] = 19;
			else if (arr[count] == 'u' || arr[count] == 'U')
				grid[i][j] = 20;
			else if (arr[count] == 'v' || arr[count] == 'V')
				grid[i][j] = 21;
			else if (arr[count] == 'w' || arr[count] == 'W')
				grid[i][j] = 22;
			else if (arr[count] == 'x' || arr[count] == 'X')
				grid[i][j] = 23;
			else if (arr[count] == 'y' || arr[count] == 'Y')
				grid[i][j] = 24;
			else if (arr[count] == 'z' || arr[count] == 'Z')
				grid[i][j] = 25;
			else if (arr[count] == ' ')
				grid[i][j] = 26;
			count++;																	//incrementing block
		}
	}

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

void addcolumn(int grid[5][5], int out[]) {				//function to add values of columns
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			out[i] += grid[j][i];
		}
		out[i] = out[i] % 27;
	}
}

void shiftrow(int grid[5][5], int out[]) {				//function to shift rows in the grid
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = -1; j < i; j++) {
			temp = grid[i][0];
			grid[i][0] = grid[i][1];
			grid[i][1] = grid[i][2];
			grid[i][2] = grid[i][3];
			grid[i][3] = grid[i][4];
			grid[i][4] = temp;
		}
	}
	addcolumn(grid, out);								//calling function to add values of columns
}
void addrow(int grid[5][5], int out[]) {				//function to add values of rows
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			out[i] += grid[i][j];
		}
		out[i] = out[i] % 27;							//value mod 27
	}
}

void shiftcolumn(int grid[5][5], int out[]) {			//function to shift columns
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = -1; j < i; j++) {
			temp = grid[4][i];
			grid[4][i] = grid[3][i];
			grid[3][i] = grid[2][i];
			grid[2][i] = grid[1][i];
			grid[1][i] = grid[0][i];
			grid[0][i] = temp;
		}
	}
	addrow(grid, out);									//calling function to add values of rows
}

string hashToText(int out[]) {							//function to convert out[] to text
	string output;
	for (int i = 0; i < 5; i++) {						// checking for each number in the array
		if (out[i] == 0)
			output += 'a';
		else if (out[i] == 1)
			output += 'b';
		else if (out[i] == 2)
			output += 'c';
		else if (out[i] == 3)
			output += 'd';
		else if (out[i] == 4)
			output += 'e';
		else if (out[i] == 5)
			output += 'f';
		else if (out[i] == 6)
			output += 'g';
		else if (out[i] == 7)
			output += 'h';
		else if (out[i] == 8)
			output += 'i';
		else if (out[i] == 9)
			output += 'j';
		else if (out[i] == 10)
			output += 'k';
		else if (out[i] == 11)
			output += 'l';
		else if (out[i] == 12)
			output += 'm';
		else if (out[i] == 13)
			output += 'n';
		else if (out[i] == 14)
			output += 'o';
		else if (out[i] == 15)
			output += 'p';
		else if (out[i] == 16)
			output += 'q';
		else if (out[i] == 17)
			output += 'r';
		else if (out[i] == 18)
			output += 's';
		else if (out[i] == 19)
			output += 't';
		else if (out[i] == 20)
			output += 'u';
		else if (out[i] == 21)
			output += 'v';
		else if (out[i] == 22)
			output += 'w';
		else if (out[i] == 23)
			output += 'x';
		else if (out[i] == 24)
			output += 'y';
		else if (out[i] == 25)
			output += 'z';
		else if (out[i] == 26)
			output += ' ';
	}
	return output;										//returning hashed value
}

int checkrem(int length, int* count) {					//function to check for blocks of plaintext
	int rem = 0;
	if (length % 25 == 0)								//checking for plaintext blocks
		*count = length / 25;
	else {
		*count = length / 25;							//if not divisible by 25(block size)
		rem = (length % 25);
	}
	return rem;
}

void hashFun(string text, int out[]) {							//function to hash the plaintext
	char block[25];
	int grid[5][5], x = 0;
	int rem = 0, count = 0;
	rem = checkrem(text.length(), &count);						//calling function to check for blocks
	for (int k = 0; k < count; k++) {
		for (int i = 0; i < 25; i++) {
			block[i] = text[x];									//dividing into blocks of 25
			x++;
		}
		toGrid(block, grid);									//converting block to grid
		addcolumn(grid, out);									//adding values of columns
		shiftrow(grid, out);									//shifting rows and adding rows
		shiftcolumn(grid, out);									//shifting columns and adding columns
	}
	if (rem != 0) {
		memset(block, ' ', sizeof(block));						//padding for block size
		for (int i = 0; i < rem; i++) {
			block[i] = text[x];
			x++;
		}
		toGrid(block, grid);									//hashing the padded block
		addcolumn(grid, out);
		shiftrow(grid, out);
		shiftcolumn(grid, out);
	}
}

bool checkServer() {
	ifstream check;
	ofstream create;
	string fileName = "local.txt";																		// check if file already exists
	create.open(fileName);

	check.open(fileName);
	if (!check.is_open()) {																		// check if file already exists
		cout << "Error." << endl;
		return false;
	}
	return true;
}

void appendText(string text) {													// function to append text to a file
	ofstream file;
	ifstream check;
	string fileName;
	fileName = "local.txt";
	check.open(fileName);																		// check if file exists
	if (!check.is_open()) {
		cout << "Data not available." << endl;
		return;																					// display error and return if does not
	}
	check.close();
	file.open(fileName, ios::app);																// open file to write in append mode
	file << text;
	cout << "Text added." << endl;													// write text to the file and return
	return;
}

void showserver() {
	ifstream check;
	string FileName = "server.txt";
	string text, data, plaintext;
	check.open(FileName);
	if (!check.is_open()) {																		// check if file exists
		cout << "Cannot locate data." << endl;
		return;																					// display error and return if does not exist
	}

	try {
		// print line by line
		for (int i = 0; (getline(check, text)); i++) {                                          //for each line																	//gets local data
			data += text;
			data += '\n';																	//storing complete encrypted text line by line
		}
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;													// display error and return if any exception
		return;
	}

	plaintext = encrypt(data);																		//decrypting and printing
	cout << plaintext << endl;
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
			if(i > 1) {
				data += text;
				text += '\n';																	//storing complete encrypted text line by line
			}
		}
	}
	catch (exception const& e) {
		cout << "Error: " << e.what() << endl;													// display error and return if any exception
		return;
	}

	plaintext = encrypt(data);																		//decrypting and printing
	cout << plaintext << endl;
	check.close();
	return;
}



int main() {
	string passwd, name, text, hashed, entext;
	int ch, out[5];
	if (checkServer()) {												//checking if local data can be added
		cout << "Enter your name: ";									//getting user details
		getline(cin, name);
		name += '\n';
		cout << "Enter password: ";
		getline(cin, passwd);
		memset(out, 0, sizeof(out));
		hashFun(passwd, out);											//hashing user password
		hashed = hashToText(out);
		const char * h = hashed.c_str();
		if (!strcmp(h, "zqrxy")) {										//checking if password is correct
			hashed += "\n";
			appendText(hashed);											//appending user details to file for verification by server
			appendText(name);
			do {																											//menu
				cout << "1. Insert Data\n2. Display Local Data\n3. Display Server Data\n4. Exit\nEnter your choice:";
				cin >> ch;
				if (ch == 1) {
					cout << "Input the data(add a '`' at the end of your text):\n";						//insert data
					cin.ignore();
					getline(cin, text, '`');
					text += '\n';
					entext = encrypt(text);																//encrypting data
					appendText(entext);																	//appending ciphertext to data
				}
				else if (ch == 2)																		//display local data
					showFile("local.txt");
				else if (ch == 3)																		//display server data
					showserver();
			} while (ch != 4);
		}
		else
			cout << "Invalid password." << endl;														//if user password was invalid
	}

	return 0;
}