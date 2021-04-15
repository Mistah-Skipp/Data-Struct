// FILE: node1.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <iostream>
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
	size_t list_length(const node* head_ptr)
		// Library facilities used: cstdlib
	{
		const node* cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())   //this is the way to traverse a linked list
			++answer;

		return answer;
	}

	void list_head_insert(node * &head_ptr, const node::value_type & entry)
	{
		head_ptr = new node(entry, head_ptr);
	}

	void list_insert(node * previous_ptr, const node::value_type & entry)
	{
		node* insert_ptr;

		insert_ptr = new node(entry, previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	node* list_search(node * head_ptr, const node::value_type & target)
		// Library facilities used: cstdlib
	{
		node* cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	const node * list_search(const node * head_ptr, const node::value_type & target)
		// Library facilities used: cstdlib
	{
		const node* cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	node * list_locate(node * head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		node* cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	const node * list_locate(const node * head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const node* cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	void list_head_remove(node * &head_ptr)
	{
		node* remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}

	void list_remove(node * previous_ptr)
	{
		node* remove_ptr;

		remove_ptr = previous_ptr->link();
		previous_ptr->set_link(remove_ptr->link());
		delete remove_ptr;
	}

	void list_clear(node * &head_ptr)
		// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	void list_copy(const node * source_ptr, node * &head_ptr, node * &tail_ptr)
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

	void list_print(const node* head_ptr) {
		size_t i;
		cout << "\nCurrent List: \n";
		for (i = 1; head_ptr != NULL; head_ptr = head_ptr->link()) {
			i++;

			cout << head_ptr->data() << "  ";
		}
			cout << "\n";
	}
	
	void showStatistics(node* head_ptr) {
		int count = 0;
		double sum = 0.0, average;
		node* cursor;
		int smallest = head_ptr->data();
		int largest = head_ptr->data();
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
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
	
	void list_tail_insert(node *& head_ptr, const node::value_type& entry) {
		node *temp = head_ptr;
		node* cursor = new node(entry, NULL);
		while(temp->link() != NULL)
			temp = temp->link();
		temp->set_link(cursor);
		
	}

	void list_tail_remove(node*& head_ptr) {
		node* remove_ptr = NULL, *temp = NULL;
		if (head_ptr == NULL)
			cout << "Empty list";
		else {
			if (head_ptr->link() == NULL) {
				remove_ptr = head_ptr;
				head_ptr = NULL;
				delete remove_ptr;
			} else {
				remove_ptr = head_ptr;
				while (remove_ptr->link() != NULL) {
					temp = remove_ptr;
					remove_ptr = remove_ptr->link();
				}
				temp->set_link(NULL);
				delete remove_ptr;
			}
		}
	}
	//END
}
