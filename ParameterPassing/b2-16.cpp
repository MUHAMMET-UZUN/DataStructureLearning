#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int num1 = 10,num2 = 15;
	
	cout<<"First num: "<<num1<<endl;
	cout<<"Second num: "<<num2<<endl;
	swap(num1,num2); cout<<"Swapped"<<endl;
	cout<<"First num: "<<num1<<endl;
	cout<<"Second num: "<<num2<<endl;
	
	return 0;
}