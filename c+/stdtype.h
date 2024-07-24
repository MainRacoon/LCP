#ifndef _CP_STDTYPE
#define _CP_STDTYPE
#include <stdbool.h>
typedef signed      char            int8,   i8;
typedef unsigned    char            uint8,  u8;
typedef signed      short           int16,  i16;
typedef unsigned    short           uint16, u16;
typedef signed      int             int32,  i32;
typedef unsigned    int             uint32, u32;
typedef signed      long long       int64,  i64;
typedef unsigned    long long       uint64, u64;

typedef float                       float32,f32;
typedef double                      float64,f64;
typedef long double                 float80,f80;


#define max(x,y) x>y?x:y
#define min(x,y) x>y?y:x
#endif