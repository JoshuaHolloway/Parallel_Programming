// MERGE SORT

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

void mergesort(int a[], int low, int high)
{
	int i = 0;
	int length = high - low + 1;
	int pivot = 0;
	int merge1 = 0;
	int merge2 = 0;

	int *working = new int[length];

	if (low == high)
		return;

	pivot = (low + high) / 2;

	mergesort(a, low, pivot);
	mergesort(a, pivot + 1, high);

	for (i = 0; i < length; i++)
		working[i] = a[low + i];

	merge1 = 0;
	merge2 = pivot - low + 1;

	for (i = 0; i < length; i++) {
		if (merge2 <= high - low)
			if (merge1 <= pivot - low)
				if (working[merge1] > working[merge2])
					a[i + low] = working[merge2++];
				else
					a[i + low] = working[merge1++];
			else
				a[i + low] = working[merge2++];
		else
			a[i + low] = working[merge1++];
	}
}


void MergeSort()
{
	int *mergeList = new int[ARRAY_SIZE];
	
	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		mergeList[i] = g_pUnsorted[i];
	}

	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << mergeList[i] << "\t";

	cout << "\n\n";

	// ascend sort the list with MergeSort algorithm
	mergesort(mergeList, 0, ARRAY_SIZE - 1);

	printf("After:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << mergeList[i] << "\t";

	cout << "\n\n";

}
