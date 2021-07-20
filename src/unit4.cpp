#include <iomanip>
using std::setprecision;
#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include "FinancingProject.h"
using bufi::FinancingProject;
#include "InvestmentProject.h"
using bufi::InvestmentProject;

int main()
{
	vector<FinancingProject> projectsA = {
		{{ -100, 120 }, 0.08 },
		{{ -80, 100 }, 0.08 },
		{{ -90, 112 }, 0.08 }
	};

	vector<FinancingProject> projectsB = {
		{{ -100 - 10, 120 }, 0.08 },
		{{ -80 - 10, 100 }, 0.08 },
		{{ -90 - 10, 112 }, 0.08 }
	};

	cout << "### Projects A ###\n";

	for (auto const &projectA : projectsA)
		cout << projectA << "-> " << projectA.getCapitalValue() << "\n";

	cout << "\n### Projects B ###\n";

	for (auto const &projectB : projectsB)
		cout << projectB << "->  " << projectB.getCapitalValue() << "\n";

	FinancingProject p1({-100, 120}, 0.08);
    FinancingProject p2({-80, 100}, 0.08);
    FinancingProject p3({-90, 112}, 0.08);
    cout << p1 - p2 << "\n";
    cout << p3 - p2 << "\n";

    InvestmentProject investmentProject(-30'000'000, 14'000, 11'000, 5'000, 1'500'000);
    double interestRate = 0.097;
    unsigned int runtime = 3;
    auto netPresentValue = investmentProject.netPresentValue(interestRate, runtime);
    cout << setprecision(12) << "\nInvestment: " << netPresentValue << "\n";

	return 0;
}
