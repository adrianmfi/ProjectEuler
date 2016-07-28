#include "problem47.h"
#include <iostream>
#include "util.h"
#include <set>
using namespace std;

void problem47(){ // Treeeeeeeeg
	int consecutive = 0;
	int antall = 4;
	int i = 2;
	while (consecutive < antall){
		if (!(i % 10000)) cout << i << endl;
		vector<int> p = factorize(i);
		set<int> s(p.begin(), p.end());
		if (s.size() == antall){
			consecutive++;
		}
		else consecutive = 0;
		i++;
	}
	cout << i - antall << endl;
}