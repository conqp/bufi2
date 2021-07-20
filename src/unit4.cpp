#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include "FinancingProject.h"
using bufi::FinancingProject;

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

	return 0;
}
