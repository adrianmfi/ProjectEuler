#include "problem51.h"
#include "util.h"
#include <iostream> 
#include <Windows.h>

#include <set>

using namespace std;

int main(){
	LARGE_INTEGER start, end, ticksPerSecond;
	QueryPerformanceCounter(&start);
	
	problem51();

	QueryPerformanceCounter(&end);
	QueryPerformanceFrequency(&ticksPerSecond);
	double seconds = (double)(end.QuadPart - start.QuadPart) / (ticksPerSecond.QuadPart);
	cout << "Number of ticks: " << (end.QuadPart - start.QuadPart) << endl;
	cout << "Runtime [s]: " << seconds << endl;

}
