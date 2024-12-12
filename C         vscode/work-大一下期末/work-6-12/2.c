#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compareAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int getMaxMinDifference(int arr[], int n) {
    int max = 0, min = 0;
    while (n > 1) {
        qsort(arr, n, sizeof(int), compareAsc);
        min = arr[0] * arr[1] + 1;
        arr[0] = min;
        n--;
        qsort(arr, n, sizeof(int), compareDesc);
        max = arr[0] * arr[1] + 1;
        arr[0] = max;
        n--;
    }
    return max - min;
}

int main() {
    int n;
    printf("���������г���n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("�ڴ����ʧ�ܡ�\\n");
        return 1;
    }

    printf("������%d��������ֵ: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int difference = getMaxMinDifference(arr, n);
    printf("max-min��ֵΪ: %d\n", difference);

    free(arr);
    return 0;
}