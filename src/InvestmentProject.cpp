//
// Created by Richard Neumann on 20.07.2021.
//

#include "bufi.h"
using bufi::presentValue;
#include "InvestmentProject.h"

namespace bufi {
    InvestmentProject::InvestmentProject(double investmentValue, double unitPrice, double unitCost, unsigned int amount,
                                         double overheadCosts)
        : investmentValue(investmentValue), unitPrice(unitPrice), unitCost(unitCost), amount(amount),
        overheadCosts(overheadCosts)
    {}

    double InvestmentProject::netPresentValue(double presentValue) const {
        return investmentValue + ((unitPrice - unitCost) * amount - overheadCosts) * presentValue;
    }

    double InvestmentProject::netPresentValue(double interestRate, unsigned int runtime) const {
        return netPresentValue(presentValue(interestRate, runtime));
    }
}