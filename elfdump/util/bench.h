#ifndef __BENCH_H_INCLUDE__
#define __BENCH_H_INCLUDE__

#include <time.h>
#include <stdio.h>

#define _BENCH_INIT() 			\
	clock_t __TIME1__;	\
	clock_t __TIME2__;	\
	double 	__DIFF_MS__;	\
	clock_t __CLOCK_DIF__	\

#define _BENCH_ENTER()			\
	__TIME1__ = clock()	\

#define _BENCH_EXIT()			\
	__TIME2__ = clock();	\
	__CLOCK_DIF__ = __TIME2__ - __TIME1__; \
	__DIFF_MS__ = (double) __CLOCK_DIF__ / (double) CLOCKS_PER_SEC; \
	__DIFF_MS__ *= 1000.f 	\

#define _BENCH_PRINT()			\
	printf("clocks: %lu\nms: %f\n", __CLOCK_DIF__, __DIFF_MS__) \

#ifdef BENCHMARK
#define BENCH_INIT()	_BENCH_INIT()
#define BENCH_ENTER() 	_BENCH_ENTER()
#define BENCH_EXIT()	_BENCH_EXIT()
#define BENCH_PRINT()	_BENCH_PRINT()
#else
#define BENCH_INIT()	do {} while(0)
#define BENCH_ENTER() 	do {} while(0)
#define BENCH_EXIT()	do {} while(0)
#define BENCH_PRINT()	do {} while(0)
#endif

#endif /* __BENCH_H_INCLUDE__ */
