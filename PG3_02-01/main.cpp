#include <stdio.h>
//template <typename T>
//
//
//T add(T a, T b) {
//	return static_cast<T>(a + b); //You can decide what type you want the variable to be
//								 // Int, Float etcetc.
//}
//
//template<typename G>
//
//G subtract(G a, G b) {
//	return static_cast<G>(a - b);
//}

template <typename T> T add(T a, T b) { return a + b; }

template<>

float add<float>(float a, float b) { return a - b;}

float add(float a, float b) { return a * b; }


int main() {
	/*float a;
	int b;
	a = 100;
	b = 50;

	printf("%f\n", add<float>(a, b));
	printf("%d\n", subtract<int>(a, b));*/

	printf("%d\n", add<int>(114, 514));
	printf("%f\n", add<float>(11.4f, 51.4f));
	printf("%f\n", add(11.4f, 51.4f));

	return 0; }