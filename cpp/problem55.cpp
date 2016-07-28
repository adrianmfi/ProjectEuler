#include <iostream>
#include <boost\multiprecision\cpp_int.hpp>
#include "util.h"
using namespace std;
using namespace boost::multiprecision;

int getDigits(uint128_t x) {
	int size = 0;
	while (x > 0){
		x /= 10;
		size++;
	}
	return size;
}

uint128_t reverseInt(uint128_t n){
	uint128_t  ret = 0;
	size_t size = getDigits(n);
	for (int i = 0; i < size; i++){
		ret *= 10;
		ret += (n % 10);
		n /= 10;
	}
	return ret;
}

bool isPalindrome(uint128_t n){
	return n == reverseInt(n);
}

void problem55(){
	int lychrelNumbers = 0;
	for (int n = 1; n < 10000; n++){
		uint128_t tmp = n;
		for (int i = 0; i < 50; i++){
			tmp += reverseInt(tmp);
			if (isPalindrome(tmp))break;
			if (i == 49){
				lychrelNumbers++;
		//		cout << n <<", " <<tmp<< endl;
			}
		}
	}
	cout << lychrelNumbers << endl;
}

void problem55tmp(){
	int lychrelNumbers = 0;
	for (int n = 1; n < 400; n++){
		int tmp = n;
		for (int i = 0; i < 50; i++){
			tmp += reverseInt(tmp);
			if (isPalindrome(tmp))break;
			if (i == 49){
				lychrelNumbers++;
				cout << n << endl;
			}
		}
	}
	cout << lychrelNumbers << endl;
}
