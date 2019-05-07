#ifndef PLAYGROUND_MERGESORT_H
#define PLAYGROUND_MERGESORT_H

#include "../Operations/List.h"
#include "stdio.h"


//The main function
List *merge_sort(List *head, int (*cmp)(void *, void *));

//Merge subroutine to merge two sorted lists
List *merge(List *a, List *b, int (*cmp)(void *, void *));

//Finding the middle element of the list for splitting
List *getMiddle(List *head);


#endif //PLAYGROUND_MERGESORT_H
