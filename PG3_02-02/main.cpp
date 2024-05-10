#include <stdio.h>

int Recursive(int n) {
	if (n <= 1) { //if the value we entered is less or 1
		return (1);
	}
	return (n * Recursive(n - 1)); //else return this
}

int main() {

	int n = 6; 
	int m = 5; 
	int result;
	int result2;

	result = Recursive(n); // 6 * 5 * 4 * 3 * 2 * 1 = 720
	result2 = Recursive(m); // 5 * 4 * 3 * 2 * 1 = 120
	printf("%d‚ÌŠKæ = %d\n", n, result);
	printf("%d‚ÌŠKæ = %d\n", m, result2);


	return 0; }