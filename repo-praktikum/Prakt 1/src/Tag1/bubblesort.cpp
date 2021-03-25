/*
 * bubblesort.cpp
 *
 *  Created on: 25.03.2021
 *      Author: pi
 */
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void swap(int *xp, int *yp)
{
    int aux = *xp;
    *xp = *yp;
    *yp = aux;
}

// the optimized version
//complexity O(n2), too high, not the best
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true; //we remember if we swapped
        }
     }

     // IF no two elements were swapped by inner loop, then break
     // which means we are finished, this allows us to know if the list
     // is already sorted before finishing
     if (swapped == false)
        break;
   }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<";";
    cout<<endl;
}

int main(){
	srand(time(nullptr));
	int i, l=32;
	int *myarray=new int[l];
	for(i=0;i<l;i++){
		myarray[i]=rand()%100;
	}
	printArray(myarray, l);
	bubbleSort(myarray, l);
	printArray(myarray, l);
	delete [] myarray;
	return 0;
}

