// BUBBLE SORT

// THIS IS THE FIRST HEADER INCLUDED
// include BubbleSort.h in other sorting headers 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <ctime>

// size of our unsorted list
// working set must be large enough for Advisor to get meaningful data
#define ARRAY_SIZE 1024 

// this unsorted integer array of 1024 items will be resorted 
// using 8 different popular sorting algorithms
int *g_pUnsorted = new int[ARRAY_SIZE];

using namespace std;

// swap 2 numbers
void Swap(int &a, int &b)
{
	// swap two elements 
	int temp = a;
	a = b;
	b = temp;
}

// ascend sort the list 
void bubbleSort(int *a)
{
	//loop to determine number of passes
	for (int pass = 0; pass < ARRAY_SIZE; pass++)
	{
		// loop to control number of checks per pass, 
		// have number be less than array size
		// since the first pass will sink largest/smallest value right away
		for (int i = 0; i < ARRAY_SIZE - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				// swap elements if lower element is greater 
				// (if your doing ascending order)
				Swap(a[i], a[i + 1]);
			}
		}
	}
}

// bubble sort task
void BubbleSort()
{
	int *bubbleSortList = new int[ARRAY_SIZE];
	
	// copy the contents of the original list 
	// into this temporary one for sorting
	// this is so the original list is unchanged for the other sorting algorithms
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		bubbleSortList[i] = g_pUnsorted[i];
	}

	printf("Before:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << bubbleSortList[i] << "\t";

	// perform the BubbleSort
	bubbleSort(bubbleSortList);

	printf("\n\nAfter:\n");
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << bubbleSortList[i] << "\t";

	printf("\n\n");
}


