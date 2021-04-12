// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count =0;
  for (int i=0; i<len-1; i++)
    for (int j = i + 1; j<len;j++)
      if (arr[i]+arr[j] == value)
        count++;
  if (count !=0)
    return count;
  else
    return 0;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
    int left = 0;
    int right = len - 1;
    while (value < arr[right])
        --right;
    for (int i = right; i > left; i--)
        for (int j = 0; j < right; j++) {
            if (arr[left] + arr[right] == value)
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
            if (arr[mid] == (value - arr[i])) {
                while ((arr[mid - 1] == (value - arr[i])) && (mid > left))
                    mid--;
                while (arr[mid] == (value - arr[i])) {
                    mid++;
                    count++;
                }
                break;
            }
            else if (arr[mid] < (value - arr[i]))
                left = mid + 1;
            else 
                right = mid;
        }
    }
    if (count != 0)
        return count;
    else
        return 0;
}
