#include <iostream>
#include <string>
using namespace std;
class catState
{
private:
public:
    // Constructor for caclRatio object
    catState(){

    };
    // Public Methods
    // Function to categorize PM ratio
    string categorisePM(double ratio)
    {
        string cat;
        if (ratio < 0.08)
            cat = "unhealty";
        else if (ratio <= 0.15)
            cat = "average";
        else
            cat = "healthy";
        return (cat);
    };

    // Function to categorize RoA ratio
    string categoriseRoA(double ratio)
    {
        string cat;
        if (ratio < 0.08)
            cat = "unhealthy";
        else if (ratio <= 0.15)
            cat = "average";
        else
            cat = "healthy";
        return (cat);
    };

    // Fucntion to categorize  Debt-To-Equity ratio
    string categoriseDE(double ratio)
    {
        string cat;
        if (ratio < 1)
            cat = "healthy";
        else if (ratio <= 2)
            cat = "average";
        else
            cat = "unhealthy";
        return (cat);
    };

    // Method that takes in the char and returns a corresponding string
    // Made for when include string was not used.
    string outputState(char cat)
    {

        if (cat = 'h')
            return ("healthy");
        else if (cat = 'a')
            return ("average");
        else if (cat = 'u')
            return ("unhealthy");
    };
};