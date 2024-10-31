#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "element/element.h"

using namespace std;

// bidirectional list
/**
 * @brief Klasa reprezentująca listę dwukierunkową
 */
class list {
	private:
        int size;                   /**< Przechowuje długość listy */ 
        element *first_element;     /**< Wskaźnik na początek listy */
        element *last_element;      /**< Wskaźnik na koniec listy */
        element *current_element;   /**< Wskaźnik na ostatnio modyfikowany element */
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