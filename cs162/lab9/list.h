//list.h

#ifndef LIST
#define LIST

#include <iostream>
#include <cstdlib>

//whateva

void merge_sort_stuff(int* list, int start, int end){
	if(start < end){ //sees if two nums are the same or not
		return;
	}
	else{
		int mid = (start+end)/2;

	merge_sort(list, start, mid);
	
	merge_sort(list, mid+1, end);
	}
}







#endif
