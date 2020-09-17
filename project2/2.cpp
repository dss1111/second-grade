#include <iostream>
#include <queue>
#include <string>
/*
2014112037 Yoon jae moon
2015.10.01
Distingush blood type program
*/
using namespace std;

class Blood
{
private:
	int count;	//how many time inputset entered
	queue <string> que;	//queue::que store input
	queue <string> result;	//queue::result store result
public:
	Blood();
	void getInput();
	void getOutput();
	void bloodDist(string father, string mother, string son);
	string distParent(string parent, string son);
	string distSon(string father, string mother);
	void show();
	~Blood();
};
Blood::Blood()
{
	count = 0;
}
void Blood::getInput()
{

	while (1)
	{
		string input1, input2, input3;
		cin >> input1 >> input2 >> input3;


		if (input1 == "E" &&input2 == "N"&&input3 == "D")	//while user enter E N D
			break;
		else 
		{
			que.push(input1); //store inputset in que
			que.push(input2);
			que.push(input3);
			count++;
		}
	}
}
void Blood::getOutput()
{
	for (int i = 0; i < count; i++)
	{
		string fa;
		string ma;
		string son;
		fa=que.front();	//take out in order stored data;
		que.pop();
		ma = que.front();
		que.pop();
		son = que.front();
		que.pop();
		bloodDist(fa, ma, son);	//distingush blood type
	}
}
void Blood::bloodDist(string f, string m, string s)
{

	if (f == "?")	//we don't know father's blood type
	{
		result.push(distParent(m,s));
		result.push(m);
		result.push(s);
	}
	if (m == "?")	//we dont't know mother's blood type
	{
		result.push(f);
		result.push(distParent(f,s));
		result.push(s);
	}
	if (s== "?")	//we don't know son's blood type
	{
		result.push(f);
		result.push(m);
		result.push(distSon(f,m));
	}
}
string Blood::distParent(string p, string s) //we don't know one of the parent's blood type
{
	string abo[4];
	string rh[2] = { "+", "-" };
	string changeP = p.erase(p.length() - 1, 1);
	string changeS = s.erase(s.length() - 1, 1);
	if (changeP == "O")
	{
		if (changeS == "O")
		{
			abo[0] = "A";
			abo[1] = "B";
			abo[2] = "O";
		}
		else if (changeS == "A")
		{
			abo[0] = "AB";
			abo[1] = "A";
		}
		else if (changeS == "B")
		{
			abo[0] = "AB";
			abo[1] = "B";
		}
		else if (changeS == "AB")
		{
			abo[0] = "IMPOSSIBLE";
		}
	}
	if (changeP == "A")
	{
		if (changeS == "O")
		{
			abo[0] = "A";
			abo[1] = "B";
			abo[2] = "O";
		}
		else if (changeS == "A")
		{
			abo[0] = "A";
			abo[1] = "B";
			abo[2] = "O";
		}
		else if (changeS == "B")
		{
			abo[0] = "AB";
			abo[1] = "B";
		}
		else if (changeS == "AB")
		{
			abo[0] = "AB";
			abo[1] = "B";
		}
	}
	if (changeP == "B")
	{
		if (changeS == "O")
		{
			abo[0] = "A";
			abo[1] = "B";
			abo[2] = "O";
		}
		else if (changeS == "A")
		{
			abo[0] = "AB";
			abo[1] = "A";
		}
		else if (changeS == "B")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeS == "AB")
		{
			abo[0] = "AB";
			abo[1] = "A";
		}
	}
	if (changeP == "AB")
	{
		if (changeS == "O")
		{
			abo[0] = "IMPOSSIBLE";
		}
		else if (changeS == "A")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeS == "B")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeS == "AB")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
		}
	}
	string result;
	if (abo[0] == "IMPOSSIBLE")
	{
		result = abo[0];
	}
	else
	{
		result = result + "{";
		for (int i = 0; abo[i] != ""&&i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				result = result + abo[i] + rh[j] + ",";
			}
		}
		result = result.erase(result.length() - 1, 1);
		result = result + "}";
	}
	return result;
}
string Blood::distSon(string f, string m)//we don't know son's blood type
{
	string abo[4];
	string rh[2];
	if (f[f.length() - 1] == '-'&&m[m.length() - 1] == '-')
	{
		rh[0] = '-';
	}
	else
	{
		rh[0] = "+";
		rh[1] = "-";
	}
	string changeF = f.erase(f.length() - 1, 1);
	string changeM = m.erase(m.length() - 1, 1);

	if (changeF== "O")
	{
		if (changeM =="O")
			abo[0] = "O";
		else if (changeM=="A")
		{
			abo[0] = "A";
			abo[1] = "O";
		}
		else if (changeM == "B")
		{
			abo[0] = "B";
			abo[1] = "O";
		}
		else if (changeM == "AB")
		{
			abo[0] = "A";
			abo[1] = "B";
		}
	}

	if (changeF == "A")
	{
		if (changeM == "O")
		{
			abo[0] = "A";
			abo[1] = "O";
		}
		else if (changeM == "A")
		{
			abo[0] = "A";
			abo[1] = "O";
		}
		else if (changeM == "B")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeM == "AB")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
		}
	}

	if (changeF == "B")
	{
		if (changeM == "O")
		{
			abo[0] = "B";
			abo[1] = "O";
		}
		else if (changeM == "A")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeM == "B")
		{
			abo[0] = "B";
			abo[1] = "O";
		}
		else if (changeM == "AB")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
		}
	}

	if (changeF == "AB")
	{
		if (changeM == "O")
		{
			abo[0] = "A";
			abo[1] = "B";
		}
		else if (changeM == "A")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeM == "B")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
			abo[3] = "O";
		}
		else if (changeM == "AB")
		{
			abo[0] = "AB";
			abo[1] = "A";
			abo[2] = "B";
		}
	}
	string result="{";
	for (int i = 0;abo[i]!=""&&i<4; i++)
	{
		for (int j = 0;rh[j]!=""&&j<2; j++)
		{
				result = result + abo[i] + rh[j]+",";
		}
	}
	result = result.erase(result.length() - 1, 1);
	result = result + "}";
	return result;
}
void Blood::show()	//show all data in que::result
{
	int i = 0;
	while (count--)
	{
		i++;
		cout<<"case"<<i<<">>"<<result.front()<<" ";
		result.pop();
		cout<<result.front()<<" ";
		result.pop();
		cout<<result.front()<<endl;
		result.pop();
	}
}
Blood:: ~Blood()
{
	
}
int main()
{

	class Blood first;
	first.getInput();	//get input
	first.getOutput();	//get Output 
	first.show();		//show result
}