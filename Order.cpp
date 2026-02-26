#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "Order.h"
#include <fstream>
using namespace std;

//default constructor
Order::Order()
{
	shippingPrice = 0;
	total = 0;
}

//deconstructor
Order::~Order()
{
}

void Order::setShippingMethod(string inputMethodOfShipping)
{
	methodOfShipping = inputMethodOfShipping;
}

void Order::addProduct(string inputDetails)
{
	productList.push_back(inputDetails);
}

void Order::showProductList()
{
	cout << "Your order contains: " << endl;
	vector <string>::iterator ptr;
	for (ptr = productList.begin(); ptr < productList.end(); ptr++)
	{
		std::cout << "	" << *ptr << endl;
		std::cout << endl;
	}
}

void Order::calculateTotal()
{
	double sum = 0;
	vector <double>::iterator ptr;
	vector <int>::iterator ptrQuantity;

	for (ptr = priceList.begin(), ptrQuantity = quantityList.begin(); ptr < priceList.end(); ptr++, ptrQuantity++)
	{
		sum = sum + *ptr * (*ptrQuantity);
	}

	calculateShippingPrice();

	total = sum + shippingPrice;
}

void Order::calculateShippingPrice()
{
	double result;

	//10 dollars for less than 5 items, and 1 dollar for each additional item if method of shipping is standard
	if (methodOfShipping.compare("standard") == 0)
	{
		if (productList.size() < 5)
		{
			result = 10;
		}
		else
		{
			result = 10 + 1 * (productList.size() - 5);
		}

	}
	else if (methodOfShipping.compare("express") == 0)
	{
		if (productList.size() < 5)
		{
			result = 20;
		}
		else
		{
			result = 20 + 1 * (productList.size() - 5);
		}

	}

	//set shipping price
	shippingPrice = result;
}

void Order::addPrice(double inputPrice)
{
	priceList.push_back(inputPrice);
}


void Order::addQuantity(int inputQuantity)
{
	//checking for invalid argument
	if (inputQuantity <= 0)
	{
		throw invalid_argument("Quantity cannot be zero or negative value");
	}

	quantityList.push_back(inputQuantity);
}
//method used to display the order details
string Order::toString()
{
	string result = "";

	vector <int>::iterator ptrQuantity;
	vector <string>::iterator ptrProduct;

	result += "Order details: \n";
	for (ptrQuantity = quantityList.begin(), ptrProduct = productList.begin(); ptrProduct < productList.end(); ptrQuantity++, ptrProduct++)
	{
		result += "Item: " + *ptrProduct + " Quantity: " + to_string(*ptrQuantity) + "\n";
	}

	result += "Shipping method: " + methodOfShipping + "\n";

	result += "Shipping cost: " + to_string(shippingPrice) + "\n";

	result += "Total cost: " + to_string(total) + "\n";

	return result;
}

double Order::getTotal()
{
	return total;
}