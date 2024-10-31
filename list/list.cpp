#include "list.h"

//------------------------------------------------------------------------


// creating a list with one element with a given value
/**
 * @brief Konstruktor, który inicjalizuję listę z jednym elementem
 * @param value Wartość do dodania
 */
list::list(int value) {
	element *element_list = new element;
    element_list->set_value(value);
    element_list->set_next_element(element_list);
    element_list->set_previous_element(element_list);

    this->first_element = element_list;
    this->last_element = element_list;

    this->current_element = element_list;

    this->size = 1;
}

// freeing memory
/**
 * @brief Destruktor do zwalniania pamięci
 */
list::~list(void) {
    clear();
}

// add an item to the front of the list
/**
 * @brief Dodaj element na początek listy
 * @param value Wartość do dodania
 */
void list::push_front(int value) {
    if(this->size == 0) {
        this->list_initialization(value);
        return;
    }

	element *element_list = new element;
    element_list->set_value(value);

    element_list->set_next_element(this->first_element);
    element_list->set_previous_element(element_list);

    this->first_element->set_previous_element(element_list);
    this->first_element = element_list;

    this->current_element = element_list;

    this->size = this->size + 1;
}

// add an item to the back of the list
/**
 * @brief Dodaj element na koniec listy
 * @param value Wartość do dodania
 */
void list::push_back(int value) {
    if(this->size == 0) {
        this->list_initialization(value);
        return;
    }

    element *element_list = new element;
    element_list->set_value(value);

    element_list->set_next_element(element_list);
    element_list->set_previous_element(this->last_element);

    this->last_element->set_next_element(element_list);
    this->last_element = element_list;

    this->current_element = element_list;

    this->size = this->size + 1;
}

// add an item to a given index list
/**
 * @brief Dodaj element pod wskazany indeks
 * @param index Indeks, pod którym dodać element
 * @param value Wartość do dodania
 */
void list::push_by_index(int value, int index) {
    if(this->size == 0) {
        this->list_initialization(value);
        return;
    }

    if(index <= 0) {
        this->push_front(value);
        return;
    }

    if(index >= this->size) {
        this->push_back(value);
        return;
    }

    element *element_list_new = new element;
    element_list_new->set_value(value);

    element *element_list;
    if(index < (this->size / 2) ) {
        element_list = this->first_element;
        for(int i = 0; i < index; i++) {
            element_list = element_list->get_next_element();
        }
    }
    else {
        element_list = this->last_element;
        for(int i = this->size; i > index + 1; i--) {
            element_list = element_list->get_previous_element();
        }
    }

    element_list_new->set_next_element(element_list);
    element_list_new->set_previous_element(element_list->get_previous_element());

    element_list->get_previous_element()->set_next_element(element_list_new);

    element_list->set_previous_element(element_list_new);

    this->current_element = element_list_new;

    this->size = this->size + 1;
}

// removing an item from the front of the list
/**
 * @brief Usuń element z początku listy
 * @return Wartosć usuwanego elementu
 */
int list::pop_front() {
    if(this->size == 0) {
        return;
    }

    element *element_list = this->first_element;

    this->first_element = element_list->get_next_element();
    this->first_element->set_previous_element(this->first_element);

    this->current_element = this->first_element;

    this->size = this->size - 1;

    return element_list->get_value();
}

// removing an item from the back of the list
/**
 * @brief Usuń element z końca listy
 * @return Wartosć usuwanego elementu
 */
int list::pop_back() {
    if(this->size == 0) {
        return;
    }

    element *element_list = this->last_element;

    this->last_element = element_list->get_previous_element();
    this->last_element->set_next_element(this->last_element);

    this->current_element = this->last_element;

    this->size = this->size - 1;

    return element_list->get_value();
}

// removing an item from the given index of the list
/**
 * @brief Usuń element z pod wskazanego indeksu
 * @param index Indeks, z którego usunąć element
 * @return Wartosć usuwanego elementu
 */
int list::pop_by_index(int index) {
    if(this->size == 0) {
        return;
    }

    if(index <= 0) {
        return this->pop_front();
    }

    if(index >= this->size) {
        return this->pop_back();
    }

    element *element_list;
    if(index < (this->size / 2) ) {
        element_list = this->first_element;
        for(int i = 0; i < index; i++) {
            element_list = element_list->get_next_element();
        }
    }
    else {
        element_list = this->last_element;
        for(int i = this->size; i > index + 1; i--) {
            element_list = element_list->get_previous_element();
        }
    }

    element_list->get_previous_element()->set_next_element(element_list->get_next_element());
    element_list->get_next_element()->set_previous_element(element_list->get_previous_element());

    this->current_element = element_list->get_next_element();


    this->size = this->size - 1;

    return element_list->get_value();
}

// displaying the contents of the list
/**
 * @brief Wyświetl całą listę
 */
void list::show(void) {
    if(this->size == 0) {
        return;
    }

    element *element_list = this->first_element;
    for(int i = 0; i < this->size; i++) {
        cout << element_list->get_value() << endl;
        element_list = element_list->get_next_element();
    }   
}

// displaying the contents of the list in reverse order
/**
 * @brief Wyświetl listę w odwrotnej kolejności
 */
void list::show_reverse() {
    if(this->size == 0) {
        return;
    }

    element *element_list = this->last_element;
    for(int i = this->size; i > 0; i--) {
        cout << element_list->get_value() << endl;
        element_list = element_list->get_previous_element();
    } 
}

// show next element
/**
 * @brief Wyświetl następnego elementu od ostatnio modyfikowanego elementu
 */
void list::show_next() {
    if(this->size == 0) {
        return;
    }
    cout << this->current_element->get_next_element()->get_value() << endl;

    this->current_element = this->current_element->get_next_element();
}

// show previous element
/**
 * @brief Wyświetl poprzedniego elementu od ostatnio modyfikowanego elementu
 */
void list::show_previous() {
    if(this->size == 0) {
        return;
    }

    cout << this->current_element->get_previous_element()->get_value() << endl;

    this->current_element = this->current_element->get_previous_element();
}

// clear the list
/**
 * @brief Czyść całą listę
 */
void list::clear() {
    element *element_list = this->first_element;
    for(int i = 0; i < this->size; i++) {
        element *element_list_delete = element_list;
        element_list = element_list->get_next_element();
        delete element_list_delete;
    }

    this->size = 0;
}

// show current element
/**
 * @brief Wyświetl ostatnio modyfikowanego elementu
 */
void list::show_current() {
    if(this->size == 0) {
        return;
    }

    cout << this->current_element->get_value() << endl;
}

// add an item to the list
/**
 * @brief Inicjalizuja listy z jednym elementem
 * @param value Wartość do dodania
 */
void list::list_initialization(int value) {
    element *element_list = new element;
    element_list->set_value(value);
    element_list->set_next_element(element_list);
    element_list->set_previous_element(element_list);

    this->first_element = element_list;
    this->last_element = element_list;

    this->current_element = element_list;

    this->size = 1;
}
