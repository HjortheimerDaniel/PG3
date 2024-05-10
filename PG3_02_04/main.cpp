#include <stdio.h>
#include <functional>


int main(int argc, const char *argv[]) {

	// [] captures the lambda
	// () parameter, same function as an int etc.
	// {} where you do the statement, i.e return
	// () call the function

	[]() {printf("lambda test\n"); }();

	auto fx = [](int i) {return i + 1; };
	printf("test one = %d\n", fx(2));

	int num = 10;
	auto fx2 = [=](int i) {return num + i; }; // [=] means we add whatever we decide "i" is gonna be

	printf("test two = %d\n", fx2(2));

	std::function<int(int)> f3 = [](int i) {return i + 1; };
	auto fx3 = [](int i) {return i + 1; };

	printf("%d\n", fx3(2));


	return 0; }