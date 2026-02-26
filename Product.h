#pragma once
//Product header file
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

//base class
class Product
{
private:
	//attributes
	int productId;
	double price;
	string description;

public:
	Product(); //default constructor
	Product(int inputProductId, double inputPrice, string inputDescription); //constructor
	virtual ~Product(); //deconstructor

	//accessor methods
	string getDescription();
	double getPrice();
	int getProductId();

	virtual string toString() = 0; //virtual toString method

};

