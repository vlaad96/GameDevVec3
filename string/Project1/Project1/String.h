#pragma once
#ifndef _STRING_H_
#define _STRING_H_

typedef unsigned int uint;

class String {

	//Attributes

private:
	
	char* str;
	uint size;

public:

	//Constructors

	String() //default
	{
		size = 0;
		str = new char[0];
	}

	String(const String& s)
	{
		size = s.lenght();
		str = new char[size];

		for (uint i = 0; i < size; i++)
		{
			str[i] = s[i];
		}
	} 

	String(const char* s)
	{
		if (s)
		{
			uint i = 0;
			while (s[i] != '\0')
				i++;
			size = i;
			str = new char[i];
			for (uint j = 0; j < i; j++)
			{
				str[j] = s[i];
			}
		}
		else
		{
			size = 0;
			str = new char[0];
		}
	}

	
	//Destructor

	~String()
	{
		delete[] str;
	}

	//Methods

	int index(char c) const		//Returns index of a char in string if exists, -1 otherwise
	{
		for (uint i = 0; i < size; i++)
			if (str[i] == c)
			{
				return i;
			}
		return -1;
	}

	void upcase(uint first, uint last)
	{
		
		for (uint i = first; i < last; i++)
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= ('a' - 'A');
	}

	bool operator== (const String& otherS)const
	{
		return strcmp(otherS.str, str) == 0;
	}

	bool operator!= (const String& otherS) const
	{
		return strcmp(otherS.str, str) != 0;
	}
};
#endif // !_STRING_H_

