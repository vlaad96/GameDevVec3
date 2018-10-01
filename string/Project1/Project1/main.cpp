#include "String.h"
#include<iostream>


using namespace std;

int main() 
{

	String s0("First string");
	String s1(s0);
	String s2("A string is a sequence of characters");
	String s3("Another one", 12);

	cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3" << s3;

	return 0;
}