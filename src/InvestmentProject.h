#pragma once

namespace bufi {
    class InvestmentProject {
    private:
        double investmentValue;
        double unitPrice;
        double unitCost;
        unsigned int amount;
        double overheadCosts;
    public:
        InvestmentProject(double investmentValue, double unitPrice, double unitCost, unsigned int amount, double overheadCosts);

        double netPresentValue(double presentValue) const;
        double netPresentValue(double interestRate, unsigned int runtime) const;
    };
};