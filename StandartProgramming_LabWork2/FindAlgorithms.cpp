#include <fstream>
//========================= �������� ����� ==========================
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

//==================== ���������������� ����� ��������� ==============
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

////============ ����� ������� ���������� ������ ======================
//
//typedef int T;  // ��� ���������
//typedef int hashTableIndex; // ������ � ���-�������
//#define compEQ(a,b) (a == b)
//typedef struct Node_ {
//	T data;// ������, ���������� � �������
//	struct Node_ *next; // ��������� �������
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
//// ������� ������ �������������� � ������� ������� � �������
//Node *insertNode(T data) {
//	Node *p, *p0;
//	hashTableIndex bucket;
//	// ������� ������� � ������ ������
//	bucket = myhash(data);
//	if ((p = new Node) == 0) {
//		fprintf(stderr, "�������� ������ (insertNode)\n");
//		exit(1);
//	}
//	p0 = hashTable[bucket];
//	hashTable[bucket] = p;
//	p->next = p0;
//	p->data = data;
//	return p;
//}
//
////������� �������� ������� �� �������
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
//// ������� ������ ������� �� ��������� data
//Node *findNode(T data) {
//	Node *p;
//	p = hashTable[myhash(data)];
//	while (p && !compEQ(p->data, data))
//		p = p->next;
//	return p;
//}
