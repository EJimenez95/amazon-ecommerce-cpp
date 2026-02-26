//header file order
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

class Order
{

public:
	Order(); 
	~Order();

	Customer myCustomer;

	vector <string> productList;
	vector <double> priceList;
	vector <int> quantityList;

	string methodOfShipping;
	double shippingPrice;
	double total;

	//mutator method
	void setShippingMethod(string inputMethodOfShipping);
	//methods for calculating shipping, products, and quantity
	void calculateShippingPrice(); 
	void calculateTotal();
	void addProduct(string inputDetails);
	void addPrice(double inputPrice);
	void addQuantity(int inputQuantity);
	void showProductList();

	//toString displays order details
	string toString();

	//accessor method
	double getTotal();

};

