//
// Created by rne on 20.07.21.
//

#ifndef BUFI_FINANCINGPROJECT_H
#define BUFI_FINANCINGPROJECT_H

#include <string>
#include <vector>

namespace bufi {
	class FinancingProject {
	private:
		std::vector<double> payments;
		double interestRate;
	public:
		FinancingProject(std::vector<double> payments, double interestRate);
		double costs() const;
		std::string toString() const;

		friend std::ostream& operator<<(std::ostream &out, FinancingProject const &project);
	};
}

#endif //BUFI_FINANCINGPROJECT_H
