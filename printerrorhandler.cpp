#include <iostream>
#include "printerrorhandler.h"

using namespace std;

void PrintErrorHandler::underflow(void) const {
  cerr << "underflow." << endl;
}

void PrintErrorHandler::badargument(const char ctx[]) const {
  cerr << "Error " << ctx << ": bad argument." << endl;
}
