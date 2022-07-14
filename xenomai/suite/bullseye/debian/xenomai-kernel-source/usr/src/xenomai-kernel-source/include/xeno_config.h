/* include/xeno_config.h.  Generated from xeno_config.h.in by configure.  */
/* include/xeno_config.h.in.  Generated from configure.ac by autoheader.  */

/* config */
#define CONFIG_MMU 1

/* config */
#define CONFIG_SMP 1

/* config */
/* #undef CONFIG_XENO_ASYNC_CANCEL */

/* config */
#define CONFIG_XENO_BUILD_ARGS " '--prefix=/usr' '--includedir=/usr/include/xenomai' '--mandir=/usr/share/man' '--with-testdir=/usr/lib/xenomai/testsuite' '--enable-smp' '--build' 'x86_64-linux-gnu' 'build_alias=x86_64-linux-gnu'"

/* Build system alias */
#define CONFIG_XENO_BUILD_STRING "x86_64-pc-linux-gnu"

/* config */
#define CONFIG_XENO_COBALT 1

/* Compiler */
#define CONFIG_XENO_COMPILER "gcc version 10.2.1 20210110 (Debian 10.2.1-6) "

/* config */
/* #undef CONFIG_XENO_COPPERPLATE_CLOCK_RESTRICTED */

/* config */
/* #undef CONFIG_XENO_DEBUG */

/* config */
/* #undef CONFIG_XENO_DEBUG_FULL */

/* config */
#define CONFIG_XENO_DEFAULT_PERIOD 100000

/* config */
#define CONFIG_XENO_FORTIFY 1

/* Host system alias */
#define CONFIG_XENO_HOST_STRING "x86_64-pc-linux-gnu"

/* config */
/* #undef CONFIG_XENO_LIBS_DLOPEN */

/* config */
#define CONFIG_XENO_LORES_CLOCK_DISABLED 1

/* config */
/* #undef CONFIG_XENO_MERCURY */

/* config */
#define CONFIG_XENO_PREFIX "/usr"

/* config */
/* #undef CONFIG_XENO_PSHARED */

/* config */
#define CONFIG_XENO_RAW_CLOCK_ENABLED 1

/* config */
/* #undef CONFIG_XENO_REGISTRY */

/* config */
/* #undef CONFIG_XENO_REGISTRY_ROOT */

/* config */
#define CONFIG_XENO_REVISION_LEVEL 12

/* config */
#define CONFIG_XENO_SANITY 1

/* config */
#define CONFIG_XENO_TLSF 1

/* TLS model */
#define CONFIG_XENO_TLS_MODEL "initial-exec"

/* config */
#define CONFIG_XENO_UAPI_LEVEL 14

/* config */
/* #undef CONFIG_XENO_VALGRIND_API */

/* config */
#define CONFIG_XENO_VERSION_MAJOR 3

/* config */
#define CONFIG_XENO_VERSION_MINOR 0

/* config */
#define CONFIG_XENO_VERSION_STRING "3.0.12"

/* config */
/* #undef CONFIG_XENO_WORKAROUND_CONDVAR_PI */

/* config */
#define CONFIG_XENO_X86_VSYSCALL 1

#ifdef __IN_XENO__

/* Define to 1 if you have the `backtrace' function. */
#define HAVE_BACKTRACE 1

/* Define to 1 if you have the `clock_nanosleep' function. */
#define HAVE_CLOCK_NANOSLEEP 1

/* Define to 1 if you have the declaration of
   `PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP', and to 0 if you don't. */
#define HAVE_DECL_PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP 1

/* Define to 1 if you have the declaration of `PTHREAD_PRIO_NONE', and to 0 if
   you don't. */
#define HAVE_DECL_PTHREAD_PRIO_NONE 1

/* Define to 1 if you have the declaration of
   `PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP', and to 0 if you don't. */
#define HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <mqueue.h> header file. */
#define HAVE_MQUEUE_H 1

/* Define to 1 if you have the <obstack.h> header file. */
#define HAVE_OBSTACK_H 1

/* Define to 1 if you have the `pthread_atfork' function. */
#define HAVE_PTHREAD_ATFORK 1

/* Define to 1 if you have the `pthread_attr_setaffinity_np' function. */
#define HAVE_PTHREAD_ATTR_SETAFFINITY_NP 1

/* Define to 1 if you have the `pthread_condattr_getclock' function. */
#define HAVE_PTHREAD_CONDATTR_GETCLOCK 1

/* Define to 1 if you have the `pthread_condattr_setclock' function. */
#define HAVE_PTHREAD_CONDATTR_SETCLOCK 1

/* Define to 1 if you have the `pthread_getattr_np' function. */
#define HAVE_PTHREAD_GETATTR_NP 1

/* Define to 1 if you have the `pthread_mutexattr_getprotocol' function. */
#define HAVE_PTHREAD_MUTEXATTR_GETPROTOCOL 1

/* Define to 1 if you have the `pthread_mutexattr_setprotocol' function. */
#define HAVE_PTHREAD_MUTEXATTR_SETPROTOCOL 1

/* Define to 1 if you have the `pthread_mutexattr_setrobust_np' function. */
#define HAVE_PTHREAD_MUTEXATTR_SETROBUST_NP 1

/* Define to 1 if you have the `pthread_setaffinity_np' function. */
#define HAVE_PTHREAD_SETAFFINITY_NP 1

/* Define to 1 if you have the `pthread_setname_np' function. */
#define HAVE_PTHREAD_SETNAME_NP 1

/* Define to 1 if you have the `pthread_spin_lock' function. */
#define HAVE_PTHREAD_SPIN_LOCK 1

/* Define to 1 if you have the `sched_getcpu' function. */
#define HAVE_SCHED_GETCPU 1

/* Define to 1 if you have the `shm_open' function. */
#define HAVE_SHM_OPEN 1

/* Define to 1 if you have the `shm_unlink' function. */
#define HAVE_SHM_UNLINK 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* config */
#define HAVE_TLS 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "xenomai"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "xenomai@xenomai.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "Xenomai"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "Xenomai 3.0.12"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "xenomai"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.0.12"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "3.0.12"

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

#endif /* __IN_XENO__ */
