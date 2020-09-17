#include <iostream>
#include <sstream>
#include <vector>
#include <string>
/*
2014112037 Yoon jae moon
2015.10.01
spreadsheet program
*/
using namespace std;
string itos(int i)	//string->int 
{
	stringstream st;
	st << i;
	return st.str();
}
class Excel
{
private:
	vector <string> vec;	//vector that store string type  data
	vector <int> sheet;		//vector that store int type data
	int row;
	int col;
public:
	Excel();
	void getinput();	
	void calculate();
	void show();
	~Excel();
};
Excel::Excel()
{
	row = 0;
	col = 0;
}
void Excel::getinput()
{
	cin >> col >> row;
	cin.ignore(256, '\n'); //ignore enter in buffer;
	string str;
	string word;
	for (int i = 0; i < row; i++)
	{
		getline(cin,str);
		for (int j = 1; j < col; j++)
		{
			word = str;
			word.erase(str.find(' '), str.length() - str.find(' '));
			str.erase(0, word.length() + 1);
			vec.push_back(word);	//trim string to word and store in vector::vec
		}
		vec.push_back(str);//store last word in vector::vec
	}
}
void Excel::calculate()
{
	int find_Row=0;	//to find row that we want 
	int find_Col=0;	//to find col that we want
	for (int i = 0; i < row*col; i++)
	{
		if (vec.at(i)[0] == '=')
		{
			string temp;
			string left;
			int sum = 0;
			temp = vec.at(i);
			temp.erase(0, 1);
			left = temp;
			while(temp.find('+')!=temp.npos)
			{
				find_Row = 0;
				find_Col = 0;
				if (isalpha(temp[2]))
				{
					find_Col += temp[2] - 'A'+1;	//if temp[2]= 'A~Z' find_Col store 0~25
					find_Col += 26 * (temp[1] - 'A' + 1);
					find_Col += 26 * 26 * (temp[0] - 'A' + 1);
					temp.erase(0, 3);
				}
				else if (isalpha(temp[1]))
				{
					find_Col += temp[1] - 'A' + 1;	//if temp[1]= 'A~Z' find_Col store 0~25
					find_Col += 26 * (temp[0] - 'A' + 1);
					temp.erase(0, 2);
				}
				else
				{
					find_Col += temp[0] - 'A' + 1;	//if temp[0]= 'A~Z' find_Col store 0~25
					temp.erase(0, 1);
				}
				find_Col--;
				left = temp;
				temp.erase(temp.find('+'), temp.length() - temp.find('+'));
				find_Row = stoi(temp) - 1;	//if temp = "11" find_Row store 11
				sum += stoi(vec.at(find_Col + find_Row * col));
				left.erase(0, left.find('+') + 1);
				temp = left;
			}
			find_Row = 0;
			find_Col = 0;
			if (isalpha(left[2]))
			{
				find_Col += left[2] - 'A' + 1;	//if temp[2]= 'A~Z' find_Col store 0~25
				find_Col += 26 * (left[1] - 'A' + 1);
				find_Col += 26 * 26 * (left[0] - 'A' + 1);
				left.erase(0, 3);
			}
			else if (isalpha(left[1]))
			{
				find_Col += left[1] - 'A' + 1;	//if temp[1]= 'A~Z' find_Col store 0~25
				find_Col += 26 * (left[0] - 'A' + 1);
				left.erase(0, 2);
			}
			else
			{
				find_Col += left[0] - 'A' + 1;	//if temp[0]= 'A~Z' find_Col store 0~25
				left.erase(0, 1);
			}
			find_Col--;
			find_Row = stoi(left) - 1;
			sum += stoi(vec.at(find_Col + find_Row * col));
			sheet.push_back(sum);
			vec.at(i) = itos(sum);	
		}
		else 
			sheet.push_back(stoi(vec.at(i)));
	}
}
void Excel::show()	//show all data in vector::sheet
{
	for (int i = 0; i < row*col; i++)
	{
		cout<<sheet.at(i)<<" ";
		if ((i + 1) % col == 0)
		{
			cout << endl;
		}
	}
}
Excel::~Excel()
{
	row = 0;
	col = 0;
	vec.clear();
	sheet.clear();
}
int main()
{
	class Excel first;
	first.getinput();	//get input 
	first.calculate();	//calculate string->int and change calculated int ->string
	first.show();		//show all data
}