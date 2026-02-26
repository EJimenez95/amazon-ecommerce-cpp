#include <iostream>
#include <string>
#include "Tool.h"
using namespace std;

//constructor
Tool::Tool(int inputId, double inputPrice, string inputDescription, string inputSize) : Product(inputId, inputPrice, inputDescription)
{
	toolSize = inputSize;
}

//default constructor
Tool::Tool()
{

}

//deconstructor
Tool::~Tool()
{
}

//method used to display the tool details
string Tool::toString() {
	string result = "Category: Tool, Description: " + getDescription() + " Price: " + to_string(getPrice()) + ", Tool size: " + toolSize;
	return result;
}