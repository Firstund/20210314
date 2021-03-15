#include <ctime>
#include <iostream>
#include <conio.h> 
#include"CAuto.h"

using namespace std;

void Start()
{
#ifdef CAutoIsHere
	cout << "자동으로 숫자를 맞추는 코드가 실행중입니다." << endl << endl;
#endif
	cout << "------------------숫자맞추기 게임---------------------" << endl;
}
int SetMaximum(int &maximumNum)
{
	int select = 0;
	cout << "난이도 선택: 1->쉬움 (1~100), 2->보통 (1~1000), 3->어려움(1~10000), 4->불가능함(1~2100000000), 5->종료" << endl;
	while (true)
	{
		cin >> select;
		if (select < 6 && select > 0)
		{
			break;
		}
		else
			cout << "1부터 5사이의 숫자를 입력해 주세요." << endl;
	}
	return select;
}
void SetTargetNum(int& targetNum, int maximum)
{
	targetNum = (rand() % (maximum + 1));
}
#ifdef CAutoIsHere
void Quetions(int targetNum, int maximum, int &sear, CAuto* a)
{
	system("CLS");
	//cout << targetNum << endl << endl; // 숫자 맞추기 자동화 프로그램 실험용
	int answer = 0;
	while (true)
	{
		sear++;
		cout << "숫자를 입력하세요->";

		answer = a->AutoSearch();
		cout << answer << endl;

		if (answer < 0 || answer > maximum)
			cout << "0부터 " << maximum << "사이의 숫자만 입력하세요." << endl << endl;
		else if (answer == targetNum)
		{
			cout << "정답입니다!" << endl;

			cout << sear << "회 만에 수를 맞혔습니다." << endl;
			cout << endl << "계속하려면 아무 키나 누르십시오." << endl;
			_getch();

			cout.flush();
			system("CLS");
			break;
		}
		else
		{
			cout << "오답입니다." << endl;
			if (answer > targetNum)
			{
				cout << "맞춰야할 숫자는 " << answer << "보다 작습니다." << endl;

				a->SetTIOC(false);

			}
			else
			{
				cout << "맞춰야할 숫자는 " << answer << "보다 큽니다." << endl;

				a->SetTIOC(true);

			}
			cout << endl;
		}
		cout.flush();
	}

}
#else
void Quetions(int targetNum, int maximum, int &sear)
{
	system("CLS");
	//cout << targetNum << endl << endl; // 숫자 맞추기 자동화 프로그램 실험용
	int answer = 0;
	while (true)
	{
		sear++;
		cout << "숫자를 입력하세요->";

		cin >> answer;

		if (answer < 0 || answer > maximum)
			cout << "0부터 " << maximum << "사이의 숫자만 입력하세요." << endl << endl;
		else if (answer == targetNum)
		{
			cout << "정답입니다!" << endl;

			cout << sear << "회 만에 수를 맞혔습니다." << endl;
			cout << endl << "계속하려면 아무 키나 누르십시오." << endl;

			_getch();

			cout.flush();
			system("CLS");
			break;
		}
		else
		{
			cout << "오답입니다." << endl;
			if (answer > targetNum)
			{
				cout << "맞춰야할 숫자는 " << answer << "보다 작습니다." << endl;
			}
			else
			{
				cout << "맞춰야할 숫자는 " << answer << "보다 큽니다." << endl;
			}
			cout << endl;
		}
		cout.flush();
	}

}
#endif
void ResetSearchNum(int& sear)
{
	sear = 0;
}
int main()
{
	bool haveToOut = false;

	int maximumNum = 0;
	int targetNum = 0;
	int searchNum = 0; 

#ifdef CAutoIsHere
	CAuto a, * aPt;
	aPt = &a;
#endif
	time_t t;
	while (true)
	{
		t = time(NULL);

		srand(t);

		Start();
#ifdef CAutoIsHere
		aPt->Reset();
#endif
		searchNum = 0; // searchNum Reset

		switch (SetMaximum(maximumNum))
		{
		case 1:
			maximumNum = 100;
			break;
		case 2:
			maximumNum = 1000;
			break;
		case 3:
			maximumNum = 10000;
			break;
		case 4:
			maximumNum = 2100000000;
			break;
		case 5:
			haveToOut = true;
			break;
		}
		
		if (haveToOut)
			break;

#ifdef CAutoIsHere
		aPt->Setmaximum(maximumNum);
#endif

		SetTargetNum(targetNum, maximumNum);
#ifdef CAutoIsHere
		Quetions(targetNum, maximumNum, searchNum, aPt);
#else
		Quetions(targetNum, maximumNum, searchNum);
#endif
	}

	return(0);
}