#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
2014112037 yoon jae moon
*/
string itos(int i)	//string->int 
{
	stringstream st;
	st << i;
	return st.str();
}
class Sensor
{
private:
	int n, d;	//n= sensor number   d=distance
	vector <int> sensorX;	//vector that store sensor X coordinate
	vector <int> sensorY;	//vector that store sensor Y coordinate
	vector <string> vec;	//vector that store sensor in the subset            ex)1 2 3 4
	vector <int> subset;	//vector that store how many sensor in the subset   ex)4
			
public:
	Sensor();
	void getInput();
	void getOutput();
	void calculate();
	int distance(int i,int j);
};
Sensor::Sensor()
{
}
void Sensor::getInput()
{
	cin >> n >> d;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		sensorX.push_back(x);
		sensorY.push_back(y);
	}
}
void Sensor::getOutput()
{
	int count = 0;
	int arr[100] = { 0, };	//array that store censor's number temporary  100 is sensor's maximum number
	string temp = "";		//string that store censor's number
	bool dis = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d*d >= distance(i, j))	//if satisfies distance condition
			{
				for (int k = 0; k < count; k++)	//even if other distance condition that between other sensor are satisfied
				{
					if (d*d < distance(j, arr[k]))	
					{
						dis = false;
					}
				}
				if (dis == true)
				{
					temp += itos(j + 1) + " ";	//store censor in string
					arr[count++] = j;			//store censor in array
				}
			}
		}
		vec.push_back(temp);	//store string data;
		subset.push_back(count);	//store how many censor in subset;
		for (int j = 0; j < count; j++)
		{
			arr[j] = 0;
		}
		count = 0;
		temp = "";
		dis = true;
	}
}
void Sensor::calculate()
{
	/*
	calculate maximum number in subset
	*/
	int maxsensor = 0;
	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		if (Max < subset.at(i))
		{
			Max = subset.at(i);
			maxsensor = i;		//get the biggest subset's location
		}
	}
	cout << Max << endl;
	int index=0;
	int temp;
	cout << vec.at(maxsensor);
}
int Sensor::distance(int i,int j)	//get two sensor number and return distance between two sensor 
{
	int x1 = sensorX.at(i);
	int y1 = sensorY.at(i);
	int x2 = sensorX.at(j);
	int y2 = sensorY.at(j);
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int main()
{
	class Sensor Sensor;
	Sensor.getInput();
	Sensor.getOutput();
	Sensor.calculate();
	return 0;
}