#include "util.h"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int concatIntegers(int a, int b){
	return a*pow(10,getDigits(b)) + b;
}

bool isPandigital(int num){

	bool numbersFound[9] = {};
	int digits = getDigits(num);
	for (int i = 0; i < digits; i++){
		int lastDigit = num % 10;
		if (lastDigit == 0) return false;

		numbersFound[lastDigit-1] = 1;
		num -= lastDigit;
		num /= 10;

	}
	for (int i = 0; i < 9; i++){
		if (numbersFound[i] == 0) return false;
	}
	return true;

}


int getDigits (unsigned x) {
	//skamløs kopi, funker ikke for tall større enn 10^10 (11?)
	if (x >= 100000) {
		if (x >= 10000000) {
			if (x >= 1000000000) return 10;
			if (x >= 100000000) return 9;
			return 8;
		}
		if (x >= 1000000) return 7;
		return 6;
	}
	else {
		if (x >= 1000) {
			if (x >= 10000) return 5;
			return 4;
		}
		else {
			if (x >= 100) return 3;
			if (x >= 10) return 2;
			return 1;
		}
	}
}

bool isPrime(unsigned int n){
	if (n <= 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n+1; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

vector<int> primeSieve(int n){ // returns a vector of the primes up to n
	vector<int> primes;
	bool* nums = new bool[n]; // boolsk array der 0. element tilsvarer tallet 2 osv.
	nums[0] = 0;
	nums[1] = 0;

	for (int i = 2; i < n; i++){
		nums[i] = 1;
	}
	int p = 2;
	while (p < n){
		int mul = 2;
		while (p*mul < n){
			nums[p*mul] = 0;
			mul++;
		}

		do{
			p++;
		} while (nums[p] == 0);
	}

	for (int i = 2; i < n; i++){
		if (nums[i]) primes.push_back(i);
	}
	delete[] nums;
	return primes;
}

vector<int> factorize(int n){
	vector<int> factors;

	int i = 2;
	while (i <= n){
		if (n % i == 0){// Tallet er delelig på primtallet
			factors.push_back(i);
			n /= i;
			i = 2;
		}
		else ++i;
	}
	return factors;
}

int reverseInt(int n){
	int ret = 0;
	size_t size = getDigits(n);
	for (int i = 0; i < size; i++){
		ret *= 10;
		ret += (n % 10);
		n /= 10;
	}
	return ret;
}

bool isPalindrome(int n){
	return n == reverseInt(n);
}

vector<string> getPermutations(string str){
	vector<string> ret;
	string tmp = str;
	do{
		ret.push_back(tmp);
	} while (next_permutation(tmp.begin(), tmp.end()));
	return ret;
}
