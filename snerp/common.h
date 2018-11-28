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