#include <iostream> //preprocessor directive

using namespace std;

double getSum(string input);
double getLines(string input);
double getMean(double lines, double sum);
double getVariance(string fileName, double lines, double mean);
double getStandardDeviation(double variance);
double getProbability(string fileName, string parameter, double sum, double lines);
string strToLower(string input);
string generateNucleotide(double Aprob, double Cprob, double Tprob, double Gprob);
string generateGaussianString(double Aprob, double Cprob, double Tprob, double Gprob, double standardDeviation, double mean);
