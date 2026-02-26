#pragma once
//customer header file
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include "Product.h"
using namespace std;

class Customer
{
private:
	//attributes
	string name;
	string address;
public:
	Customer(); //default constructor 
	~Customer(); //deconstructor
};

