#include "utility_funcs.h"


void display_array(int* Array, int size_of_array){
		int i;
		for(i = 0;i < size_of_array;i++){
				printf("%d ", Array[i]);
			}
		printf("\n");
	}
