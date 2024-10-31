#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "element/element.h"

using namespace std;

// bidirectional list
class list {
	private:
		int size;
        element *first_element;
        element *last_element;
        element *current_element;
	public:
		list(int value);
		~list(void);
        void push_front(int value);
        void push_back(int value);
        void push_by_index(int value, int index);
        int pop_front(void);
        int pop_back(void);
        int pop_by_index(int index);
        void show(void);
        void show_reverse(void);
        void show_next(void);
        void show_previous(void);
        void clear(void);

        void show_current(void);
        void list_initialization(int value);
};

#endif