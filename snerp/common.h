#pragma once

#ifdef _WIN32
#define SNPRINTF sprintf_s
#else
#define SNPRINTF snprintf
#endif

#define CHECK(cond, ...) do { \
  if (!(cond)) { \
	char buf[512]; \
	SNPRINTF(buf, 511, "" __VA_ARGS__); \
	fprintf(stderr, "CHECK failed (%s:%d): %s %s\n", __FILE__, __LINE__, #cond, buf); \
	_flushall(); \
	abort(); \
  } \
} while (0)


#define TRACE_ERROR 0
#define TRACE_WARNING 1
#define TRACE_INFO 2
#define TRACE_DEBUG 3
#define TRACE_SPAM 4

#define TRACE_LEVEL TRACE_INFO

#define TRACE(level, ...) \
do { \
  if ((level) <= TRACE_LEVEL) { \
    printf("%s %s:%d - ", #level, __FILE__, __LINE__); \
    printf(__VA_ARGS__); \
    printf("\n"); \
  } \
} while (0)