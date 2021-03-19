#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

  int i,j,diff;
  *returnSize = 2;
  int* ret = malloc((*returnSize) * sizeof(int));

  for ( i = 0; i < numsSize; i++)
  {
    diff = target - nums[i];
    for ( j = i+1; j < numsSize; j++)
    {
      //printf("i: %d, j: %d, diff: %d\n", i, j, diff);
      if (diff == nums[j])
      {
        ret[0] = i;
        ret[1] = j;
        return ret;
      }
      
    }
  }
  return nums;
}

int main() {
  int numsSize = 4;
  int* nums;
  int  var[numsSize];
  var[0] = 5;
  var[1] = 2;
  var[2] = 7;
  var[3] = 15;
  nums = var;

  int target = 9;
  int* ret;
  int  retVar = 2;
  ret = &retVar;

  for (int i = 0; i < *ret; i++)
  {
    printf("%d\n",twoSum(nums,numsSize,target,ret)[i]);
  }
  

  //printf("%d\n",*twoSum(nums,numsSize,target,ret));
  return 0;
}