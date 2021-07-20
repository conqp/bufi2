//
// Created by rne on 20.07.21.
//

#ifndef BUFI_BUFI_H
#define BUFI_BUFI_H


namespace bufi {
	double coveringSpan(double sellingPrice, double variableUnitCosts);
	double profitContribution(double salesVolume, double coveringSpan);
	double depositSurplus(double profitContribution, double overheadCosts);
}


#endif //BUFI_BUFI_H
