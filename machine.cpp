#include "machine.h"
#include "stacktype.h"
#include "doublestacktype.h"
#include "stringstacktype.h"

using namespace std;

Machine::Machine() {
  rpn = new stack<StackType*>();
  errorHandler = new PrintErrorHandler();
}

Machine::~Machine() {
  delete(rpn);
  delete(errorHandler);
}

const StackType* Machine::push(const double p) {
  StackType *d = new DoubleStackType(p, errorHandler);
  rpn->push(d);
  return rpn->top();
}


const StackType* Machine::push(const char* s) {
  StackType *st = new StringStackType(s, errorHandler);
  rpn->push(st);
  return rpn->top();
}

const StackType* Machine::add(void) {
  if(rpn->size() > 1) {
    const StackType *r2 = pop();
    StackType *r  = rpn->top();
    
    *r += *r2;
    
    delete(r2);
    return r;
  } else {
    underflow();
  }
}

const StackType* Machine::sub(void) {
  if(rpn->size() > 1) {
    const StackType *r2 = pop();
    StackType *r  = rpn->top();

    *r -= *r2;

    delete(r2);
    return r;
  } else {
    underflow();
  }
}


const StackType* Machine::mul(void) {
  if(rpn->size() > 1) {
    const StackType *r2 = pop();
    StackType *r  = rpn->top();

    *r *= *r2;

    delete(r2);
    return r;
  } else {
    underflow();
  }
}

const StackType* Machine::div(void) {
  if(rpn->size() > 1) {
    const StackType *r2 = pop();
    StackType *r  = rpn->top();

    *r /= *r2;

    delete(r2);
    return r;
  } else {
    underflow();
  }
}

const StackType* Machine::acos(void) {
  if(rpn->size() > 0) {
    StackType* a = rpn->top();
    a->acos();
    return a;
  } else {
    underflow();
  }
}

const StackType* Machine::abs(void) {
  if(rpn->size() > 0) {
    StackType* a = rpn->top();
    a->abs();
    return a;
  } else {
    underflow();
  }
}

const StackType* Machine::acosh(void) {
  if(rpn->size() > 0) {
    StackType* a = rpn->top();
    a->acosh();
    return a;
  } else {
    underflow();
  }
}

const StackType* Machine::alog(void) {
  if(rpn->size() > 0) {
    StackType* a = rpn->top();
    a->alog();
    return a;
  } else {
    underflow();
  }
}


void Machine::drop(void) {
  if(!rpn->empty()) {
    delete(pop());
  }
}

void Machine::swap(void) {
  if(rpn->size() > 1) {
    StackType* r2 = pop();
    StackType* r1 = pop();
    rpn->push(r2);
    rpn->push(r1);
  } else {
    underflow();
  }
}

void Machine::clear(void) {
  while(!rpn->empty()) {
    delete(pop());
  }
}
  
void Machine::print(void) {
  if(!rpn->empty()) {
    const StackType* st = rpn->top();
    cout << "= " << *st << endl;
  }
}

void Machine::underflow(void) {
  errorHandler->underflow();
}

StackType* Machine::pop(void) {
  StackType* r = rpn->top(); rpn->pop();
  return r;
}

int Machine::depth(void) {
  push(rpn->size());
}
