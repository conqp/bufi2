#include <cmath>
#include <ostream>
using std::endl;
using std::ostream;
#include <stdexcept>
using std::invalid_argument;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "bufi.h"
#include "functions.h"

#include "FinancingProject.h"

namespace bufi {
    FinancingProject::FinancingProject(vector<double> const & depositSurplusses, double interestRate)
        : depositSurplusses(depositSurplusses), interestRate(interestRate)
    {}

    FinancingProject::FinancingProject(vector<double> const &depositSurplusses)
        : FinancingProject(depositSurplusses, 0)
    {}

    double FinancingProject::getInterestFactor() const {
        return 1 + interestRate;
    }

    vector<double> FinancingProject::getDepositSurplusses() const {
        return depositSurplusses;
    }

    double FinancingProject::getInvestment() const {
        return abs(depositSurplusses.at(0));
    }

    double FinancingProject::getCapitalValue() const {
        double result = 0;

        for (long unsigned int i = 0; i < depositSurplusses.size(); i++)
            result += depositSurplusses[i] / pow(getInterestFactor(), i);

        return result;
    }

    double FinancingProject::getCapitalValueRate() const
    {
        return getCapitalValue() / getInvestment();
    }

    double FinancingProject::getPresentValue(unsigned int runtime) const
    {
        return (1 / interestRate) * (1 - (1 / (pow(getInterestFactor(), runtime))));
    }

    /*
        Fixed-rate mortgage in rears
        DE: nachschüssige Annuität
    */
    double FinancingProject::FRMInRears(double cashFlow, unsigned int runtime) const
    {
        return cashFlow * getPresentValue(runtime);
    }

    /*
        Fixed-rate mortgage in advance
        DE: vorschüssige Annuität
    */
    double FinancingProject::FRMInAdvance(double cashFlow, unsigned int runtime) const
    {
        return getInterestFactor() * FRMInRears(cashFlow, runtime);
    }

    /*
        Fixed-rate mortgage in advance
        DE: vorschüssige Annuität
    */
    double FinancingProject::equivalentFRM(double presentValue) const
    {
        return getCapitalValue() / presentValue;
    }

    FinancingProject FinancingProject::operator-(FinancingProject const &other) const
    {
        if (interestRate != other.interestRate)
            throw invalid_argument("Interest rates do not match.");

        if (depositSurplusses.size() != other.depositSurplusses.size())
            throw invalid_argument("Deposit surplusses sizes do not match.");

        vector<double> depositSurplussesDiff;

        for (size_t index = 0; index < depositSurplusses.size(); ++index)
            depositSurplussesDiff.push_back(depositSurplusses[index] - other.depositSurplusses[index]);

        return FinancingProject(depositSurplussesDiff, interestRate);
    }

    void FinancingProject::print(ostream & target) const
    {
        target << "Deposit surplusses: " << join<double>(depositSurplusses, ", ") << endl;
        target << "Capital value: " << getCapitalValue() << endl;
        target << "Capital value rate: " << getCapitalValueRate() << endl;
    }

    ostream & operator<<(ostream & target, FinancingProject const & project)
    {
        project.print(target);
        return target;
    }
}