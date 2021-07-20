#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * Finanzierungsprojekt
 */
namespace bufi {
    class FinancingProject {
    private:
        std::vector<double> depositSurplusses;
        double interestRate;
    private:
        [[nodiscard]] double getInterestFactor() const;
    public:
        FinancingProject(std::vector<double> const & depositSurplusses, double interestRate);
        virtual ~FinancingProject() = default;

        [[nodiscard]] std::vector<double> getDepositSurplusses() const;
        [[nodiscard]] double getInvestment() const;
        [[nodiscard]] double getCapitalValue() const;
        [[nodiscard]] double getCapitalValueRate() const;
        [[nodiscard]] double getPresentValue(unsigned int runtime) const;
        [[nodiscard]] double FRMInRears(double cashFlow, unsigned int runtime) const;
        [[nodiscard]] double FRMInAdvance(double cashFlow, unsigned int runtime) const;
        [[nodiscard]] double equivalentFRM(double presentValue) const;

        virtual void print(std::ostream& target = std::cout) const;
        friend std::ostream& operator<<(std::ostream& target, FinancingProject const & project);
    };
}
