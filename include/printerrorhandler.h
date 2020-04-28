#ifndef __PRINT_ERROR_HANDLER_H_
#define __PRINT_ERROR_HANDLER_H_ 1

#include "errorhandler.h"

class PrintErrorHandler : public ErrorHandler {
public:
  void underflow(void) const;

  void badargument(const char ctx[]) const;
};

#endif
