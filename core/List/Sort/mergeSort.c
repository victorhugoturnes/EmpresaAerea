//
// Created by last on 4/7/19.
//

#include <malloc.h>
#include "mergeSort.h"


List *getMiddle(List *head) {
    if (!head)
        return head;

    List *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

List *merge(List *a, List *b, int (*cmp)(void *, void *)) {
    List *dummyHead = newList();

    List *current = dummyHead;
    for (; a && b; current = current->next) {

        if (cmp(a, b) == -1) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
    }

    current->next = (a == NULL) ? b : a;
    current = dummyHead->next;
    free(dummyHead);
    return current;
}

List *merge_sort(List *head, int (*cmp)(void *, void *)) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    List *middle = getMiddle(head);      //get the middle of the list
    List *left_head = head;
    List *right_head = middle->next;
    middle->next = NULL;             //split the list into two halfs

    return merge(merge_sort(left_head, cmp), merge_sort(right_head, cmp), cmp);  //recurse on that
}
