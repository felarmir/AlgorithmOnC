//
//  CombSort.c
//  Comb sort on C
//
//  Created by Denis Andreev on 20/04/2017.
//  Copyright © 2017 Denis Andreev. All rights reserved.
// 

#include <stdio.h>

typedef int bool;
#define true  1
#define false  0

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp; 
}

void array_print(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 5, 18, 11, 4, 9, 8, 1, 17, 7, 2, 3, 16, 6, 12, 15, 14, 13};
	double factor = 1.2473309;
	int step = (sizeof(arr)/sizeof(*arr));

	printf("After sort:\n");
	array_print(arr, (sizeof(arr)/sizeof(*arr)));

	while (step > 1) {
		for (int i = 0; (i + step) < (sizeof(arr)/sizeof(*arr)); ++i)
		{
			if (arr[i] > arr[i+step])
			{
				swap(&arr[i], &arr[i+step]);
			}
		}
		step /= factor;
	}

	// and bubble
	for (int i = 0; i < (sizeof(arr)/sizeof(*arr))-1; i++)
	{
		bool swaped = false;
		for (int j = 0; j < (sizeof(arr)/sizeof(*arr)) - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			    swaped = true;
			}
		}
		if (!swaped) 
		{
			break;
		}
	}
	printf("Before sort:\n");
	array_print(arr, (sizeof(arr)/sizeof(*arr)));

	return 0;
}