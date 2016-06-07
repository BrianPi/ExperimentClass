// example.cpp
//
// Example code for experiments involving several traits, each of which can be supported
// or refuted by tests associated with each trait.  Positive and negative tests are
// symmetrical: there is a positive and negative test for each trait.  If positive and
// negative tests for the trait fail, then there is no evidence for that trait; if
// positive and negative tests both succeed, then evidence for that trait is conflicting.
//
// An experiment consists of a number of trials.  The results of an experiment can be
// summarized, results from several experiments can be compared and combined, etc.
//

#include "Experiment.h"

#include <iostream>
#include <fstream>

// Read trials from the named input file and add them to the passed-in experiment.
static void read_exp(Experiment& exp, const char* name)
{
    std::ifstream inf(name);
    Evidence e;
    while (!inf.eof())
    {
        inf >> e;
        exp.addTrial(e);
    }
}

static void print_summary(Experiment& exp)
{
    const std::vector<double>& summary = exp.summary();
    for (unsigned j = 0; j < (unsigned) trait_count; ++j)
        std::cout << ' ' << summary[j];
    std::cout << std::endl;
}

// Sample code to exercise the Experiment class.
int main(int argc, const char* argv[])
{
    Experiment exp_1, exp_2;
    
    read_exp(exp_1, "data1.txt");
    read_exp(exp_2, "data2.txt");

    print_summary(exp_1);
    print_summary(exp_2);

    exp_1.outlierCull(0.5);
    exp_2.outlierCull(0.9);

    print_summary(exp_1);
    print_summary(exp_2);

    exp_1 += exp_2;

    print_summary(exp_1);
}
