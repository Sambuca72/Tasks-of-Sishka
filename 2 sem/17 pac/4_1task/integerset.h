#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <stdlib.h>
#define P 1000007
#define hashTableSize 1000003

typedef struct IntegerSet IntegerSet;
IntegerSet* CreateSet(int* intSet, int len);
int IsInSet(IntegerSet* intSet, int num);
#endif