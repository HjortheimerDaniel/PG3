#include <stdio.h>
#include <Windows.h>

void PrintHelloWorld() { printf("HelloWorld\n"); }

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
//int div(int a, int b) { return a / b; }

typedef int (*newType)(int a);
typedef void (*PFunc)(int*);

int Twice(int a) {
	return a * 2;
}
int Thrice(int a) {
	return a * 3;
}

void DispResult(int *s) {
	printf("%d秒待って実行されたよ\n", *s);
}

void SetTimeout(PFunc p, int second) {
	Sleep(second * 1000);
	p(&second);
}

int main() {

	//printf("%p", main);

	void (*pfunc)();
	

	pfunc = PrintHelloWorld;
	printf("PrintHelloWorldのアドレス＝%p\n", PrintHelloWorld);
	printf("pfuncの内容　＝　%p\n", *pfunc);
	pfunc(); //HelloWorld

	int l = 114;
	int h = 514;
	
	const int max = 3;

	int (*calc)(int, int); //this is a pointer

	calc = add; //since it is a pointer, here it points to the add function
	printf("%d\n", calc(l, h));
	calc = sub; //here we change the address to the sub function
	printf("%d\n\n", calc(l, h));

	int (*funcArr[max])(int, int) = {add, sub, mul, /*div*/}; //0 is add, 1 is sub etc.

	for (int i = 0; i < max; i++) { //add, sub, multi, div
		printf("%d\n", funcArr[i](l, h));
	}

	newType test;
	int j = 4;

	test = &Twice;
	printf("\n%d\n", test(j));

	test = &Thrice;
	printf("%d\n", test(j));

	printf("start\n");

	PFunc p;

	p = DispResult;
	SetTimeout(p, 2);

	return 0; }