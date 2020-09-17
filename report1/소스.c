#include <stdio.h>
#include <string.h>

int main()
{
	char input[11];
	int nnum[10] = { 0, };
	int snum[10] = { 0, };
	int index = 0; //점의위치
	int slong = 0; //문장길이
	int count = 0;
	int temp;
	puts("실수숫자의 카운트");
	puts("실수입력후 Enter 하세요.");	
	puts("정수, 실수부분은 9자리를 초과할수 없음");
	printf("입력>");
	gets(input);
	printf("입력된 실수 : %s \n", input);
	while (input[count] != NULL)
	{
		if (input[count] == '.')
		{
			index = count;
		}
		count++;
	}
	slong = count--;
	printf("정수 부분   : ");
	for (count = 0; count <index; count++)
	{
		temp = input[count] - 48;
		printf("%d", temp);
		nnum[temp]++;
	}
	printf("\n소수이하부분: ");
	for (count = index + 1; count < slong; count++)
	{
		temp = input[count] - 48;
		printf("%d", temp);
		snum[temp]++;
	}
	count = 0;
	printf("\n소수점이상\nnnum  count");
	while (count != 10)
	{
		printf("\n%d      %d", count, nnum[count]);
		++count;
	}
	count = 0;
	printf("\n소수점이하\nnnum  count");
	while (count != 10)
	{
		printf("\n%d      %d", count, snum[count]);
		++count;
	}
	puts("");
	return 0;
}