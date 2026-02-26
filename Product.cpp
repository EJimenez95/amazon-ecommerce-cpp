#include <iostream>
#include <string>
#include "Product.h"
using namespace std;


Product::Product() //default constructor
{
}
//constructor
Product::Product(int inputProductId, double inputPrice, string inputDescription)
{
	productId = inputProductId;

	//exception handling in class for invalid input
	if (inputPrice < 0)
	{
		throw invalid_argument("Item price cannot be negative");
	}
	price = inputPrice;
	description = inputDescription;

}
//destructor
Product::~Product()
{
}
//accessor methods
string Product::getDescription()
{
	return description;
}

double Product::getPrice()
{
	return price;
}

int Product::getProductId()
{
	return productId;
}