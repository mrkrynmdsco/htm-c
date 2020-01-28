
#ifndef HTM_TYPES_H
#define HTM_TYPES_H


#include <stdlib.h>
#include <stdint.h>


#define CHAR_BITS   8

/**
 * Represents an 8-bit signed integer
 */
typedef char sint8;

/**
 * Represents an 8-bit unsigned integer
 */
typedef unsigned char uint8;
typedef unsigned char byte;

/**
 * Represents a 16-bit signed integer.
 */
typedef short sint16;

/**
 * Represents a 16-bit unsigned integer.
 */
typedef unsigned short uint16;

/**
 * Represents a 32-bit signed integer.
 */
typedef int32_t sint32;

/**
 * Represents a 32-bit unsigned integer.
 */
typedef uint32_t uint32;

/**
 * Represents a 64-bit signed integer.
 */
typedef int64_t sint64;

/**
 * Represents a 64-bit unsigned integer.
 */
typedef uint64_t uint64;

/**
 * Represents a 32-bit real number(a floating-point number).
 */
typedef float real32;

/**
 * Represents a 64-bit real number(a floating-point number).
 */
typedef double real64;


#endif // HTM_TYPES_H
