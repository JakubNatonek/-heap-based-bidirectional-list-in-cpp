#include <iostream>
#include "element/element.h"
#include "list/list.h"

using namespace std;

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