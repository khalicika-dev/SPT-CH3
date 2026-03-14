#include <iostream>
#include "Inventory.h"
#include "Item.h"
using namespace std;

#define RUN_INVENTORY_ITEM
//#define RUN_INVENTORY_INT
//#define RUN_INVENTORY_STRING

#ifdef RUN_INVENTORY_ITEM
int main(void)
{
	Inventory<Item> inven1(5);

	cout << "--Item ÀÎº¥Åä¸®--" << endl;
	//Add
	cout << "1) Add" << endl;
	cout << "Inven1" << endl;
	inven1.AddItem(Item("´ß¹ß", 500));
	inven1.AddItem(Item("»ç°ú", 100));
	inven1.AddItem(Item("»¡°£¹öÆ°", 99999));
	inven1.AddItem(Item("Äá", 40));
	inven1.AddItem(Item("ÆÏ", 35));
	inven1.AddItem(Item("Àü¼³ÀÇ°Ë", 7000));
	inven1.AddItem(Item("Àü¼³ÀÇÃÑ", 10000));
	inven1.AddItem(Item("¹ä»ó", 30000));
	inven1.AddItem(Item("°ð»ç¶óÁú³à¼®", 1500));

	cout << endl;
	cout << "2) Remove" << endl;
	//Remove
	inven1.RemoveLastItem();
	inven1.PrintAllItems();

	//Copy
	cout << endl;
	cout << "3) Copy" << endl;
	cout << "Inven2" << endl;
	Inventory<Item> inven2(inven1);
	inven2.PrintAllItems();
	inven2.AddItem(Item("±³¼ö´ÔÀÇ C+", 999));
	inven2.AddItem(Item("¾ð¸®¾ó", 50500));

	//Assign
	cout << endl;
	cout << "4) Assign" << endl;
	cout << "Inven1" << endl;
	inven1.Assign(inven2);
	inven1.PrintAllItems();

	//Resize
	cout << endl;
	cout << "5) Resize" << endl;
	inven1.Resize(100);
	inven1.PrintAllItems();

	//Sort
	cout << endl;
	cout << "6) Sort" << endl;
	inven1.SortItems();
	inven1.PrintAllItems();
	
	return 0;
}
#endif

#ifdef RUN_INVENTORY_INT
int main(void)
{
	Inventory<int> inven1(5);

	cout << "--Item ÀÎº¥Åä¸®--" << endl;
	//Add
	cout << "1) Add" << endl;
	cout << "Inven1" << endl;
	inven1.AddItem(500);
	inven1.AddItem(100);
	inven1.AddItem(99999);
	inven1.AddItem(40);
	inven1.AddItem(35);
	inven1.AddItem(7000);
	inven1.AddItem(10000);
	inven1.AddItem(30000);
	inven1.AddItem(1500);

	cout << endl;
	cout << "2) Remove" << endl;
	//Remove
	inven1.RemoveLastItem();
	inven1.PrintAllItems();

	//Copy
	cout << endl;
	cout << "3) Copy" << endl;
	cout << "Inven2" << endl;
	Inventory<int> inven2(inven1);
	inven2.PrintAllItems();
	inven2.AddItem(999);
	inven2.AddItem(50500);

	//Assign
	cout << endl;
	cout << "4) Assign" << endl;
	cout << "Inven1" << endl;
	inven1.Assign(inven2);
	inven1.PrintAllItems();

	//Resize
	cout << endl;
	cout << "5) Resize" << endl;
	inven1.Resize(100);
	inven1.PrintAllItems();

	//Sort
	cout << endl;
	cout << "6) Sort" << endl;
	inven1.SortItems();
	inven1.PrintAllItems();

	return 0;
}
#endif

#ifdef RUN_INVENTORY_STRING
int main(void)
{
	Inventory<string> inven1(5);

	cout << "--Item ÀÎº¥Åä¸®--" << endl;
	//Add
	cout << "1) Add" << endl;
	cout << "Inven1" << endl;
	inven1.AddItem("´ß¹ß");
	inven1.AddItem("»ç°ú");
	inven1.AddItem("»¡°£¹öÆ°");
	inven1.AddItem("Äá");
	inven1.AddItem("ÆÏ");
	inven1.AddItem("Àü¼³ÀÇ°Ë");
	inven1.AddItem("Àü¼³ÀÇÃÑ");
	inven1.AddItem("¹ä»ó");
	inven1.AddItem("°ð»ç¶óÁú³à¼®");

	cout << endl;
	cout << "2) Remove" << endl;
	//Remove
	inven1.RemoveLastItem();
	inven1.PrintAllItems();

	//Copy
	cout << endl;
	cout << "3) Copy" << endl;
	cout << "Inven2" << endl;
	Inventory<string> inven2(inven1);
	inven2.PrintAllItems();
	inven2.AddItem("±³¼ö´ÔÀÇ C+");
	inven2.AddItem("¾ð¸®¾ó");

	//Assign
	cout << endl;
	cout << "4) Assign" << endl;
	cout << "Inven1" << endl;
	inven1.Assign(inven2);
	inven1.PrintAllItems();

	//Resize
	cout << endl;
	cout << "5) Resize" << endl;
	inven1.Resize(100);
	inven1.PrintAllItems();

	//Sort
	cout << endl;
	cout << "6) Sort" << endl;
	inven1.SortItems();
	inven1.PrintAllItems();

	return 0;
}
#endif