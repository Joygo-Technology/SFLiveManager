#ifndef __OSL_ATOMIC_H__
#define __OSL_ATOMIC_H__

#ifdef WIN32
	#include <windows.h>
	typedef volatile long atomic_t;

	#define osl_atomic_inc(x)			InterlockedIncrement((x))
	#define osl_atomic_dec(x)			InterlockedDecrement((x))
	#define osl_atomic_get(x)			InterlockedExchangeAdd((x),0)
	#define osl_atomic_set(x,y)			InterlockedCompareExchange((x),(y),*(x))

#elif IPHONE
//#include <libkern/OSAtomic.h>
//typedef volatile int32_t atomic_t;
//#define osl_atomic_inc(x)			OSAtomicIncrement32((x))
//#define osl_atomic_dec(x)			OSAtomicDecrement32((x))
//#define osl_atomic_get(x)			OSAtomicOr32(0, (x))
//#define osl_atomic_set(x,y)			OSAtomicCompareAndSwap32((x),(y),(y))

typedef volatile long atomic_t;
#define osl_atomic_inc(x)			__sync_add_and_fetch((x),1)
#define osl_atomic_dec(x)			__sync_sub_and_fetch((x),1)
#define osl_atomic_get(x)			__sync_or_and_fetch((x),0)
#define osl_atomic_set(x,y)			__sync_val_compare_and_swap((x),(y),(y))

#else

#ifndef NDK
#ifdef ANDROID
#include "cutils/atomic.h"
	typedef volatile int32_t atomic_t;
#define osl_atomic_inc(x)			android_atomic_inc(x)
#define osl_atomic_dec(x)			android_atomic_dec(x)
#define osl_atomic_get(x)		    android_atomic_get(x)
#define osl_atomic_set(x,y)			android_atomic_swap(x,y)
#endif
#else
	typedef volatile long atomic_t;
#define osl_atomic_inc(x)			__sync_add_and_fetch((x),1)
#define osl_atomic_dec(x)			__sync_sub_and_fetch((x),1)
#define osl_atomic_get(x)			__sync_or_and_fetch((x),0)
#define osl_atomic_set(x,y)			__sync_val_compare_and_swap((x),(y),(y))
#endif
#endif

#endif

