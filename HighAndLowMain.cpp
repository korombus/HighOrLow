#include <stdlib.h>
#include <time.h>

#define MAX 10

int CreateRandNum(int max);
int GetHighOrLow(int ran1, int ran2);

int main() {
	/*
		*/
	int rand1 = 0;
	while (true) {
		rand1 = CreateRandNum(MAX);
		printf("Now Number is %d.\nPlease push number button High( 1 ) or Low( 0 ) and Enter Key : ", rand1);

		int userInputNum = 0;
		scanf_s("%d", &userInputNum);
		if (userInputNum > 1 || userInputNum < 0) continue;

		int rand2 = CreateRandNum(MAX);
		int hol = GetHighOrLow(rand1, rand2);
		printf("\nNext Number is %d\n", rand2);

		if (userInputNum == hol) {
			printf("\nSuccessed!\n\n");
			rand1 = rand2;
		}
		else {
			printf("\nFailed...\n");
			printf("\nContinue? y( 1 ) or n( 0 ) : ");
			scanf_s("%d", &userInputNum );
			if (userInputNum == 1) continue;
			else break;
		}
	}
	return 0;
}

int CreateRandNum(int max) {
	srand((unsigned)time(NULL));
	return rand() % max;
}

int GetHighOrLow(int ran1, int ran2) {
	if (ran1 < ran2) { return 1; }
	else { return 0; }
}
