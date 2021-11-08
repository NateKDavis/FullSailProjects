#pragma once

namespace Helper
{
	int GetValidatedInt(const char* strMessage, int nMinimumRange = INT_MIN, int nMaximumRange = INT_MAX);	// Will repeatedly ask given prompt until input is a valid Int inside of the given range
	void Header(const char header[32]);																		//Creates a title -=-=-=-= your input =-=-=-=- then goes two lines down
	void Footer();																							//ends the current line, pauses for input, then clears the screen
	void ClearInputBuffer();																				//clears input buffer and ignore until next \n
	int RandomNumber(int max = INT_MAX);																	//Creates a random number between given min and max.
}