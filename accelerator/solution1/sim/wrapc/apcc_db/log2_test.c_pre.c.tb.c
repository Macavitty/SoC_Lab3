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
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int main(void);
void AESL_WRAP_l_log2(float , float *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[7] = "in.dat";
static  char aesl_internal__OC_str1[2] = "r";
static  char aesl_internal__OC_str2[8] = "out.dat";
static  char aesl_internal__OC_str3[2] = "w";
static  char aesl_internal__OC_str4[3] = "%d";
static  char aesl_internal_str[31] = "Comparing against output data ";
static  char aesl_internal__OC_str5[5] = "\n%f\n";
static  char aesl_internal__OC_str7[29] = "diff -w out.dat out.gold.dat";
static  char aesl_internal__OC_str8[45] = "*******************************************\n";
static  char aesl_internal__OC_str9[47] = "FAIL: Output DOES NOT match the golden output\n";
static  char aesl_internal__OC_str10[45] = "PASS: The output matches the golden output!\n";


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

signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_test_count_count = 0;
  signed int llvm_cbe_test_count;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_x_count = 0;
  float llvm_cbe_x;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_res_count = 0;
  float llvm_cbe_res;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  float llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  float llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  double llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%test_count, align 4, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  *(&llvm_cbe_test_count) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  store float 6.000000e+00, float* %%res, align 4, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_17_count);
  *(&llvm_cbe_res) = 0x1.8p2;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x1.8p2);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str3, i64 0, i64 0)) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__2 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])), ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32* %%test_count) nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_27_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (signed int *)(&llvm_cbe_test_count));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%test_count, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__4 = (unsigned int )*(&llvm_cbe_test_count);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
  if ((((signed int )llvm_cbe_tmp__4) > ((signed int )0u))) {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ %%11, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",llvm_cbe_tmp__10);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str5, i64 0, i64 0), float* %%x) nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__1, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), (float *)(&llvm_cbe_x));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load float* %%x, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__6 = (float )*(&llvm_cbe_x);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__6, *(int*)(&llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_l_log2(float %%7, float* %%res) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  AESL_WRAP_l_log2(llvm_cbe_tmp__6, (float *)(&llvm_cbe_res));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__6, *(int*)(&llvm_cbe_tmp__6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%res, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__7 = (float )*(&llvm_cbe_res);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__7, *(int*)(&llvm_cbe_tmp__7));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = fpext float %%8 to double, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__8 = (double )((double )llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__8, *(long long*)(&llvm_cbe_tmp__8));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%2, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str5, i64 0, i64 0), double %%9) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %lf,  0x%llx",llvm_cbe_tmp__8, *(long long*)(&llvm_cbe_tmp__8));
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%storemerge2, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i32* %%test_count, align 4, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__11 = (unsigned int )*(&llvm_cbe_test_count);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
  if ((((signed int )llvm_cbe_tmp__10) < ((signed int )llvm_cbe_tmp__11))) {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__10;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 @fclose(%%struct._iobuf* %%2) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_70_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call i32 @system(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str7, i64 0, i64 0)) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__14 = (unsigned int )system(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
  if (((llvm_cbe_tmp__14&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__33;
  } else {
    goto llvm_cbe_tmp__34;
  }

llvm_cbe_tmp__34:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__15 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct._iobuf* %%19, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__16 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__15[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%20), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  fwrite(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__18 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct._iobuf* %%22, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__19 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__18[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i64 @fwrite(i8* getelementptr inbounds ([47 x i8]* @aesl_internal_.str9, i64 0, i64 0), i64 46, i64 1, %%struct._iobuf* %%23), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  fwrite(( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 47
#endif
])), 46ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",46ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__21 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct._iobuf* %%25, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__22 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__21[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%26), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  fwrite(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__23);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__35;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__24 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct._iobuf* %%29, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__25 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__24[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%30), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
  fwrite(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__27 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct._iobuf* %%32, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__28 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__27[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%33), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_89_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__30 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct._iobuf* %%35, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__31 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__30[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%36), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_92_count);
  fwrite(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__32);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__35;

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 1, %%18 ], [ 0, %%28  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge1;
}

