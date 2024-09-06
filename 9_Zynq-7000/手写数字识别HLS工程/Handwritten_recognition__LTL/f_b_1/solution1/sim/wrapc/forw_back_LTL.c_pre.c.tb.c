// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_1/forw_back_LTL.c"
# 1 "C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_1/forw_back_LTL.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_1/forw_back_LTL.c" 2
# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 1 3
# 10 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
# 10 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3


# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 10 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 1 3
# 10 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 277 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 1 3
# 13 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 674 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3
# 674 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3

# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3
# 675 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 13 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 2 3


#pragma pack(push,_CRT_PACKING)








 typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 102 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
#pragma pack(pop)
# 277 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3


#pragma pack(push,_CRT_PACKING)
# 370 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long size_t;
# 380 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ssize_t;
# 392 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long intptr_t;
# 405 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long uintptr_t;
# 418 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ptrdiff_t;
# 428 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;
# 456 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;







typedef __time64_t time_t;
# 607 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {
  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;
} threadlocinfo;







const char *__mingw_get_crt_info (void);





#pragma pack(pop)
# 12 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 2 3


struct _exception;

#pragma pack(push,_CRT_PACKING)
# 79 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 extern double * __imp__HUGE;
# 91 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  struct _exception {
    int type;
    const char *name;
    double arg1;
    double arg2;
    double retval;
  };

  void __mingw_raise_matherr (int typ, const char *name, double a1, double a2,
         double rslt);
  void __mingw_setusermatherr (int (__cdecl *)(struct _exception *));
  __attribute__ ((__dllimport__)) void __setusermatherr(int (__cdecl *)(struct _exception *));



  double __cdecl sin(double _X);
  double __cdecl cos(double _X);
  double __cdecl tan(double _X);
  double __cdecl sinh(double _X);
  double __cdecl cosh(double _X);
  double __cdecl tanh(double _X);
  double __cdecl asin(double _X);
  double __cdecl acos(double _X);
  double __cdecl atan(double _X);
  double __cdecl atan2(double _Y,double _X);
  double __cdecl exp(double _X);
  double __cdecl log(double _X);
  double __cdecl log10(double _X);
  double __cdecl pow(double _X,double _Y);
  double __cdecl sqrt(double _X);
  double __cdecl ceil(double _X);
  double __cdecl floor(double _X);
  double __cdecl fabs(double _X);
# 135 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  double __cdecl ldexp(double _X,int _Y);
  double __cdecl frexp(double _X,int *_Y);
  double __cdecl modf(double _X,double *_Y);
  double __cdecl fmod(double _X,double _Y);

  void __cdecl sincos (double __x, double *p_sin, double *p_cos);
  void __cdecl sincosl (long double __x, long double *p_sin, long double *p_cos);
  void __cdecl sincosf (float __x, float *p_sin, float *p_cos);



  int __cdecl abs(int _X);
  long __cdecl labs(long _X);



  double __cdecl atof(const char *_String);
  double __cdecl _atof_l(const char *_String,_locale_t _Locale);
# 162 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  struct _complex {
    double x;
    double y;
  };


  __attribute__ ((__dllimport__)) double __cdecl _cabs(struct _complex _ComplexA);
  double __cdecl _hypot(double _X,double _Y);
  __attribute__ ((__dllimport__)) double __cdecl _j0(double _X);
  __attribute__ ((__dllimport__)) double __cdecl _j1(double _X);
  __attribute__ ((__dllimport__)) double __cdecl _jn(int _X,double _Y);
  __attribute__ ((__dllimport__)) double __cdecl _y0(double _X);
  __attribute__ ((__dllimport__)) double __cdecl _y1(double _X);
  __attribute__ ((__dllimport__)) double __cdecl _yn(int _X,double _Y);


  __attribute__ ((__dllimport__)) int __cdecl _matherr (struct _exception *);
# 189 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  __attribute__ ((__dllimport__)) double __cdecl _chgsign (double _X);
  __attribute__ ((__dllimport__)) double __cdecl _copysign (double _Number,double _Sign);
  __attribute__ ((__dllimport__)) double __cdecl _logb (double);
  __attribute__ ((__dllimport__)) double __cdecl _nextafter (double, double);
  __attribute__ ((__dllimport__)) double __cdecl _scalb (double, long);
  __attribute__ ((__dllimport__)) int __cdecl _finite (double);
  __attribute__ ((__dllimport__)) int __cdecl _fpclass (double);
  __attribute__ ((__dllimport__)) int __cdecl _isnan (double);






__attribute__ ((__dllimport__)) double __cdecl j0 (double) ;
__attribute__ ((__dllimport__)) double __cdecl j1 (double) ;
__attribute__ ((__dllimport__)) double __cdecl jn (int, double) ;
__attribute__ ((__dllimport__)) double __cdecl y0 (double) ;
__attribute__ ((__dllimport__)) double __cdecl y1 (double) ;
__attribute__ ((__dllimport__)) double __cdecl yn (int, double) ;

__attribute__ ((__dllimport__)) double __cdecl chgsign (double);
# 219 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  __attribute__ ((__dllimport__)) int __cdecl finite (double);
  __attribute__ ((__dllimport__)) int __cdecl fpclass (double);
# 264 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
typedef float float_t;
typedef double double_t;
# 299 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern int __cdecl __fpclassifyl (long double);
  extern int __cdecl __fpclassifyf (float);
  extern int __cdecl __fpclassify (double);
# 335 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern int __cdecl __isnan (double);
  extern int __cdecl __isnanf (float);
  extern int __cdecl __isnanl (long double);
# 376 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern int __cdecl __signbit (double);
  extern int __cdecl __signbitf (float);
  extern int __cdecl __signbitl (long double);
# 404 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern float __cdecl sinf(float _X);
  extern long double __cdecl sinl(long double);

  extern float __cdecl cosf(float _X);
  extern long double __cdecl cosl(long double);

  extern float __cdecl tanf(float _X);
  extern long double __cdecl tanl(long double);
  extern float __cdecl asinf(float _X);
  extern long double __cdecl asinl(long double);

  extern float __cdecl acosf (float);
  extern long double __cdecl acosl (long double);

  extern float __cdecl atanf (float);
  extern long double __cdecl atanl (long double);

  extern float __cdecl atan2f (float, float);
  extern long double __cdecl atan2l (long double, long double);


  extern float __cdecl sinhf(float _X);



  extern long double __cdecl sinhl(long double);

  extern float __cdecl coshf(float _X);



  extern long double __cdecl coshl(long double);

  extern float __cdecl tanhf(float _X);



  extern long double __cdecl tanhl(long double);



  extern double __cdecl acosh (double);
  extern float __cdecl acoshf (float);
  extern long double __cdecl acoshl (long double);


  extern double __cdecl asinh (double);
  extern float __cdecl asinhf (float);
  extern long double __cdecl asinhl (long double);


  extern double __cdecl atanh (double);
  extern float __cdecl atanhf (float);
  extern long double __cdecl atanhl (long double);



  extern float __cdecl expf(float _X);



  extern long double __cdecl expl(long double);


  extern double __cdecl exp2(double);
  extern float __cdecl exp2f(float);
  extern long double __cdecl exp2l(long double);



  extern double __cdecl expm1(double);
  extern float __cdecl expm1f(float);
  extern long double __cdecl expm1l(long double);


  extern float frexpf(float _X,int *_Y);



  extern long double __cdecl frexpl(long double,int *);




  extern int __cdecl ilogb (double);
  extern int __cdecl ilogbf (float);
  extern int __cdecl ilogbl (long double);


  extern float __cdecl ldexpf(float _X,int _Y);



  extern long double __cdecl ldexpl (long double, int);


  extern float __cdecl logf (float);
  extern long double __cdecl logl(long double);


  extern float __cdecl log10f (float);
  extern long double __cdecl log10l(long double);


  extern double __cdecl log1p(double);
  extern float __cdecl log1pf(float);
  extern long double __cdecl log1pl(long double);


  extern double __cdecl log2 (double);
  extern float __cdecl log2f (float);
  extern long double __cdecl log2l (long double);


  extern double __cdecl logb (double);
  extern float __cdecl logbf (float);
  extern long double __cdecl logbl (long double);
# 553 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern float __cdecl modff (float, float*);
  extern long double __cdecl modfl (long double, long double*);


  extern double __cdecl scalbn (double, int);
  extern float __cdecl scalbnf (float, int);
  extern long double __cdecl scalbnl (long double, int);

  extern double __cdecl scalbln (double, long);
  extern float __cdecl scalblnf (float, long);
  extern long double __cdecl scalblnl (long double, long);



  extern double __cdecl cbrt (double);
  extern float __cdecl cbrtf (float);
  extern long double __cdecl cbrtl (long double);


  extern float __cdecl fabsf (float x);
# 583 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern long double __cdecl fabsl (long double);
# 595 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern double __cdecl hypot (double, double) ;
  extern float __cdecl hypotf (float x, float y);



  extern long double __cdecl hypotl (long double, long double);


  extern float __cdecl powf(float _X,float _Y);



  extern long double __cdecl powl (long double, long double);


  extern float __cdecl sqrtf (float);
  extern long double sqrtl(long double);


  extern double __cdecl erf (double);
  extern float __cdecl erff (float);
  extern long double __cdecl erfl (long double);


  extern double __cdecl erfc (double);
  extern float __cdecl erfcf (float);
  extern long double __cdecl erfcl (long double);


  extern double __cdecl lgamma (double);
  extern float __cdecl lgammaf (float);
  extern long double __cdecl lgammal (long double);


  extern double __cdecl tgamma (double);
  extern float __cdecl tgammaf (float);
  extern long double __cdecl tgammal (long double);


  extern float __cdecl ceilf (float);
  extern long double __cdecl ceill (long double);


  extern float __cdecl floorf (float);
  extern long double __cdecl floorl (long double);


  extern double __cdecl nearbyint ( double);
  extern float __cdecl nearbyintf (float);
  extern long double __cdecl nearbyintl (long double);



extern double __cdecl rint (double);
extern float __cdecl rintf (float);
extern long double __cdecl rintl (long double);


extern long __cdecl lrint (double);
extern long __cdecl lrintf (float);
extern long __cdecl lrintl (long double);

__extension__ long long __cdecl llrint (double);
__extension__ long long __cdecl llrintf (float);
__extension__ long long __cdecl llrintl (long double);
# 739 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern double __cdecl round (double);
  extern float __cdecl roundf (float);
  extern long double __cdecl roundl (long double);


  extern long __cdecl lround (double);
  extern long __cdecl lroundf (float);
  extern long __cdecl lroundl (long double);
  __extension__ long long __cdecl llround (double);
  __extension__ long long __cdecl llroundf (float);
  __extension__ long long __cdecl llroundl (long double);



  extern double __cdecl trunc (double);
  extern float __cdecl truncf (float);
  extern long double __cdecl truncl (long double);


  extern float __cdecl fmodf (float, float);
  extern long double __cdecl fmodl (long double, long double);


  extern double __cdecl remainder (double, double);
  extern float __cdecl remainderf (float, float);
  extern long double __cdecl remainderl (long double, long double);


  extern double __cdecl remquo(double, double, int *);
  extern float __cdecl remquof(float, float, int *);
  extern long double __cdecl remquol(long double, long double, int *);


  extern double __cdecl copysign (double, double);
  extern float __cdecl copysignf (float, float);
  extern long double __cdecl copysignl (long double, long double);


  extern double __cdecl nan(const char *tagp);
  extern float __cdecl nanf(const char *tagp);
  extern long double __cdecl nanl(const char *tagp);
# 788 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern double __cdecl nextafter (double, double);
  extern float __cdecl nextafterf (float, float);
  extern long double __cdecl nextafterl (long double, long double);


  extern double __cdecl nexttoward (double, long double);
  extern float __cdecl nexttowardf (float, long double);
  extern long double __cdecl nexttowardl (long double, long double);



  extern double __cdecl fdim (double x, double y);
  extern float __cdecl fdimf (float x, float y);
  extern long double __cdecl fdiml (long double x, long double y);







  extern double __cdecl fmax (double, double);
  extern float __cdecl fmaxf (float, float);
  extern long double __cdecl fmaxl (long double, long double);


  extern double __cdecl fmin (double, double);
  extern float __cdecl fminf (float, float);
  extern long double __cdecl fminl (long double, long double);



  extern double __cdecl fma (double, double, double);
  extern float __cdecl fmaf (float, float, float);
  extern long double __cdecl fmal (long double, long double, long double);
# 871 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
   __attribute__ ((__dllimport__)) float __cdecl _copysignf (float _Number,float _Sign);
   __attribute__ ((__dllimport__)) float __cdecl _chgsignf (float _X);
   __attribute__ ((__dllimport__)) float __cdecl _logbf(float _X);
   __attribute__ ((__dllimport__)) float __cdecl _nextafterf(float _X,float _Y);
   __attribute__ ((__dllimport__)) int __cdecl _finitef(float _X);
   __attribute__ ((__dllimport__)) int __cdecl _isnanf(float _X);
   __attribute__ ((__dllimport__)) int __cdecl _fpclassf(float _X);



   extern long double __cdecl _chgsignl (long double);
# 898 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
#pragma pack(pop)
# 2 "C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_1/forw_back_LTL.c" 2
# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3








# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 9 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 36 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 3
  __attribute__ ((__dllimport__)) void *__cdecl _memccpy(void *_Dst,const void *_Src,int _Val,size_t _MaxCount);
                void *__cdecl memchr(const void *_Buf ,int _Val,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  __attribute__ ((__dllimport__)) int __cdecl _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  int __cdecl memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void *__cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size) ;
  void *__cdecl memset(void *_Dst,int _Val,size_t _Size);

  void *__cdecl memccpy(void *_Dst,const void *_Src,int _Val,size_t _Size) ;
  int __cdecl memicmp(const void *_Buf1,const void *_Buf2,size_t _Size) ;


  char *__cdecl _strset(char *_Str,int _Val) ;
  char *__cdecl _strset_l(char *_Str,int _Val,_locale_t _Locale) ;
  char *__cdecl strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
  char *__cdecl strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
  int __cdecl strcmp(const char *_Str1,const char *_Str2);
  size_t __cdecl strlen(const char *_Str);
  size_t __cdecl strnlen(const char *_Str,size_t _MaxCount);
  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strdup(const char *_Src);
                char *__cdecl strchr(const char *_Str,int _Val);
  __attribute__ ((__dllimport__)) int __cdecl _stricmp(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _strcmpi(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _stricmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  int __cdecl strcoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _strcoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _stricoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _stricoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _strncoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _strnicoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(const char *_Str,const char *_Control);
  __attribute__ ((__dllimport__)) char *__cdecl _strerror(const char *_ErrMsg) ;
  char *__cdecl strerror(int) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strlwr(char *_String) ;
  char *strlwr_l(char *_String,_locale_t _Locale) ;
  char *__cdecl strncat(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  int __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strnset(char *_Str,int _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strnset_l(char *str,int c,size_t count,_locale_t _Locale) ;
                char *__cdecl strpbrk(const char *_Str,const char *_Control);
                char *__cdecl strrchr(const char *_Str,int _Ch);
  __attribute__ ((__dllimport__)) char *__cdecl _strrev(char *_Str);
  size_t __cdecl strspn(const char *_Str,const char *_Control);
                char *__cdecl strstr(const char *_Str,const char *_SubStr);
  char *__cdecl strtok(char * __restrict__ _Str,const char * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strupr(char *_String) ;
  __attribute__ ((__dllimport__)) char *_strupr_l(char *_String,_locale_t _Locale) ;
  size_t __cdecl strxfrm(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __cdecl _strxfrm_l(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);


  char *__cdecl strdup(const char *_Src) ;
  int __cdecl strcmpi(const char *_Str1,const char *_Str2) ;
  int __cdecl stricmp(const char *_Str1,const char *_Str2) ;
  char *__cdecl strlwr(char *_Str) ;
  int __cdecl strnicmp(const char *_Str1,const char *_Str,size_t _MaxCount) ;
  int __cdecl strncasecmp (const char *, const char *, size_t);
  int __cdecl strcasecmp (const char *, const char *);







  char *__cdecl strnset(char *_Str,int _Val,size_t _MaxCount) ;
  char *__cdecl strrev(char *_Str) ;
  char *__cdecl strset(char *_Str,int _Val) ;
  char *__cdecl strupr(char *_Str) ;





  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
                wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  int __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  int __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  wchar_t *__cdecl _wcsncpy_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count,_locale_t _Locale) ;
                wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcserror(int _ErrNum) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl __wcserror(const wchar_t *_Str) ;
  __attribute__ ((__dllimport__)) int __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcslwr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsupr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale) ;
  size_t __cdecl wcsxfrm(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __cdecl _wcsxfrm_l(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);
  int __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);


  wchar_t *__cdecl wcsdup(const wchar_t *_Str) ;

  int __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2) ;
  int __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount) ;
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  wchar_t *__cdecl wcsrev(wchar_t *_Str) ;
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val) ;
  wchar_t *__cdecl wcslwr(wchar_t *_Str) ;
  wchar_t *__cdecl wcsupr(wchar_t *_Str) ;
  int __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2) ;








# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 1 3








# 1 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3
# 9 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 2 3
# 175 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 3 "C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_1/forw_back_LTL.c" 2


static float conv_kernel_1[3][3];
static float conv_kernel_2[3][3];
static float conv_kernel_3[3][3];
static float fc_hidden_layer1[576][180];
static float fc_hidden_layer2[180][45];
static float fc_hidden_layer3[45][10];


static float mnist_data[30][30];
static float conv_out_1[28][28];
static float conv_out_2[26][26];
static float conv_out_3[24][24];
static float fc_in_1[1][576];
static float fc_out_1[1][180];
static float fc_in_2_relu1[1][180];
static float fc_out_2[1][45];
static float fc_in_3_relu2[1][45];
static float fc_out_3[1][10];
static float probability_result[10];

float max(float a, float b) {
 return (a > b)? a : b;
}


void Conv2d(int w,int h,int k,float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<w-k+1;i++)
        for(int j=0;j<h-k+1;j++){
            out_matrix[i*(h-k+1)+j]=0;
            Conv2d_label0:for(int col=i;col<i+3;col++)
                for(int row=j;row<j+3;row++)
                    out_matrix[i*(h-k+1)+j]+=input_matrix[col*h+row]*kernel[(col-i)*k+(row-j)];
        }
}

void MatrixExtensionImproved(int w,int h,float *input_matrix1,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*h+j]=input_matrix1[i*h+j];
}

void MatrixMultiply(int h,int h_out,float *input_matrix,float *para_layer,float*output_matrix){
    for(int j=0;j<h_out;j++){
        output_matrix[j]=0;
        for(int i=0;i<h;i++)
            output_matrix[j]+=input_matrix[i]*para_layer[i*h_out+j];
    }
}

void Relu(int h,float *input_matrix,float *output_matrix){
    for(int j=0;j<h;j++)
        output_matrix[j]=max(input_matrix[j],input_matrix[j]*0.05);
}


void MatrixBackPropagationMultiply(int w,int h,float *input_matrix,float *grad,float *rgrad){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            rgrad[i*h+j]=input_matrix[i]*grad[j];
}

void CalculateMatrixGrad(int w,int h,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++){
        output_matrix[i]=0;
        for(int j=0;j<h;j++)
            output_matrix[i]+=input_matrix[i*h+j]*grad[j];
    }
}

void ReluBackPropagation(int w,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++)
        if(input_matrix[i]>0)
            output_matrix[i]=1*grad[i];
        else
            output_matrix[i]=0.05*grad[i];
}

void OverturnKernel(int k,float *input_matrix,float *output_matrix){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            output_matrix[(k-1-i)*k+(k-1-j)]=input_matrix[i*k+j];
}

void Padding(int w,int stride,float *input_matrix,float *output_matrix){
    for(int i=0;i<w+2*stride;i++)
        for(int j=0;j<w+2*stride;j++){
            if((i>=stride)&&(j>=stride)&&(i<stride+w)&&(j<stride+w))
                output_matrix[i*(w+2*stride)+j]=input_matrix[(i-stride)*w+(j-stride)];
            else
                output_matrix[i*(w+2*stride)+j]=0;
        }
}

void MatrixBackPropagation(int w,int h,float *input_matrix,float *output_matrix,float lr){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*h+j]-=lr*input_matrix[i*h+j];
}


void forward(){
    Conv2d(30,30,3,mnist_data,conv_kernel_1,conv_out_1);
    Conv2d(28,28,3,conv_out_1,conv_kernel_2,conv_out_2);
    Conv2d(26,26,3,conv_out_2,conv_kernel_3,conv_out_3);

    MatrixExtensionImproved(24,24,conv_out_3,fc_in_1);
    MatrixMultiply(576,180,fc_in_1,fc_hidden_layer1,fc_out_1);
    Relu(180,fc_out_1,fc_in_2_relu1);
    MatrixMultiply(180,45,fc_in_2_relu1,fc_hidden_layer2,fc_out_2);
    Relu(45,fc_out_2,fc_in_3_relu2);
    MatrixMultiply(45,10,fc_in_3_relu2,fc_hidden_layer3,fc_out_3);

    float probability_sum=0;
    for(int i=0;i<10;i++){
        probability_sum+=exp(fc_out_3[0][i]);
    }
    for(int j=0;j<10;j++){
        probability_result[j]=exp(fc_out_3[0][j])/probability_sum;
    }
    return;
}

void backward(int label,float* lr_in){
    float grad_3[10];
    for(int i=0;i<10;i++)
        if(i==label) grad_3[i]=probability_result[i]-1;
        else grad_3[i]=probability_result[i]-0;

    float wgrad_3[450];
    MatrixBackPropagationMultiply(45,10,fc_in_3_relu2,grad_3,wgrad_3);

    float rgrad_2[45];
    CalculateMatrixGrad(45,10,fc_hidden_layer3,grad_3,rgrad_2);
    float grad_2[180];
    ReluBackPropagation(45,fc_out_2,rgrad_2,grad_2);
    float wgrad_2[8100];
    MatrixBackPropagationMultiply(180,45,fc_in_2_relu1,grad_2,wgrad_2);

    float rgrad_1[180];
    CalculateMatrixGrad(180,45,fc_hidden_layer2,grad_2,rgrad_1);
    float grad_1[180];
    ReluBackPropagation(180,fc_out_1,rgrad_1,grad_1);
    float wgrad_1[103680];
    MatrixBackPropagationMultiply(576,180,fc_in_1,grad_1,wgrad_1);

    float grad_0[576];
    CalculateMatrixGrad(576,180,fc_hidden_layer1,grad_1,grad_0);

    float *conv_grad_3=grad_0;
    float kernel_grad_3[9];
    Conv2d(26,26,24,conv_out_2,conv_grad_3,kernel_grad_3);
    float conv_grad_2[676];
    float kernel_grad_3_overturn[9];
    OverturnKernel(3,conv_kernel_3,kernel_grad_3_overturn);
    float conv_grad_3_padding[784];
    Padding(24,2,conv_grad_3,conv_grad_3_padding);
    Conv2d(28,28,3,conv_grad_3_padding,kernel_grad_3_overturn,conv_grad_2);

    float kernel_grad_2[9];
    Conv2d(28,28,26,conv_out_1,conv_grad_2,kernel_grad_2);
    float conv_grad_1[784];
    float kernel_grad_2_overturn[9];
    OverturnKernel(3,conv_kernel_2,kernel_grad_2_overturn);
    float conv_grad_2_padding[900];
    Padding(26,2,conv_grad_2,conv_grad_2_padding);
    Conv2d(30,30,3,conv_grad_2_padding,kernel_grad_2_overturn,conv_grad_1);

    float kernel_grad_1[9];
    Conv2d(30,30,28,mnist_data,conv_grad_1,kernel_grad_1);

    MatrixBackPropagation(3,3,kernel_grad_1,conv_kernel_1,(*lr_in));
    MatrixBackPropagation(3,3,kernel_grad_2,conv_kernel_2,(*lr_in));
    MatrixBackPropagation(3,3,kernel_grad_3,conv_kernel_3,(*lr_in));

    MatrixBackPropagation(576,180,wgrad_1,fc_hidden_layer1,(*lr_in));
    MatrixBackPropagation(180,45,wgrad_2,fc_hidden_layer2,(*lr_in));
    MatrixBackPropagation(45,10,wgrad_3,fc_hidden_layer3,(*lr_in));
    return;
}

void forw_back(int flag, float *in, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3, float *out, int label, float* lr) {

#pragma HLS INTERFACE s_axilite port=flag bundle=ctrl
#pragma HLS INTERFACE s_axilite port=label bundle=ctrl
#pragma HLS INTERFACE s_axilite port=in bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv1 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv2 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv3 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=out bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc1 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc2 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc3 bundle=ctrl
#pragma HLS INTERFACE m_axi depth=32 port=in bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv1 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv2 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv3 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=out bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc1 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc2 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc3 bundle=data
#pragma HLS INTERFACE s_axilite port=return bundle=ctrl

 memcpy(mnist_data, in, sizeof(float) * 30 * 30);
    memcpy(conv_kernel_1, conv1, sizeof(float) * 9);
    memcpy(conv_kernel_2, conv2, sizeof(float) * 9);
    memcpy(conv_kernel_3, conv3, sizeof(float) * 9);
    memcpy(fc_hidden_layer1, fc1, sizeof(float) * 576 * 180);
    memcpy(fc_hidden_layer2, fc2, sizeof(float) * 180 * 45);
    memcpy(fc_hidden_layer3, fc3, sizeof(float) * 45 * 10);

 if(flag == 0) {
        forward();
        memcpy(out, probability_result, sizeof(float) * 10);
    }
    else {
     forward();
     float probability = 0;
        backward(label, lr);
        memcpy(out, probability_result, sizeof(float) * 10);

        memcpy(conv1, conv_kernel_1, sizeof(float) * 9);
        memcpy(conv2, conv_kernel_2, sizeof(float) * 9);
        memcpy(conv3, conv_kernel_3, sizeof(float) * 9);
        memcpy(fc1, fc_hidden_layer1, sizeof(float) * 103680);
        memcpy(fc2, fc_hidden_layer2, sizeof(float) * 8100);
        memcpy(fc3, fc_hidden_layer3, sizeof(float) * 450);
    }
}
