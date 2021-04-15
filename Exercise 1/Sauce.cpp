#include <iostream>
#include "dnode.h"	//doubly linked list header
#include "node1.h"	//singly linked list header
using namespace std;
using namespace main_savitch_5;

void mainMenu();
void singlSub();
void doublSub();

int main() {
	node *head = NULL;
	dnode *dhead = NULL, *dtail = NULL;
	//sSub = singly sub menu||dSub = doubly sub menu||mMenu = main menu 
	int mMenu = 0, sSub = 0, dSub = 0;
	//sExist = singly list exist||dExist = doubly list exist
	bool sExist = false, dExist = false;
	//num = number 2b stored in DF
	int num;

	while (mMenu != 3) {	//while mainMenu isnt exit condition is loops
		cout << "Menu";
		cout << "\n1:Singly Linked List \n2:Doubly Linked List \n3:Exit\n";
		cin >> mMenu;
		switch (mMenu) {
		case 1:		//Singly Sub Menu
			while (sSub != 8) {	//while singly sub menu isnt exit cond, loops
				singlSub();
				cin >> sSub;
				if (sSub == 1) {//create new node
					if (sExist == true)
						cout << "Node list already exist, can not make new list";
					else {
						sExist = true;
						cout << "Enter number to be stored: ";
						cin >> num;
						head = new node(num,NULL);
					}
				} else if (sSub == 2) {	//insert node head
					if (sExist == false)
						cout << "No node exist, make one";
					else {	//insert head node code 	
						cout << "Enter number to be stored: ";
						cin >> num;
						list_head_insert(head, num);
					}
				} else if (sSub == 3) { //insert node tail
					if (sExist == false)
						cout << "No node exist, make one";
					else {	//insert tail node code
						cout << "enter number to be stored: ";
						cin >> num;
						list_tail_insert(head, num);

					}
				} else if (sSub == 4) { //remove node head
					if (sExist == false) 
						cout << "No node exist, make one";
					else {
						list_head_remove(head);
						cout << "Boink head node gone!\n";
					}
				} else if (sSub == 5) {	//remove node tail
					if (sExist == false) 
						cout << "No node exist, make one";
					else {
						list_tail_remove(head);
						cout << "Zoinks tail node eliminated\n";
					}
				} else if (sSub == 6) {	//print list
					if (sExist == false) 
						cout << "Node list is empty";
					else 
						list_print(head);

				} else if (sSub == 7) {	//show stat
					if (sExist == false) 
						cout << "No node exist, make one";
					else
						showStatistics(head);

				} else if (sSub == 8) {	//exit
					sSub = 0;
					break;
				} else
					cout << "Invalid Input!!";
			}
			break;
		case 2:	//Doubly Sub Menu
			while (dSub != 9) {
				doublSub();
				cin >> dSub;
				if (dSub == 1) {//create node
					dExist = true;
					cout << "Enter number to be stored: ";
					cin >> num;
					dhead = new dnode(num, dhead, dtail);
				} else if (dSub == 2) {// insert node head
					if (dExist == false)
						cout << "Double List Empty! ";
					else {
						cout << "Enter Number to be stored: ";
						cin >> num;
						dhead_insert(dhead, num);
					}					
				} else if (dSub == 3) {//insert node tail
					if (dExist == false)
						cout << "Double List Empty! ";
					else {
						cout << "Enter Number to be stored: ";
						cin >> num;
						dtail_insert(dhead, num);
					}
				}else if (dSub == 4) {//remove node head
					if (dExist == false)
						cout << "Double List Empty! ";
					else {
						dhead_remove(dhead);
						cout << "Head node deleted!\n";
					}
				}else if (dSub == 5) {//remove node tail
					if (dExist == false)
						cout << "Double List Empty! ";
					else {
						dtail_remove(dhead);
					}
				}else if (dSub == 6) {//print list
					if (dExist == false)
						cout << "Double List Empty! ";
					else {
						list_printForeward(dhead);
					}
				}else if (dSub == 7) {//print list Reversed
					if (dExist == false)
						cout << "Double List Empty! ";
					else {
						list_printReverse(dhead);
					}
				}else if (dSub == 8) {//show stats
					if (dExist == false)
						cout << "Double List Empty! ";
					else
						list_showStatistics(dhead);
				}else if (dSub == 9) {//exit
					dSub = 0;
					break;
					
				} else	//invalid opt
					cout << "Invalid Input!";
			}
			break;
		case 3:	//Exit	
				exit(10);
		
		default://Invalid Input
				cout << "Invalid Option";
				break;
		}
	}
}


//main menu
void mainMenu() {
	cout << "\nMenu";
	cout << "\n1:Singly Linked List \n2:Doubly Linked List \n3:Exit\n";
}
//single linked list sub menu
void singlSub() {
	cout <<"\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Singly Linked List\n";
	cout << "1:Create a node "
		"\n2:Insert a node to head "
		"\n3:Insert a node to tail"
		"\n4:Remove a node from head"
		"\n5:Remove a node from tail"
		"\n6:Print List"
		"\n7:Show Stats \n8:Exit to Main menu\n";
}
//double linked list sub menu
void doublSub() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Doubly Linked List\n";
	cout << "1:Create a node"
		"\n2:Insert a node to head"
		"\n3:Insert a node to tail"
		"\n4:Remove a node from head"
		"\n5:Remove a node from tail"
		"\n6:Print list"
		"\n7:Print List reversed"
		"\n8:Show Stats"
		"\n9:Exit to Main menu\n";
	
	/*1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu*/
}
