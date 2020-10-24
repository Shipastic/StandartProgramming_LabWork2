#include <fstream>
//========================= Бинарный поиск ==========================
int BinarySearch(int n, int arr[], int search)
{
	int bot = 0;
	int top = n - 1;
	int mid;
	while (top >= bot)
	{
		mid = (top + bot) / 2;
		if (arr[mid] == search)
			return (mid + 1);
		else
		{
			if (arr[mid] < search)
			{
				bot = mid + 1;
			}
			else
			{
				top = mid;
			}
		}
	}
	return -1;
}

//==================== Последовательный поиск элементов ==============
int LineSearch(int arr[], int search, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == search)
		{
			return i ;
		}
	}
	return -1;
}

////============ Поиск методом вычисления адреса ======================
//
//typedef int T;  // тип элементов
//typedef int hashTableIndex; // индекс в хеш-таблице
//#define compEQ(a,b) (a == b)
//typedef struct Node_ {
//	T data;// данные, хранящиеся в вершине
//	struct Node_ *next; // следующая вершина
//} Node;
//
//Node **hashTable;
//int hashTableSize;
//hashTableIndex myhash(T data);
//Node *insertNode(T data);
//void deleteNode(T data);
//Node *findNode(T data);
//
//
//
//// функция поиска местоположения и вставки вершины в таблицу
//Node *insertNode(T data) {
//	Node *p, *p0;
//	hashTableIndex bucket;
//	// вставка вершины в начало списка
//	bucket = myhash(data);
//	if ((p = new Node) == 0) {
//		fprintf(stderr, "Нехватка памяти (insertNode)\n");
//		exit(1);
//	}
//	p0 = hashTable[bucket];
//	hashTable[bucket] = p;
//	p->next = p0;
//	p->data = data;
//	return p;
//}
//
////функция удаления вершины из таблицы
//void deleteNode(T data) {
//	Node *p0, *p;
//	hashTableIndex bucket;
//	p0 = 0;
//	bucket = myhash(data);
//	p = hashTable[bucket];
//	while (p && !compEQ(p->data, data)) {
//		p0 = p;
//		p = p->next;
//	}
//	if (!p) return;
//	if (p0)
//		p0->next = p->next;
//	else
//		hashTable[bucket] = p->next;
//	free(p);
//}
//
//// функция поиска вершины со значением data
//Node *findNode(T data) {
//	Node *p;
//	p = hashTable[myhash(data)];
//	while (p && !compEQ(p->data, data))
//		p = p->next;
//	return p;
//}
