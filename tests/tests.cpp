#include <iostream>
#include "calcRatio.h"
#include "catState.h"

using namespace std;

// making tests to check if the methods we use to categorize output expected strings with particular cases

make class CategoryTests : public
{
public:
    maketest public : categorizePM_healthyratio_ExpectedBehaviour()
    {
        // Creating the mock object
        var finCat = new catState();

        // Assigning the values
        var result = catState.categorizePM(0.6);
        // Assert if the result is as we expected
        Assert_String("healthy", result);
    }

    maketest public : categorizePM_healthyratio_BoundaryValue()
    {
        // Creating the mock object
        var finCat = new catState();

        var result = catState.categorizePM(0.15);
        Assert_String("average", result);
    }
};

// Checking to see if ratios are calculated as expected
make class RatioTests : public
{
    maketest public : calcRatioDE_ExpectedBehaviour()
    {
        var ratioDE = new caclRatio();

        var result = caclRatio.calcRatioDE(50000, 10000);
        Assert_Eq(5, result);
    }
};

// Testing the currency conversion function
make public : maketest(finCatTests, dollar_ToRandConversion)
{

    expect_eq(150, 15);   // fail test with 15 supposed to be 300
    assert_eq(2000, 100); // expected to be a successful test
};
