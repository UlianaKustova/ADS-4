// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count > 0) {
        return count;
    }
    return 0;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0, x = 0, y = len;
    for (int i = len; i > 0; i--) {
        if (arr[i] <= value) {
            y = i;
            break;
        }
    }
    for (int i = 0; i < (len - 1); i++) {
        if ((arr[i] + arr[i+1]) >= value) {
            x = i;
            break;
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = x; j <= y; j++) {
            if (j > i) {
                if ((arr[i] + arr[j]) == value) {
                    count++;
                }
            }
        }
    }
    if (count > 0) {
        return count;
    }
    return 0;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0, y = 0, min = 0, max = len;
    for (int i = 0; i < len; i++) {
        min = i;
        max = len - 1;
        while (min <= max) {
            y = min + ((max - min) / 2);
            if ((arr[i] + arr[y]) == value) {
                break;
            }
            if (min == max) {
                break;
            }
            if ((arr[i] + arr[y]) > value) {
                max = y;
                if (max - min == 1) {
                    max = min;
                }
            } else {
                min = y;
                if (max - min == 1) {
                    min = max;
                }
            }
        }
        for (int j = min; j <= max; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count > 0) {
        return count;
    }
    return 111111;
}
