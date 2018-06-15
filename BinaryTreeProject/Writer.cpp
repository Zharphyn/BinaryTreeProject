#include "stdafx.h"
#include "Writer.h"
#include <iostream>

using namespace std;


Writer::Writer()
{
}

Writer::~Writer()
{
}

// Standardizes how strings are written to the screen
void Writer::WriteToScreen(string OutPut) const
{
	// printf("format %s", OutPut );
	cout << OutPut << endl;
}

// Standardizes how strings are written to the screen
void Writer::WriteToScreen(string OutPut, string FillIn)
{
	string replace1 = "{0}";
	try
	{
		for (int i = 0; i < 5; i++) {
			OutPut.replace(OutPut.find(replace1), replace1.length(), FillIn);
		}
	}
	catch (...)
	{
	}
	cout << OutPut << endl;
}

// Standardizes how strings are written to the screen
void Writer::WriteToScreen(string OutPut, string FillIn1, string FillIn2)
{
	string replace1 = "{0}";
	string replace2 = "{1}";
	try
	{
		for (int i = 0; i < 5; i++) {
			OutPut.replace(OutPut.find(replace1), replace1.length(), FillIn1);
			OutPut.replace(OutPut.find(replace2), replace2.length(), FillIn2);
		}
	}
	catch (...)
	{
	}
	cout << OutPut << endl;
}