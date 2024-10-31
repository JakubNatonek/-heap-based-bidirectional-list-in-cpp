#include "element.h"

//------------------------------------------------------------------------
element::element(void) {

};

element::~element(void) {

}

// seting value
/**
 * @brief Funkcja ustawiająca wartosć elementu listy
 * @param value Wartość, którą przechowuje elementu listy
 */
void element::set_value(int value) {
    this->value = value;
}

// geting value
/**
 * @brief Funkcja zwracająca wartość którą przechowuje elementu listy
 * @return Wartosć elementu listy
 */
int element::get_value(void) {
   return this->value;
}

// seting previous element
/**
 * @brief Funkcja ustawiająca poprzedni element
 * @param previous_element Wartość, którą przechowuje element listy
 */
void element::set_previous_element(element *previous_element) {
    this->previous_element = previous_element;
}

// geting previous element
/**
 * @brief Funkcja zwracająca poprzedni element
 * @return poprzedni element
 */
element* element::get_previous_element(void) {
   return this->previous_element;
}

// seting next element
/**
 * @brief Funkcja ustawiająca nastempny element
 * @param next_element Wartość, którą przechowuje element listy
 */
void element::set_next_element(element *next_element) {
    this->next_element = next_element;
}

// geting next element
/**
 * @brief Funkcja zwracająca nastempny element
 * @return nastempny element
 */
element* element::get_next_element(void) {
   return this->next_element;
}
