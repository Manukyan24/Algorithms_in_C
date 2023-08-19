#include <stdio.h>
#include <stdlib.h>



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
	int j= 0, k = 0;
	
	
	for (i = p; i < r+1; i++){

				if (L[j] <= R[k]){
						if (j < l_size){
							A[i] = L[j];
							j++;
						}
						else if (k < r_size){
								A[i] = R[k];
								k++;
							}
					}
				else{
							if(k < r_size){
							A[i] = R[k];
							k++;
							}
							else if (j < l_size){
									A[i] = L[j];
									j++;
								}
					}
		
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
	
	int A[] = {1,104,68,20,0,1,2,3,-150};
	int p = 0;
	int r = sizeof(A)/sizeof(int) - 1;
	int q = (p+r)/2;
	//printf("%d \n\n\n\n", r);
	merge_sort(A,p,r);
	//merge(A,p,q,r);
	for (p=0;p<r+1;p++){
		printf("%d\n", A[p]);
	}
	
	return 0; 

}




