#include "util.h"
#include <iostream>
using namespace std;
void problem38(){
for (long i = 1; i < 10000; i++){
	long long concatted = i;
	int j = 2;

	while (concatted < 10000){
		concatted = concatIntegers(concatted, concatted*j);
		j++;
	}
	if (isPandigital(concatted)) cout << concatted << endl;
}
}