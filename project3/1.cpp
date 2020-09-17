#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
2014112037 yoon jae moon
*/
class Pathway
{
private:
	int n,r;	// n = spot number   r= result number
	vector <string> path;
	queue <string> spot;
public:
	Pathway();
	void getInput();	//get input from user
	void storePath(string s);	//store input data
	void getResult();	//split input data easy to distinguish and get result
	void calculate(int f,int * m,int b,int count);	//calculate data
};
Pathway::Pathway()
{

}
void Pathway::getInput()	//getinput
{
	string s;
	cin >>n >> r;
	cin.ignore(256, '\n');
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		storePath(s);	//store path as vector
	}
	for (int i = 0; i < r; i++)
	{
		getline(cin, s);
		spot.push(s);	//store how to get to destination
	}
}
void Pathway::storePath(string s)
{	/*
	create an array as a vector
	*/
	string result;
	while (s.find(' ') != s.npos)
	{
		result = s.substr(0, s.find(' '));
		s = s.substr(s.find(' ')+1,s.length()-s.find(' '));
		path.push_back(result);
	}
	path.push_back(s);
}
void Pathway::getResult()
{
	/*
	split input data by front,middle,back
	*/
	string temp;
	int front;
	int middle[100] = {0,};
	int back;
	string strmid;
	int count;
	for (int i = 0; i < r; i++)
	{
		/*
		ex) 1 2 3 4 5
		front=1
		middle[1]=2 middle[2]=3 middle[3]=4
		back=5
		*/
		count = 1;
		temp=spot.front();
		spot.pop();
		front = stoi(temp.substr(0, temp.find(' ')));
		back = stoi(temp.substr(temp.find_last_of(' ') + 1, temp.length() - temp.find_last_of(' ')));
		temp = temp.substr(temp.find(' ') + 1, temp.length() - temp.find(' '));
		while (temp.find(' ') != temp.npos)
		{
			middle[count++] = stoi(temp.substr(0, temp.find(' ')));
			temp = temp.substr(temp.find(' ') + 1);
		}
		calculate(front, middle, back,count);
		while (count == 1)
		{
			middle[count--] = 0;
		}
	}
}
void Pathway::calculate(int f,int * m,int b,int count)
{
	/*
	calculate the shortest way
	*/
	m[0] = f;
	m[count] = b;
	sort(m + 1, m + count);	//sorting for use next_permutation
	int Min =1215752191;	//initialize big number
	int sum = 0;;
	do 
	{
		for (int i = 0; i < count; i++)
		{
			if (stoi(path.at((m[i] - 1)*n + (m[i + 1] - 1))) == 0)	//no way to go
			{
				sum = 0;
				break;
			}
			else 
				sum += stoi(path.at((m[i] - 1)*n + (m[i + 1] - 1)));	
		}
		if (sum != 0 && sum < Min)	//record the shortest way
		{
			Min = sum;
		}

	} while (next_permutation(m+1,m+count));
	/*
	we can get all possible way to use next permutation
	*/
	if (Min == 1215752191)	//not changed = no way to go to destination
	{
		Min = 0;
	}
	cout << Min << endl;
}
int main()
{
	class Pathway one;
	one.getInput();
	one.getResult();
	return 0;
}