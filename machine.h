#ifndef __MACHINE_H_
#define __MACHINE_H_ 1

#include <iostream>
#include <stack>

#include "errorhandler.h"
#include "printerrorhandler.h"
#include "stacktype.h"

/*
 * a stack based computing machine
 */
class Machine {
private: 
  std::stack<StackType*> *rpn;
  ErrorHandler  *errorHandler;
  
public: 
  Machine();

  ~Machine();

  const StackType *push(const double p);

  const StackType *push(const char* s);

  const StackType *add(void);

  const StackType *sub(void);

  const StackType *mul(void);

  const StackType *div(void);

  const StackType *acos(void);

  const StackType *abs(void);

  const StackType *acosh(void);

  const StackType *alog(void);

  int depth(void);

  void drop(void);

  void swap(void);

  void clear(void);
  
  void print(void);

protected:
  virtual void underflow(void);

  StackType* pop(void);
};

#endif
