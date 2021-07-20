//
// Created by rne on 20.07.21.
//

#include "bufi.h"

namespace bufi {
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
}