#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int IntTotalValue = 0;//����� ���� ��������� ���������� �������
	vector<int> VecIntFirst;//������ ��������� ������
	srand(time(NULL));

	cout << "��������� ���������� ����������� �����" << endl << endl;

//���������� ������������ ������� �������

	cout << "������� �����, 0 - ����� ������������������" << endl;
	int* IntInput = new int;//��������� ���������� ��� �����
	for (;;)
	{
		cin >> *IntInput;
		if (*IntInput == 0) break;
		VecIntFirst.insert(VecIntFirst.end(), *IntInput);
		IntTotalValue += *IntInput;
	}
	delete IntInput;

//����� ���������� �������

	cout << "\n��������� ������: ";
	copy(VecIntFirst.begin(),
		VecIntFirst.end(),
		ostream_iterator<int>(cout, " ")
		);

//�� ������� ������� ������ � 2*N ���������� 
//� 2 ���� �������� � ���� ���������� ������� �������

	vector<int> VecIntSecond;
	for (int IntCount = 0; IntCount < 2; IntCount++)
	{
		VecIntSecond.insert(VecIntSecond.end(), VecIntFirst.begin(), VecIntFirst.end());
	}

//������������� ��������� ������� ������� ��������� ������� 

	int* IntSwapID = new int;
	for (int IntCount = 0; IntCount < VecIntSecond.size(); IntCount++)
	{
		*IntSwapID = rand() % VecIntSecond.size();
		swap(VecIntSecond[IntCount], VecIntSecond[*IntSwapID]);
	}
	delete IntSwapID;

//����� ������������� �������

	cout << "\n\n������������ ������: ";
	copy(VecIntSecond.begin(),   
		VecIntSecond.end(),    
		ostream_iterator<int>(cout, " ") 
		);

//������� ��������� ������� �� 2*N ���������

	VecIntSecond.erase(VecIntSecond.begin() + rand() % VecIntSecond.size());

//����� ����� �������� 1 ��������:

	cout << "\n\n�������� ������: ";
	copy(VecIntSecond.begin(),
		VecIntSecond.end(),
		ostream_iterator<int>(cout, " ")
		);

//���������� ���������� 2*N-1 ��������

	int* IntFinalValue = new int(0);
	for (int IntCount = 0; IntCount < VecIntSecond.size(); IntCount++)
	{
		*IntFinalValue += VecIntSecond[IntCount];
	}

//���������� ����� ����� ������� ���������� � ��������� �������� �������� �������:

	cout << "\n\n���������� ����� = " << (IntTotalValue * 2 - *IntFinalValue) << endl<<endl;

	delete IntFinalValue;
	system("PAUSE");
	return 0;
}