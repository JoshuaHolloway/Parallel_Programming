#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include "BubbleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "TreeSort.h"

// include Thread object for parallel task execution
//#include "TaskHandler.h"

// Annotate
// Step 2.3 to do annotations
#include "advisor-annotate.h"

using namespace std;

int main()
{
	// normally you would want to generate a seed in order to have truly random numbers
	// but lets have rand return the usuals. 
	// load 1024 random values into array
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		g_pUnsorted[i] = rand();
	}

	// serial execution of all 8 sorting tasks
	cout << "\n-------------------------------------------------\n";
	cout << "                BUBBLE SORT                        \n";
	cout << "---------------------------------------------------\n";
	BubbleSort();

	cout << "\n-------------------------------------------------- \n";
	cout << "              INSERTION SORT                         \n";
	cout << "---------------------------------------------------- \n";
	InsertionSort();

	cout << "\n-------------------------------------------------- \n";
	cout << "              SELECTION SORT                         \n";
	cout << "---------------------------------------------------- \n";
	SelectionSort();

	cout << "\n-------------------------------------------------- \n";
	cout << "                QUICK SORT                           \n";
	cout << "---------------------------------------------------- \n";
	QuickSort();

	cout << "\n---------------------------------------------------- \n";
	cout << "                 TREE SORT								\n";
	cout << "------------------------------------------------------ \n";
	TreeSort();

	cout << "\n-------------------------------------------------- \n";
	cout << "                MERGE SORT                           \n";
	cout << "---------------------------------------------------- \n";
	MergeSort();

	cout << "\n-------------------------------------------------\n";
	cout << "                 HEAP SORT                         \n";
	cout << "---------------------------------------------------\n";
	HeapSort();

	cout << "\n-------------------------------------------------- \n";
	cout << "                SHELL SORT                           \n";
	cout << "---------------------------------------------------- \n";
	ShellSort();

	return 0;

}