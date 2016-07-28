#include "util.h"
#include "problem58.h"
#include <iostream>
using namespace std;
void problem58(){
	double ratio = 1;
	int numberOfPrimes = 3;
	int checkedNumbers = 5;
	int sideLength = 3;
	while (ratio > 0.1){
		sideLength += 2;
		int	n1 = sideLength*sideLength;
		int	n2 = n1 - sideLength + 1;
		int	n3 = n2 - sideLength + 1;
		int	n4 = n3 - sideLength + 1;
		if (isPrime(n1))
			numberOfPrimes += 1;
		if (isPrime(n2))
			numberOfPrimes += 1;
		if (isPrime(n3))
			numberOfPrimes += 1;
		if (isPrime(n4))
			numberOfPrimes += 1;
		checkedNumbers += 4;
		ratio = (double)numberOfPrimes / checkedNumbers;
	}
	cout << sideLength << endl;
}