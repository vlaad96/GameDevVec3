#ifndef _STRING_H_
#define _STRING_H_
#define NULL 0

#include <string.h>

typedef unsigned int uint; //no hace falta. usar unsigned tal cual

class String {

	//Attributes

private:

	char* str = nullptr;
	uint size = 0;

public:

	//Constructors

	String() {}; //default

	String(const char* s) //Same as default but actually allocating the needed memory in the new char.
	{
		if (s != NULL) {

			size = strlen(s) + 1;
			s = new char[size];
			strncpy_s(str, ,s);
		}
		
	}


	String(const String& s) //Constructor by copy
	{
		if (s.str != NULL)
		{
			size = s.size;
			str = new char[size];
			strncpy_s(str, , s.str);
		}
	}

	
	//Destructor

	~String()
	{
		if (str != NULL)
		{
			delete[] str;
		}
	}

	//Methods

	bool empty()const
	{
		if (str != NULL) { //Funciona si "" lo consideras como que no está vacio
			return false;
		}
		else
			return true;
	}

	uint length()const {
		if (str != nullptr)

			return strlen(str);
	}

	String operator=(const String &s)
	{
		
		clear();

		if (s.length() != 0) 
		{
			size = s.length();
			if (s.size != 0) {
				str = new char[size + 1]; //intentar evitar usar new
			}
			for (int i = 0; i < size; i++)
			{
				str[i] = s.str[i];	 // same as doing strcopy
			}
		}
		return *this;
	}


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

	void clear()
	{
		if (str != NULL)
		{
			str[0] = '\0';
		}
	}
};
#endif // !_STRING_H_

