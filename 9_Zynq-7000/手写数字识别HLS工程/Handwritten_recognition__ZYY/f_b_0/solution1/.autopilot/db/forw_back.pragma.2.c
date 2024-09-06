# 1 "f_b_0/forw_back.c"
# 1 "f_b_0/forw_back.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1






# 1 "D:/Xilinx/Vivado/2019.1/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
# 305 "D:/Xilinx/Vivado/2019.1/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_op_SpecStable() __attribute__ ((nothrow));
    void _ssdm_op_SpecStableContent() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipoDepth() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 8 "<command line>" 2
# 1 "<built-in>" 2
# 1 "f_b_0/forw_back.c" 2
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
  void __mingw_setusermatherr (int ( *)(struct _exception *));
  __attribute__ ((__dllimport__)) void __setusermatherr(int ( *)(struct _exception *));



  double sin(double _X);
  double cos(double _X);
  double tan(double _X);
  double sinh(double _X);
  double cosh(double _X);
  double tanh(double _X);
  double asin(double _X);
  double acos(double _X);
  double atan(double _X);
  double atan2(double _Y,double _X);
  double exp(double _X);
  double log(double _X);
  double log10(double _X);
  double pow(double _X,double _Y);
  double sqrt(double _X);
  double ceil(double _X);
  double floor(double _X);
  double fabs(double _X);
# 135 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  double ldexp(double _X,int _Y);
  double frexp(double _X,int *_Y);
  double modf(double _X,double *_Y);
  double fmod(double _X,double _Y);

  void sincos (double __x, double *p_sin, double *p_cos);
  void sincosl (long double __x, long double *p_sin, long double *p_cos);
  void sincosf (float __x, float *p_sin, float *p_cos);



  int abs(int _X);
  long labs(long _X);



  double atof(const char *_String);
  double _atof_l(const char *_String,_locale_t _Locale);
# 162 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  struct _complex {
    double x;
    double y;
  };


  __attribute__ ((__dllimport__)) double _cabs(struct _complex _ComplexA);
  double _hypot(double _X,double _Y);
  __attribute__ ((__dllimport__)) double _j0(double _X);
  __attribute__ ((__dllimport__)) double _j1(double _X);
  __attribute__ ((__dllimport__)) double _jn(int _X,double _Y);
  __attribute__ ((__dllimport__)) double _y0(double _X);
  __attribute__ ((__dllimport__)) double _y1(double _X);
  __attribute__ ((__dllimport__)) double _yn(int _X,double _Y);


  __attribute__ ((__dllimport__)) int _matherr (struct _exception *);
# 189 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  __attribute__ ((__dllimport__)) double _chgsign (double _X);
  __attribute__ ((__dllimport__)) double _copysign (double _Number,double _Sign);
  __attribute__ ((__dllimport__)) double _logb (double);
  __attribute__ ((__dllimport__)) double _nextafter (double, double);
  __attribute__ ((__dllimport__)) double _scalb (double, long);
  __attribute__ ((__dllimport__)) int _finite (double);
  __attribute__ ((__dllimport__)) int _fpclass (double);
  __attribute__ ((__dllimport__)) int _isnan (double);






__attribute__ ((__dllimport__)) double j0 (double) ;
__attribute__ ((__dllimport__)) double j1 (double) ;
__attribute__ ((__dllimport__)) double jn (int, double) ;
__attribute__ ((__dllimport__)) double y0 (double) ;
__attribute__ ((__dllimport__)) double y1 (double) ;
__attribute__ ((__dllimport__)) double yn (int, double) ;

__attribute__ ((__dllimport__)) double chgsign (double);
# 219 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  __attribute__ ((__dllimport__)) int finite (double);
  __attribute__ ((__dllimport__)) int fpclass (double);
# 264 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
typedef float float_t;
typedef double double_t;
# 299 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern int __fpclassifyl (long double);
  extern int __fpclassifyf (float);
  extern int __fpclassify (double);
# 335 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern int __isnan (double);
  extern int __isnanf (float);
  extern int __isnanl (long double);
# 376 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern int __signbit (double);
  extern int __signbitf (float);
  extern int __signbitl (long double);
# 404 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern float sinf(float _X);
  extern long double sinl(long double);

  extern float cosf(float _X);
  extern long double cosl(long double);

  extern float tanf(float _X);
  extern long double tanl(long double);
  extern float asinf(float _X);
  extern long double asinl(long double);

  extern float acosf (float);
  extern long double acosl (long double);

  extern float atanf (float);
  extern long double atanl (long double);

  extern float atan2f (float, float);
  extern long double atan2l (long double, long double);


  extern float sinhf(float _X);



  extern long double sinhl(long double);

  extern float coshf(float _X);



  extern long double coshl(long double);

  extern float tanhf(float _X);



  extern long double tanhl(long double);



  extern double acosh (double);
  extern float acoshf (float);
  extern long double acoshl (long double);


  extern double asinh (double);
  extern float asinhf (float);
  extern long double asinhl (long double);


  extern double atanh (double);
  extern float atanhf (float);
  extern long double atanhl (long double);



  extern float expf(float _X);



  extern long double expl(long double);


  extern double exp2(double);
  extern float exp2f(float);
  extern long double exp2l(long double);



  extern double expm1(double);
  extern float expm1f(float);
  extern long double expm1l(long double);


  extern float frexpf(float _X,int *_Y);



  extern long double frexpl(long double,int *);




  extern int ilogb (double);
  extern int ilogbf (float);
  extern int ilogbl (long double);


  extern float ldexpf(float _X,int _Y);



  extern long double ldexpl (long double, int);


  extern float logf (float);
  extern long double logl(long double);


  extern float log10f (float);
  extern long double log10l(long double);


  extern double log1p(double);
  extern float log1pf(float);
  extern long double log1pl(long double);


  extern double log2 (double);
  extern float log2f (float);
  extern long double log2l (long double);


  extern double logb (double);
  extern float logbf (float);
  extern long double logbl (long double);
# 553 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern float modff (float, float*);
  extern long double modfl (long double, long double*);


  extern double scalbn (double, int);
  extern float scalbnf (float, int);
  extern long double scalbnl (long double, int);

  extern double scalbln (double, long);
  extern float scalblnf (float, long);
  extern long double scalblnl (long double, long);



  extern double cbrt (double);
  extern float cbrtf (float);
  extern long double cbrtl (long double);


  extern float fabsf (float x);
# 583 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern long double fabsl (long double);
# 595 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern double hypot (double, double) ;
  extern float hypotf (float x, float y);



  extern long double hypotl (long double, long double);


  extern float powf(float _X,float _Y);



  extern long double powl (long double, long double);


  extern float sqrtf (float);
  extern long double sqrtl(long double);


  extern double erf (double);
  extern float erff (float);
  extern long double erfl (long double);


  extern double erfc (double);
  extern float erfcf (float);
  extern long double erfcl (long double);


  extern double lgamma (double);
  extern float lgammaf (float);
  extern long double lgammal (long double);


  extern double tgamma (double);
  extern float tgammaf (float);
  extern long double tgammal (long double);


  extern float ceilf (float);
  extern long double ceill (long double);


  extern float floorf (float);
  extern long double floorl (long double);


  extern double nearbyint ( double);
  extern float nearbyintf (float);
  extern long double nearbyintl (long double);



extern double rint (double);
extern float rintf (float);
extern long double rintl (long double);


extern long lrint (double);
extern long lrintf (float);
extern long lrintl (long double);

__extension__ long long llrint (double);
__extension__ long long llrintf (float);
__extension__ long long llrintl (long double);
# 739 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern double round (double);
  extern float roundf (float);
  extern long double roundl (long double);


  extern long lround (double);
  extern long lroundf (float);
  extern long lroundl (long double);
  __extension__ long long llround (double);
  __extension__ long long llroundf (float);
  __extension__ long long llroundl (long double);



  extern double trunc (double);
  extern float truncf (float);
  extern long double truncl (long double);


  extern float fmodf (float, float);
  extern long double fmodl (long double, long double);


  extern double remainder (double, double);
  extern float remainderf (float, float);
  extern long double remainderl (long double, long double);


  extern double remquo(double, double, int *);
  extern float remquof(float, float, int *);
  extern long double remquol(long double, long double, int *);


  extern double copysign (double, double);
  extern float copysignf (float, float);
  extern long double copysignl (long double, long double);


  extern double nan(const char *tagp);
  extern float nanf(const char *tagp);
  extern long double nanl(const char *tagp);
# 788 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
  extern double nextafter (double, double);
  extern float nextafterf (float, float);
  extern long double nextafterl (long double, long double);


  extern double nexttoward (double, long double);
  extern float nexttowardf (float, long double);
  extern long double nexttowardl (long double, long double);



  extern double fdim (double x, double y);
  extern float fdimf (float x, float y);
  extern long double fdiml (long double x, long double y);







  extern double fmax (double, double);
  extern float fmaxf (float, float);
  extern long double fmaxl (long double, long double);


  extern double fmin (double, double);
  extern float fminf (float, float);
  extern long double fminl (long double, long double);



  extern double fma (double, double, double);
  extern float fmaf (float, float, float);
  extern long double fmal (long double, long double, long double);
# 871 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
   __attribute__ ((__dllimport__)) float _copysignf (float _Number,float _Sign);
   __attribute__ ((__dllimport__)) float _chgsignf (float _X);
   __attribute__ ((__dllimport__)) float _logbf(float _X);
   __attribute__ ((__dllimport__)) float _nextafterf(float _X,float _Y);
   __attribute__ ((__dllimport__)) int _finitef(float _X);
   __attribute__ ((__dllimport__)) int _isnanf(float _X);
   __attribute__ ((__dllimport__)) int _fpclassf(float _X);



   extern long double _chgsignl (long double);
# 898 "D:/Xilinx/Vivado/2019.1/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
#pragma pack(pop)
# 2 "f_b_0/forw_back.c" 2

static float conv_kernel1[3][3] = {0};

static float conv_kernel2[3][3] = {0};

static float conv_kernel3[3][3] = {0};

static float fc_hidden_layer1[576][180] = {0};
static float fc_hidden_layer2[180][45] = {0};
static float fc_hidden_layer3[45][10] = {0};


static float mnist_data[30][30] = {0};
static float first_conv1[28][28] = {0};
static float sencond_conv1[26][26] = {0};
static float third_conv1[24][24] = {0};
static float flatten_conv[1][576] = {0};
static float first_fc[1][180] = {0};
static float first_relu[1][180] = {0};
static float second_fc[1][45] = {0};
static float second_relu[1][45] = {0};
static float outmlp[1][10] = {0};
static float result[10] = {0};
static float out_grad[10] = {0};

float max(float a, float b) {
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 27 "f_b_0/forw_back.c"

 return (a > b)? a : b;
}

void Conv2d1(int ershiba,float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 31 "f_b_0/forw_back.c"

    for(int i=0;i<28;i++)
        for(int j=0;j<28;j++){
            out_matrix[i*28+j]=0;
            Conv2d1_label0:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 35 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*ershiba+j]+=input_matrix[row*30+col]*kernel[(row-i)*3+(col-j)];
        }
}

void Conv2d2(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 41 "f_b_0/forw_back.c"

    for(int i=0;i<28-3+1;i++)
        for(int j=0;j<28-3+1;j++){
            out_matrix[i*(28-3+1)+j]=0;
            Conv2d2_label1:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 45 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(28-3+1)+j]+=input_matrix[row*28+col]*kernel[(row-i)*3+(col-j)];
        }
}

void Conv2d3(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 51 "f_b_0/forw_back.c"

    for(int i=0;i<26-3+1;i++)
        for(int j=0;j<26-3+1;j++){
            out_matrix[i*(26-3+1)+j]=0;
            Conv2d3_label2:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 55 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(26-3+1)+j]+=input_matrix[row*26+col]*kernel[(row-i)*3+(col-j)];
        }
}

void Relu1(float *input_matrix,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 61 "f_b_0/forw_back.c"

    Relu1_label0:for(int j=0;j<180;j++)
        output_matrix[j]=max(input_matrix[j],input_matrix[j]*0.05);
}

void Relu2(float *input_matrix,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 66 "f_b_0/forw_back.c"

    Relu2_label1:for(int j=0;j<45;j++)
        output_matrix[j]=max(input_matrix[j],input_matrix[j]*0.05);
}

void MatrixExtensionImproved(float *input_matrix1,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 71 "f_b_0/forw_back.c"

    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++) {
            output_matrix[i*24+j]=input_matrix1[i*24+j];
        }
}

void MatrixMultiply1(float *input_matrix,float *para_layer,float*output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 78 "f_b_0/forw_back.c"

    for(int j=0;j<180;j++){
        output_matrix[j]=0;
        for(int k=0;k<576;k++)
            output_matrix[j]+=input_matrix[k]*para_layer[k*180+j];
    }
}

void MatrixMultiply2(float *input_matrix,float *para_layer,float*output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 86 "f_b_0/forw_back.c"

    for(int j=0;j<45;j++){
        output_matrix[j]=0;
        for(int k=0;k<180;k++)
            output_matrix[j]+=input_matrix[k]*para_layer[k*45+j];
    }
}

void MatrixMultiply3(float *input_matrix,float *para_layer,float*output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 94 "f_b_0/forw_back.c"

    for(int j=0;j<10;j++){
        output_matrix[j]=0;
        for(int k=0;k<45;k++)
            output_matrix[j]+=input_matrix[k]*para_layer[k*10+j];
    }
}
void Conv2d_b1(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 101 "f_b_0/forw_back.c"

    for(int i=0;i<26-24+1;i++)
        for(int j=0;j<26-24+1;j++){
            out_matrix[i*(26-24+1)+j]=0;
            Conv2d_b1_label4:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 105 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(26-24+1)+j]+=input_matrix[row*26+col]*kernel[(row-i)*24+(col-j)];
        }
}
void Conv2d_b2(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 110 "f_b_0/forw_back.c"

    for(int i=0;i<28-3+1;i++)
        for(int j=0;j<28-3+1;j++){
            out_matrix[i*(28-3+1)+j]=0;
            Conv2d_b2_label5:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 114 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(28-3+1)+j]+=input_matrix[row*28+col]*kernel[(row-i)*3+(col-j)];
        }
}
void Conv2d_b3(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 119 "f_b_0/forw_back.c"

    for(int i=0;i<28-26+1;i++)
        for(int j=0;j<28-26+1;j++){
            out_matrix[i*(28-26+1)+j]=0;
            Conv2d_b3_label6:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 123 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(28-26+1)+j]+=input_matrix[row*28+col]*kernel[(row-i)*26+(col-j)];
        }
}
void Conv2d_b4(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 128 "f_b_0/forw_back.c"

    for(int i=0;i<30-3+1;i++)
        for(int j=0;j<30-3+1;j++){
            out_matrix[i*(30-3+1)+j]=0;
            Conv2d_b4_label7:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 132 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(30-3+1)+j]+=input_matrix[row*30+col]*kernel[(row-i)*3+(col-j)];
        }
}
void Conv2d_b5(float *input_matrix,float *kernel,float *out_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 137 "f_b_0/forw_back.c"

    for(int i=0;i<30-28+1;i++)
        for(int j=0;j<30-28+1;j++){
            out_matrix[i*(30-28+1)+j]=0;
            Conv2d_b5_label8:for(int row=i;row<i+3;row++)
_ssdm_op_SpecPipeline(-1, 1, 1, 0, "");
# 141 "f_b_0/forw_back.c"

                for(int col=j;col<j+3;col++)
                    out_matrix[i*(30-28+1)+j]+=input_matrix[row*30+col]*kernel[(row-i)*28+(col-j)];
        }
}

void MatrixBackPropagationMultiply1(float *para,float *grad,float *rgrad){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 147 "f_b_0/forw_back.c"

    for(int i=0;i<45;i++)
        for(int j=0;j<10;j++)
            rgrad[i*10+j]=para[i]*grad[j];

}

void MatrixBackPropagationMultiply2(float *para,float *grad,float *rgrad){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 154 "f_b_0/forw_back.c"

    for(int i=0;i<180;i++)
        for(int j=0;j<45;j++)
            rgrad[i*45+j]=para[i]*grad[j];

}

void MatrixBackPropagationMultiply3(float *para,float *grad,float *rgrad){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 161 "f_b_0/forw_back.c"

    for(int i=0;i<576;i++)
        for(int j=0;j<180;j++)
            rgrad[i*180+j]=para[i]*grad[j];
}


void CalculateMatrixGrad1(float *input_matrix,float *grad,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 168 "f_b_0/forw_back.c"

    for(int i=0;i<45;i++){
        output_matrix[i]=0;
        for(int j=0;j<10;j++){
            output_matrix[i]+=input_matrix[i*10+j]*grad[j];
        }
    }
}
void CalculateMatrixGrad2(float *input_matrix,float *grad,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 176 "f_b_0/forw_back.c"

    for(int i=0;i<180;i++){
        output_matrix[i]=0;
        for(int j=0;j<45;j++){
            output_matrix[i]+=input_matrix[i*45+j]*grad[j];
        }
    }
}
void CalculateMatrixGrad3(float *input_matrix,float *grad,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 184 "f_b_0/forw_back.c"

    for(int i=0;i<576;i++){
        output_matrix[i]=0;
        for(int j=0;j<180;j++){
            output_matrix[i]+=input_matrix[i*180+j]*grad[j];
        }
    }
}

void ReluBackPropagation1(float *input_matrix,float *grad,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 193 "f_b_0/forw_back.c"

    for(int i=0;i<45;i++){
        if(input_matrix[i]>0) output_matrix[i]=1*grad[i];
        else output_matrix[i]=0.05*grad[i];
    }
}
void ReluBackPropagation2(float *input_matrix,float *grad,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 199 "f_b_0/forw_back.c"

    for(int i=0;i<180;i++){
        if(input_matrix[i]>0) output_matrix[i]=1*grad[i];
        else output_matrix[i]=0.05*grad[i];
    }
}

void Padding1(float *input_matrix,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 206 "f_b_0/forw_back.c"

    for(int i=0;i<26+2;i++)
        for(int j=0;j<26+2;j++)
            output_matrix[i*(26+2)+j]=0;
}
void Padding2(float *input_matrix,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 211 "f_b_0/forw_back.c"

    for(int i=0;i<24+2;i++)
        for(int j=0;j<24+2;j++)
            output_matrix[i*(24+2)+j]=0;
}

void OverturnKernel(float *input_matrix,float *output_matrix){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 217 "f_b_0/forw_back.c"

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            output_matrix[(3-1-i)*3+(3-1-j)]=input_matrix[i*3+j];
}

void MatrixSplit(float *input_matrix,float *splited_matrix1){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 223 "f_b_0/forw_back.c"

    for(int idx=0;idx<576;idx++){
        splited_matrix1[idx]=input_matrix[idx];
    }
}

void backward(int label, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3, float* lr_in){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 229 "f_b_0/forw_back.c"

    for(int i=0;i<10;i++) {
        if(i==label) out_grad[i]=result[i]-1;
        else out_grad[i]=result[i]-0;
    }

    float out_wgrad[450];
    MatrixBackPropagationMultiply1(second_relu,out_grad,out_wgrad);

    float second_rgrad[45];
    CalculateMatrixGrad1(fc_hidden_layer3,out_grad,second_rgrad);
    float second_grad[180];
    ReluBackPropagation1(second_fc,second_rgrad,second_grad);
    float second_wgrad[8100];
    MatrixBackPropagationMultiply2(first_relu,second_grad,second_wgrad);


    float first_rgrad[180];
    CalculateMatrixGrad2(fc_hidden_layer2,second_grad,first_rgrad);
    float first_grad[180];
    ReluBackPropagation2(first_fc,first_rgrad,first_grad);
    float first_wgrad[103680];
    MatrixBackPropagationMultiply3(flatten_conv,first_grad,first_wgrad);
    float third_conv_grad1[576];
    CalculateMatrixGrad3(fc_hidden_layer1,first_grad,third_conv_grad1);

    float third_kernel_grad[9];
    Conv2d_b1(sencond_conv1,third_conv_grad1,third_kernel_grad);
    float second_conv_grad1[676];
    float third_kernel_overturn[9];
    OverturnKernel(conv_kernel3,third_kernel_overturn);
    float third_conv_grad_padding1[784];
    Padding1(third_conv_grad1,third_conv_grad_padding1);
    Conv2d_b2(third_conv_grad_padding1,third_kernel_overturn,second_conv_grad1);
    float second_kernel_grad[9];
    Conv2d_b3(first_conv1,second_conv_grad1,second_kernel_grad);
    float first_conv_grad[784];
    float second_kernel_overturn[9];
    OverturnKernel(conv_kernel2,second_kernel_overturn);
    float second_conv_grad_padding1[900];
    Padding2(second_conv_grad1,second_conv_grad_padding1);
    Conv2d_b4(second_conv_grad_padding1,second_kernel_overturn,first_conv_grad);
    float first_kernel_grad[9];
    Conv2d_b5(mnist_data,first_conv_grad,first_kernel_grad);

    float lr[1];
    memcpy(lr, lr_in, sizeof(float));
    int m = 0;
    int n = 0;
    for(m = 0; m < 3; m++) {
     for(n = 0; n < 3; n++) {
      conv_kernel1[m][n] -= lr[0] * first_kernel_grad[m * 3 + n];
      conv_kernel2[m][n] -= lr[0] * second_kernel_grad[m * 3 + n];
      conv_kernel3[m][n] -= lr[0] * third_kernel_grad[m * 3 + n];
     }
    }
    for(m = 0; m < 576; m++) {
     for(n = 0; n < 180; n++) {
      fc_hidden_layer1[m][n] -= lr[0] * first_wgrad[m * 576 + n];
     }
    }
    for(m = 0; m < 180; m++) {
  for(n = 0; n < 45; n++) {
   fc_hidden_layer2[m][n] -= lr[0] * second_wgrad[m * 180 + n];
  }
 }
    for(m = 0; m < 45; m++) {
  for(n = 0; n < 10; n++) {
   fc_hidden_layer3[m][n] -= lr[0] * out_wgrad[m * 45 + n];
  }
 }
    memcpy(conv1, conv_kernel1, sizeof(float) * 9);
    memcpy(conv2, conv_kernel2, sizeof(float) * 9);
    memcpy(conv3, conv_kernel3, sizeof(float) * 9);
    memcpy(fc1, fc_hidden_layer1, sizeof(float) * 103680);
    memcpy(fc2, fc_hidden_layer2, sizeof(float) * 8100);
    memcpy(fc3, fc_hidden_layer3, sizeof(float) * 450);
}

void forward(float *input_matrix, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3){
_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 308 "f_b_0/forw_back.c"

 memcpy(mnist_data, input_matrix, sizeof(float) * 30 * 30);
    memcpy(conv_kernel1, conv1, sizeof(float) * 9);
    memcpy(conv_kernel2, conv2, sizeof(float) * 9);
    memcpy(conv_kernel3, conv3, sizeof(float) * 9);
    data1:{
  Conv2d1(28,mnist_data,conv_kernel1,first_conv1);
  Conv2d2(first_conv1,conv_kernel2,sencond_conv1);
  Conv2d3(sencond_conv1,conv_kernel3,third_conv1);
    }

    memcpy(fc_hidden_layer1, fc1, sizeof(float) * 576 * 180);
    memcpy(fc_hidden_layer2, fc2, sizeof(float) * 180 * 45);
    memcpy(fc_hidden_layer3, fc3, sizeof(float) * 45 * 10);
    MatrixExtensionImproved(third_conv1,flatten_conv);
    data2:{
     MatrixMultiply1(flatten_conv,fc_hidden_layer1,first_fc);
  Relu1(first_fc,first_relu);
  MatrixMultiply2(first_relu,fc_hidden_layer2,second_fc);
  Relu2(second_fc,second_relu);
  MatrixMultiply3(second_relu,fc_hidden_layer3,outmlp);
    }
}

void forw_back(int flag, float *in, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3, float *out, int label, float* lr) {
_ssdm_op_SpecInterface(lr, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
# 332 "f_b_0/forw_back.c"

_ssdm_op_SpecInterface(lr, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
# 332 "f_b_0/forw_back.c"

_ssdm_op_SpecResource(&fc_hidden_layer2, "", "RAM_2P_LUTRAM", "", -1, "", "", "", "", "");
# 332 "f_b_0/forw_back.c"


_ssdm_op_SpecInterface(flag, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(label, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(in, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(conv1, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(conv2, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(conv3, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(out, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(fc1, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(fc2, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(fc3, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(in, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(conv1, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(conv2, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(conv3, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(out, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(fc1, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(fc2, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(fc3, "m_axi", 0, 0, "", 0, 32, "data", "", "", 16, 16, 16, 16, "", "");
_ssdm_op_SpecInterface(0, "s_axilite", 0, 0, "", 0, 0, "ctrl", "", "", 0, 0, 0, 0, "", "");

 if(flag == 0) {
        forward(in, conv1, conv2, conv3, fc1, fc2, fc3);
        memcpy(out, outmlp, sizeof(float) * 10);
    }
    else {
     forward(in, conv1, conv2, conv3, fc1, fc2, fc3);
     float probability = 0;
     for(int j = 0; j < 10; j++) {
      probability += exp(outmlp[0][j]);
     }
     for(int i=0;i<10;i++){
   result[i]=exp(outmlp[0][i])/probability;
  }
     memcpy(out, result, sizeof(float) * 10);
        backward(label, conv1, conv2, conv3, fc1, fc2, fc3, lr);
    }
}
