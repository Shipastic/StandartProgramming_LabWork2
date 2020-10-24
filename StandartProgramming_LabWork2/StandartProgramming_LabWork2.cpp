
#include <iostream>
#include <fstream>
#include "FindAlgorithms.h"
#include "SortAlgorithms.h"
using namespace std;
typedef int T;  // тип элементов
typedef int hashTableIndex; // индекс в хеш-таблице
#define compEQ(a,b) (a == b)
typedef struct Node_ {
	T data;// данные, хранящиеся в вершине
	struct Node_ *next; // следующая вершина
} Node;
Node **hashTable;
int hashTableSize;
hashTableIndex myhash(T data);
Node *insertNode(T data);
void deleteNode(T data);
Node *findNode(T data);

int main()
{
	setlocale(LC_ALL, "Russian");
	int kod;	//Код меню
	int search = 0;	// Число для поиска
	int num = 0;	// Количество элементов массива
	int arr[40];	//массив на 40 элементов
	int result = 0;	// Искомый индекс элемента
	int i, *a, maxnum;
	ofstream out("List.txt");

	while (true)
	{
		cout<< "Выберите нужный пункт меню путем нажатия соответствующей цифры" << endl<<endl
			<< "Бинарный поис...................- 1." << endl
			<< "Линейный поиск..................- 2." << endl
			<< "Поиск методом вычисления адреса.- 3." << endl
			<< "Сортировка пузырьком............- 4." << endl
			<< "Сортировка вставками............- 5." << endl
			<< "Сортировка методом выбора.......- 6." << endl
			<< "Выход...........................- 0." << endl<<endl
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cin >> kod;

		switch (kod) 
		{
			
		case 1:	//=================== Бинарный поиск ===============================
			cout << "Бинарный поиск" << endl;
			cout << "\nEnter the number of elements: ";
			cin >> num;
			cout << "\nEnter " << num << " elements in ascending order: ";
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			cout << "\nEnter your search element: ";
			cin >> search;
			result = BinarySearch(num, arr, search);
			if (result == -1)
				cout << "Value is not Found !!!"<<endl;
			else
			{
				cout << "\nElement Found at " << result << " position"<<endl;
			}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
			
		case 2:	//=================== Линейный поиск ================================
			cout << "Линейный поиск" << endl;
			cout << "\nEnter the number of elements: ";
			cin >> num;
			cout << "\nEnter " << num << " elements in ascending order: ";
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			cout << "\nEnter your search element: ";
			cin >> search;
			result = LineSearch(arr, search, num);
			if (result == -1)
				cout << "\nValue is not Found !!!"<<endl;
			else
			{
				cout << "\nElement Found at " << result + 1 << " position"<<endl;
			}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
			
		case 3:	//==================== Поиск методом вычисления адреса ===============
			cout << "Поиск методом вычисления адреса" << endl;
			cout << "\nEnter the number of elements: ";
			cin >> num;
			cout << "\nEnter " << num << " elements in ascending order: ";
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			cout << "Введите размер хеш-таблицы HashTableSize : ";
			cin >> hashTableSize;
			//a = new int[num];
			hashTable = new Node*[hashTableSize];
			for (i = 0; i < hashTableSize; i++)
				hashTable[i] = NULL;
			// заполнение хеш-таблицы элементами массива
			for (i = 0; i < num; i++)
			{
				insertNode(arr[i]);
			}
			// поиск элементов массива по хеш-таблице
			for (i = num - 1; i >= 0; i--)
			{
				findNode(arr[i]);
			}
			// вывод элементов массива в файл List.txt

			for (i = 0; i < num; i++)
			{
				out << arr[i];
				if (i < num - 1) out << "\t";
			}
			out.close();
			// сохранение хеш-таблицы в файл HashTable.txt
			out.open("HashTable.txt");
			for (i = 0; i < hashTableSize; i++) 
			{
				out << i << "  :  ";
				Node *Temp = hashTable[i];
				while (Temp) {
					out << Temp->data << " -> ";
					Temp = Temp->next;
				}
				out << endl;
			}
			out.close();
			// очистка хеш-таблицы
			for (i = num - 1; i >= 0; i--)
			{
				deleteNode(arr[i]);
			}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
			
		case 4:	//===================== Пузырьковая сортировка ================
			cout << "Сортировка пузырьком" << endl;
			cout << "\nEnter the number of elements: ";
			cin >> num;
			cout << "\nEnter " << num << " elements in ascending order: ";
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			bubbleSort(arr, num);
			cout << "Отсортированный массив: " << endl;
			for (int i = 0; i < num; i++)
				cout << arr[i] <<endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
			
		case 5:	//===================== Сортировка вставками ==================
			cout << "Сортировка вставками" << endl;
			cout << "\nEnter the number of elements: ";
			cin >> num;
			cout << "\nEnter " << num << " elements in ascending order: ";
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			insertSort(arr, num);
			cout << "Отсортированный массив: " << endl;
			for (int i = 0; i < num; i++)
				cout << arr[i] << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
			
		case 6:	//================== Сортировка методом выбора ================
			cout << "Сортировка методом выбора" << endl;
			cout << "\nEnter the number of elements: ";
			cin >> num;
			cout << "\nEnter " << num << " elements in ascending order: ";
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			selectSort(arr, num, 0);
			cout << "Отсортированный массив: " << endl;
			for (int i = 0; i < num; i++)
				cout << arr[i] << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		case 0:
			exit(0);
			break;
		}

	}
}

// хеш-функция размещения вершины
hashTableIndex myhash(T data) {
	return (data % hashTableSize);
}

// функция поиска местоположения и вставки вершины в таблицу
Node *insertNode(T data) {
	Node *p, *p0;
	hashTableIndex bucket;
	// вставка вершины в начало списка
	bucket = myhash(data);
	if ((p = new Node) == 0) {
		fprintf(stderr, "Нехватка памяти (insertNode)\n");
		exit(1);
	}
	p0 = hashTable[bucket];
	hashTable[bucket] = p;
	p->next = p0;
	p->data = data;
	return p;
}

//функция удаления вершины из таблицы
void deleteNode(T data) {
	Node *p0, *p;
	hashTableIndex bucket;
	p0 = 0;
	bucket = myhash(data);
	p = hashTable[bucket];
	while (p && !compEQ(p->data, data)) {
		p0 = p;
		p = p->next;
	}
	if (!p) return;
	if (p0)
		p0->next = p->next;
	else
		hashTable[bucket] = p->next;
	free(p);
}
// функция поиска вершины со значением data
Node *findNode(T data) {
	Node *p;
	p = hashTable[myhash(data)];
	while (p && !compEQ(p->data, data))
		p = p->next;
	return p;
}
