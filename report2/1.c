#include <stdio.h>
#include <conio.h>
struct data input1();
struct data2 input2();
int input3();
struct data calculate(struct data temp, struct data2 input2);
int zelle(int a, int b, int c);
void printdow(int h);
struct data //struct for save year, month and day
{
	int year;
	int month;
	int day;
};
struct data2  //struct for save sign(+/-) and num(to addition and subtraction)
{
	char sign;
	int num;
};
int arr[2][13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //how many day in month   arr[leap year check][month]
int main()
{
	struct data temp = { 0, 0, 0 };
	struct data2 temp2 = { NULL, 0 };
	temp = input1();
	temp2 = input2();
	temp = calculate(temp, temp2);
	printf("%d년 %d월 %d일", temp.year, temp.month, temp.day);
	printdow(zelle(temp.year, temp.month, temp.day));
}
struct data input1() //function copy int data that type converted onto struct
{
	char input[9]; 
	struct data temp = { 0, 0, 0 };
	printf("\n년월일을 입력하세요 ex)19950207\n");
	gets(input);
	temp.year = 1000 * (input[0] - 48);				//year  type conversion: char->int 
	temp.year = temp.year + 100 * (input[1]-48); 
	temp.year = temp.year + 10 * (input[2]-48);
	temp.year = temp.year + (input[3]-48);
	temp.month = 10 * (input[4]-48);				//month
	temp.month = temp.month + (input[5]-48);
	temp.day = 10 * (input[6]-48);					//day
	temp.day = temp.day + (input[7]-48);
	return temp;
}
struct data2 input2()// add or subtract day
{
	struct data2 input = { NULL, 0 };
	printf("며칠전후인지 입력\n ex)+5 5일이후, -5 5일이전\n");
	input.sign = getche();
	scanf("%d",&input.num);
	return input;
}
struct data calculate(struct data temp, struct data2 input2)  //calculate year,month and day	temp:: struct that had year,month and day data	input2::struct that had sign and day data
{
	int leapyear = 0; // 1==leapyear 0!=leapyear
	if (temp.year % 4 == 0 && (temp.year % 100 != 0 || temp.year % 400 == 0)) // check leapyear
	{
		leapyear = 1;
	}
	if (input2.sign == '+') //addition
	{
		temp.day = temp.day + input2.num; // add day 
		while (temp.day > arr[leapyear][temp.month])//until no more number over day of the month
		{
			temp.day = temp.day - arr[leapyear][temp.month];
			temp.month++;
			if (temp.month > 12) //check: if month is over 12
			{
				temp.month = 1;	//set month 1
				temp.year = temp.year++; //year++;
			}
			if (temp.year % 4 == 0 && (temp.year % 100 != 0 || temp.year % 400 == 0)) //check leapyear
			{
				leapyear = 1;
			}
			else leapyear = 0;
		}
	}
	if (input2.sign == '-') // subtraction
	{
		temp.day = temp.day - input2.num; //subtract day
		while (temp.day < 1) //until no more number that subtract left
		{
			if (temp.month != 1) // if month is January, there is a possibility that year changed
			{
				temp.day = temp.day + arr[leapyear][--temp.month]; //day - day of month
			}
			else // month== January
			{
				temp.day = temp.day + 31;
				temp.month = 12;
				temp.year--;
				if (temp.year % 4 == 0 && (temp.year % 100 != 0 || temp.year % 400 == 0)) //check leapyear
				{
					leapyear = 1;
				}
				else leapyear = 0;
			}
		}
	}
	return temp;
}
int zelle(int year, int month, int day) //using zelle's congruence, check day of week
{
	if (month <= 2)
	{
		month = month + 12;
		year--;
	}
	int k, j, h;
	k = year % 100;
	j = year / 100;
	h = 21 * j / 4 + 5 * k / 4 + 13 * (month + 1) / 5 + day - 1;//use zelle's congruence
	if (h < 0)
	{
		h = h + 7;
	}
	h = h % 7;
	return h; // 0= sunday 1=monday 2=tuesday ...
}
void printdow(int a) //print day of the week
{
	switch (a)
	{
	case 0: printf(" 일요일 \n"); break;
	case 1: printf(" 월요일 \n"); break;
	case 2: printf(" 화요일 \n"); break;
	case 3: printf(" 수요일 \n"); break;
	case 4: printf(" 목요일 \n"); break;
	case 5: printf(" 금요일 \n"); break;
	case 6: printf(" 토요일 \n"); break;
	}
}
