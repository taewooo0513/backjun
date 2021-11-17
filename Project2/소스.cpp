#include <iostream>
#include <list>
using namespace std;
void swap(int& a, int& b);
int main()
{
	bool End = false;
	int a;
	cin >> a;
	int* intList = new int[a];
	int* in = &intList[0];
	int* inc = &intList[0];
	list<int> bcds;
	bool v = false;
	for (int i = 0; i < a; i++, intList++)
	{
		cin >> *intList;
		bcds.push_back(*intList);
	}
	bcds.sort();
	in = inc;

	for (auto iter : bcds)
	{
		*in = iter;
		in++;
	}
	in = inc;
	for (size_t t = 0; t < a; t++, in++)
	{
		int n1 = *(in - 1), n2 = *(in + 1);
		int co1 = 1;
		int co2 = 1;

		while (true)
		{
			if (*(in) == *(in - co1))
			{
				co1++;
			}
			else
				break;
		}
		while (true)
		{
			int e = *(in);
			int g = *(in + co2);
			if (*(in) == *(in + co2))
			{
				co2++;
			}
			else
				break;
		}
		int f1 = 1, f2 = 1;
		if ((int)t - co1 < 0)
		{
			f1 = 0;
			co1 = 0;
		}
		if (co2 + (int)t > a - 1)
		{
			f2 = 0;
			co2 = 0;
		}
		if (*(in - co1) + (int)f1 == *in && *(in + co2) - (int)f2 == *in)
		{
			if (co1 != 0 &&co2!= 0)
			{
				if (*(in - co1) <= *(in + co2))
				{
					swap(*in, *(in + co2));
				}
				v = true;
			}
		}
		else if (*(in - co1) + (int)f1 != *in && *(in + co2) - (int)f2 == *in)
		{
			
				if (*(in - co1) != *(in + co2))
				{
					
				}
				else if (*(in - co1) <= *(in + co2))
				{
					swap(*in, *(in + co2));
				}
			
				v = true;
		}
		
		
	}
	if (v == true)
		for (size_t t = 0; t < a; t++, inc++)
		{
			cout << *inc <<" ";
		}
	else
	{
		for (int t = a - 1; t >= 0; t--)
		{
			--in;
			cout << *in <<" ";
		}
	}
}

void swap(int& a, int& b)
{
	int Dum = a;
	a = b;
	b = Dum;
}

