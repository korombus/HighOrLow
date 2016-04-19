#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int CreateRandNum(int max);
int GetHighOrLow(int ran1, int ran2);

int main() {
	/*
		1. 乱数1発生
		2. 乱数を表示して、ユーザに次の数は高いか低いかを予想してもらう
		3. ユーザの入力が確定したら、乱数を発生
		4. 乱数１と入力後の乱数の高低差を比較
		5. ユーザの予想と実際の高低差を比較
		6. 結果を表示
		7, 続けるか止めるかを選択
		8, 続けるならば1に戻る
		9. 止めるならば終了
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