// JA - it is good practice to insert comment about intended use, context, contributors, etc
// change
#include <iostream>
#include <fstream>
#include <string>
#include "calcRatio.h"
#include "catState.h"

using namespace std;

// Fucntion to convert Dollars ro rands of Revenue
double dollars2rands(double x) // pass in double and return double
{
    return (x * 20);
}

// Main function that reads from string, performs operations, then outputs
void process_data(char *input_file, char *output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    double revenue_USD, expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    string cat, cat2, cat3; // categories for ratios , made to be strings.
    caclRatio companyRatio; // Creates instance of company ratio object
    catState ratioCat;      // Creates instance of ratio category

    f_in.open(input_file, ios::in);
    f_out.open(output_file, ofstream::out);
    while (!f_in.eof())
    {
        // Reading from file
        f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
        revenue_ZAR = dollars2rands(double(revenue_USD)); // Conversion of Revenue is made

        ratio_PM = companyRatio.calcRatioPM(revenue_ZAR, expenses); // revenue ZAR passed to our functions
        cat = ratioCat.categorisePM(ratio_PM);

        ratio_RoA = companyRatio.calcRatioRoA(revenue_ZAR, expenses, assets);
        cat2 = ratioCat.categoriseRoA(ratio_RoA);

        ratio_DE = companyRatio.calcRatioDE(assets, liabilities);
        cat3 = ratioCat.categoriseDE(ratio_DE);

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
