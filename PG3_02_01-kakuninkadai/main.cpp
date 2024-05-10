#include <stdio.h>

template <typename T> //template which lets you enter a variable afterwards


//find the smallest variable
T min(T a, T b) { 
	if (a < b) { //if a is smallets, return a
		return a;
	} //otherwise return b
	return b;
}

int main() {
	

	printf("%d\n", min<int>(50, 20)); //this makes them int
	printf("%f\n", min<float>(50, 20)); //float
	printf("%lf\n", min<double>(20, 50)); //double

	return 0; }