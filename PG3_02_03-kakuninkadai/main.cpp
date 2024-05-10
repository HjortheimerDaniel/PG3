#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef void(*PFunc)(int *);

void Even() { //if we selected an even number
	printf("\n������I�т܂����A�T�C�R����U��܂�\n");
}
void Odd() { //if we selected an odd number
	printf("\n���I�т܂����A�T�C�R����U��܂�\n");
};

void Other() { //if we entered something that were not allowed to
	printf("\n��������Ȃ�T�C�R����U��Ȃ��񂶂�Ȃ��ł����H�H�I�H�I�H\n");
}

void DispRightResult(int* result) { //if we guessed right
	printf("����!\n");
}

void DispWrongResult(int* result) { //if we guessed incorrect
	printf("�s����!\n");
}

void SetTimeout(PFunc counter, int second) { //how long it takes before we show the answer / how long it takes to roll the dice
	Sleep(second); //how many seconds we wait
	counter(&second);
}

int main() {

	void(*pfunc)(); //this is where we enter the function
	PFunc counter; //another way to enter the function, where we use the typedef up top
	int dice, answer;

	unsigned int currentTime = (unsigned int)time(nullptr); //a variable where we take the time
	srand(currentTime); //using time to get a new random variable every time we execute
	dice = rand() % 6 + 1; //the random value is between 1 and 6
	printf("�U�����T�C�R���͊(1, 3, 5)�Ȃ�P����́A����(2, 4, 6)�Ȃ�Q����͂��Ă��������F�@");
	scanf_s("%d", &answer); //variable where we store the answer the user inputted

	if (answer == 2) { // if the number we entered can be divided by 2 and we didnt answer something higher than 6
		pfunc = Even;
	}
	else if (answer == 1) {  // if the number we entered can NOT be divided by 2 and we didnt answer something higher than 6
		pfunc = Odd;
	}
	else { //if we entered something weird
		pfunc = Other;
	}

	pfunc(); //run the function that is inside pfunc()

	if (pfunc == Even && dice % 2 == 0 || pfunc == Odd && dice % 2 != 0) { //if the number we entered is even and the dice can be divided by two OR the number we entered cant be divided by two and same with the dice
		counter = DispRightResult;
		SetTimeout(counter, 3000);
	}
	else if(pfunc == Even && dice % 2 != 0 || pfunc == Odd && dice % 2 == 0) { //we entered an even number and the dice is odd OR the entered an odd number and the dice is even
		counter = DispWrongResult;
		SetTimeout(counter, 3000);
	}
	

	//printf("%d\n", answer);
	//printf("%d\n", dice);

	/*if (answer == dice) {
		printf("����");
	}
	else {
		printf("�s����");

	}*/


	return 0; }