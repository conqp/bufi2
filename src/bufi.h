#pragma once

#include <vector>

#include "FinancingProject.h"

namespace bufi {
    bool sortByCapitalValueRate(FinancingProject const & alice, FinancingProject const & bob);
    std::vector<FinancingProject> getExecutableProjects(std::vector<FinancingProject> & projects);
    std::vector<double> investOptimal(double budget, std::vector<FinancingProject> & projects);
	double coveringSpan(double sellingPrice, double variableUnitCosts);
	double profitContribution(double salesVolume, double coveringSpan);
	double depositSurplus(double profitContribution, double overheadCosts);
	double breakEvenValue(double A0, double presentValue, double costs, double price, double unitCost);
    double breakEvenPrice(double A0, double presentValue, double costs, double amount, double unitCost);
}