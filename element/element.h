#ifndef ELEMENT_H
#define ELEMENT_H

// element of bidirectional list
/**
 * @brief Klasa reprezentująca element listy
 */
class element {
    private:
        element *previous_element;  /**< Wskaźnik do poprzedniego elementu listy */
        element *next_element;      /**< Wskaźnik do następnego elementu listy */
        int value;                  /**< Przechowuje wartość elementu listy */
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

#endif