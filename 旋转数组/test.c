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

void rotate1(int* nums, int numsSize, int k) {
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

void rotate2(int* nums, int numsSize, int k) {
	//借助O(n)O(n)的空间解法。再利用(i + k) % n = 旋转后的位置，可以将原有数组中的数据复制到新数组中。

	//	例如：



	//	3元素在数组中的2位置上，(2 + 3) % 7 = 5
	//	5元素在数组中的4位置上，(4 + 3) % 7 = 0
	//	6元素在数组中的5位置上，(5 + 3) % 7 = 1
	//	7元素在数组中的6位置上，(6 + 3) % 7 = 2
	//	12345

	//	根据以上可以推断出，诸如将一个数组向右偏移或者旋转多少步等之类的题目，可以通
	//	过(元素位置 + 偏移或旋转步数) 模与 数组长度可以得到偏移或者旋转之后的元素位置
	int i = 0;
	int array[7] = { 0 };
	for (i = 0; i < numsSize; i++)
	{
		array[(i + k) % numsSize] = nums[i];
	}
	for (i = 0; i < numsSize; i++)
	{
		nums[i] = array[i];
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
	rotate1(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	rotate2(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	system("pause");
	return 0;
}