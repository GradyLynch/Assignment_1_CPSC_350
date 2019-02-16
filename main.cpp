#include <iostream> //preprocessor directive
#include <fstream>
#include "Functions.h"

using namespace std;

int main()
{

  std::ofstream myfile;
  myfile.open("GradyLynch.txt", std::ofstream::app);
  if (myfile.is_open())
  {
    myfile << "Grady Lynch" << "\n";
    myfile << "ID: 002297574" << "\n";
    myfile << "E-mail: grlynch@chapman.edu" << "\n";
    myfile << "Assignment 1 CPSC 350" << "\n";
    myfile << "\n";
  }
  myfile.close();

  string fileName = "";

  cout << "Please enter the name of a text file that contains an arbitrary list of DNA strings:\n>";
  getline(cin, fileName);
  cout << endl;

  while(fileName != "no" || fileName != "No" || fileName != "NO")
  {
    cout << "Some statistics of your file, " << fileName << ", have been sent to the file GradyLynch.txt" << endl;
    cout << "along with a generated list of 1000 DNA strings with the same mean, variance, and nucleotide" << endl;
    cout << "probability as your file." << endl;

    double sum = getSum(fileName);
    double lines = getLines(fileName);
    double mean = getMean(lines, sum);
    double variance = getVariance(fileName, lines, mean);
    double standardDeviation = getStandardDeviation(variance);
    double Aprob = getProbability(fileName, "A", sum, lines);
    double Cprob = getProbability(fileName, "C", sum, lines);
    double Tprob = getProbability(fileName, "T", sum, lines);
    double Gprob = getProbability(fileName, "G", sum, lines);
    double AAprob = getProbability(fileName, "AA", sum, lines);
    double CCprob = getProbability(fileName, "CC", sum, lines);
    double TTprob = getProbability(fileName, "TT", sum, lines);
    double GGprob = getProbability(fileName, "GG", sum, lines);
    double ACprob = getProbability(fileName, "AC", sum, lines);
    double ATprob = getProbability(fileName, "AT", sum, lines);
    double AGprob = getProbability(fileName, "AG", sum, lines);
    double CAprob = getProbability(fileName, "CA", sum, lines);
    double CTprob = getProbability(fileName, "CT", sum, lines);
    double CGprob = getProbability(fileName, "CG", sum, lines);
    double TAprob = getProbability(fileName, "TA", sum, lines);
    double TCprob = getProbability(fileName, "TC", sum, lines);
    double TGprob = getProbability(fileName, "TG", sum, lines);
    double GAprob = getProbability(fileName, "GA", sum, lines);
    double GCprob = getProbability(fileName, "GC", sum, lines);
    double GTprob = getProbability(fileName, "GT", sum, lines);

    std::ofstream myfile;
    myfile.open("GradyLynch.txt", std::ofstream::app);
    if (myfile.is_open())
    {
      myfile << "Statistics of the file: " << fileName << "\n";
      myfile << "   Sum = " << sum << "\n";
      myfile << "   Mean = " << mean << "\n";
      myfile << "   Variance = " << variance << "\n";
      myfile << "   Standard Deviation = " << standardDeviation << "\n";
      myfile << "  Nucleotide (and nucleotide pair) probabilities" << "\n";
      myfile << "   'A' = " << Aprob << "%" << "\n";
      myfile << "   'C' = " << Cprob << "%" << "\n";
      myfile << "   'T' = " << Tprob << "%" << "\n";
      myfile << "   'G' = " << Gprob << "%" << "\n";
      myfile << "   'AA' = " << AAprob << "%" << "\n";
      myfile << "   'AC' = " << ACprob << "%" << "\n";
      myfile << "   'AT' = " << ATprob << "%" << "\n";
      myfile << "   'AG' = " << AGprob << "%" << "\n";
      myfile << "   'CC' = " << CCprob << "%" << "\n";
      myfile << "   'CA' = " << CAprob << "%" << "\n";
      myfile << "   'CT' = " << CTprob << "%" << "\n";
      myfile << "   'CG' = " << CGprob << "%" << "\n";
      myfile << "   'TT' = " << TTprob << "%" << "\n";
      myfile << "   'TA' = " << TAprob << "%" << "\n";
      myfile << "   'TC' = " << TCprob << "%" << "\n";
      myfile << "   'TG' = " << TGprob << "%" << "\n";
      myfile << "   'GG' = " << GGprob << "%" << "\n";
      myfile << "   'GA' = " << GAprob << "%" << "\n";
      myfile << "   'GC' = " << GCprob << "%" << "\n";
      myfile << "   'GT' = " << GTprob << "%" << "\n";
      myfile << "\n";
      myfile << "\n";
      myfile << "1000 generated strings with mean, variance, and nucleotide probability as listed above:" << "\n";
      myfile << "\n";

      for(int i = 0; i < 1000; i++)
      {
        myfile << generateGaussianString(Aprob, Cprob, Tprob, Gprob, standardDeviation, mean);
        myfile << "\n";
      }
      myfile << "\n";
      myfile << "\n";
      myfile.close();
    }

    cout << "If you would like to repeat this process with another file, please enter the name of that file. Otherwise, please enter 'no'.\n";
    getline(cin, fileName);
    cout << fileName << endl;
    cout << endl;
  }
	return 0;
}
