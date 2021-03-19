#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
  int i = 0, j = 0;
  int curr = 0,last = 0;
  int index = (nums1Size + nums2Size) / 2 + 1;
  while (i + j < index)
  {
    printf("i: %d, j: %d, curr: %d, last: %d\n", i, j, curr, last);
    if (i == nums1Size)
    {
      last = curr;
      curr = nums2[j];
      j += 1;
      continue;
    }
    if (j == nums2Size)
    {
      last = curr;
      curr = nums1[i];
      i += 1;
      continue;
    }
    if (nums1[i] > nums2[j])
    {
      last = curr;
      curr = nums2[j];
      j += 1;
      continue;
    }
    last = curr;
    curr = nums1[i];
    i += 1;
  }
  printf("i: %d, j: %d, curr: %d, last: %d\n", i, j, curr, last);
  if ( (nums1Size + nums2Size) % 2 == 1)
  {
    return (double)curr;
  }
  return ((double)curr + (double)last)/2.0;
}

int main() {
  int s1 = 2;
  int s2 = 1;
  int nums1[3] = {1,3};
  int nums2[1] = {2};

  int *p1 = nums1;
  int *p2 = nums2;
  printf("%f\n", findMedianSortedArrays(p1,s1,p2,s2));
}