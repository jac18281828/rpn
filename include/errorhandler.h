#ifndef __ERROR_HANDLER_H_
#define __ERROR_HANDLER_H_ 1

#include <string>

class ErrorHandler {
public:
  virtual void underflow(void) const = 0;
  
  virtual void badargument(const char* ctx) const = 0;
};

#endif
