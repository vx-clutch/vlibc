#ifndef IO_H
#define IO_H

#include <cstdarg>
#include <stdio.h>

int printfn(const char *__restrict format, ...) {
  va_list args;
  va_start(args, format);
  int status = printf(format, args);
  printf("\n");
  va_end(args);
  return status;
}

#endif
