#include <stdio.h>
#include <stdlib.h>

int countAndRemoveInversions(int arr[], int n) {
  int inversions = 0;
  int comparisons = 0;
  int swaps = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      comparisons++;

      if (arr[i] > arr[j]) {
        swaps++;
        inversions++;
        
        // Swap using XOR logic
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
      }
    }
  }

  return inversions;
}

int main() {
  int *arr = NULL;
  int num;
  int n = 0;

  scanf("%d", &num);
  while (num != -1) {
    n++;
    arr = (int*) realloc(arr, n * sizeof(int));
    arr[n - 1] = num;
    scanf("%d", &num);
  }

  int numInversions = countAndRemoveInversions(arr, n);

  printf("%d %d %d\n", numInversions, (n * (n - 1)) / 2 - numInversions, 0);

  free(arr);

  return 0;
}

