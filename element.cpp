#include "element.h"

//------------------------------------------------------------------------
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