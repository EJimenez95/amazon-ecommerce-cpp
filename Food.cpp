#include <iostream>
#include <string>
#include "Food.h"
using namespace std;

//default constructor
Food::Food()
{
}

//constructor 
Food::Food(int inputId, double inputPrice, string inputDescription, int inputCalories) : Product(inputId, inputPrice, inputDescription)
{
	calories = inputCalories;
}

//deconstructor
Food::~Food()
{
}

//method used to display the food details
string Food::toString() {
	string result = "Category: Food, Description: " + getDescription() + " Price: " + to_string(getPrice()) + ", Calories: " + to_string(calories);
	return result;
}
