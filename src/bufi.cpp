//
// Created by rne on 20.07.21.
//

#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include "bufi.h"

namespace bufi {

    bool sortByCapitalValueRate(FinancingProject const & alice, FinancingProject const & bob) {
        return alice.getCapitalValueRate() > bob.getCapitalValue();
    }

    vector<FinancingProject> getExecutableProjects(vector<FinancingProject> & projects) {
        vector<FinancingProject> result = {};
        sort(projects.begin(), projects.end(), sortByCapitalValueRate);

        for (FinancingProject const & project : projects) {
            if (project.getCapitalValueRate() < 0)
                break;

            result.emplace_back(project);
        }

        return result;
    }

    vector<double> investOptimal(double budget, vector<FinancingProject> & projects) {
        double investment;
        vector<double> result = {};
        sort(projects.begin(), projects.end(), sortByCapitalValueRate);

        for (FinancingProject const & project : getExecutableProjects(projects)) {
            if (budget == 0)
                break;

            investment = project.getInvestment();

            if (budget < investment) {
                result.emplace_back(budget);
                return result;
            }

            result.emplace_back(investment);
            budget -= investment;
        }

        return result;
    }

	double coveringSpan(double sellingPrice, double variableUnitCosts)
	{
		return sellingPrice - variableUnitCosts;
	}

	double profitContribution(double salesVolume, double coveringSpan)
	{
		return salesVolume * coveringSpan;
	}

	double depositSurplus(double profitContribution, double overheadCosts)
	{
		return profitContribution - overheadCosts;
	}

    double breakEvenValue(double A0, double presentValue, double costs, double price, double unitCost)
    {
	    return ((A0 / presentValue) + costs) / (price - unitCost);
    }

    double breakEvenPrice(double A0, double presentValue, double costs, double amount, double unitCost)
    {
	    return unitCost + (((A0 / presentValue) + costs) / amount);
    }
}