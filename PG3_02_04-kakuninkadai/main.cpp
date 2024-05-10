#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void(*PFunc)(int*);

void Even() { //if we entered an even number
	printf("\n偶数を選びました、サイコロを振ります\n");
}
void Odd() { //if we entered an odd number
	printf("\n奇数を選びました、サイコロを振ります\n");
};

void Other() { //if we entered something weird
	printf("\nこうするならサイコロを振らないんじゃないですか？？！？！？\n");
}

void DispRightResult(int* result) { //we got it right
	printf("正解!\n");
}

void DispWrongResult(int* result) { //we got it wrong
	printf("不正解!\n");
}

void SetTimeout(PFunc counter, int second) { //wait a determined time before we show the answer to build suspension
	Sleep(second); //how many seconds we wait
	counter(&second);
}

int main(int argc, const char *argv[]) {

	void(*pfunc)(); //this is where we enter the function
	PFunc counter; //a typedef where we enter a fuction
	int dice, answer{};

	unsigned int currentTime = (unsigned int)time(nullptr); //keeps track of the current time
	srand(currentTime); //use the current time to get a new value every time, thus creating a random value
	dice = rand() % 6 + 1; //the value should be between 1 and 6
	printf("振ったサイコロは奇数(1, 3, 5)か偶数(2, 4, 6)を選んでください：　");
	auto fx = [](int &answer) {
		scanf_s("%d", &answer); //keep track of what input we did
		return answer; //return the input
		};
	fx(answer); //run the code with what we inputted as a reference for if we are right or wrong

	if (answer % 2 == 0 && answer <= 6 && answer > 0) { //if our number is even and not above 6
		pfunc = Even;
	}
	else if (answer % 2 != 0 && answer <= 6 && answer > 0) { //if our number is odd and not above 6
		pfunc = Odd;
	}
	else { //if we entered something weird
		pfunc = Other;
	}

	pfunc(); //run the function inside pfunc

	if (pfunc == Even && dice % 2 == 0 || pfunc == Odd && dice % 2 != 0) { //if our number and the dice is even OR our number and the dice is odd
		counter = DispRightResult; //we got it right
		SetTimeout(counter, 3000); //wait 3 seconds before showing answer
	}
	else if (pfunc == Even && dice % 2 != 0 || pfunc == Odd && dice % 2 == 0) { //if number is even and dice is odd OR number is odd and dice is even
		counter = DispWrongResult; //we got it wrong
		SetTimeout(counter, 3000); //wait 3 seconds before showing answer
	}



	return 0;
}