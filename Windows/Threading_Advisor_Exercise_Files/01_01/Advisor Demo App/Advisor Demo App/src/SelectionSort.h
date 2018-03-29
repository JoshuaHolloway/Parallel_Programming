// SELECTION SORT

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void printPass(int *a, const int size)
{
	static int pass = 0;
	printf("\npass %d: ", pass);
	for (int i = 0; i < size; i++)
		printf("%d  ", a[i]);

	printf("\n");
	pass++;
}

void selectionSort(int *&a, int size)
{
	//var to keep track of the smallest element's position in array a[]
	int smallest;

	//loop through N-1 elements number of times
	for (int i = 0; i < size - 1; i++)
	{
		// keep track of current smallest 
		//loop through from a[smallest] + 1 to a[size] to find the element with the min value
		// MUST init j = i + 1 to essentially 'cut' off the left side of the array for comparisons
		// this way you will only find the smallest value on the right side and swap with the
		// current smallest from where you cut array off at
		smallest = i; 
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[smallest])
			{
				smallest = j;
			}
		}

		// swap new smallest value with current smallest value
		swap(a[i], a[smallest]);

#ifdef _DEBUG
		printPass(a, size);
#endif

	}
}

// Selection Sort task
void SelectionSort()
{
	int *selectionList = new int[ARRAY_SIZE];
	
	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		selectionList[i] = g_pUnsorted[i];
	}

	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << selectionList[i] << "\t";

	cout << "\n\n";

	// ascend sort list using SelectionSort algorithm
	selectionSort(selectionList, ARRAY_SIZE);

	printf("\nAfter:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << selectionList[i] << "\t";

	cout << "\n\n";
}





