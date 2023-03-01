#include <stdio.h>
#include <stdlib.h>

int maximum (int a, int b)
{
  return (a > b) ? a : b;
}

int minimum (int a, int b)
{
  return (a < b) ? a : b;
}

void findMinMax (int arr[], int low, int high, int *max, int *min)
{
  int mid, max1, max2, min1, min2;

  if (high - low == 1)
    {
      if (arr[low] > arr[high])
	{
	  *max = arr[low];
	  *min = arr[high];
	}
      else
	{
	  *max = arr[high];
	  *min = arr[low];
	}
    }
  else if (high - low == 0)
    {
      *max = arr[low];
      *min = arr[low];
    }
  else
    {
      mid = (low + high) / 2;
      findMinMax (arr, low, mid, &max1, &min1);
      findMinMax (arr, mid + 1, high, &max2, &min2);
      *max = maximum (max1, max2);
      *min = minimum (min1, min2);
    }
}

int main ()
{
  int n, i;
  printf ("Enter the number of elements in the array: ");
  scanf ("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++)
    {
      printf ("Enter element %d: ", i + 1);
      scanf ("%d", &arr[i]);
    }
  int max, min;
  findMinMax (arr, 0, n - 1, &max, &min);
  printf ("Maximum element in the array is: %d\n", max);
  printf ("Minimum element in the array is: %d\n", min);
  return 0;
}
