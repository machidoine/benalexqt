#include "test.h"
#include <QApplication>
#include <iostream>
using namespace std;

Test::Test()
{

}

Test::~Test() {
    cout << "delete" << endl;
}

void Test::t() {
     cout << "in t" << endl;
}
