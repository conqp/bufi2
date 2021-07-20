//
// Created by rne on 20.07.21.
//

#include <cmath>
#include <ostream>
using std::ostream;
#include <string>
using std::string;
using std::to_string;

#include "FinancingProject.h"

namespace bufi {

	FinancingProject::FinancingProject(std::vector<double> payments, double interestRate)
	: payments(payments), interestRate(interestRate)
	{}

	double FinancingProject::costs() const
	{
		double costs = 0;

		for (size_t index = 0; index < payments.size(); ++index) {
			costs += payments.at(index) / pow(1 + interestRate, index);
		}

		return costs;
	}

	string FinancingProject::toString() const
	{
		string result = "{ ";

		for (auto const &payment : payments)
			result += to_string(payment) + " ";

		return result + "}, " + to_string(interestRate);
	}

	ostream& operator<<(std::ostream &out, FinancingProject const &project)
	{
		out << project.toString();
		return out;
	}
}