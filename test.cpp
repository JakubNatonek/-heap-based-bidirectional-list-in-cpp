#include <iostream>

using namespace std;

//------------------------------------------------------------------------

// element of bidirectional list
class element {
    private:
        element *previous_element;
        element *next_element;
        int value;
    public:
        element(void);
        ~element(void);

        void set_value(int value);
        int get_value(void);

        void set_previous_element(element *previous_element);
        element* get_previous_element(void);

        void set_next_element(element *next_element);
        element* get_next_element(void);
};

element::element(void) {

};

element::~element(void) {

}

// seting value
void element::set_value(int value) {
    this->value = value;
}

// geting value
int element::get_value(void) {
   return this->value;
}

// seting previous element
void element::set_previous_element(element *previous_element) {
    this->previous_element = previous_element;
}

// geting previous element
element* element::get_previous_element(void) {
   return this->previous_element;
}

// seting next element
void element::set_next_element(element *next_element) {
    this->next_element = next_element;
}

// geting next element
element* element::get_next_element(void) {
   return this->next_element;
}


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



// creating a list with one element with a given value
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

list::~list(void) {
    clear();
}

// add an item to the front of the list
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
int list::pop_front() {
    if(this->size == 0) {
        return NULL;
    }

    element *element_list = this->first_element;

    this->first_element = element_list->get_next_element();
    this->first_element->set_previous_element(this->first_element);

    this->current_element = this->first_element;

    this->size = this->size - 1;

    return element_list->get_value();
}

// removing an item from the back of the list
int list::pop_back() {
    if(this->size == 0) {
        return NULL;
    }

    element *element_list = this->last_element;

    this->last_element = element_list->get_previous_element();
    this->last_element->set_next_element(this->last_element);

    this->current_element = this->last_element;

    this->size = this->size - 1;

    return element_list->get_value();
}

// removing an item from the given index of the list
int list::pop_by_index(int index) {
    if(this->size == 0) {
        return NULL;
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
void list::show_next() {
    if(this->size == 0) {
        return;
    }
    cout << this->current_element->get_next_element()->get_value() << endl;

    this->current_element = this->current_element->get_next_element();
}

// show previous element
void list::show_previous() {
    if(this->size == 0) {
        return;
    }

    cout << this->current_element->get_previous_element()->get_value() << endl;

    this->current_element = this->current_element->get_previous_element();
}

// clear the list
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
void list::show_current() {
    if(this->size == 0) {
        return;
    }

    cout << this->current_element->get_value() << endl;
}

// add an item to the list
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


//------------------------------------------------------------------------

int main() {
    
    list table(1);

    table.push_front(2);

    table.push_back(0);
    table.push_back(2);
    table.push_back(3);
    table.push_back(4);

    table.show();

    cout << "---------------" << endl;

    table.push_by_index(8, 5);

    table.show();

    cout << "---------------" << endl;

    table.push_by_index(9, 2);

    table.show();

    cout << "---------------" << endl;

    cout << table.pop_front() << endl;

    cout << "---------------" << endl;

    table.show();

    cout << "---------------" << endl;

    cout << table.pop_back() << endl;

    cout << "---------------" << endl;

    table.show();

    cout << "---------------" << endl;

    cout << table.pop_by_index(2) << endl;

    cout << "---------------" << endl;

    table.show();

    cout << "---------------" << endl;

    table.show_reverse();

    cout << "---------------" << endl;

    table.show_next();

    cout << "---------------" << endl;

    table.show_previous();

    cout << "---------------" << endl;

    table.clear();
    table.clear();
   
    table.show();

    cout << "---------------" << endl;

    table.push_by_index(9, 30);

    table.show();

  return 0;
}