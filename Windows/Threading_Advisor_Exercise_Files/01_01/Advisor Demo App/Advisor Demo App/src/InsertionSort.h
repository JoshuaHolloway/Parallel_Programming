// INSERTION SORT

#include <iostream>
#include <iomanip>

using namespace std;

int fm(int arr[], int b, int n)
{
	int f = b;
	int c;

	for (c = b + 1; c < n; c++)
		if (arr[c] < arr[f])
			f = c;

	return f;
}

void isort(int arr[], int n)
{
	int s, w;
	int sm;

	for (s = 0; s < n - 1; s++)
	{
		w = fm(arr, s, n);
		sm = arr[w];
		arr[w] = arr[s];
		arr[s] = sm;
	}
}

void InsertionSort()
{
	int *insertionSortList = new int[ARRAY_SIZE];

	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		insertionSortList[i] = g_pUnsorted[i];
	}

	cout << "Before:\n";
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << insertionSortList[i] << "\t";
	
	cout << "\n\n";

	// perform the actual InsertionSort
	isort(insertionSortList, ARRAY_SIZE);

	cout << "After:\n";
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << insertionSortList[i] << "\t";

	cout << "\n\n";

}



