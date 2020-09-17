#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void draw(int *arr,int num);
int Low_to_high(int *arr,int num);
void result(int *arr);
int main()
{
	int num;
	int freq[45] = { 0, };//arr to how many times number drawed
	scanf("%d", &num);
	draw(freq,num);
	result(freq);
	return 0;
}
void draw(int *freq,int num)
{
	int random;
	int size[45] = { 0, };
	srand((unsigned)time(NULL));
	random = (rand() % 45) + 1;
	int *arr_p;
	int check = 0;			//check number duplication
	for (int k = 0; k <1000; k++)
	{
		for (int i = 0; i < num; i++)
		{
			while (check != 0)//check duplication
			{
				check = 0;
				random = (rand() % 45) + 1;

				for (int j = 0; j < i; ++j)
				{
					if (random == size[j])  //if number is duplicate?
					{
						check = 1;			//duplicate
						break;
					}
				}
			}
			check = 1;
			size[i] = random;
		}
		for (int i = 0; i < num; i++)		//printf not sorted number
		{
			printf("%d ", size[i]);
		}
		puts("");
		arr_p=Low_to_high(size, num);		
		for (int i = 0; i < num; i++)		//printf sorted number
		{
			printf("%d ", arr_p[i]);
		}
		puts("");
		for (int i = 0; i < 45; i++)		//how many times number drawed
		{
			for (int j = 0; j < num; j++)	//matching all number
			{
				if (size[j] == i + 1)
				{
					freq[i]++;
				}
			}
		}
	}
	return;
}
int Low_to_high(int *arr,int num)	//sort number low to high
{
	int temp = arr[0];
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return arr;
}
void result(int *freq) //result: show how many times number drawed
{
	for (int i = 0; i < 6; i++)
	{
		int max = 0;
		int top = 0;
		for (int j = 0; j < 45; j++)
		{
			if (freq[j]>max)
			{
				max = freq[j];
				top = j;
			}
		}
		printf("번호%d : %d회나왔습니다.\n", top + 1, freq[top]);
		freq[top] = 0;
	}
	return;
}