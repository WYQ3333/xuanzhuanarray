//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//示例 1:
//输入 : [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
// 解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//	示例 2 :
//输入 : [-1, -100, 3, 99] 和 k = 2
// 输出 : [3, 99, -1, -100]
//  解释 :
//	 向右旋转 1 步 : [99, -1, -100, 3]
//	 向右旋转 2 步 : [3, 99, -1, -100]
// 说明 :
//	尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//	要求使用空间复杂度为 O(1) 的原地算法。
//

#include<stdio.h>
#include<Windows.h>

void rotate(int* nums, int numsSize, int k) {
	int i = 0;
	for (i = 1; i <= k; i++)
	{
		int tmp = 0;
		int j = numsSize-1;
		tmp = nums[j];
		while (j > 0)
		{
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = tmp;
	}
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	system("pause");
	return 0;
}