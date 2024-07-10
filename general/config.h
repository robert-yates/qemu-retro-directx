#ifndef __WINE_CONFIG_H
#define __WINE_CONFIG_H

#define _X86_
#define __i386__

#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
#define __WINE_ALLOC_SIZE(x) __attribute__((__alloc_size__(x)))
#else
#define __WINE_ALLOC_SIZE(x)
#endif

#ifndef ARRAY_SIZE
# define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#define EXEEXT ".exe"
#define HAVE_FLOAT_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_ISFINITE 1
#define HAVE_ISINF 1
#define HAVE_ISNAN 1
#define HAVE_PTHREAD_H 1
#define HAVE_SCHED_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define HAVE_UTIME_H 1
#define HAVE___CLEAR_CACHE 1
#define PACKAGE_BUGREPORT "wine-devel@winehq.org"

#define PACKAGE_NAME "Wine"
#define PACKAGE_STRING "Wine 9.12"
#define PACKAGE_TARNAME "wine"
#define PACKAGE_URL "https://www.winehq.org"
#define PACKAGE_VERSION "9.12"

#define SONAME_LIBNETAPI "libnetapi.dll"
#define SONAME_LIBODBC "libodbc.dll"

#define STDC_HEADERS 1
#define X_DISPLAY_MISSING 1
#define _FILE_OFFSET_BITS 64

#define __WINESRC__ 1
#define USE_WIN32_OPENGL

#ifndef M_PI
  #define M_PI  3.14159265358979323846264f  // from CRC
#endif

#define DCX_USESTYLE         0x00010000
#define DECLSPEC_HOTPATCH

#include <sdkddkver.h>
#if defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0A00)
  #define DUMMYUNIONNAME u1
  #define DUMMYUNIONNAME2 u2
  #define DUMMYSTRUCTNAME s1
  #define DUMMYSTRUCTNAME2 s2
  #define STRUCTURE_ACCESS_1_STABLE(var, union1, field) var.union1.field
  #define STRUCTURE_ACCESS_1(var, union1, field) var.union1.field
  #define STRUCTURE_ACCESS_1P(var, union1, field) var->union1.field
  #define STRUCTURE_ACCESS_2(var, union1, union2, field) var.union1.union2.field
  #define STRUCTURE_ACCESS_2P(var, union1, union2, field) var->union1.union2.field
#else
  #define DUMMYUNIONNAME u1
  #define STRUCTURE_ACCESS_1_STABLE(var, union1, field) var.union1.field
  #define STRUCTURE_ACCESS_1(var, union1, field) var.field
  #define STRUCTURE_ACCESS_1P(var, union1, field) var->field
  #define STRUCTURE_ACCESS_2P(var, union1, union2, field) var->field
#endif

#endif /* __WINE_CONFIG_H */