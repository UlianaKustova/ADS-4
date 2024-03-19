// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count > (0)) {
        return count;
    }
    return 0;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; j > i; --j) {
            if (value == arr[i] + arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        int min = i;
        int max = len;
        while (min < (max - 1)) {
            int y = (max + min) / 2;
            if (arr[i] + arr[y] == value) {
                count++;
                int j = y + 1;
                while ((arr[i] + arr[j] == value) && (j < max)) {
                    count++;
                    j++;
                }
                j = y - 1;
                while ((arr[i] + arr[j] == value) && (j > min)) {
                    count++;
                    j--;
                }
                break;
            } else if ((arr[i] + arr[y]) > value) {
                max = y;
            } else {
                min = y;
            }
        }
    }
    return count;
}
