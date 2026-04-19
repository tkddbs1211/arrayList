#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

int main()
{
	arrayList* myArrayList;
	myArrayList = createArrayList(4);

	if (sizeArrayList(myArrayList) == 0) 
	{									
		printf("create ok\n");
	}


	elementArrayList item;
	item.row = 0;
	item.col = 0;
	item.value = 0;


	//insert test
	insertArrayList(myArrayList, 0, item);//최초 삽입
	insertArrayList(myArrayList, 1, item);
	insertArrayList(myArrayList, 2, item);
	insertArrayList(myArrayList, 3, item);
	insertArrayList(myArrayList, 4, item);//realloc test


	printArrayList(myArrayList);
	
	return 0;

}
