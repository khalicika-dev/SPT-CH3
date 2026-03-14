#include <iostream>
#pragma once
class Item
{
	std::string name_;
	int price_;
public:
	Item(std::string name = "Item", int price = 100) :name_(name), price_(price) {}
	friend std::ostream& operator<<(std::ostream& os, const Item& itm)
	{
		os << "[이름: " << itm.name_ << ", 가격: " << itm.price_ << "G]";
		return os;
	}
	std::string Getname() const { return name_; }
	int GetPrice() const { return price_; }
	//void PrintInfo() const
	//{
	//	std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
	//}
};