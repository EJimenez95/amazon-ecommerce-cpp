#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Product.h"
#include "Clothing.h"
#include "Tool.h"
#include "Food.h"
#include "Order.h"
using namespace std;


const string STANDARD_SHIPPING = "standard";
const string EXPRESS_SHIPPING = "express";

int main()
{
	//read a file to get list of products to display
	ifstream inputFile;
	//vector to store orders and products
	vector<Product*> amazonProducts;
	vector <Order> myOrders;

	inputFile.open("file.dat");
	if (inputFile.is_open())
	{

		std::cout << "File is found and opened." << endl;
		std::cout << "Products read are as follows: " << endl;
		int productId;
		double price;
		string description;

		string line;
		while (std::getline(inputFile, line))
		{
			productId = stoi(line);


			std::cout << "ProductId: " << productId;

			//read price
			std::getline(inputFile, line);
			price = stoi(line);

			std::cout << ", Price: " << price;

			std::getline(inputFile, description);
			std::cout << ", Description: " << description << endl;
			switch (productId)
			{
			case 1:
			{
				cout << "Clothing item found" << endl;
				string fabric;
				std::getline(inputFile, fabric);

				//add the product to vector
				amazonProducts.push_back(new Clothing(productId, price, description, fabric));

			}
			break;

			case 2:
			{
				cout << "Tool item found" << endl;
				string toolSize;
				std::getline(inputFile, toolSize);

				//add the product to vector
				amazonProducts.push_back(new Tool(productId, price, description, toolSize));
			}
			break;


			case 3:
			{
				cout << "Food item found" << endl;
				string inputLine;
				int inputCalories;
				std::getline(inputFile, inputLine);
				inputCalories = stoi(inputLine);

				//add the product to vector
				amazonProducts.push_back(new Food(productId, price, description, inputCalories));

			}
			}

		}

		//show the user list of goods on amazon
		cout << endl;
		cout << "***Welcome to Amazon.com***" << endl;
		cout << "Here is the list of items for you to buy: " << endl;

		//start loop for order
		int moreOrder = 1;
		do
		{
			Order myOrder;
			//utilizes toString method to display name and number
			for (int i = 0; i < static_cast<int>(amazonProducts.size()); i++)
			{
				std::cout << i << "	" << amazonProducts[i]->toString() << endl;
				std::cout << endl;
			}

			int more;
			do
			{
				//get item selection
				int index;
				do
				{
					cout << "Enter the index of item you want to buy: ";

					cin >> index;

				} while (index >= amazonProducts.size() || index < 0);



				//add product description to order
				myOrder.addProduct(amazonProducts[index]->toString());


				myOrder.addPrice(amazonProducts[index]->getPrice());

				int quantity;

				do
				{
					cout << "How much quantity of the selected item do you need?";
					cin >> quantity;

					if (quantity > 0)
					{
						myOrder.addQuantity(quantity);
					}
					else
					{
						cout << "Please enter a positive integer for quantity." << endl;
					}

				} while (quantity <= 0);

				cout << "Do you want to add more products to basket? Press 1 for Yes, 2 for No: ";
				cin >> more;

			} while (more == 1);



			int choice;
			do
			{
				cout << "Which shipping method do you want to use: standard or express. Enter 1 for standard, 2 for express: ";
				cin >> choice;

				if (choice != 1 && choice != 2)
				{
					cout << "Invalid input. Please enter 1 or 2 only." << endl;
				}
			} while (choice != 1 && choice != 2);

			switch (choice)
			{
			case 1:
				myOrder.setShippingMethod(STANDARD_SHIPPING);
				break;

			case 2:
				myOrder.setShippingMethod(EXPRESS_SHIPPING);
				break;

			}

			//calculating shipping price
			myOrder.calculateTotal();

			//Show order details
			cout << myOrder.toString();

			//add order to order basket
			myOrders.push_back(myOrder);

			cout << "Do you want to place more orders? Enter 1 for Yes, 2 for No: ";
			cin >> moreOrder;

		} while (moreOrder == 1);

		double totalShoppingCost = 0;
		cout << "To sum up - The following orders will be delivered to you: ";
		for (int i = 0; i < myOrders.size(); i++)
		{
			cout << myOrders[i].toString() << endl;
			totalShoppingCost += myOrders[i].getTotal();
		}
		cout << "Your total shopping expense is " << totalShoppingCost << endl;
		cout << "Bye! Bye!" << endl;
	}

	else
	{
		std::cout << "File is not found. Nothing to sell on Amazon. " << endl;
		return -1;
	}


	system("pause");
	return 0;
}

