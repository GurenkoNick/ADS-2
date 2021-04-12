// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i=0; i < len-1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value)
        count++;
  if (count !=0)
    return count;
  else
    return 0;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int right = len - 1;
    while (arr[right] > value)
        right--;
    for (right; right > 0; right--)
        for (int left = 0; left < right; left++) {
            if (arr[right] + arr[left] == value)
                count++;
        }
    if (count != 0)
        return count;
    else
        return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, left, right;
    for (int i = 0; i < len-1; i++) {
        left = i + 1;
        right = len;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < (value - arr[i]))
                left = mid + 1;
            else
                right = mid;
            if (arr[left] == (value - arr[i])) {
                while (arr[left] == (value - arr[i])) {
                    left++;
                    count++;
                }
            }
        }
    }
    if (count != 0)
        return count;
    else
        return 0;
}
