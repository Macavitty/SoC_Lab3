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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void l_log2(float llvm_cbe_x, float *llvm_cbe_y);


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

void l_log2(float llvm_cbe_x, float *llvm_cbe_y) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  float llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  float llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  float llvm_cbe_tmp__3;
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
  float llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__5;
  unsigned int llvm_cbe_tmp__5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  float llvm_cbe_tmp__6;
  float llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  float llvm_cbe_tmp__7;
  float llvm_cbe_tmp__7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  float llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  float llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  float llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  float llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @l_log2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = fadd float %%x, -1.000000e+00, !dbg !3 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__1 = (float )((float )(llvm_cbe_x + -0x1p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1, *(int*)(&llvm_cbe_tmp__1));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = fadd float %%x, 1.000000e+00, !dbg !3 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__2 = (float )((float )(llvm_cbe_x + 0x1p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__2, *(int*)(&llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = fdiv float %%1, %%2, !dbg !3 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__3 = (float )((float )(llvm_cbe_tmp__1 / llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__3, *(int*)(&llvm_cbe_tmp__3));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = fmul float %%3, %%3, !dbg !4 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__4 = (float )((float )(llvm_cbe_tmp__3 * llvm_cbe_tmp__3));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__4, *(int*)(&llvm_cbe_tmp__4));
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  llvm_cbe_tmp__6__PHI_TEMPORARY = (float )llvm_cbe_tmp__3;   /* for PHI node */
  llvm_cbe_tmp__7__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
  goto llvm_cbe_tmp__16;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__16:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%14, %%5  for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i32 [ 1, %%0 ], [ %%12, %%5  for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__5 = (unsigned int )llvm_cbe_tmp__5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__5);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = phi float [ %%3, %%0 ], [ %%13, %%5  for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__6 = (float )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__6);
printf("\n = %f",llvm_cbe_tmp__3);
printf("\n = %f",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi float [ 0.000000e+00, %%0 ], [ %%11, %%5  for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__7 = (float )llvm_cbe_tmp__7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %f",llvm_cbe_tmp__7);
printf("\n = %f",0x0p0);
printf("\n = %f",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sitofp i32 %%6 to float, !dbg !4 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__8 = (float )((float )(signed int )llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__8, *(int*)(&llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fdiv float %%7, %%9, !dbg !4 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__9 = (float )((float )(llvm_cbe_tmp__6 / llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__9, *(int*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = fadd float %%8, %%10, !dbg !5 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__10 = (float )((float )(llvm_cbe_tmp__7 + llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%6, 2, !dbg !4 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = fmul float %%7, %%4, !dbg !4 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__12 = (float )((float )(llvm_cbe_tmp__6 * llvm_cbe_tmp__4));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge1, 1, !dbg !5 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
  if (((llvm_cbe_tmp__13&4294967295U) == (21u&4294967295U))) {
    goto llvm_cbe_tmp__17;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__13;   /* for PHI node */
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__11;   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = (float )llvm_cbe_tmp__12;   /* for PHI node */
    llvm_cbe_tmp__7__PHI_TEMPORARY = (float )llvm_cbe_tmp__10;   /* for PHI node */
    goto llvm_cbe_tmp__16;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__17:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fadd float %%11, %%11, !dbg !2 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__14 = (float )((float )(llvm_cbe_tmp__10 + llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__14, *(int*)(&llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fdiv float %%16, 0x3FE62E4300000000, !dbg !2 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__15 = (float )((float )(llvm_cbe_tmp__14 / 0x1.62e43p-1));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__15, *(int*)(&llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  store float %%17, float* %%y, align 4, !dbg !2 for 0x%I64xth hint within @l_log2  --> \n", ++aesl_llvm_cbe_59_count);
  *llvm_cbe_y = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__15);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @l_log2}\n");
  return;
}

