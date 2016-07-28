#include "problem50.h"
#include "util.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void problem50(){
	int upperLimit = 1000000;

	vector<int> p = primeSieve(upperLimit);
	//Find the longest possible chain
	int sum = 0;
	int chainSize = 0;
	while (sum < upperLimit){
		sum += p[chainSize];
		chainSize++;
	}

	//start at chainSize chain, then decrement chain length until prime is hit;
	while (chainSize >0){
		//Start at the start, then move chain by one
		sum = 0;
		int i = 0;
		for (i; i < chainSize; i++){
			sum += p[i];
		}

		while (sum < upperLimit){
			if (isPrime(sum)){
				cout << "Sum: " << sum << ", " << "length: " << chainSize << endl;
				return;
			}
			sum -= p[i - chainSize];
			sum += p[i];
			i++;
		}
		chainSize--;
	}

}