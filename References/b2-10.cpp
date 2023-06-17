#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int a = 10;
	int &r = a; //reference
	
	printf("%d, %d",a,r);
	
	return 0;
}