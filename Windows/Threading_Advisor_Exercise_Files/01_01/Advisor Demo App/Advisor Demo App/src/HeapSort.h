// HEAP SORT

#include <iostream>
#include <iomanip>

using namespace std;

/* help heapsort() to bubble down starting at pos[ition] */
void heapbubble(int pos, int array[], int len)
{
	int z = 0;
	int max = 0;
	int tmp = 0;
	int left = 0;
	int right = 0;

	z = pos;

	for (;;)
	{
		left = 2 * z + 1;
		right = left + 1;

		int zIndex = (int)z;
		int maxIndex = (int)max;
		int leftIndex = (int)left;
		int rightIndex = (int)right;
		

		if (left >= len)
			return;
		else if (right >= len)
			max = left;
		else if (array[leftIndex] > array[rightIndex])
			max = left;
		else
			max = right;

		if (array[zIndex] > array[maxIndex])
			return;

		tmp = array[zIndex];
		array[zIndex] = array[maxIndex];
		array[maxIndex] = tmp;
		z = max;
	}
}

/* preform the heapsort */
void heapsort(int array[], int len)
{
	int i = 0;
	int tmp = 0;

	for (i = len / 2; i >= 0; --i)
		heapbubble(i, array, len);

	for (i = len - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		heapbubble(0, array, i);
	}
}


void HeapSort()
{
	int *heapSortList = new int[ARRAY_SIZE];

	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		heapSortList[i] = g_pUnsorted[i];
	}

	// print the original array 
	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << heapSortList[i] << "\t";
	
	cout << "\n\n";

	// perform the actual HeapSort
	heapsort(heapSortList, ARRAY_SIZE);

	// print the heapsorted array 
	printf("After:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << heapSortList[i] << "\t";

	cout << "\n\n";

}




