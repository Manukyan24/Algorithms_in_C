#include <stdio.h>
#include <stdlib.h>


/*

		int* A is array that will be sorted
		int p is lower border index of A from which array will be sorted 
		int r is upper border index of A until which array will be sorted
		int q is (p+r)/2

		(In merge function, this indexes have little another role. Merge() function will be merge A[p...q] and A[q+1...r] sorted arrays in A )
	

*/



void merge(int* A, int p, int q, int r){
	int l_size = q-p+1;
	int r_size = r - q ;
	int* L = (int * )malloc( l_size * sizeof(int) );
	int* R = (int * )malloc( r_size * sizeof(int) );
	int i=0;
	
	for (i=0;i<l_size;i++){
		L[i] = A[p + i];
	}
	for (i=0;i<r_size;i++){
		R[i] = A[(q + 1) + i];
	}
	int j,k;
	
	for (i=p, j = 0, k = 0; i < r+1; i++){
			if (j == l_size){
					A[i] = R[k++];
					continue;  
				}
			if (k == r_size){
					A[i] = L[j++];
					continue;
				}
			A[i] = (L[j] < R[k]) ? L[j++] : R[k++];
			}


	
	free(L);
	free(R);
}

void merge_sort(int * A, int p, int r){
	int q = (p+r)/2;
	if(p < r){
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A, p, q, r);
	}
}


int main(){
	// For testing
	int A[] = {10,9,8,8,8,8,3,4,2,1,5,-1516112,0 ,2};
	int p = 0;
	int r = sizeof(A)/sizeof(int) - 1;
	merge_sort(A,p,r);
	
	//Displaying array
	for (p=0;p<r+1;p++){
		printf("%d\n", A[p]);
	}
	
	return 0; 

}




