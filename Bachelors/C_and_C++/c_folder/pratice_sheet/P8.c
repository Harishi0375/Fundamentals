#include <stdio.h>

void total_time(int mins[], int secs[], int n, int *sum_min, int *sum_sec) {
    for (int i = 0; i < n; i++) {
        *sum_min += mins[i];
        *sum_sec += secs[i];
    }

    if (*sum_sec > 59) {
        *sum_min = *sum_min + (*sum_sec / 60);
        *sum_sec = *sum_sec%60;
    }

    printf("mins %d\n", *sum_min);
    printf("seconds %d\n", *sum_sec);
}

int main() {
    int mins[3] = {2, 3, 4};
    int secs[3] = {67, 89, 54};
    int sum_min = 0;
    int sum_sec = 0;

    total_time(mins, secs, 3, &sum_min, &sum_sec);

    return 0;
}
