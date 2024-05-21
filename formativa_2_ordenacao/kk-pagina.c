#include <stdio.h>
#include <stdlib.h>

typedef int item;

void swap(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

int median(item *v, int left, int right) {
    int mid = left + (right - left) / 2;
    if (v[mid] < v[left]) swap(&v[left], &v[mid]);
    if (v[right] < v[left]) swap(&v[left], &v[right]);
    if (v[right] < v[mid]) swap(&v[mid], &v[right]);
    return mid;
}

int partition(item *v, int left, int right) {
    int index = median(v, left, right);
    item pivot = v[index];
    swap(&v[index], &v[right]);
    int i = left;
    for (int j = left; j < right; j++) {
        if (v[j] < pivot) {
            swap(&v[i], &v[j]);
            i++;
        }
    }
    swap(&v[i], &v[right]);
    return i;
}

void quickselect(item *v, int left, int right, int k) {
    if (left >= right) return;
    int pivot = partition(v, left, right);
    if (pivot > k) {
        quickselect(v, left, pivot - 1, k);
    } else if (pivot < k) {
        quickselect(v, pivot + 1, right, k);
    }
}

void insertionsort(item *v, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int j = i;
        item temp = v[j];
        while (j > left && temp < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = temp;
    }
}

void quicksortMedian(item *v, int left, int right) {
    if (right - left <= 32) {
        insertionsort(v, left, right);
        return;
    }
    int pivot = partition(v, left, right);
    quicksortMedian(v, left, pivot - 1);
    quicksortMedian(v, pivot + 1, right);
}

int main() {
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    item *v = malloc(n * sizeof(item));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int startPage = n - 1 < p * x ? n - 1 : p * x;
    int endPage = n - 1 < (p + 1) * x - 1 ? n - 1 : (p + 1) * x - 1;

    quickselect(v, 0, n - 1, startPage);
    quickselect(v, 0, n - 1, endPage);
    quicksortMedian(v, startPage, endPage);

    for (int i = startPage; i < n && i < (p + 1) * x; i++) {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}
