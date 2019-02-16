#include <iostream> //preprocessor directive
#include <fstream>
#include <cmath>
#include "Functions.h"
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

double getSum(string fileName)
{
	// Funtion that takes in a file name and outputs the total number of
	// characters in the file.

	double sum = 0;
	string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      sum += (line.length() - 1);
    }
    myfile.close();
  }
	return sum;
}

double getLines(string  fileName)
{
	// Function that takes in a file name and outputs the number of lines in it.

	double count = 0;
	string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      count ++;
    }
    myfile.close();
  }
	return count;
}

double getMean(double lines, double sum)
{
	// Function that takes in the number of lines and total number of characters
	// in a file and outputs the average line length.

	double mean = sum / lines;
	return mean;
}

double getVariance(string fileName, double lines, double mean)
{
	// Function that takes in a file name, number of lines, and average line
	// length of a file and outputs the variance.
	// Variance = (sigma((each line length - mean)^2)) / (number of lines)

	double x = 0;  // Placeholder variable for part of equation

	string line;
  ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      x += (line.length() - 1 - mean) * (line.length() - 1 - mean);
			// line.length() returns a number one greater than the actual length of
			// the line, hence the " - 1 "
    }
    myfile.close();
  }
	// while loop that calculates (line length - mean)^2 for each line and adds it to x

	double variance = x / (lines);
	return variance;
}

double getStandardDeviation(double variance)
{
	// Function that takes in a file name, number of lines, and average line
	// length of a file and outputs the standard deviation.
	// deviation = square root(variance)

	double deviation = sqrt(variance);
	return deviation;
}

double getProbability(string fileName, string parameter, double sum, double lines)
{
	// Function that takes in a file name, a string to search for, and the total
	// number of characters in the file and outputs the probabilty of the string
	// occuring in the file.

	double count = 0;
	string lowerParameter = strToLower(parameter);
	string lowerLine;
	string line;
  ifstream myfile (fileName);

  if(parameter.length() == 1) // If parameter is one character (A, C, T, or G)
	{
		if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
				lowerLine = strToLower(line);
				for(double i =0; i < lowerLine.length() - 1; i++)
				{
					if(lowerLine[i] == lowerParameter[0])
						count++;
				}
	    }
	    myfile.close();
	  }
		return (count / sum) * 100;
		// probability = number of occurances / total characters
	}

	else // If parameter is two characters (AA, AC, AT, AG, CA, CC, CT, CG, etc)
	{
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
			{
				lowerLine = strToLower(line);
				for(double i = 0; i < (lowerLine.length() - 2); i++)
				{
					if(lowerLine[i] == lowerParameter[0] && lowerLine[i+1] == lowerParameter[1])
						count++;
				}
			}
			myfile.close();
		}

		double pairs = sum - lines;
		// a line n characters long has n-1 adjacent pairs
		// a set of n lines with m total characters has m-n adjacent pairs

		return (count / pairs) * 100;
	}
}

string strToLower(string input)
{
	// Function that takes in a string and outputs the string in all lowercase.
	// SOURCE: https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	return input;
}

string generateNucleotide(double Aprob, double Cprob, double Tprob, double Gprob)
{
	// Function that generates a nucleotide based on given probabilities

	double x = rand() % 100 + 1;     // number in the range 1 to 100, SOURCE: http://www.cplusplus.com/reference/cstdlib/rand/

	if(x <= Aprob)
	{
		return "A";
	}
	if(Aprob < x && x <= Aprob + Cprob)
	{
		return "C";
	}
	if(Aprob + Cprob < x && x <= Aprob + Cprob + Tprob)
	{
		return "T";
	}
	if(Aprob + Cprob + Tprob < x && x <= Aprob + Cprob + Tprob + Gprob)
	{
		return "G";
	}
}

string generateGaussianString(double Aprob, double Cprob, double Tprob, double Gprob, double standardDeviation, double mean)
{
	// Function that uses generateNucleotide() and the equation D = standard deviation * C + mean
	// to generate a DNA string.

	string output = "";

	double a = ((double) rand() / (RAND_MAX));
	double b = ((double) rand() / (RAND_MAX));

	double c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);

	double d = standardDeviation * c + mean;

	if(d < 0)
	{
		// Make d positive if it isn't already

		d = d * -1;
	}

	for(int i = 0; i < d; i++)
	{
		output += generateNucleotide(Aprob, Cprob, Tprob, Gprob);
	}

	return output;
}
