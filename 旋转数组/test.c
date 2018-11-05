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
	//����O(n)O(n)�Ŀռ�ⷨ��������(i + k) % n = ��ת���λ�ã����Խ�ԭ�������е����ݸ��Ƶ��������С�

	//	���磺



	//	3Ԫ���������е�2λ���ϣ�(2 + 3) % 7 = 5
	//	5Ԫ���������е�4λ���ϣ�(4 + 3) % 7 = 0
	//	6Ԫ���������е�5λ���ϣ�(5 + 3) % 7 = 1
	//	7Ԫ���������е�6λ���ϣ�(6 + 3) % 7 = 2
	//	12345

	//	�������Ͽ����ƶϳ������罫һ����������ƫ�ƻ�����ת���ٲ���֮�����Ŀ������ͨ
	//	��(Ԫ��λ�� + ƫ�ƻ���ת����) ģ�� ���鳤�ȿ��Եõ�ƫ�ƻ�����ת֮���Ԫ��λ��
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