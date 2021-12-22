#include "VecInt.h"
#include <stdlib.h>
#include <stdio.h>

void VecInt_createEmpty(struct VecInt *self)
{
    self->data = NULL;
    self->sz = 0;
    self->cp = 0;
}

void VecInt_createOfSize(struct VecInt *self, size_t size, int initValue)
{
    self->data = (int *)malloc(size * sizeof(int));
    if (self->data == NULL)
    {
        printf("VecInt: memory error");
        exit(1);
    }

    self->sz = size;
    self->cp = size;

    for (int i = 0; i < size; i++)
    {
        self->data[i] = initValue;
    }
}

void VecInt_pushBack(struct VecInt *self, int x)
{
    if (self->sz == self->cp)
    {
        self->cp = (self->cp == 0) ? 1 : self->cp * 2;
        int *newData = (int *)malloc(self->cp * sizeof(int));

        for (size_t i = 0; i < self->sz; i++)
        {
            newData[i] = self->data[i];
        }

        free(self->data);
        self->data = newData;
    }

    self->data[self->sz++] = x;
}

void VecInt_destroy(struct VecInt *self)
{
    free(self->data);
    self->sz = 0;
    self->cp = 0;
}