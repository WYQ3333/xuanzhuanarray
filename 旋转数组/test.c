//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
//ʾ�� 1:
//���� : [1, 2, 3, 4, 5, 6, 7] �� k = 3
//��� : [5, 6, 7, 1, 2, 3, 4]
// ���� :
//	������ת 1 �� : [7, 1, 2, 3, 4, 5, 6]
//	������ת 2 �� : [6, 7, 1, 2, 3, 4, 5]
//	������ת 3 �� : [5, 6, 7, 1, 2, 3, 4]
//	ʾ�� 2 :
//���� : [-1, -100, 3, 99] �� k = 2
// ��� : [3, 99, -1, -100]
//  ���� :
//	 ������ת 1 �� : [99, -1, -100, 3]
//	 ������ת 2 �� : [3, 99, -1, -100]
// ˵�� :
//	�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
//	Ҫ��ʹ�ÿռ临�Ӷ�Ϊ O(1) ��ԭ���㷨��
//

#include<stdio.h>
#include<Windows.h>

void rotate(int* nums, int numsSize, int k) {
	int i = 0;
	for (i = 1; i <= k; i++)
	{
		int tmp = 0;
		int j = numsSize-1;
		while (j > 0)
		{
			tmp = nums[j];
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