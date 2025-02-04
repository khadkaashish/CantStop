// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Dice.hpp"
#include "tools.hpp"
//-----------------------------------------------------------------

// Helper function to roll and print dice
void rollAndPrint(Dice& dice, ofstream& testOutput, const string& testName) {
	testOutput << testName << endl;
	dice.roll();
	testOutput << "Rolled: " << dice << endl;
	testOutput << "-------------------------" << endl;
}

void unitDice() {
	// Seed the random number generator once
	srand(time(nullptr));

	// Open the test output file in append mode
	ofstream testOutput("test_output.txt", ios::app);

	if (!testOutput) {
		cerr << "Error opening test output file: test_output.txt" << endl;
		return;
	}

	// Test 1: Default Constructor (1 Die)
	{
		Dice dice1;  // Default constructor (1 die)
		rollAndPrint(dice1, testOutput, "Test 1: Rolling 1 die (default constructor)");
	}

	// Test 2: Constructor with 2 Dice
	{
		Dice dice2(2);  // Constructor with 2 dice
		rollAndPrint(dice2, testOutput, "Test 2: Rolling 2 dice");
	}
	
	// Test 3: Constructor with 3 Dice
	{
		Dice dice3(3);  // Constructor with 3 dice
		rollAndPrint(dice3, testOutput, "Test 3: Rolling 3 dice");
	}
	
	// Test 4: Constructor with 4 Dice
	{
		Dice dice4(4);  // Constructor with 4 dice
		rollAndPrint(dice4, testOutput, "Test 4: Rolling 4 dice");
	}


	// Test 5: Constructor with 5 Dice
	{
		Dice dice5(5);  // Constructor with 5 dice
		rollAndPrint(dice5, testOutput, "Test 5: Rolling 5 dice");
	}
	
	// Test 6: Constructor with 6 Dice
	{
		Dice dice6(6);  // Constructor with 5 dice
		rollAndPrint(dice6, testOutput, "Test 6: Rolling 6 dice");
	}
	
	
	// Test 7: Edge Case – 0 Dice (Invalid Input)
	{
		try {
			Dice dice0(0);  // Attempt to create a Dice object with 0 dice
			rollAndPrint(dice0, testOutput, "Test 7: Rolling 0 dice (invalid input)");
		} catch (const exception& e) {
			fatal("Invalid Input - 0");
			testOutput << "Test 7: Invalid Input - " << e.what() << endl;
			testOutput << "-------------------------" << endl;
		}
	}
}
