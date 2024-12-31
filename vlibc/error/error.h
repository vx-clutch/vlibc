#ifndef ERROR_H
#define ERROR_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* ANSI color codes */
static const char *RESET = "\033[0m";
static const char *RED = "\033[1;91m";
static const char *PURPLE = "\033[0;95m";
static const char *WHITE = "\033[0;97m";

/* Program Name */
char *__NAME = "C";

static inline void set_name(char *name) {
  __NAME = name;
}

/* fatal */
static inline void fatal_error(const char *message) {
  (void)fprintf(stderr,
                "%s%s%s: %sfatal error%s: %s\ncompilation terminated.\n",
                WHITE, __NAME, RESET, RED, RESET, message);
  exit(EXIT_FAILURE);
}

static inline void fatal_errorf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stderr, "%s%s%s: %sfatal error%s: ", WHITE, __NAME, RESET, RED, RESET);
  (void)vfprintf(stderr, format, args);
  (void)fprintf(stderr, "\ncompilation terminated.\n");
  va_end(args);
  exit(EXIT_FAILURE);
}

/* error */
static inline int error(const char *message) {
  (void)fprintf(stderr, "%s%s%s: %serror%s: %s\n", WHITE, __NAME, RESET, RED, RESET,
                message);
  return 0;
}

static inline void errorf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stderr, "%s%s%s: %serror%s: ", WHITE, __NAME ,RESET, RED, RESET);
  (void)vfprintf(stderr, format, args);
  (void)printf("\n");
  va_end(args);
}

/* warning */
static inline int warning(const char *message) {
  (void)fprintf(stderr, "%s%s%s: %swarning%s: %s\n", WHITE, __NAME, RESET, PURPLE,
                RESET, message);
  return 0;
}

static inline void warningf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stderr, "%s%s%s: %swarning%s: ", WHITE, __NAME, RESET, PURPLE, RESET);
  (void)vfprintf(stderr, format, args);
  (void)printf("\n");
  va_end(args);
}

/* debug */
static inline int debug(const char *tag, const char *message) {
  (void)printf("debug: %s: %s", tag, message);
  return 0;
}

static inline void debugf(const char *tag, const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stdout, "%s%s%s: ", WHITE, tag, RESET);
  (void)vfprintf(stdout, format, args);
  (void)printf("\n");
  va_end(args);
}

#endif
