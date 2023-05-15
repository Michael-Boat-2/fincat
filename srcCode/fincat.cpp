// JA - it is good practice to insert comment about intended use, context, contributors, etc
// change
#include <iostream>
#include <fstream>
#include <string>
#include "calcRatio.h"

using namespace std;

// Fucntion to convert Dollars ro rands of Revenue
double dollars2rands(double x) // pass in double and return double
{
    return (x * 20);
}

// Function to calculate Profit Margin ratio
double calcRatioPM(double revenue, double expenses)
{
    return ((revenue - expenses) / revenue);
}

// Function to calculate Return on Assets ratio
double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ((revenue - expenses) / assets);
}

// Function to calculate Debt to Equity ratio
double calcRatioDE(double assets, double liabilities)
{
    return (assets / liabilities);
}

// Function to categorize PM ratio
char categorisePM(double ratio)
{
    char cat;
    if (ratio < 0.08)
        cat = 'unhealty';
    else if (ratio <= 0.15)
        cat = 'average';
    else
        cat = 'healthy';
    return (cat);
}

// Function to categorize RoA ratio
char categoriseRoA(double ratio)
{
    char cat;
    if (ratio < 0.08)
        cat = 'unhealthy';
    else if (ratio <= 0.15)
        cat = 'average';
    else
        cat = 'healthy';
    return (cat);
}

// Fucntion to categorize  Debt-To-Equity ratio
char categoriseDE(double ratio)
{
    char cat;
    if (ratio < 1)
        cat = 'healthy';
    else if (ratio <= 2)
        cat = 'average';
    else
        cat = 'unhealthy';
    return (cat);
}

// Main function that reads from string, performs operations, then outputs
void process_data(char *input_file, char *output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    double revenue_USD, expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    char cat, cat2, cat3; // categories for ratios

    f_in.open(input_file, ios::in);
    f_out.open(output_file, ofstream::out);
    while (!f_in.eof())
    {
        // Reading from file
        f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
        revenue_ZAR = dollars2rands(double(revenue_USD)); // Conversion of Revenue is made

        ratio_PM = calcRatioPM(revenue_ZAR, expenses); // revenue ZAR passed to our functions
        cat = categorisePM(ratio_PM);
        ratio_RoA = calcRatioRoA(revenue_ZAR, expenses, assets);

        cat2 = categoriseRoA(ratio_RoA);
        ratio_DE = calcRatioDE(assets, liabilities);
        cat3 = categoriseDE(ratio_DE);

        f_out << company_id << " " << ratio_PM << " " << cat << ratio_RoA << " " << cat3 << ratio_DE << " " << cat2 << endl;
    }
    f_in.close();
    f_out.close();
}

int main(int argc, char *argv[])
{
    // JA - Need to check that 3 arguments were supplied upon execution
    process_data(argv[1], argv[2]);
}
