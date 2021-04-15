// FILE: dnode.cpp
// IMPLEMENTS: The functions of the dnode class and the
// doubly linked list toolkit (see dnode.h for documentation).


#include "dnode.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5 {
	void list_printReverse(dnode* dhead_ptr) {
		
		dnode *tail = dhead_ptr;

		while (tail->fore() != NULL)
			tail = tail->fore();

		if (dhead_ptr->fore() == NULL)
			cout << "The doubly linked list is empty." << endl;
		else {
			dnode* cursor;
			cout << "The Foreward order of current doubly linked list is:" << endl;
			for (cursor = tail; cursor != NULL; cursor = cursor->back()) {
				cout << cursor->data() << "  ";
				cout << endl;
			}
		}
	}

	void list_showStatistics(dnode * dhead_ptr)
	{
		int count = 0;
		double sum = 0.0, average;
		dnode* cursor;
		int smallest = dhead_ptr->data();
		int largest = dhead_ptr->data();
		for (cursor = dhead_ptr; cursor != NULL; cursor = cursor->fore())
		{
			count++;
			if (smallest > cursor->data())
				smallest = cursor->data();
			if (largest < cursor->data())
				largest = cursor->data();
			sum = sum + cursor->data();
		}
		average = sum / count;
		cout << "Statistics:" << endl;
		cout << "Total sum: " << sum << endl;
		cout << "Largest: " << largest << endl;
		cout << "Smallest: " << smallest << endl;
		cout << "Average: " << average << endl;
	}

	void list_printForeward(dnode* dhead_ptr) {
		if (dhead_ptr == NULL)
			cout << "The doubly linked list is empty." << endl;
		else
		{
			dnode* cursor;
			cout << "The Foreward order of current doubly linked list is:" << endl;
			for (cursor = dhead_ptr; cursor != NULL; cursor = cursor->fore()) {
				cout << cursor->data() << "  ";
				cout << endl;
			}
		}
	}

	void dhead_insert(dnode *&dhead_ptr, const dnode::value_type & entry) {
		dnode *temp;
		temp = new dnode(entry, dhead_ptr, NULL);
		dhead_ptr->set_back(temp);
		dhead_ptr = temp;
	}

	void dtail_insert(dnode *&dhead_ptr, const dnode::value_type & entry) {
		dnode *temp, *cursor;
		temp = new dnode(entry, NULL, NULL);
		cursor = dhead_ptr;
		while (cursor->fore() != NULL)
			cursor = cursor->fore();
		cursor->set_fore(temp);
		temp->set_back(cursor);

	}
	void dhead_remove(dnode *&dhead_ptr) {
		dnode *remove;
		remove = dhead_ptr;
		dhead_ptr = dhead_ptr->fore();
		dhead_ptr->set_back(NULL);
		delete remove;
	}

	void dtail_remove(dnode *&dhead_ptr) {
		dnode *remove = NULL, *temp = NULL;
		if (dhead_ptr == NULL)
			cout << "Empty List";
		else {
			if (dhead_ptr->fore() == NULL) {
				remove = dhead_ptr;
				dhead_ptr = NULL;
				delete remove;
			} else {
				remove = dhead_ptr;
				while (remove->fore() != NULL) {
					temp = remove;
					remove = remove->fore();
				}
				temp->set_fore(NULL);
				delete remove;
			}
		}
	}
}
