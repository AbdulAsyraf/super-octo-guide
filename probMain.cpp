#include <iostream>
#include "prob.h"

using namespace std;

int main()
{
    int search;
    Whaa w;
    w.add();
    w.printData();
    cout << "Please enter a search term: ";
    cin >> search;
    w.search(search);
    w.printData();
}