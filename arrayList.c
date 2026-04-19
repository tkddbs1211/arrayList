#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

arrayList* createArrayList(int count) {
	arrayList* al;
	al = (arrayList*)malloc(sizeof(arrayList));

	al->data = (elementArrayList*)malloc(  
		sizeof(elementArrayList) * count); 
	al->size = 0;
	al->capacity = count;

	return al;
}

void destroyArrayList(arrayList* al) {
	free(al->data); 
	free(al);      
}

int isEmptyArrayList(arrayList* al) {
	if (al->size == 0) {
		return 1;                
	}
	else {
		return 0;           
	}
}

int isFullArrayList(arrayList* al) {
	if (al->size == al->capacity) { 
		return 1;
	}
	else {
		return 0;
	}
}

int sizeArrayList(arrayList* al) {   
	return al->size; 
}

int insertArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size) { 
		return 0;
	}

	if (al->size == al->capacity)
	{
		int newCapacity = al->capacity * 2;

		elementArrayList* newData = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * newCapacity);

		if (newData != NULL)
		{	
			printf("success\n");
			al->data = newData;
			al->capacity = newCapacity;
		}
	}

	for (int i = al->size-1; i >= pos; i--) {  
		al->data[i + 1] = al->data[i];        
	}										 

	al->data[pos] = item;    
	al->size++;				
	 
	return 1;				
}

elementArrayList deleteArrayList(
	arrayList* al, int pos) {
	if (pos < 0 || pos > al->size - 1) {
		printf("error");					
	}

	elementArrayList item = al->data[pos];
												
	for (int i = pos; i < al->size - 1; i++) { 
		al->data[i] = al->data[i + 1];
	}

	al->size--; 

	return item; 
}

void initArrayList(arrayList* al) {

	if (al == NULL)return; 

	for (int i = al->size - 1; i >= 0; i--) { 
		deleteArrayList(al, i);				
	}
}

elementArrayList getItemArrayList(
	arrayList* al, int pos) {
	return al->data[pos];
}

int replaceItemArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size - 1) { 
		return 0;
	}

	al->data[pos] = item; 

	return 1;
}

void printArrayList(arrayList* al) {
	printf("List: ");

	printf("Cap: %d, size: %d", al->capacity, al->size);

	for (int i = 0; i < al->size; i++) {
		printf("(%d %d %d) ", al->data[i].row,al->data[i].col, al->data[i].value);
	}
}
