// QUICK SORT

#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

/// sort everything inbetween `low' <-> `high' 
void quicksort(int arr[], int low, int high)
{
	int i = low;
	int j = high;
	int y = 0;

	// compare value 
	int z = arr[(low + high) / 2];

	/// partition 
	do {
		// find member above 
		while (arr[i] < z) 
			i++;

		// find element below
		while (arr[j] > z) 
			j--;

		if (i <= j) 
		{
			// swap two elements 
			y = arr[i];
			arr[i] = arr[j];
			arr[j] = y;
			i++;
			j--;
		}

	} while (i <= j);

	// recursive calls
	if (low < j)
		quicksort(arr, low, j);

	if (i < high)
		quicksort(arr, i, high);
}

void QuickSort()
{
	int *quickSortList = new int[ARRAY_SIZE];
	
	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		quickSortList[i] = g_pUnsorted[i];
	}

	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << quickSortList[i] << "\t";
	
	cout << "\n\n";

	// ascend sort the list using QuickSort algorithm
	quicksort(quickSortList, 0, (ARRAY_SIZE - 1));

	printf("After:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << quickSortList[i] << "\t";
	
	cout << "\n\n";

}

