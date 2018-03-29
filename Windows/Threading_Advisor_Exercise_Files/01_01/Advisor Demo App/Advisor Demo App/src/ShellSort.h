// SHELL SORT

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

void shellsort(int a[], int total, int index)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;

	for (k = 0; k < index; k++) 
	{
		for (i = k; i < total; i += index) 
		{
			l = a[i];
			for (j = (i - index); j >= 0; j -= index) 
			{
				if (a[j] > l)
					a[j + index] = a[j];
				else
					break;
			}

			a[j + index] = l;
		}
	}
}


void ShellSort()
{
	int *shellList = new int[ARRAY_SIZE];
	
	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		shellList[i] = g_pUnsorted[i];
	}

	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << shellList[i] << "\t";
	
	cout << "\n\n";

	// ascend sort the list using Shell Sort algorithm
	shellsort(shellList, ARRAY_SIZE, 1);

	printf("After:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << shellList[i] << "\t";
	
	cout << "\n\n";

}


