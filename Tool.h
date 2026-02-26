//header file for tool
#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

//child class 
class Tool : public Product
{
private:
	//attribute
	string toolSize;
public:

	Tool(); //default constructor
	~Tool(); //deconstructor
	Tool(int inputId, double inputPrice, string inputDescription, string inputSize); // constructor

	//toString method to display clothing details
	string toString();
};

