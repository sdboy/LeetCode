#include "test.h"

void TestTwoSum() {
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  int returnSize = 0;
  int* result = TwoSum(nums, 4, target, &returnSize);

  if (returnSize == 2 && result[0] == 0 && result[1] == 1) {
      printf("TestTwoSum passed.\n");
  } else {
      printf("TestTwoSum failed.\n");
  }

  free(result);
}