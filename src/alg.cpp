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
    for (int i = 0; i < len; i++) {
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
    int count = 0, y = len / 2;
    for (int i = 0; i < len; i++) {
        y = i + ((len - i) / 2);
        while (y > i && y < len) {
            if ((arr[i] + arr[y]) == value) {
                break;
            }
            if ((arr[i] + arr[y]) > value) {
                y = i + ((y - i) / 2);
            } else {
                if ((arr[i] + arr[y]) < value) {
                    y = y + ((len - y) / 2);
                }
            }           
        }
        for (int j = i + 1; j <= y; j++) {
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
