#include "problem51.h"
#include <math.h>
#include <iostream>
using namespace std;



void problem51(){
	const int upperValue = 56004;
	bool isPrime[upperValue];
	
	/*Generate prime sieve*/
	for (int i = 2; i < upperValue; i++){
		isPrime[i] = true; //Initialize prime sieve array
	}
	isPrime[0] = false;
	isPrime[1] = false;
	int p = 2;
	while (p < upperValue){
		int mul = 2;
		int current = p*mul;
		while (current < upperValue){
			isPrime[current] = 0;
			mul++;
			current = p*mul;
		}

		do{
			p++;
		} while (!isPrime[p]);
	}
	
	/**/
	int smallest = upperValue;
	int familyCount[upperValue] = { 0 };
	for (int prime = 0; prime < upperValue; prime++){
		if (isPrime[prime]){
			/*Make all different variations of the prime...*/
			/*Check if count = 8, if so make prime smallest*/
		}
	}
}