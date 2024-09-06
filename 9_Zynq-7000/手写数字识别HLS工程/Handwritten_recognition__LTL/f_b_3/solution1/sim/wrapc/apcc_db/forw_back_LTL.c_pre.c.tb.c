/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
float max(float llvm_cbe_a, float llvm_cbe_b);
void Conv2d(signed int llvm_cbe_w, signed int llvm_cbe_h, signed int llvm_cbe_k, float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void MatrixExtensionImproved(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix1, float *llvm_cbe_output_matrix);
void MatrixMultiply(signed int llvm_cbe_h, signed int llvm_cbe_h_out, float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix);
void Relu(signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void MatrixBackPropagationMultiply(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_rgrad);
void CalculateMatrixGrad(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void ReluBackPropagation(signed int llvm_cbe_w, float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void OverturnKernel(signed int llvm_cbe_k, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void Padding(signed int llvm_cbe_w, signed int llvm_cbe_stride, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void MatrixBackPropagation(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix, float llvm_cbe_lr);
void forward(void);
void backward(signed int llvm_cbe_label, float *llvm_cbe_lr_in);
void forw_back(signed int llvm_cbe_flag, float *llvm_cbe_in, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3, float *llvm_cbe_out, signed int llvm_cbe_label, float *llvm_cbe_lr);


/* Global Variable Definitions and Initialization */
static float aesl_internal_mnist_data[30][30];
static float aesl_internal_conv_out_1[28][28];
static float aesl_internal_conv_kernel_2[3][3];
static float aesl_internal_conv_out_2[26][26];
static float aesl_internal_fc_in_2_relu1[1][180];
static float aesl_internal_conv_kernel_3[3][3];
static float aesl_internal_conv_out_3[24][24];
static float aesl_internal_fc_in_1[1][576];
static float aesl_internal_fc_hidden_layer1[576][180];
static float aesl_internal_fc_out_1[1][180];
static float aesl_internal_fc_hidden_layer2[180][45];
static float aesl_internal_fc_out_2[1][45];
static float aesl_internal_fc_in_3_relu2[1][45];
static float aesl_internal_conv_kernel_1[3][3];
static float aesl_internal_fc_hidden_layer3[45][10];
static float aesl_internal_fc_out_3[1][10];
static float aesl_internal_probability_result[10];


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

float max(float llvm_cbe_a, float llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  float llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @max\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = select i1 %%1, float %%a, float %%b, !dbg !16 for 0x%I64xth hint within @max  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__1 = (float )(((llvm_fcmp_ogt(llvm_cbe_a, llvm_cbe_b))) ? ((float )llvm_cbe_a) : ((float )llvm_cbe_b));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1, *(int*)(&llvm_cbe_tmp__1));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @max}\n");
  return llvm_cbe_tmp__1;
}


void Conv2d(signed int llvm_cbe_w, signed int llvm_cbe_h, signed int llvm_cbe_k, float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge17_2e_us;
  unsigned int llvm_cbe_storemerge17_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  float llvm_cbe_tmp__15;
  float llvm_cbe_tmp__15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge34_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge34_2e_us;
  unsigned int llvm_cbe_storemerge34_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  float *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  float llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  float *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  float llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  float llvm_cbe_tmp__27;
  float llvm_cbe_tmp__27__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge25_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge25_2e_us;
  unsigned int llvm_cbe_storemerge25_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge8_2e_us;
  unsigned int llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add i32 %%w, 1, !dbg !16 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_w&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sub i32 %%1, %%k, !dbg !16 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) - ((unsigned int )(llvm_cbe_k&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__3) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader6_2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__34;
  }

llvm_cbe__2e_preheader6_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sub nsw i32 %%h, %%k, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_h&4294967295ull)) - ((unsigned int )(llvm_cbe_k&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%4, 1, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_tmp__4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__5) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader6_2e_lr_2e_ph_2e_split_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge10;
  }

llvm_cbe__2e_preheader6_2e_lr_2e_ph_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i32 %%h, 1, !dbg !16 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_h&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sub i32 %%7, %%k, !dbg !16 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_tmp__6&4294967295ull)) - ((unsigned int )(llvm_cbe_k&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
  llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8.us = phi i32 [ 0, %%.preheader6.lr.ph.split.us ], [ %%10, %%9  for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_storemerge8_2e_us_count);
  llvm_cbe_storemerge8_2e_us = (unsigned int )llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8.us = 0x%X",llvm_cbe_storemerge8_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = mul nsw i32 %%storemerge8.us, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%storemerge8.us, 3, !dbg !18 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8_2e_us&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));
  llvm_cbe_storemerge17_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__35;

llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge8.us, 1, !dbg !18 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
  if (((llvm_cbe_tmp__8&4294967295U) == (llvm_cbe_tmp__3&4294967295U))) {
    goto llvm_cbe__2e__crit_edge10;
  } else {
    llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__8;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17.us = phi i32 [ 0, %%.lr.ph.us ], [ %%12, %%11  for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_storemerge17_2e_us_count);
  llvm_cbe_storemerge17_2e_us = (unsigned int )llvm_cbe_storemerge17_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17.us = 0x%X",llvm_cbe_storemerge17_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge17.us, %%40, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__32&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%14 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__11 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%out_matrix, i64 %%15, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__12 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_73_count);
  *llvm_cbe_tmp__12 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%storemerge17.us, 3, !dbg !19 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17_2e_us&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
  llvm_cbe_tmp__27__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge25_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8_2e_us;   /* for PHI node */
  goto llvm_cbe__2e_preheader_2e_us;

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge17.us, 1, !dbg !18 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
  if (((llvm_cbe_tmp__9&4294967295U) == (llvm_cbe_tmp__7&4294967295U))) {
    goto llvm_cbe_tmp__36;
  } else {
    llvm_cbe_storemerge17_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__9;   /* for PHI node */
    goto llvm_cbe_tmp__35;
  }

  do {     /* Syntactic loop '.preheader.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = phi float [ 0.000000e+00, %%13 ], [ %%32, %%18  for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__27 = (float )llvm_cbe_tmp__27__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__27);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25.us = phi i32 [ %%storemerge8.us, %%13 ], [ %%19, %%18  for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_storemerge25_2e_us_count);
  llvm_cbe_storemerge25_2e_us = (unsigned int )llvm_cbe_storemerge25_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25.us = 0x%X",llvm_cbe_storemerge25_2e_us);
printf("\nstoremerge8.us = 0x%X",llvm_cbe_storemerge8_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = mul nsw i32 %%storemerge25.us, %%h, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_h&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sub nsw i32 %%storemerge25.us, %%storemerge8.us, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25_2e_us&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge8_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = mul nsw i32 %%37, %%k, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_tmp__29&4294967295ull)) * ((unsigned int )(llvm_cbe_k&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = sub i32 %%38, %%storemerge17.us, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__30&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge17_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
  llvm_cbe_tmp__15__PHI_TEMPORARY = (float )llvm_cbe_tmp__27;   /* for PHI node */
  llvm_cbe_storemerge34_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge17_2e_us;   /* for PHI node */
  goto llvm_cbe_tmp__38;

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%storemerge25.us, 1, !dbg !19 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__14) < ((signed int )llvm_cbe_tmp__33))) {
    llvm_cbe_tmp__27__PHI_TEMPORARY = (float )llvm_cbe_tmp__25;   /* for PHI node */
    llvm_cbe_storemerge25_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__14;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_us;
  } else {
    goto llvm_cbe_tmp__37;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__38:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi float [ %%35, %%.preheader.us ], [ %%32, %%21 ], !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__15 = (float )llvm_cbe_tmp__15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__15);
printf("\n = %f",llvm_cbe_tmp__27);
printf("\n = %f",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34.us = phi i32 [ %%storemerge17.us, %%.preheader.us ], [ %%33, %%21  for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_storemerge34_2e_us_count);
  llvm_cbe_storemerge34_2e_us = (unsigned int )llvm_cbe_storemerge34_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34.us = 0x%X",llvm_cbe_storemerge34_2e_us);
printf("\nstoremerge17.us = 0x%X",llvm_cbe_storemerge17_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%storemerge34.us, %%36, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__28&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__17 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%input_matrix, i64 %%24, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__18 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__17))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__17));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__19 = (float )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__19, *(int*)(&llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i32 %%39, %%storemerge34.us, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_tmp__31&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge34_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%27 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__21 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds float* %%kernel, i64 %%28, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__22 = (float *)(&llvm_cbe_kernel[(((signed long long )llvm_cbe_tmp__21))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__21));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load float* %%29, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__23 = (float )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = fmul float %%26, %%30, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__24 = (float )((float )(llvm_cbe_tmp__19 * llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__24, *(int*)(&llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = fadd float %%22, %%31, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__25 = (float )((float )(llvm_cbe_tmp__15 + llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__25, *(int*)(&llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%32, float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_100_count);
  *llvm_cbe_tmp__12 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge34.us, 1, !dbg !19 for 0x%I64xth hint within @Conv2d  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__26) < ((signed int )llvm_cbe_tmp__13))) {
    llvm_cbe_tmp__15__PHI_TEMPORARY = (float )llvm_cbe_tmp__25;   /* for PHI node */
    llvm_cbe_storemerge34_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__26;   /* for PHI node */
    goto llvm_cbe_tmp__38;
  } else {
    goto llvm_cbe_tmp__39;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader.us' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge10:
  goto llvm_cbe_tmp__34;

llvm_cbe_tmp__34:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d}\n");
  return;
}


void MatrixExtensionImproved(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix1, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  float *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  float llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  float *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixExtensionImproved\n");
  if ((((signed int )llvm_cbe_w) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__48;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_h) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%4, %%3 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__40);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul nsw i32 %%storemerge3.us, %%h, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__47 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_h&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__47&4294967295ull)));
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge3.us, 1, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__40 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__40&4294967295ull)));
  if (((llvm_cbe_tmp__40&4294967295U) == (llvm_cbe_w&4294967295U))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%11, %%5  for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__46);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge12.us, %%12, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__47&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__42 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix1, i64 %%7, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__43 = (float *)(&llvm_cbe_input_matrix1[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__44 = (float )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__44, *(int*)(&llvm_cbe_tmp__44));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds float* %%output_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__45 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* %%10, align 4, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_163_count);
  *llvm_cbe_tmp__45 = llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%storemerge12.us, 1, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__46&4294967295ull)));
  if (((llvm_cbe_tmp__46&4294967295U) == (llvm_cbe_h&4294967295U))) {
    goto llvm_cbe_tmp__50;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__46;   /* for PHI node */
    goto llvm_cbe_tmp__49;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge4:
  goto llvm_cbe_tmp__48;

llvm_cbe_tmp__48:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixExtensionImproved}\n");
  return;
}


void MatrixMultiply(signed int llvm_cbe_h, signed int llvm_cbe_h_out, float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  float llvm_cbe_tmp__52;
  float llvm_cbe_tmp__52__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  float *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  float llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  float *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  float llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  float llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  float llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  float *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  float *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixMultiply\n");
  if ((((signed int )llvm_cbe_h_out) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe_tmp__69;
  }

llvm_cbe__2e_lr_2e_ph5:
  if ((((signed int )llvm_cbe_h) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__70;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%4, %%3 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__51);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sext i32 %%storemerge3.us to i64, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__64 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds float* %%output_matrix, i64 %%18, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__65 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__64))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__64));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%19, align 4, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_230_count);
  *llvm_cbe_tmp__65 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  llvm_cbe_tmp__52__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__71;

llvm_cbe_tmp__72:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge3.us, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));
  if (((llvm_cbe_tmp__51&4294967295U) == (llvm_cbe_h_out&4294967295U))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__51;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__71:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi float [ 0.000000e+00, %%.lr.ph.us ], [ %%16, %%5 ], !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__52 = (float )llvm_cbe_tmp__52__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__52);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%17, %%5  for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__63);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge12.us to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__53 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__54 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__53))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__53));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__55 = (float )*llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__55, *(int*)(&llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul nsw i32 %%storemerge12.us, %%h_out, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_h_out&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%10, %%storemerge3.us, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%11 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__58 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds float* %%para_layer, i64 %%12, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__59 = (float *)(&llvm_cbe_para_layer[(((signed long long )llvm_cbe_tmp__58))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__58));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* %%13, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__60 = (float )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__60, *(int*)(&llvm_cbe_tmp__60));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fmul float %%9, %%14, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__61 = (float )((float )(llvm_cbe_tmp__55 * llvm_cbe_tmp__60));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__61, *(int*)(&llvm_cbe_tmp__61));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fadd float %%6, %%15, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__62 = (float )((float )(llvm_cbe_tmp__52 + llvm_cbe_tmp__61));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__62, *(int*)(&llvm_cbe_tmp__62));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%16, float* %%19, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_220_count);
  *llvm_cbe_tmp__65 = llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%storemerge12.us, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__63&4294967295ull)));
  if (((llvm_cbe_tmp__63&4294967295U) == (llvm_cbe_h&4294967295U))) {
    goto llvm_cbe_tmp__72;
  } else {
    llvm_cbe_tmp__52__PHI_TEMPORARY = (float )llvm_cbe_tmp__62;   /* for PHI node */
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__63;   /* for PHI node */
    goto llvm_cbe_tmp__71;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__70:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%23, %%20 ], [ 0, %%.lr.ph5  for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__68);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__66 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds float* %%output_matrix, i64 %%21, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__67 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%22, align 4, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_239_count);
  *llvm_cbe_tmp__67 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__68&4294967295ull)));
  if (((llvm_cbe_tmp__68&4294967295U) == (llvm_cbe_h_out&4294967295U))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__68;   /* for PHI node */
    goto llvm_cbe_tmp__70;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge6:
  goto llvm_cbe_tmp__69;

llvm_cbe_tmp__69:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixMultiply}\n");
  return;
}


void Relu(signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  float *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  float llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  double llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  double llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  float llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  float llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  float *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Relu\n");
  if ((((signed int )llvm_cbe_h) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%10, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__81);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__73 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__74 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__73))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__73));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__75 = (float )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__75, *(int*)(&llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = fpext float %%4 to double, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__76 = (double )((double )llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__76, *(long long*)(&llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fmul double %%5, 5.000000e-02, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__77 = (double )llvm_cbe_tmp__76 * 0x1.999999999999ap-5;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__77, *(long long*)(&llvm_cbe_tmp__77));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fptrunc double %%6 to float, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__78 = (float )((float )llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__78, *(int*)(&llvm_cbe_tmp__78));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call float @max(float %%4, float %%7), !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__79 = (float ) /*tail*/ max(llvm_cbe_tmp__75, llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__75, *(int*)(&llvm_cbe_tmp__75));
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__78, *(int*)(&llvm_cbe_tmp__78));
printf("\nReturn  = %f",llvm_cbe_tmp__79);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__80 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__73))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__73));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_278_count);
  *llvm_cbe_tmp__80 = llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge1, 1, !dbg !17 for 0x%I64xth hint within @Relu  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__81&4294967295ull)));
  if (((llvm_cbe_tmp__81&4294967295U) == (llvm_cbe_h&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__81;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Relu}\n");
  return;
}


void MatrixBackPropagationMultiply(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_rgrad) {
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  float *llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  float llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  float *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  float llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  float llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  float *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixBackPropagationMultiply\n");
  if ((((signed int )llvm_cbe_w) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%16, %%._crit_edge  for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__94);
}
  if ((((signed int )llvm_cbe_h) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_333_count);
  llvm_cbe_tmp__94 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__94&4294967295ull)));
  if (((llvm_cbe_tmp__94&4294967295U) == (llvm_cbe_w&4294967295U))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__94;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__95:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.lr.ph ], [ %%15, %%6  for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__93);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__85 = (float )*llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__85, *(int*)(&llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__86 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%grad, i64 %%8, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__87 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__86))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__86));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__88 = (float )*llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__88, *(int*)(&llvm_cbe_tmp__88));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fmul float %%7, %%10, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_321_count);
  llvm_cbe_tmp__89 = (float )((float )(llvm_cbe_tmp__85 * llvm_cbe_tmp__88));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__89, *(int*)(&llvm_cbe_tmp__89));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge12, %%5, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__90 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__84&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__90&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__91 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds float* %%rgrad, i64 %%13, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__92 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__91))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%11, float* %%14, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_325_count);
  *llvm_cbe_tmp__92 = llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__93 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__93&4294967295ull)));
  if (((llvm_cbe_tmp__93&4294967295U) == (llvm_cbe_h&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__93;   /* for PHI node */
    goto llvm_cbe_tmp__95;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge3 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__82 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds float* %%input_matrix, i64 %%3, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__83 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__82))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__82));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul nsw i32 %%storemerge3, %%h, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__84 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(llvm_cbe_h&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__84&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__95;

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixBackPropagationMultiply}\n");
  return;
}


void CalculateMatrixGrad(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  float *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  float llvm_cbe_tmp__99;
  float llvm_cbe_tmp__99__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  float *llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  float llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  float *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  float llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  float llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  float llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @CalculateMatrixGrad\n");
  if ((((signed int )llvm_cbe_w) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

llvm_cbe__2e_lr_2e_ph5:
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__111;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__111:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%.lr.ph5 ], [ %%19, %%._crit_edge  for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__110);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__96 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%output_matrix, i64 %%4, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__97 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__96))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__96));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%5, align 4, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_365_count);
  *llvm_cbe_tmp__97 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  if ((((signed int )llvm_cbe_h) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__110 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__110&4294967295ull)));
  if (((llvm_cbe_tmp__110&4294967295U) == (llvm_cbe_w&4294967295U))) {
    goto llvm_cbe__2e__crit_edge6;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__110;   /* for PHI node */
    goto llvm_cbe_tmp__111;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__112:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%.lr.ph ], [ %%17, %%7 ], !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__99 = (float )llvm_cbe_tmp__99__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__99);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__108);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.lr.ph ], [ %%18, %%7  for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__109);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge12, %%6, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__100 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__98&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__100&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%9 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__101 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%input_matrix, i64 %%10, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__102 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__101))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__101));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__103 = (float )*llvm_cbe_tmp__102;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__103, *(int*)(&llvm_cbe_tmp__103));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__104 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds float* %%grad, i64 %%13, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__105 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__104))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__104));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* %%14, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__106 = (float )*llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__106, *(int*)(&llvm_cbe_tmp__106));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fmul float %%12, %%15, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__107 = (float )((float )(llvm_cbe_tmp__103 * llvm_cbe_tmp__106));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__107, *(int*)(&llvm_cbe_tmp__107));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fadd float %%8, %%16, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__108 = (float )((float )(llvm_cbe_tmp__99 + llvm_cbe_tmp__107));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__108, *(int*)(&llvm_cbe_tmp__108));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%17, float* %%5, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_384_count);
  *llvm_cbe_tmp__97 = llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__109 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__109&4294967295ull)));
  if (((llvm_cbe_tmp__109&4294967295U) == (llvm_cbe_h&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__99__PHI_TEMPORARY = (float )llvm_cbe_tmp__108;   /* for PHI node */
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__109;   /* for PHI node */
    goto llvm_cbe_tmp__112;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = mul nsw i32 %%storemerge3, %%h, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__98 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(llvm_cbe_h&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__98&4294967295ull)));
  llvm_cbe_tmp__99__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__112;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge6:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @CalculateMatrixGrad}\n");
  return;
}


void ReluBackPropagation(signed int llvm_cbe_w, float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  float *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  float llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  float *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  float llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  float *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  float *llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  float llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  double llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  double llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  float llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  float *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @ReluBackPropagation\n");
  if ((((signed int )llvm_cbe_w) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%18, %%17 ], [ 0, %%0  for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__125);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_421_count);
  llvm_cbe_tmp__113 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_422_count);
  llvm_cbe_tmp__114 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__115 = (float )*llvm_cbe_tmp__114;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__115, *(int*)(&llvm_cbe_tmp__115));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__115, 0x0p0))) {
    goto llvm_cbe_tmp__126;
  } else {
    goto llvm_cbe_tmp__127;
  }

llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__125 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__125&4294967295ull)));
  if (((llvm_cbe_tmp__125&4294967295U) == (llvm_cbe_w&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__125;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__126:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%grad, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_426_count);
  llvm_cbe_tmp__116 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_427_count);
  llvm_cbe_tmp__117 = (float )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__117, *(int*)(&llvm_cbe_tmp__117));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_428_count);
  llvm_cbe_tmp__118 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_429_count);
  *llvm_cbe_tmp__118 = llvm_cbe_tmp__117;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__117);
  goto llvm_cbe_tmp__128;

llvm_cbe_tmp__127:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%grad, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_431_count);
  llvm_cbe_tmp__119 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__120 = (float )*llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__120, *(int*)(&llvm_cbe_tmp__120));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fpext float %%12 to double, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_433_count);
  llvm_cbe_tmp__121 = (double )((double )llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__121, *(long long*)(&llvm_cbe_tmp__121));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul double %%13, 5.000000e-02, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__122 = (double )llvm_cbe_tmp__121 * 0x1.999999999999ap-5;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__122, *(long long*)(&llvm_cbe_tmp__122));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fptrunc double %%14 to float, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__123 = (float )((float )llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__123, *(int*)(&llvm_cbe_tmp__123));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__124 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__113))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__113));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation  --> \n", ++aesl_llvm_cbe_437_count);
  *llvm_cbe_tmp__124 = llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__123);
  goto llvm_cbe_tmp__128;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @ReluBackPropagation}\n");
  return;
}


void OverturnKernel(signed int llvm_cbe_k, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  unsigned int llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  unsigned int llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  unsigned int llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  unsigned int llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  unsigned int llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  float *llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  float llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned int llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  float *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  unsigned int llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @OverturnKernel\n");
  if ((((signed int )llvm_cbe_k) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%k, -1, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__129 = (unsigned int )((unsigned int )(llvm_cbe_k&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__129&4294967295ull)));
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph;

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%16, %%._crit_edge  for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__142);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul nsw i32 %%storemerge3, %%k, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_474_count);
  llvm_cbe_tmp__130 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(llvm_cbe_k&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__130&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sub nsw i32 %%2, %%storemerge3, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_475_count);
  llvm_cbe_tmp__131 = (unsigned int )((unsigned int )(llvm_cbe_tmp__129&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__131&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul nsw i32 %%4, %%k, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_476_count);
  llvm_cbe_tmp__132 = (unsigned int )((unsigned int )(llvm_cbe_tmp__131&4294967295ull)) * ((unsigned int )(llvm_cbe_k&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__132&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%5, %%2, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_477_count);
  llvm_cbe_tmp__133 = (unsigned int )((unsigned int )(llvm_cbe_tmp__132&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__129&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__133&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__143;

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge3, 1, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__142 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__142&4294967295ull)));
  if (((llvm_cbe_tmp__142&4294967295U) == (llvm_cbe_k&4294967295U))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__142;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__143:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.lr.ph ], [ %%15, %%7  for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__141);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge12, %%3, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_479_count);
  llvm_cbe_tmp__134 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__130&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__134&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sext i32 %%8 to i64, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_480_count);
  llvm_cbe_tmp__135 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds float* %%input_matrix, i64 %%9, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__136 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__135))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__135));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* %%10, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_482_count);
  llvm_cbe_tmp__137 = (float )*llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__137, *(int*)(&llvm_cbe_tmp__137));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%6, %%storemerge12, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__138 = (unsigned int )((unsigned int )(llvm_cbe_tmp__133&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__138&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__139 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds float* %%output_matrix, i64 %%13, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__140 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__139))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__139));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%11, float* %%14, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_486_count);
  *llvm_cbe_tmp__140 = llvm_cbe_tmp__137;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge12, 1, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_487_count);
  llvm_cbe_tmp__141 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__141&4294967295ull)));
  if (((llvm_cbe_tmp__141&4294967295U) == (llvm_cbe_k&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__141;   /* for PHI node */
    goto llvm_cbe_tmp__143;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @OverturnKernel}\n");
  return;
}


void Padding(signed int llvm_cbe_w, signed int llvm_cbe_stride, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned int llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  unsigned int llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  unsigned int llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  unsigned int llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  unsigned int llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  unsigned int llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  unsigned int llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  unsigned int llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge13_count = 0;
  unsigned int llvm_cbe_storemerge13;
  unsigned int llvm_cbe_storemerge13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond2_count = 0;
  bool llvm_cbe_or_2e_cond2;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  unsigned int llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  unsigned long long llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  float *llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  float llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned int llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  float *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  unsigned int llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  unsigned long long llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  float *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  unsigned int llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned int llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond6_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Padding\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl nsw i32 %%stride, 1, !dbg !16 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__144 = (unsigned int )llvm_cbe_stride << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%1, %%w, !dbg !16 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_535_count);
  llvm_cbe_tmp__145 = (unsigned int )((unsigned int )(llvm_cbe_tmp__144&4294967295ull)) + ((unsigned int )(llvm_cbe_w&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__145&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__145) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge5;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%stride, %%w, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_538_count);
  llvm_cbe_tmp__146 = (unsigned int )((unsigned int )(llvm_cbe_stride&4294967295ull)) + ((unsigned int )(llvm_cbe_w&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__146&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl i32 %%stride, 1, !dbg !16 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_539_count);
  llvm_cbe_tmp__147 = (unsigned int )llvm_cbe_stride << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%5, %%w, !dbg !16 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__148 = (unsigned int )((unsigned int )(llvm_cbe_tmp__147&4294967295ull)) + ((unsigned int )(llvm_cbe_w&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__148&4294967295ull)));
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph;

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 0, %%.preheader.lr.ph ], [ %%31, %%._crit_edge  for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__164);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul nsw i32 %%storemerge4, %%2, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__149 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__145&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__149&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%storemerge4, %%stride, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_552_count);
  llvm_cbe_tmp__150 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) - ((unsigned int )(llvm_cbe_stride&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__150&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, %%w, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_553_count);
  llvm_cbe_tmp__151 = (unsigned int )((unsigned int )(llvm_cbe_tmp__150&4294967295ull)) * ((unsigned int )(llvm_cbe_w&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__151&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%11, %%stride, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_554_count);
  llvm_cbe_tmp__152 = (unsigned int )((unsigned int )(llvm_cbe_tmp__151&4294967295ull)) - ((unsigned int )(llvm_cbe_stride&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__152&4294967295ull)));
  llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__165;

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge4, 1, !dbg !18 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__164 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__164&4294967295ull)));
  if (((llvm_cbe_tmp__164&4294967295U) == (llvm_cbe_tmp__148&4294967295U))) {
    goto llvm_cbe__2e__crit_edge5;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__164;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__165:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13 = phi i32 [ 0, %%.lr.ph ], [ %%30, %%29  for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_storemerge13_count);
  llvm_cbe_storemerge13 = (unsigned int )llvm_cbe_storemerge13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%X",llvm_cbe_storemerge13);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__163);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%7, %%14, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((signed int )llvm_cbe_storemerge4) < ((signed int )llvm_cbe_stride)) | (((signed int )llvm_cbe_storemerge13) < ((signed int )llvm_cbe_stride)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    goto llvm_cbe_tmp__166;
  } else {
    goto llvm_cbe_tmp__167;
  }

llvm_cbe_tmp__168:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add nsw i32 %%storemerge13, 1, !dbg !18 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__163 = (unsigned int )((unsigned int )(llvm_cbe_storemerge13&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__163&4294967295ull)));
  if (((llvm_cbe_tmp__163&4294967295U) == (llvm_cbe_tmp__148&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__163;   /* for PHI node */
    goto llvm_cbe_tmp__165;
  }

llvm_cbe_tmp__169:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%12, %%storemerge13, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__153 = (unsigned int )((unsigned int )(llvm_cbe_tmp__152&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge13&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__153&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%18 to i64, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__154 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds float* %%input_matrix, i64 %%19, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__155 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__154))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__154));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load float* %%20, align 4, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__156 = (float )*llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__156, *(int*)(&llvm_cbe_tmp__156));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge13, %%8, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__157 = (unsigned int )((unsigned int )(llvm_cbe_storemerge13&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__149&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__157&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%22 to i64, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_565_count);
  llvm_cbe_tmp__158 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%output_matrix, i64 %%23, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_566_count);
  llvm_cbe_tmp__159 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__158))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__158));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%24, align 4, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_567_count);
  *llvm_cbe_tmp__159 = llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__156);
  goto llvm_cbe_tmp__168;

llvm_cbe_tmp__167:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond2 = and i1 %%9, %%16, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_or_2e_cond2_count);
  llvm_cbe_or_2e_cond2 = (bool )(((((signed int )llvm_cbe_storemerge4) < ((signed int )llvm_cbe_tmp__146)) & (((signed int )llvm_cbe_storemerge13) < ((signed int )llvm_cbe_tmp__146)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond2 = 0x%X\n", llvm_cbe_or_2e_cond2);
  if (llvm_cbe_or_2e_cond2) {
    goto llvm_cbe_tmp__169;
  } else {
    goto llvm_cbe_tmp__166;
  }

llvm_cbe_tmp__166:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%storemerge13, %%8, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__160 = (unsigned int )((unsigned int )(llvm_cbe_storemerge13&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__149&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__160&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i32 %%26 to i64, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_570_count);
  llvm_cbe_tmp__161 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds float* %%output_matrix, i64 %%27, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__162 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__161))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__161));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%28, align 4, !dbg !17 for 0x%I64xth hint within @Padding  --> \n", ++aesl_llvm_cbe_572_count);
  *llvm_cbe_tmp__162 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  goto llvm_cbe_tmp__168;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge5:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Padding}\n");
  return;
}


void MatrixBackPropagation(signed int llvm_cbe_w, signed int llvm_cbe_h, float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix, float llvm_cbe_lr) {
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  unsigned int llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  unsigned int llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  float *llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  float llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  float llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  float *llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  float llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  float llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  unsigned int llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixBackPropagation\n");
  if ((((signed int )llvm_cbe_w) > ((signed int )0u))) {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  } else {
    goto llvm_cbe_tmp__181;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if ((((signed int )llvm_cbe_h) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%4, %%3 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__170);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul nsw i32 %%storemerge3.us, %%h, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_643_count);
  llvm_cbe_tmp__180 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_h&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__180&4294967295ull)));
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__182;

llvm_cbe_tmp__183:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge3.us, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_616_count);
  llvm_cbe_tmp__170 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__170&4294967295ull)));
  if (((llvm_cbe_tmp__170&4294967295U) == (llvm_cbe_w&4294967295U))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__170;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__182:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%14, %%5  for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__179);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge12.us, %%15, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_623_count);
  llvm_cbe_tmp__171 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__180&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__171&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_624_count);
  llvm_cbe_tmp__172 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__173 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__172))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__172));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_626_count);
  llvm_cbe_tmp__174 = (float )*llvm_cbe_tmp__173;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__174, *(int*)(&llvm_cbe_tmp__174));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fmul float %%9, %%lr, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__175 = (float )((float )(llvm_cbe_tmp__174 * llvm_cbe_lr));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__175, *(int*)(&llvm_cbe_tmp__175));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%output_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__176 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__172))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__172));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__177 = (float )*llvm_cbe_tmp__176;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__177, *(int*)(&llvm_cbe_tmp__177));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fsub float %%12, %%10, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__178 = (float )((float )(llvm_cbe_tmp__177 - llvm_cbe_tmp__175));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__178, *(int*)(&llvm_cbe_tmp__178));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%13, float* %%11, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_631_count);
  *llvm_cbe_tmp__176 = llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge12.us, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagation  --> \n", ++aesl_llvm_cbe_632_count);
  llvm_cbe_tmp__179 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__179&4294967295ull)));
  if (((llvm_cbe_tmp__179&4294967295U) == (llvm_cbe_h&4294967295U))) {
    goto llvm_cbe_tmp__183;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__179;   /* for PHI node */
    goto llvm_cbe_tmp__182;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge4:
  goto llvm_cbe_tmp__181;

llvm_cbe_tmp__181:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixBackPropagation}\n");
  return;
}


void forward(void) {
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  float llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  double llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  double llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  double llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  float llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  float llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  double llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  double llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  double llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  double llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  float llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  float llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  double llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  double llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  double llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  double llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  float llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  float llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  double llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  double llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  double llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  double llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  float llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  float llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  double llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  double llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  double llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  double llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  float llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  float llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  double llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  double llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  double llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  double llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  float llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  float llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  double llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  double llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  double llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  double llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  float llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  float llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  double llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  double llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  double llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  double llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  float llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  float llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  double llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  double llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  double llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  double llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  float llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  float llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  double llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  double llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  double llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  double llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  float llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  double llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  float llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  double llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  double llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  double llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  float llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  float llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  double llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  double llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  double llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  float llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  float llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  double llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  double llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  double llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  float llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  float llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  double llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  double llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  double llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  float llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  float llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  double llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  double llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  double llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  float llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  float llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  double llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  double llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  double llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  float llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  float llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  double llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  double llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  double llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  float llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  float llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  double llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  double llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  double llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  float llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  float llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  double llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  double llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  double llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  float llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  float llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  double llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  double llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  double llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  float llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @forward\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Conv2d(i32 30, i32 30, i32 3, float* getelementptr inbounds ([30 x [30 x float]]* @aesl_internal_mnist_data, i64 0, i64 0, i64 0), float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([28 x [28 x float]]* @aesl_internal_conv_out_1, i64 0, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_647_count);
   /*tail*/ Conv2d(30u, 30u, 3u, (float *)((&aesl_internal_mnist_data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), (float *)((&aesl_internal_conv_kernel_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&aesl_internal_conv_out_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",30u);
printf("\nArgument  = 0x%X",30u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Conv2d(i32 28, i32 28, i32 3, float* getelementptr inbounds ([28 x [28 x float]]* @aesl_internal_conv_out_1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([26 x [26 x float]]* @aesl_internal_conv_out_2, i64 0, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_648_count);
   /*tail*/ Conv2d(28u, 28u, 3u, (float *)((&aesl_internal_conv_out_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), (float *)((&aesl_internal_conv_kernel_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&aesl_internal_conv_out_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",28u);
printf("\nArgument  = 0x%X",28u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Conv2d(i32 26, i32 26, i32 3, float* getelementptr inbounds ([26 x [26 x float]]* @aesl_internal_conv_out_2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_3, i64 0, i64 0, i64 0), float* getelementptr inbounds ([24 x [24 x float]]* @aesl_internal_conv_out_3, i64 0, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_649_count);
   /*tail*/ Conv2d(26u, 26u, 3u, (float *)((&aesl_internal_conv_out_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])), (float *)((&aesl_internal_conv_kernel_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&aesl_internal_conv_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",26u);
printf("\nArgument  = 0x%X",26u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixExtensionImproved(i32 24, i32 24, float* getelementptr inbounds ([24 x [24 x float]]* @aesl_internal_conv_out_3, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [576 x float]]* @aesl_internal_fc_in_1, i64 0, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_650_count);
   /*tail*/ MatrixExtensionImproved(24u, 24u, (float *)((&aesl_internal_conv_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
])), (float *)((&aesl_internal_fc_in_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",24u);
printf("\nArgument  = 0x%X",24u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixMultiply(i32 576, i32 180, float* getelementptr inbounds ([1 x [576 x float]]* @aesl_internal_fc_in_1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_fc_out_1, i64 0, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_651_count);
   /*tail*/ MatrixMultiply(576u, 180u, (float *)((&aesl_internal_fc_in_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
])), (float *)((&aesl_internal_fc_hidden_layer1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)((&aesl_internal_fc_out_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",576u);
printf("\nArgument  = 0x%X",180u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Relu(i32 180, float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_fc_out_1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_fc_in_2_relu1, i64 0, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_652_count);
   /*tail*/ Relu(180u, (float *)((&aesl_internal_fc_out_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)((&aesl_internal_fc_in_2_relu1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",180u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixMultiply(i32 180, i32 45, float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_fc_in_2_relu1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_fc_out_2, i64 0, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_653_count);
   /*tail*/ MatrixMultiply(180u, 45u, (float *)((&aesl_internal_fc_in_2_relu1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)((&aesl_internal_fc_hidden_layer2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)((&aesl_internal_fc_out_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",180u);
printf("\nArgument  = 0x%X",45u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Relu(i32 45, float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_fc_out_2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_fc_in_3_relu2, i64 0, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_654_count);
   /*tail*/ Relu(45u, (float *)((&aesl_internal_fc_out_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)((&aesl_internal_fc_in_3_relu2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",45u);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixMultiply(i32 45, i32 10, float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_fc_in_3_relu2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_655_count);
   /*tail*/ MatrixMultiply(45u, 10u, (float *)((&aesl_internal_fc_in_3_relu2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)((&aesl_internal_fc_hidden_layer3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), (float *)((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",45u);
printf("\nArgument  = 0x%X",10u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 0), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_663_count);
  llvm_cbe_tmp__184 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__184, *(int*)(&llvm_cbe_tmp__184));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = fpext float %%0 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_664_count);
  llvm_cbe_tmp__185 = (double )((double )llvm_cbe_tmp__184);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__185, *(long long*)(&llvm_cbe_tmp__185));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call double @exp(double %%1) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_665_count);
  llvm_cbe_tmp__186 = (double ) /*tail*/ exp(llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__185, *(long long*)(&llvm_cbe_tmp__185));
printf("\nReturn  = %lf",llvm_cbe_tmp__186);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = fadd double %%2, 0.000000e+00, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_666_count);
  llvm_cbe_tmp__187 = (double )llvm_cbe_tmp__186 + 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__187, *(long long*)(&llvm_cbe_tmp__187));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = fptrunc double %%3 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_667_count);
  llvm_cbe_tmp__188 = (float )((float )llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__188, *(int*)(&llvm_cbe_tmp__188));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 1), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_675_count);
  llvm_cbe_tmp__189 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__189, *(int*)(&llvm_cbe_tmp__189));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fpext float %%5 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_676_count);
  llvm_cbe_tmp__190 = (double )((double )llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__190, *(long long*)(&llvm_cbe_tmp__190));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call double @exp(double %%6) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_677_count);
  llvm_cbe_tmp__191 = (double ) /*tail*/ exp(llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__190, *(long long*)(&llvm_cbe_tmp__190));
printf("\nReturn  = %lf",llvm_cbe_tmp__191);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fpext float %%4 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_678_count);
  llvm_cbe_tmp__192 = (double )((double )llvm_cbe_tmp__188);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__192, *(long long*)(&llvm_cbe_tmp__192));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fadd double %%8, %%7, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_679_count);
  llvm_cbe_tmp__193 = (double )llvm_cbe_tmp__192 + llvm_cbe_tmp__191;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__193, *(long long*)(&llvm_cbe_tmp__193));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fptrunc double %%9 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_680_count);
  llvm_cbe_tmp__194 = (float )((float )llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__194, *(int*)(&llvm_cbe_tmp__194));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 2), align 8, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__195 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__195, *(int*)(&llvm_cbe_tmp__195));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fpext float %%11 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_689_count);
  llvm_cbe_tmp__196 = (double )((double )llvm_cbe_tmp__195);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__196, *(long long*)(&llvm_cbe_tmp__196));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call double @exp(double %%12) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__197 = (double ) /*tail*/ exp(llvm_cbe_tmp__196);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__196, *(long long*)(&llvm_cbe_tmp__196));
printf("\nReturn  = %lf",llvm_cbe_tmp__197);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fpext float %%10 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_691_count);
  llvm_cbe_tmp__198 = (double )((double )llvm_cbe_tmp__194);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__198, *(long long*)(&llvm_cbe_tmp__198));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fadd double %%14, %%13, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_692_count);
  llvm_cbe_tmp__199 = (double )llvm_cbe_tmp__198 + llvm_cbe_tmp__197;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__199, *(long long*)(&llvm_cbe_tmp__199));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fptrunc double %%15 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_693_count);
  llvm_cbe_tmp__200 = (float )((float )llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__200, *(int*)(&llvm_cbe_tmp__200));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 3), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__201 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__201, *(int*)(&llvm_cbe_tmp__201));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fpext float %%17 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__202 = (double )((double )llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__202, *(long long*)(&llvm_cbe_tmp__202));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call double @exp(double %%18) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__203 = (double ) /*tail*/ exp(llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__202, *(long long*)(&llvm_cbe_tmp__202));
printf("\nReturn  = %lf",llvm_cbe_tmp__203);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fpext float %%16 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__204 = (double )((double )llvm_cbe_tmp__200);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__204, *(long long*)(&llvm_cbe_tmp__204));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fadd double %%20, %%19, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__205 = (double )llvm_cbe_tmp__204 + llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__205, *(long long*)(&llvm_cbe_tmp__205));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = fptrunc double %%21 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__206 = (float )((float )llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__206, *(int*)(&llvm_cbe_tmp__206));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 4), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_714_count);
  llvm_cbe_tmp__207 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__207, *(int*)(&llvm_cbe_tmp__207));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = fpext float %%23 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_715_count);
  llvm_cbe_tmp__208 = (double )((double )llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__208, *(long long*)(&llvm_cbe_tmp__208));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = tail call double @exp(double %%24) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_716_count);
  llvm_cbe_tmp__209 = (double ) /*tail*/ exp(llvm_cbe_tmp__208);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__208, *(long long*)(&llvm_cbe_tmp__208));
printf("\nReturn  = %lf",llvm_cbe_tmp__209);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fpext float %%22 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__210 = (double )((double )llvm_cbe_tmp__206);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__210, *(long long*)(&llvm_cbe_tmp__210));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = fadd double %%26, %%25, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__211 = (double )llvm_cbe_tmp__210 + llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__211, *(long long*)(&llvm_cbe_tmp__211));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = fptrunc double %%27 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_719_count);
  llvm_cbe_tmp__212 = (float )((float )llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__212, *(int*)(&llvm_cbe_tmp__212));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 5), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_727_count);
  llvm_cbe_tmp__213 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__213, *(int*)(&llvm_cbe_tmp__213));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fpext float %%29 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__214 = (double )((double )llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__214, *(long long*)(&llvm_cbe_tmp__214));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call double @exp(double %%30) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__215 = (double ) /*tail*/ exp(llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__214, *(long long*)(&llvm_cbe_tmp__214));
printf("\nReturn  = %lf",llvm_cbe_tmp__215);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = fpext float %%28 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__216 = (double )((double )llvm_cbe_tmp__212);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__216, *(long long*)(&llvm_cbe_tmp__216));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fadd double %%32, %%31, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__217 = (double )llvm_cbe_tmp__216 + llvm_cbe_tmp__215;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__217, *(long long*)(&llvm_cbe_tmp__217));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = fptrunc double %%33 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__218 = (float )((float )llvm_cbe_tmp__217);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__218, *(int*)(&llvm_cbe_tmp__218));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 6), align 8, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_740_count);
  llvm_cbe_tmp__219 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__219, *(int*)(&llvm_cbe_tmp__219));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = fpext float %%35 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_741_count);
  llvm_cbe_tmp__220 = (double )((double )llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__220, *(long long*)(&llvm_cbe_tmp__220));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = tail call double @exp(double %%36) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__221 = (double ) /*tail*/ exp(llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__220, *(long long*)(&llvm_cbe_tmp__220));
printf("\nReturn  = %lf",llvm_cbe_tmp__221);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = fpext float %%34 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__222 = (double )((double )llvm_cbe_tmp__218);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__222, *(long long*)(&llvm_cbe_tmp__222));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fadd double %%38, %%37, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__223 = (double )llvm_cbe_tmp__222 + llvm_cbe_tmp__221;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__223, *(long long*)(&llvm_cbe_tmp__223));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fptrunc double %%39 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_745_count);
  llvm_cbe_tmp__224 = (float )((float )llvm_cbe_tmp__223);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__224, *(int*)(&llvm_cbe_tmp__224));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 7), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__225 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__225, *(int*)(&llvm_cbe_tmp__225));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = fpext float %%41 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__226 = (double )((double )llvm_cbe_tmp__225);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__226, *(long long*)(&llvm_cbe_tmp__226));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = tail call double @exp(double %%42) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_755_count);
  llvm_cbe_tmp__227 = (double ) /*tail*/ exp(llvm_cbe_tmp__226);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__226, *(long long*)(&llvm_cbe_tmp__226));
printf("\nReturn  = %lf",llvm_cbe_tmp__227);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = fpext float %%40 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_756_count);
  llvm_cbe_tmp__228 = (double )((double )llvm_cbe_tmp__224);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__228, *(long long*)(&llvm_cbe_tmp__228));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = fadd double %%44, %%43, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_757_count);
  llvm_cbe_tmp__229 = (double )llvm_cbe_tmp__228 + llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__229, *(long long*)(&llvm_cbe_tmp__229));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = fptrunc double %%45 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_758_count);
  llvm_cbe_tmp__230 = (float )((float )llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__230, *(int*)(&llvm_cbe_tmp__230));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 8), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_766_count);
  llvm_cbe_tmp__231 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__231, *(int*)(&llvm_cbe_tmp__231));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = fpext float %%47 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_767_count);
  llvm_cbe_tmp__232 = (double )((double )llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__232, *(long long*)(&llvm_cbe_tmp__232));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = tail call double @exp(double %%48) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__233 = (double ) /*tail*/ exp(llvm_cbe_tmp__232);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__232, *(long long*)(&llvm_cbe_tmp__232));
printf("\nReturn  = %lf",llvm_cbe_tmp__233);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fpext float %%46 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_769_count);
  llvm_cbe_tmp__234 = (double )((double )llvm_cbe_tmp__230);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__234, *(long long*)(&llvm_cbe_tmp__234));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = fadd double %%50, %%49, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__235 = (double )llvm_cbe_tmp__234 + llvm_cbe_tmp__233;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__235, *(long long*)(&llvm_cbe_tmp__235));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = fptrunc double %%51 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_771_count);
  llvm_cbe_tmp__236 = (float )((float )llvm_cbe_tmp__235);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__236, *(int*)(&llvm_cbe_tmp__236));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 9), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__237 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__237, *(int*)(&llvm_cbe_tmp__237));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fpext float %%53 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_780_count);
  llvm_cbe_tmp__238 = (double )((double )llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__238, *(long long*)(&llvm_cbe_tmp__238));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = tail call double @exp(double %%54) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__239 = (double ) /*tail*/ exp(llvm_cbe_tmp__238);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__238, *(long long*)(&llvm_cbe_tmp__238));
printf("\nReturn  = %lf",llvm_cbe_tmp__239);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fpext float %%52 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__240 = (double )((double )llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__240, *(long long*)(&llvm_cbe_tmp__240));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = fadd double %%56, %%55, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__241 = (double )llvm_cbe_tmp__240 + llvm_cbe_tmp__239;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__241, *(long long*)(&llvm_cbe_tmp__241));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = fptrunc double %%57 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__242 = (float )((float )llvm_cbe_tmp__241);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__242, *(int*)(&llvm_cbe_tmp__242));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = fpext float %%58 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_796_count);
  llvm_cbe_tmp__243 = (double )((double )llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__243, *(long long*)(&llvm_cbe_tmp__243));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 0), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_797_count);
  llvm_cbe_tmp__244 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__244, *(int*)(&llvm_cbe_tmp__244));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = fpext float %%60 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__245 = (double )((double )llvm_cbe_tmp__244);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__245, *(long long*)(&llvm_cbe_tmp__245));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = tail call double @exp(double %%61) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__246 = (double ) /*tail*/ exp(llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__245, *(long long*)(&llvm_cbe_tmp__245));
printf("\nReturn  = %lf",llvm_cbe_tmp__246);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = fdiv double %%62, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__247 = (double )llvm_cbe_tmp__246 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__247, *(long long*)(&llvm_cbe_tmp__247));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = fptrunc double %%63 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__248 = (float )((float )llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__248, *(int*)(&llvm_cbe_tmp__248));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%64, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 0), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_802_count);
  *((&aesl_internal_probability_result[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__248);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 1), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_808_count);
  llvm_cbe_tmp__249 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__249, *(int*)(&llvm_cbe_tmp__249));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fpext float %%65 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__250 = (double )((double )llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__250, *(long long*)(&llvm_cbe_tmp__250));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = tail call double @exp(double %%66) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__251 = (double ) /*tail*/ exp(llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__250, *(long long*)(&llvm_cbe_tmp__250));
printf("\nReturn  = %lf",llvm_cbe_tmp__251);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = fdiv double %%67, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_811_count);
  llvm_cbe_tmp__252 = (double )llvm_cbe_tmp__251 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__252, *(long long*)(&llvm_cbe_tmp__252));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = fptrunc double %%68 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__253 = (float )((float )llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__253, *(int*)(&llvm_cbe_tmp__253));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%69, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 1), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_813_count);
  *((&aesl_internal_probability_result[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 2), align 8, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_819_count);
  llvm_cbe_tmp__254 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__254, *(int*)(&llvm_cbe_tmp__254));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = fpext float %%70 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_820_count);
  llvm_cbe_tmp__255 = (double )((double )llvm_cbe_tmp__254);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__255, *(long long*)(&llvm_cbe_tmp__255));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = tail call double @exp(double %%71) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_821_count);
  llvm_cbe_tmp__256 = (double ) /*tail*/ exp(llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__255, *(long long*)(&llvm_cbe_tmp__255));
printf("\nReturn  = %lf",llvm_cbe_tmp__256);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fdiv double %%72, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_822_count);
  llvm_cbe_tmp__257 = (double )llvm_cbe_tmp__256 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__257, *(long long*)(&llvm_cbe_tmp__257));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fptrunc double %%73 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_823_count);
  llvm_cbe_tmp__258 = (float )((float )llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__258, *(int*)(&llvm_cbe_tmp__258));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 2), align 8, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_824_count);
  *((&aesl_internal_probability_result[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__258;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__258);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 3), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_830_count);
  llvm_cbe_tmp__259 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__259, *(int*)(&llvm_cbe_tmp__259));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = fpext float %%75 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__260 = (double )((double )llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__260, *(long long*)(&llvm_cbe_tmp__260));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = tail call double @exp(double %%76) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_832_count);
  llvm_cbe_tmp__261 = (double ) /*tail*/ exp(llvm_cbe_tmp__260);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__260, *(long long*)(&llvm_cbe_tmp__260));
printf("\nReturn  = %lf",llvm_cbe_tmp__261);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = fdiv double %%77, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_833_count);
  llvm_cbe_tmp__262 = (double )llvm_cbe_tmp__261 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__262, *(long long*)(&llvm_cbe_tmp__262));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = fptrunc double %%78 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_834_count);
  llvm_cbe_tmp__263 = (float )((float )llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__263, *(int*)(&llvm_cbe_tmp__263));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%79, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 3), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_835_count);
  *((&aesl_internal_probability_result[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__263;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__263);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 4), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_841_count);
  llvm_cbe_tmp__264 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__264, *(int*)(&llvm_cbe_tmp__264));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = fpext float %%80 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_842_count);
  llvm_cbe_tmp__265 = (double )((double )llvm_cbe_tmp__264);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__265, *(long long*)(&llvm_cbe_tmp__265));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = tail call double @exp(double %%81) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_843_count);
  llvm_cbe_tmp__266 = (double ) /*tail*/ exp(llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__265, *(long long*)(&llvm_cbe_tmp__265));
printf("\nReturn  = %lf",llvm_cbe_tmp__266);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = fdiv double %%82, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_844_count);
  llvm_cbe_tmp__267 = (double )llvm_cbe_tmp__266 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__267, *(long long*)(&llvm_cbe_tmp__267));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = fptrunc double %%83 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_845_count);
  llvm_cbe_tmp__268 = (float )((float )llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__268, *(int*)(&llvm_cbe_tmp__268));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%84, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 4), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_846_count);
  *((&aesl_internal_probability_result[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__268;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 5), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_852_count);
  llvm_cbe_tmp__269 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__269, *(int*)(&llvm_cbe_tmp__269));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = fpext float %%85 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_853_count);
  llvm_cbe_tmp__270 = (double )((double )llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__270, *(long long*)(&llvm_cbe_tmp__270));
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = tail call double @exp(double %%86) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_854_count);
  llvm_cbe_tmp__271 = (double ) /*tail*/ exp(llvm_cbe_tmp__270);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__270, *(long long*)(&llvm_cbe_tmp__270));
printf("\nReturn  = %lf",llvm_cbe_tmp__271);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = fdiv double %%87, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_855_count);
  llvm_cbe_tmp__272 = (double )llvm_cbe_tmp__271 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__272, *(long long*)(&llvm_cbe_tmp__272));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = fptrunc double %%88 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_856_count);
  llvm_cbe_tmp__273 = (float )((float )llvm_cbe_tmp__272);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__273, *(int*)(&llvm_cbe_tmp__273));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%89, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 5), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_857_count);
  *((&aesl_internal_probability_result[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__273;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__273);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 6), align 8, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_863_count);
  llvm_cbe_tmp__274 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__274, *(int*)(&llvm_cbe_tmp__274));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = fpext float %%90 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_864_count);
  llvm_cbe_tmp__275 = (double )((double )llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__275, *(long long*)(&llvm_cbe_tmp__275));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = tail call double @exp(double %%91) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_865_count);
  llvm_cbe_tmp__276 = (double ) /*tail*/ exp(llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__275, *(long long*)(&llvm_cbe_tmp__275));
printf("\nReturn  = %lf",llvm_cbe_tmp__276);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = fdiv double %%92, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__277 = (double )llvm_cbe_tmp__276 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__277, *(long long*)(&llvm_cbe_tmp__277));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = fptrunc double %%93 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_867_count);
  llvm_cbe_tmp__278 = (float )((float )llvm_cbe_tmp__277);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__278, *(int*)(&llvm_cbe_tmp__278));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%94, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 6), align 8, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_868_count);
  *((&aesl_internal_probability_result[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__278;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__278);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 7), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_874_count);
  llvm_cbe_tmp__279 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__279, *(int*)(&llvm_cbe_tmp__279));
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = fpext float %%95 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_875_count);
  llvm_cbe_tmp__280 = (double )((double )llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__280, *(long long*)(&llvm_cbe_tmp__280));
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = tail call double @exp(double %%96) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_876_count);
  llvm_cbe_tmp__281 = (double ) /*tail*/ exp(llvm_cbe_tmp__280);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__280, *(long long*)(&llvm_cbe_tmp__280));
printf("\nReturn  = %lf",llvm_cbe_tmp__281);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = fdiv double %%97, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_877_count);
  llvm_cbe_tmp__282 = (double )llvm_cbe_tmp__281 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__282, *(long long*)(&llvm_cbe_tmp__282));
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = fptrunc double %%98 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_878_count);
  llvm_cbe_tmp__283 = (float )((float )llvm_cbe_tmp__282);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__283, *(int*)(&llvm_cbe_tmp__283));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%99, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 7), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_879_count);
  *((&aesl_internal_probability_result[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__283;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__283);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 8), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_885_count);
  llvm_cbe_tmp__284 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__284, *(int*)(&llvm_cbe_tmp__284));
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = fpext float %%100 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_886_count);
  llvm_cbe_tmp__285 = (double )((double )llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__285, *(long long*)(&llvm_cbe_tmp__285));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = tail call double @exp(double %%101) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__286 = (double ) /*tail*/ exp(llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__285, *(long long*)(&llvm_cbe_tmp__285));
printf("\nReturn  = %lf",llvm_cbe_tmp__286);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = fdiv double %%102, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__287 = (double )llvm_cbe_tmp__286 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__287, *(long long*)(&llvm_cbe_tmp__287));
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = fptrunc double %%103 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_889_count);
  llvm_cbe_tmp__288 = (float )((float )llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__288, *(int*)(&llvm_cbe_tmp__288));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%104, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 8), align 16, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_890_count);
  *((&aesl_internal_probability_result[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__288;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_fc_out_3, i64 0, i64 0, i64 9), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__289 = (float )*((&aesl_internal_fc_out_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__289, *(int*)(&llvm_cbe_tmp__289));
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = fpext float %%105 to double, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__290 = (double )((double )llvm_cbe_tmp__289);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__290, *(long long*)(&llvm_cbe_tmp__290));
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = tail call double @exp(double %%106) nounwind, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_898_count);
  llvm_cbe_tmp__291 = (double ) /*tail*/ exp(llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__290, *(long long*)(&llvm_cbe_tmp__290));
printf("\nReturn  = %lf",llvm_cbe_tmp__291);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = fdiv double %%107, %%59, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_899_count);
  llvm_cbe_tmp__292 = (double )llvm_cbe_tmp__291 / llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__292, *(long long*)(&llvm_cbe_tmp__292));
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = fptrunc double %%108 to float, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_900_count);
  llvm_cbe_tmp__293 = (float )((float )llvm_cbe_tmp__292);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__293, *(int*)(&llvm_cbe_tmp__293));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%109, float* getelementptr inbounds ([10 x float]* @aesl_internal_probability_result, i64 0, i64 9), align 4, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_901_count);
  *((&aesl_internal_probability_result[(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__293);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @forward}\n");
  return;
}


void backward(signed int llvm_cbe_label, float *llvm_cbe_lr_in) {
  static  unsigned long long aesl_llvm_cbe_grad_3_count = 0;
  float llvm_cbe_grad_3[10];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_wgrad_3_count = 0;
  float llvm_cbe_wgrad_3[450];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rgrad_2_count = 0;
  float llvm_cbe_rgrad_2[45];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_grad_2_count = 0;
  float llvm_cbe_grad_2[180];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_wgrad_2_count = 0;
  float llvm_cbe_wgrad_2[8100];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rgrad_1_count = 0;
  float llvm_cbe_rgrad_1[180];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_grad_1_count = 0;
  float llvm_cbe_grad_1[180];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_wgrad_1_count = 0;
  float llvm_cbe_wgrad_1[103680];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_grad_0_count = 0;
  float llvm_cbe_grad_0[576];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_grad_3_count = 0;
  float llvm_cbe_kernel_grad_3[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_conv_grad_2_count = 0;
  float llvm_cbe_conv_grad_2[676];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_grad_3_overturn_count = 0;
  float llvm_cbe_kernel_grad_3_overturn[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_conv_grad_3_padding_count = 0;
  float llvm_cbe_conv_grad_3_padding[784];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_grad_2_count = 0;
  float llvm_cbe_kernel_grad_2[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_conv_grad_1_count = 0;
  float llvm_cbe_conv_grad_1[784];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_grad_2_overturn_count = 0;
  float llvm_cbe_kernel_grad_2_overturn[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_conv_grad_2_padding_count = 0;
  float llvm_cbe_conv_grad_2_padding[900];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_grad_1_count = 0;
  float llvm_cbe_kernel_grad_1[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  unsigned long long llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  float *llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  float llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  float llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  float *llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  unsigned long long llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  float *llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  float llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  float *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  unsigned int llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  float *llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  float *llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  float *llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  float *llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  float *llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  float *llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  float *llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  float *llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  float *llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  float *llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  float *llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  float *llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  float *llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  float *llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  float *llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  float *llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  float *llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  float *llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  float llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  float llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  float llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  float llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  float llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  float llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @backward\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__328;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__328:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%15, %%14  for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__303);
}
  if (((llvm_cbe_storemerge1&4294967295U) == (llvm_cbe_label&4294967295U))) {
    goto llvm_cbe_tmp__329;
  } else {
    goto llvm_cbe_tmp__330;
  }

llvm_cbe_tmp__331:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_942_count);
  llvm_cbe_tmp__303 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__303&4294967295ull)));
  if (((llvm_cbe_tmp__303&4294967295U) == (10u&4294967295U))) {
    goto llvm_cbe_tmp__332;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__303;   /* for PHI node */
    goto llvm_cbe_tmp__328;
  }

llvm_cbe_tmp__329:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%label to i64, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_929_count);
  llvm_cbe_tmp__294 = (unsigned long long )((signed long long )(signed int )llvm_cbe_label);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__294);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [10 x float]* @aesl_internal_probability_result, i64 0, i64 %%4, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_930_count);
  llvm_cbe_tmp__295 = (float *)(&aesl_internal_probability_result[(((signed long long )llvm_cbe_tmp__294))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__294));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__294) < 10)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_probability_result' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_931_count);
  llvm_cbe_tmp__296 = (float )*llvm_cbe_tmp__295;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__296, *(int*)(&llvm_cbe_tmp__296));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fadd float %%6, -1.000000e+00, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__297 = (float )((float )(llvm_cbe_tmp__296 + -0x1p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__297, *(int*)(&llvm_cbe_tmp__297));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [10 x float]* %%grad_3, i64 0, i64 %%4, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_933_count);
  llvm_cbe_tmp__298 = (float *)(&llvm_cbe_grad_3[(((signed long long )llvm_cbe_tmp__294))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__294));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__294) < 10 && "Write access out of array 'grad_3' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%7, float* %%8, align 4, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_934_count);
  *llvm_cbe_tmp__298 = llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__297);
  goto llvm_cbe_tmp__331;

llvm_cbe_tmp__330:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge1 to i64, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_936_count);
  llvm_cbe_tmp__299 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [10 x float]* @aesl_internal_probability_result, i64 0, i64 %%10, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_937_count);
  llvm_cbe_tmp__300 = (float *)(&aesl_internal_probability_result[(((signed long long )llvm_cbe_tmp__299))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__299));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__299) < 10)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_probability_result' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_938_count);
  llvm_cbe_tmp__301 = (float )*llvm_cbe_tmp__300;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__301, *(int*)(&llvm_cbe_tmp__301));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [10 x float]* %%grad_3, i64 0, i64 %%10, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_939_count);
  llvm_cbe_tmp__302 = (float *)(&llvm_cbe_grad_3[(((signed long long )llvm_cbe_tmp__299))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__299));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__299) < 10 && "Write access out of array 'grad_3' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%13, align 4, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_940_count);
  *llvm_cbe_tmp__302 = llvm_cbe_tmp__301;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__301);
  goto llvm_cbe_tmp__331;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__332:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [10 x float]* %%grad_3, i64 0, i64 0, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_953_count);
  llvm_cbe_tmp__304 = (float *)(&llvm_cbe_grad_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [450 x float]* %%wgrad_3, i64 0, i64 0, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_954_count);
  llvm_cbe_tmp__305 = (float *)(&llvm_cbe_wgrad_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 450
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagationMultiply(i32 45, i32 10, float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_fc_in_3_relu2, i64 0, i64 0, i64 0), float* %%17, float* %%18), !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_955_count);
  MatrixBackPropagationMultiply(45u, 10u, (float *)((&aesl_internal_fc_in_3_relu2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)llvm_cbe_tmp__304, (float *)llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",45u);
printf("\nArgument  = 0x%X",10u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [45 x float]* %%rgrad_2, i64 0, i64 0, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_957_count);
  llvm_cbe_tmp__306 = (float *)(&llvm_cbe_rgrad_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @CalculateMatrixGrad(i32 45, i32 10, float* getelementptr inbounds ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3, i64 0, i64 0, i64 0), float* %%17, float* %%19), !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_958_count);
  CalculateMatrixGrad(45u, 10u, (float *)((&aesl_internal_fc_hidden_layer3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), (float *)llvm_cbe_tmp__304, (float *)llvm_cbe_tmp__306);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",45u);
printf("\nArgument  = 0x%X",10u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [180 x float]* %%grad_2, i64 0, i64 0, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_960_count);
  llvm_cbe_tmp__307 = (float *)(&llvm_cbe_grad_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @ReluBackPropagation(i32 45, float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_fc_out_2, i64 0, i64 0, i64 0), float* %%19, float* %%20), !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_961_count);
  ReluBackPropagation(45u, (float *)((&aesl_internal_fc_out_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)llvm_cbe_tmp__306, (float *)llvm_cbe_tmp__307);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",45u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [8100 x float]* %%wgrad_2, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_963_count);
  llvm_cbe_tmp__308 = (float *)(&llvm_cbe_wgrad_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagationMultiply(i32 180, i32 45, float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_fc_in_2_relu1, i64 0, i64 0, i64 0), float* %%20, float* %%21), !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_964_count);
  MatrixBackPropagationMultiply(180u, 45u, (float *)((&aesl_internal_fc_in_2_relu1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)llvm_cbe_tmp__307, (float *)llvm_cbe_tmp__308);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",180u);
printf("\nArgument  = 0x%X",45u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [180 x float]* %%rgrad_1, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_966_count);
  llvm_cbe_tmp__309 = (float *)(&llvm_cbe_rgrad_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @CalculateMatrixGrad(i32 180, i32 45, float* getelementptr inbounds ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2, i64 0, i64 0, i64 0), float* %%20, float* %%22), !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_967_count);
  CalculateMatrixGrad(180u, 45u, (float *)((&aesl_internal_fc_hidden_layer2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)llvm_cbe_tmp__307, (float *)llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",180u);
printf("\nArgument  = 0x%X",45u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [180 x float]* %%grad_1, i64 0, i64 0, !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_969_count);
  llvm_cbe_tmp__310 = (float *)(&llvm_cbe_grad_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @ReluBackPropagation(i32 180, float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_fc_out_1, i64 0, i64 0, i64 0), float* %%22, float* %%23), !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_970_count);
  ReluBackPropagation(180u, (float *)((&aesl_internal_fc_out_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)llvm_cbe_tmp__309, (float *)llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",180u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [103680 x float]* %%wgrad_1, i64 0, i64 0, !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_972_count);
  llvm_cbe_tmp__311 = (float *)(&llvm_cbe_wgrad_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 103680
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagationMultiply(i32 576, i32 180, float* getelementptr inbounds ([1 x [576 x float]]* @aesl_internal_fc_in_1, i64 0, i64 0, i64 0), float* %%23, float* %%24), !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_973_count);
  MatrixBackPropagationMultiply(576u, 180u, (float *)((&aesl_internal_fc_in_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
])), (float *)llvm_cbe_tmp__310, (float *)llvm_cbe_tmp__311);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",576u);
printf("\nArgument  = 0x%X",180u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [576 x float]* %%grad_0, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_975_count);
  llvm_cbe_tmp__312 = (float *)(&llvm_cbe_grad_0[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @CalculateMatrixGrad(i32 576, i32 180, float* getelementptr inbounds ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1, i64 0, i64 0, i64 0), float* %%23, float* %%25), !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_976_count);
  CalculateMatrixGrad(576u, 180u, (float *)((&aesl_internal_fc_hidden_layer1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)llvm_cbe_tmp__310, (float *)llvm_cbe_tmp__312);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",576u);
printf("\nArgument  = 0x%X",180u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [9 x float]* %%kernel_grad_3, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_981_count);
  llvm_cbe_tmp__313 = (float *)(&llvm_cbe_kernel_grad_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d(i32 26, i32 26, i32 24, float* getelementptr inbounds ([26 x [26 x float]]* @aesl_internal_conv_out_2, i64 0, i64 0, i64 0), float* %%25, float* %%26), !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_982_count);
  Conv2d(26u, 26u, 24u, (float *)((&aesl_internal_conv_out_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])), (float *)llvm_cbe_tmp__312, (float *)llvm_cbe_tmp__313);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",26u);
printf("\nArgument  = 0x%X",26u);
printf("\nArgument  = 0x%X",24u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds [9 x float]* %%kernel_grad_3_overturn, i64 0, i64 0, !dbg !23 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_985_count);
  llvm_cbe_tmp__314 = (float *)(&llvm_cbe_kernel_grad_3_overturn[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @OverturnKernel(i32 3, float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_3, i64 0, i64 0, i64 0), float* %%27), !dbg !23 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_986_count);
  OverturnKernel(3u, (float *)((&aesl_internal_conv_kernel_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)llvm_cbe_tmp__314);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [784 x float]* %%conv_grad_3_padding, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__315 = (float *)(&llvm_cbe_conv_grad_3_padding[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 784
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Padding(i32 24, i32 2, float* %%25, float* %%28), !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_989_count);
  Padding(24u, 2u, (float *)llvm_cbe_tmp__312, (float *)llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",24u);
printf("\nArgument  = 0x%X",2u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [676 x float]* %%conv_grad_2, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__316 = (float *)(&llvm_cbe_conv_grad_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 676
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d(i32 28, i32 28, i32 3, float* %%28, float* %%27, float* %%29), !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_991_count);
  Conv2d(28u, 28u, 3u, (float *)llvm_cbe_tmp__315, (float *)llvm_cbe_tmp__314, (float *)llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",28u);
printf("\nArgument  = 0x%X",28u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [9 x float]* %%kernel_grad_2, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_993_count);
  llvm_cbe_tmp__317 = (float *)(&llvm_cbe_kernel_grad_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d(i32 28, i32 28, i32 26, float* getelementptr inbounds ([28 x [28 x float]]* @aesl_internal_conv_out_1, i64 0, i64 0, i64 0), float* %%29, float* %%30), !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_994_count);
  Conv2d(28u, 28u, 26u, (float *)((&aesl_internal_conv_out_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), (float *)llvm_cbe_tmp__316, (float *)llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",28u);
printf("\nArgument  = 0x%X",28u);
printf("\nArgument  = 0x%X",26u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [9 x float]* %%kernel_grad_2_overturn, i64 0, i64 0, !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_997_count);
  llvm_cbe_tmp__318 = (float *)(&llvm_cbe_kernel_grad_2_overturn[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @OverturnKernel(i32 3, float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_2, i64 0, i64 0, i64 0), float* %%31), !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_998_count);
  OverturnKernel(3u, (float *)((&aesl_internal_conv_kernel_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds [900 x float]* %%conv_grad_2_padding, i64 0, i64 0, !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1000_count);
  llvm_cbe_tmp__319 = (float *)(&llvm_cbe_conv_grad_2_padding[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 900
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Padding(i32 26, i32 2, float* %%29, float* %%32), !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1001_count);
  Padding(26u, 2u, (float *)llvm_cbe_tmp__316, (float *)llvm_cbe_tmp__319);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",26u);
printf("\nArgument  = 0x%X",2u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [784 x float]* %%conv_grad_1, i64 0, i64 0, !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1002_count);
  llvm_cbe_tmp__320 = (float *)(&llvm_cbe_conv_grad_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 784
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d(i32 30, i32 30, i32 3, float* %%32, float* %%31, float* %%33), !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1003_count);
  Conv2d(30u, 30u, 3u, (float *)llvm_cbe_tmp__319, (float *)llvm_cbe_tmp__318, (float *)llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",30u);
printf("\nArgument  = 0x%X",30u);
printf("\nArgument  = 0x%X",3u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [9 x float]* %%kernel_grad_1, i64 0, i64 0, !dbg !26 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1005_count);
  llvm_cbe_tmp__321 = (float *)(&llvm_cbe_kernel_grad_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d(i32 30, i32 30, i32 28, float* getelementptr inbounds ([30 x [30 x float]]* @aesl_internal_mnist_data, i64 0, i64 0, i64 0), float* %%33, float* %%34), !dbg !26 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1006_count);
  Conv2d(30u, 30u, 28u, (float *)((&aesl_internal_mnist_data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), (float *)llvm_cbe_tmp__320, (float *)llvm_cbe_tmp__321);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",30u);
printf("\nArgument  = 0x%X",30u);
printf("\nArgument  = 0x%X",28u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load float* %%lr_in, align 4, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1007_count);
  llvm_cbe_tmp__322 = (float )*llvm_cbe_lr_in;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__322, *(int*)(&llvm_cbe_tmp__322));
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagation(i32 3, i32 3, float* %%34, float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_1, i64 0, i64 0, i64 0), float %%35), !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1008_count);
  MatrixBackPropagation(3u, 3u, (float *)llvm_cbe_tmp__321, (float *)((&aesl_internal_conv_kernel_1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__322, *(int*)(&llvm_cbe_tmp__322));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%lr_in, align 4, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1009_count);
  llvm_cbe_tmp__323 = (float )*llvm_cbe_lr_in;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__323, *(int*)(&llvm_cbe_tmp__323));
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagation(i32 3, i32 3, float* %%30, float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_2, i64 0, i64 0, i64 0), float %%36), !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1010_count);
  MatrixBackPropagation(3u, 3u, (float *)llvm_cbe_tmp__317, (float *)((&aesl_internal_conv_kernel_2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), llvm_cbe_tmp__323);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__323, *(int*)(&llvm_cbe_tmp__323));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load float* %%lr_in, align 4, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1011_count);
  llvm_cbe_tmp__324 = (float )*llvm_cbe_lr_in;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__324, *(int*)(&llvm_cbe_tmp__324));
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagation(i32 3, i32 3, float* %%26, float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel_3, i64 0, i64 0, i64 0), float %%37), !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1012_count);
  MatrixBackPropagation(3u, 3u, (float *)llvm_cbe_tmp__313, (float *)((&aesl_internal_conv_kernel_3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), llvm_cbe_tmp__324);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = 0x%X",3u);
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__324, *(int*)(&llvm_cbe_tmp__324));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%lr_in, align 4, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__325 = (float )*llvm_cbe_lr_in;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__325, *(int*)(&llvm_cbe_tmp__325));
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagation(i32 576, i32 180, float* %%24, float* getelementptr inbounds ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1, i64 0, i64 0, i64 0), float %%38), !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1014_count);
  MatrixBackPropagation(576u, 180u, (float *)llvm_cbe_tmp__311, (float *)((&aesl_internal_fc_hidden_layer1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",576u);
printf("\nArgument  = 0x%X",180u);
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__325, *(int*)(&llvm_cbe_tmp__325));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* %%lr_in, align 4, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1015_count);
  llvm_cbe_tmp__326 = (float )*llvm_cbe_lr_in;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__326, *(int*)(&llvm_cbe_tmp__326));
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagation(i32 180, i32 45, float* %%21, float* getelementptr inbounds ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2, i64 0, i64 0, i64 0), float %%39), !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1016_count);
  MatrixBackPropagation(180u, 45u, (float *)llvm_cbe_tmp__308, (float *)((&aesl_internal_fc_hidden_layer2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",180u);
printf("\nArgument  = 0x%X",45u);
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__326, *(int*)(&llvm_cbe_tmp__326));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* %%lr_in, align 4, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1017_count);
  llvm_cbe_tmp__327 = (float )*llvm_cbe_lr_in;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__327, *(int*)(&llvm_cbe_tmp__327));
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagation(i32 45, i32 10, float* %%18, float* getelementptr inbounds ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3, i64 0, i64 0, i64 0), float %%40), !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1018_count);
  MatrixBackPropagation(45u, 10u, (float *)llvm_cbe_tmp__305, (float *)((&aesl_internal_fc_hidden_layer3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",45u);
printf("\nArgument  = 0x%X",10u);
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__327, *(int*)(&llvm_cbe_tmp__327));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @backward}\n");
  return;
}


void forw_back(signed int llvm_cbe_flag, float *llvm_cbe_in, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3, float *llvm_cbe_out, signed int llvm_cbe_label, float *llvm_cbe_lr) {
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
   char *llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
   char *llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
   char *llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
   char *llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
   char *llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
   char *llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
   char *llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
   char *llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
   char *llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
   char *llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
   char *llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
   char *llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
   char *llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
   char *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
   char *llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
   char *llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
   char *llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
   char *llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
   char *llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
   char *llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
   char *llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
   char *llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
   char *llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
   char *llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
   char *llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
   char *llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
   char *llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
   char *llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @forw_back\n");
  if (((llvm_cbe_flag&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__361;
  } else {
    goto llvm_cbe_tmp__362;
  }

llvm_cbe_tmp__361:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast float* %%conv1 to i8*, !dbg !17 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1054_count);
  llvm_cbe_tmp__333 = ( char *)(( char *)llvm_cbe_conv1);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memcpy(i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel_1 to i8*), i8* %%3, i64 36 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1055_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_conv_kernel_1)), ( char *)llvm_cbe_tmp__333, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__334);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast float* %%conv2 to i8*, !dbg !18 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__335 = ( char *)(( char *)llvm_cbe_conv2);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @memcpy(i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel_2 to i8*), i8* %%5, i64 36 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1057_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_conv_kernel_2)), ( char *)llvm_cbe_tmp__335, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__336);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast float* %%conv3 to i8*, !dbg !18 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1058_count);
  llvm_cbe_tmp__337 = ( char *)(( char *)llvm_cbe_conv3);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memcpy(i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel_3 to i8*), i8* %%7, i64 36 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1059_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_conv_kernel_3)), ( char *)llvm_cbe_tmp__337, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__338);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast float* %%fc1 to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1060_count);
  llvm_cbe_tmp__339 = ( char *)(( char *)llvm_cbe_fc1);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memcpy(i8* bitcast ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1 to i8*), i8* %%9, i64 414720 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1061_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_fc_hidden_layer1)), ( char *)llvm_cbe_tmp__339, 414720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",414720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__340);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast float* %%fc2 to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1062_count);
  llvm_cbe_tmp__341 = ( char *)(( char *)llvm_cbe_fc2);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i8* @memcpy(i8* bitcast ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2 to i8*), i8* %%11, i64 32400 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1063_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_fc_hidden_layer2)), ( char *)llvm_cbe_tmp__341, 32400ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32400ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__342);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = bitcast float* %%fc3 to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__343 = ( char *)(( char *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i8* @memcpy(i8* bitcast ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3 to i8*), i8* %%13, i64 1800 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1065_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_fc_hidden_layer3)), ( char *)llvm_cbe_tmp__343, 1800ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1800ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__344);
}
  goto llvm_cbe_tmp__363;

llvm_cbe_tmp__362:
  if (((llvm_cbe_flag&4294967295U) == (1u&4294967295U))) {
    goto llvm_cbe_tmp__364;
  } else {
    goto llvm_cbe_tmp__365;
  }

llvm_cbe_tmp__364:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = bitcast float* %%in to i8*, !dbg !17 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1069_count);
  llvm_cbe_tmp__345 = ( char *)(( char *)llvm_cbe_in);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i8* @memcpy(i8* bitcast ([30 x [30 x float]]* @aesl_internal_mnist_data to i8*), i8* %%18, i64 3600 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1070_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_mnist_data)), ( char *)llvm_cbe_tmp__345, 3600ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",3600ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__346);
}
  goto llvm_cbe_tmp__366;

llvm_cbe_tmp__365:
  if (((llvm_cbe_flag&4294967295U) == (2u&4294967295U))) {
    goto llvm_cbe_tmp__367;
  } else {
    goto llvm_cbe_tmp__368;
  }

llvm_cbe_tmp__367:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @forward(), !dbg !21 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1074_count);
   /*tail*/ forward();
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__369;

llvm_cbe_tmp__368:
  if (((llvm_cbe_flag&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__370;
  } else {
    goto llvm_cbe_tmp__371;
  }

llvm_cbe_tmp__370:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @forward(), !dbg !21 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1078_count);
   /*tail*/ forward();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @backward(i32 %%label, float* %%lr), !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1079_count);
   /*tail*/ backward(llvm_cbe_label, (float *)llvm_cbe_lr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument label = 0x%X",llvm_cbe_label);
}
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__371:
  if (((llvm_cbe_flag&4294967295U) == (4u&4294967295U))) {
    goto llvm_cbe_tmp__373;
  } else {
    goto llvm_cbe_tmp__374;
  }

llvm_cbe_tmp__373:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = bitcast float* %%out to i8*, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1083_count);
  llvm_cbe_tmp__347 = ( char *)(( char *)llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call i8* @memcpy(i8* %%29, i8* bitcast ([10 x float]* @aesl_internal_probability_result to i8*), i64 40 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1084_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__347, ( char *)(( char *)(&aesl_internal_probability_result)), 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__348);
}
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__374:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = bitcast float* %%conv1 to i8*, !dbg !17 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1086_count);
  llvm_cbe_tmp__349 = ( char *)(( char *)llvm_cbe_conv1);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = call i8* @memcpy(i8* %%32, i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel_1 to i8*), i64 36 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1087_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__349, ( char *)(( char *)(&aesl_internal_conv_kernel_1)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__350);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = bitcast float* %%conv2 to i8*, !dbg !18 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1088_count);
  llvm_cbe_tmp__351 = ( char *)(( char *)llvm_cbe_conv2);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i8* @memcpy(i8* %%34, i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel_2 to i8*), i64 36 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1089_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__351, ( char *)(( char *)(&aesl_internal_conv_kernel_2)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__352);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = bitcast float* %%conv3 to i8*, !dbg !18 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1090_count);
  llvm_cbe_tmp__353 = ( char *)(( char *)llvm_cbe_conv3);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i8* @memcpy(i8* %%36, i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel_3 to i8*), i64 36 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1091_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__353, ( char *)(( char *)(&aesl_internal_conv_kernel_3)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__354);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = bitcast float* %%fc1 to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1092_count);
  llvm_cbe_tmp__355 = ( char *)(( char *)llvm_cbe_fc1);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call i8* @memcpy(i8* %%38, i8* bitcast ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1 to i8*), i64 414720 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1093_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__355, ( char *)(( char *)(&aesl_internal_fc_hidden_layer1)), 414720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",414720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__356);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = bitcast float* %%fc2 to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1094_count);
  llvm_cbe_tmp__357 = ( char *)(( char *)llvm_cbe_fc2);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i8* @memcpy(i8* %%40, i8* bitcast ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2 to i8*), i64 32400 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1095_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__357, ( char *)(( char *)(&aesl_internal_fc_hidden_layer2)), 32400ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32400ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__358);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = bitcast float* %%fc3 to i8*, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1096_count);
  llvm_cbe_tmp__359 = ( char *)(( char *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = call i8* @memcpy(i8* %%42, i8* bitcast ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3 to i8*), i64 1800 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_1097_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__359, ( char *)(( char *)(&aesl_internal_fc_hidden_layer3)), 1800ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1800ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__360);
}
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__375:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__372:
  goto llvm_cbe_tmp__369;

llvm_cbe_tmp__369:
  goto llvm_cbe_tmp__366;

llvm_cbe_tmp__366:
  goto llvm_cbe_tmp__363;

llvm_cbe_tmp__363:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @forw_back}\n");
  return;
}

