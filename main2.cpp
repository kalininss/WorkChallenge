#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int IntTotalValue = 0;//сумма всех элементов начального вектора
	vector<int> VecIntFirst;//пустой начальный вектор
	srand(time(NULL));

	cout << "Программа нахождения потерянного числа" << endl << endl;

//заполнение изначального массива данными

	cout << "Вводите числа, 0 - конец последовательности" << endl;
	int* IntInput = new int;//временная переменная для ввода
	for (;;)
	{
		cin >> *IntInput;
		if (*IntInput == 0) break;
		VecIntFirst.insert(VecIntFirst.end(), *IntInput);
		IntTotalValue += *IntInput;
	}
	delete IntInput;

//вывод начального массива

	cout << "\nВведенный массив: ";
	copy(VecIntFirst.begin(),
		VecIntFirst.end(),
		ostream_iterator<int>(cout, " ")
		);

//по условию создаем вектор с 2*N элементами 
//и 2 раза копируем в него содержимое первого вектора

	vector<int> VecIntSecond;
	for (int IntCount = 0; IntCount < 2; IntCount++)
	{
		VecIntSecond.insert(VecIntSecond.end(), VecIntFirst.begin(), VecIntFirst.end());
	}

//переставление элементов второго массива случайным образом 

	int* IntSwapID = new int;
	for (int IntCount = 0; IntCount < VecIntSecond.size(); IntCount++)
	{
		*IntSwapID = rand() % VecIntSecond.size();
		swap(VecIntSecond[IntCount], VecIntSecond[*IntSwapID]);
	}
	delete IntSwapID;

//вывод перемешанного массива

	cout << "\n\nПеремешанный массив: ";
	copy(VecIntSecond.begin(),   
		VecIntSecond.end(),    
		ostream_iterator<int>(cout, " ") 
		);

//удаляем случайный элемент из 2*N элементов

	VecIntSecond.erase(VecIntSecond.begin() + rand() % VecIntSecond.size());

//вывод после удаления 1 элемента:

	cout << "\n\nКонечный массив: ";
	copy(VecIntSecond.begin(),
		VecIntSecond.end(),
		ostream_iterator<int>(cout, " ")
		);

//складываем оставшиеся 2*N-1 элементы

	int* IntFinalValue = new int(0);
	for (int IntCount = 0; IntCount < VecIntSecond.size(); IntCount++)
	{
		*IntFinalValue += VecIntSecond[IntCount];
	}

//потерянное число равно разнице начального и конечного векторов деленное пополам:

	cout << "\n\nПотерянное число = " << (IntTotalValue * 2 - *IntFinalValue) << endl<<endl;

	delete IntFinalValue;
	system("PAUSE");
	return 0;
}