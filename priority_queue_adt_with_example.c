#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef long long int element;

struct heap
{
    long long int count;
    long long int size;
    element *heapparr;
};

typedef struct heap *PriorQueue;

long long int *heap;
long long int size;
long long int count;
long long int init_size = 300005;

PriorQueue heap_init(PriorQueue h)
{
    h = (PriorQueue)malloc(sizeof(struct heap));
    h->heapparr = (element *)malloc(sizeof(long long int) * (init_size));
    h->count = 0;
    h->size = init_size;
    return h;
}

void min_heapify(element *data, long long int loc, long long int count)
{
    long long int left, largest, right, temp;
    left = 2 * loc + 1;
    right = left + 1;
    largest = loc;

    if (left <= count && data[left] <= data[largest])
    {
        largest = left;
    }

    if (right <= count && data[right] <= data[largest])
    {
        largest = right;
    }

    if (largest != loc)
    {
        temp = data[loc];
        data[loc] = data[largest];
        data[largest] = temp;
        min_heapify(data, largest, count);
    }
}

void swap(long long int *a, long long int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertmin(element x, PriorQueue h)
{
    long long int idx, parent;
    idx = h->count++;
    for (; idx; idx = parent)
    {
        parent = (idx - 1) / 2;
        if (h->heapparr[parent] <= x)
        {
            break;
        }
        h->heapparr[idx] = h->heapparr[parent];
    }
    h->heapparr[idx] = x;
}

element deletemin(PriorQueue h)
{
    element removed;
    long long int temp = h->heapparr[--h->count];
    if (h->count <= (h->size + 2) && (h->size > init_size))
    {
        h->size -= 1;
        h->heapparr = realloc(h->heapparr, sizeof(element) * h->size);
        // if (!h->heapparr)
        // {
        //     printf("E3!\n");
        //     return 0;
        // }
    }
    removed = h->heapparr[0];
    h->heapparr[0] = temp;
    min_heapify(h->heapparr, 0, h->count);
    return removed;
}

int main()
{
    PriorQueue h = NULL;
    h = heap_init(h);
    long long int l, d;
    scanf("%lld %lld", &l, &d);
    long long int height[d];
    for (int i = 0; i < d; i++)
    {
        scanf("%lld", &height[i]);
        insertmin(height[i], h);
    }
    // printf("%lld\n", h->count);
    if (h->count == 1)
    {
        printf("0\n");
        return 0;
    }
    long long int res = 0;
    while (h->count > 1)
    {
        long long int first = deletemin(h);
        long long int second = deletemin(h);
        res += first + second;
        insertmin(first + second, h);
    }
    printf("%lld\n", res);
    return 0;
}
