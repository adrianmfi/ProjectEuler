#include "problem46.h"
#include "util.h"
#include <iostream>
using namespace std;
void problem46(){
	int n = 10000;

	vector<int> oddCompNum;
	vector<int> primes = primeSieve(n);
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

	for (int i = 3; i < n; i+=2){
		if (!nums[i] ) oddCompNum.push_back(i);
	}
	delete[] nums;

	for (int i = 0; i < primes.size(); i++){
		int a = primes[i];
		int l = 1;
		while (a + 2 * pow(l, 2) <= oddCompNum[oddCompNum.size() - 1]){
			int y = a + 2 * pow(l, 2) ;
			auto x = find(oddCompNum.begin(), oddCompNum.end(), y);
			
			if (x != oddCompNum.end()){
				oddCompNum.erase(x);
			}
			l++;
		}
	}
	cout << oddCompNum[0] << endl;
}