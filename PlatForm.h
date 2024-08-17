

#ifndef PLATFORM_H
#define PLATFORM_H



#define CPU_T8 8
#define CPU_T16 16
#define CPU_T32 32
#define CPU_T64 64

#define CPU_ARCH (CPU_T64)


#if (CPU_ARCH == CPU_T8)
typedef bit boolean; // bit = 1 bit

typedef unsigned char uint_8;
typedef unsigned short uint_16; // short == int = 16 bit
typedef unsigned long uint_32; // long == long long = 32 bit

typedef char sint_8;
typedef short sint_16; // short == int = 16 bit
typedef long sint_32; // long == long long = 32 bit

typedef float float32; // float == double == long double = 32

#elif (CPU_ARCH == CPU_T16)
typedef unsigned char boolean;

typedef unsigned char uint_8;
typedef unsigned short uint_16; // short == int = 16 bit
typedef unsigned long uint_32;
typedef unsigned long long uint_64;

typedef char sint_8;
typedef short sint_16; // short == int = 16 bit
typedef long sint_32;
typedef long long sint_64;

typedef float float_32;
typedef double float_64;

#elif (CPU_ARCH == CPU_T32)
typedef unsigned char boolean;

typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned long uint_32; // long == int = 32 bit
typedef unsigned long long uint_64;

typedef char sint_8;
typedef short sint_16;
typedef long sint_32; // long == int = 32 bit
typedef long long sint_64;

typedef float float_32;
typedef double float_64;

#elif (CPU_ARCH == CPU_T64)
typedef unsigned char boolean;

typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned int uint_32; // int == long = 32 bit
typedef unsigned long long uint_64;

typedef char sint_8;
typedef short sint_16;
typedef int sint_32; // int == long = 32 bit
typedef long long sint_64;

typedef float float_32;
typedef double float_64;
typedef long double float_128;


#endif
#endif //PLATFORM_H
