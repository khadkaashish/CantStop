// ===============================================================
// Can't Stop Board Game          File: Dice.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Dice.hpp"
#include "tools.hpp"
//-----------------------------------------------------------------
Dice::Dice (int n) : nDice (n) {

	diceValues = new int [nDice];
	srand(time(NULL));
}

Dice::~Dice(){
	delete[] diceValues;
}

//-----------------------------------------------------------------
// roll the die and store the values
const int* Dice::roll() {
	for (int k = 0; k < nDice; ++k) {
		diceValues[k] = (rand() % 6) + 1;
	}
	return diceValues;
}

//-----------------------------------------------------------------
ostream& Dice::print(ostream& os) const {
	for (int k = 0; k < nDice; ++k) {
		os << diceValues[k] << " ";
	}
	return os;
}
