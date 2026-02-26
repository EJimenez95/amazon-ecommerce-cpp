//header file food
#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

//child class 
class Food : public Product
{
private:
	int calories; //attribute
public:
	Food(); //default constructor
	~Food(); //deconstructor
	Food(int inputId, double inputPrice, string inputDescription, int inputCalories); //constructor

	string toString(); //toString to display food details
};

