#include <stdio.h>
#include <stdlib.h>
#include "utility_funcs.h"

/*

	Problem 2.3.4 Recursive implementation of insertion sort;
	Time of this algorithm, is discribing by following recursive equation
	T(n) = T(n-1) + Thetha(n)

	because insert() function works for Theta(n) time:
	
*/



void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int* A, int upper_border){
		int i=upper_border;
		while ((i > 0) && A[i] < A[i-1]){
				swap(&A[i], &A[i-1]);
				i--;
			}
	}


void rec_ins_sort(int* A, int upper_border){

		if (--upper_border > 0){
				rec_ins_sort(A, upper_border);
				insert(A, upper_border  + 1);
			}	

	}



int main(){

	int A[] = {2,4,5,0,-15,2,14,2,0,0,0,0,2};
	int up = sizeof(A)/sizeof(int) - 1;
	
	rec_ins_sort(A,up);

	int i;
	/*
	for (i=0;i<=up;i++){
			printf(" %d ", A[i]);
		}
	*/

	display_array(A,up);


	return 0;

}
