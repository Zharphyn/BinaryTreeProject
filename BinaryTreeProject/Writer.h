#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Writer
{
public:
	Writer();
	~Writer();
	// Standardizes how strings are written to the screen
	void WriteToScreen(string OutPut) const;
	void WriteToScreen(string OutPut, string FillIn);
	void WriteToScreen(string OutPut, string FillIn1, string FillIn2);

};

