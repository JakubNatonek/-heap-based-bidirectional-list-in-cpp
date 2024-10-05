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
    delete previous_element;
    delete next_element;
    delete this;
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
	public:
		list(int value);
		~list(void);
        void push_front(int value);


        void show(void);
};



// Creating a list with one element with a given value
list::list(int value) {
	element *element_list = new element;
    element_list->set_value(value);
    element_list->set_next_element(element_list);
    element_list->set_previous_element(element_list);

    this->first_element = element_list;
    this->last_element = element_list;
    this->size = 1;
}

list::~list(void) {

}

// Add an item to the start of the list
void list::push_front(int value) {
	element *element_list = new element;
    element_list->set_value(value);

    element_list->set_next_element(this->first_element);
    element_list->set_previous_element(element_list);

    this->first_element->set_previous_element(element_list);
    this->first_element = element_list;
    this->size = this->size + 1;
}

void list::show(void) {
    cout << this->first_element->get_value() << endl;
}


void push_back();
void push_by_index();
void pop_front();
void pop_back();
void pop_by_index();

void show_reverse();
void show_next();
void show_previous();
void clear();




//------------------------------------------------------------------------

int main() {
    
    list table(1);

    table.push_front(2);

    table.show();

  return 0;
}