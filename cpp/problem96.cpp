#include <iostream>
#include "problem96.h"
#include <string>
#include <fstream>
#include <bitset>
using namespace std;

int NumberOfSetBits(int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
short flagToValue(short flag){
	int value = 1;
	while ((flag & 1) == 0){
		flag/=2;
		value++;
	}
	return value;
}

class Sudoku{
public:
	Sudoku();
	void openFromString(string sudoku);
	void insert(int row, int col, short value);
	short possibleMoves[9][9];
	short insertedValues[9][9];
	int insertedNumbers;
	void solve1();
	void solve2();
	void placeIfOnlyInRow(int row, short value);
	void placeIfOnlyInCol(int col, short value);
	void placeIfOnlyInBox(int box, short value);
	void printBoard();
}; 

Sudoku::Sudoku(){
	insertedNumbers = 0;
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			insertedValues[row][col] = 0;
			possibleMoves[row][col] = 0;
			for (short i = 1; i < 512; i *= 2){
				possibleMoves[row][col] = possibleMoves[row][col] | i;
			}
		}
	}
}
void Sudoku::openFromString(string sudoku){
	int row = 0; int column = 0;
	for (int i = 0; i < sudoku.length(); i++){
		int value = sudoku[i]-'0';
		if (value<0 || value > 9){
			row++;
			column = 0;
		}
		else {
			if (value != 0){
				insert(row, column, value);
			}
			column++;
		}
	}
}

void Sudoku::insert(int row, int col, short value){

	insertedNumbers++;
	insertedValues[row][col] = value;
	short flag = 1 << (value-1);
	short flagInverted = ~flag;
	for (int i = 0; i < 9; i++){
		possibleMoves[row][i] = possibleMoves[row][i] & flagInverted;
		possibleMoves[i][col] = possibleMoves[i][col] & flagInverted;
	}
	for (int i = 3 * (row / 3); i < 3 * (row / 3)+3; i++){
		for (int j = 3 * (col / 3); j < 3 * (col / 3)+3; j++){
			possibleMoves[i][j] = possibleMoves[i][j] & flagInverted;
		}
	}
	possibleMoves[row][col] = 0;
}

void Sudoku::solve1(){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (NumberOfSetBits(possibleMoves[i][j]) == 1){
					//cout << "Inserting " << flagToValue(possibleMoves[i][j]) << " at (" << i << ", " << j << ")\n";
					insert(i, j, flagToValue(possibleMoves[i][j]));
				}
			}
		}
}
void Sudoku::solve2(){
	for (int i = 0; i < 9; i++){
		for (short val = 1; val <= 9; val++){
			placeIfOnlyInBox(i, val);
			placeIfOnlyInCol(i, val);
			placeIfOnlyInBox(i, val);
		}
	}
}

void Sudoku::placeIfOnlyInRow(int row, short value){
	bool found = false;
	int foundRow = 0;
	int foundCol = 0;
	short flag = 1 << (value - 1);
	for (int col = 0; col < 9; col++){
		if (possibleMoves[row][col] & flag == flag && insertedValues[row][col] == 0){
			if (found) return;
			found = true;
			foundRow = row;
			foundCol = col;
		}
	}
	if (found){
		insert(foundRow, foundCol, value);
	}
}
void Sudoku::placeIfOnlyInCol(int col, short value){
	bool found = false;
	int foundRow = 0;
	int foundCol = 0;
	short flag = 1 << (value - 1);
	for (int row = 0; row < 9; row++){
		if (possibleMoves[row][col] & flag == flag && insertedValues[row][col] == 0){
			if (found) return;
			found = true;
			foundRow = row;
			foundCol = col;
		}
	}
	if (found){
		insert(foundRow, foundCol, value);
	}
}

void Sudoku::placeIfOnlyInBox(int box, short value){
	bool found = false;
	int foundRow = 0;
	int foundCol = 0;
	short flag = 1 << (value - 1);
	for (int row = box/3; row < box/3+3; row++){
		for (int col = 3 * (box % 3); col < 3 * (box % 3) + 3; col++){
			if (possibleMoves[row][col] & flag == flag && insertedValues[row][col] == 0){
				if (found) return;
				found = true;
				foundRow = row;
				foundCol = col;
			}
		}
	}
	if (found){
		insert(foundRow, foundCol, value);
	}
}


void Sudoku::printBoard(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << insertedValues[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void problem96(){
	ifstream file("p096_sudoku.txt");

	for (int i = 0; i < 40; i++){
		Sudoku s;
		string board1;
		string line;
		getline(file, line);
		int lines = 0;
		while (lines < 9){
			getline(file, line);
			board1 += line + '\n';
			lines++;
		}
		s.openFromString(board1);

		s.printBoard();
		int sum = 0;
		while (sum == 0){
			s.solve1();
			s.solve2();
			sum = s.insertedValues[0][0] * s.insertedValues[0][1] * s.insertedValues[0][2];
		}
		s.printBoard();

	}
}
