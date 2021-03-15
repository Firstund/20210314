#include <ctime>
#include <iostream>
#include <conio.h> 
#include"CAuto.h"

using namespace std;

void Start()
{
#ifdef CAutoIsHere
	cout << "�ڵ����� ���ڸ� ���ߴ� �ڵ尡 �������Դϴ�." << endl << endl;
#endif
	cout << "------------------���ڸ��߱� ����---------------------" << endl;
}
int SetMaximum(int &maximumNum)
{
	int select = 0;
	cout << "���̵� ����: 1->���� (1~100), 2->���� (1~1000), 3->�����(1~10000), 4->�Ұ�����(1~2100000000), 5->����" << endl;
	while (true)
	{
		cin >> select;
		if (select < 6 && select > 0)
		{
			break;
		}
		else
			cout << "1���� 5������ ���ڸ� �Է��� �ּ���." << endl;
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
	//cout << targetNum << endl << endl; // ���� ���߱� �ڵ�ȭ ���α׷� �����
	int answer = 0;
	while (true)
	{
		sear++;
		cout << "���ڸ� �Է��ϼ���->";

		answer = a->AutoSearch();
		cout << answer << endl;

		if (answer < 0 || answer > maximum)
			cout << "0���� " << maximum << "������ ���ڸ� �Է��ϼ���." << endl << endl;
		else if (answer == targetNum)
		{
			cout << "�����Դϴ�!" << endl;

			cout << sear << "ȸ ���� ���� �������ϴ�." << endl;
			cout << endl << "����Ϸ��� �ƹ� Ű�� �����ʽÿ�." << endl;
			_getch();

			cout.flush();
			system("CLS");
			break;
		}
		else
		{
			cout << "�����Դϴ�." << endl;
			if (answer > targetNum)
			{
				cout << "������� ���ڴ� " << answer << "���� �۽��ϴ�." << endl;

				a->SetTIOC(false);

			}
			else
			{
				cout << "������� ���ڴ� " << answer << "���� Ů�ϴ�." << endl;

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
	//cout << targetNum << endl << endl; // ���� ���߱� �ڵ�ȭ ���α׷� �����
	int answer = 0;
	while (true)
	{
		sear++;
		cout << "���ڸ� �Է��ϼ���->";

		cin >> answer;

		if (answer < 0 || answer > maximum)
			cout << "0���� " << maximum << "������ ���ڸ� �Է��ϼ���." << endl << endl;
		else if (answer == targetNum)
		{
			cout << "�����Դϴ�!" << endl;

			cout << sear << "ȸ ���� ���� �������ϴ�." << endl;
			cout << endl << "����Ϸ��� �ƹ� Ű�� �����ʽÿ�." << endl;

			_getch();

			cout.flush();
			system("CLS");
			break;
		}
		else
		{
			cout << "�����Դϴ�." << endl;
			if (answer > targetNum)
			{
				cout << "������� ���ڴ� " << answer << "���� �۽��ϴ�." << endl;
			}
			else
			{
				cout << "������� ���ڴ� " << answer << "���� Ů�ϴ�." << endl;
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