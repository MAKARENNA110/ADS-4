// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int k = len - 1;
    while (arr[k] > value) {
        k -= 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = k; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0, center, j = 0;
    int left = 0, right = 0;
    int minlen = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] <= value) {
            minlen = i;
            break;
        }
    }
    for (int i = 0; i < minlen - 1; i++) {
        left = i, right = minlen + 1;
        while (left < right - 1) {
            center = (left + right) / 2;
            if (arr[i] + arr[center] == value) {
                count++;
                j = center + 1;
                while (arr[i] + arr[j] == value && j < right) {
                    count++;
                    j++;
                }
                j = center - 1;
                while (arr[i] + arr[j] == value && j > left) {
                    count++;
                    j--;
                }
                break;
            } else if (arr[i] + arr[center] > value) {
                right = center;
            } else {
                left = center;
            }
        }
    }
    return count;
}
