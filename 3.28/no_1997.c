#include<stdio.h>

int firstDayBeenInAllRooms(int* nextVisit, int nextVisitSize) {
    int day = 0;
    int* count;
    int i;
    count = (int*)malloc(sizeof(int) * nextVisitSize);
    int visit = 0; // 访问的位置编号

    for (i = 0; i < nextVisitSize; i++) {
        count[i] = 0;
    }

    while (visit < nextVisitSize-1) {
        day += 1;
        count[visit] += 1;
        if (count[visit] % 2 == 1) {
            visit = nextVisit[visit];
        } else {
            visit = (visit + 1) % nextVisitSize;
        }
    }
    free(count);
    return day;
}