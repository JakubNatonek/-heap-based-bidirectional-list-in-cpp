#include <iostream>
#include "element/element.h"
#include "list/list.h"

using namespace std;

//------------------------------------------------------------------------

/**
 * @brief Funkcja główna
 * @return Kod zakończenia
 */
int main() {
    
    // creating a new table
    list table(1);

    // pushing value to table
    table.push_front(2);
    table.push_back(0);
    table.push_back(2);
    table.push_back(3);
    table.push_back(4);

    // showing values in table
    table.show();

    cout << "---------------" << endl;

    table.push_by_index(8, 5);

    // showing values in table
    table.show();

    cout << "---------------" << endl;

    // pushing element by index
    table.push_by_index(9, 2);

    // showing values in table
    table.show();

    cout << "---------------" << endl;

    // removing element
    cout << table.pop_front() << endl;

    cout << "---------------" << endl;

    // showing values in table
    table.show();

    cout << "---------------" << endl;

    // removing element
    cout << table.pop_back() << endl;

    cout << "---------------" << endl;

    // showing values in table
    table.show();

    cout << "---------------" << endl;

    // removing element by index
    cout << table.pop_by_index(2) << endl;

    cout << "---------------" << endl;

    // showing values in table
    table.show();

    cout << "---------------" << endl;

    // showing values in table
    table.show_reverse();

    cout << "---------------" << endl;

    // showing next element
    table.show_next();

    cout << "---------------" << endl;

    // showing previous element
    table.show_previous();

    cout << "---------------" << endl;

    // clearing table
    table.clear();
    table.clear();
   
    // showing values in table
    table.show();

    cout << "---------------" << endl;

    // pushing value to table
    table.push_by_index(9, 30);

    // showing values in table
    table.show();

  return 0;
}