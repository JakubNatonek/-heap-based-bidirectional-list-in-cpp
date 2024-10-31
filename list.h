#ifndef LIST_H
#define LIST_H

#include "element.h"

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
        int pop_front();
        int pop_back();
        int pop_by_index(int index);
        void show(void);
        void show_reverse();
        void show_next();
        void show_previous();
        void clear();

        void show_current();
        void list_initialization(int value);
};

#endif