#include "problem54.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

enum Suit { Diamonds, Hearts, Clubs, Spades };
struct Hand{
	char values[5];
	char suit[5];
};

void printHand(Hand h){
	for (int i = 0; i < 5; i++){
		cout << h.values[i] << h.suit[i] << " ";
	}
	cout << endl;
}

bool p1isWinner(Hand p1, Hand p2){ // True = p1, false = p2
	int p1Occurences[14] = {};
	int p2Occurences[14] = {};
	bool p1IsFlush = true;
	bool p2IsFlush = true;

	for (int i = 0; i < 4; i++){
		if (p1.suit[i] != p1.suit[i + 1]) p1IsFlush = false;
		if (p2.suit[i] != p2.suit[i + 1]) p2IsFlush = false;
	}

	return true;
}

void problem54(){
	ifstream file("p054_poker.txt");
	if (file.fail()){
		cout << "Error opening file" << endl;
		return;
	}

	char card[3];
	Hand player1, player2;
	int cardNumber = 0;
	int p1Wins = 0;

	while (file >> card){
		if (cardNumber < 5){
			player1.values[cardNumber] = card[0];
			player1.suit[cardNumber] = card[1];
		}
		else if (cardNumber < 10){
			player2.values[(cardNumber - 5)] = card[0];
			player2.suit[(cardNumber - 5)] = card[1];
		}
		else{
			if (p1isWinner(player1, player2)){
				p1Wins++;
			}

			cardNumber = 0;
			player1.values[cardNumber] = card[0];
			player1.suit[cardNumber] = card[1];
		}
		cardNumber++;
	}
	if (p1isWinner(player1, player2)){
		p1Wins++;
	}
	cout << p1Wins << endl;
	file.close();
}