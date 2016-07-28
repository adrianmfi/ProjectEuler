#include "problem59.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


void problem59(){
	ifstream file("p059_cipher.txt");
	if (file.fail()){
		cout << "File error " << endl;
		exit(1);
	}
	
	string fileString;
	file >> fileString;
	file.close();
	
	stringstream s(fileString);
	string tmp;
	vector<int> ascii;

	while (getline(s, tmp, ',')){
		int i = stoi(tmp);
		ascii.push_back(i);
	}
	int size = ascii.size();
	int ascii_a = (int)'a';
	int ascii_z = (int)'z';
	int eOccurences = 0;
	int maxEOccurences = 0;
	char ckey1,ckey2,ckey3;
	
	for (int key1 = ascii_a; key1 <= ascii_z; key1++){
		eOccurences = 0;
		for (int i = 0; i < size; i += 3){
			char decrypted = (ascii[i] ^ key1);
			if (decrypted == ' ') eOccurences++;
		}
		if (maxEOccurences < eOccurences){
			maxEOccurences = eOccurences;
			ckey1 = key1;
		}
	}

	maxEOccurences = 0;
	for (int key2 = ascii_a; key2 <= ascii_z; key2++){
		eOccurences = 0;
		for (int i = 1; i < size; i += 3){
			char decrypted = (ascii[i] ^ key2);
			if (decrypted == ' ') eOccurences++;
		}
		if (maxEOccurences <= eOccurences){
			maxEOccurences = eOccurences;
			ckey2 = key2;
		}
	}

	maxEOccurences = 0;
	for (int key3 = ascii_a; key3 <= ascii_z; key3++){
		eOccurences = 0;
		for (int i = 2; i < size; i += 3){
			char decrypted = (ascii[i] ^ key3);
			if (decrypted == ' ') eOccurences++;
		}
		if (maxEOccurences < eOccurences){
			maxEOccurences = eOccurences;
			ckey3 = key3;
		}  
	}
	int correctKey[3] = { ckey1, ckey2, ckey3 };
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum+=ascii[i] ^ correctKey[i % 3];
	}
	cout << sum << endl;
}