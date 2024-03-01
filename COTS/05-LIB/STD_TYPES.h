/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : STD_TYPES.h                *****************/
/****************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/**< Include standard integer types for fixed-size definitions */ 
#include <stdint.h> 

typedef uint8_t  u8;           /**< 8-bit unsigned integer type */
typedef uint16_t u16;          /**< 16-bit unsigned integer type */
typedef uint32_t u32;          /**< 32-bit unsigned integer type */
typedef uint64_t u64;          /**< 64-bit unsigned integer type */

typedef int8_t  s8;            /**< 8-bit signed integer type */
typedef int16_t s16;           /**< 16-bit signed integer type */
typedef int32_t s32;           /**< 32-bit signed integer type */
typedef int64_t s64;           /**< 64-bit signed integer type */

typedef float  f32;            /**<  Single-precision floating-point type */
typedef double f64;            /**<  Double-precision floating-point type */
typedef long double f96;       /**<  Extended-precision floating-point type */

typedef u8 Std_ReturnType;     /**< Standard return type for functions */
typedef s8 INVALID_VALUE;      /**< Marker for invalid or uninitialized data */

#define NULL ((void *)0x0)     /**< Null pointer definition */

#define E_OK ((Std_ReturnType)1)                    /**< Function execution successful */
#define E_NOT_OK ((Std_ReturnType)0)                /**< Function execution failed */

#define E_INVALID_PARAMETER  ((INVALID_VALUE)-1)    /**< Invalid parameter marker */



#endif /* STD_TYPES_H_ */


