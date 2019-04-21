//
// Created by last on 4/16/19.
//

#ifndef AEROTRACKER_LIST_H
#define AEROTRACKER_LIST_H

typedef struct List{
    void *info;
    struct List* next;
}List;

List *newList();

List *insert(List *list, void *info);

List *search(void *value, List *src, int (*cmp)(void *, void *));

List *delete(List *src);

#endif //AEROTRACKER_LIST_H
