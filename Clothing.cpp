#include <iostream>
#include <string>
#include "Clothing.h"
using namespace std;

// default constructor
Clothing::Clothing()
{
}

//constructor
Clothing::Clothing(int inputId, double inputPrice, string inputDescription, string inputFabric) : Product(inputId, inputPrice, inputDescription)
{
	fabric = inputFabric;
}

//deconstructor
Clothing::~Clothing()
{
}

//method used to display the clothing details
string Clothing::toString() {
	string result = "Category: Clothing, Description: " + getDescription() + " Price: " + to_string(getPrice()) + ", Fabric: " + fabric;
	return result;
}
