#include<iostream>
#include <string>
#include <sstream>

using namespace std;

int validNum(string text)
{
	int num;
	do
	{
		cout<<text;
		cin>>num;
		if(num>0)
		{
			return num;
		}else
		{
			cout<<"El numero debe ser mayor a 0";
		}
	}while(true);
}
