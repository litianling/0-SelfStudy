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
void Conv2d1(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Conv2d2(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Conv2d3(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Relu1(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void Relu2(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void MatrixExtensionImproved(float *llvm_cbe_input_matrix1, float *llvm_cbe_output_matrix);
void MatrixMultiply1(float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix);
void MatrixMultiply2(float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix);
void MatrixMultiply3(float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix);
void Conv2d_b1(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Conv2d_b2(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Conv2d_b3(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Conv2d_b4(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void Conv2d_b5(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix);
void MatrixBackPropagationMultiply1(float *llvm_cbe_para, float *llvm_cbe_grad, float *llvm_cbe_rgrad);
void MatrixBackPropagationMultiply2(float *llvm_cbe_para, float *llvm_cbe_grad, float *llvm_cbe_rgrad);
void MatrixBackPropagationMultiply3(float *llvm_cbe_para, float *llvm_cbe_grad, float *llvm_cbe_rgrad);
void CalculateMatrixGrad1(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void CalculateMatrixGrad2(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void CalculateMatrixGrad3(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void ReluBackPropagation1(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void ReluBackPropagation2(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix);
void Padding1(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void Padding2(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void OverturnKernel(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix);
void MatrixSplit(float *llvm_cbe_input_matrix, float *llvm_cbe_splited_matrix1);
void backward(signed int llvm_cbe_label, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3);
void forward(float *llvm_cbe_input_matrix, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3);
void forw_back(signed int llvm_cbe_flag, float *llvm_cbe_in, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3, float *llvm_cbe_out, signed int llvm_cbe_label);


/* Global Variable Definitions and Initialization */
static float aesl_internal_conv_kernel1[3][3];
static float aesl_internal_conv_kernel2[3][3];
static float aesl_internal_conv_kernel3[3][3];
static float aesl_internal_fc_hidden_layer1[576][180];
static float aesl_internal_fc_hidden_layer2[180][45];
static float aesl_internal_mnist_data[30][30];
static float aesl_internal_outmlp[1][10];
static float aesl_internal_first_conv1[28][28];
static float aesl_internal_sencond_conv1[26][26];
static float aesl_internal_second_relu[1][45];
static float aesl_internal_first_fc[1][180];
static float aesl_internal_fc_hidden_layer3[45][10];
static float aesl_internal_out_grad[10];
static float aesl_internal_flatten_conv[1][576];
static float aesl_internal_first_relu[1][180];
static float aesl_internal_second_fc[1][45];
static float aesl_internal_result[10];
static float aesl_internal_third_conv1[24][24];


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
printf("\n  %%2 = select i1 %%1, float %%a, float %%b, !dbg !17 for 0x%I64xth hint within @max  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__1 = (float )(((llvm_fcmp_ogt(llvm_cbe_a, llvm_cbe_b))) ? ((float )llvm_cbe_a) : ((float )llvm_cbe_b));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1, *(int*)(&llvm_cbe_tmp__1));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @max}\n");
  return llvm_cbe_tmp__1;
}


void Conv2d1(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  float *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  float llvm_cbe_tmp__8;
  float llvm_cbe_tmp__8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  float llvm_cbe_tmp__13;
  float llvm_cbe_tmp__13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  float *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  float *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  float llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  float llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d1\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%33, %%32  for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 28, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__28;

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge8, 1, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
  if (((llvm_cbe_tmp__27&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__30;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__27;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%31, %%30  for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__5 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%out_matrix, i64 %%5, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__6 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__5))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__5));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%6, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_40_count);
  *llvm_cbe_tmp__6 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge17, 3, !dbg !19 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
  llvm_cbe_tmp__8__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
  if (((llvm_cbe_tmp__26&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__29;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__26;   /* for PHI node */
    goto llvm_cbe_tmp__28;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%3 ], [ %%24, %%27  for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__8 = (float )llvm_cbe_tmp__8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__8);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%storemerge8, %%3 ], [ %%28, %%27  for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge25, 30, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) * ((unsigned int )(30u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%storemerge25, %%storemerge8, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, 3, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_tmp__10&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%11, %%storemerge17, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__11&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
  llvm_cbe_tmp__13__PHI_TEMPORARY = (float )llvm_cbe_tmp__8;   /* for PHI node */
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge17;   /* for PHI node */
  goto llvm_cbe_tmp__32;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge25, 1, !dbg !19 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__25) < ((signed int )llvm_cbe_tmp__3))) {
    llvm_cbe_tmp__8__PHI_TEMPORARY = (float )llvm_cbe_tmp__23;   /* for PHI node */
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__31;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi float [ %%8, %%.preheader ], [ %%24, %%13 ], !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__13 = (float )llvm_cbe_tmp__13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__13);
printf("\n = %f",llvm_cbe_tmp__8);
printf("\n = %f",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ %%storemerge17, %%.preheader ], [ %%25, %%13  for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge34, %%9, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__9&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__15 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%input_matrix, i64 %%16, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__16 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__15))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__17 = (float )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__17, *(int*)(&llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%12, %%storemerge34, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(llvm_cbe_tmp__12&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__19 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%kernel, i64 %%20, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__20 = (float *)(&llvm_cbe_kernel[(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__21 = (float )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__21, *(int*)(&llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fmul float %%18, %%22, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__22 = (float )((float )(llvm_cbe_tmp__17 * llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__22, *(int*)(&llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = fadd float %%14, %%23, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__23 = (float )((float )(llvm_cbe_tmp__13 + llvm_cbe_tmp__22));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__23, *(int*)(&llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%6, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_60_count);
  *llvm_cbe_tmp__6 = llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge34, 1, !dbg !19 for 0x%I64xth hint within @Conv2d1  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__24) < ((signed int )llvm_cbe_tmp__7))) {
    llvm_cbe_tmp__13__PHI_TEMPORARY = (float )llvm_cbe_tmp__23;   /* for PHI node */
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe_tmp__32;
  } else {
    goto llvm_cbe_tmp__33;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__30:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d1}\n");
  return;
}


void Conv2d2(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  float *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  float llvm_cbe_tmp__40;
  float llvm_cbe_tmp__40__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  float llvm_cbe_tmp__45;
  float llvm_cbe_tmp__45__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  float *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  float llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  float *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  float llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  float llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  float llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d2\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%33, %%32  for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 26, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__34 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__34&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__60;

llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge8, 1, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
  if (((llvm_cbe_tmp__59&4294967295U) == (26u&4294967295U))) {
    goto llvm_cbe_tmp__62;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__60:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%31, %%30  for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__37 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%out_matrix, i64 %%5, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__38 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__37))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%6, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_112_count);
  *llvm_cbe_tmp__38 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge17, 3, !dbg !19 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
  llvm_cbe_tmp__40__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__63:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__58&4294967295ull)));
  if (((llvm_cbe_tmp__58&4294967295U) == (26u&4294967295U))) {
    goto llvm_cbe_tmp__61;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__58;   /* for PHI node */
    goto llvm_cbe_tmp__60;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%3 ], [ %%24, %%27  for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__40 = (float )llvm_cbe_tmp__40__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__40);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__55);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%storemerge8, %%3 ], [ %%28, %%27  for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",llvm_cbe_tmp__57);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge25, 28, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%storemerge25, %%storemerge8, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__42 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__42&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, 3, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__43 = (unsigned int )((unsigned int )(llvm_cbe_tmp__42&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__43&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%11, %%storemerge17, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(llvm_cbe_tmp__43&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__44&4294967295ull)));
  llvm_cbe_tmp__45__PHI_TEMPORARY = (float )llvm_cbe_tmp__40;   /* for PHI node */
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge17;   /* for PHI node */
  goto llvm_cbe_tmp__64;

llvm_cbe_tmp__65:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge25, 1, !dbg !19 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__57) < ((signed int )llvm_cbe_tmp__35))) {
    llvm_cbe_tmp__40__PHI_TEMPORARY = (float )llvm_cbe_tmp__55;   /* for PHI node */
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__57;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__63;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__64:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi float [ %%8, %%.preheader ], [ %%24, %%13 ], !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__45 = (float )llvm_cbe_tmp__45__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__45);
printf("\n = %f",llvm_cbe_tmp__40);
printf("\n = %f",llvm_cbe_tmp__55);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ %%storemerge17, %%.preheader ], [ %%25, %%13  for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge34, %%9, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__41&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__46&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__47 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%input_matrix, i64 %%16, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__48 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__47))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__47));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__49 = (float )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__49, *(int*)(&llvm_cbe_tmp__49));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%12, %%storemerge34, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__50 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__50&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__51 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%kernel, i64 %%20, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__52 = (float *)(&llvm_cbe_kernel[(((signed long long )llvm_cbe_tmp__51))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__51));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__53 = (float )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__53, *(int*)(&llvm_cbe_tmp__53));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fmul float %%18, %%22, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__54 = (float )((float )(llvm_cbe_tmp__49 * llvm_cbe_tmp__53));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__54, *(int*)(&llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = fadd float %%14, %%23, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__55 = (float )((float )(llvm_cbe_tmp__45 + llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__55, *(int*)(&llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%6, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_132_count);
  *llvm_cbe_tmp__38 = llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge34, 1, !dbg !19 for 0x%I64xth hint within @Conv2d2  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__56) < ((signed int )llvm_cbe_tmp__39))) {
    llvm_cbe_tmp__45__PHI_TEMPORARY = (float )llvm_cbe_tmp__55;   /* for PHI node */
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__56;   /* for PHI node */
    goto llvm_cbe_tmp__64;
  } else {
    goto llvm_cbe_tmp__65;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__62:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d2}\n");
  return;
}


void Conv2d3(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  float *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  float llvm_cbe_tmp__72;
  float llvm_cbe_tmp__72__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  float llvm_cbe_tmp__77;
  float llvm_cbe_tmp__77__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned long long llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  float *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  float llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  float *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  float llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  float llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d3\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%33, %%32  for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__91);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 24, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__66 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(24u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__66&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__67 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__67&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__92;

llvm_cbe_tmp__93:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge8, 1, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
  if (((llvm_cbe_tmp__91&4294967295U) == (24u&4294967295U))) {
    goto llvm_cbe_tmp__94;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__91;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__92:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%31, %%30  for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__90);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__66&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__68&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__69 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%out_matrix, i64 %%5, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__70 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__69))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%6, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_184_count);
  *llvm_cbe_tmp__70 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge17, 3, !dbg !19 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__71 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__71&4294967295ull)));
  llvm_cbe_tmp__72__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__95:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__90 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__90&4294967295ull)));
  if (((llvm_cbe_tmp__90&4294967295U) == (24u&4294967295U))) {
    goto llvm_cbe_tmp__93;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__90;   /* for PHI node */
    goto llvm_cbe_tmp__92;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%3 ], [ %%24, %%27  for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__72 = (float )llvm_cbe_tmp__72__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__72);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%storemerge8, %%3 ], [ %%28, %%27  for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge25, 26, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__73 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__73&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%storemerge25, %%storemerge8, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, 3, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__75 = (unsigned int )((unsigned int )(llvm_cbe_tmp__74&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__75&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%11, %%storemerge17, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__76 = (unsigned int )((unsigned int )(llvm_cbe_tmp__75&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__76&4294967295ull)));
  llvm_cbe_tmp__77__PHI_TEMPORARY = (float )llvm_cbe_tmp__72;   /* for PHI node */
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge17;   /* for PHI node */
  goto llvm_cbe_tmp__96;

llvm_cbe_tmp__97:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge25, 1, !dbg !19 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__89 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__89&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__89) < ((signed int )llvm_cbe_tmp__67))) {
    llvm_cbe_tmp__72__PHI_TEMPORARY = (float )llvm_cbe_tmp__87;   /* for PHI node */
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__89;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__95;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__96:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi float [ %%8, %%.preheader ], [ %%24, %%13 ], !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__77 = (float )llvm_cbe_tmp__77__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__77);
printf("\n = %f",llvm_cbe_tmp__72);
printf("\n = %f",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ %%storemerge17, %%.preheader ], [ %%25, %%13  for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",llvm_cbe_tmp__88);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge34, %%9, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__78 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__73&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__78&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__79 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%input_matrix, i64 %%16, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__80 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__79))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__79));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__81 = (float )*llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__81, *(int*)(&llvm_cbe_tmp__81));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%12, %%storemerge34, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__82 = (unsigned int )((unsigned int )(llvm_cbe_tmp__76&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__82&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__83 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%kernel, i64 %%20, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__84 = (float *)(&llvm_cbe_kernel[(((signed long long )llvm_cbe_tmp__83))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__83));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__85 = (float )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__85, *(int*)(&llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fmul float %%18, %%22, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__86 = (float )((float )(llvm_cbe_tmp__81 * llvm_cbe_tmp__85));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = fadd float %%14, %%23, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__87 = (float )((float )(llvm_cbe_tmp__77 + llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__87, *(int*)(&llvm_cbe_tmp__87));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%6, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_204_count);
  *llvm_cbe_tmp__70 = llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge34, 1, !dbg !19 for 0x%I64xth hint within @Conv2d3  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__88 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__88&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__88) < ((signed int )llvm_cbe_tmp__71))) {
    llvm_cbe_tmp__77__PHI_TEMPORARY = (float )llvm_cbe_tmp__87;   /* for PHI node */
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__88;   /* for PHI node */
    goto llvm_cbe_tmp__96;
  } else {
    goto llvm_cbe_tmp__97;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__94:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d3}\n");
  return;
}


void Relu1(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  float *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  float llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  double llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  double llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  float llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  float llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  float *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  unsigned int llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Relu1\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__107;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__107:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%10, %%1  for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__106);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__98 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__99 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__98))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__98));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__100 = (float )*llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__100, *(int*)(&llvm_cbe_tmp__100));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = fpext float %%4 to double, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__101 = (double )((double )llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__101, *(long long*)(&llvm_cbe_tmp__101));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fmul double %%5, 5.000000e-02, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__102 = (double )llvm_cbe_tmp__101 * 0x1.999999999999ap-5;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__102, *(long long*)(&llvm_cbe_tmp__102));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fptrunc double %%6 to float, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__103 = (float )((float )llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__103, *(int*)(&llvm_cbe_tmp__103));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call float @max(float %%4, float %%7), !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__104 = (float ) /*tail*/ max(llvm_cbe_tmp__100, llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__100, *(int*)(&llvm_cbe_tmp__100));
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__103, *(int*)(&llvm_cbe_tmp__103));
printf("\nReturn  = %f",llvm_cbe_tmp__104);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__105 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__98))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__98));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_246_count);
  *llvm_cbe_tmp__105 = llvm_cbe_tmp__104;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @Relu1  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__106 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__106&4294967295ull)));
  if (((llvm_cbe_tmp__106&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__108;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__106;   /* for PHI node */
    goto llvm_cbe_tmp__107;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__108:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Relu1}\n");
  return;
}


void Relu2(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  float *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  float llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  double llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  double llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  float llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  float llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  float *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Relu2\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__118;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%10, %%1  for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__117);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__109 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__110 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__109))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__111 = (float )*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__111, *(int*)(&llvm_cbe_tmp__111));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = fpext float %%4 to double, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__112 = (double )((double )llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__112, *(long long*)(&llvm_cbe_tmp__112));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fmul double %%5, 5.000000e-02, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__113 = (double )llvm_cbe_tmp__112 * 0x1.999999999999ap-5;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__113, *(long long*)(&llvm_cbe_tmp__113));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fptrunc double %%6 to float, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__114 = (float )((float )llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__114, *(int*)(&llvm_cbe_tmp__114));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call float @max(float %%4, float %%7), !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__115 = (float ) /*tail*/ max(llvm_cbe_tmp__111, llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__111, *(int*)(&llvm_cbe_tmp__111));
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__114, *(int*)(&llvm_cbe_tmp__114));
printf("\nReturn  = %f",llvm_cbe_tmp__115);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__116 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__109))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_276_count);
  *llvm_cbe_tmp__116 = llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @Relu2  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__117 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__117&4294967295ull)));
  if (((llvm_cbe_tmp__117&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__119;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__117;   /* for PHI node */
    goto llvm_cbe_tmp__118;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__119:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Relu2}\n");
  return;
}


void MatrixExtensionImproved(float *llvm_cbe_input_matrix1, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned int llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned long long llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  float *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  float llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  float *llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  unsigned int llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixExtensionImproved\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%10, %%9  for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__127);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge3, 24, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__120 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(24u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__120&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__128;

llvm_cbe_tmp__129:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__127 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__127&4294967295ull)));
  if (((llvm_cbe_tmp__127&4294967295U) == (24u&4294967295U))) {
    goto llvm_cbe_tmp__130;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__127;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%8, %%2  for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%storemerge12, %%1, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__121 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__120&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__121&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%3 to i64, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__122 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%input_matrix1, i64 %%4, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__123 = (float *)(&llvm_cbe_input_matrix1[(((signed long long )llvm_cbe_tmp__122))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__122));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__124 = (float )*llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__124, *(int*)(&llvm_cbe_tmp__124));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%output_matrix, i64 %%4, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__125 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__122))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__122));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_307_count);
  *llvm_cbe_tmp__125 = llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixExtensionImproved  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__126 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__126&4294967295ull)));
  if (((llvm_cbe_tmp__126&4294967295U) == (24u&4294967295U))) {
    goto llvm_cbe_tmp__129;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__126;   /* for PHI node */
    goto llvm_cbe_tmp__128;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__130:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixExtensionImproved}\n");
  return;
}


void MatrixMultiply1(float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  float *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  float llvm_cbe_tmp__133;
  float llvm_cbe_tmp__133__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned long long llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  float *llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  float llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned int llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  float *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  float llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  float llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  float llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned int llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixMultiply1\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__146;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__146:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__145);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__131 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__132 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__131))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__131));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%3, align 4, !dbg !18 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_339_count);
  *llvm_cbe_tmp__132 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  llvm_cbe_tmp__133__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__147;

llvm_cbe_tmp__148:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__145 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__145&4294967295ull)));
  if (((llvm_cbe_tmp__145&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__149;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__145;   /* for PHI node */
    goto llvm_cbe_tmp__146;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__147:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi float [ 0.000000e+00, %%1 ], [ %%15, %%4 ], !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__133 = (float )llvm_cbe_tmp__133__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__133);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__143);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%1 ], [ %%16, %%4  for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__144);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__134 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%input_matrix, i64 %%6, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__135 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__134))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__134));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__136 = (float )*llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__136, *(int*)(&llvm_cbe_tmp__136));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge12, 180, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__137 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) * ((unsigned int )(180u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__137&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge3, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__138 = (unsigned int )((unsigned int )(llvm_cbe_tmp__137&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__138&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__139 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%para_layer, i64 %%11, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__140 = (float *)(&llvm_cbe_para_layer[(((signed long long )llvm_cbe_tmp__139))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__139));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__141 = (float )*llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__141, *(int*)(&llvm_cbe_tmp__141));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul float %%8, %%13, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__142 = (float )((float )(llvm_cbe_tmp__136 * llvm_cbe_tmp__141));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__142, *(int*)(&llvm_cbe_tmp__142));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fadd float %%5, %%14, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__143 = (float )((float )(llvm_cbe_tmp__133 + llvm_cbe_tmp__142));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__143, *(int*)(&llvm_cbe_tmp__143));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_357_count);
  *llvm_cbe_tmp__132 = llvm_cbe_tmp__143;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply1  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__144 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__144&4294967295ull)));
  if (((llvm_cbe_tmp__144&4294967295U) == (576u&4294967295U))) {
    goto llvm_cbe_tmp__148;
  } else {
    llvm_cbe_tmp__133__PHI_TEMPORARY = (float )llvm_cbe_tmp__143;   /* for PHI node */
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__144;   /* for PHI node */
    goto llvm_cbe_tmp__147;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__149:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixMultiply1}\n");
  return;
}


void MatrixMultiply2(float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  unsigned long long llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  float *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  float llvm_cbe_tmp__152;
  float llvm_cbe_tmp__152__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  unsigned long long llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  float *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  float llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  unsigned int llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned int llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned long long llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  float *llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  float llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  float llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  float llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  unsigned int llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  unsigned int llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixMultiply2\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__165;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__165:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__164);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__150 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__151 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__150))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__150));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%3, align 4, !dbg !18 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_390_count);
  *llvm_cbe_tmp__151 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  llvm_cbe_tmp__152__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__166;

llvm_cbe_tmp__167:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__164 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__164&4294967295ull)));
  if (((llvm_cbe_tmp__164&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__168;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__164;   /* for PHI node */
    goto llvm_cbe_tmp__165;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__166:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi float [ 0.000000e+00, %%1 ], [ %%15, %%4 ], !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__152 = (float )llvm_cbe_tmp__152__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__152);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__162);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%1 ], [ %%16, %%4  for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__163);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__153 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__153);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%input_matrix, i64 %%6, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__154 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__153))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__153));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_400_count);
  llvm_cbe_tmp__155 = (float )*llvm_cbe_tmp__154;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__155, *(int*)(&llvm_cbe_tmp__155));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge12, 45, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_401_count);
  llvm_cbe_tmp__156 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) * ((unsigned int )(45u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__156&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge3, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__157 = (unsigned int )((unsigned int )(llvm_cbe_tmp__156&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__157&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__158 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__158);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%para_layer, i64 %%11, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__159 = (float *)(&llvm_cbe_para_layer[(((signed long long )llvm_cbe_tmp__158))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__158));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__160 = (float )*llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__160, *(int*)(&llvm_cbe_tmp__160));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul float %%8, %%13, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__161 = (float )((float )(llvm_cbe_tmp__155 * llvm_cbe_tmp__160));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__161, *(int*)(&llvm_cbe_tmp__161));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fadd float %%5, %%14, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_407_count);
  llvm_cbe_tmp__162 = (float )((float )(llvm_cbe_tmp__152 + llvm_cbe_tmp__161));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__162, *(int*)(&llvm_cbe_tmp__162));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_408_count);
  *llvm_cbe_tmp__151 = llvm_cbe_tmp__162;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply2  --> \n", ++aesl_llvm_cbe_409_count);
  llvm_cbe_tmp__163 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__163&4294967295ull)));
  if (((llvm_cbe_tmp__163&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__167;
  } else {
    llvm_cbe_tmp__152__PHI_TEMPORARY = (float )llvm_cbe_tmp__162;   /* for PHI node */
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__163;   /* for PHI node */
    goto llvm_cbe_tmp__166;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__168:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixMultiply2}\n");
  return;
}


void MatrixMultiply3(float *llvm_cbe_input_matrix, float *llvm_cbe_para_layer, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  float *llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  float llvm_cbe_tmp__171;
  float llvm_cbe_tmp__171__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  float *llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  float llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned int llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned int llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  float *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  float llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  float llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  float llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  unsigned int llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  unsigned int llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixMultiply3\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__184;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__184:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__183);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__169 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__170 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__169))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__169));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%3, align 4, !dbg !18 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_441_count);
  *llvm_cbe_tmp__170 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
  llvm_cbe_tmp__171__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__185;

llvm_cbe_tmp__186:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_467_count);
  llvm_cbe_tmp__183 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__183&4294967295ull)));
  if (((llvm_cbe_tmp__183&4294967295U) == (10u&4294967295U))) {
    goto llvm_cbe_tmp__187;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__183;   /* for PHI node */
    goto llvm_cbe_tmp__184;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__185:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi float [ 0.000000e+00, %%1 ], [ %%15, %%4 ], !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_448_count);
  llvm_cbe_tmp__171 = (float )llvm_cbe_tmp__171__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__171);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__181);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%1 ], [ %%16, %%4  for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__182);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__172 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%input_matrix, i64 %%6, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__173 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__172))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__172));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__174 = (float )*llvm_cbe_tmp__173;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__174, *(int*)(&llvm_cbe_tmp__174));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge12, 10, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__175 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__175&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%9, %%storemerge3, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__176 = (unsigned int )((unsigned int )(llvm_cbe_tmp__175&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__176&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__177 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__177);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%para_layer, i64 %%11, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__178 = (float *)(&llvm_cbe_para_layer[(((signed long long )llvm_cbe_tmp__177))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__177));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__179 = (float )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__179, *(int*)(&llvm_cbe_tmp__179));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul float %%8, %%13, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__180 = (float )((float )(llvm_cbe_tmp__174 * llvm_cbe_tmp__179));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__180, *(int*)(&llvm_cbe_tmp__180));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fadd float %%5, %%14, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__181 = (float )((float )(llvm_cbe_tmp__171 + llvm_cbe_tmp__180));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__181, *(int*)(&llvm_cbe_tmp__181));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_459_count);
  *llvm_cbe_tmp__170 = llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixMultiply3  --> \n", ++aesl_llvm_cbe_460_count);
  llvm_cbe_tmp__182 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__182&4294967295ull)));
  if (((llvm_cbe_tmp__182&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__186;
  } else {
    llvm_cbe_tmp__171__PHI_TEMPORARY = (float )llvm_cbe_tmp__181;   /* for PHI node */
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__182;   /* for PHI node */
    goto llvm_cbe_tmp__185;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__187:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixMultiply3}\n");
  return;
}


void Conv2d_b1(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  unsigned int llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  unsigned int llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  float *llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  unsigned int llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  unsigned int llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  unsigned long long llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  float *llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  float llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  float llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  float llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  float llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  unsigned int llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  unsigned int llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  float *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  float llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  float *llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  float llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  float llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  float llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  unsigned int llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  unsigned long long llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  float *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  float llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  float *llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  float llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  float llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  float llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  unsigned int llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  unsigned int llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  unsigned int llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  unsigned long long llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  float *llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  float llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  float *llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  float llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  float llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  float llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  unsigned int llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  unsigned long long llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  float *llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  float llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  float *llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  float llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  float llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  float llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  unsigned int llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  float *llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  float llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  float *llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  float llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  float llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  float llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned int llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  unsigned int llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  unsigned int llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  float *llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  float llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  float *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  float llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  float llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  float llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  unsigned int llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  unsigned long long llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  float *llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  float llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  float *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  float llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  float llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  float llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned int llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  float *llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  float llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  float *llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  float llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  float llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  float llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d_b1\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%31, %%83  for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__218);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__188 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__188&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__270:
  if (((llvm_cbe_tmp__218&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__271;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__218;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%13, %%.preheader  for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__200);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_502_count);
  llvm_cbe_tmp__189 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__188&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__189&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_503_count);
  llvm_cbe_tmp__190 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__189);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds float* %%out_matrix, i64 %%3, !dbg !18 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__191 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__190))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__190));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%4, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_505_count);
  *llvm_cbe_tmp__191 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul nsw i32 %%storemerge8, 26, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_506_count);
  llvm_cbe_tmp__192 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__192&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge17, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_507_count);
  llvm_cbe_tmp__193 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__192&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__193&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_508_count);
  llvm_cbe_tmp__194 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__194);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_509_count);
  llvm_cbe_tmp__195 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__194))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__194));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_510_count);
  llvm_cbe_tmp__196 = (float )*llvm_cbe_tmp__195;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__196, *(int*)(&llvm_cbe_tmp__196));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%kernel, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_511_count);
  llvm_cbe_tmp__197 = (float )*llvm_cbe_kernel;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__197, *(int*)(&llvm_cbe_tmp__197));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fmul float %%9, %%10, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_512_count);
  llvm_cbe_tmp__198 = (float )((float )(llvm_cbe_tmp__196 * llvm_cbe_tmp__197));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__198, *(int*)(&llvm_cbe_tmp__198));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fadd float %%11, 0.000000e+00, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_513_count);
  llvm_cbe_tmp__199 = (float )((float )(llvm_cbe_tmp__198 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__199, *(int*)(&llvm_cbe_tmp__199));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_514_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__199;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_515_count);
  llvm_cbe_tmp__200 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__200&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%13, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__201 = (unsigned int )((unsigned int )(llvm_cbe_tmp__200&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__192&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__201&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%14 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__202 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%input_matrix, i64 %%15, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__203 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__202))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__202));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_519_count);
  llvm_cbe_tmp__204 = (float )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__204, *(int*)(&llvm_cbe_tmp__204));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds float* %%kernel, i64 1, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__205 = (float *)(&llvm_cbe_kernel[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* %%18, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__206 = (float )*llvm_cbe_tmp__205;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__206, *(int*)(&llvm_cbe_tmp__206));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fmul float %%17, %%19, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_522_count);
  llvm_cbe_tmp__207 = (float )((float )(llvm_cbe_tmp__204 * llvm_cbe_tmp__206));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__207, *(int*)(&llvm_cbe_tmp__207));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fadd float %%12, %%20, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_523_count);
  llvm_cbe_tmp__208 = (float )((float )(llvm_cbe_tmp__199 + llvm_cbe_tmp__207));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__208, *(int*)(&llvm_cbe_tmp__208));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_524_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__208;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__208);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge17, 2, !dbg !19 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_525_count);
  llvm_cbe_tmp__209 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__209&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%22, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_526_count);
  llvm_cbe_tmp__210 = (unsigned int )((unsigned int )(llvm_cbe_tmp__209&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__192&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__210&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_527_count);
  llvm_cbe_tmp__211 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%input_matrix, i64 %%24, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_528_count);
  llvm_cbe_tmp__212 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__211))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__211));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_529_count);
  llvm_cbe_tmp__213 = (float )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__213, *(int*)(&llvm_cbe_tmp__213));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds float* %%kernel, i64 2, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_530_count);
  llvm_cbe_tmp__214 = (float *)(&llvm_cbe_kernel[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__215 = (float )*llvm_cbe_tmp__214;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__215, *(int*)(&llvm_cbe_tmp__215));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fmul float %%26, %%28, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_532_count);
  llvm_cbe_tmp__216 = (float )((float )(llvm_cbe_tmp__213 * llvm_cbe_tmp__215));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__216, *(int*)(&llvm_cbe_tmp__216));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fadd float %%21, %%29, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_533_count);
  llvm_cbe_tmp__217 = (float )((float )(llvm_cbe_tmp__208 + llvm_cbe_tmp__216));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__217, *(int*)(&llvm_cbe_tmp__217));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_534_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__217;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__217);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge8, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_535_count);
  llvm_cbe_tmp__218 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__218&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul nsw i32 %%31, 26, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_536_count);
  llvm_cbe_tmp__219 = (unsigned int )((unsigned int )(llvm_cbe_tmp__218&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__219&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge17, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_537_count);
  llvm_cbe_tmp__220 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__219&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__220&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sext i32 %%33 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_538_count);
  llvm_cbe_tmp__221 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__221);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds float* %%input_matrix, i64 %%34, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_539_count);
  llvm_cbe_tmp__222 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__221))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__221));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%35, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__223 = (float )*llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__223, *(int*)(&llvm_cbe_tmp__223));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds float* %%kernel, i64 24, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_541_count);
  llvm_cbe_tmp__224 = (float *)(&llvm_cbe_kernel[(((signed long long )24ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__225 = (float )*llvm_cbe_tmp__224;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__225, *(int*)(&llvm_cbe_tmp__225));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fmul float %%36, %%38, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_543_count);
  llvm_cbe_tmp__226 = (float )((float )(llvm_cbe_tmp__223 * llvm_cbe_tmp__225));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__226, *(int*)(&llvm_cbe_tmp__226));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fadd float %%30, %%39, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__227 = (float )((float )(llvm_cbe_tmp__217 + llvm_cbe_tmp__226));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__227, *(int*)(&llvm_cbe_tmp__227));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%40, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_545_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__227;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__227);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%13, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_546_count);
  llvm_cbe_tmp__228 = (unsigned int )((unsigned int )(llvm_cbe_tmp__200&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__219&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__228&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = sext i32 %%41 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__229 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__228);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds float* %%input_matrix, i64 %%42, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__230 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__229))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__229));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load float* %%43, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__231 = (float )*llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__231, *(int*)(&llvm_cbe_tmp__231));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds float* %%kernel, i64 25, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__232 = (float *)(&llvm_cbe_kernel[(((signed long long )25ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%45, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_551_count);
  llvm_cbe_tmp__233 = (float )*llvm_cbe_tmp__232;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__233, *(int*)(&llvm_cbe_tmp__233));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fmul float %%44, %%46, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_552_count);
  llvm_cbe_tmp__234 = (float )((float )(llvm_cbe_tmp__231 * llvm_cbe_tmp__233));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__234, *(int*)(&llvm_cbe_tmp__234));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = fadd float %%40, %%47, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_553_count);
  llvm_cbe_tmp__235 = (float )((float )(llvm_cbe_tmp__227 + llvm_cbe_tmp__234));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__235, *(int*)(&llvm_cbe_tmp__235));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%48, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_554_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__235;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__235);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%22, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_555_count);
  llvm_cbe_tmp__236 = (unsigned int )((unsigned int )(llvm_cbe_tmp__209&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__219&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__236&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%49 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_556_count);
  llvm_cbe_tmp__237 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds float* %%input_matrix, i64 %%50, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_557_count);
  llvm_cbe_tmp__238 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__237))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__237));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* %%51, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_558_count);
  llvm_cbe_tmp__239 = (float )*llvm_cbe_tmp__238;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__239, *(int*)(&llvm_cbe_tmp__239));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds float* %%kernel, i64 26, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_559_count);
  llvm_cbe_tmp__240 = (float *)(&llvm_cbe_kernel[(((signed long long )26ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__241 = (float )*llvm_cbe_tmp__240;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__241, *(int*)(&llvm_cbe_tmp__241));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fmul float %%52, %%54, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__242 = (float )((float )(llvm_cbe_tmp__239 * llvm_cbe_tmp__241));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__242, *(int*)(&llvm_cbe_tmp__242));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fadd float %%48, %%55, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__243 = (float )((float )(llvm_cbe_tmp__235 + llvm_cbe_tmp__242));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__243, *(int*)(&llvm_cbe_tmp__243));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%56, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_563_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__243);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = mul i32 %%storemerge8, 26, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__244 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__244&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%57, 52, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_565_count);
  llvm_cbe_tmp__245 = (unsigned int )((unsigned int )(llvm_cbe_tmp__244&4294967295ull)) + ((unsigned int )(52u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__245&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add nsw i32 %%storemerge17, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_566_count);
  llvm_cbe_tmp__246 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__245&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__246&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%59 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_567_count);
  llvm_cbe_tmp__247 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds float* %%input_matrix, i64 %%60, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_568_count);
  llvm_cbe_tmp__248 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__247))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__247));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load float* %%61, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_569_count);
  llvm_cbe_tmp__249 = (float )*llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__249, *(int*)(&llvm_cbe_tmp__249));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds float* %%kernel, i64 48, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_570_count);
  llvm_cbe_tmp__250 = (float *)(&llvm_cbe_kernel[(((signed long long )48ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load float* %%63, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__251 = (float )*llvm_cbe_tmp__250;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__251, *(int*)(&llvm_cbe_tmp__251));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = fmul float %%62, %%64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_572_count);
  llvm_cbe_tmp__252 = (float )((float )(llvm_cbe_tmp__249 * llvm_cbe_tmp__251));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__252, *(int*)(&llvm_cbe_tmp__252));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fadd float %%56, %%65, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_573_count);
  llvm_cbe_tmp__253 = (float )((float )(llvm_cbe_tmp__243 + llvm_cbe_tmp__252));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__253, *(int*)(&llvm_cbe_tmp__253));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%66, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_574_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add nsw i32 %%13, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__254 = (unsigned int )((unsigned int )(llvm_cbe_tmp__200&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__245&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__254&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = sext i32 %%67 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_576_count);
  llvm_cbe_tmp__255 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__254);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds float* %%input_matrix, i64 %%68, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__256 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__255))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__255));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* %%69, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__257 = (float )*llvm_cbe_tmp__256;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__257, *(int*)(&llvm_cbe_tmp__257));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds float* %%kernel, i64 49, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__258 = (float *)(&llvm_cbe_kernel[(((signed long long )49ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load float* %%71, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_580_count);
  llvm_cbe_tmp__259 = (float )*llvm_cbe_tmp__258;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__259, *(int*)(&llvm_cbe_tmp__259));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fmul float %%70, %%72, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_581_count);
  llvm_cbe_tmp__260 = (float )((float )(llvm_cbe_tmp__257 * llvm_cbe_tmp__259));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__260, *(int*)(&llvm_cbe_tmp__260));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fadd float %%66, %%73, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__261 = (float )((float )(llvm_cbe_tmp__253 + llvm_cbe_tmp__260));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__261, *(int*)(&llvm_cbe_tmp__261));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_583_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__261;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add nsw i32 %%22, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__262 = (unsigned int )((unsigned int )(llvm_cbe_tmp__209&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__245&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__262&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = sext i32 %%75 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_585_count);
  llvm_cbe_tmp__263 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__263);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds float* %%input_matrix, i64 %%76, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__264 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__263))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__263));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_587_count);
  llvm_cbe_tmp__265 = (float )*llvm_cbe_tmp__264;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__265, *(int*)(&llvm_cbe_tmp__265));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds float* %%kernel, i64 50, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_588_count);
  llvm_cbe_tmp__266 = (float *)(&llvm_cbe_kernel[(((signed long long )50ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* %%79, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__267 = (float )*llvm_cbe_tmp__266;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__267, *(int*)(&llvm_cbe_tmp__267));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = fmul float %%78, %%80, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__268 = (float )((float )(llvm_cbe_tmp__265 * llvm_cbe_tmp__267));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__268, *(int*)(&llvm_cbe_tmp__268));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fadd float %%74, %%81, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__269 = (float )((float )(llvm_cbe_tmp__261 + llvm_cbe_tmp__268));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__269, *(int*)(&llvm_cbe_tmp__269));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%82, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b1  --> \n", ++aesl_llvm_cbe_592_count);
  *llvm_cbe_tmp__191 = llvm_cbe_tmp__269;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__269);
  if (((llvm_cbe_tmp__200&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__270;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__200;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__271:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d_b1}\n");
  return;
}


void Conv2d_b2(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  unsigned int llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  unsigned int llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  unsigned int llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  unsigned long long llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  float *llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  unsigned int llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  float llvm_cbe_tmp__278;
  float llvm_cbe_tmp__278__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  unsigned int llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  unsigned int llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  unsigned int llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  unsigned int llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  float llvm_cbe_tmp__283;
  float llvm_cbe_tmp__283__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  unsigned int llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  float *llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  float llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  unsigned int llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  unsigned long long llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  float *llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  float llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  float llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  float llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  unsigned int llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  unsigned int llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  unsigned int llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  unsigned int llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d_b2\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%33, %%32  for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__297);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 26, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_620_count);
  llvm_cbe_tmp__272 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__272&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_621_count);
  llvm_cbe_tmp__273 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__273&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__298;

llvm_cbe_tmp__299:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge8, 1, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_665_count);
  llvm_cbe_tmp__297 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__297&4294967295ull)));
  if (((llvm_cbe_tmp__297&4294967295U) == (26u&4294967295U))) {
    goto llvm_cbe_tmp__300;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__297;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__298:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%31, %%30  for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__296);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_623_count);
  llvm_cbe_tmp__274 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__272&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__274&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_624_count);
  llvm_cbe_tmp__275 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%out_matrix, i64 %%5, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__276 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__275))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__275));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%6, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_626_count);
  *llvm_cbe_tmp__276 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge17, 3, !dbg !19 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__277 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__277&4294967295ull)));
  llvm_cbe_tmp__278__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__301:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_663_count);
  llvm_cbe_tmp__296 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__296&4294967295ull)));
  if (((llvm_cbe_tmp__296&4294967295U) == (26u&4294967295U))) {
    goto llvm_cbe_tmp__299;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__296;   /* for PHI node */
    goto llvm_cbe_tmp__298;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%3 ], [ %%24, %%27  for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__278 = (float )llvm_cbe_tmp__278__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__278);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__293);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%storemerge8, %%3 ], [ %%28, %%27  for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",llvm_cbe_tmp__295);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge25, 28, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__279 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__279&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%storemerge25, %%storemerge8, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__280 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__280&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, 3, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_632_count);
  llvm_cbe_tmp__281 = (unsigned int )((unsigned int )(llvm_cbe_tmp__280&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__281&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%11, %%storemerge17, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_633_count);
  llvm_cbe_tmp__282 = (unsigned int )((unsigned int )(llvm_cbe_tmp__281&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__282&4294967295ull)));
  llvm_cbe_tmp__283__PHI_TEMPORARY = (float )llvm_cbe_tmp__278;   /* for PHI node */
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge17;   /* for PHI node */
  goto llvm_cbe_tmp__302;

llvm_cbe_tmp__303:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge25, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_655_count);
  llvm_cbe_tmp__295 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__295&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__295) < ((signed int )llvm_cbe_tmp__273))) {
    llvm_cbe_tmp__278__PHI_TEMPORARY = (float )llvm_cbe_tmp__293;   /* for PHI node */
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__295;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__301;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__302:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi float [ %%8, %%.preheader ], [ %%24, %%13 ], !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_635_count);
  llvm_cbe_tmp__283 = (float )llvm_cbe_tmp__283__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__283);
printf("\n = %f",llvm_cbe_tmp__278);
printf("\n = %f",llvm_cbe_tmp__293);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ %%storemerge17, %%.preheader ], [ %%25, %%13  for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",llvm_cbe_tmp__294);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge34, %%9, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_636_count);
  llvm_cbe_tmp__284 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__279&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__284&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_637_count);
  llvm_cbe_tmp__285 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%input_matrix, i64 %%16, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_638_count);
  llvm_cbe_tmp__286 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__285))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__285));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_639_count);
  llvm_cbe_tmp__287 = (float )*llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__287, *(int*)(&llvm_cbe_tmp__287));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%12, %%storemerge34, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_640_count);
  llvm_cbe_tmp__288 = (unsigned int )((unsigned int )(llvm_cbe_tmp__282&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__288&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_641_count);
  llvm_cbe_tmp__289 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__289);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%kernel, i64 %%20, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_642_count);
  llvm_cbe_tmp__290 = (float *)(&llvm_cbe_kernel[(((signed long long )llvm_cbe_tmp__289))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__289));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_643_count);
  llvm_cbe_tmp__291 = (float )*llvm_cbe_tmp__290;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__291, *(int*)(&llvm_cbe_tmp__291));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fmul float %%18, %%22, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_644_count);
  llvm_cbe_tmp__292 = (float )((float )(llvm_cbe_tmp__287 * llvm_cbe_tmp__291));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__292, *(int*)(&llvm_cbe_tmp__292));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = fadd float %%14, %%23, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_645_count);
  llvm_cbe_tmp__293 = (float )((float )(llvm_cbe_tmp__283 + llvm_cbe_tmp__292));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__293, *(int*)(&llvm_cbe_tmp__293));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%6, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_646_count);
  *llvm_cbe_tmp__276 = llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge34, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b2  --> \n", ++aesl_llvm_cbe_647_count);
  llvm_cbe_tmp__294 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__294&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__294) < ((signed int )llvm_cbe_tmp__277))) {
    llvm_cbe_tmp__283__PHI_TEMPORARY = (float )llvm_cbe_tmp__293;   /* for PHI node */
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__294;   /* for PHI node */
    goto llvm_cbe_tmp__302;
  } else {
    goto llvm_cbe_tmp__303;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__300:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d_b2}\n");
  return;
}


void Conv2d_b3(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  unsigned int llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  unsigned int llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  unsigned long long llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  float *llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  unsigned int llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  unsigned int llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  unsigned long long llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  float *llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  float llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  float llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  float llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  float llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  unsigned int llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  unsigned int llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  unsigned long long llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  float *llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  float llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  float *llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  float llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  float llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  float llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  unsigned int llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  unsigned int llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  unsigned long long llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  float *llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  float llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  float *llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  float llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  float llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  float llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  unsigned int llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  unsigned int llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned int llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  unsigned long long llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  float *llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  float llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  float *llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  float llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  float llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  float llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  unsigned int llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  unsigned long long llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  float *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  float llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  float *llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  float llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  float llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  float llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  unsigned int llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  unsigned long long llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  float *llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  float llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  float *llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  float llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  float llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  float llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  unsigned int llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  unsigned int llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  unsigned int llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  unsigned long long llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  float *llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  float llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  float *llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  float llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  float llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  float llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  unsigned int llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  unsigned long long llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  float *llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  float llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  float *llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  float llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  float llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  float llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  unsigned int llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  unsigned long long llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  float *llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  float llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  float *llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  float llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  float llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  float llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d_b3\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%31, %%83  for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__334);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_692_count);
  llvm_cbe_tmp__304 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__304&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__386:
  if (((llvm_cbe_tmp__334&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__387;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__334;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%13, %%.preheader  for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__316);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_694_count);
  llvm_cbe_tmp__305 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__304&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__305&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_695_count);
  llvm_cbe_tmp__306 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__306);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds float* %%out_matrix, i64 %%3, !dbg !18 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_696_count);
  llvm_cbe_tmp__307 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__306))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__306));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%4, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_697_count);
  *llvm_cbe_tmp__307 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul nsw i32 %%storemerge8, 28, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__308 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__308&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge17, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_699_count);
  llvm_cbe_tmp__309 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__308&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__309&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_700_count);
  llvm_cbe_tmp__310 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__311 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__310))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__310));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__312 = (float )*llvm_cbe_tmp__311;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__312, *(int*)(&llvm_cbe_tmp__312));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%kernel, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__313 = (float )*llvm_cbe_kernel;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__313, *(int*)(&llvm_cbe_tmp__313));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fmul float %%9, %%10, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__314 = (float )((float )(llvm_cbe_tmp__312 * llvm_cbe_tmp__313));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__314, *(int*)(&llvm_cbe_tmp__314));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fadd float %%11, 0.000000e+00, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__315 = (float )((float )(llvm_cbe_tmp__314 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__315, *(int*)(&llvm_cbe_tmp__315));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_706_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__315;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__316 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__316&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%13, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_708_count);
  llvm_cbe_tmp__317 = (unsigned int )((unsigned int )(llvm_cbe_tmp__316&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__308&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__317&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%14 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__318 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%input_matrix, i64 %%15, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_710_count);
  llvm_cbe_tmp__319 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__318))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__318));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_711_count);
  llvm_cbe_tmp__320 = (float )*llvm_cbe_tmp__319;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__320, *(int*)(&llvm_cbe_tmp__320));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds float* %%kernel, i64 1, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_712_count);
  llvm_cbe_tmp__321 = (float *)(&llvm_cbe_kernel[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* %%18, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_713_count);
  llvm_cbe_tmp__322 = (float )*llvm_cbe_tmp__321;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__322, *(int*)(&llvm_cbe_tmp__322));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fmul float %%17, %%19, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_714_count);
  llvm_cbe_tmp__323 = (float )((float )(llvm_cbe_tmp__320 * llvm_cbe_tmp__322));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__323, *(int*)(&llvm_cbe_tmp__323));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fadd float %%12, %%20, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_715_count);
  llvm_cbe_tmp__324 = (float )((float )(llvm_cbe_tmp__315 + llvm_cbe_tmp__323));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__324, *(int*)(&llvm_cbe_tmp__324));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_716_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__324;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__324);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge17, 2, !dbg !19 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_717_count);
  llvm_cbe_tmp__325 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__325&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%22, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_718_count);
  llvm_cbe_tmp__326 = (unsigned int )((unsigned int )(llvm_cbe_tmp__325&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__308&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__326&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_719_count);
  llvm_cbe_tmp__327 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%input_matrix, i64 %%24, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_720_count);
  llvm_cbe_tmp__328 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__327))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__327));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_721_count);
  llvm_cbe_tmp__329 = (float )*llvm_cbe_tmp__328;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__329, *(int*)(&llvm_cbe_tmp__329));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds float* %%kernel, i64 2, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_722_count);
  llvm_cbe_tmp__330 = (float *)(&llvm_cbe_kernel[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_723_count);
  llvm_cbe_tmp__331 = (float )*llvm_cbe_tmp__330;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__331, *(int*)(&llvm_cbe_tmp__331));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fmul float %%26, %%28, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_724_count);
  llvm_cbe_tmp__332 = (float )((float )(llvm_cbe_tmp__329 * llvm_cbe_tmp__331));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__332, *(int*)(&llvm_cbe_tmp__332));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fadd float %%21, %%29, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_725_count);
  llvm_cbe_tmp__333 = (float )((float )(llvm_cbe_tmp__324 + llvm_cbe_tmp__332));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__333, *(int*)(&llvm_cbe_tmp__333));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_726_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__333;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__333);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge8, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_727_count);
  llvm_cbe_tmp__334 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__334&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul nsw i32 %%31, 28, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_728_count);
  llvm_cbe_tmp__335 = (unsigned int )((unsigned int )(llvm_cbe_tmp__334&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__335&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge17, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__336 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__335&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__336&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sext i32 %%33 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_730_count);
  llvm_cbe_tmp__337 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__336);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__337);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds float* %%input_matrix, i64 %%34, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__338 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__337))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__337));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%35, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__339 = (float )*llvm_cbe_tmp__338;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__339, *(int*)(&llvm_cbe_tmp__339));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds float* %%kernel, i64 26, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_733_count);
  llvm_cbe_tmp__340 = (float *)(&llvm_cbe_kernel[(((signed long long )26ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__341 = (float )*llvm_cbe_tmp__340;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__341, *(int*)(&llvm_cbe_tmp__341));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fmul float %%36, %%38, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_735_count);
  llvm_cbe_tmp__342 = (float )((float )(llvm_cbe_tmp__339 * llvm_cbe_tmp__341));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__342, *(int*)(&llvm_cbe_tmp__342));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fadd float %%30, %%39, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_736_count);
  llvm_cbe_tmp__343 = (float )((float )(llvm_cbe_tmp__333 + llvm_cbe_tmp__342));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__343, *(int*)(&llvm_cbe_tmp__343));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%40, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_737_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__343;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__343);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%13, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_738_count);
  llvm_cbe_tmp__344 = (unsigned int )((unsigned int )(llvm_cbe_tmp__316&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__335&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__344&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = sext i32 %%41 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__345 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds float* %%input_matrix, i64 %%42, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_740_count);
  llvm_cbe_tmp__346 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__345))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__345));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load float* %%43, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_741_count);
  llvm_cbe_tmp__347 = (float )*llvm_cbe_tmp__346;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__347, *(int*)(&llvm_cbe_tmp__347));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds float* %%kernel, i64 27, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__348 = (float *)(&llvm_cbe_kernel[(((signed long long )27ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%45, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__349 = (float )*llvm_cbe_tmp__348;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__349, *(int*)(&llvm_cbe_tmp__349));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fmul float %%44, %%46, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__350 = (float )((float )(llvm_cbe_tmp__347 * llvm_cbe_tmp__349));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__350, *(int*)(&llvm_cbe_tmp__350));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = fadd float %%40, %%47, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_745_count);
  llvm_cbe_tmp__351 = (float )((float )(llvm_cbe_tmp__343 + llvm_cbe_tmp__350));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__351, *(int*)(&llvm_cbe_tmp__351));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%48, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_746_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__351;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%22, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_747_count);
  llvm_cbe_tmp__352 = (unsigned int )((unsigned int )(llvm_cbe_tmp__325&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__335&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__352&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%49 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_748_count);
  llvm_cbe_tmp__353 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__352);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__353);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds float* %%input_matrix, i64 %%50, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_749_count);
  llvm_cbe_tmp__354 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__353))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__353));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* %%51, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_750_count);
  llvm_cbe_tmp__355 = (float )*llvm_cbe_tmp__354;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__355, *(int*)(&llvm_cbe_tmp__355));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds float* %%kernel, i64 28, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_751_count);
  llvm_cbe_tmp__356 = (float *)(&llvm_cbe_kernel[(((signed long long )28ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_752_count);
  llvm_cbe_tmp__357 = (float )*llvm_cbe_tmp__356;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__357, *(int*)(&llvm_cbe_tmp__357));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fmul float %%52, %%54, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__358 = (float )((float )(llvm_cbe_tmp__355 * llvm_cbe_tmp__357));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__358, *(int*)(&llvm_cbe_tmp__358));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fadd float %%48, %%55, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__359 = (float )((float )(llvm_cbe_tmp__351 + llvm_cbe_tmp__358));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__359, *(int*)(&llvm_cbe_tmp__359));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%56, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_755_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__359;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__359);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = mul i32 %%storemerge8, 28, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_756_count);
  llvm_cbe_tmp__360 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__360&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%57, 56, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_757_count);
  llvm_cbe_tmp__361 = (unsigned int )((unsigned int )(llvm_cbe_tmp__360&4294967295ull)) + ((unsigned int )(56u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__361&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add nsw i32 %%storemerge17, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_758_count);
  llvm_cbe_tmp__362 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__361&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__362&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%59 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_759_count);
  llvm_cbe_tmp__363 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__363);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds float* %%input_matrix, i64 %%60, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_760_count);
  llvm_cbe_tmp__364 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__363))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__363));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load float* %%61, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_761_count);
  llvm_cbe_tmp__365 = (float )*llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__365, *(int*)(&llvm_cbe_tmp__365));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds float* %%kernel, i64 52, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_762_count);
  llvm_cbe_tmp__366 = (float *)(&llvm_cbe_kernel[(((signed long long )52ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load float* %%63, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_763_count);
  llvm_cbe_tmp__367 = (float )*llvm_cbe_tmp__366;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__367, *(int*)(&llvm_cbe_tmp__367));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = fmul float %%62, %%64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_764_count);
  llvm_cbe_tmp__368 = (float )((float )(llvm_cbe_tmp__365 * llvm_cbe_tmp__367));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__368, *(int*)(&llvm_cbe_tmp__368));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fadd float %%56, %%65, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_765_count);
  llvm_cbe_tmp__369 = (float )((float )(llvm_cbe_tmp__359 + llvm_cbe_tmp__368));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__369, *(int*)(&llvm_cbe_tmp__369));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%66, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_766_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__369;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__369);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add nsw i32 %%13, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_767_count);
  llvm_cbe_tmp__370 = (unsigned int )((unsigned int )(llvm_cbe_tmp__316&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__361&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__370&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = sext i32 %%67 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_768_count);
  llvm_cbe_tmp__371 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__371);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds float* %%input_matrix, i64 %%68, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_769_count);
  llvm_cbe_tmp__372 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__371))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__371));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* %%69, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__373 = (float )*llvm_cbe_tmp__372;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__373, *(int*)(&llvm_cbe_tmp__373));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds float* %%kernel, i64 53, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_771_count);
  llvm_cbe_tmp__374 = (float *)(&llvm_cbe_kernel[(((signed long long )53ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load float* %%71, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_772_count);
  llvm_cbe_tmp__375 = (float )*llvm_cbe_tmp__374;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__375, *(int*)(&llvm_cbe_tmp__375));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fmul float %%70, %%72, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_773_count);
  llvm_cbe_tmp__376 = (float )((float )(llvm_cbe_tmp__373 * llvm_cbe_tmp__375));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__376, *(int*)(&llvm_cbe_tmp__376));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fadd float %%66, %%73, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_774_count);
  llvm_cbe_tmp__377 = (float )((float )(llvm_cbe_tmp__369 + llvm_cbe_tmp__376));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__377, *(int*)(&llvm_cbe_tmp__377));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_775_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__377;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__377);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add nsw i32 %%22, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__378 = (unsigned int )((unsigned int )(llvm_cbe_tmp__325&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__361&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__378&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = sext i32 %%75 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__379 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__379);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds float* %%input_matrix, i64 %%76, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_778_count);
  llvm_cbe_tmp__380 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__379))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__379));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_779_count);
  llvm_cbe_tmp__381 = (float )*llvm_cbe_tmp__380;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__381, *(int*)(&llvm_cbe_tmp__381));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds float* %%kernel, i64 54, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_780_count);
  llvm_cbe_tmp__382 = (float *)(&llvm_cbe_kernel[(((signed long long )54ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* %%79, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__383 = (float )*llvm_cbe_tmp__382;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__383, *(int*)(&llvm_cbe_tmp__383));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = fmul float %%78, %%80, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__384 = (float )((float )(llvm_cbe_tmp__381 * llvm_cbe_tmp__383));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__384, *(int*)(&llvm_cbe_tmp__384));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fadd float %%74, %%81, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__385 = (float )((float )(llvm_cbe_tmp__377 + llvm_cbe_tmp__384));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__385, *(int*)(&llvm_cbe_tmp__385));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%82, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b3  --> \n", ++aesl_llvm_cbe_784_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__385;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__385);
  if (((llvm_cbe_tmp__316&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__386;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__316;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__387:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d_b3}\n");
  return;
}


void Conv2d_b4(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  unsigned int llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  unsigned int llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  unsigned int llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  unsigned long long llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  float *llvm_cbe_tmp__392;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  unsigned int llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  float llvm_cbe_tmp__394;
  float llvm_cbe_tmp__394__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  unsigned int llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  unsigned int llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  unsigned int llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  unsigned int llvm_cbe_tmp__398;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  float llvm_cbe_tmp__399;
  float llvm_cbe_tmp__399__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  unsigned int llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  unsigned long long llvm_cbe_tmp__401;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  float *llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  float llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  unsigned int llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  unsigned long long llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  float *llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  float llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  float llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  float llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  unsigned int llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  unsigned int llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  unsigned int llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  unsigned int llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d_b4\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%33, %%32  for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__413);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 28, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__388 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__388&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_813_count);
  llvm_cbe_tmp__389 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__389&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__414;

llvm_cbe_tmp__415:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge8, 1, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_857_count);
  llvm_cbe_tmp__413 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__413&4294967295ull)));
  if (((llvm_cbe_tmp__413&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__416;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__413;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__414:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%31, %%30  for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__412);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_815_count);
  llvm_cbe_tmp__390 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__388&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__390&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_816_count);
  llvm_cbe_tmp__391 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__390);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__391);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%out_matrix, i64 %%5, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_817_count);
  llvm_cbe_tmp__392 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__391))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__391));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%6, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_818_count);
  *llvm_cbe_tmp__392 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge17, 3, !dbg !19 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_819_count);
  llvm_cbe_tmp__393 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__393&4294967295ull)));
  llvm_cbe_tmp__394__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge8;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__417:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_855_count);
  llvm_cbe_tmp__412 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__412&4294967295ull)));
  if (((llvm_cbe_tmp__412&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__415;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__412;   /* for PHI node */
    goto llvm_cbe_tmp__414;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%3 ], [ %%24, %%27  for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_821_count);
  llvm_cbe_tmp__394 = (float )llvm_cbe_tmp__394__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__394);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__409);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%storemerge8, %%3 ], [ %%28, %%27  for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",llvm_cbe_tmp__411);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%storemerge25, 30, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_822_count);
  llvm_cbe_tmp__395 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) * ((unsigned int )(30u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__395&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%storemerge25, %%storemerge8, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_823_count);
  llvm_cbe_tmp__396 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__396&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = mul nsw i32 %%10, 3, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_824_count);
  llvm_cbe_tmp__397 = (unsigned int )((unsigned int )(llvm_cbe_tmp__396&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__397&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub i32 %%11, %%storemerge17, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_825_count);
  llvm_cbe_tmp__398 = (unsigned int )((unsigned int )(llvm_cbe_tmp__397&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__398&4294967295ull)));
  llvm_cbe_tmp__399__PHI_TEMPORARY = (float )llvm_cbe_tmp__394;   /* for PHI node */
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge17;   /* for PHI node */
  goto llvm_cbe_tmp__418;

llvm_cbe_tmp__419:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge25, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_847_count);
  llvm_cbe_tmp__411 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__411&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__411) < ((signed int )llvm_cbe_tmp__389))) {
    llvm_cbe_tmp__394__PHI_TEMPORARY = (float )llvm_cbe_tmp__409;   /* for PHI node */
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__411;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__417;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__418:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi float [ %%8, %%.preheader ], [ %%24, %%13 ], !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__399 = (float )llvm_cbe_tmp__399__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__399);
printf("\n = %f",llvm_cbe_tmp__394);
printf("\n = %f",llvm_cbe_tmp__409);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ %%storemerge17, %%.preheader ], [ %%25, %%13  for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",llvm_cbe_tmp__410);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge34, %%9, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_828_count);
  llvm_cbe_tmp__400 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__395&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__400&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_829_count);
  llvm_cbe_tmp__401 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__400);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__401);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%input_matrix, i64 %%16, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_830_count);
  llvm_cbe_tmp__402 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__401))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__401));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_831_count);
  llvm_cbe_tmp__403 = (float )*llvm_cbe_tmp__402;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__403, *(int*)(&llvm_cbe_tmp__403));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%12, %%storemerge34, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_832_count);
  llvm_cbe_tmp__404 = (unsigned int )((unsigned int )(llvm_cbe_tmp__398&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__404&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_833_count);
  llvm_cbe_tmp__405 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__404);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%kernel, i64 %%20, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_834_count);
  llvm_cbe_tmp__406 = (float *)(&llvm_cbe_kernel[(((signed long long )llvm_cbe_tmp__405))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__405));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_835_count);
  llvm_cbe_tmp__407 = (float )*llvm_cbe_tmp__406;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__407, *(int*)(&llvm_cbe_tmp__407));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fmul float %%18, %%22, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_836_count);
  llvm_cbe_tmp__408 = (float )((float )(llvm_cbe_tmp__403 * llvm_cbe_tmp__407));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__408, *(int*)(&llvm_cbe_tmp__408));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = fadd float %%14, %%23, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_837_count);
  llvm_cbe_tmp__409 = (float )((float )(llvm_cbe_tmp__399 + llvm_cbe_tmp__408));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__409, *(int*)(&llvm_cbe_tmp__409));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%6, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_838_count);
  *llvm_cbe_tmp__392 = llvm_cbe_tmp__409;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge34, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b4  --> \n", ++aesl_llvm_cbe_839_count);
  llvm_cbe_tmp__410 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__410&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__410) < ((signed int )llvm_cbe_tmp__393))) {
    llvm_cbe_tmp__399__PHI_TEMPORARY = (float )llvm_cbe_tmp__409;   /* for PHI node */
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__410;   /* for PHI node */
    goto llvm_cbe_tmp__418;
  } else {
    goto llvm_cbe_tmp__419;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__416:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d_b4}\n");
  return;
}


void Conv2d_b5(float *llvm_cbe_input_matrix, float *llvm_cbe_kernel, float *llvm_cbe_out_matrix) {
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  unsigned int llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  unsigned int llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  unsigned long long llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  float *llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  unsigned int llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  unsigned int llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  unsigned long long llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  float *llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  float llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  float llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  float llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  float llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  unsigned int llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  unsigned int llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  unsigned long long llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  float *llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  float llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  float *llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  float llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  float llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  float llvm_cbe_tmp__440;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  unsigned int llvm_cbe_tmp__441;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  unsigned int llvm_cbe_tmp__442;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  unsigned long long llvm_cbe_tmp__443;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  float *llvm_cbe_tmp__444;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  float llvm_cbe_tmp__445;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  float *llvm_cbe_tmp__446;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  float llvm_cbe_tmp__447;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  float llvm_cbe_tmp__448;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  float llvm_cbe_tmp__449;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  unsigned int llvm_cbe_tmp__450;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  unsigned int llvm_cbe_tmp__451;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  unsigned int llvm_cbe_tmp__452;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  unsigned long long llvm_cbe_tmp__453;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  float *llvm_cbe_tmp__454;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  float llvm_cbe_tmp__455;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  float *llvm_cbe_tmp__456;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  float llvm_cbe_tmp__457;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  float llvm_cbe_tmp__458;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  float llvm_cbe_tmp__459;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  unsigned int llvm_cbe_tmp__460;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  unsigned long long llvm_cbe_tmp__461;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  float *llvm_cbe_tmp__462;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  float llvm_cbe_tmp__463;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  float *llvm_cbe_tmp__464;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  float llvm_cbe_tmp__465;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  float llvm_cbe_tmp__466;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  float llvm_cbe_tmp__467;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  unsigned int llvm_cbe_tmp__468;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  unsigned long long llvm_cbe_tmp__469;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  float *llvm_cbe_tmp__470;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  float llvm_cbe_tmp__471;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  float *llvm_cbe_tmp__472;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  float llvm_cbe_tmp__473;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  float llvm_cbe_tmp__474;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  float llvm_cbe_tmp__475;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  unsigned int llvm_cbe_tmp__476;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  unsigned int llvm_cbe_tmp__477;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  unsigned int llvm_cbe_tmp__478;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  unsigned long long llvm_cbe_tmp__479;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  float *llvm_cbe_tmp__480;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  float llvm_cbe_tmp__481;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  float *llvm_cbe_tmp__482;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  float llvm_cbe_tmp__483;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  float llvm_cbe_tmp__484;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  float llvm_cbe_tmp__485;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  unsigned int llvm_cbe_tmp__486;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  unsigned long long llvm_cbe_tmp__487;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  float *llvm_cbe_tmp__488;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  float llvm_cbe_tmp__489;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  float *llvm_cbe_tmp__490;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  float llvm_cbe_tmp__491;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  float llvm_cbe_tmp__492;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  float llvm_cbe_tmp__493;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  unsigned int llvm_cbe_tmp__494;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  unsigned long long llvm_cbe_tmp__495;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  float *llvm_cbe_tmp__496;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  float llvm_cbe_tmp__497;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  float *llvm_cbe_tmp__498;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  float llvm_cbe_tmp__499;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  float llvm_cbe_tmp__500;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  float llvm_cbe_tmp__501;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Conv2d_b5\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%31, %%83  for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__450);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge8, 3, !dbg !18 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_884_count);
  llvm_cbe_tmp__420 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__420&4294967295ull)));
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__502:
  if (((llvm_cbe_tmp__450&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__503;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__450;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%13, %%.preheader  for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__432);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge17, %%1, !dbg !18 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_886_count);
  llvm_cbe_tmp__421 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__420&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__421&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !18 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__422 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__422);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds float* %%out_matrix, i64 %%3, !dbg !18 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__423 = (float *)(&llvm_cbe_out_matrix[(((signed long long )llvm_cbe_tmp__422))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__422));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%4, align 4, !dbg !18 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_889_count);
  *llvm_cbe_tmp__423 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = mul nsw i32 %%storemerge8, 30, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_890_count);
  llvm_cbe_tmp__424 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(30u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__424&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge17, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_891_count);
  llvm_cbe_tmp__425 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__424&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__425&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_892_count);
  llvm_cbe_tmp__426 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__425);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__426);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix, i64 %%7, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_893_count);
  llvm_cbe_tmp__427 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__426))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__426));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_894_count);
  llvm_cbe_tmp__428 = (float )*llvm_cbe_tmp__427;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__428, *(int*)(&llvm_cbe_tmp__428));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%kernel, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_895_count);
  llvm_cbe_tmp__429 = (float )*llvm_cbe_kernel;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__429, *(int*)(&llvm_cbe_tmp__429));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fmul float %%9, %%10, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__430 = (float )((float )(llvm_cbe_tmp__428 * llvm_cbe_tmp__429));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__430, *(int*)(&llvm_cbe_tmp__430));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fadd float %%11, 0.000000e+00, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__431 = (float )((float )(llvm_cbe_tmp__430 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__431, *(int*)(&llvm_cbe_tmp__431));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_898_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__431;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge17, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_899_count);
  llvm_cbe_tmp__432 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__432&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%13, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_900_count);
  llvm_cbe_tmp__433 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__424&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__433&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%14 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_901_count);
  llvm_cbe_tmp__434 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__433);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__434);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%input_matrix, i64 %%15, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_902_count);
  llvm_cbe_tmp__435 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__434))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__434));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_903_count);
  llvm_cbe_tmp__436 = (float )*llvm_cbe_tmp__435;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__436, *(int*)(&llvm_cbe_tmp__436));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds float* %%kernel, i64 1, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_904_count);
  llvm_cbe_tmp__437 = (float *)(&llvm_cbe_kernel[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load float* %%18, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__438 = (float )*llvm_cbe_tmp__437;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__438, *(int*)(&llvm_cbe_tmp__438));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fmul float %%17, %%19, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_906_count);
  llvm_cbe_tmp__439 = (float )((float )(llvm_cbe_tmp__436 * llvm_cbe_tmp__438));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__439, *(int*)(&llvm_cbe_tmp__439));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fadd float %%12, %%20, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_907_count);
  llvm_cbe_tmp__440 = (float )((float )(llvm_cbe_tmp__431 + llvm_cbe_tmp__439));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__440, *(int*)(&llvm_cbe_tmp__440));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_908_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__440;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__440);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge17, 2, !dbg !19 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_909_count);
  llvm_cbe_tmp__441 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__441&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%22, %%5, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_910_count);
  llvm_cbe_tmp__442 = (unsigned int )((unsigned int )(llvm_cbe_tmp__441&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__424&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__442&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_911_count);
  llvm_cbe_tmp__443 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__442);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__443);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds float* %%input_matrix, i64 %%24, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_912_count);
  llvm_cbe_tmp__444 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__443))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__443));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_913_count);
  llvm_cbe_tmp__445 = (float )*llvm_cbe_tmp__444;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__445, *(int*)(&llvm_cbe_tmp__445));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds float* %%kernel, i64 2, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_914_count);
  llvm_cbe_tmp__446 = (float *)(&llvm_cbe_kernel[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* %%27, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_915_count);
  llvm_cbe_tmp__447 = (float )*llvm_cbe_tmp__446;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__447, *(int*)(&llvm_cbe_tmp__447));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fmul float %%26, %%28, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_916_count);
  llvm_cbe_tmp__448 = (float )((float )(llvm_cbe_tmp__445 * llvm_cbe_tmp__447));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__448, *(int*)(&llvm_cbe_tmp__448));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = fadd float %%21, %%29, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_917_count);
  llvm_cbe_tmp__449 = (float )((float )(llvm_cbe_tmp__440 + llvm_cbe_tmp__448));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__449, *(int*)(&llvm_cbe_tmp__449));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%30, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_918_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__449;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__449);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge8, 1, !dbg !19 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_919_count);
  llvm_cbe_tmp__450 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__450&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul nsw i32 %%31, 30, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_920_count);
  llvm_cbe_tmp__451 = (unsigned int )((unsigned int )(llvm_cbe_tmp__450&4294967295ull)) * ((unsigned int )(30u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__451&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%storemerge17, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_921_count);
  llvm_cbe_tmp__452 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__451&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__452&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sext i32 %%33 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_922_count);
  llvm_cbe_tmp__453 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__452);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__453);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds float* %%input_matrix, i64 %%34, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_923_count);
  llvm_cbe_tmp__454 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__453))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__453));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load float* %%35, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_924_count);
  llvm_cbe_tmp__455 = (float )*llvm_cbe_tmp__454;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__455, *(int*)(&llvm_cbe_tmp__455));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds float* %%kernel, i64 28, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_925_count);
  llvm_cbe_tmp__456 = (float *)(&llvm_cbe_kernel[(((signed long long )28ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_926_count);
  llvm_cbe_tmp__457 = (float )*llvm_cbe_tmp__456;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__457, *(int*)(&llvm_cbe_tmp__457));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fmul float %%36, %%38, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_927_count);
  llvm_cbe_tmp__458 = (float )((float )(llvm_cbe_tmp__455 * llvm_cbe_tmp__457));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__458, *(int*)(&llvm_cbe_tmp__458));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fadd float %%30, %%39, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_928_count);
  llvm_cbe_tmp__459 = (float )((float )(llvm_cbe_tmp__449 + llvm_cbe_tmp__458));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__459, *(int*)(&llvm_cbe_tmp__459));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%40, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_929_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__459;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__459);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%13, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_930_count);
  llvm_cbe_tmp__460 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__451&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__460&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = sext i32 %%41 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_931_count);
  llvm_cbe_tmp__461 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__460);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__461);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds float* %%input_matrix, i64 %%42, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__462 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__461))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__461));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load float* %%43, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_933_count);
  llvm_cbe_tmp__463 = (float )*llvm_cbe_tmp__462;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__463, *(int*)(&llvm_cbe_tmp__463));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds float* %%kernel, i64 29, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_934_count);
  llvm_cbe_tmp__464 = (float *)(&llvm_cbe_kernel[(((signed long long )29ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%45, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_935_count);
  llvm_cbe_tmp__465 = (float )*llvm_cbe_tmp__464;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__465, *(int*)(&llvm_cbe_tmp__465));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fmul float %%44, %%46, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_936_count);
  llvm_cbe_tmp__466 = (float )((float )(llvm_cbe_tmp__463 * llvm_cbe_tmp__465));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__466, *(int*)(&llvm_cbe_tmp__466));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = fadd float %%40, %%47, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_937_count);
  llvm_cbe_tmp__467 = (float )((float )(llvm_cbe_tmp__459 + llvm_cbe_tmp__466));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__467, *(int*)(&llvm_cbe_tmp__467));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%48, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_938_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__467;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__467);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%22, %%32, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_939_count);
  llvm_cbe_tmp__468 = (unsigned int )((unsigned int )(llvm_cbe_tmp__441&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__451&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__468&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%49 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_940_count);
  llvm_cbe_tmp__469 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__468);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__469);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds float* %%input_matrix, i64 %%50, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__470 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__469))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__469));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* %%51, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_942_count);
  llvm_cbe_tmp__471 = (float )*llvm_cbe_tmp__470;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__471, *(int*)(&llvm_cbe_tmp__471));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds float* %%kernel, i64 30, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_943_count);
  llvm_cbe_tmp__472 = (float *)(&llvm_cbe_kernel[(((signed long long )30ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_944_count);
  llvm_cbe_tmp__473 = (float )*llvm_cbe_tmp__472;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__473, *(int*)(&llvm_cbe_tmp__473));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fmul float %%52, %%54, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_945_count);
  llvm_cbe_tmp__474 = (float )((float )(llvm_cbe_tmp__471 * llvm_cbe_tmp__473));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__474, *(int*)(&llvm_cbe_tmp__474));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fadd float %%48, %%55, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_946_count);
  llvm_cbe_tmp__475 = (float )((float )(llvm_cbe_tmp__467 + llvm_cbe_tmp__474));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__475, *(int*)(&llvm_cbe_tmp__475));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%56, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_947_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__475;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__475);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = mul i32 %%storemerge8, 30, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_948_count);
  llvm_cbe_tmp__476 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) * ((unsigned int )(30u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__476&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%57, 60, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_949_count);
  llvm_cbe_tmp__477 = (unsigned int )((unsigned int )(llvm_cbe_tmp__476&4294967295ull)) + ((unsigned int )(60u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__477&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add nsw i32 %%storemerge17, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_950_count);
  llvm_cbe_tmp__478 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__477&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__478&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%59 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_951_count);
  llvm_cbe_tmp__479 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__478);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__479);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds float* %%input_matrix, i64 %%60, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_952_count);
  llvm_cbe_tmp__480 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__479))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__479));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load float* %%61, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_953_count);
  llvm_cbe_tmp__481 = (float )*llvm_cbe_tmp__480;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__481, *(int*)(&llvm_cbe_tmp__481));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds float* %%kernel, i64 56, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_954_count);
  llvm_cbe_tmp__482 = (float *)(&llvm_cbe_kernel[(((signed long long )56ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load float* %%63, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_955_count);
  llvm_cbe_tmp__483 = (float )*llvm_cbe_tmp__482;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__483, *(int*)(&llvm_cbe_tmp__483));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = fmul float %%62, %%64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_956_count);
  llvm_cbe_tmp__484 = (float )((float )(llvm_cbe_tmp__481 * llvm_cbe_tmp__483));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__484, *(int*)(&llvm_cbe_tmp__484));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fadd float %%56, %%65, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_957_count);
  llvm_cbe_tmp__485 = (float )((float )(llvm_cbe_tmp__475 + llvm_cbe_tmp__484));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__485, *(int*)(&llvm_cbe_tmp__485));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%66, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_958_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__485;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__485);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add nsw i32 %%13, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_959_count);
  llvm_cbe_tmp__486 = (unsigned int )((unsigned int )(llvm_cbe_tmp__432&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__477&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__486&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = sext i32 %%67 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_960_count);
  llvm_cbe_tmp__487 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__486);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__487);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds float* %%input_matrix, i64 %%68, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_961_count);
  llvm_cbe_tmp__488 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__487))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__487));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* %%69, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_962_count);
  llvm_cbe_tmp__489 = (float )*llvm_cbe_tmp__488;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__489, *(int*)(&llvm_cbe_tmp__489));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds float* %%kernel, i64 57, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_963_count);
  llvm_cbe_tmp__490 = (float *)(&llvm_cbe_kernel[(((signed long long )57ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load float* %%71, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_964_count);
  llvm_cbe_tmp__491 = (float )*llvm_cbe_tmp__490;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__491, *(int*)(&llvm_cbe_tmp__491));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fmul float %%70, %%72, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_965_count);
  llvm_cbe_tmp__492 = (float )((float )(llvm_cbe_tmp__489 * llvm_cbe_tmp__491));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__492, *(int*)(&llvm_cbe_tmp__492));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fadd float %%66, %%73, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_966_count);
  llvm_cbe_tmp__493 = (float )((float )(llvm_cbe_tmp__485 + llvm_cbe_tmp__492));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__493, *(int*)(&llvm_cbe_tmp__493));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_967_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__493;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__493);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add nsw i32 %%22, %%58, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_968_count);
  llvm_cbe_tmp__494 = (unsigned int )((unsigned int )(llvm_cbe_tmp__441&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__477&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__494&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = sext i32 %%75 to i64, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_969_count);
  llvm_cbe_tmp__495 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__494);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__495);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds float* %%input_matrix, i64 %%76, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_970_count);
  llvm_cbe_tmp__496 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__495))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__495));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_971_count);
  llvm_cbe_tmp__497 = (float )*llvm_cbe_tmp__496;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__497, *(int*)(&llvm_cbe_tmp__497));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds float* %%kernel, i64 58, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_972_count);
  llvm_cbe_tmp__498 = (float *)(&llvm_cbe_kernel[(((signed long long )58ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* %%79, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_973_count);
  llvm_cbe_tmp__499 = (float )*llvm_cbe_tmp__498;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__499, *(int*)(&llvm_cbe_tmp__499));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = fmul float %%78, %%80, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_974_count);
  llvm_cbe_tmp__500 = (float )((float )(llvm_cbe_tmp__497 * llvm_cbe_tmp__499));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__500, *(int*)(&llvm_cbe_tmp__500));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fadd float %%74, %%81, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_975_count);
  llvm_cbe_tmp__501 = (float )((float )(llvm_cbe_tmp__493 + llvm_cbe_tmp__500));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__501, *(int*)(&llvm_cbe_tmp__501));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%82, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @Conv2d_b5  --> \n", ++aesl_llvm_cbe_976_count);
  *llvm_cbe_tmp__423 = llvm_cbe_tmp__501;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__501);
  if (((llvm_cbe_tmp__432&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__502;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__432;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__503:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Conv2d_b5}\n");
  return;
}


void MatrixBackPropagationMultiply1(float *llvm_cbe_para, float *llvm_cbe_grad, float *llvm_cbe_rgrad) {
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  unsigned long long llvm_cbe_tmp__504;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  float *llvm_cbe_tmp__505;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  unsigned int llvm_cbe_tmp__506;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  float llvm_cbe_tmp__507;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  float llvm_cbe_tmp__508;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  float llvm_cbe_tmp__509;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  unsigned long long llvm_cbe_tmp__510;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  float *llvm_cbe_tmp__511;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  float llvm_cbe_tmp__512;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  float *llvm_cbe_tmp__513;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  float llvm_cbe_tmp__514;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  float llvm_cbe_tmp__515;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  unsigned int llvm_cbe_tmp__516;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  unsigned long long llvm_cbe_tmp__517;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  float *llvm_cbe_tmp__518;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  float llvm_cbe_tmp__519;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  float *llvm_cbe_tmp__520;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  float llvm_cbe_tmp__521;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  float llvm_cbe_tmp__522;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  unsigned int llvm_cbe_tmp__523;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  unsigned long long llvm_cbe_tmp__524;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  float *llvm_cbe_tmp__525;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  float llvm_cbe_tmp__526;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  float *llvm_cbe_tmp__527;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  float llvm_cbe_tmp__528;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  float llvm_cbe_tmp__529;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  unsigned int llvm_cbe_tmp__530;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  unsigned long long llvm_cbe_tmp__531;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  float *llvm_cbe_tmp__532;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  float llvm_cbe_tmp__533;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  float *llvm_cbe_tmp__534;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  float llvm_cbe_tmp__535;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  float llvm_cbe_tmp__536;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  unsigned int llvm_cbe_tmp__537;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  unsigned long long llvm_cbe_tmp__538;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  float *llvm_cbe_tmp__539;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  float llvm_cbe_tmp__540;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  float *llvm_cbe_tmp__541;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  float llvm_cbe_tmp__542;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  float llvm_cbe_tmp__543;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  unsigned int llvm_cbe_tmp__544;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  unsigned long long llvm_cbe_tmp__545;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  float *llvm_cbe_tmp__546;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  float llvm_cbe_tmp__547;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  float *llvm_cbe_tmp__548;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  float llvm_cbe_tmp__549;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  float llvm_cbe_tmp__550;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  unsigned int llvm_cbe_tmp__551;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  unsigned long long llvm_cbe_tmp__552;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  float *llvm_cbe_tmp__553;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  float llvm_cbe_tmp__554;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  float *llvm_cbe_tmp__555;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  float llvm_cbe_tmp__556;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  float llvm_cbe_tmp__557;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  unsigned int llvm_cbe_tmp__558;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  unsigned long long llvm_cbe_tmp__559;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  float *llvm_cbe_tmp__560;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  float llvm_cbe_tmp__561;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  float *llvm_cbe_tmp__562;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  float llvm_cbe_tmp__563;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  float llvm_cbe_tmp__564;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  unsigned int llvm_cbe_tmp__565;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  unsigned long long llvm_cbe_tmp__566;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  float *llvm_cbe_tmp__567;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  float llvm_cbe_tmp__568;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  float *llvm_cbe_tmp__569;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  float llvm_cbe_tmp__570;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  float llvm_cbe_tmp__571;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  unsigned int llvm_cbe_tmp__572;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  unsigned long long llvm_cbe_tmp__573;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  float *llvm_cbe_tmp__574;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  unsigned int llvm_cbe_tmp__575;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixBackPropagationMultiply1\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%72, %%.preheader  for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__575);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge3 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_996_count);
  llvm_cbe_tmp__504 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__504);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%para, i64 %%1, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_997_count);
  llvm_cbe_tmp__505 = (float *)(&llvm_cbe_para[(((signed long long )llvm_cbe_tmp__504))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__504));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul nsw i32 %%storemerge3, 10, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_998_count);
  llvm_cbe_tmp__506 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__506&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_999_count);
  llvm_cbe_tmp__507 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__507, *(int*)(&llvm_cbe_tmp__507));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* %%grad, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1000_count);
  llvm_cbe_tmp__508 = (float )*llvm_cbe_grad;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__508, *(int*)(&llvm_cbe_tmp__508));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fmul float %%4, %%5, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1001_count);
  llvm_cbe_tmp__509 = (float )((float )(llvm_cbe_tmp__507 * llvm_cbe_tmp__508));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__509, *(int*)(&llvm_cbe_tmp__509));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%3 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1002_count);
  llvm_cbe_tmp__510 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__506);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__510);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%rgrad, i64 %%7, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1003_count);
  llvm_cbe_tmp__511 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__510))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__510));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1004_count);
  *llvm_cbe_tmp__511 = llvm_cbe_tmp__509;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__509);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1010_count);
  llvm_cbe_tmp__512 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__512, *(int*)(&llvm_cbe_tmp__512));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds float* %%grad, i64 1, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1011_count);
  llvm_cbe_tmp__513 = (float *)(&llvm_cbe_grad[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load float* %%10, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1012_count);
  llvm_cbe_tmp__514 = (float )*llvm_cbe_tmp__513;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__514, *(int*)(&llvm_cbe_tmp__514));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fmul float %%9, %%11, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__515 = (float )((float )(llvm_cbe_tmp__512 * llvm_cbe_tmp__514));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__515, *(int*)(&llvm_cbe_tmp__515));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = or i32 %%3, 1, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1014_count);
  llvm_cbe_tmp__516 = (unsigned int )llvm_cbe_tmp__506 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__516);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1015_count);
  llvm_cbe_tmp__517 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__516);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__517);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds float* %%rgrad, i64 %%14, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1016_count);
  llvm_cbe_tmp__518 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__517))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__517));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%15, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1017_count);
  *llvm_cbe_tmp__518 = llvm_cbe_tmp__515;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__515);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1023_count);
  llvm_cbe_tmp__519 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__519, *(int*)(&llvm_cbe_tmp__519));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%grad, i64 2, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1024_count);
  llvm_cbe_tmp__520 = (float *)(&llvm_cbe_grad[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1025_count);
  llvm_cbe_tmp__521 = (float )*llvm_cbe_tmp__520;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__521, *(int*)(&llvm_cbe_tmp__521));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = fmul float %%16, %%18, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1026_count);
  llvm_cbe_tmp__522 = (float )((float )(llvm_cbe_tmp__519 * llvm_cbe_tmp__521));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__522, *(int*)(&llvm_cbe_tmp__522));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%3, 2, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1027_count);
  llvm_cbe_tmp__523 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__523&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sext i32 %%20 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1028_count);
  llvm_cbe_tmp__524 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__523);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__524);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds float* %%rgrad, i64 %%21, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1029_count);
  llvm_cbe_tmp__525 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__524))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__524));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%19, float* %%22, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1030_count);
  *llvm_cbe_tmp__525 = llvm_cbe_tmp__522;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__522);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1036_count);
  llvm_cbe_tmp__526 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__526, *(int*)(&llvm_cbe_tmp__526));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds float* %%grad, i64 3, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1037_count);
  llvm_cbe_tmp__527 = (float *)(&llvm_cbe_grad[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load float* %%24, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1038_count);
  llvm_cbe_tmp__528 = (float )*llvm_cbe_tmp__527;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__528, *(int*)(&llvm_cbe_tmp__528));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fmul float %%23, %%25, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1039_count);
  llvm_cbe_tmp__529 = (float )((float )(llvm_cbe_tmp__526 * llvm_cbe_tmp__528));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__529, *(int*)(&llvm_cbe_tmp__529));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%3, 3, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1040_count);
  llvm_cbe_tmp__530 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__530&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%27 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1041_count);
  llvm_cbe_tmp__531 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__530);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__531);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds float* %%rgrad, i64 %%28, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1042_count);
  llvm_cbe_tmp__532 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__531))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__531));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%29, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1043_count);
  *llvm_cbe_tmp__532 = llvm_cbe_tmp__529;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__529);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1049_count);
  llvm_cbe_tmp__533 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__533, *(int*)(&llvm_cbe_tmp__533));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds float* %%grad, i64 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1050_count);
  llvm_cbe_tmp__534 = (float *)(&llvm_cbe_grad[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* %%31, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1051_count);
  llvm_cbe_tmp__535 = (float )*llvm_cbe_tmp__534;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__535, *(int*)(&llvm_cbe_tmp__535));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fmul float %%30, %%32, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1052_count);
  llvm_cbe_tmp__536 = (float )((float )(llvm_cbe_tmp__533 * llvm_cbe_tmp__535));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__536, *(int*)(&llvm_cbe_tmp__536));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add nsw i32 %%3, 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1053_count);
  llvm_cbe_tmp__537 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__537&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sext i32 %%34 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1054_count);
  llvm_cbe_tmp__538 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__537);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__538);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds float* %%rgrad, i64 %%35, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1055_count);
  llvm_cbe_tmp__539 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__538))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__538));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%33, float* %%36, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1056_count);
  *llvm_cbe_tmp__539 = llvm_cbe_tmp__536;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__536);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1062_count);
  llvm_cbe_tmp__540 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__540, *(int*)(&llvm_cbe_tmp__540));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds float* %%grad, i64 5, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1063_count);
  llvm_cbe_tmp__541 = (float *)(&llvm_cbe_grad[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load float* %%38, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__542 = (float )*llvm_cbe_tmp__541;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__542, *(int*)(&llvm_cbe_tmp__542));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fmul float %%37, %%39, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__543 = (float )((float )(llvm_cbe_tmp__540 * llvm_cbe_tmp__542));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__543, *(int*)(&llvm_cbe_tmp__543));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%3, 5, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1066_count);
  llvm_cbe_tmp__544 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__544&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = sext i32 %%41 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1067_count);
  llvm_cbe_tmp__545 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__544);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__545);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds float* %%rgrad, i64 %%42, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1068_count);
  llvm_cbe_tmp__546 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__545))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__545));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%40, float* %%43, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1069_count);
  *llvm_cbe_tmp__546 = llvm_cbe_tmp__543;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__543);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1075_count);
  llvm_cbe_tmp__547 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__547, *(int*)(&llvm_cbe_tmp__547));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds float* %%grad, i64 6, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1076_count);
  llvm_cbe_tmp__548 = (float *)(&llvm_cbe_grad[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%45, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1077_count);
  llvm_cbe_tmp__549 = (float )*llvm_cbe_tmp__548;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__549, *(int*)(&llvm_cbe_tmp__549));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fmul float %%44, %%46, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1078_count);
  llvm_cbe_tmp__550 = (float )((float )(llvm_cbe_tmp__547 * llvm_cbe_tmp__549));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__550, *(int*)(&llvm_cbe_tmp__550));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add nsw i32 %%3, 6, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1079_count);
  llvm_cbe_tmp__551 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(6u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__551&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = sext i32 %%48 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1080_count);
  llvm_cbe_tmp__552 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__551);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__552);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds float* %%rgrad, i64 %%49, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1081_count);
  llvm_cbe_tmp__553 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__552))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__552));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%47, float* %%50, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1082_count);
  *llvm_cbe_tmp__553 = llvm_cbe_tmp__550;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__550);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1088_count);
  llvm_cbe_tmp__554 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__554, *(int*)(&llvm_cbe_tmp__554));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds float* %%grad, i64 7, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1089_count);
  llvm_cbe_tmp__555 = (float *)(&llvm_cbe_grad[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load float* %%52, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1090_count);
  llvm_cbe_tmp__556 = (float )*llvm_cbe_tmp__555;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__556, *(int*)(&llvm_cbe_tmp__556));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fmul float %%51, %%53, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1091_count);
  llvm_cbe_tmp__557 = (float )((float )(llvm_cbe_tmp__554 * llvm_cbe_tmp__556));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__557, *(int*)(&llvm_cbe_tmp__557));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add nsw i32 %%3, 7, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1092_count);
  llvm_cbe_tmp__558 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(7u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__558&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = sext i32 %%55 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1093_count);
  llvm_cbe_tmp__559 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__558);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__559);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds float* %%rgrad, i64 %%56, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1094_count);
  llvm_cbe_tmp__560 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__559))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__559));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%54, float* %%57, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1095_count);
  *llvm_cbe_tmp__560 = llvm_cbe_tmp__557;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__557);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1101_count);
  llvm_cbe_tmp__561 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__561, *(int*)(&llvm_cbe_tmp__561));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds float* %%grad, i64 8, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1102_count);
  llvm_cbe_tmp__562 = (float *)(&llvm_cbe_grad[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load float* %%59, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1103_count);
  llvm_cbe_tmp__563 = (float )*llvm_cbe_tmp__562;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__563, *(int*)(&llvm_cbe_tmp__563));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = fmul float %%58, %%60, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1104_count);
  llvm_cbe_tmp__564 = (float )((float )(llvm_cbe_tmp__561 * llvm_cbe_tmp__563));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__564, *(int*)(&llvm_cbe_tmp__564));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add nsw i32 %%3, 8, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1105_count);
  llvm_cbe_tmp__565 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(8u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__565&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = sext i32 %%62 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1106_count);
  llvm_cbe_tmp__566 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__565);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__566);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds float* %%rgrad, i64 %%63, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1107_count);
  llvm_cbe_tmp__567 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__566))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__566));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%61, float* %%64, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1108_count);
  *llvm_cbe_tmp__567 = llvm_cbe_tmp__564;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__564);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1114_count);
  llvm_cbe_tmp__568 = (float )*llvm_cbe_tmp__505;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__568, *(int*)(&llvm_cbe_tmp__568));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds float* %%grad, i64 9, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1115_count);
  llvm_cbe_tmp__569 = (float *)(&llvm_cbe_grad[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load float* %%66, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1116_count);
  llvm_cbe_tmp__570 = (float )*llvm_cbe_tmp__569;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__570, *(int*)(&llvm_cbe_tmp__570));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = fmul float %%65, %%67, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1117_count);
  llvm_cbe_tmp__571 = (float )((float )(llvm_cbe_tmp__568 * llvm_cbe_tmp__570));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__571, *(int*)(&llvm_cbe_tmp__571));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = add nsw i32 %%3, 9, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1118_count);
  llvm_cbe_tmp__572 = (unsigned int )((unsigned int )(llvm_cbe_tmp__506&4294967295ull)) + ((unsigned int )(9u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__572&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = sext i32 %%69 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1119_count);
  llvm_cbe_tmp__573 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__572);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__573);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds float* %%rgrad, i64 %%70, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1120_count);
  llvm_cbe_tmp__574 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__573))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__573));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%68, float* %%71, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1121_count);
  *llvm_cbe_tmp__574 = llvm_cbe_tmp__571;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__571);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply1  --> \n", ++aesl_llvm_cbe_1127_count);
  llvm_cbe_tmp__575 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__575&4294967295ull)));
  if (((llvm_cbe_tmp__575&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__576;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__575;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__576:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixBackPropagationMultiply1}\n");
  return;
}


void MatrixBackPropagationMultiply2(float *llvm_cbe_para, float *llvm_cbe_grad, float *llvm_cbe_rgrad) {
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  unsigned long long llvm_cbe_tmp__577;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  float *llvm_cbe_tmp__578;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  unsigned int llvm_cbe_tmp__579;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  float llvm_cbe_tmp__580;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  unsigned long long llvm_cbe_tmp__581;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  float *llvm_cbe_tmp__582;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  float llvm_cbe_tmp__583;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  float llvm_cbe_tmp__584;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  unsigned int llvm_cbe_tmp__585;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  unsigned long long llvm_cbe_tmp__586;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  float *llvm_cbe_tmp__587;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  unsigned int llvm_cbe_tmp__588;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned int llvm_cbe_tmp__589;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixBackPropagationMultiply2\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%15, %%14  for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__589);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge3 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1151_count);
  llvm_cbe_tmp__577 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__577);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%para, i64 %%1, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1152_count);
  llvm_cbe_tmp__578 = (float *)(&llvm_cbe_para[(((signed long long )llvm_cbe_tmp__577))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__577));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul nsw i32 %%storemerge3, 45, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1153_count);
  llvm_cbe_tmp__579 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(45u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__579&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__590;

llvm_cbe_tmp__591:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__589 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__589&4294967295ull)));
  if (((llvm_cbe_tmp__589&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__592;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__589;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__590:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%13, %%4  for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__588);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1155_count);
  llvm_cbe_tmp__580 = (float )*llvm_cbe_tmp__578;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__580, *(int*)(&llvm_cbe_tmp__580));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1156_count);
  llvm_cbe_tmp__581 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__581);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%grad, i64 %%6, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1157_count);
  llvm_cbe_tmp__582 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__581))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__581));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1158_count);
  llvm_cbe_tmp__583 = (float )*llvm_cbe_tmp__582;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__583, *(int*)(&llvm_cbe_tmp__583));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fmul float %%5, %%8, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1159_count);
  llvm_cbe_tmp__584 = (float )((float )(llvm_cbe_tmp__580 * llvm_cbe_tmp__583));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__584, *(int*)(&llvm_cbe_tmp__584));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge12, %%3, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__585 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__579&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__585&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1161_count);
  llvm_cbe_tmp__586 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__585);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__586);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%rgrad, i64 %%11, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1162_count);
  llvm_cbe_tmp__587 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__586))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__586));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1163_count);
  *llvm_cbe_tmp__587 = llvm_cbe_tmp__584;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__584);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply2  --> \n", ++aesl_llvm_cbe_1164_count);
  llvm_cbe_tmp__588 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__588&4294967295ull)));
  if (((llvm_cbe_tmp__588&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__591;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__588;   /* for PHI node */
    goto llvm_cbe_tmp__590;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__592:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixBackPropagationMultiply2}\n");
  return;
}


void MatrixBackPropagationMultiply3(float *llvm_cbe_para, float *llvm_cbe_grad, float *llvm_cbe_rgrad) {
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  unsigned long long llvm_cbe_tmp__593;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  float *llvm_cbe_tmp__594;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  unsigned int llvm_cbe_tmp__595;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  float llvm_cbe_tmp__596;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  unsigned long long llvm_cbe_tmp__597;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  float *llvm_cbe_tmp__598;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  float llvm_cbe_tmp__599;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  float llvm_cbe_tmp__600;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  unsigned int llvm_cbe_tmp__601;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  unsigned long long llvm_cbe_tmp__602;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  float *llvm_cbe_tmp__603;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  unsigned int llvm_cbe_tmp__604;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  unsigned int llvm_cbe_tmp__605;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixBackPropagationMultiply3\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%15, %%14  for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__605);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge3 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1195_count);
  llvm_cbe_tmp__593 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__593);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%para, i64 %%1, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1196_count);
  llvm_cbe_tmp__594 = (float *)(&llvm_cbe_para[(((signed long long )llvm_cbe_tmp__593))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__593));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul nsw i32 %%storemerge3, 180, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1197_count);
  llvm_cbe_tmp__595 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(180u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__595&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__606;

llvm_cbe_tmp__607:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1215_count);
  llvm_cbe_tmp__605 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__605&4294967295ull)));
  if (((llvm_cbe_tmp__605&4294967295U) == (576u&4294967295U))) {
    goto llvm_cbe_tmp__608;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__605;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__606:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%13, %%4  for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__604);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1199_count);
  llvm_cbe_tmp__596 = (float )*llvm_cbe_tmp__594;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__596, *(int*)(&llvm_cbe_tmp__596));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1200_count);
  llvm_cbe_tmp__597 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__597);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%grad, i64 %%6, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1201_count);
  llvm_cbe_tmp__598 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__597))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__597));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1202_count);
  llvm_cbe_tmp__599 = (float )*llvm_cbe_tmp__598;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__599, *(int*)(&llvm_cbe_tmp__599));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fmul float %%5, %%8, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1203_count);
  llvm_cbe_tmp__600 = (float )((float )(llvm_cbe_tmp__596 * llvm_cbe_tmp__599));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__600, *(int*)(&llvm_cbe_tmp__600));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge12, %%3, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1204_count);
  llvm_cbe_tmp__601 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__595&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__601&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1205_count);
  llvm_cbe_tmp__602 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__601);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__602);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%rgrad, i64 %%11, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1206_count);
  llvm_cbe_tmp__603 = (float *)(&llvm_cbe_rgrad[(((signed long long )llvm_cbe_tmp__602))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__602));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1207_count);
  *llvm_cbe_tmp__603 = llvm_cbe_tmp__600;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__600);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @MatrixBackPropagationMultiply3  --> \n", ++aesl_llvm_cbe_1208_count);
  llvm_cbe_tmp__604 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__604&4294967295ull)));
  if (((llvm_cbe_tmp__604&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__607;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__604;   /* for PHI node */
    goto llvm_cbe_tmp__606;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__608:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixBackPropagationMultiply3}\n");
  return;
}


void CalculateMatrixGrad1(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  unsigned long long llvm_cbe_tmp__609;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  float *llvm_cbe_tmp__610;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  unsigned int llvm_cbe_tmp__611;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  unsigned long long llvm_cbe_tmp__612;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  float *llvm_cbe_tmp__613;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  float llvm_cbe_tmp__614;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  float llvm_cbe_tmp__615;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  float llvm_cbe_tmp__616;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  float llvm_cbe_tmp__617;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  unsigned int llvm_cbe_tmp__618;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  unsigned long long llvm_cbe_tmp__619;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  float *llvm_cbe_tmp__620;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  float llvm_cbe_tmp__621;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  float *llvm_cbe_tmp__622;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  float llvm_cbe_tmp__623;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  float llvm_cbe_tmp__624;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  float llvm_cbe_tmp__625;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  unsigned int llvm_cbe_tmp__626;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  unsigned long long llvm_cbe_tmp__627;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  float *llvm_cbe_tmp__628;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  float llvm_cbe_tmp__629;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  float *llvm_cbe_tmp__630;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  float llvm_cbe_tmp__631;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  float llvm_cbe_tmp__632;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  float llvm_cbe_tmp__633;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  unsigned int llvm_cbe_tmp__634;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  unsigned long long llvm_cbe_tmp__635;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  float *llvm_cbe_tmp__636;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  float llvm_cbe_tmp__637;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  float *llvm_cbe_tmp__638;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  float llvm_cbe_tmp__639;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  float llvm_cbe_tmp__640;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  float llvm_cbe_tmp__641;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  unsigned int llvm_cbe_tmp__642;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  unsigned long long llvm_cbe_tmp__643;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  float *llvm_cbe_tmp__644;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  float llvm_cbe_tmp__645;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  float *llvm_cbe_tmp__646;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  float llvm_cbe_tmp__647;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  float llvm_cbe_tmp__648;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  float llvm_cbe_tmp__649;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  unsigned int llvm_cbe_tmp__650;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  unsigned long long llvm_cbe_tmp__651;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  float *llvm_cbe_tmp__652;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  float llvm_cbe_tmp__653;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  float *llvm_cbe_tmp__654;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  float llvm_cbe_tmp__655;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  float llvm_cbe_tmp__656;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  float llvm_cbe_tmp__657;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  unsigned int llvm_cbe_tmp__658;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
  unsigned long long llvm_cbe_tmp__659;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  float *llvm_cbe_tmp__660;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  float llvm_cbe_tmp__661;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  float *llvm_cbe_tmp__662;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  float llvm_cbe_tmp__663;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  float llvm_cbe_tmp__664;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  float llvm_cbe_tmp__665;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  unsigned int llvm_cbe_tmp__666;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  unsigned long long llvm_cbe_tmp__667;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  float *llvm_cbe_tmp__668;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  float llvm_cbe_tmp__669;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  float *llvm_cbe_tmp__670;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  float llvm_cbe_tmp__671;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  float llvm_cbe_tmp__672;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  float llvm_cbe_tmp__673;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  unsigned int llvm_cbe_tmp__674;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  unsigned long long llvm_cbe_tmp__675;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  float *llvm_cbe_tmp__676;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  float llvm_cbe_tmp__677;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  float *llvm_cbe_tmp__678;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  float llvm_cbe_tmp__679;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  float llvm_cbe_tmp__680;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  float llvm_cbe_tmp__681;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  unsigned int llvm_cbe_tmp__682;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  unsigned long long llvm_cbe_tmp__683;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  float *llvm_cbe_tmp__684;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  float llvm_cbe_tmp__685;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  float *llvm_cbe_tmp__686;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  float llvm_cbe_tmp__687;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  float llvm_cbe_tmp__688;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  float llvm_cbe_tmp__689;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  unsigned int llvm_cbe_tmp__690;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @CalculateMatrixGrad1\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__691;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__691:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%83, %%1  for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__690);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1237_count);
  llvm_cbe_tmp__609 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__609);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1238_count);
  llvm_cbe_tmp__610 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__609))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__609));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%3, align 4, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1239_count);
  *llvm_cbe_tmp__610 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul nsw i32 %%storemerge3, 10, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1245_count);
  llvm_cbe_tmp__611 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__611&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1246_count);
  llvm_cbe_tmp__612 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__611);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__612);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds float* %%input_matrix, i64 %%5, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1247_count);
  llvm_cbe_tmp__613 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__612))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__612));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load float* %%6, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1248_count);
  llvm_cbe_tmp__614 = (float )*llvm_cbe_tmp__613;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__614, *(int*)(&llvm_cbe_tmp__614));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%grad, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1249_count);
  llvm_cbe_tmp__615 = (float )*llvm_cbe_grad;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__615, *(int*)(&llvm_cbe_tmp__615));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fmul float %%7, %%8, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1250_count);
  llvm_cbe_tmp__616 = (float )((float )(llvm_cbe_tmp__614 * llvm_cbe_tmp__615));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__616, *(int*)(&llvm_cbe_tmp__616));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fadd float %%9, 0.000000e+00, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1251_count);
  llvm_cbe_tmp__617 = (float )((float )(llvm_cbe_tmp__616 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__617, *(int*)(&llvm_cbe_tmp__617));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%10, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1252_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__617;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__617);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i32 %%4, 1, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1258_count);
  llvm_cbe_tmp__618 = (unsigned int )llvm_cbe_tmp__611 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__618);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%11 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__619 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__618);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__619);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds float* %%input_matrix, i64 %%12, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__620 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__619))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__619));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* %%13, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1261_count);
  llvm_cbe_tmp__621 = (float )*llvm_cbe_tmp__620;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__621, *(int*)(&llvm_cbe_tmp__621));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds float* %%grad, i64 1, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1262_count);
  llvm_cbe_tmp__622 = (float *)(&llvm_cbe_grad[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* %%15, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1263_count);
  llvm_cbe_tmp__623 = (float )*llvm_cbe_tmp__622;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__623, *(int*)(&llvm_cbe_tmp__623));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fmul float %%14, %%16, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1264_count);
  llvm_cbe_tmp__624 = (float )((float )(llvm_cbe_tmp__621 * llvm_cbe_tmp__623));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__624, *(int*)(&llvm_cbe_tmp__624));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fadd float %%10, %%17, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1265_count);
  llvm_cbe_tmp__625 = (float )((float )(llvm_cbe_tmp__617 + llvm_cbe_tmp__624));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__625, *(int*)(&llvm_cbe_tmp__625));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1266_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__625;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__625);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%4, 2, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1272_count);
  llvm_cbe_tmp__626 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__626&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1273_count);
  llvm_cbe_tmp__627 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__626);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__627);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds float* %%input_matrix, i64 %%20, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1274_count);
  llvm_cbe_tmp__628 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__627))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__627));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1275_count);
  llvm_cbe_tmp__629 = (float )*llvm_cbe_tmp__628;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__629, *(int*)(&llvm_cbe_tmp__629));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds float* %%grad, i64 2, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1276_count);
  llvm_cbe_tmp__630 = (float *)(&llvm_cbe_grad[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1277_count);
  llvm_cbe_tmp__631 = (float )*llvm_cbe_tmp__630;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__631, *(int*)(&llvm_cbe_tmp__631));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = fmul float %%22, %%24, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1278_count);
  llvm_cbe_tmp__632 = (float )((float )(llvm_cbe_tmp__629 * llvm_cbe_tmp__631));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__632, *(int*)(&llvm_cbe_tmp__632));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fadd float %%18, %%25, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1279_count);
  llvm_cbe_tmp__633 = (float )((float )(llvm_cbe_tmp__625 + llvm_cbe_tmp__632));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__633, *(int*)(&llvm_cbe_tmp__633));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%26, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1280_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__633;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__633);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%4, 3, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1286_count);
  llvm_cbe_tmp__634 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__634&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = sext i32 %%27 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1287_count);
  llvm_cbe_tmp__635 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__634);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__635);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds float* %%input_matrix, i64 %%28, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1288_count);
  llvm_cbe_tmp__636 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__635))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__635));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load float* %%29, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1289_count);
  llvm_cbe_tmp__637 = (float )*llvm_cbe_tmp__636;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__637, *(int*)(&llvm_cbe_tmp__637));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds float* %%grad, i64 3, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1290_count);
  llvm_cbe_tmp__638 = (float *)(&llvm_cbe_grad[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load float* %%31, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1291_count);
  llvm_cbe_tmp__639 = (float )*llvm_cbe_tmp__638;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__639, *(int*)(&llvm_cbe_tmp__639));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fmul float %%30, %%32, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1292_count);
  llvm_cbe_tmp__640 = (float )((float )(llvm_cbe_tmp__637 * llvm_cbe_tmp__639));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__640, *(int*)(&llvm_cbe_tmp__640));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = fadd float %%26, %%33, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1293_count);
  llvm_cbe_tmp__641 = (float )((float )(llvm_cbe_tmp__633 + llvm_cbe_tmp__640));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__641, *(int*)(&llvm_cbe_tmp__641));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%34, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1294_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__641;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__641);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%4, 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1300_count);
  llvm_cbe_tmp__642 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__642&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%35 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1301_count);
  llvm_cbe_tmp__643 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__642);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__643);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds float* %%input_matrix, i64 %%36, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1302_count);
  llvm_cbe_tmp__644 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__643))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__643));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load float* %%37, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1303_count);
  llvm_cbe_tmp__645 = (float )*llvm_cbe_tmp__644;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__645, *(int*)(&llvm_cbe_tmp__645));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds float* %%grad, i64 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1304_count);
  llvm_cbe_tmp__646 = (float *)(&llvm_cbe_grad[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* %%39, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1305_count);
  llvm_cbe_tmp__647 = (float )*llvm_cbe_tmp__646;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__647, *(int*)(&llvm_cbe_tmp__647));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = fmul float %%38, %%40, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1306_count);
  llvm_cbe_tmp__648 = (float )((float )(llvm_cbe_tmp__645 * llvm_cbe_tmp__647));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__648, *(int*)(&llvm_cbe_tmp__648));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = fadd float %%34, %%41, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1307_count);
  llvm_cbe_tmp__649 = (float )((float )(llvm_cbe_tmp__641 + llvm_cbe_tmp__648));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__649, *(int*)(&llvm_cbe_tmp__649));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%42, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1308_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__649;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__649);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add nsw i32 %%4, 5, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1314_count);
  llvm_cbe_tmp__650 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__650&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%43 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1315_count);
  llvm_cbe_tmp__651 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__650);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__651);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds float* %%input_matrix, i64 %%44, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1316_count);
  llvm_cbe_tmp__652 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__651))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__651));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* %%45, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1317_count);
  llvm_cbe_tmp__653 = (float )*llvm_cbe_tmp__652;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__653, *(int*)(&llvm_cbe_tmp__653));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds float* %%grad, i64 5, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1318_count);
  llvm_cbe_tmp__654 = (float *)(&llvm_cbe_grad[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load float* %%47, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1319_count);
  llvm_cbe_tmp__655 = (float )*llvm_cbe_tmp__654;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__655, *(int*)(&llvm_cbe_tmp__655));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = fmul float %%46, %%48, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1320_count);
  llvm_cbe_tmp__656 = (float )((float )(llvm_cbe_tmp__653 * llvm_cbe_tmp__655));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__656, *(int*)(&llvm_cbe_tmp__656));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fadd float %%42, %%49, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1321_count);
  llvm_cbe_tmp__657 = (float )((float )(llvm_cbe_tmp__649 + llvm_cbe_tmp__656));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__657, *(int*)(&llvm_cbe_tmp__657));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%50, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1322_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__657;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__657);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add nsw i32 %%4, 6, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1328_count);
  llvm_cbe_tmp__658 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(6u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__658&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = sext i32 %%51 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1329_count);
  llvm_cbe_tmp__659 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__658);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__659);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds float* %%input_matrix, i64 %%52, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1330_count);
  llvm_cbe_tmp__660 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__659))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__659));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load float* %%53, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1331_count);
  llvm_cbe_tmp__661 = (float )*llvm_cbe_tmp__660;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__661, *(int*)(&llvm_cbe_tmp__661));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds float* %%grad, i64 6, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1332_count);
  llvm_cbe_tmp__662 = (float *)(&llvm_cbe_grad[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load float* %%55, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1333_count);
  llvm_cbe_tmp__663 = (float )*llvm_cbe_tmp__662;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__663, *(int*)(&llvm_cbe_tmp__663));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = fmul float %%54, %%56, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1334_count);
  llvm_cbe_tmp__664 = (float )((float )(llvm_cbe_tmp__661 * llvm_cbe_tmp__663));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__664, *(int*)(&llvm_cbe_tmp__664));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = fadd float %%50, %%57, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1335_count);
  llvm_cbe_tmp__665 = (float )((float )(llvm_cbe_tmp__657 + llvm_cbe_tmp__664));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__665, *(int*)(&llvm_cbe_tmp__665));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%58, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1336_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__665;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__665);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add nsw i32 %%4, 7, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1342_count);
  llvm_cbe_tmp__666 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(7u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__666&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%59 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1343_count);
  llvm_cbe_tmp__667 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__666);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__667);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds float* %%input_matrix, i64 %%60, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1344_count);
  llvm_cbe_tmp__668 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__667))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__667));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load float* %%61, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1345_count);
  llvm_cbe_tmp__669 = (float )*llvm_cbe_tmp__668;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__669, *(int*)(&llvm_cbe_tmp__669));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds float* %%grad, i64 7, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1346_count);
  llvm_cbe_tmp__670 = (float *)(&llvm_cbe_grad[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load float* %%63, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1347_count);
  llvm_cbe_tmp__671 = (float )*llvm_cbe_tmp__670;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__671, *(int*)(&llvm_cbe_tmp__671));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = fmul float %%62, %%64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1348_count);
  llvm_cbe_tmp__672 = (float )((float )(llvm_cbe_tmp__669 * llvm_cbe_tmp__671));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__672, *(int*)(&llvm_cbe_tmp__672));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fadd float %%58, %%65, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1349_count);
  llvm_cbe_tmp__673 = (float )((float )(llvm_cbe_tmp__665 + llvm_cbe_tmp__672));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__673, *(int*)(&llvm_cbe_tmp__673));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%66, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1350_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__673;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__673);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add nsw i32 %%4, 8, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1356_count);
  llvm_cbe_tmp__674 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(8u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__674&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = sext i32 %%67 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1357_count);
  llvm_cbe_tmp__675 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__674);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__675);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds float* %%input_matrix, i64 %%68, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1358_count);
  llvm_cbe_tmp__676 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__675))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__675));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* %%69, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1359_count);
  llvm_cbe_tmp__677 = (float )*llvm_cbe_tmp__676;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__677, *(int*)(&llvm_cbe_tmp__677));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds float* %%grad, i64 8, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1360_count);
  llvm_cbe_tmp__678 = (float *)(&llvm_cbe_grad[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = load float* %%71, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1361_count);
  llvm_cbe_tmp__679 = (float )*llvm_cbe_tmp__678;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__679, *(int*)(&llvm_cbe_tmp__679));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fmul float %%70, %%72, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1362_count);
  llvm_cbe_tmp__680 = (float )((float )(llvm_cbe_tmp__677 * llvm_cbe_tmp__679));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__680, *(int*)(&llvm_cbe_tmp__680));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fadd float %%66, %%73, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1363_count);
  llvm_cbe_tmp__681 = (float )((float )(llvm_cbe_tmp__673 + llvm_cbe_tmp__680));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__681, *(int*)(&llvm_cbe_tmp__681));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1364_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__681;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__681);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add nsw i32 %%4, 9, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1370_count);
  llvm_cbe_tmp__682 = (unsigned int )((unsigned int )(llvm_cbe_tmp__611&4294967295ull)) + ((unsigned int )(9u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__682&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = sext i32 %%75 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1371_count);
  llvm_cbe_tmp__683 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__682);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__683);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds float* %%input_matrix, i64 %%76, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1372_count);
  llvm_cbe_tmp__684 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__683))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__683));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load float* %%77, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1373_count);
  llvm_cbe_tmp__685 = (float )*llvm_cbe_tmp__684;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__685, *(int*)(&llvm_cbe_tmp__685));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds float* %%grad, i64 9, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1374_count);
  llvm_cbe_tmp__686 = (float *)(&llvm_cbe_grad[(((signed long long )9ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* %%79, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1375_count);
  llvm_cbe_tmp__687 = (float )*llvm_cbe_tmp__686;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__687, *(int*)(&llvm_cbe_tmp__687));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = fmul float %%78, %%80, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1376_count);
  llvm_cbe_tmp__688 = (float )((float )(llvm_cbe_tmp__685 * llvm_cbe_tmp__687));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__688, *(int*)(&llvm_cbe_tmp__688));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fadd float %%74, %%81, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1377_count);
  llvm_cbe_tmp__689 = (float )((float )(llvm_cbe_tmp__681 + llvm_cbe_tmp__688));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__689, *(int*)(&llvm_cbe_tmp__689));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%82, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1378_count);
  *llvm_cbe_tmp__610 = llvm_cbe_tmp__689;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__689);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad1  --> \n", ++aesl_llvm_cbe_1384_count);
  llvm_cbe_tmp__690 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__690&4294967295ull)));
  if (((llvm_cbe_tmp__690&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__692;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__690;   /* for PHI node */
    goto llvm_cbe_tmp__691;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__692:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @CalculateMatrixGrad1}\n");
  return;
}


void CalculateMatrixGrad2(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  unsigned long long llvm_cbe_tmp__693;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  float *llvm_cbe_tmp__694;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  unsigned int llvm_cbe_tmp__695;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  float llvm_cbe_tmp__696;
  float llvm_cbe_tmp__696__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  unsigned int llvm_cbe_tmp__697;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  unsigned long long llvm_cbe_tmp__698;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  float *llvm_cbe_tmp__699;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  float llvm_cbe_tmp__700;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  unsigned long long llvm_cbe_tmp__701;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  float *llvm_cbe_tmp__702;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  float llvm_cbe_tmp__703;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  float llvm_cbe_tmp__704;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  float llvm_cbe_tmp__705;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  unsigned int llvm_cbe_tmp__706;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  unsigned int llvm_cbe_tmp__707;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @CalculateMatrixGrad2\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__708;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__708:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__707);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1407_count);
  llvm_cbe_tmp__693 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__693);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1408_count);
  llvm_cbe_tmp__694 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__693))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__693));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%3, align 4, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1409_count);
  *llvm_cbe_tmp__694 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul nsw i32 %%storemerge3, 45, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1415_count);
  llvm_cbe_tmp__695 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(45u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__695&4294967295ull)));
  llvm_cbe_tmp__696__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__709;

llvm_cbe_tmp__710:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1435_count);
  llvm_cbe_tmp__707 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__707&4294967295ull)));
  if (((llvm_cbe_tmp__707&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__711;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__707;   /* for PHI node */
    goto llvm_cbe_tmp__708;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__709:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi float [ 0.000000e+00, %%1 ], [ %%15, %%5 ], !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1417_count);
  llvm_cbe_tmp__696 = (float )llvm_cbe_tmp__696__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__696);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__705);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%1 ], [ %%16, %%5  for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__706);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge12, %%4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1418_count);
  llvm_cbe_tmp__697 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__695&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__697&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%7 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1419_count);
  llvm_cbe_tmp__698 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__697);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__698);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%input_matrix, i64 %%8, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1420_count);
  llvm_cbe_tmp__699 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__698))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__698));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1421_count);
  llvm_cbe_tmp__700 = (float )*llvm_cbe_tmp__699;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__700, *(int*)(&llvm_cbe_tmp__700));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1422_count);
  llvm_cbe_tmp__701 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__701);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%grad, i64 %%11, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1423_count);
  llvm_cbe_tmp__702 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__701))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__701));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1424_count);
  llvm_cbe_tmp__703 = (float )*llvm_cbe_tmp__702;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__703, *(int*)(&llvm_cbe_tmp__703));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul float %%10, %%13, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1425_count);
  llvm_cbe_tmp__704 = (float )((float )(llvm_cbe_tmp__700 * llvm_cbe_tmp__703));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__704, *(int*)(&llvm_cbe_tmp__704));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fadd float %%6, %%14, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1426_count);
  llvm_cbe_tmp__705 = (float )((float )(llvm_cbe_tmp__696 + llvm_cbe_tmp__704));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__705, *(int*)(&llvm_cbe_tmp__705));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1427_count);
  *llvm_cbe_tmp__694 = llvm_cbe_tmp__705;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__705);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad2  --> \n", ++aesl_llvm_cbe_1428_count);
  llvm_cbe_tmp__706 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__706&4294967295ull)));
  if (((llvm_cbe_tmp__706&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__710;
  } else {
    llvm_cbe_tmp__696__PHI_TEMPORARY = (float )llvm_cbe_tmp__705;   /* for PHI node */
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__706;   /* for PHI node */
    goto llvm_cbe_tmp__709;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__711:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @CalculateMatrixGrad2}\n");
  return;
}


void CalculateMatrixGrad3(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  unsigned long long llvm_cbe_tmp__712;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  float *llvm_cbe_tmp__713;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  unsigned int llvm_cbe_tmp__714;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  float llvm_cbe_tmp__715;
  float llvm_cbe_tmp__715__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  unsigned int llvm_cbe_tmp__716;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  unsigned long long llvm_cbe_tmp__717;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  float *llvm_cbe_tmp__718;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  float llvm_cbe_tmp__719;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  unsigned long long llvm_cbe_tmp__720;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  float *llvm_cbe_tmp__721;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  float llvm_cbe_tmp__722;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  float llvm_cbe_tmp__723;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  float llvm_cbe_tmp__724;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  unsigned int llvm_cbe_tmp__725;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  unsigned int llvm_cbe_tmp__726;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @CalculateMatrixGrad3\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__727;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__727:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__726);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1458_count);
  llvm_cbe_tmp__712 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__712);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1459_count);
  llvm_cbe_tmp__713 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__712))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__712));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%3, align 4, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1460_count);
  *llvm_cbe_tmp__713 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul nsw i32 %%storemerge3, 180, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1466_count);
  llvm_cbe_tmp__714 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(180u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__714&4294967295ull)));
  llvm_cbe_tmp__715__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__728;

llvm_cbe_tmp__729:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1486_count);
  llvm_cbe_tmp__726 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__726&4294967295ull)));
  if (((llvm_cbe_tmp__726&4294967295U) == (576u&4294967295U))) {
    goto llvm_cbe_tmp__730;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__726;   /* for PHI node */
    goto llvm_cbe_tmp__727;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__728:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi float [ 0.000000e+00, %%1 ], [ %%15, %%5 ], !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1468_count);
  llvm_cbe_tmp__715 = (float )llvm_cbe_tmp__715__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__715);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__724);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%1 ], [ %%16, %%5  for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__725);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge12, %%4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1469_count);
  llvm_cbe_tmp__716 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__714&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__716&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%7 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1470_count);
  llvm_cbe_tmp__717 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__716);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__717);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%input_matrix, i64 %%8, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1471_count);
  llvm_cbe_tmp__718 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__717))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__717));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1472_count);
  llvm_cbe_tmp__719 = (float )*llvm_cbe_tmp__718;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__719, *(int*)(&llvm_cbe_tmp__719));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge12 to i64, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1473_count);
  llvm_cbe_tmp__720 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__720);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds float* %%grad, i64 %%11, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1474_count);
  llvm_cbe_tmp__721 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__720))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__720));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load float* %%12, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1475_count);
  llvm_cbe_tmp__722 = (float )*llvm_cbe_tmp__721;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__722, *(int*)(&llvm_cbe_tmp__722));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul float %%10, %%13, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1476_count);
  llvm_cbe_tmp__723 = (float )((float )(llvm_cbe_tmp__719 * llvm_cbe_tmp__722));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__723, *(int*)(&llvm_cbe_tmp__723));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fadd float %%6, %%14, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1477_count);
  llvm_cbe_tmp__724 = (float )((float )(llvm_cbe_tmp__715 + llvm_cbe_tmp__723));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__724, *(int*)(&llvm_cbe_tmp__724));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1478_count);
  *llvm_cbe_tmp__713 = llvm_cbe_tmp__724;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__724);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @CalculateMatrixGrad3  --> \n", ++aesl_llvm_cbe_1479_count);
  llvm_cbe_tmp__725 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__725&4294967295ull)));
  if (((llvm_cbe_tmp__725&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__729;
  } else {
    llvm_cbe_tmp__715__PHI_TEMPORARY = (float )llvm_cbe_tmp__724;   /* for PHI node */
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__725;   /* for PHI node */
    goto llvm_cbe_tmp__728;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__730:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @CalculateMatrixGrad3}\n");
  return;
}


void ReluBackPropagation1(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  unsigned long long llvm_cbe_tmp__731;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  float *llvm_cbe_tmp__732;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  float llvm_cbe_tmp__733;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  float *llvm_cbe_tmp__734;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  float llvm_cbe_tmp__735;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  float *llvm_cbe_tmp__736;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  float *llvm_cbe_tmp__737;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  float llvm_cbe_tmp__738;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  double llvm_cbe_tmp__739;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  double llvm_cbe_tmp__740;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  float llvm_cbe_tmp__741;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  float *llvm_cbe_tmp__742;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  unsigned int llvm_cbe_tmp__743;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @ReluBackPropagation1\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__744;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__744:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__743);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1512_count);
  llvm_cbe_tmp__731 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__731);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1513_count);
  llvm_cbe_tmp__732 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__731))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__731));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1514_count);
  llvm_cbe_tmp__733 = (float )*llvm_cbe_tmp__732;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__733, *(int*)(&llvm_cbe_tmp__733));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__733, 0x0p0))) {
    goto llvm_cbe_tmp__745;
  } else {
    goto llvm_cbe_tmp__746;
  }

llvm_cbe_tmp__747:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1530_count);
  llvm_cbe_tmp__743 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__743&4294967295ull)));
  if (((llvm_cbe_tmp__743&4294967295U) == (45u&4294967295U))) {
    goto llvm_cbe_tmp__748;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__743;   /* for PHI node */
    goto llvm_cbe_tmp__744;
  }

llvm_cbe_tmp__745:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%grad, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1517_count);
  llvm_cbe_tmp__734 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__731))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__731));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1518_count);
  llvm_cbe_tmp__735 = (float )*llvm_cbe_tmp__734;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__735, *(int*)(&llvm_cbe_tmp__735));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1519_count);
  llvm_cbe_tmp__736 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__731))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__731));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1520_count);
  *llvm_cbe_tmp__736 = llvm_cbe_tmp__735;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__735);
  goto llvm_cbe_tmp__747;

llvm_cbe_tmp__746:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%grad, i64 %%2, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1522_count);
  llvm_cbe_tmp__737 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__731))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__731));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1523_count);
  llvm_cbe_tmp__738 = (float )*llvm_cbe_tmp__737;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__738, *(int*)(&llvm_cbe_tmp__738));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fpext float %%12 to double, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1524_count);
  llvm_cbe_tmp__739 = (double )((double )llvm_cbe_tmp__738);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__739, *(long long*)(&llvm_cbe_tmp__739));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul double %%13, 5.000000e-02, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1525_count);
  llvm_cbe_tmp__740 = (double )llvm_cbe_tmp__739 * 0x1.999999999999ap-5;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__740, *(long long*)(&llvm_cbe_tmp__740));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fptrunc double %%14 to float, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1526_count);
  llvm_cbe_tmp__741 = (float )((float )llvm_cbe_tmp__740);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__741, *(int*)(&llvm_cbe_tmp__741));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1527_count);
  llvm_cbe_tmp__742 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__731))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__731));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%16, align 4, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation1  --> \n", ++aesl_llvm_cbe_1528_count);
  *llvm_cbe_tmp__742 = llvm_cbe_tmp__741;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__741);
  goto llvm_cbe_tmp__747;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__748:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @ReluBackPropagation1}\n");
  return;
}


void ReluBackPropagation2(float *llvm_cbe_input_matrix, float *llvm_cbe_grad, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
  static  unsigned long long aesl_llvm_cbe_1545_count = 0;
  static  unsigned long long aesl_llvm_cbe_1546_count = 0;
  static  unsigned long long aesl_llvm_cbe_1547_count = 0;
  static  unsigned long long aesl_llvm_cbe_1548_count = 0;
  static  unsigned long long aesl_llvm_cbe_1549_count = 0;
  static  unsigned long long aesl_llvm_cbe_1550_count = 0;
  static  unsigned long long aesl_llvm_cbe_1551_count = 0;
  static  unsigned long long aesl_llvm_cbe_1552_count = 0;
  static  unsigned long long aesl_llvm_cbe_1553_count = 0;
  static  unsigned long long aesl_llvm_cbe_1554_count = 0;
  static  unsigned long long aesl_llvm_cbe_1555_count = 0;
  static  unsigned long long aesl_llvm_cbe_1556_count = 0;
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;
  unsigned long long llvm_cbe_tmp__749;
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  float *llvm_cbe_tmp__750;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  float llvm_cbe_tmp__751;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  float *llvm_cbe_tmp__752;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  float llvm_cbe_tmp__753;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  float *llvm_cbe_tmp__754;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  float *llvm_cbe_tmp__755;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  float llvm_cbe_tmp__756;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
  double llvm_cbe_tmp__757;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;
  double llvm_cbe_tmp__758;
  static  unsigned long long aesl_llvm_cbe_1572_count = 0;
  float llvm_cbe_tmp__759;
  static  unsigned long long aesl_llvm_cbe_1573_count = 0;
  float *llvm_cbe_tmp__760;
  static  unsigned long long aesl_llvm_cbe_1574_count = 0;
  static  unsigned long long aesl_llvm_cbe_1575_count = 0;
  static  unsigned long long aesl_llvm_cbe_1576_count = 0;
  unsigned int llvm_cbe_tmp__761;
  static  unsigned long long aesl_llvm_cbe_1577_count = 0;
  static  unsigned long long aesl_llvm_cbe_1578_count = 0;
  static  unsigned long long aesl_llvm_cbe_1579_count = 0;
  static  unsigned long long aesl_llvm_cbe_1580_count = 0;
  static  unsigned long long aesl_llvm_cbe_1581_count = 0;
  static  unsigned long long aesl_llvm_cbe_1582_count = 0;
  static  unsigned long long aesl_llvm_cbe_1583_count = 0;
  static  unsigned long long aesl_llvm_cbe_1584_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1585_count = 0;
  static  unsigned long long aesl_llvm_cbe_1586_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @ReluBackPropagation2\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__762;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__762:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__761);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1558_count);
  llvm_cbe_tmp__749 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__749);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1559_count);
  llvm_cbe_tmp__750 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__749))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__749));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1560_count);
  llvm_cbe_tmp__751 = (float )*llvm_cbe_tmp__750;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__751, *(int*)(&llvm_cbe_tmp__751));
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__751, 0x0p0))) {
    goto llvm_cbe_tmp__763;
  } else {
    goto llvm_cbe_tmp__764;
  }

llvm_cbe_tmp__765:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1576_count);
  llvm_cbe_tmp__761 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__761&4294967295ull)));
  if (((llvm_cbe_tmp__761&4294967295U) == (180u&4294967295U))) {
    goto llvm_cbe_tmp__766;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__761;   /* for PHI node */
    goto llvm_cbe_tmp__762;
  }

llvm_cbe_tmp__763:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%grad, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1563_count);
  llvm_cbe_tmp__752 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__749))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__749));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1564_count);
  llvm_cbe_tmp__753 = (float )*llvm_cbe_tmp__752;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__753, *(int*)(&llvm_cbe_tmp__753));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1565_count);
  llvm_cbe_tmp__754 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__749))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__749));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%8, float* %%9, align 4, !dbg !17 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1566_count);
  *llvm_cbe_tmp__754 = llvm_cbe_tmp__753;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__753);
  goto llvm_cbe_tmp__765;

llvm_cbe_tmp__764:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%grad, i64 %%2, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1568_count);
  llvm_cbe_tmp__755 = (float *)(&llvm_cbe_grad[(((signed long long )llvm_cbe_tmp__749))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__749));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1569_count);
  llvm_cbe_tmp__756 = (float )*llvm_cbe_tmp__755;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__756, *(int*)(&llvm_cbe_tmp__756));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fpext float %%12 to double, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1570_count);
  llvm_cbe_tmp__757 = (double )((double )llvm_cbe_tmp__756);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__757, *(long long*)(&llvm_cbe_tmp__757));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fmul double %%13, 5.000000e-02, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1571_count);
  llvm_cbe_tmp__758 = (double )llvm_cbe_tmp__757 * 0x1.999999999999ap-5;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__758, *(long long*)(&llvm_cbe_tmp__758));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fptrunc double %%14 to float, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1572_count);
  llvm_cbe_tmp__759 = (float )((float )llvm_cbe_tmp__758);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__759, *(int*)(&llvm_cbe_tmp__759));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%output_matrix, i64 %%2, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1573_count);
  llvm_cbe_tmp__760 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__749))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__749));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%16, align 4, !dbg !18 for 0x%I64xth hint within @ReluBackPropagation2  --> \n", ++aesl_llvm_cbe_1574_count);
  *llvm_cbe_tmp__760 = llvm_cbe_tmp__759;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__759);
  goto llvm_cbe_tmp__765;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__766:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @ReluBackPropagation2}\n");
  return;
}


void Padding1(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1595_count = 0;
  static  unsigned long long aesl_llvm_cbe_1596_count = 0;
  static  unsigned long long aesl_llvm_cbe_1597_count = 0;
  static  unsigned long long aesl_llvm_cbe_1598_count = 0;
  unsigned int llvm_cbe_tmp__767;
  static  unsigned long long aesl_llvm_cbe_1599_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1600_count = 0;
  unsigned int llvm_cbe_tmp__768;
  static  unsigned long long aesl_llvm_cbe_1601_count = 0;
  unsigned long long llvm_cbe_tmp__769;
  static  unsigned long long aesl_llvm_cbe_1602_count = 0;
  float *llvm_cbe_tmp__770;
  static  unsigned long long aesl_llvm_cbe_1603_count = 0;
  static  unsigned long long aesl_llvm_cbe_1604_count = 0;
  unsigned int llvm_cbe_tmp__771;
  static  unsigned long long aesl_llvm_cbe_1605_count = 0;
  static  unsigned long long aesl_llvm_cbe_1606_count = 0;
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
  unsigned int llvm_cbe_tmp__772;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_1615_count = 0;
  static  unsigned long long aesl_llvm_cbe_1616_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Padding1\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%8, %%7  for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__772);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge3, 28, !dbg !17 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1598_count);
  llvm_cbe_tmp__767 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(28u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__767&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__773;

llvm_cbe_tmp__774:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1610_count);
  llvm_cbe_tmp__772 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__772&4294967295ull)));
  if (((llvm_cbe_tmp__772&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__775;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__772;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__773:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%6, %%2  for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__771);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%storemerge12, %%1, !dbg !17 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1600_count);
  llvm_cbe_tmp__768 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__767&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__768&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%3 to i64, !dbg !17 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1601_count);
  llvm_cbe_tmp__769 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__768);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__769);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%output_matrix, i64 %%4, !dbg !17 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1602_count);
  llvm_cbe_tmp__770 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__769))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__769));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%5, align 4, !dbg !17 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1603_count);
  *llvm_cbe_tmp__770 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @Padding1  --> \n", ++aesl_llvm_cbe_1604_count);
  llvm_cbe_tmp__771 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__771&4294967295ull)));
  if (((llvm_cbe_tmp__771&4294967295U) == (28u&4294967295U))) {
    goto llvm_cbe_tmp__774;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__771;   /* for PHI node */
    goto llvm_cbe_tmp__773;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__775:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Padding1}\n");
  return;
}


void Padding2(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1617_count = 0;
  static  unsigned long long aesl_llvm_cbe_1618_count = 0;
  static  unsigned long long aesl_llvm_cbe_1619_count = 0;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;
  static  unsigned long long aesl_llvm_cbe_1621_count = 0;
  static  unsigned long long aesl_llvm_cbe_1622_count = 0;
  static  unsigned long long aesl_llvm_cbe_1623_count = 0;
  static  unsigned long long aesl_llvm_cbe_1624_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1625_count = 0;
  static  unsigned long long aesl_llvm_cbe_1626_count = 0;
  static  unsigned long long aesl_llvm_cbe_1627_count = 0;
  static  unsigned long long aesl_llvm_cbe_1628_count = 0;
  unsigned int llvm_cbe_tmp__776;
  static  unsigned long long aesl_llvm_cbe_1629_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  unsigned int llvm_cbe_tmp__777;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  unsigned long long llvm_cbe_tmp__778;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  float *llvm_cbe_tmp__779;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
  unsigned int llvm_cbe_tmp__780;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1639_count = 0;
  static  unsigned long long aesl_llvm_cbe_1640_count = 0;
  unsigned int llvm_cbe_tmp__781;
  static  unsigned long long aesl_llvm_cbe_1641_count = 0;
  static  unsigned long long aesl_llvm_cbe_1642_count = 0;
  static  unsigned long long aesl_llvm_cbe_1643_count = 0;
  static  unsigned long long aesl_llvm_cbe_1644_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_1645_count = 0;
  static  unsigned long long aesl_llvm_cbe_1646_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Padding2\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%8, %%7  for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__781);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = mul nsw i32 %%storemerge3, 26, !dbg !17 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1628_count);
  llvm_cbe_tmp__776 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) * ((unsigned int )(26u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__776&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__782;

llvm_cbe_tmp__783:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge3, 1, !dbg !18 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1640_count);
  llvm_cbe_tmp__781 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__781&4294967295ull)));
  if (((llvm_cbe_tmp__781&4294967295U) == (26u&4294967295U))) {
    goto llvm_cbe_tmp__784;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__781;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__782:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.preheader ], [ %%6, %%2  for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__780);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%storemerge12, %%1, !dbg !17 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1630_count);
  llvm_cbe_tmp__777 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__776&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__777&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%3 to i64, !dbg !17 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1631_count);
  llvm_cbe_tmp__778 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__777);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__778);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%output_matrix, i64 %%4, !dbg !17 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1632_count);
  llvm_cbe_tmp__779 = (float *)(&llvm_cbe_output_matrix[(((signed long long )llvm_cbe_tmp__778))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__778));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%5, align 4, !dbg !17 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1633_count);
  *llvm_cbe_tmp__779 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @Padding2  --> \n", ++aesl_llvm_cbe_1634_count);
  llvm_cbe_tmp__780 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__780&4294967295ull)));
  if (((llvm_cbe_tmp__780&4294967295U) == (26u&4294967295U))) {
    goto llvm_cbe_tmp__783;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__780;   /* for PHI node */
    goto llvm_cbe_tmp__782;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__784:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Padding2}\n");
  return;
}


void OverturnKernel(float *llvm_cbe_input_matrix, float *llvm_cbe_output_matrix) {
  static  unsigned long long aesl_llvm_cbe_1647_count = 0;
  static  unsigned long long aesl_llvm_cbe_1648_count = 0;
  static  unsigned long long aesl_llvm_cbe_1649_count = 0;
  static  unsigned long long aesl_llvm_cbe_1650_count = 0;
  static  unsigned long long aesl_llvm_cbe_1651_count = 0;
  static  unsigned long long aesl_llvm_cbe_1652_count = 0;
  static  unsigned long long aesl_llvm_cbe_1653_count = 0;
  static  unsigned long long aesl_llvm_cbe_1654_count = 0;
  static  unsigned long long aesl_llvm_cbe_1655_count = 0;
  static  unsigned long long aesl_llvm_cbe_1656_count = 0;
  static  unsigned long long aesl_llvm_cbe_1657_count = 0;
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  float llvm_cbe_tmp__785;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
  float *llvm_cbe_tmp__786;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  float *llvm_cbe_tmp__787;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
  float llvm_cbe_tmp__788;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  float *llvm_cbe_tmp__789;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  float *llvm_cbe_tmp__790;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
  float llvm_cbe_tmp__791;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
  float *llvm_cbe_tmp__792;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;
  static  unsigned long long aesl_llvm_cbe_1684_count = 0;
  static  unsigned long long aesl_llvm_cbe_1685_count = 0;
  static  unsigned long long aesl_llvm_cbe_1686_count = 0;
  static  unsigned long long aesl_llvm_cbe_1687_count = 0;
  static  unsigned long long aesl_llvm_cbe_1688_count = 0;
  static  unsigned long long aesl_llvm_cbe_1689_count = 0;
  static  unsigned long long aesl_llvm_cbe_1690_count = 0;
  static  unsigned long long aesl_llvm_cbe_1691_count = 0;
  static  unsigned long long aesl_llvm_cbe_1692_count = 0;
  static  unsigned long long aesl_llvm_cbe_1693_count = 0;
  static  unsigned long long aesl_llvm_cbe_1694_count = 0;
  static  unsigned long long aesl_llvm_cbe_1695_count = 0;
  float *llvm_cbe_tmp__793;
  static  unsigned long long aesl_llvm_cbe_1696_count = 0;
  float llvm_cbe_tmp__794;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  float *llvm_cbe_tmp__795;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;
  static  unsigned long long aesl_llvm_cbe_1703_count = 0;
  static  unsigned long long aesl_llvm_cbe_1704_count = 0;
  float *llvm_cbe_tmp__796;
  static  unsigned long long aesl_llvm_cbe_1705_count = 0;
  float llvm_cbe_tmp__797;
  static  unsigned long long aesl_llvm_cbe_1706_count = 0;
  float *llvm_cbe_tmp__798;
  static  unsigned long long aesl_llvm_cbe_1707_count = 0;
  static  unsigned long long aesl_llvm_cbe_1708_count = 0;
  static  unsigned long long aesl_llvm_cbe_1709_count = 0;
  static  unsigned long long aesl_llvm_cbe_1710_count = 0;
  static  unsigned long long aesl_llvm_cbe_1711_count = 0;
  static  unsigned long long aesl_llvm_cbe_1712_count = 0;
  static  unsigned long long aesl_llvm_cbe_1713_count = 0;
  float *llvm_cbe_tmp__799;
  static  unsigned long long aesl_llvm_cbe_1714_count = 0;
  float llvm_cbe_tmp__800;
  static  unsigned long long aesl_llvm_cbe_1715_count = 0;
  float *llvm_cbe_tmp__801;
  static  unsigned long long aesl_llvm_cbe_1716_count = 0;
  static  unsigned long long aesl_llvm_cbe_1717_count = 0;
  static  unsigned long long aesl_llvm_cbe_1718_count = 0;
  static  unsigned long long aesl_llvm_cbe_1719_count = 0;
  static  unsigned long long aesl_llvm_cbe_1720_count = 0;
  static  unsigned long long aesl_llvm_cbe_1721_count = 0;
  static  unsigned long long aesl_llvm_cbe_1722_count = 0;
  static  unsigned long long aesl_llvm_cbe_1723_count = 0;
  static  unsigned long long aesl_llvm_cbe_1724_count = 0;
  static  unsigned long long aesl_llvm_cbe_1725_count = 0;
  static  unsigned long long aesl_llvm_cbe_1726_count = 0;
  static  unsigned long long aesl_llvm_cbe_1727_count = 0;
  static  unsigned long long aesl_llvm_cbe_1728_count = 0;
  static  unsigned long long aesl_llvm_cbe_1729_count = 0;
  static  unsigned long long aesl_llvm_cbe_1730_count = 0;
  static  unsigned long long aesl_llvm_cbe_1731_count = 0;
  float *llvm_cbe_tmp__802;
  static  unsigned long long aesl_llvm_cbe_1732_count = 0;
  float llvm_cbe_tmp__803;
  static  unsigned long long aesl_llvm_cbe_1733_count = 0;
  float *llvm_cbe_tmp__804;
  static  unsigned long long aesl_llvm_cbe_1734_count = 0;
  static  unsigned long long aesl_llvm_cbe_1735_count = 0;
  static  unsigned long long aesl_llvm_cbe_1736_count = 0;
  static  unsigned long long aesl_llvm_cbe_1737_count = 0;
  static  unsigned long long aesl_llvm_cbe_1738_count = 0;
  static  unsigned long long aesl_llvm_cbe_1739_count = 0;
  static  unsigned long long aesl_llvm_cbe_1740_count = 0;
  float *llvm_cbe_tmp__805;
  static  unsigned long long aesl_llvm_cbe_1741_count = 0;
  float llvm_cbe_tmp__806;
  static  unsigned long long aesl_llvm_cbe_1742_count = 0;
  float *llvm_cbe_tmp__807;
  static  unsigned long long aesl_llvm_cbe_1743_count = 0;
  static  unsigned long long aesl_llvm_cbe_1744_count = 0;
  static  unsigned long long aesl_llvm_cbe_1745_count = 0;
  static  unsigned long long aesl_llvm_cbe_1746_count = 0;
  static  unsigned long long aesl_llvm_cbe_1747_count = 0;
  static  unsigned long long aesl_llvm_cbe_1748_count = 0;
  static  unsigned long long aesl_llvm_cbe_1749_count = 0;
  float *llvm_cbe_tmp__808;
  static  unsigned long long aesl_llvm_cbe_1750_count = 0;
  float llvm_cbe_tmp__809;
  static  unsigned long long aesl_llvm_cbe_1751_count = 0;
  static  unsigned long long aesl_llvm_cbe_1752_count = 0;
  static  unsigned long long aesl_llvm_cbe_1753_count = 0;
  static  unsigned long long aesl_llvm_cbe_1754_count = 0;
  static  unsigned long long aesl_llvm_cbe_1755_count = 0;
  static  unsigned long long aesl_llvm_cbe_1756_count = 0;
  static  unsigned long long aesl_llvm_cbe_1757_count = 0;
  static  unsigned long long aesl_llvm_cbe_1758_count = 0;
  static  unsigned long long aesl_llvm_cbe_1759_count = 0;
  static  unsigned long long aesl_llvm_cbe_1760_count = 0;
  static  unsigned long long aesl_llvm_cbe_1761_count = 0;
  static  unsigned long long aesl_llvm_cbe_1762_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @OverturnKernel\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = load float* %%input_matrix, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1660_count);
  llvm_cbe_tmp__785 = (float )*llvm_cbe_input_matrix;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__785, *(int*)(&llvm_cbe_tmp__785));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds float* %%output_matrix, i64 8, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1661_count);
  llvm_cbe_tmp__786 = (float *)(&llvm_cbe_output_matrix[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%0, float* %%1, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1662_count);
  *llvm_cbe_tmp__786 = llvm_cbe_tmp__785;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__785);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds float* %%input_matrix, i64 1, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1668_count);
  llvm_cbe_tmp__787 = (float *)(&llvm_cbe_input_matrix[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load float* %%2, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1669_count);
  llvm_cbe_tmp__788 = (float )*llvm_cbe_tmp__787;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__788, *(int*)(&llvm_cbe_tmp__788));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds float* %%output_matrix, i64 7, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1670_count);
  llvm_cbe_tmp__789 = (float *)(&llvm_cbe_output_matrix[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%3, float* %%4, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1671_count);
  *llvm_cbe_tmp__789 = llvm_cbe_tmp__788;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__788);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%input_matrix, i64 2, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1677_count);
  llvm_cbe_tmp__790 = (float *)(&llvm_cbe_input_matrix[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1678_count);
  llvm_cbe_tmp__791 = (float )*llvm_cbe_tmp__790;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__791, *(int*)(&llvm_cbe_tmp__791));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds float* %%output_matrix, i64 6, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1679_count);
  llvm_cbe_tmp__792 = (float *)(&llvm_cbe_output_matrix[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%6, float* %%7, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1680_count);
  *llvm_cbe_tmp__792 = llvm_cbe_tmp__791;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__791);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds float* %%input_matrix, i64 3, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1695_count);
  llvm_cbe_tmp__793 = (float *)(&llvm_cbe_input_matrix[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load float* %%8, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1696_count);
  llvm_cbe_tmp__794 = (float )*llvm_cbe_tmp__793;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__794, *(int*)(&llvm_cbe_tmp__794));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds float* %%output_matrix, i64 5, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1697_count);
  llvm_cbe_tmp__795 = (float *)(&llvm_cbe_output_matrix[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* %%10, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1698_count);
  *llvm_cbe_tmp__795 = llvm_cbe_tmp__794;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__794);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds float* %%input_matrix, i64 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1704_count);
  llvm_cbe_tmp__796 = (float *)(&llvm_cbe_input_matrix[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1705_count);
  llvm_cbe_tmp__797 = (float )*llvm_cbe_tmp__796;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__797, *(int*)(&llvm_cbe_tmp__797));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds float* %%output_matrix, i64 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1706_count);
  llvm_cbe_tmp__798 = (float *)(&llvm_cbe_output_matrix[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%13, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1707_count);
  *llvm_cbe_tmp__798 = llvm_cbe_tmp__797;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__797);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds float* %%input_matrix, i64 5, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1713_count);
  llvm_cbe_tmp__799 = (float *)(&llvm_cbe_input_matrix[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load float* %%14, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1714_count);
  llvm_cbe_tmp__800 = (float )*llvm_cbe_tmp__799;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__800, *(int*)(&llvm_cbe_tmp__800));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds float* %%output_matrix, i64 3, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1715_count);
  llvm_cbe_tmp__801 = (float *)(&llvm_cbe_output_matrix[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%15, float* %%16, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1716_count);
  *llvm_cbe_tmp__801 = llvm_cbe_tmp__800;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__800);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds float* %%input_matrix, i64 6, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1731_count);
  llvm_cbe_tmp__802 = (float *)(&llvm_cbe_input_matrix[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load float* %%17, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1732_count);
  llvm_cbe_tmp__803 = (float )*llvm_cbe_tmp__802;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__803, *(int*)(&llvm_cbe_tmp__803));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds float* %%output_matrix, i64 2, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1733_count);
  llvm_cbe_tmp__804 = (float *)(&llvm_cbe_output_matrix[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%18, float* %%19, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1734_count);
  *llvm_cbe_tmp__804 = llvm_cbe_tmp__803;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__803);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds float* %%input_matrix, i64 7, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1740_count);
  llvm_cbe_tmp__805 = (float *)(&llvm_cbe_input_matrix[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load float* %%20, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1741_count);
  llvm_cbe_tmp__806 = (float )*llvm_cbe_tmp__805;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__806, *(int*)(&llvm_cbe_tmp__806));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds float* %%output_matrix, i64 1, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1742_count);
  llvm_cbe_tmp__807 = (float *)(&llvm_cbe_output_matrix[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%21, float* %%22, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1743_count);
  *llvm_cbe_tmp__807 = llvm_cbe_tmp__806;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__806);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds float* %%input_matrix, i64 8, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1749_count);
  llvm_cbe_tmp__808 = (float *)(&llvm_cbe_input_matrix[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load float* %%23, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1750_count);
  llvm_cbe_tmp__809 = (float )*llvm_cbe_tmp__808;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__809, *(int*)(&llvm_cbe_tmp__809));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%24, float* %%output_matrix, align 4, !dbg !17 for 0x%I64xth hint within @OverturnKernel  --> \n", ++aesl_llvm_cbe_1751_count);
  *llvm_cbe_output_matrix = llvm_cbe_tmp__809;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__809);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @OverturnKernel}\n");
  return;
}


void MatrixSplit(float *llvm_cbe_input_matrix, float *llvm_cbe_splited_matrix1) {
  static  unsigned long long aesl_llvm_cbe_1763_count = 0;
  static  unsigned long long aesl_llvm_cbe_1764_count = 0;
  static  unsigned long long aesl_llvm_cbe_1765_count = 0;
  static  unsigned long long aesl_llvm_cbe_1766_count = 0;
  static  unsigned long long aesl_llvm_cbe_1767_count = 0;
  static  unsigned long long aesl_llvm_cbe_1768_count = 0;
  static  unsigned long long aesl_llvm_cbe_1769_count = 0;
  static  unsigned long long aesl_llvm_cbe_1770_count = 0;
  static  unsigned long long aesl_llvm_cbe_1771_count = 0;
  static  unsigned long long aesl_llvm_cbe_1772_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1773_count = 0;
  unsigned long long llvm_cbe_tmp__810;
  static  unsigned long long aesl_llvm_cbe_1774_count = 0;
  float *llvm_cbe_tmp__811;
  static  unsigned long long aesl_llvm_cbe_1775_count = 0;
  float llvm_cbe_tmp__812;
  static  unsigned long long aesl_llvm_cbe_1776_count = 0;
  float *llvm_cbe_tmp__813;
  static  unsigned long long aesl_llvm_cbe_1777_count = 0;
  static  unsigned long long aesl_llvm_cbe_1778_count = 0;
  unsigned int llvm_cbe_tmp__814;
  static  unsigned long long aesl_llvm_cbe_1779_count = 0;
  static  unsigned long long aesl_llvm_cbe_1780_count = 0;
  static  unsigned long long aesl_llvm_cbe_1781_count = 0;
  static  unsigned long long aesl_llvm_cbe_1782_count = 0;
  static  unsigned long long aesl_llvm_cbe_1783_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1784_count = 0;
  static  unsigned long long aesl_llvm_cbe_1785_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @MatrixSplit\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__815;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__815:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__814);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !17 for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_1773_count);
  llvm_cbe_tmp__810 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__810);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds float* %%input_matrix, i64 %%2, !dbg !17 for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_1774_count);
  llvm_cbe_tmp__811 = (float *)(&llvm_cbe_input_matrix[(((signed long long )llvm_cbe_tmp__810))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__810));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !17 for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_1775_count);
  llvm_cbe_tmp__812 = (float )*llvm_cbe_tmp__811;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__812, *(int*)(&llvm_cbe_tmp__812));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds float* %%splited_matrix1, i64 %%2, !dbg !17 for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_1776_count);
  llvm_cbe_tmp__813 = (float *)(&llvm_cbe_splited_matrix1[(((signed long long )llvm_cbe_tmp__810))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__810));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%4, float* %%5, align 4, !dbg !17 for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_1777_count);
  *llvm_cbe_tmp__813 = llvm_cbe_tmp__812;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__812);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @MatrixSplit  --> \n", ++aesl_llvm_cbe_1778_count);
  llvm_cbe_tmp__814 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__814&4294967295ull)));
  if (((llvm_cbe_tmp__814&4294967295U) == (576u&4294967295U))) {
    goto llvm_cbe_tmp__816;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__814;   /* for PHI node */
    goto llvm_cbe_tmp__815;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__816:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @MatrixSplit}\n");
  return;
}


void backward(signed int llvm_cbe_label, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3) {
  static  unsigned long long aesl_llvm_cbe_out_wgrad_count = 0;
  float llvm_cbe_out_wgrad[450];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_rgrad_count = 0;
  float llvm_cbe_second_rgrad[45];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_grad_count = 0;
  float llvm_cbe_second_grad[180];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_wgrad_count = 0;
  float llvm_cbe_second_wgrad[8100];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_first_rgrad_count = 0;
  float llvm_cbe_first_rgrad[180];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_first_grad_count = 0;
  float llvm_cbe_first_grad[180];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_first_wgrad_count = 0;
  float llvm_cbe_first_wgrad[103680];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_third_conv_grad1_count = 0;
  float llvm_cbe_third_conv_grad1[576];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_third_kernel_grad_count = 0;
  float llvm_cbe_third_kernel_grad[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_conv_grad1_count = 0;
  float llvm_cbe_second_conv_grad1[676];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_third_kernel_overturn_count = 0;
  float llvm_cbe_third_kernel_overturn[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_third_conv_grad_padding1_count = 0;
  float llvm_cbe_third_conv_grad_padding1[784];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_kernel_grad_count = 0;
  float llvm_cbe_second_kernel_grad[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_first_conv_grad_count = 0;
  float llvm_cbe_first_conv_grad[784];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_kernel_overturn_count = 0;
  float llvm_cbe_second_kernel_overturn[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_second_conv_grad_padding1_count = 0;
  float llvm_cbe_second_conv_grad_padding1[900];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_first_kernel_grad_count = 0;
  float llvm_cbe_first_kernel_grad[9];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1786_count = 0;
  static  unsigned long long aesl_llvm_cbe_1787_count = 0;
  static  unsigned long long aesl_llvm_cbe_1788_count = 0;
  static  unsigned long long aesl_llvm_cbe_1789_count = 0;
  static  unsigned long long aesl_llvm_cbe_1790_count = 0;
  static  unsigned long long aesl_llvm_cbe_1791_count = 0;
  static  unsigned long long aesl_llvm_cbe_1792_count = 0;
  static  unsigned long long aesl_llvm_cbe_1793_count = 0;
  static  unsigned long long aesl_llvm_cbe_1794_count = 0;
  static  unsigned long long aesl_llvm_cbe_1795_count = 0;
  static  unsigned long long aesl_llvm_cbe_1796_count = 0;
  static  unsigned long long aesl_llvm_cbe_1797_count = 0;
  static  unsigned long long aesl_llvm_cbe_1798_count = 0;
  static  unsigned long long aesl_llvm_cbe_1799_count = 0;
  static  unsigned long long aesl_llvm_cbe_1800_count = 0;
  static  unsigned long long aesl_llvm_cbe_1801_count = 0;
  static  unsigned long long aesl_llvm_cbe_1802_count = 0;
  static  unsigned long long aesl_llvm_cbe_1803_count = 0;
  static  unsigned long long aesl_llvm_cbe_1804_count = 0;
  static  unsigned long long aesl_llvm_cbe_1805_count = 0;
  static  unsigned long long aesl_llvm_cbe_1806_count = 0;
  static  unsigned long long aesl_llvm_cbe_1807_count = 0;
  static  unsigned long long aesl_llvm_cbe_1808_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1809_count = 0;
  static  unsigned long long aesl_llvm_cbe_1810_count = 0;
  static  unsigned long long aesl_llvm_cbe_1811_count = 0;
  unsigned long long llvm_cbe_tmp__817;
  static  unsigned long long aesl_llvm_cbe_1812_count = 0;
  float *llvm_cbe_tmp__818;
  static  unsigned long long aesl_llvm_cbe_1813_count = 0;
  float llvm_cbe_tmp__819;
  static  unsigned long long aesl_llvm_cbe_1814_count = 0;
  float llvm_cbe_tmp__820;
  static  unsigned long long aesl_llvm_cbe_1815_count = 0;
  float *llvm_cbe_tmp__821;
  static  unsigned long long aesl_llvm_cbe_1816_count = 0;
  static  unsigned long long aesl_llvm_cbe_1817_count = 0;
  static  unsigned long long aesl_llvm_cbe_1818_count = 0;
  unsigned long long llvm_cbe_tmp__822;
  static  unsigned long long aesl_llvm_cbe_1819_count = 0;
  float *llvm_cbe_tmp__823;
  static  unsigned long long aesl_llvm_cbe_1820_count = 0;
  float llvm_cbe_tmp__824;
  static  unsigned long long aesl_llvm_cbe_1821_count = 0;
  float *llvm_cbe_tmp__825;
  static  unsigned long long aesl_llvm_cbe_1822_count = 0;
  static  unsigned long long aesl_llvm_cbe_1823_count = 0;
  static  unsigned long long aesl_llvm_cbe_1824_count = 0;
  unsigned int llvm_cbe_tmp__826;
  static  unsigned long long aesl_llvm_cbe_1825_count = 0;
  static  unsigned long long aesl_llvm_cbe_1826_count = 0;
  static  unsigned long long aesl_llvm_cbe_1827_count = 0;
  static  unsigned long long aesl_llvm_cbe_1828_count = 0;
  static  unsigned long long aesl_llvm_cbe_1829_count = 0;
  static  unsigned long long aesl_llvm_cbe_1830_count = 0;
  static  unsigned long long aesl_llvm_cbe_1831_count = 0;
  static  unsigned long long aesl_llvm_cbe_1832_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1833_count = 0;
  static  unsigned long long aesl_llvm_cbe_1834_count = 0;
  static  unsigned long long aesl_llvm_cbe_1835_count = 0;
   char *llvm_cbe_tmp__827;
  static  unsigned long long aesl_llvm_cbe_1836_count = 0;
   char *llvm_cbe_tmp__828;
  static  unsigned long long aesl_llvm_cbe_1837_count = 0;
  float *llvm_cbe_tmp__829;
  static  unsigned long long aesl_llvm_cbe_1838_count = 0;
  static  unsigned long long aesl_llvm_cbe_1839_count = 0;
  static  unsigned long long aesl_llvm_cbe_1840_count = 0;
   char *llvm_cbe_tmp__830;
  static  unsigned long long aesl_llvm_cbe_1841_count = 0;
   char *llvm_cbe_tmp__831;
  static  unsigned long long aesl_llvm_cbe_1842_count = 0;
  float *llvm_cbe_tmp__832;
  static  unsigned long long aesl_llvm_cbe_1843_count = 0;
  static  unsigned long long aesl_llvm_cbe_1844_count = 0;
  static  unsigned long long aesl_llvm_cbe_1845_count = 0;
   char *llvm_cbe_tmp__833;
  static  unsigned long long aesl_llvm_cbe_1846_count = 0;
   char *llvm_cbe_tmp__834;
  static  unsigned long long aesl_llvm_cbe_1847_count = 0;
  float *llvm_cbe_tmp__835;
  static  unsigned long long aesl_llvm_cbe_1848_count = 0;
  static  unsigned long long aesl_llvm_cbe_1849_count = 0;
  static  unsigned long long aesl_llvm_cbe_1850_count = 0;
   char *llvm_cbe_tmp__836;
  static  unsigned long long aesl_llvm_cbe_1851_count = 0;
   char *llvm_cbe_tmp__837;
  static  unsigned long long aesl_llvm_cbe_1852_count = 0;
  float *llvm_cbe_tmp__838;
  static  unsigned long long aesl_llvm_cbe_1853_count = 0;
  static  unsigned long long aesl_llvm_cbe_1854_count = 0;
  static  unsigned long long aesl_llvm_cbe_1855_count = 0;
   char *llvm_cbe_tmp__839;
  static  unsigned long long aesl_llvm_cbe_1856_count = 0;
   char *llvm_cbe_tmp__840;
  static  unsigned long long aesl_llvm_cbe_1857_count = 0;
  float *llvm_cbe_tmp__841;
  static  unsigned long long aesl_llvm_cbe_1858_count = 0;
  static  unsigned long long aesl_llvm_cbe_1859_count = 0;
  static  unsigned long long aesl_llvm_cbe_1860_count = 0;
   char *llvm_cbe_tmp__842;
  static  unsigned long long aesl_llvm_cbe_1861_count = 0;
   char *llvm_cbe_tmp__843;
  static  unsigned long long aesl_llvm_cbe_1862_count = 0;
  float *llvm_cbe_tmp__844;
  static  unsigned long long aesl_llvm_cbe_1863_count = 0;
  static  unsigned long long aesl_llvm_cbe_1864_count = 0;
  static  unsigned long long aesl_llvm_cbe_1865_count = 0;
   char *llvm_cbe_tmp__845;
  static  unsigned long long aesl_llvm_cbe_1866_count = 0;
   char *llvm_cbe_tmp__846;
  static  unsigned long long aesl_llvm_cbe_1867_count = 0;
  float *llvm_cbe_tmp__847;
  static  unsigned long long aesl_llvm_cbe_1868_count = 0;
  static  unsigned long long aesl_llvm_cbe_1869_count = 0;
  static  unsigned long long aesl_llvm_cbe_1870_count = 0;
   char *llvm_cbe_tmp__848;
  static  unsigned long long aesl_llvm_cbe_1871_count = 0;
   char *llvm_cbe_tmp__849;
  static  unsigned long long aesl_llvm_cbe_1872_count = 0;
  float *llvm_cbe_tmp__850;
  static  unsigned long long aesl_llvm_cbe_1873_count = 0;
  static  unsigned long long aesl_llvm_cbe_1874_count = 0;
  static  unsigned long long aesl_llvm_cbe_1875_count = 0;
   char *llvm_cbe_tmp__851;
  static  unsigned long long aesl_llvm_cbe_1876_count = 0;
   char *llvm_cbe_tmp__852;
  static  unsigned long long aesl_llvm_cbe_1877_count = 0;
  float *llvm_cbe_tmp__853;
  static  unsigned long long aesl_llvm_cbe_1878_count = 0;
  static  unsigned long long aesl_llvm_cbe_1879_count = 0;
  static  unsigned long long aesl_llvm_cbe_1880_count = 0;
   char *llvm_cbe_tmp__854;
  static  unsigned long long aesl_llvm_cbe_1881_count = 0;
   char *llvm_cbe_tmp__855;
  static  unsigned long long aesl_llvm_cbe_1882_count = 0;
  static  unsigned long long aesl_llvm_cbe_1883_count = 0;
   char *llvm_cbe_tmp__856;
  static  unsigned long long aesl_llvm_cbe_1884_count = 0;
   char *llvm_cbe_tmp__857;
  static  unsigned long long aesl_llvm_cbe_1885_count = 0;
  float *llvm_cbe_tmp__858;
  static  unsigned long long aesl_llvm_cbe_1886_count = 0;
  static  unsigned long long aesl_llvm_cbe_1887_count = 0;
  static  unsigned long long aesl_llvm_cbe_1888_count = 0;
   char *llvm_cbe_tmp__859;
  static  unsigned long long aesl_llvm_cbe_1889_count = 0;
   char *llvm_cbe_tmp__860;
  static  unsigned long long aesl_llvm_cbe_1890_count = 0;
  float *llvm_cbe_tmp__861;
  static  unsigned long long aesl_llvm_cbe_1891_count = 0;
  static  unsigned long long aesl_llvm_cbe_1892_count = 0;
  float *llvm_cbe_tmp__862;
  static  unsigned long long aesl_llvm_cbe_1893_count = 0;
  static  unsigned long long aesl_llvm_cbe_1894_count = 0;
  static  unsigned long long aesl_llvm_cbe_1895_count = 0;
   char *llvm_cbe_tmp__863;
  static  unsigned long long aesl_llvm_cbe_1896_count = 0;
   char *llvm_cbe_tmp__864;
  static  unsigned long long aesl_llvm_cbe_1897_count = 0;
  float *llvm_cbe_tmp__865;
  static  unsigned long long aesl_llvm_cbe_1898_count = 0;
  static  unsigned long long aesl_llvm_cbe_1899_count = 0;
  static  unsigned long long aesl_llvm_cbe_1900_count = 0;
   char *llvm_cbe_tmp__866;
  static  unsigned long long aesl_llvm_cbe_1901_count = 0;
   char *llvm_cbe_tmp__867;
  static  unsigned long long aesl_llvm_cbe_1902_count = 0;
  static  unsigned long long aesl_llvm_cbe_1903_count = 0;
   char *llvm_cbe_tmp__868;
  static  unsigned long long aesl_llvm_cbe_1904_count = 0;
   char *llvm_cbe_tmp__869;
  static  unsigned long long aesl_llvm_cbe_1905_count = 0;
  float *llvm_cbe_tmp__870;
  static  unsigned long long aesl_llvm_cbe_1906_count = 0;
  static  unsigned long long aesl_llvm_cbe_1907_count = 0;
  static  unsigned long long aesl_llvm_cbe_1908_count = 0;
   char *llvm_cbe_tmp__871;
  static  unsigned long long aesl_llvm_cbe_1909_count = 0;
   char *llvm_cbe_tmp__872;
  static  unsigned long long aesl_llvm_cbe_1910_count = 0;
  float *llvm_cbe_tmp__873;
  static  unsigned long long aesl_llvm_cbe_1911_count = 0;
  static  unsigned long long aesl_llvm_cbe_1912_count = 0;
  float *llvm_cbe_tmp__874;
  static  unsigned long long aesl_llvm_cbe_1913_count = 0;
  static  unsigned long long aesl_llvm_cbe_1914_count = 0;
  static  unsigned long long aesl_llvm_cbe_1915_count = 0;
   char *llvm_cbe_tmp__875;
  static  unsigned long long aesl_llvm_cbe_1916_count = 0;
   char *llvm_cbe_tmp__876;
  static  unsigned long long aesl_llvm_cbe_1917_count = 0;
  float *llvm_cbe_tmp__877;
  static  unsigned long long aesl_llvm_cbe_1918_count = 0;
  static  unsigned long long aesl_llvm_cbe_1919_count = 0;
   char *llvm_cbe_tmp__878;
  static  unsigned long long aesl_llvm_cbe_1920_count = 0;
   char *llvm_cbe_tmp__879;
  static  unsigned long long aesl_llvm_cbe_1921_count = 0;
   char *llvm_cbe_tmp__880;
  static  unsigned long long aesl_llvm_cbe_1922_count = 0;
   char *llvm_cbe_tmp__881;
  static  unsigned long long aesl_llvm_cbe_1923_count = 0;
   char *llvm_cbe_tmp__882;
  static  unsigned long long aesl_llvm_cbe_1924_count = 0;
   char *llvm_cbe_tmp__883;
  static  unsigned long long aesl_llvm_cbe_1925_count = 0;
   char *llvm_cbe_tmp__884;
  static  unsigned long long aesl_llvm_cbe_1926_count = 0;
   char *llvm_cbe_tmp__885;
  static  unsigned long long aesl_llvm_cbe_1927_count = 0;
   char *llvm_cbe_tmp__886;
  static  unsigned long long aesl_llvm_cbe_1928_count = 0;
   char *llvm_cbe_tmp__887;
  static  unsigned long long aesl_llvm_cbe_1929_count = 0;
   char *llvm_cbe_tmp__888;
  static  unsigned long long aesl_llvm_cbe_1930_count = 0;
   char *llvm_cbe_tmp__889;
  static  unsigned long long aesl_llvm_cbe_1931_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @backward\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__890;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__890:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%15, %%14  for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__826);
}
  if (((llvm_cbe_storemerge1&4294967295U) == (llvm_cbe_label&4294967295U))) {
    goto llvm_cbe_tmp__891;
  } else {
    goto llvm_cbe_tmp__892;
  }

llvm_cbe_tmp__893:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge1, 1, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1824_count);
  llvm_cbe_tmp__826 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__826&4294967295ull)));
  if (((llvm_cbe_tmp__826&4294967295U) == (10u&4294967295U))) {
    goto llvm_cbe_tmp__894;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__826;   /* for PHI node */
    goto llvm_cbe_tmp__890;
  }

llvm_cbe_tmp__891:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%label to i64, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1811_count);
  llvm_cbe_tmp__817 = (unsigned long long )((signed long long )(signed int )llvm_cbe_label);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__817);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [10 x float]* @aesl_internal_result, i64 0, i64 %%4, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1812_count);
  llvm_cbe_tmp__818 = (float *)(&aesl_internal_result[(((signed long long )llvm_cbe_tmp__817))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__817));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__817) < 10)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_result' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1813_count);
  llvm_cbe_tmp__819 = (float )*llvm_cbe_tmp__818;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__819, *(int*)(&llvm_cbe_tmp__819));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = fadd float %%6, -1.000000e+00, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1814_count);
  llvm_cbe_tmp__820 = (float )((float )(llvm_cbe_tmp__819 + -0x1p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__820, *(int*)(&llvm_cbe_tmp__820));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [10 x float]* @aesl_internal_out_grad, i64 0, i64 %%4, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1815_count);
  llvm_cbe_tmp__821 = (float *)(&aesl_internal_out_grad[(((signed long long )llvm_cbe_tmp__817))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__817));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__817) < 10 && "Write access out of array 'aesl_internal_out_grad' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%7, float* %%8, align 4, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1816_count);
  *llvm_cbe_tmp__821 = llvm_cbe_tmp__820;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__820);
  goto llvm_cbe_tmp__893;

llvm_cbe_tmp__892:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge1 to i64, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1818_count);
  llvm_cbe_tmp__822 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__822);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [10 x float]* @aesl_internal_result, i64 0, i64 %%10, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1819_count);
  llvm_cbe_tmp__823 = (float *)(&aesl_internal_result[(((signed long long )llvm_cbe_tmp__822))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__822));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__822) < 10)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_result' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 4, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1820_count);
  llvm_cbe_tmp__824 = (float )*llvm_cbe_tmp__823;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__824, *(int*)(&llvm_cbe_tmp__824));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [10 x float]* @aesl_internal_out_grad, i64 0, i64 %%10, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1821_count);
  llvm_cbe_tmp__825 = (float *)(&aesl_internal_out_grad[(((signed long long )llvm_cbe_tmp__822))
#ifdef AESL_BC_SIM
 % 10
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__822));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__822) < 10 && "Write access out of array 'aesl_internal_out_grad' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%12, float* %%13, align 4, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1822_count);
  *llvm_cbe_tmp__825 = llvm_cbe_tmp__824;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__824);
  goto llvm_cbe_tmp__893;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__894:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = bitcast [450 x float]* %%out_wgrad to i8*, !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1835_count);
  llvm_cbe_tmp__827 = ( char *)(( char *)(&llvm_cbe_out_wgrad));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i8* @memset(i8* %%17, i32 0, i64 1800 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1836_count);
  ( char *)memset(( char *)llvm_cbe_tmp__827, 0u, 1800ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",1800ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__828);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [450 x float]* %%out_wgrad, i64 0, i64 0, !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1837_count);
  llvm_cbe_tmp__829 = (float *)(&llvm_cbe_out_wgrad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 450
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagationMultiply1(float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_second_relu, i64 0, i64 0, i64 0), float* getelementptr inbounds ([10 x float]* @aesl_internal_out_grad, i64 0, i64 0), float* %%19), !dbg !20 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1838_count);
  MatrixBackPropagationMultiply1((float *)((&aesl_internal_second_relu[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)((&aesl_internal_out_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), (float *)llvm_cbe_tmp__829);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = bitcast [45 x float]* %%second_rgrad to i8*, !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1840_count);
  llvm_cbe_tmp__830 = ( char *)(( char *)(&llvm_cbe_second_rgrad));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i8* @memset(i8* %%20, i32 0, i64 180 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1841_count);
  ( char *)memset(( char *)llvm_cbe_tmp__830, 0u, 180ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",180ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__831);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [45 x float]* %%second_rgrad, i64 0, i64 0, !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1842_count);
  llvm_cbe_tmp__832 = (float *)(&llvm_cbe_second_rgrad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @CalculateMatrixGrad1(float* getelementptr inbounds ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3, i64 0, i64 0, i64 0), float* getelementptr inbounds ([10 x float]* @aesl_internal_out_grad, i64 0, i64 0), float* %%22), !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1843_count);
  CalculateMatrixGrad1((float *)((&aesl_internal_fc_hidden_layer3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), (float *)((&aesl_internal_out_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), (float *)llvm_cbe_tmp__832);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = bitcast [180 x float]* %%second_grad to i8*, !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1845_count);
  llvm_cbe_tmp__833 = ( char *)(( char *)(&llvm_cbe_second_grad));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i8* @memset(i8* %%23, i32 0, i64 720 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1846_count);
  ( char *)memset(( char *)llvm_cbe_tmp__833, 0u, 720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__834);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [180 x float]* %%second_grad, i64 0, i64 0, !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1847_count);
  llvm_cbe_tmp__835 = (float *)(&llvm_cbe_second_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @ReluBackPropagation1(float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_second_fc, i64 0, i64 0, i64 0), float* %%22, float* %%25), !dbg !21 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1848_count);
  ReluBackPropagation1((float *)((&aesl_internal_second_fc[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)llvm_cbe_tmp__832, (float *)llvm_cbe_tmp__835);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = bitcast [8100 x float]* %%second_wgrad to i8*, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1850_count);
  llvm_cbe_tmp__836 = ( char *)(( char *)(&llvm_cbe_second_wgrad));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = call i8* @memset(i8* %%26, i32 0, i64 32400 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1851_count);
  ( char *)memset(( char *)llvm_cbe_tmp__836, 0u, 32400ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32400ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__837);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [8100 x float]* %%second_wgrad, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1852_count);
  llvm_cbe_tmp__838 = (float *)(&llvm_cbe_second_wgrad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagationMultiply2(float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_first_relu, i64 0, i64 0, i64 0), float* %%25, float* %%28), !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1853_count);
  MatrixBackPropagationMultiply2((float *)((&aesl_internal_first_relu[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)llvm_cbe_tmp__835, (float *)llvm_cbe_tmp__838);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = bitcast [180 x float]* %%first_rgrad to i8*, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1855_count);
  llvm_cbe_tmp__839 = ( char *)(( char *)(&llvm_cbe_first_rgrad));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call i8* @memset(i8* %%29, i32 0, i64 720 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1856_count);
  ( char *)memset(( char *)llvm_cbe_tmp__839, 0u, 720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__840);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [180 x float]* %%first_rgrad, i64 0, i64 0, !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1857_count);
  llvm_cbe_tmp__841 = (float *)(&llvm_cbe_first_rgrad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @CalculateMatrixGrad2(float* getelementptr inbounds ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2, i64 0, i64 0, i64 0), float* %%25, float* %%31), !dbg !22 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1858_count);
  CalculateMatrixGrad2((float *)((&aesl_internal_fc_hidden_layer2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)llvm_cbe_tmp__835, (float *)llvm_cbe_tmp__841);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = bitcast [180 x float]* %%first_grad to i8*, !dbg !23 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1860_count);
  llvm_cbe_tmp__842 = ( char *)(( char *)(&llvm_cbe_first_grad));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = call i8* @memset(i8* %%32, i32 0, i64 720 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1861_count);
  ( char *)memset(( char *)llvm_cbe_tmp__842, 0u, 720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__843);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [180 x float]* %%first_grad, i64 0, i64 0, !dbg !23 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1862_count);
  llvm_cbe_tmp__844 = (float *)(&llvm_cbe_first_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @ReluBackPropagation2(float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_first_fc, i64 0, i64 0, i64 0), float* %%31, float* %%34), !dbg !23 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1863_count);
  ReluBackPropagation2((float *)((&aesl_internal_first_fc[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)llvm_cbe_tmp__841, (float *)llvm_cbe_tmp__844);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = bitcast [103680 x float]* %%first_wgrad to i8*, !dbg !23 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1865_count);
  llvm_cbe_tmp__845 = ( char *)(( char *)(&llvm_cbe_first_wgrad));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = call i8* @memset(i8* %%35, i32 0, i64 414720 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1866_count);
  ( char *)memset(( char *)llvm_cbe_tmp__845, 0u, 414720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",414720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__846);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [103680 x float]* %%first_wgrad, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1867_count);
  llvm_cbe_tmp__847 = (float *)(&llvm_cbe_first_wgrad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 103680
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @MatrixBackPropagationMultiply3(float* getelementptr inbounds ([1 x [576 x float]]* @aesl_internal_flatten_conv, i64 0, i64 0, i64 0), float* %%34, float* %%37), !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1868_count);
  MatrixBackPropagationMultiply3((float *)((&aesl_internal_flatten_conv[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
])), (float *)llvm_cbe_tmp__844, (float *)llvm_cbe_tmp__847);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = bitcast [576 x float]* %%third_conv_grad1 to i8*, !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1870_count);
  llvm_cbe_tmp__848 = ( char *)(( char *)(&llvm_cbe_third_conv_grad1));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call i8* @memset(i8* %%38, i32 0, i64 2304 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1871_count);
  ( char *)memset(( char *)llvm_cbe_tmp__848, 0u, 2304ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",2304ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__849);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds [576 x float]* %%third_conv_grad1, i64 0, i64 0, !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1872_count);
  llvm_cbe_tmp__850 = (float *)(&llvm_cbe_third_conv_grad1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @CalculateMatrixGrad3(float* getelementptr inbounds ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1, i64 0, i64 0, i64 0), float* %%34, float* %%40), !dbg !24 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1873_count);
  CalculateMatrixGrad3((float *)((&aesl_internal_fc_hidden_layer1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)llvm_cbe_tmp__844, (float *)llvm_cbe_tmp__850);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = bitcast [9 x float]* %%third_kernel_grad to i8*, !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1875_count);
  llvm_cbe_tmp__851 = ( char *)(( char *)(&llvm_cbe_third_kernel_grad));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = call i8* @memset(i8* %%41, i32 0, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1876_count);
  ( char *)memset(( char *)llvm_cbe_tmp__851, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__852);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [9 x float]* %%third_kernel_grad, i64 0, i64 0, !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1877_count);
  llvm_cbe_tmp__853 = (float *)(&llvm_cbe_third_kernel_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d_b1(float* getelementptr inbounds ([26 x [26 x float]]* @aesl_internal_sencond_conv1, i64 0, i64 0, i64 0), float* %%40, float* %%43), !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1878_count);
  Conv2d_b1((float *)((&aesl_internal_sencond_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])), (float *)llvm_cbe_tmp__850, (float *)llvm_cbe_tmp__853);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = bitcast [676 x float]* %%second_conv_grad1 to i8*, !dbg !25 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1880_count);
  llvm_cbe_tmp__854 = ( char *)(( char *)(&llvm_cbe_second_conv_grad1));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call i8* @memset(i8* %%44, i32 0, i64 2704 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1881_count);
  ( char *)memset(( char *)llvm_cbe_tmp__854, 0u, 2704ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",2704ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__855);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = bitcast [9 x float]* %%third_kernel_overturn to i8*, !dbg !26 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1883_count);
  llvm_cbe_tmp__856 = ( char *)(( char *)(&llvm_cbe_third_kernel_overturn));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i8* @memset(i8* %%46, i32 0, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1884_count);
  ( char *)memset(( char *)llvm_cbe_tmp__856, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__857);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [9 x float]* %%third_kernel_overturn, i64 0, i64 0, !dbg !26 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1885_count);
  llvm_cbe_tmp__858 = (float *)(&llvm_cbe_third_kernel_overturn[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @OverturnKernel(float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel3, i64 0, i64 0, i64 0), float* %%48), !dbg !26 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1886_count);
  OverturnKernel((float *)((&aesl_internal_conv_kernel3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)llvm_cbe_tmp__858);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = bitcast [784 x float]* %%third_conv_grad_padding1 to i8*, !dbg !26 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1888_count);
  llvm_cbe_tmp__859 = ( char *)(( char *)(&llvm_cbe_third_conv_grad_padding1));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = call i8* @memset(i8* %%49, i32 0, i64 3136 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1889_count);
  ( char *)memset(( char *)llvm_cbe_tmp__859, 0u, 3136ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",3136ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__860);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [784 x float]* %%third_conv_grad_padding1, i64 0, i64 0, !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1890_count);
  llvm_cbe_tmp__861 = (float *)(&llvm_cbe_third_conv_grad_padding1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 784
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Padding1(float* %%40, float* %%51), !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1891_count);
  Padding1((float *)llvm_cbe_tmp__850, (float *)llvm_cbe_tmp__861);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds [676 x float]* %%second_conv_grad1, i64 0, i64 0, !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1892_count);
  llvm_cbe_tmp__862 = (float *)(&llvm_cbe_second_conv_grad1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 676
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d_b2(float* %%51, float* %%48, float* %%52), !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1893_count);
  Conv2d_b2((float *)llvm_cbe_tmp__861, (float *)llvm_cbe_tmp__858, (float *)llvm_cbe_tmp__862);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = bitcast [9 x float]* %%second_kernel_grad to i8*, !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1895_count);
  llvm_cbe_tmp__863 = ( char *)(( char *)(&llvm_cbe_second_kernel_grad));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = call i8* @memset(i8* %%53, i32 0, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1896_count);
  ( char *)memset(( char *)llvm_cbe_tmp__863, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__864);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [9 x float]* %%second_kernel_grad, i64 0, i64 0, !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1897_count);
  llvm_cbe_tmp__865 = (float *)(&llvm_cbe_second_kernel_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d_b3(float* getelementptr inbounds ([28 x [28 x float]]* @aesl_internal_first_conv1, i64 0, i64 0, i64 0), float* %%52, float* %%55), !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1898_count);
  Conv2d_b3((float *)((&aesl_internal_first_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), (float *)llvm_cbe_tmp__862, (float *)llvm_cbe_tmp__865);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = bitcast [784 x float]* %%first_conv_grad to i8*, !dbg !27 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1900_count);
  llvm_cbe_tmp__866 = ( char *)(( char *)(&llvm_cbe_first_conv_grad));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = call i8* @memset(i8* %%56, i32 0, i64 3136 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1901_count);
  ( char *)memset(( char *)llvm_cbe_tmp__866, 0u, 3136ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",3136ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__867);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = bitcast [9 x float]* %%second_kernel_overturn to i8*, !dbg !28 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1903_count);
  llvm_cbe_tmp__868 = ( char *)(( char *)(&llvm_cbe_second_kernel_overturn));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = call i8* @memset(i8* %%58, i32 0, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1904_count);
  ( char *)memset(( char *)llvm_cbe_tmp__868, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__869);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds [9 x float]* %%second_kernel_overturn, i64 0, i64 0, !dbg !28 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1905_count);
  llvm_cbe_tmp__870 = (float *)(&llvm_cbe_second_kernel_overturn[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @OverturnKernel(float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel2, i64 0, i64 0, i64 0), float* %%60), !dbg !28 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1906_count);
  OverturnKernel((float *)((&aesl_internal_conv_kernel2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)llvm_cbe_tmp__870);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = bitcast [900 x float]* %%second_conv_grad_padding1 to i8*, !dbg !28 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1908_count);
  llvm_cbe_tmp__871 = ( char *)(( char *)(&llvm_cbe_second_conv_grad_padding1));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = call i8* @memset(i8* %%61, i32 0, i64 3600 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1909_count);
  ( char *)memset(( char *)llvm_cbe_tmp__871, 0u, 3600ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",3600ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__872);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds [900 x float]* %%second_conv_grad_padding1, i64 0, i64 0, !dbg !28 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1910_count);
  llvm_cbe_tmp__873 = (float *)(&llvm_cbe_second_conv_grad_padding1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 900
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Padding2(float* %%52, float* %%63), !dbg !28 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1911_count);
  Padding2((float *)llvm_cbe_tmp__862, (float *)llvm_cbe_tmp__873);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [784 x float]* %%first_conv_grad, i64 0, i64 0, !dbg !29 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1912_count);
  llvm_cbe_tmp__874 = (float *)(&llvm_cbe_first_conv_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 784
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d_b4(float* %%63, float* %%60, float* %%64), !dbg !29 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1913_count);
  Conv2d_b4((float *)llvm_cbe_tmp__873, (float *)llvm_cbe_tmp__870, (float *)llvm_cbe_tmp__874);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = bitcast [9 x float]* %%first_kernel_grad to i8*, !dbg !29 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1915_count);
  llvm_cbe_tmp__875 = ( char *)(( char *)(&llvm_cbe_first_kernel_grad));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = call i8* @memset(i8* %%65, i32 0, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1916_count);
  ( char *)memset(( char *)llvm_cbe_tmp__875, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__876);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds [9 x float]* %%first_kernel_grad, i64 0, i64 0, !dbg !29 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1917_count);
  llvm_cbe_tmp__877 = (float *)(&llvm_cbe_first_kernel_grad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @Conv2d_b5(float* getelementptr inbounds ([30 x [30 x float]]* @aesl_internal_mnist_data, i64 0, i64 0, i64 0), float* %%64, float* %%67), !dbg !29 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1918_count);
  Conv2d_b5((float *)((&aesl_internal_mnist_data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), (float *)llvm_cbe_tmp__874, (float *)llvm_cbe_tmp__877);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = bitcast float* %%conv1 to i8*, !dbg !17 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1919_count);
  llvm_cbe_tmp__878 = ( char *)(( char *)llvm_cbe_conv1);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = call i8* @memcpy(i8* %%68, i8* %%65, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1920_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__878, ( char *)llvm_cbe_tmp__875, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__879);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = bitcast float* %%conv2 to i8*, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1921_count);
  llvm_cbe_tmp__880 = ( char *)(( char *)llvm_cbe_conv2);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = call i8* @memcpy(i8* %%70, i8* %%53, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1922_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__880, ( char *)llvm_cbe_tmp__863, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__881);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = bitcast float* %%conv3 to i8*, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1923_count);
  llvm_cbe_tmp__882 = ( char *)(( char *)llvm_cbe_conv3);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = call i8* @memcpy(i8* %%72, i8* %%41, i64 36 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1924_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__882, ( char *)llvm_cbe_tmp__851, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__883);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = bitcast float* %%fc1 to i8*, !dbg !18 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1925_count);
  llvm_cbe_tmp__884 = ( char *)(( char *)llvm_cbe_fc1);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = call i8* @memcpy(i8* %%74, i8* %%35, i64 414720 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1926_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__884, ( char *)llvm_cbe_tmp__845, 414720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",414720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__885);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = bitcast float* %%fc2 to i8*, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1927_count);
  llvm_cbe_tmp__886 = ( char *)(( char *)llvm_cbe_fc2);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = call i8* @memcpy(i8* %%76, i8* %%26, i64 32400 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1928_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__886, ( char *)llvm_cbe_tmp__836, 32400ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32400ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__887);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = bitcast float* %%fc3 to i8*, !dbg !19 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1929_count);
  llvm_cbe_tmp__888 = ( char *)(( char *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = call i8* @memcpy(i8* %%78, i8* %%17, i64 1800 for 0x%I64xth hint within @backward  --> \n", ++aesl_llvm_cbe_1930_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__888, ( char *)llvm_cbe_tmp__827, 1800ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1800ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__889);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @backward}\n");
  return;
}


void forward(float *llvm_cbe_input_matrix, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3) {
  static  unsigned long long aesl_llvm_cbe_1932_count = 0;
  static  unsigned long long aesl_llvm_cbe_1933_count = 0;
  static  unsigned long long aesl_llvm_cbe_1934_count = 0;
  static  unsigned long long aesl_llvm_cbe_1935_count = 0;
  static  unsigned long long aesl_llvm_cbe_1936_count = 0;
  static  unsigned long long aesl_llvm_cbe_1937_count = 0;
  static  unsigned long long aesl_llvm_cbe_1938_count = 0;
  static  unsigned long long aesl_llvm_cbe_1939_count = 0;
  static  unsigned long long aesl_llvm_cbe_1940_count = 0;
  static  unsigned long long aesl_llvm_cbe_1941_count = 0;
  static  unsigned long long aesl_llvm_cbe_1942_count = 0;
  static  unsigned long long aesl_llvm_cbe_1943_count = 0;
  static  unsigned long long aesl_llvm_cbe_1944_count = 0;
  static  unsigned long long aesl_llvm_cbe_1945_count = 0;
  static  unsigned long long aesl_llvm_cbe_1946_count = 0;
   char *llvm_cbe_tmp__895;
  static  unsigned long long aesl_llvm_cbe_1947_count = 0;
   char *llvm_cbe_tmp__896;
  static  unsigned long long aesl_llvm_cbe_1948_count = 0;
   char *llvm_cbe_tmp__897;
  static  unsigned long long aesl_llvm_cbe_1949_count = 0;
   char *llvm_cbe_tmp__898;
  static  unsigned long long aesl_llvm_cbe_1950_count = 0;
   char *llvm_cbe_tmp__899;
  static  unsigned long long aesl_llvm_cbe_1951_count = 0;
   char *llvm_cbe_tmp__900;
  static  unsigned long long aesl_llvm_cbe_1952_count = 0;
   char *llvm_cbe_tmp__901;
  static  unsigned long long aesl_llvm_cbe_1953_count = 0;
   char *llvm_cbe_tmp__902;
  static  unsigned long long aesl_llvm_cbe_1954_count = 0;
  static  unsigned long long aesl_llvm_cbe_1955_count = 0;
  static  unsigned long long aesl_llvm_cbe_1956_count = 0;
  static  unsigned long long aesl_llvm_cbe_1957_count = 0;
   char *llvm_cbe_tmp__903;
  static  unsigned long long aesl_llvm_cbe_1958_count = 0;
   char *llvm_cbe_tmp__904;
  static  unsigned long long aesl_llvm_cbe_1959_count = 0;
   char *llvm_cbe_tmp__905;
  static  unsigned long long aesl_llvm_cbe_1960_count = 0;
   char *llvm_cbe_tmp__906;
  static  unsigned long long aesl_llvm_cbe_1961_count = 0;
   char *llvm_cbe_tmp__907;
  static  unsigned long long aesl_llvm_cbe_1962_count = 0;
   char *llvm_cbe_tmp__908;
  static  unsigned long long aesl_llvm_cbe_1963_count = 0;
  static  unsigned long long aesl_llvm_cbe_1964_count = 0;
  static  unsigned long long aesl_llvm_cbe_1965_count = 0;
  static  unsigned long long aesl_llvm_cbe_1966_count = 0;
  static  unsigned long long aesl_llvm_cbe_1967_count = 0;
  static  unsigned long long aesl_llvm_cbe_1968_count = 0;
  static  unsigned long long aesl_llvm_cbe_1969_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @forward\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast float* %%input_matrix to i8*, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1946_count);
  llvm_cbe_tmp__895 = ( char *)(( char *)llvm_cbe_input_matrix);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memcpy(i8* bitcast ([30 x [30 x float]]* @aesl_internal_mnist_data to i8*), i8* %%1, i64 3600 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1947_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_mnist_data)), ( char *)llvm_cbe_tmp__895, 3600ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",3600ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__896);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast float* %%conv1 to i8*, !dbg !17 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1948_count);
  llvm_cbe_tmp__897 = ( char *)(( char *)llvm_cbe_conv1);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memcpy(i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel1 to i8*), i8* %%3, i64 36 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1949_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_conv_kernel1)), ( char *)llvm_cbe_tmp__897, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__898);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast float* %%conv2 to i8*, !dbg !18 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1950_count);
  llvm_cbe_tmp__899 = ( char *)(( char *)llvm_cbe_conv2);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @memcpy(i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel2 to i8*), i8* %%5, i64 36 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1951_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_conv_kernel2)), ( char *)llvm_cbe_tmp__899, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__900);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = bitcast float* %%conv3 to i8*, !dbg !18 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1952_count);
  llvm_cbe_tmp__901 = ( char *)(( char *)llvm_cbe_conv3);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memcpy(i8* bitcast ([3 x [3 x float]]* @aesl_internal_conv_kernel3 to i8*), i8* %%7, i64 36 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1953_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_conv_kernel3)), ( char *)llvm_cbe_tmp__901, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__902);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Conv2d1(float* getelementptr inbounds ([30 x [30 x float]]* @aesl_internal_mnist_data, i64 0, i64 0, i64 0), float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([28 x [28 x float]]* @aesl_internal_first_conv1, i64 0, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1954_count);
   /*tail*/ Conv2d1((float *)((&aesl_internal_mnist_data[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), (float *)((&aesl_internal_conv_kernel1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&aesl_internal_first_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Conv2d2(float* getelementptr inbounds ([28 x [28 x float]]* @aesl_internal_first_conv1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([26 x [26 x float]]* @aesl_internal_sencond_conv1, i64 0, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1955_count);
   /*tail*/ Conv2d2((float *)((&aesl_internal_first_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])), (float *)((&aesl_internal_conv_kernel2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&aesl_internal_sencond_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Conv2d3(float* getelementptr inbounds ([26 x [26 x float]]* @aesl_internal_sencond_conv1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([3 x [3 x float]]* @aesl_internal_conv_kernel3, i64 0, i64 0, i64 0), float* getelementptr inbounds ([24 x [24 x float]]* @aesl_internal_third_conv1, i64 0, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1956_count);
   /*tail*/ Conv2d3((float *)((&aesl_internal_sencond_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 26
#endif
])), (float *)((&aesl_internal_conv_kernel3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (float *)((&aesl_internal_third_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast float* %%fc1 to i8*, !dbg !18 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1957_count);
  llvm_cbe_tmp__903 = ( char *)(( char *)llvm_cbe_fc1);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memcpy(i8* bitcast ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1 to i8*), i8* %%9, i64 414720 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1958_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_fc_hidden_layer1)), ( char *)llvm_cbe_tmp__903, 414720ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",414720ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__904);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = bitcast float* %%fc2 to i8*, !dbg !18 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1959_count);
  llvm_cbe_tmp__905 = ( char *)(( char *)llvm_cbe_fc2);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i8* @memcpy(i8* bitcast ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2 to i8*), i8* %%11, i64 32400 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1960_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_fc_hidden_layer2)), ( char *)llvm_cbe_tmp__905, 32400ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32400ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__906);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = bitcast float* %%fc3 to i8*, !dbg !19 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1961_count);
  llvm_cbe_tmp__907 = ( char *)(( char *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i8* @memcpy(i8* bitcast ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3 to i8*), i8* %%13, i64 1800 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1962_count);
  ( char *)memcpy(( char *)(( char *)(&aesl_internal_fc_hidden_layer3)), ( char *)llvm_cbe_tmp__907, 1800ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1800ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__908);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixExtensionImproved(float* getelementptr inbounds ([24 x [24 x float]]* @aesl_internal_third_conv1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [576 x float]]* @aesl_internal_flatten_conv, i64 0, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1963_count);
   /*tail*/ MatrixExtensionImproved((float *)((&aesl_internal_third_conv1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
])), (float *)((&aesl_internal_flatten_conv[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 576
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixMultiply1(float* getelementptr inbounds ([1 x [576 x float]]* @aesl_internal_flatten_conv, i64 0, i64 0, i64 0), float* getelementptr inbounds ([576 x [180 x float]]* @aesl_internal_fc_hidden_layer1, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_first_fc, i64 0, i64 0, i64 0)), !dbg !19 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1964_count);
   /*tail*/ MatrixMultiply1((float *)((&aesl_internal_flatten_conv[(((signed long long )0ull))
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
])), (float *)((&aesl_internal_first_fc[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Relu1(float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_first_fc, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_first_relu, i64 0, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1965_count);
   /*tail*/ Relu1((float *)((&aesl_internal_first_fc[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])), (float *)((&aesl_internal_first_relu[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 180
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixMultiply2(float* getelementptr inbounds ([1 x [180 x float]]* @aesl_internal_first_relu, i64 0, i64 0, i64 0), float* getelementptr inbounds ([180 x [45 x float]]* @aesl_internal_fc_hidden_layer2, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_second_fc, i64 0, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1966_count);
   /*tail*/ MatrixMultiply2((float *)((&aesl_internal_first_relu[(((signed long long )0ull))
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
])), (float *)((&aesl_internal_second_fc[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @Relu2(float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_second_fc, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_second_relu, i64 0, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1967_count);
   /*tail*/ Relu2((float *)((&aesl_internal_second_fc[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), (float *)((&aesl_internal_second_relu[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @MatrixMultiply3(float* getelementptr inbounds ([1 x [45 x float]]* @aesl_internal_second_relu, i64 0, i64 0, i64 0), float* getelementptr inbounds ([45 x [10 x float]]* @aesl_internal_fc_hidden_layer3, i64 0, i64 0, i64 0), float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 0)), !dbg !20 for 0x%I64xth hint within @forward  --> \n", ++aesl_llvm_cbe_1968_count);
   /*tail*/ MatrixMultiply3((float *)((&aesl_internal_second_relu[(((signed long long )0ull))
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
])), (float *)((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])));
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @forward}\n");
  return;
}


void forw_back(signed int llvm_cbe_flag, float *llvm_cbe_in, float *llvm_cbe_conv1, float *llvm_cbe_conv2, float *llvm_cbe_conv3, float *llvm_cbe_fc1, float *llvm_cbe_fc2, float *llvm_cbe_fc3, float *llvm_cbe_out, signed int llvm_cbe_label) {
  static  unsigned long long aesl_llvm_cbe_1970_count = 0;
  static  unsigned long long aesl_llvm_cbe_1971_count = 0;
  static  unsigned long long aesl_llvm_cbe_1972_count = 0;
  static  unsigned long long aesl_llvm_cbe_1973_count = 0;
  static  unsigned long long aesl_llvm_cbe_1974_count = 0;
  static  unsigned long long aesl_llvm_cbe_1975_count = 0;
  static  unsigned long long aesl_llvm_cbe_1976_count = 0;
  static  unsigned long long aesl_llvm_cbe_1977_count = 0;
  static  unsigned long long aesl_llvm_cbe_1978_count = 0;
  static  unsigned long long aesl_llvm_cbe_1979_count = 0;
  static  unsigned long long aesl_llvm_cbe_1980_count = 0;
  static  unsigned long long aesl_llvm_cbe_1981_count = 0;
  static  unsigned long long aesl_llvm_cbe_1982_count = 0;
  static  unsigned long long aesl_llvm_cbe_1983_count = 0;
  static  unsigned long long aesl_llvm_cbe_1984_count = 0;
  static  unsigned long long aesl_llvm_cbe_1985_count = 0;
  static  unsigned long long aesl_llvm_cbe_1986_count = 0;
  static  unsigned long long aesl_llvm_cbe_1987_count = 0;
  static  unsigned long long aesl_llvm_cbe_1988_count = 0;
  static  unsigned long long aesl_llvm_cbe_1989_count = 0;
  static  unsigned long long aesl_llvm_cbe_1990_count = 0;
  static  unsigned long long aesl_llvm_cbe_1991_count = 0;
  static  unsigned long long aesl_llvm_cbe_1992_count = 0;
  static  unsigned long long aesl_llvm_cbe_1993_count = 0;
  static  unsigned long long aesl_llvm_cbe_1994_count = 0;
  static  unsigned long long aesl_llvm_cbe_1995_count = 0;
  static  unsigned long long aesl_llvm_cbe_1996_count = 0;
  static  unsigned long long aesl_llvm_cbe_1997_count = 0;
  static  unsigned long long aesl_llvm_cbe_1998_count = 0;
  static  unsigned long long aesl_llvm_cbe_1999_count = 0;
  static  unsigned long long aesl_llvm_cbe_2000_count = 0;
  static  unsigned long long aesl_llvm_cbe_2001_count = 0;
  static  unsigned long long aesl_llvm_cbe_2002_count = 0;
  static  unsigned long long aesl_llvm_cbe_2003_count = 0;
  static  unsigned long long aesl_llvm_cbe_2004_count = 0;
  static  unsigned long long aesl_llvm_cbe_2005_count = 0;
  static  unsigned long long aesl_llvm_cbe_2006_count = 0;
  static  unsigned long long aesl_llvm_cbe_2007_count = 0;
   char *llvm_cbe_tmp__909;
  static  unsigned long long aesl_llvm_cbe_2008_count = 0;
   char *llvm_cbe_tmp__910;
  static  unsigned long long aesl_llvm_cbe_2009_count = 0;
  static  unsigned long long aesl_llvm_cbe_2010_count = 0;
  static  unsigned long long aesl_llvm_cbe_2011_count = 0;
  static  unsigned long long aesl_llvm_cbe_2012_count = 0;
  static  unsigned long long aesl_llvm_cbe_2013_count = 0;
  static  unsigned long long aesl_llvm_cbe_2014_count = 0;
  static  unsigned long long aesl_llvm_cbe_2015_count = 0;
  static  unsigned long long aesl_llvm_cbe_2016_count = 0;
  static  unsigned long long aesl_llvm_cbe_2017_count = 0;
  static  unsigned long long aesl_llvm_cbe_2018_count = 0;
  float llvm_cbe_tmp__911;
  static  unsigned long long aesl_llvm_cbe_2019_count = 0;
  double llvm_cbe_tmp__912;
  static  unsigned long long aesl_llvm_cbe_2020_count = 0;
  double llvm_cbe_tmp__913;
  static  unsigned long long aesl_llvm_cbe_2021_count = 0;
  double llvm_cbe_tmp__914;
  static  unsigned long long aesl_llvm_cbe_2022_count = 0;
  float llvm_cbe_tmp__915;
  static  unsigned long long aesl_llvm_cbe_2023_count = 0;
  static  unsigned long long aesl_llvm_cbe_2024_count = 0;
  static  unsigned long long aesl_llvm_cbe_2025_count = 0;
  static  unsigned long long aesl_llvm_cbe_2026_count = 0;
  static  unsigned long long aesl_llvm_cbe_2027_count = 0;
  static  unsigned long long aesl_llvm_cbe_2028_count = 0;
  static  unsigned long long aesl_llvm_cbe_2029_count = 0;
  static  unsigned long long aesl_llvm_cbe_2030_count = 0;
  float llvm_cbe_tmp__916;
  static  unsigned long long aesl_llvm_cbe_2031_count = 0;
  double llvm_cbe_tmp__917;
  static  unsigned long long aesl_llvm_cbe_2032_count = 0;
  double llvm_cbe_tmp__918;
  static  unsigned long long aesl_llvm_cbe_2033_count = 0;
  double llvm_cbe_tmp__919;
  static  unsigned long long aesl_llvm_cbe_2034_count = 0;
  double llvm_cbe_tmp__920;
  static  unsigned long long aesl_llvm_cbe_2035_count = 0;
  float llvm_cbe_tmp__921;
  static  unsigned long long aesl_llvm_cbe_2036_count = 0;
  static  unsigned long long aesl_llvm_cbe_2037_count = 0;
  static  unsigned long long aesl_llvm_cbe_2038_count = 0;
  static  unsigned long long aesl_llvm_cbe_2039_count = 0;
  static  unsigned long long aesl_llvm_cbe_2040_count = 0;
  static  unsigned long long aesl_llvm_cbe_2041_count = 0;
  static  unsigned long long aesl_llvm_cbe_2042_count = 0;
  static  unsigned long long aesl_llvm_cbe_2043_count = 0;
  float llvm_cbe_tmp__922;
  static  unsigned long long aesl_llvm_cbe_2044_count = 0;
  double llvm_cbe_tmp__923;
  static  unsigned long long aesl_llvm_cbe_2045_count = 0;
  double llvm_cbe_tmp__924;
  static  unsigned long long aesl_llvm_cbe_2046_count = 0;
  double llvm_cbe_tmp__925;
  static  unsigned long long aesl_llvm_cbe_2047_count = 0;
  double llvm_cbe_tmp__926;
  static  unsigned long long aesl_llvm_cbe_2048_count = 0;
  float llvm_cbe_tmp__927;
  static  unsigned long long aesl_llvm_cbe_2049_count = 0;
  static  unsigned long long aesl_llvm_cbe_2050_count = 0;
  static  unsigned long long aesl_llvm_cbe_2051_count = 0;
  static  unsigned long long aesl_llvm_cbe_2052_count = 0;
  static  unsigned long long aesl_llvm_cbe_2053_count = 0;
  static  unsigned long long aesl_llvm_cbe_2054_count = 0;
  static  unsigned long long aesl_llvm_cbe_2055_count = 0;
  static  unsigned long long aesl_llvm_cbe_2056_count = 0;
  float llvm_cbe_tmp__928;
  static  unsigned long long aesl_llvm_cbe_2057_count = 0;
  double llvm_cbe_tmp__929;
  static  unsigned long long aesl_llvm_cbe_2058_count = 0;
  double llvm_cbe_tmp__930;
  static  unsigned long long aesl_llvm_cbe_2059_count = 0;
  double llvm_cbe_tmp__931;
  static  unsigned long long aesl_llvm_cbe_2060_count = 0;
  double llvm_cbe_tmp__932;
  static  unsigned long long aesl_llvm_cbe_2061_count = 0;
  float llvm_cbe_tmp__933;
  static  unsigned long long aesl_llvm_cbe_2062_count = 0;
  static  unsigned long long aesl_llvm_cbe_2063_count = 0;
  static  unsigned long long aesl_llvm_cbe_2064_count = 0;
  static  unsigned long long aesl_llvm_cbe_2065_count = 0;
  static  unsigned long long aesl_llvm_cbe_2066_count = 0;
  static  unsigned long long aesl_llvm_cbe_2067_count = 0;
  static  unsigned long long aesl_llvm_cbe_2068_count = 0;
  static  unsigned long long aesl_llvm_cbe_2069_count = 0;
  float llvm_cbe_tmp__934;
  static  unsigned long long aesl_llvm_cbe_2070_count = 0;
  double llvm_cbe_tmp__935;
  static  unsigned long long aesl_llvm_cbe_2071_count = 0;
  double llvm_cbe_tmp__936;
  static  unsigned long long aesl_llvm_cbe_2072_count = 0;
  double llvm_cbe_tmp__937;
  static  unsigned long long aesl_llvm_cbe_2073_count = 0;
  double llvm_cbe_tmp__938;
  static  unsigned long long aesl_llvm_cbe_2074_count = 0;
  float llvm_cbe_tmp__939;
  static  unsigned long long aesl_llvm_cbe_2075_count = 0;
  static  unsigned long long aesl_llvm_cbe_2076_count = 0;
  static  unsigned long long aesl_llvm_cbe_2077_count = 0;
  static  unsigned long long aesl_llvm_cbe_2078_count = 0;
  static  unsigned long long aesl_llvm_cbe_2079_count = 0;
  static  unsigned long long aesl_llvm_cbe_2080_count = 0;
  static  unsigned long long aesl_llvm_cbe_2081_count = 0;
  static  unsigned long long aesl_llvm_cbe_2082_count = 0;
  float llvm_cbe_tmp__940;
  static  unsigned long long aesl_llvm_cbe_2083_count = 0;
  double llvm_cbe_tmp__941;
  static  unsigned long long aesl_llvm_cbe_2084_count = 0;
  double llvm_cbe_tmp__942;
  static  unsigned long long aesl_llvm_cbe_2085_count = 0;
  double llvm_cbe_tmp__943;
  static  unsigned long long aesl_llvm_cbe_2086_count = 0;
  double llvm_cbe_tmp__944;
  static  unsigned long long aesl_llvm_cbe_2087_count = 0;
  float llvm_cbe_tmp__945;
  static  unsigned long long aesl_llvm_cbe_2088_count = 0;
  static  unsigned long long aesl_llvm_cbe_2089_count = 0;
  static  unsigned long long aesl_llvm_cbe_2090_count = 0;
  static  unsigned long long aesl_llvm_cbe_2091_count = 0;
  static  unsigned long long aesl_llvm_cbe_2092_count = 0;
  static  unsigned long long aesl_llvm_cbe_2093_count = 0;
  static  unsigned long long aesl_llvm_cbe_2094_count = 0;
  static  unsigned long long aesl_llvm_cbe_2095_count = 0;
  float llvm_cbe_tmp__946;
  static  unsigned long long aesl_llvm_cbe_2096_count = 0;
  double llvm_cbe_tmp__947;
  static  unsigned long long aesl_llvm_cbe_2097_count = 0;
  double llvm_cbe_tmp__948;
  static  unsigned long long aesl_llvm_cbe_2098_count = 0;
  double llvm_cbe_tmp__949;
  static  unsigned long long aesl_llvm_cbe_2099_count = 0;
  double llvm_cbe_tmp__950;
  static  unsigned long long aesl_llvm_cbe_2100_count = 0;
  float llvm_cbe_tmp__951;
  static  unsigned long long aesl_llvm_cbe_2101_count = 0;
  static  unsigned long long aesl_llvm_cbe_2102_count = 0;
  static  unsigned long long aesl_llvm_cbe_2103_count = 0;
  static  unsigned long long aesl_llvm_cbe_2104_count = 0;
  static  unsigned long long aesl_llvm_cbe_2105_count = 0;
  static  unsigned long long aesl_llvm_cbe_2106_count = 0;
  static  unsigned long long aesl_llvm_cbe_2107_count = 0;
  static  unsigned long long aesl_llvm_cbe_2108_count = 0;
  float llvm_cbe_tmp__952;
  static  unsigned long long aesl_llvm_cbe_2109_count = 0;
  double llvm_cbe_tmp__953;
  static  unsigned long long aesl_llvm_cbe_2110_count = 0;
  double llvm_cbe_tmp__954;
  static  unsigned long long aesl_llvm_cbe_2111_count = 0;
  double llvm_cbe_tmp__955;
  static  unsigned long long aesl_llvm_cbe_2112_count = 0;
  double llvm_cbe_tmp__956;
  static  unsigned long long aesl_llvm_cbe_2113_count = 0;
  float llvm_cbe_tmp__957;
  static  unsigned long long aesl_llvm_cbe_2114_count = 0;
  static  unsigned long long aesl_llvm_cbe_2115_count = 0;
  static  unsigned long long aesl_llvm_cbe_2116_count = 0;
  static  unsigned long long aesl_llvm_cbe_2117_count = 0;
  static  unsigned long long aesl_llvm_cbe_2118_count = 0;
  static  unsigned long long aesl_llvm_cbe_2119_count = 0;
  static  unsigned long long aesl_llvm_cbe_2120_count = 0;
  static  unsigned long long aesl_llvm_cbe_2121_count = 0;
  float llvm_cbe_tmp__958;
  static  unsigned long long aesl_llvm_cbe_2122_count = 0;
  double llvm_cbe_tmp__959;
  static  unsigned long long aesl_llvm_cbe_2123_count = 0;
  double llvm_cbe_tmp__960;
  static  unsigned long long aesl_llvm_cbe_2124_count = 0;
  double llvm_cbe_tmp__961;
  static  unsigned long long aesl_llvm_cbe_2125_count = 0;
  double llvm_cbe_tmp__962;
  static  unsigned long long aesl_llvm_cbe_2126_count = 0;
  float llvm_cbe_tmp__963;
  static  unsigned long long aesl_llvm_cbe_2127_count = 0;
  static  unsigned long long aesl_llvm_cbe_2128_count = 0;
  static  unsigned long long aesl_llvm_cbe_2129_count = 0;
  static  unsigned long long aesl_llvm_cbe_2130_count = 0;
  static  unsigned long long aesl_llvm_cbe_2131_count = 0;
  static  unsigned long long aesl_llvm_cbe_2132_count = 0;
  static  unsigned long long aesl_llvm_cbe_2133_count = 0;
  static  unsigned long long aesl_llvm_cbe_2134_count = 0;
  float llvm_cbe_tmp__964;
  static  unsigned long long aesl_llvm_cbe_2135_count = 0;
  double llvm_cbe_tmp__965;
  static  unsigned long long aesl_llvm_cbe_2136_count = 0;
  double llvm_cbe_tmp__966;
  static  unsigned long long aesl_llvm_cbe_2137_count = 0;
  double llvm_cbe_tmp__967;
  static  unsigned long long aesl_llvm_cbe_2138_count = 0;
  double llvm_cbe_tmp__968;
  static  unsigned long long aesl_llvm_cbe_2139_count = 0;
  float llvm_cbe_tmp__969;
  static  unsigned long long aesl_llvm_cbe_2140_count = 0;
  static  unsigned long long aesl_llvm_cbe_2141_count = 0;
  static  unsigned long long aesl_llvm_cbe_2142_count = 0;
  static  unsigned long long aesl_llvm_cbe_2143_count = 0;
  static  unsigned long long aesl_llvm_cbe_2144_count = 0;
  static  unsigned long long aesl_llvm_cbe_2145_count = 0;
  static  unsigned long long aesl_llvm_cbe_2146_count = 0;
  static  unsigned long long aesl_llvm_cbe_2147_count = 0;
  static  unsigned long long aesl_llvm_cbe_2148_count = 0;
  static  unsigned long long aesl_llvm_cbe_2149_count = 0;
  static  unsigned long long aesl_llvm_cbe_2150_count = 0;
  static  unsigned long long aesl_llvm_cbe_2151_count = 0;
  double llvm_cbe_tmp__970;
  static  unsigned long long aesl_llvm_cbe_2152_count = 0;
  float llvm_cbe_tmp__971;
  static  unsigned long long aesl_llvm_cbe_2153_count = 0;
  double llvm_cbe_tmp__972;
  static  unsigned long long aesl_llvm_cbe_2154_count = 0;
  double llvm_cbe_tmp__973;
  static  unsigned long long aesl_llvm_cbe_2155_count = 0;
  double llvm_cbe_tmp__974;
  static  unsigned long long aesl_llvm_cbe_2156_count = 0;
  float llvm_cbe_tmp__975;
  static  unsigned long long aesl_llvm_cbe_2157_count = 0;
  static  unsigned long long aesl_llvm_cbe_2158_count = 0;
  static  unsigned long long aesl_llvm_cbe_2159_count = 0;
  static  unsigned long long aesl_llvm_cbe_2160_count = 0;
  static  unsigned long long aesl_llvm_cbe_2161_count = 0;
  static  unsigned long long aesl_llvm_cbe_2162_count = 0;
  static  unsigned long long aesl_llvm_cbe_2163_count = 0;
  float llvm_cbe_tmp__976;
  static  unsigned long long aesl_llvm_cbe_2164_count = 0;
  double llvm_cbe_tmp__977;
  static  unsigned long long aesl_llvm_cbe_2165_count = 0;
  double llvm_cbe_tmp__978;
  static  unsigned long long aesl_llvm_cbe_2166_count = 0;
  double llvm_cbe_tmp__979;
  static  unsigned long long aesl_llvm_cbe_2167_count = 0;
  float llvm_cbe_tmp__980;
  static  unsigned long long aesl_llvm_cbe_2168_count = 0;
  static  unsigned long long aesl_llvm_cbe_2169_count = 0;
  static  unsigned long long aesl_llvm_cbe_2170_count = 0;
  static  unsigned long long aesl_llvm_cbe_2171_count = 0;
  static  unsigned long long aesl_llvm_cbe_2172_count = 0;
  static  unsigned long long aesl_llvm_cbe_2173_count = 0;
  static  unsigned long long aesl_llvm_cbe_2174_count = 0;
  float llvm_cbe_tmp__981;
  static  unsigned long long aesl_llvm_cbe_2175_count = 0;
  double llvm_cbe_tmp__982;
  static  unsigned long long aesl_llvm_cbe_2176_count = 0;
  double llvm_cbe_tmp__983;
  static  unsigned long long aesl_llvm_cbe_2177_count = 0;
  double llvm_cbe_tmp__984;
  static  unsigned long long aesl_llvm_cbe_2178_count = 0;
  float llvm_cbe_tmp__985;
  static  unsigned long long aesl_llvm_cbe_2179_count = 0;
  static  unsigned long long aesl_llvm_cbe_2180_count = 0;
  static  unsigned long long aesl_llvm_cbe_2181_count = 0;
  static  unsigned long long aesl_llvm_cbe_2182_count = 0;
  static  unsigned long long aesl_llvm_cbe_2183_count = 0;
  static  unsigned long long aesl_llvm_cbe_2184_count = 0;
  static  unsigned long long aesl_llvm_cbe_2185_count = 0;
  float llvm_cbe_tmp__986;
  static  unsigned long long aesl_llvm_cbe_2186_count = 0;
  double llvm_cbe_tmp__987;
  static  unsigned long long aesl_llvm_cbe_2187_count = 0;
  double llvm_cbe_tmp__988;
  static  unsigned long long aesl_llvm_cbe_2188_count = 0;
  double llvm_cbe_tmp__989;
  static  unsigned long long aesl_llvm_cbe_2189_count = 0;
  float llvm_cbe_tmp__990;
  static  unsigned long long aesl_llvm_cbe_2190_count = 0;
  static  unsigned long long aesl_llvm_cbe_2191_count = 0;
  static  unsigned long long aesl_llvm_cbe_2192_count = 0;
  static  unsigned long long aesl_llvm_cbe_2193_count = 0;
  static  unsigned long long aesl_llvm_cbe_2194_count = 0;
  static  unsigned long long aesl_llvm_cbe_2195_count = 0;
  static  unsigned long long aesl_llvm_cbe_2196_count = 0;
  float llvm_cbe_tmp__991;
  static  unsigned long long aesl_llvm_cbe_2197_count = 0;
  double llvm_cbe_tmp__992;
  static  unsigned long long aesl_llvm_cbe_2198_count = 0;
  double llvm_cbe_tmp__993;
  static  unsigned long long aesl_llvm_cbe_2199_count = 0;
  double llvm_cbe_tmp__994;
  static  unsigned long long aesl_llvm_cbe_2200_count = 0;
  float llvm_cbe_tmp__995;
  static  unsigned long long aesl_llvm_cbe_2201_count = 0;
  static  unsigned long long aesl_llvm_cbe_2202_count = 0;
  static  unsigned long long aesl_llvm_cbe_2203_count = 0;
  static  unsigned long long aesl_llvm_cbe_2204_count = 0;
  static  unsigned long long aesl_llvm_cbe_2205_count = 0;
  static  unsigned long long aesl_llvm_cbe_2206_count = 0;
  static  unsigned long long aesl_llvm_cbe_2207_count = 0;
  float llvm_cbe_tmp__996;
  static  unsigned long long aesl_llvm_cbe_2208_count = 0;
  double llvm_cbe_tmp__997;
  static  unsigned long long aesl_llvm_cbe_2209_count = 0;
  double llvm_cbe_tmp__998;
  static  unsigned long long aesl_llvm_cbe_2210_count = 0;
  double llvm_cbe_tmp__999;
  static  unsigned long long aesl_llvm_cbe_2211_count = 0;
  float llvm_cbe_tmp__1000;
  static  unsigned long long aesl_llvm_cbe_2212_count = 0;
  static  unsigned long long aesl_llvm_cbe_2213_count = 0;
  static  unsigned long long aesl_llvm_cbe_2214_count = 0;
  static  unsigned long long aesl_llvm_cbe_2215_count = 0;
  static  unsigned long long aesl_llvm_cbe_2216_count = 0;
  static  unsigned long long aesl_llvm_cbe_2217_count = 0;
  static  unsigned long long aesl_llvm_cbe_2218_count = 0;
  float llvm_cbe_tmp__1001;
  static  unsigned long long aesl_llvm_cbe_2219_count = 0;
  double llvm_cbe_tmp__1002;
  static  unsigned long long aesl_llvm_cbe_2220_count = 0;
  double llvm_cbe_tmp__1003;
  static  unsigned long long aesl_llvm_cbe_2221_count = 0;
  double llvm_cbe_tmp__1004;
  static  unsigned long long aesl_llvm_cbe_2222_count = 0;
  float llvm_cbe_tmp__1005;
  static  unsigned long long aesl_llvm_cbe_2223_count = 0;
  static  unsigned long long aesl_llvm_cbe_2224_count = 0;
  static  unsigned long long aesl_llvm_cbe_2225_count = 0;
  static  unsigned long long aesl_llvm_cbe_2226_count = 0;
  static  unsigned long long aesl_llvm_cbe_2227_count = 0;
  static  unsigned long long aesl_llvm_cbe_2228_count = 0;
  static  unsigned long long aesl_llvm_cbe_2229_count = 0;
  float llvm_cbe_tmp__1006;
  static  unsigned long long aesl_llvm_cbe_2230_count = 0;
  double llvm_cbe_tmp__1007;
  static  unsigned long long aesl_llvm_cbe_2231_count = 0;
  double llvm_cbe_tmp__1008;
  static  unsigned long long aesl_llvm_cbe_2232_count = 0;
  double llvm_cbe_tmp__1009;
  static  unsigned long long aesl_llvm_cbe_2233_count = 0;
  float llvm_cbe_tmp__1010;
  static  unsigned long long aesl_llvm_cbe_2234_count = 0;
  static  unsigned long long aesl_llvm_cbe_2235_count = 0;
  static  unsigned long long aesl_llvm_cbe_2236_count = 0;
  static  unsigned long long aesl_llvm_cbe_2237_count = 0;
  static  unsigned long long aesl_llvm_cbe_2238_count = 0;
  static  unsigned long long aesl_llvm_cbe_2239_count = 0;
  static  unsigned long long aesl_llvm_cbe_2240_count = 0;
  float llvm_cbe_tmp__1011;
  static  unsigned long long aesl_llvm_cbe_2241_count = 0;
  double llvm_cbe_tmp__1012;
  static  unsigned long long aesl_llvm_cbe_2242_count = 0;
  double llvm_cbe_tmp__1013;
  static  unsigned long long aesl_llvm_cbe_2243_count = 0;
  double llvm_cbe_tmp__1014;
  static  unsigned long long aesl_llvm_cbe_2244_count = 0;
  float llvm_cbe_tmp__1015;
  static  unsigned long long aesl_llvm_cbe_2245_count = 0;
  static  unsigned long long aesl_llvm_cbe_2246_count = 0;
  static  unsigned long long aesl_llvm_cbe_2247_count = 0;
  static  unsigned long long aesl_llvm_cbe_2248_count = 0;
  static  unsigned long long aesl_llvm_cbe_2249_count = 0;
  static  unsigned long long aesl_llvm_cbe_2250_count = 0;
  static  unsigned long long aesl_llvm_cbe_2251_count = 0;
  float llvm_cbe_tmp__1016;
  static  unsigned long long aesl_llvm_cbe_2252_count = 0;
  double llvm_cbe_tmp__1017;
  static  unsigned long long aesl_llvm_cbe_2253_count = 0;
  double llvm_cbe_tmp__1018;
  static  unsigned long long aesl_llvm_cbe_2254_count = 0;
  double llvm_cbe_tmp__1019;
  static  unsigned long long aesl_llvm_cbe_2255_count = 0;
  float llvm_cbe_tmp__1020;
  static  unsigned long long aesl_llvm_cbe_2256_count = 0;
  static  unsigned long long aesl_llvm_cbe_2257_count = 0;
  static  unsigned long long aesl_llvm_cbe_2258_count = 0;
  static  unsigned long long aesl_llvm_cbe_2259_count = 0;
  static  unsigned long long aesl_llvm_cbe_2260_count = 0;
  static  unsigned long long aesl_llvm_cbe_2261_count = 0;
  static  unsigned long long aesl_llvm_cbe_2262_count = 0;
  static  unsigned long long aesl_llvm_cbe_2263_count = 0;
   char *llvm_cbe_tmp__1021;
  static  unsigned long long aesl_llvm_cbe_2264_count = 0;
   char *llvm_cbe_tmp__1022;
  static  unsigned long long aesl_llvm_cbe_2265_count = 0;
  static  unsigned long long aesl_llvm_cbe_2266_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @forw_back\n");
  if (((llvm_cbe_flag&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__1023;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe_tmp__1023:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @forward(float* %%in, float* %%conv1, float* %%conv2, float* %%conv3, float* %%fc1, float* %%fc2, float* %%fc3), !dbg !17 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2006_count);
   /*tail*/ forward((float *)llvm_cbe_in, (float *)llvm_cbe_conv1, (float *)llvm_cbe_conv2, (float *)llvm_cbe_conv3, (float *)llvm_cbe_fc1, (float *)llvm_cbe_fc2, (float *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = bitcast float* %%out to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2007_count);
  llvm_cbe_tmp__909 = ( char *)(( char *)llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memcpy(i8* %%3, i8* bitcast ([1 x [10 x float]]* @aesl_internal_outmlp to i8*), i64 40 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2008_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__909, ( char *)(( char *)(&aesl_internal_outmlp)), 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__910);
}
  goto llvm_cbe_tmp__1024;

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @forward(float* %%in, float* %%conv1, float* %%conv2, float* %%conv3, float* %%fc1, float* %%fc2, float* %%fc3), !dbg !17 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2010_count);
   /*tail*/ forward((float *)llvm_cbe_in, (float *)llvm_cbe_conv1, (float *)llvm_cbe_conv2, (float *)llvm_cbe_conv3, (float *)llvm_cbe_fc1, (float *)llvm_cbe_fc2, (float *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 0), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2018_count);
  llvm_cbe_tmp__911 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__911, *(int*)(&llvm_cbe_tmp__911));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = fpext float %%5 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2019_count);
  llvm_cbe_tmp__912 = (double )((double )llvm_cbe_tmp__911);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__912, *(long long*)(&llvm_cbe_tmp__912));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call double @exp(double %%6) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2020_count);
  llvm_cbe_tmp__913 = (double ) /*tail*/ exp(llvm_cbe_tmp__912);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__912, *(long long*)(&llvm_cbe_tmp__912));
printf("\nReturn  = %lf",llvm_cbe_tmp__913);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fadd double %%7, 0.000000e+00, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2021_count);
  llvm_cbe_tmp__914 = (double )llvm_cbe_tmp__913 + 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__914, *(long long*)(&llvm_cbe_tmp__914));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fptrunc double %%8 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2022_count);
  llvm_cbe_tmp__915 = (float )((float )llvm_cbe_tmp__914);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__915, *(int*)(&llvm_cbe_tmp__915));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 1), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2030_count);
  llvm_cbe_tmp__916 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__916, *(int*)(&llvm_cbe_tmp__916));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fpext float %%10 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2031_count);
  llvm_cbe_tmp__917 = (double )((double )llvm_cbe_tmp__916);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__917, *(long long*)(&llvm_cbe_tmp__917));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call double @exp(double %%11) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2032_count);
  llvm_cbe_tmp__918 = (double ) /*tail*/ exp(llvm_cbe_tmp__917);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__917, *(long long*)(&llvm_cbe_tmp__917));
printf("\nReturn  = %lf",llvm_cbe_tmp__918);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fpext float %%9 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2033_count);
  llvm_cbe_tmp__919 = (double )((double )llvm_cbe_tmp__915);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__919, *(long long*)(&llvm_cbe_tmp__919));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = fadd double %%13, %%12, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2034_count);
  llvm_cbe_tmp__920 = (double )llvm_cbe_tmp__919 + llvm_cbe_tmp__918;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__920, *(long long*)(&llvm_cbe_tmp__920));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fptrunc double %%14 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2035_count);
  llvm_cbe_tmp__921 = (float )((float )llvm_cbe_tmp__920);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__921, *(int*)(&llvm_cbe_tmp__921));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 2), align 8, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2043_count);
  llvm_cbe_tmp__922 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__922, *(int*)(&llvm_cbe_tmp__922));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fpext float %%16 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2044_count);
  llvm_cbe_tmp__923 = (double )((double )llvm_cbe_tmp__922);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__923, *(long long*)(&llvm_cbe_tmp__923));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = tail call double @exp(double %%17) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2045_count);
  llvm_cbe_tmp__924 = (double ) /*tail*/ exp(llvm_cbe_tmp__923);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__923, *(long long*)(&llvm_cbe_tmp__923));
printf("\nReturn  = %lf",llvm_cbe_tmp__924);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = fpext float %%15 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2046_count);
  llvm_cbe_tmp__925 = (double )((double )llvm_cbe_tmp__921);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__925, *(long long*)(&llvm_cbe_tmp__925));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fadd double %%19, %%18, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2047_count);
  llvm_cbe_tmp__926 = (double )llvm_cbe_tmp__925 + llvm_cbe_tmp__924;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__926, *(long long*)(&llvm_cbe_tmp__926));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fptrunc double %%20 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2048_count);
  llvm_cbe_tmp__927 = (float )((float )llvm_cbe_tmp__926);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__927, *(int*)(&llvm_cbe_tmp__927));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 3), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2056_count);
  llvm_cbe_tmp__928 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__928, *(int*)(&llvm_cbe_tmp__928));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = fpext float %%22 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2057_count);
  llvm_cbe_tmp__929 = (double )((double )llvm_cbe_tmp__928);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__929, *(long long*)(&llvm_cbe_tmp__929));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = tail call double @exp(double %%23) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2058_count);
  llvm_cbe_tmp__930 = (double ) /*tail*/ exp(llvm_cbe_tmp__929);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__929, *(long long*)(&llvm_cbe_tmp__929));
printf("\nReturn  = %lf",llvm_cbe_tmp__930);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = fpext float %%21 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2059_count);
  llvm_cbe_tmp__931 = (double )((double )llvm_cbe_tmp__927);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__931, *(long long*)(&llvm_cbe_tmp__931));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = fadd double %%25, %%24, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2060_count);
  llvm_cbe_tmp__932 = (double )llvm_cbe_tmp__931 + llvm_cbe_tmp__930;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__932, *(long long*)(&llvm_cbe_tmp__932));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = fptrunc double %%26 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2061_count);
  llvm_cbe_tmp__933 = (float )((float )llvm_cbe_tmp__932);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__933, *(int*)(&llvm_cbe_tmp__933));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 4), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2069_count);
  llvm_cbe_tmp__934 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__934, *(int*)(&llvm_cbe_tmp__934));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fpext float %%28 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2070_count);
  llvm_cbe_tmp__935 = (double )((double )llvm_cbe_tmp__934);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__935, *(long long*)(&llvm_cbe_tmp__935));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = tail call double @exp(double %%29) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2071_count);
  llvm_cbe_tmp__936 = (double ) /*tail*/ exp(llvm_cbe_tmp__935);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__935, *(long long*)(&llvm_cbe_tmp__935));
printf("\nReturn  = %lf",llvm_cbe_tmp__936);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = fpext float %%27 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2072_count);
  llvm_cbe_tmp__937 = (double )((double )llvm_cbe_tmp__933);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__937, *(long long*)(&llvm_cbe_tmp__937));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = fadd double %%31, %%30, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2073_count);
  llvm_cbe_tmp__938 = (double )llvm_cbe_tmp__937 + llvm_cbe_tmp__936;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__938, *(long long*)(&llvm_cbe_tmp__938));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = fptrunc double %%32 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2074_count);
  llvm_cbe_tmp__939 = (float )((float )llvm_cbe_tmp__938);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__939, *(int*)(&llvm_cbe_tmp__939));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 5), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2082_count);
  llvm_cbe_tmp__940 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__940, *(int*)(&llvm_cbe_tmp__940));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = fpext float %%34 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2083_count);
  llvm_cbe_tmp__941 = (double )((double )llvm_cbe_tmp__940);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__941, *(long long*)(&llvm_cbe_tmp__941));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = tail call double @exp(double %%35) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2084_count);
  llvm_cbe_tmp__942 = (double ) /*tail*/ exp(llvm_cbe_tmp__941);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__941, *(long long*)(&llvm_cbe_tmp__941));
printf("\nReturn  = %lf",llvm_cbe_tmp__942);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = fpext float %%33 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2085_count);
  llvm_cbe_tmp__943 = (double )((double )llvm_cbe_tmp__939);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__943, *(long long*)(&llvm_cbe_tmp__943));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = fadd double %%37, %%36, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2086_count);
  llvm_cbe_tmp__944 = (double )llvm_cbe_tmp__943 + llvm_cbe_tmp__942;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__944, *(long long*)(&llvm_cbe_tmp__944));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = fptrunc double %%38 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2087_count);
  llvm_cbe_tmp__945 = (float )((float )llvm_cbe_tmp__944);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__945, *(int*)(&llvm_cbe_tmp__945));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 6), align 8, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2095_count);
  llvm_cbe_tmp__946 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__946, *(int*)(&llvm_cbe_tmp__946));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = fpext float %%40 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2096_count);
  llvm_cbe_tmp__947 = (double )((double )llvm_cbe_tmp__946);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__947, *(long long*)(&llvm_cbe_tmp__947));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = tail call double @exp(double %%41) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2097_count);
  llvm_cbe_tmp__948 = (double ) /*tail*/ exp(llvm_cbe_tmp__947);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__947, *(long long*)(&llvm_cbe_tmp__947));
printf("\nReturn  = %lf",llvm_cbe_tmp__948);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = fpext float %%39 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2098_count);
  llvm_cbe_tmp__949 = (double )((double )llvm_cbe_tmp__945);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__949, *(long long*)(&llvm_cbe_tmp__949));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = fadd double %%43, %%42, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2099_count);
  llvm_cbe_tmp__950 = (double )llvm_cbe_tmp__949 + llvm_cbe_tmp__948;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__950, *(long long*)(&llvm_cbe_tmp__950));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = fptrunc double %%44 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2100_count);
  llvm_cbe_tmp__951 = (float )((float )llvm_cbe_tmp__950);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__951, *(int*)(&llvm_cbe_tmp__951));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 7), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2108_count);
  llvm_cbe_tmp__952 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__952, *(int*)(&llvm_cbe_tmp__952));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = fpext float %%46 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2109_count);
  llvm_cbe_tmp__953 = (double )((double )llvm_cbe_tmp__952);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__953, *(long long*)(&llvm_cbe_tmp__953));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = tail call double @exp(double %%47) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2110_count);
  llvm_cbe_tmp__954 = (double ) /*tail*/ exp(llvm_cbe_tmp__953);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__953, *(long long*)(&llvm_cbe_tmp__953));
printf("\nReturn  = %lf",llvm_cbe_tmp__954);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = fpext float %%45 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2111_count);
  llvm_cbe_tmp__955 = (double )((double )llvm_cbe_tmp__951);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__955, *(long long*)(&llvm_cbe_tmp__955));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fadd double %%49, %%48, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2112_count);
  llvm_cbe_tmp__956 = (double )llvm_cbe_tmp__955 + llvm_cbe_tmp__954;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__956, *(long long*)(&llvm_cbe_tmp__956));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = fptrunc double %%50 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2113_count);
  llvm_cbe_tmp__957 = (float )((float )llvm_cbe_tmp__956);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__957, *(int*)(&llvm_cbe_tmp__957));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 8), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2121_count);
  llvm_cbe_tmp__958 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__958, *(int*)(&llvm_cbe_tmp__958));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = fpext float %%52 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2122_count);
  llvm_cbe_tmp__959 = (double )((double )llvm_cbe_tmp__958);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__959, *(long long*)(&llvm_cbe_tmp__959));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = tail call double @exp(double %%53) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2123_count);
  llvm_cbe_tmp__960 = (double ) /*tail*/ exp(llvm_cbe_tmp__959);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__959, *(long long*)(&llvm_cbe_tmp__959));
printf("\nReturn  = %lf",llvm_cbe_tmp__960);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = fpext float %%51 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2124_count);
  llvm_cbe_tmp__961 = (double )((double )llvm_cbe_tmp__957);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__961, *(long long*)(&llvm_cbe_tmp__961));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fadd double %%55, %%54, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2125_count);
  llvm_cbe_tmp__962 = (double )llvm_cbe_tmp__961 + llvm_cbe_tmp__960;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__962, *(long long*)(&llvm_cbe_tmp__962));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = fptrunc double %%56 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2126_count);
  llvm_cbe_tmp__963 = (float )((float )llvm_cbe_tmp__962);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__963, *(int*)(&llvm_cbe_tmp__963));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 9), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2134_count);
  llvm_cbe_tmp__964 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__964, *(int*)(&llvm_cbe_tmp__964));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = fpext float %%58 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2135_count);
  llvm_cbe_tmp__965 = (double )((double )llvm_cbe_tmp__964);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__965, *(long long*)(&llvm_cbe_tmp__965));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = tail call double @exp(double %%59) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2136_count);
  llvm_cbe_tmp__966 = (double ) /*tail*/ exp(llvm_cbe_tmp__965);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__965, *(long long*)(&llvm_cbe_tmp__965));
printf("\nReturn  = %lf",llvm_cbe_tmp__966);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = fpext float %%57 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2137_count);
  llvm_cbe_tmp__967 = (double )((double )llvm_cbe_tmp__963);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__967, *(long long*)(&llvm_cbe_tmp__967));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = fadd double %%61, %%60, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2138_count);
  llvm_cbe_tmp__968 = (double )llvm_cbe_tmp__967 + llvm_cbe_tmp__966;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__968, *(long long*)(&llvm_cbe_tmp__968));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = fptrunc double %%62 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2139_count);
  llvm_cbe_tmp__969 = (float )((float )llvm_cbe_tmp__968);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__969, *(int*)(&llvm_cbe_tmp__969));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = fpext float %%63 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2151_count);
  llvm_cbe_tmp__970 = (double )((double )llvm_cbe_tmp__969);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__970, *(long long*)(&llvm_cbe_tmp__970));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 0), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2152_count);
  llvm_cbe_tmp__971 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__971, *(int*)(&llvm_cbe_tmp__971));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fpext float %%65 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2153_count);
  llvm_cbe_tmp__972 = (double )((double )llvm_cbe_tmp__971);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__972, *(long long*)(&llvm_cbe_tmp__972));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = tail call double @exp(double %%66) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2154_count);
  llvm_cbe_tmp__973 = (double ) /*tail*/ exp(llvm_cbe_tmp__972);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__972, *(long long*)(&llvm_cbe_tmp__972));
printf("\nReturn  = %lf",llvm_cbe_tmp__973);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = fdiv double %%67, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2155_count);
  llvm_cbe_tmp__974 = (double )llvm_cbe_tmp__973 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__974, *(long long*)(&llvm_cbe_tmp__974));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = fptrunc double %%68 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2156_count);
  llvm_cbe_tmp__975 = (float )((float )llvm_cbe_tmp__974);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__975, *(int*)(&llvm_cbe_tmp__975));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%69, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 0), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2157_count);
  *((&aesl_internal_result[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__975;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__975);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 1), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2163_count);
  llvm_cbe_tmp__976 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__976, *(int*)(&llvm_cbe_tmp__976));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = fpext float %%70 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2164_count);
  llvm_cbe_tmp__977 = (double )((double )llvm_cbe_tmp__976);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__977, *(long long*)(&llvm_cbe_tmp__977));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = tail call double @exp(double %%71) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2165_count);
  llvm_cbe_tmp__978 = (double ) /*tail*/ exp(llvm_cbe_tmp__977);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__977, *(long long*)(&llvm_cbe_tmp__977));
printf("\nReturn  = %lf",llvm_cbe_tmp__978);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fdiv double %%72, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2166_count);
  llvm_cbe_tmp__979 = (double )llvm_cbe_tmp__978 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__979, *(long long*)(&llvm_cbe_tmp__979));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = fptrunc double %%73 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2167_count);
  llvm_cbe_tmp__980 = (float )((float )llvm_cbe_tmp__979);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__980, *(int*)(&llvm_cbe_tmp__980));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%74, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 1), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2168_count);
  *((&aesl_internal_result[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__980;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__980);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 2), align 8, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2174_count);
  llvm_cbe_tmp__981 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__981, *(int*)(&llvm_cbe_tmp__981));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = fpext float %%75 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2175_count);
  llvm_cbe_tmp__982 = (double )((double )llvm_cbe_tmp__981);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__982, *(long long*)(&llvm_cbe_tmp__982));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = tail call double @exp(double %%76) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2176_count);
  llvm_cbe_tmp__983 = (double ) /*tail*/ exp(llvm_cbe_tmp__982);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__982, *(long long*)(&llvm_cbe_tmp__982));
printf("\nReturn  = %lf",llvm_cbe_tmp__983);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = fdiv double %%77, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2177_count);
  llvm_cbe_tmp__984 = (double )llvm_cbe_tmp__983 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__984, *(long long*)(&llvm_cbe_tmp__984));
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = fptrunc double %%78 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2178_count);
  llvm_cbe_tmp__985 = (float )((float )llvm_cbe_tmp__984);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__985, *(int*)(&llvm_cbe_tmp__985));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%79, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 2), align 8, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2179_count);
  *((&aesl_internal_result[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__985;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__985);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 3), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2185_count);
  llvm_cbe_tmp__986 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__986, *(int*)(&llvm_cbe_tmp__986));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = fpext float %%80 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2186_count);
  llvm_cbe_tmp__987 = (double )((double )llvm_cbe_tmp__986);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__987, *(long long*)(&llvm_cbe_tmp__987));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = tail call double @exp(double %%81) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2187_count);
  llvm_cbe_tmp__988 = (double ) /*tail*/ exp(llvm_cbe_tmp__987);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__987, *(long long*)(&llvm_cbe_tmp__987));
printf("\nReturn  = %lf",llvm_cbe_tmp__988);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = fdiv double %%82, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2188_count);
  llvm_cbe_tmp__989 = (double )llvm_cbe_tmp__988 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__989, *(long long*)(&llvm_cbe_tmp__989));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = fptrunc double %%83 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2189_count);
  llvm_cbe_tmp__990 = (float )((float )llvm_cbe_tmp__989);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__990, *(int*)(&llvm_cbe_tmp__990));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%84, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 3), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2190_count);
  *((&aesl_internal_result[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__990;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__990);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 4), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2196_count);
  llvm_cbe_tmp__991 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__991, *(int*)(&llvm_cbe_tmp__991));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = fpext float %%85 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2197_count);
  llvm_cbe_tmp__992 = (double )((double )llvm_cbe_tmp__991);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__992, *(long long*)(&llvm_cbe_tmp__992));
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = tail call double @exp(double %%86) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2198_count);
  llvm_cbe_tmp__993 = (double ) /*tail*/ exp(llvm_cbe_tmp__992);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__992, *(long long*)(&llvm_cbe_tmp__992));
printf("\nReturn  = %lf",llvm_cbe_tmp__993);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = fdiv double %%87, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2199_count);
  llvm_cbe_tmp__994 = (double )llvm_cbe_tmp__993 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__994, *(long long*)(&llvm_cbe_tmp__994));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = fptrunc double %%88 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2200_count);
  llvm_cbe_tmp__995 = (float )((float )llvm_cbe_tmp__994);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__995, *(int*)(&llvm_cbe_tmp__995));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%89, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 4), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2201_count);
  *((&aesl_internal_result[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__995;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__995);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 5), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2207_count);
  llvm_cbe_tmp__996 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__996, *(int*)(&llvm_cbe_tmp__996));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = fpext float %%90 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2208_count);
  llvm_cbe_tmp__997 = (double )((double )llvm_cbe_tmp__996);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__997, *(long long*)(&llvm_cbe_tmp__997));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = tail call double @exp(double %%91) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2209_count);
  llvm_cbe_tmp__998 = (double ) /*tail*/ exp(llvm_cbe_tmp__997);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__997, *(long long*)(&llvm_cbe_tmp__997));
printf("\nReturn  = %lf",llvm_cbe_tmp__998);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = fdiv double %%92, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2210_count);
  llvm_cbe_tmp__999 = (double )llvm_cbe_tmp__998 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__999, *(long long*)(&llvm_cbe_tmp__999));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = fptrunc double %%93 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2211_count);
  llvm_cbe_tmp__1000 = (float )((float )llvm_cbe_tmp__999);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1000, *(int*)(&llvm_cbe_tmp__1000));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%94, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 5), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2212_count);
  *((&aesl_internal_result[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__1000;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__1000);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 6), align 8, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2218_count);
  llvm_cbe_tmp__1001 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1001, *(int*)(&llvm_cbe_tmp__1001));
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = fpext float %%95 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2219_count);
  llvm_cbe_tmp__1002 = (double )((double )llvm_cbe_tmp__1001);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1002, *(long long*)(&llvm_cbe_tmp__1002));
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = tail call double @exp(double %%96) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2220_count);
  llvm_cbe_tmp__1003 = (double ) /*tail*/ exp(llvm_cbe_tmp__1002);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__1002, *(long long*)(&llvm_cbe_tmp__1002));
printf("\nReturn  = %lf",llvm_cbe_tmp__1003);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = fdiv double %%97, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2221_count);
  llvm_cbe_tmp__1004 = (double )llvm_cbe_tmp__1003 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1004, *(long long*)(&llvm_cbe_tmp__1004));
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = fptrunc double %%98 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2222_count);
  llvm_cbe_tmp__1005 = (float )((float )llvm_cbe_tmp__1004);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1005, *(int*)(&llvm_cbe_tmp__1005));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%99, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 6), align 8, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2223_count);
  *((&aesl_internal_result[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__1005;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__1005);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 7), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2229_count);
  llvm_cbe_tmp__1006 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1006, *(int*)(&llvm_cbe_tmp__1006));
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = fpext float %%100 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2230_count);
  llvm_cbe_tmp__1007 = (double )((double )llvm_cbe_tmp__1006);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1007, *(long long*)(&llvm_cbe_tmp__1007));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = tail call double @exp(double %%101) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2231_count);
  llvm_cbe_tmp__1008 = (double ) /*tail*/ exp(llvm_cbe_tmp__1007);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__1007, *(long long*)(&llvm_cbe_tmp__1007));
printf("\nReturn  = %lf",llvm_cbe_tmp__1008);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = fdiv double %%102, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2232_count);
  llvm_cbe_tmp__1009 = (double )llvm_cbe_tmp__1008 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1009, *(long long*)(&llvm_cbe_tmp__1009));
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = fptrunc double %%103 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2233_count);
  llvm_cbe_tmp__1010 = (float )((float )llvm_cbe_tmp__1009);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1010, *(int*)(&llvm_cbe_tmp__1010));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%104, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 7), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2234_count);
  *((&aesl_internal_result[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__1010;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__1010);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 8), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2240_count);
  llvm_cbe_tmp__1011 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1011, *(int*)(&llvm_cbe_tmp__1011));
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = fpext float %%105 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2241_count);
  llvm_cbe_tmp__1012 = (double )((double )llvm_cbe_tmp__1011);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1012, *(long long*)(&llvm_cbe_tmp__1012));
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = tail call double @exp(double %%106) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2242_count);
  llvm_cbe_tmp__1013 = (double ) /*tail*/ exp(llvm_cbe_tmp__1012);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__1012, *(long long*)(&llvm_cbe_tmp__1012));
printf("\nReturn  = %lf",llvm_cbe_tmp__1013);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = fdiv double %%107, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2243_count);
  llvm_cbe_tmp__1014 = (double )llvm_cbe_tmp__1013 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1014, *(long long*)(&llvm_cbe_tmp__1014));
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = fptrunc double %%108 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2244_count);
  llvm_cbe_tmp__1015 = (float )((float )llvm_cbe_tmp__1014);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1015, *(int*)(&llvm_cbe_tmp__1015));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%109, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 8), align 16, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2245_count);
  *((&aesl_internal_result[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__1015;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__1015);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = load float* getelementptr inbounds ([1 x [10 x float]]* @aesl_internal_outmlp, i64 0, i64 0, i64 9), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2251_count);
  llvm_cbe_tmp__1016 = (float )*((&aesl_internal_outmlp[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1
#endif
][(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 10
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1016, *(int*)(&llvm_cbe_tmp__1016));
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = fpext float %%110 to double, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2252_count);
  llvm_cbe_tmp__1017 = (double )((double )llvm_cbe_tmp__1016);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1017, *(long long*)(&llvm_cbe_tmp__1017));
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = tail call double @exp(double %%111) nounwind, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2253_count);
  llvm_cbe_tmp__1018 = (double ) /*tail*/ exp(llvm_cbe_tmp__1017);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__1017, *(long long*)(&llvm_cbe_tmp__1017));
printf("\nReturn  = %lf",llvm_cbe_tmp__1018);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = fdiv double %%112, %%64, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2254_count);
  llvm_cbe_tmp__1019 = (double )llvm_cbe_tmp__1018 / llvm_cbe_tmp__970;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__1019, *(long long*)(&llvm_cbe_tmp__1019));
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = fptrunc double %%113 to float, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2255_count);
  llvm_cbe_tmp__1020 = (float )((float )llvm_cbe_tmp__1019);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1020, *(int*)(&llvm_cbe_tmp__1020));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%114, float* getelementptr inbounds ([10 x float]* @aesl_internal_result, i64 0, i64 9), align 4, !dbg !20 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2256_count);
  *((&aesl_internal_result[(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])) = llvm_cbe_tmp__1020;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__1020);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @backward(i32 %%label, float* %%conv1, float* %%conv2, float* %%conv3, float* %%fc1, float* %%fc2, float* %%fc3), !dbg !18 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2262_count);
   /*tail*/ backward(llvm_cbe_label, (float *)llvm_cbe_conv1, (float *)llvm_cbe_conv2, (float *)llvm_cbe_conv3, (float *)llvm_cbe_fc1, (float *)llvm_cbe_fc2, (float *)llvm_cbe_fc3);
if (AESL_DEBUG_TRACE) {
printf("\nArgument label = 0x%X",llvm_cbe_label);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = bitcast float* %%out to i8*, !dbg !19 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2263_count);
  llvm_cbe_tmp__1021 = ( char *)(( char *)llvm_cbe_out);
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = call i8* @memcpy(i8* %%115, i8* bitcast ([10 x float]* @aesl_internal_out_grad to i8*), i64 4 for 0x%I64xth hint within @forw_back  --> \n", ++aesl_llvm_cbe_2264_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__1021, ( char *)(( char *)(&aesl_internal_out_grad)), 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1022);
}
  goto llvm_cbe_tmp__1024;

llvm_cbe_tmp__1024:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @forw_back}\n");
  return;
}

