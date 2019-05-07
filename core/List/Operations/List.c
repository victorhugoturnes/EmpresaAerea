#include "List.h"

List *insert(List *list, void *info) {
    List *tmp = newList();
    tmp->info = info;
    tmp->next = list;
    return tmp;
}

List *newList() {
    List *list = malloc(sizeof(List));
    list->info = NULL;
    list->next = NULL;
    list->active = 1;
    return list;
}

List *search(void *value, List *src, int (*cmp)(void *, void *)) {
    List *result = NULL;
    while (src) {
        if (src->active && cmp(value, src->info)) {
            if (!result) {
                result = newList();
                result->info = src->info;
            } else {
                result = insert(result, src->info);
            }
        }
        src = src->next;
    }
    return result;
}

List *delete(List *src) {
    if (!src) return NULL;
    List *tmp = src->next;
    free(src);
    return tmp;
}


int contains(void *value, List *src, int (*cmp)(void *, void *)) {
    while (src) {
        if (cmp(value, src->info)) {
            return 1;
        }
        src = src->next;
    }
    return 0;
}

int length(List *l) {
    return (!l) ? 0 : length(l->next) + 1;
}
