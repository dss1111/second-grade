#include <stdio.h>
#include <string.h>

int main()
{
	char input[11];
	int nnum[10] = { 0, };
	int snum[10] = { 0, };
	int index = 0; //������ġ
	int slong = 0; //�������
	int count = 0;
	int temp;
	puts("�Ǽ������� ī��Ʈ");
	puts("�Ǽ��Է��� Enter �ϼ���.");	
	puts("����, �Ǽ��κ��� 9�ڸ��� �ʰ��Ҽ� ����");
	printf("�Է�>");
	gets(input);
	printf("�Էµ� �Ǽ� : %s \n", input);
	while (input[count] != NULL)
	{
		if (input[count] == '.')
		{
			index = count;
		}
		count++;
	}
	slong = count--;
	printf("���� �κ�   : ");
	for (count = 0; count <index; count++)
	{
		temp = input[count] - 48;
		printf("%d", temp);
		nnum[temp]++;
	}
	printf("\n�Ҽ����Ϻκ�: ");
	for (count = index + 1; count < slong; count++)
	{
		temp = input[count] - 48;
		printf("%d", temp);
		snum[temp]++;
	}
	count = 0;
	printf("\n�Ҽ����̻�\nnnum  count");
	while (count != 10)
	{
		printf("\n%d      %d", count, nnum[count]);
		++count;
	}
	count = 0;
	printf("\n�Ҽ�������\nnnum  count");
	while (count != 10)
	{
		printf("\n%d      %d", count, snum[count]);
		++count;
	}
	puts("");
	return 0;
}