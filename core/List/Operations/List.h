//
// Created by last on 4/16/19.
//

#ifndef AEROTRACKER_LIST_H
#define AEROTRACKER_LIST_H

#include <malloc.h>
#include <stdio.h>

typedef struct List{
    void *info;
    struct List* next;
}List;

List *newList();

List *insert(List *list, void *info);

List *search(void *value, List *src, int (*cmp)(void *, void *));

List *delete(List *src);

int contains(void *value, List *src, int (*cmp)(void *, void *));

#endif //AEROTRACKER_LIST_H
