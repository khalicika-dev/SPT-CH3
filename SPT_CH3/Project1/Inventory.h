#include <iostream>
#include <algorithm>
#include <cassert>
#include <type_traits>
#include "Item.h"
#pragma once

class Item;
bool compareItemsByPrice(const Item& a, const Item& b) {
	return a.GetPrice() < b.GetPrice();
}

template<typename T>
class Inventory
{
	T* pItems_;
	int capacity_;
	int size_;
public:
	Inventory(int capacity = 10)
	{
		if (capacity <= 0)
			capacity_ = 1;
		else
			capacity_ = capacity;

		pItems_ = new T[capacity_];
		size_ = 0;
	}
	Inventory(const Inventory<T>& other)
	{
		assert(other.capacity_ >= other.size_);
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		std::cout << "Copy Complete (Capacity: " << capacity_ << ", Size: " << size_ << ")" << std::endl;
	}
	~Inventory()
	{
		if (pItems_ != nullptr)
			delete[] pItems_; // delete[]를 사용해야 배열단위로 주소를 해제한다.
		pItems_ = nullptr;
	}
	
	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
			Resize(capacity_ * 2);
		}
		pItems_[size_] = item;
		size_++;
		std::cout << "Add: " << item << " (Capacity: " << capacity_ << ", Size: " << size_ << ")" << std::endl;
	}
	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리가 비어있습니다." << std::endl;
			return;
		}
		size_--;
		std::cout << "Remove (Capacity: " << capacity_ << ", Size: " << size_ << ")" << std::endl;
	}
	void Assign(const Inventory<T>& other)
	{
		if (pItems_ != nullptr)
			delete[] pItems_;
		assert(other.capacity_ >= other.size_);
		pItems_ = new T[other.capacity_];
		for (int i = 0; i < other.size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		capacity_ = other.capacity_;
		size_ = other.size_;
		std::cout << "Assign Complete (Capacity: " << capacity_ << ", Size: " << size_ << ")" << std::endl;
	}
	void Resize(int newCapacity)
	{
		T* pTemp;
		if (newCapacity <= size_)
		{
			std::cout << "잘못된 입력입니다. 현재 사이즈보다 커야합니다." << std::endl;
			return;
		}
		pTemp = new T[newCapacity];
		for (int i = 0; i < size_; ++i) {
			pTemp[i] = pItems_[i];
		}
		capacity_ = newCapacity;
		delete[] pItems_;
		pItems_ = pTemp;
		pTemp = nullptr;
		std::cout << "Resize Complete (Capacity: " << capacity_ << ", Size: " << size_ << ")" << std::endl;
	}
	void SortItems()
	{
		#pragma warning(suppress:4984)
		if constexpr (std::is_same<T, Item>::value)	// 템플릿 인수 T가 Item인가?
			std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
		else
			std::sort(pItems_, pItems_ + size_, [](const T& a, const T& b) {return a < b; });	// T의 존재때문에 람다식[](){} 사용
		std::cout << "Sort Complete (Capacity: " << capacity_ << ", Size: " << size_ << ")" << std::endl;
	}
	
	int GetSize() const { return size_; }
	int GetCapacity() const { return capacity_; }
	void PrintAllItems() const
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리 비어있음." << std::endl;
			return;
		}

		for (int i = 0; i < size_; i++)
		{
			std::cout << pItems_[i] << std::endl;
		}
	}
};
