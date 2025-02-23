/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Linking FlexiBLAS statically or dynamically with other modules is making a
 * combined work based on FlexiBLAS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * As a special exception, the copyright holders of FlexiBLAS give you permission
 * to combine FlexiBLAS program with free software programs or libraries that are
 * released under the GNU LGPL and with independent modules that communicate with
 * FlexiBLAS solely through the BLAS/LAPACK interface as provided by the
 * BLAS/LAPACK reference implementation. You may copy and distribute such a system
 * following the terms of the GNU GPL for FlexiBLAS and the licenses of the other
 * code concerned, provided that you include the source code of that other code
 * when and as the GNU GPL requires distribution of source code and provided that
 * you do not modify the BLAS/LAPACK interface.
 *
 * Note that people who make modified versions of FlexiBLAS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release a
 * modified version without this exception; this exception also makes it possible
 * to release a modified version which carries forward this exception. If you
 * modify the BLAS/LAPACK interface, this exception does not apply to your
 * modified version of FlexiBLAS, and you must remove this exception when you
 * distribute your modified version.
 *
 * This exception is an additional permission under section 7 of the GNU General
 * Public License, version 3 (“GPLv3”)
 *
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) Martin Koehler, 2013-2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <complex.h>

#include "flexiblas_fortran_mangle.h"

#include "flexiblas.h"


#ifdef INTEGER8
#define blasint int64_t
#else
#define blasint int
#endif
#ifndef __INT32_MAX__
#define __INT32_MAX__ 2147483647
#endif


HIDDEN int __flexiblas_load_fblas ( flexiblas_backend_t *handle, int *loaded, int *failed )  {
	int _ifailed = *failed;
	LOAD_FBLAS(handle,blas.caxpy,caxpy);
	LOAD_FBLAS(handle,blas.ccopy,ccopy);
	LOAD_FBLAS(handle,blas.cdotc,cdotc);
	LOAD_FBLAS(handle,blas.cdotu,cdotu);
	LOAD_FBLAS(handle,blas.cgbmv,cgbmv);
	LOAD_FBLAS(handle,blas.cgemm,cgemm);
	LOAD_FBLAS(handle,blas.cgemv,cgemv);
	LOAD_FBLAS(handle,blas.cgerc,cgerc);
	LOAD_FBLAS(handle,blas.cgeru,cgeru);
	LOAD_FBLAS(handle,blas.chbmv,chbmv);
	LOAD_FBLAS(handle,blas.chemm,chemm);
	LOAD_FBLAS(handle,blas.chemv,chemv);
	LOAD_FBLAS(handle,blas.cher,cher);
	LOAD_FBLAS(handle,blas.cher2,cher2);
	LOAD_FBLAS(handle,blas.cher2k,cher2k);
	LOAD_FBLAS(handle,blas.cherk,cherk);
	LOAD_FBLAS(handle,blas.chpmv,chpmv);
	LOAD_FBLAS(handle,blas.chpr,chpr);
	LOAD_FBLAS(handle,blas.chpr2,chpr2);
	LOAD_FBLAS(handle,blas.crotg,crotg);
	LOAD_FBLAS(handle,blas.cscal,cscal);
	LOAD_FBLAS(handle,blas.csrot,csrot);
	LOAD_FBLAS(handle,blas.csscal,csscal);
	LOAD_FBLAS(handle,blas.cswap,cswap);
	LOAD_FBLAS(handle,blas.csymm,csymm);
	LOAD_FBLAS(handle,blas.csyr2k,csyr2k);
	LOAD_FBLAS(handle,blas.csyrk,csyrk);
	LOAD_FBLAS(handle,blas.ctbmv,ctbmv);
	LOAD_FBLAS(handle,blas.ctbsv,ctbsv);
	LOAD_FBLAS(handle,blas.ctpmv,ctpmv);
	LOAD_FBLAS(handle,blas.ctpsv,ctpsv);
	LOAD_FBLAS(handle,blas.ctrmm,ctrmm);
	LOAD_FBLAS(handle,blas.ctrmv,ctrmv);
	LOAD_FBLAS(handle,blas.ctrsm,ctrsm);
	LOAD_FBLAS(handle,blas.ctrsv,ctrsv);
	LOAD_FBLAS(handle,blas.dasum,dasum);
	LOAD_FBLAS(handle,blas.daxpy,daxpy);
	LOAD_FBLAS(handle,blas.dcopy,dcopy);
	LOAD_FBLAS(handle,blas.ddot,ddot);
	LOAD_FBLAS(handle,blas.dgbmv,dgbmv);
	LOAD_FBLAS(handle,blas.dgemm,dgemm);
	LOAD_FBLAS(handle,blas.dgemv,dgemv);
	LOAD_FBLAS(handle,blas.dger,dger);
	LOAD_FBLAS(handle,blas.dnrm2,dnrm2);
	LOAD_FBLAS(handle,blas.drot,drot);
	LOAD_FBLAS(handle,blas.drotg,drotg);
	LOAD_FBLAS(handle,blas.drotm,drotm);
	LOAD_FBLAS(handle,blas.drotmg,drotmg);
	LOAD_FBLAS(handle,blas.dsbmv,dsbmv);
	LOAD_FBLAS(handle,blas.dscal,dscal);
	LOAD_FBLAS(handle,blas.dsdot,dsdot);
	LOAD_FBLAS(handle,blas.dspmv,dspmv);
	LOAD_FBLAS(handle,blas.dspr,dspr);
	LOAD_FBLAS(handle,blas.dspr2,dspr2);
	LOAD_FBLAS(handle,blas.dswap,dswap);
	LOAD_FBLAS(handle,blas.dsymm,dsymm);
	LOAD_FBLAS(handle,blas.dsymv,dsymv);
	LOAD_FBLAS(handle,blas.dsyr,dsyr);
	LOAD_FBLAS(handle,blas.dsyr2,dsyr2);
	LOAD_FBLAS(handle,blas.dsyr2k,dsyr2k);
	LOAD_FBLAS(handle,blas.dsyrk,dsyrk);
	LOAD_FBLAS(handle,blas.dtbmv,dtbmv);
	LOAD_FBLAS(handle,blas.dtbsv,dtbsv);
	LOAD_FBLAS(handle,blas.dtpmv,dtpmv);
	LOAD_FBLAS(handle,blas.dtpsv,dtpsv);
	LOAD_FBLAS(handle,blas.dtrmm,dtrmm);
	LOAD_FBLAS(handle,blas.dtrmv,dtrmv);
	LOAD_FBLAS(handle,blas.dtrsm,dtrsm);
	LOAD_FBLAS(handle,blas.dtrsv,dtrsv);
	LOAD_FBLAS(handle,blas.dzasum,dzasum);
	LOAD_FBLAS(handle,blas.dznrm2,dznrm2);
	LOAD_FBLAS(handle,blas.icamax,icamax);
	LOAD_FBLAS(handle,blas.idamax,idamax);
	LOAD_FBLAS(handle,blas.isamax,isamax);
	LOAD_FBLAS(handle,blas.izamax,izamax);
	LOAD_FBLAS(handle,blas.sasum,sasum);
	LOAD_FBLAS(handle,blas.saxpy,saxpy);
	LOAD_FBLAS(handle,blas.scasum,scasum);
	LOAD_FBLAS(handle,blas.scnrm2,scnrm2);
	LOAD_FBLAS(handle,blas.scopy,scopy);
	LOAD_FBLAS(handle,blas.sdot,sdot);
	LOAD_FBLAS(handle,blas.sdsdot,sdsdot);
	LOAD_FBLAS(handle,blas.sgbmv,sgbmv);
	LOAD_FBLAS(handle,blas.sgemm,sgemm);
	LOAD_FBLAS(handle,blas.sgemv,sgemv);
	LOAD_FBLAS(handle,blas.sger,sger);
	LOAD_FBLAS(handle,blas.snrm2,snrm2);
	LOAD_FBLAS(handle,blas.srot,srot);
	LOAD_FBLAS(handle,blas.srotg,srotg);
	LOAD_FBLAS(handle,blas.srotm,srotm);
	LOAD_FBLAS(handle,blas.srotmg,srotmg);
	LOAD_FBLAS(handle,blas.ssbmv,ssbmv);
	LOAD_FBLAS(handle,blas.sscal,sscal);
	LOAD_FBLAS(handle,blas.sspmv,sspmv);
	LOAD_FBLAS(handle,blas.sspr,sspr);
	LOAD_FBLAS(handle,blas.sspr2,sspr2);
	LOAD_FBLAS(handle,blas.sswap,sswap);
	LOAD_FBLAS(handle,blas.ssymm,ssymm);
	LOAD_FBLAS(handle,blas.ssymv,ssymv);
	LOAD_FBLAS(handle,blas.ssyr,ssyr);
	LOAD_FBLAS(handle,blas.ssyr2,ssyr2);
	LOAD_FBLAS(handle,blas.ssyr2k,ssyr2k);
	LOAD_FBLAS(handle,blas.ssyrk,ssyrk);
	LOAD_FBLAS(handle,blas.stbmv,stbmv);
	LOAD_FBLAS(handle,blas.stbsv,stbsv);
	LOAD_FBLAS(handle,blas.stpmv,stpmv);
	LOAD_FBLAS(handle,blas.stpsv,stpsv);
	LOAD_FBLAS(handle,blas.strmm,strmm);
	LOAD_FBLAS(handle,blas.strmv,strmv);
	LOAD_FBLAS(handle,blas.strsm,strsm);
	LOAD_FBLAS(handle,blas.strsv,strsv);
	LOAD_FBLAS(handle,blas.zaxpy,zaxpy);
	LOAD_FBLAS(handle,blas.zcopy,zcopy);
	LOAD_FBLAS(handle,blas.zdotc,zdotc);
	LOAD_FBLAS(handle,blas.zdotu,zdotu);
	LOAD_FBLAS(handle,blas.zdrot,zdrot);
	LOAD_FBLAS(handle,blas.zdscal,zdscal);
	LOAD_FBLAS(handle,blas.zgbmv,zgbmv);
	LOAD_FBLAS(handle,blas.zgemm,zgemm);
	LOAD_FBLAS(handle,blas.zgemv,zgemv);
	LOAD_FBLAS(handle,blas.zgerc,zgerc);
	LOAD_FBLAS(handle,blas.zgeru,zgeru);
	LOAD_FBLAS(handle,blas.zhbmv,zhbmv);
	LOAD_FBLAS(handle,blas.zhemm,zhemm);
	LOAD_FBLAS(handle,blas.zhemv,zhemv);
	LOAD_FBLAS(handle,blas.zher,zher);
	LOAD_FBLAS(handle,blas.zher2,zher2);
	LOAD_FBLAS(handle,blas.zher2k,zher2k);
	LOAD_FBLAS(handle,blas.zherk,zherk);
	LOAD_FBLAS(handle,blas.zhpmv,zhpmv);
	LOAD_FBLAS(handle,blas.zhpr,zhpr);
	LOAD_FBLAS(handle,blas.zhpr2,zhpr2);
	LOAD_FBLAS(handle,blas.zrotg,zrotg);
	LOAD_FBLAS(handle,blas.zscal,zscal);
	LOAD_FBLAS(handle,blas.zswap,zswap);
	LOAD_FBLAS(handle,blas.zsymm,zsymm);
	LOAD_FBLAS(handle,blas.zsyr2k,zsyr2k);
	LOAD_FBLAS(handle,blas.zsyrk,zsyrk);
	LOAD_FBLAS(handle,blas.ztbmv,ztbmv);
	LOAD_FBLAS(handle,blas.ztbsv,ztbsv);
	LOAD_FBLAS(handle,blas.ztpmv,ztpmv);
	LOAD_FBLAS(handle,blas.ztpsv,ztpsv);
	LOAD_FBLAS(handle,blas.ztrmm,ztrmm);
	LOAD_FBLAS(handle,blas.ztrmv,ztrmv);
	LOAD_FBLAS(handle,blas.ztrsm,ztrsm);
	LOAD_FBLAS(handle,blas.ztrsv,ztrsv);
	LOAD_FBLAS(handle,blas.caxpby,caxpby);
	LOAD_FBLAS(handle,blas.daxpby,daxpby);
	LOAD_FBLAS(handle,blas.zaxpby,zaxpby);
	LOAD_FBLAS(handle,blas.saxpby,saxpby);
	LOAD_FBLAS(handle,blas.comatcopy,comatcopy);
	LOAD_FBLAS(handle,blas.zomatcopy,zomatcopy);
	LOAD_FBLAS(handle,blas.domatcopy,domatcopy);
	LOAD_FBLAS(handle,blas.somatcopy,somatcopy);
	LOAD_FBLAS(handle,blas.cimatcopy,cimatcopy);
	LOAD_FBLAS(handle,blas.zimatcopy,zimatcopy);
	LOAD_FBLAS(handle,blas.dimatcopy,dimatcopy);
	LOAD_FBLAS(handle,blas.simatcopy,simatcopy);
	LOAD_FBLAS(handle,blas.sgeadd,sgeadd);
	LOAD_FBLAS(handle,blas.dgeadd,dgeadd);
	LOAD_FBLAS(handle,blas.cgeadd,cgeadd);
	LOAD_FBLAS(handle,blas.zgeadd,zgeadd);
	if (_ifailed != (*failed))
		return 1;
	else
			return 0;
}

void FC_GLOBAL(caxpy,CAXPY)(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cy, blasint* incy)
{
	void (*fn) (void* n, void* ca, void* cx, void* incx, void* cy, void* incy);
	void (*fn_hook) (void* n, void* ca, void* cx, void* incx, void* cy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.caxpy.f77_blas_function;
	fn_hook = __flexiblas_hooks->caxpy.f77_hook_function[0];
	hook_pos_caxpy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) ca, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
	} else {
		fn((void*) n, (void*) ca, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void caxpy_(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(caxpy,CAXPY)))));
#else
#ifndef __APPLE__
void caxpy(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(caxpy,CAXPY)))));
#else
void caxpy(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cy, blasint* incy){ FC_GLOBAL(caxpy,CAXPY)((void*) n, (void*) ca, (void*) cx, (void*) incx, (void*) cy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(ccopy,CCOPY)(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy)
{
	void (*fn) (void* n, void* cx, void* incx, void* cy, void* incy);
	void (*fn_hook) (void* n, void* cx, void* incx, void* cy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ccopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->ccopy.f77_hook_function[0];
	hook_pos_ccopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
	} else {
		fn((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ccopy_(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ccopy,CCOPY)))));
#else
#ifndef __APPLE__
void ccopy(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ccopy,CCOPY)))));
#else
void ccopy(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy){ FC_GLOBAL(ccopy,CCOPY)((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(cdotc,CDOTC)( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy)
{
	float complex (*fn) (void* n, void* cx, void* incx, void* cy, void* incy);
	float complex (*fn_hook) (void* n, void* cx, void* incx, void* cy, void* incy);
	void (*fn_intel) (float complex *ret, void* n, void* cx, void* incx, void* cy, void* incy);
	void (*fn_intel_hook) (float complex *ret, void* n, void* cx, void* incx, void* cy, void* incy);
	float complex ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cdotc.f77_blas_function;
	fn_hook = __flexiblas_hooks->cdotc.f77_hook_function[0];
	hook_pos_cdotc = 0;
	fn_intel = (void *) fn;
	fn_intel_hook = (void *) fn_hook;
	if ( fn_hook != NULL) {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn_hook((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			} else {
				fn_intel_hook( &ret, (void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			}
	} else {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			} else {
				fn_intel( &ret, (void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			}
	}
	*returnvalue = ret; 
		return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cdotc_( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cdotc,CDOTC)))));
#else
#ifndef __APPLE__
void cdotc( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cdotc,CDOTC)))));
#else
void cdotc( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy){ FC_GLOBAL(cdotc,CDOTC)( (void*) returnvalue, (void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(cdotu,CDOTU)( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy)
{
	float complex (*fn) (void* n, void* cx, void* incx, void* cy, void* incy);
	float complex (*fn_hook) (void* n, void* cx, void* incx, void* cy, void* incy);
	void (*fn_intel) (float complex *ret, void* n, void* cx, void* incx, void* cy, void* incy);
	void (*fn_intel_hook) (float complex *ret, void* n, void* cx, void* incx, void* cy, void* incy);
	float complex ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cdotu.f77_blas_function;
	fn_hook = __flexiblas_hooks->cdotu.f77_hook_function[0];
	hook_pos_cdotu = 0;
	fn_intel = (void *) fn;
	fn_intel_hook = (void *) fn_hook;
	if ( fn_hook != NULL) {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn_hook((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			} else {
				fn_intel_hook( &ret, (void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			}
	} else {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			} else {
				fn_intel( &ret, (void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
			}
	}
	*returnvalue = ret; 
		return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cdotu_( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cdotu,CDOTU)))));
#else
#ifndef __APPLE__
void cdotu( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cdotu,CDOTU)))));
#else
void cdotu( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy){ FC_GLOBAL(cdotu,CDOTU)( (void*) returnvalue, (void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(cgbmv,CGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cgbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->cgbmv.f77_hook_function[0];
	hook_pos_cgbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cgbmv_(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cgbmv,CGBMV)))));
#else
#ifndef __APPLE__
void cgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cgbmv,CGBMV)))));
#else
void cgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy){ FC_GLOBAL(cgbmv,CGBMV)((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(cgemm,CGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cgemm.f77_blas_function;
	fn_hook = __flexiblas_hooks->cgemm.f77_hook_function[0];
	hook_pos_cgemm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cgemm_(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(cgemm,CGEMM)))));
#else
#ifndef __APPLE__
void cgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(cgemm,CGEMM)))));
#else
void cgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc){ FC_GLOBAL(cgemm,CGEMM)((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(cgemv,CGEMV)(char* trans, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cgemv.f77_blas_function;
	fn_hook = __flexiblas_hooks->cgemv.f77_hook_function[0];
	hook_pos_cgemv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cgemv_(char* trans, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cgemv,CGEMV)))));
#else
#ifndef __APPLE__
void cgemv(char* trans, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cgemv,CGEMV)))));
#else
void cgemv(char* trans, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy){ FC_GLOBAL(cgemv,CGEMV)((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(cgerc,CGERC)(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda)
{
	void (*fn) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cgerc.f77_blas_function;
	fn_hook = __flexiblas_hooks->cgerc.f77_hook_function[0];
	hook_pos_cgerc = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cgerc_(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cgerc,CGERC)))));
#else
#ifndef __APPLE__
void cgerc(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cgerc,CGERC)))));
#else
void cgerc(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda){ FC_GLOBAL(cgerc,CGERC)((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(cgeru,CGERU)(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda)
{
	void (*fn) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cgeru.f77_blas_function;
	fn_hook = __flexiblas_hooks->cgeru.f77_hook_function[0];
	hook_pos_cgeru = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cgeru_(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cgeru,CGERU)))));
#else
#ifndef __APPLE__
void cgeru(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cgeru,CGERU)))));
#else
void cgeru(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda){ FC_GLOBAL(cgeru,CGERU)((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(chbmv,CHBMV)(char* uplo, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.chbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->chbmv.f77_hook_function[0];
	hook_pos_chbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void chbmv_(char* uplo, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(chbmv,CHBMV)))));
#else
#ifndef __APPLE__
void chbmv(char* uplo, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(chbmv,CHBMV)))));
#else
void chbmv(char* uplo, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy){ FC_GLOBAL(chbmv,CHBMV)((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(chemm,CHEMM)(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.chemm.f77_blas_function;
	fn_hook = __flexiblas_hooks->chemm.f77_hook_function[0];
	hook_pos_chemm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void chemm_(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(chemm,CHEMM)))));
#else
#ifndef __APPLE__
void chemm(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(chemm,CHEMM)))));
#else
void chemm(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc){ FC_GLOBAL(chemm,CHEMM)((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(chemv,CHEMV)(char* uplo, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.chemv.f77_blas_function;
	fn_hook = __flexiblas_hooks->chemv.f77_hook_function[0];
	hook_pos_chemv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void chemv_(char* uplo, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(chemv,CHEMV)))));
#else
#ifndef __APPLE__
void chemv(char* uplo, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(chemv,CHEMV)))));
#else
void chemv(char* uplo, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy){ FC_GLOBAL(chemv,CHEMV)((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(cher,CHER)(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cher.f77_blas_function;
	fn_hook = __flexiblas_hooks->cher.f77_hook_function[0];
	hook_pos_cher = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cher_(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cher,CHER)))));
#else
#ifndef __APPLE__
void cher(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cher,CHER)))));
#else
void cher(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* a, blasint* lda){ FC_GLOBAL(cher,CHER)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(cher2,CHER2)(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cher2.f77_blas_function;
	fn_hook = __flexiblas_hooks->cher2.f77_hook_function[0];
	hook_pos_cher2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cher2_(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cher2,CHER2)))));
#else
#ifndef __APPLE__
void cher2(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(cher2,CHER2)))));
#else
void cher2(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda){ FC_GLOBAL(cher2,CHER2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(cher2k,CHER2K)(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cher2k.f77_blas_function;
	fn_hook = __flexiblas_hooks->cher2k.f77_hook_function[0];
	hook_pos_cher2k = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cher2k_(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(cher2k,CHER2K)))));
#else
#ifndef __APPLE__
void cher2k(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(cher2k,CHER2K)))));
#else
void cher2k(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float* beta, float complex* c, blasint* ldc){ FC_GLOBAL(cher2k,CHER2K)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(cherk,CHERK)(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float complex* a, blasint* lda, float* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cherk.f77_blas_function;
	fn_hook = __flexiblas_hooks->cherk.f77_hook_function[0];
	hook_pos_cherk = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cherk_(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float complex* a, blasint* lda, float* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(cherk,CHERK)))));
#else
#ifndef __APPLE__
void cherk(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float complex* a, blasint* lda, float* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(cherk,CHERK)))));
#else
void cherk(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float complex* a, blasint* lda, float* beta, float complex* c, blasint* ldc){ FC_GLOBAL(cherk,CHERK)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(chpmv,CHPMV)(char* uplo, blasint* n, float complex* alpha, float complex* ap, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.chpmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->chpmv.f77_hook_function[0];
	hook_pos_chpmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void chpmv_(char* uplo, blasint* n, float complex* alpha, float complex* ap, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(chpmv,CHPMV)))));
#else
#ifndef __APPLE__
void chpmv(char* uplo, blasint* n, float complex* alpha, float complex* ap, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(chpmv,CHPMV)))));
#else
void chpmv(char* uplo, blasint* n, float complex* alpha, float complex* ap, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy){ FC_GLOBAL(chpmv,CHPMV)((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(chpr,CHPR)(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.chpr.f77_blas_function;
	fn_hook = __flexiblas_hooks->chpr.f77_hook_function[0];
	hook_pos_chpr = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void chpr_(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* ap) __attribute__((alias(MTS(FC_GLOBAL(chpr,CHPR)))));
#else
#ifndef __APPLE__
void chpr(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* ap) __attribute__((alias(MTS(FC_GLOBAL(chpr,CHPR)))));
#else
void chpr(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* ap){ FC_GLOBAL(chpr,CHPR)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap); }
#endif
#endif



void FC_GLOBAL(chpr2,CHPR2)(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.chpr2.f77_blas_function;
	fn_hook = __flexiblas_hooks->chpr2.f77_hook_function[0];
	hook_pos_chpr2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void chpr2_(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* ap) __attribute__((alias(MTS(FC_GLOBAL(chpr2,CHPR2)))));
#else
#ifndef __APPLE__
void chpr2(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* ap) __attribute__((alias(MTS(FC_GLOBAL(chpr2,CHPR2)))));
#else
void chpr2(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* ap){ FC_GLOBAL(chpr2,CHPR2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap); }
#endif
#endif



void FC_GLOBAL(crotg,CROTG)(float complex* ca, float complex* cb, float* c, float complex* s)
{
	void (*fn) (void* ca, void* cb, void* c, void* s);
	void (*fn_hook) (void* ca, void* cb, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.crotg.f77_blas_function;
	fn_hook = __flexiblas_hooks->crotg.f77_hook_function[0];
	hook_pos_crotg = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) ca, (void*) cb, (void*) c, (void*) s);
	} else {
		fn((void*) ca, (void*) cb, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void crotg_(float complex* ca, float complex* cb, float* c, float complex* s) __attribute__((alias(MTS(FC_GLOBAL(crotg,CROTG)))));
#else
#ifndef __APPLE__
void crotg(float complex* ca, float complex* cb, float* c, float complex* s) __attribute__((alias(MTS(FC_GLOBAL(crotg,CROTG)))));
#else
void crotg(float complex* ca, float complex* cb, float* c, float complex* s){ FC_GLOBAL(crotg,CROTG)((void*) ca, (void*) cb, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(cscal,CSCAL)(blasint* n, float complex* ca, float complex* cx, blasint* incx)
{
	void (*fn) (void* n, void* ca, void* cx, void* incx);
	void (*fn_hook) (void* n, void* ca, void* cx, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cscal.f77_blas_function;
	fn_hook = __flexiblas_hooks->cscal.f77_hook_function[0];
	hook_pos_cscal = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) ca, (void*) cx, (void*) incx);
	} else {
		fn((void*) n, (void*) ca, (void*) cx, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cscal_(blasint* n, float complex* ca, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(cscal,CSCAL)))));
#else
#ifndef __APPLE__
void cscal(blasint* n, float complex* ca, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(cscal,CSCAL)))));
#else
void cscal(blasint* n, float complex* ca, float complex* cx, blasint* incx){ FC_GLOBAL(cscal,CSCAL)((void*) n, (void*) ca, (void*) cx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(csrot,CSROT)(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy, float* c, float* s)
{
	void (*fn) (void* n, void* cx, void* incx, void* cy, void* incy, void* c, void* s);
	void (*fn_hook) (void* n, void* cx, void* incx, void* cy, void* incy, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.csrot.f77_blas_function;
	fn_hook = __flexiblas_hooks->csrot.f77_hook_function[0];
	hook_pos_csrot = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy, (void*) c, (void*) s);
	} else {
		fn((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void csrot_(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy, float* c, float* s) __attribute__((alias(MTS(FC_GLOBAL(csrot,CSROT)))));
#else
#ifndef __APPLE__
void csrot(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy, float* c, float* s) __attribute__((alias(MTS(FC_GLOBAL(csrot,CSROT)))));
#else
void csrot(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy, float* c, float* s){ FC_GLOBAL(csrot,CSROT)((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(csscal,CSSCAL)(blasint* n, float* sa, float complex* cx, blasint* incx)
{
	void (*fn) (void* n, void* sa, void* cx, void* incx);
	void (*fn_hook) (void* n, void* sa, void* cx, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.csscal.f77_blas_function;
	fn_hook = __flexiblas_hooks->csscal.f77_hook_function[0];
	hook_pos_csscal = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sa, (void*) cx, (void*) incx);
	} else {
		fn((void*) n, (void*) sa, (void*) cx, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void csscal_(blasint* n, float* sa, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(csscal,CSSCAL)))));
#else
#ifndef __APPLE__
void csscal(blasint* n, float* sa, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(csscal,CSSCAL)))));
#else
void csscal(blasint* n, float* sa, float complex* cx, blasint* incx){ FC_GLOBAL(csscal,CSSCAL)((void*) n, (void*) sa, (void*) cx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(cswap,CSWAP)(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy)
{
	void (*fn) (void* n, void* cx, void* incx, void* cy, void* incy);
	void (*fn_hook) (void* n, void* cx, void* incx, void* cy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cswap.f77_blas_function;
	fn_hook = __flexiblas_hooks->cswap.f77_hook_function[0];
	hook_pos_cswap = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
	} else {
		fn((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cswap_(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cswap,CSWAP)))));
#else
#ifndef __APPLE__
void cswap(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(cswap,CSWAP)))));
#else
void cswap(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy){ FC_GLOBAL(cswap,CSWAP)((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(csymm,CSYMM)(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.csymm.f77_blas_function;
	fn_hook = __flexiblas_hooks->csymm.f77_hook_function[0];
	hook_pos_csymm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void csymm_(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(csymm,CSYMM)))));
#else
#ifndef __APPLE__
void csymm(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(csymm,CSYMM)))));
#else
void csymm(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc){ FC_GLOBAL(csymm,CSYMM)((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(csyr2k,CSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.csyr2k.f77_blas_function;
	fn_hook = __flexiblas_hooks->csyr2k.f77_hook_function[0];
	hook_pos_csyr2k = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void csyr2k_(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(csyr2k,CSYR2K)))));
#else
#ifndef __APPLE__
void csyr2k(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(csyr2k,CSYR2K)))));
#else
void csyr2k(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc){ FC_GLOBAL(csyr2k,CSYR2K)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(csyrk,CSYRK)(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.csyrk.f77_blas_function;
	fn_hook = __flexiblas_hooks->csyrk.f77_hook_function[0];
	hook_pos_csyrk = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void csyrk_(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(csyrk,CSYRK)))));
#else
#ifndef __APPLE__
void csyrk(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(csyrk,CSYRK)))));
#else
void csyrk(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* c, blasint* ldc){ FC_GLOBAL(csyrk,CSYRK)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(ctbmv,CTBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctbmv.f77_hook_function[0];
	hook_pos_ctbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctbmv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctbmv,CTBMV)))));
#else
#ifndef __APPLE__
void ctbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctbmv,CTBMV)))));
#else
void ctbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx){ FC_GLOBAL(ctbmv,CTBMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ctbsv,CTBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctbsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctbsv.f77_hook_function[0];
	hook_pos_ctbsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctbsv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctbsv,CTBSV)))));
#else
#ifndef __APPLE__
void ctbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctbsv,CTBSV)))));
#else
void ctbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx){ FC_GLOBAL(ctbsv,CTBSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ctpmv,CTPMV)(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctpmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctpmv.f77_hook_function[0];
	hook_pos_ctpmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctpmv_(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctpmv,CTPMV)))));
#else
#ifndef __APPLE__
void ctpmv(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctpmv,CTPMV)))));
#else
void ctpmv(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx){ FC_GLOBAL(ctpmv,CTPMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ctpsv,CTPSV)(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctpsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctpsv.f77_hook_function[0];
	hook_pos_ctpsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctpsv_(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctpsv,CTPSV)))));
#else
#ifndef __APPLE__
void ctpsv(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctpsv,CTPSV)))));
#else
void ctpsv(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx){ FC_GLOBAL(ctpsv,CTPSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ctrmm,CTRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctrmm.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctrmm.f77_hook_function[0];
	hook_pos_ctrmm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctrmm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ctrmm,CTRMM)))));
#else
#ifndef __APPLE__
void ctrmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ctrmm,CTRMM)))));
#else
void ctrmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb){ FC_GLOBAL(ctrmm,CTRMM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(ctrmv,CTRMV)(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctrmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctrmv.f77_hook_function[0];
	hook_pos_ctrmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctrmv_(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctrmv,CTRMV)))));
#else
#ifndef __APPLE__
void ctrmv(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctrmv,CTRMV)))));
#else
void ctrmv(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx){ FC_GLOBAL(ctrmv,CTRMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ctrsm,CTRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctrsm.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctrsm.f77_hook_function[0];
	hook_pos_ctrsm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctrsm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ctrsm,CTRSM)))));
#else
#ifndef __APPLE__
void ctrsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ctrsm,CTRSM)))));
#else
void ctrsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb){ FC_GLOBAL(ctrsm,CTRSM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(ctrsv,CTRSV)(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ctrsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ctrsv.f77_hook_function[0];
	hook_pos_ctrsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ctrsv_(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctrsv,CTRSV)))));
#else
#ifndef __APPLE__
void ctrsv(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ctrsv,CTRSV)))));
#else
void ctrsv(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx){ FC_GLOBAL(ctrsv,CTRSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



double FC_GLOBAL(dasum,DASUM)(blasint* n, double* dx, blasint* incx)
{
	double (*fn) (void* n, void* dx, void* incx);
	double (*fn_hook) (void* n, void* dx, void* incx);
	double ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dasum.f77_blas_function;
	fn_hook = __flexiblas_hooks->dasum.f77_hook_function[0];
	hook_pos_dasum = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) dx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) dx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
double dasum_(blasint* n, double* dx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dasum,DASUM)))));
#else
#ifndef __APPLE__
double dasum(blasint* n, double* dx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dasum,DASUM)))));
#else
double dasum(blasint* n, double* dx, blasint* incx){ return FC_GLOBAL(dasum,DASUM)((void*) n, (void*) dx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(daxpy,DAXPY)(blasint* n, double* da, double* dx, blasint* incx, double* dy, blasint* incy)
{
	void (*fn) (void* n, void* da, void* dx, void* incx, void* dy, void* incy);
	void (*fn_hook) (void* n, void* da, void* dx, void* incx, void* dy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.daxpy.f77_blas_function;
	fn_hook = __flexiblas_hooks->daxpy.f77_hook_function[0];
	hook_pos_daxpy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) da, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	} else {
		fn((void*) n, (void*) da, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void daxpy_(blasint* n, double* da, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(daxpy,DAXPY)))));
#else
#ifndef __APPLE__
void daxpy(blasint* n, double* da, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(daxpy,DAXPY)))));
#else
void daxpy(blasint* n, double* da, double* dx, blasint* incx, double* dy, blasint* incy){ FC_GLOBAL(daxpy,DAXPY)((void*) n, (void*) da, (void*) dx, (void*) incx, (void*) dy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dcopy,DCOPY)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy)
{
	void (*fn) (void* n, void* dx, void* incx, void* dy, void* incy);
	void (*fn_hook) (void* n, void* dx, void* incx, void* dy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->dcopy.f77_hook_function[0];
	hook_pos_dcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	} else {
		fn((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dcopy_(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dcopy,DCOPY)))));
#else
#ifndef __APPLE__
void dcopy(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dcopy,DCOPY)))));
#else
void dcopy(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy){ FC_GLOBAL(dcopy,DCOPY)((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy); }
#endif
#endif



double FC_GLOBAL(ddot,DDOT)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy)
{
	double (*fn) (void* n, void* dx, void* incx, void* dy, void* incy);
	double (*fn_hook) (void* n, void* dx, void* incx, void* dy, void* incy);
	double ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ddot.f77_blas_function;
	fn_hook = __flexiblas_hooks->ddot.f77_hook_function[0];
	hook_pos_ddot = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	} else {
		ret = fn((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
double ddot_(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ddot,DDOT)))));
#else
#ifndef __APPLE__
double ddot(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ddot,DDOT)))));
#else
double ddot(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy){ return FC_GLOBAL(ddot,DDOT)((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dgbmv,DGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dgbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dgbmv.f77_hook_function[0];
	hook_pos_dgbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dgbmv_(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dgbmv,DGBMV)))));
#else
#ifndef __APPLE__
void dgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dgbmv,DGBMV)))));
#else
void dgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy){ FC_GLOBAL(dgbmv,DGBMV)((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dgemm,DGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc)
{
	void (*fn) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dgemm.f77_blas_function;
	fn_hook = __flexiblas_hooks->dgemm.f77_hook_function[0];
	hook_pos_dgemm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dgemm_(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dgemm,DGEMM)))));
#else
#ifndef __APPLE__
void dgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dgemm,DGEMM)))));
#else
void dgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc){ FC_GLOBAL(dgemm,DGEMM)((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(dgemv,DGEMV)(char* trans, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dgemv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dgemv.f77_hook_function[0];
	hook_pos_dgemv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dgemv_(char* trans, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dgemv,DGEMV)))));
#else
#ifndef __APPLE__
void dgemv(char* trans, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dgemv,DGEMV)))));
#else
void dgemv(char* trans, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy){ FC_GLOBAL(dgemv,DGEMV)((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dger,DGER)(blasint* m, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda)
{
	void (*fn) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dger.f77_blas_function;
	fn_hook = __flexiblas_hooks->dger.f77_hook_function[0];
	hook_pos_dger = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dger_(blasint* m, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(dger,DGER)))));
#else
#ifndef __APPLE__
void dger(blasint* m, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(dger,DGER)))));
#else
void dger(blasint* m, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda){ FC_GLOBAL(dger,DGER)((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



double FC_GLOBAL(dnrm2,DNRM2)(blasint* n, double* x, blasint* incx)
{
	double (*fn) (void* n, void* x, void* incx);
	double (*fn_hook) (void* n, void* x, void* incx);
	double ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dnrm2.f77_blas_function;
	fn_hook = __flexiblas_hooks->dnrm2.f77_hook_function[0];
	hook_pos_dnrm2 = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) x, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) x, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
double dnrm2_(blasint* n, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dnrm2,DNRM2)))));
#else
#ifndef __APPLE__
double dnrm2(blasint* n, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dnrm2,DNRM2)))));
#else
double dnrm2(blasint* n, double* x, blasint* incx){ return FC_GLOBAL(dnrm2,DNRM2)((void*) n, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(drot,DROT)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* c, double* s)
{
	void (*fn) (void* n, void* dx, void* incx, void* dy, void* incy, void* c, void* s);
	void (*fn_hook) (void* n, void* dx, void* incx, void* dy, void* incy, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.drot.f77_blas_function;
	fn_hook = __flexiblas_hooks->drot.f77_hook_function[0];
	hook_pos_drot = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy, (void*) c, (void*) s);
	} else {
		fn((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void drot_(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* c, double* s) __attribute__((alias(MTS(FC_GLOBAL(drot,DROT)))));
#else
#ifndef __APPLE__
void drot(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* c, double* s) __attribute__((alias(MTS(FC_GLOBAL(drot,DROT)))));
#else
void drot(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* c, double* s){ FC_GLOBAL(drot,DROT)((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(drotg,DROTG)(double* da, double* db, double* c, double* s)
{
	void (*fn) (void* da, void* db, void* c, void* s);
	void (*fn_hook) (void* da, void* db, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.drotg.f77_blas_function;
	fn_hook = __flexiblas_hooks->drotg.f77_hook_function[0];
	hook_pos_drotg = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) da, (void*) db, (void*) c, (void*) s);
	} else {
		fn((void*) da, (void*) db, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void drotg_(double* da, double* db, double* c, double* s) __attribute__((alias(MTS(FC_GLOBAL(drotg,DROTG)))));
#else
#ifndef __APPLE__
void drotg(double* da, double* db, double* c, double* s) __attribute__((alias(MTS(FC_GLOBAL(drotg,DROTG)))));
#else
void drotg(double* da, double* db, double* c, double* s){ FC_GLOBAL(drotg,DROTG)((void*) da, (void*) db, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(drotm,DROTM)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* dparam)
{
	void (*fn) (void* n, void* dx, void* incx, void* dy, void* incy, void* dparam);
	void (*fn_hook) (void* n, void* dx, void* incx, void* dy, void* incy, void* dparam);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.drotm.f77_blas_function;
	fn_hook = __flexiblas_hooks->drotm.f77_hook_function[0];
	hook_pos_drotm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy, (void*) dparam);
	} else {
		fn((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy, (void*) dparam);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void drotm_(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* dparam) __attribute__((alias(MTS(FC_GLOBAL(drotm,DROTM)))));
#else
#ifndef __APPLE__
void drotm(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* dparam) __attribute__((alias(MTS(FC_GLOBAL(drotm,DROTM)))));
#else
void drotm(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* dparam){ FC_GLOBAL(drotm,DROTM)((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy, (void*) dparam); }
#endif
#endif



void FC_GLOBAL(drotmg,DROTMG)(double* dd1, double* dd2, double* dx1, double* dy1, double* dparam)
{
	void (*fn) (void* dd1, void* dd2, void* dx1, void* dy1, void* dparam);
	void (*fn_hook) (void* dd1, void* dd2, void* dx1, void* dy1, void* dparam);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.drotmg.f77_blas_function;
	fn_hook = __flexiblas_hooks->drotmg.f77_hook_function[0];
	hook_pos_drotmg = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) dd1, (void*) dd2, (void*) dx1, (void*) dy1, (void*) dparam);
	} else {
		fn((void*) dd1, (void*) dd2, (void*) dx1, (void*) dy1, (void*) dparam);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void drotmg_(double* dd1, double* dd2, double* dx1, double* dy1, double* dparam) __attribute__((alias(MTS(FC_GLOBAL(drotmg,DROTMG)))));
#else
#ifndef __APPLE__
void drotmg(double* dd1, double* dd2, double* dx1, double* dy1, double* dparam) __attribute__((alias(MTS(FC_GLOBAL(drotmg,DROTMG)))));
#else
void drotmg(double* dd1, double* dd2, double* dx1, double* dy1, double* dparam){ FC_GLOBAL(drotmg,DROTMG)((void*) dd1, (void*) dd2, (void*) dx1, (void*) dy1, (void*) dparam); }
#endif
#endif



void FC_GLOBAL(dsbmv,DSBMV)(char* uplo, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsbmv.f77_hook_function[0];
	hook_pos_dsbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsbmv_(char* uplo, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dsbmv,DSBMV)))));
#else
#ifndef __APPLE__
void dsbmv(char* uplo, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dsbmv,DSBMV)))));
#else
void dsbmv(char* uplo, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy){ FC_GLOBAL(dsbmv,DSBMV)((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dscal,DSCAL)(blasint* n, double* da, double* dx, blasint* incx)
{
	void (*fn) (void* n, void* da, void* dx, void* incx);
	void (*fn_hook) (void* n, void* da, void* dx, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dscal.f77_blas_function;
	fn_hook = __flexiblas_hooks->dscal.f77_hook_function[0];
	hook_pos_dscal = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) da, (void*) dx, (void*) incx);
	} else {
		fn((void*) n, (void*) da, (void*) dx, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dscal_(blasint* n, double* da, double* dx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dscal,DSCAL)))));
#else
#ifndef __APPLE__
void dscal(blasint* n, double* da, double* dx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dscal,DSCAL)))));
#else
void dscal(blasint* n, double* da, double* dx, blasint* incx){ FC_GLOBAL(dscal,DSCAL)((void*) n, (void*) da, (void*) dx, (void*) incx); }
#endif
#endif



double FC_GLOBAL(dsdot,DSDOT)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy)
{
	double (*fn) (void* n, void* sx, void* incx, void* sy, void* incy);
	double (*fn_hook) (void* n, void* sx, void* incx, void* sy, void* incy);
	double ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsdot.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsdot.f77_hook_function[0];
	hook_pos_dsdot = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	} else {
		ret = fn((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
double dsdot_(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dsdot,DSDOT)))));
#else
#ifndef __APPLE__
double dsdot(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dsdot,DSDOT)))));
#else
double dsdot(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy){ return FC_GLOBAL(dsdot,DSDOT)((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dspmv,DSPMV)(char* uplo, blasint* n, double* alpha, double* ap, double* x, blasint* incx, double* beta, double* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dspmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dspmv.f77_hook_function[0];
	hook_pos_dspmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dspmv_(char* uplo, blasint* n, double* alpha, double* ap, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dspmv,DSPMV)))));
#else
#ifndef __APPLE__
void dspmv(char* uplo, blasint* n, double* alpha, double* ap, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dspmv,DSPMV)))));
#else
void dspmv(char* uplo, blasint* n, double* alpha, double* ap, double* x, blasint* incx, double* beta, double* y, blasint* incy){ FC_GLOBAL(dspmv,DSPMV)((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dspr,DSPR)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dspr.f77_blas_function;
	fn_hook = __flexiblas_hooks->dspr.f77_hook_function[0];
	hook_pos_dspr = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dspr_(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* ap) __attribute__((alias(MTS(FC_GLOBAL(dspr,DSPR)))));
#else
#ifndef __APPLE__
void dspr(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* ap) __attribute__((alias(MTS(FC_GLOBAL(dspr,DSPR)))));
#else
void dspr(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* ap){ FC_GLOBAL(dspr,DSPR)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap); }
#endif
#endif



void FC_GLOBAL(dspr2,DSPR2)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dspr2.f77_blas_function;
	fn_hook = __flexiblas_hooks->dspr2.f77_hook_function[0];
	hook_pos_dspr2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dspr2_(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* ap) __attribute__((alias(MTS(FC_GLOBAL(dspr2,DSPR2)))));
#else
#ifndef __APPLE__
void dspr2(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* ap) __attribute__((alias(MTS(FC_GLOBAL(dspr2,DSPR2)))));
#else
void dspr2(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* ap){ FC_GLOBAL(dspr2,DSPR2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap); }
#endif
#endif



void FC_GLOBAL(dswap,DSWAP)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy)
{
	void (*fn) (void* n, void* dx, void* incx, void* dy, void* incy);
	void (*fn_hook) (void* n, void* dx, void* incx, void* dy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dswap.f77_blas_function;
	fn_hook = __flexiblas_hooks->dswap.f77_hook_function[0];
	hook_pos_dswap = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	} else {
		fn((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dswap_(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dswap,DSWAP)))));
#else
#ifndef __APPLE__
void dswap(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dswap,DSWAP)))));
#else
void dswap(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy){ FC_GLOBAL(dswap,DSWAP)((void*) n, (void*) dx, (void*) incx, (void*) dy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dsymm,DSYMM)(char* side, char* uplo, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc)
{
	void (*fn) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsymm.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsymm.f77_hook_function[0];
	hook_pos_dsymm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsymm_(char* side, char* uplo, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dsymm,DSYMM)))));
#else
#ifndef __APPLE__
void dsymm(char* side, char* uplo, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dsymm,DSYMM)))));
#else
void dsymm(char* side, char* uplo, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc){ FC_GLOBAL(dsymm,DSYMM)((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(dsymv,DSYMV)(char* uplo, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsymv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsymv.f77_hook_function[0];
	hook_pos_dsymv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsymv_(char* uplo, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dsymv,DSYMV)))));
#else
#ifndef __APPLE__
void dsymv(char* uplo, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(dsymv,DSYMV)))));
#else
void dsymv(char* uplo, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy){ FC_GLOBAL(dsymv,DSYMV)((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(dsyr,DSYR)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsyr.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsyr.f77_hook_function[0];
	hook_pos_dsyr = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsyr_(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(dsyr,DSYR)))));
#else
#ifndef __APPLE__
void dsyr(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(dsyr,DSYR)))));
#else
void dsyr(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* a, blasint* lda){ FC_GLOBAL(dsyr,DSYR)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(dsyr2,DSYR2)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsyr2.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsyr2.f77_hook_function[0];
	hook_pos_dsyr2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsyr2_(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(dsyr2,DSYR2)))));
#else
#ifndef __APPLE__
void dsyr2(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(dsyr2,DSYR2)))));
#else
void dsyr2(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda){ FC_GLOBAL(dsyr2,DSYR2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(dsyr2k,DSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsyr2k.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsyr2k.f77_hook_function[0];
	hook_pos_dsyr2k = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsyr2k_(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dsyr2k,DSYR2K)))));
#else
#ifndef __APPLE__
void dsyr2k(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dsyr2k,DSYR2K)))));
#else
void dsyr2k(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc){ FC_GLOBAL(dsyr2k,DSYR2K)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(dsyrk,DSYRK)(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* beta, double* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dsyrk.f77_blas_function;
	fn_hook = __flexiblas_hooks->dsyrk.f77_hook_function[0];
	hook_pos_dsyrk = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dsyrk_(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dsyrk,DSYRK)))));
#else
#ifndef __APPLE__
void dsyrk(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* beta, double* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(dsyrk,DSYRK)))));
#else
void dsyrk(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* beta, double* c, blasint* ldc){ FC_GLOBAL(dsyrk,DSYRK)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(dtbmv,DTBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtbmv.f77_hook_function[0];
	hook_pos_dtbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtbmv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtbmv,DTBMV)))));
#else
#ifndef __APPLE__
void dtbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtbmv,DTBMV)))));
#else
void dtbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx){ FC_GLOBAL(dtbmv,DTBMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(dtbsv,DTBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtbsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtbsv.f77_hook_function[0];
	hook_pos_dtbsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtbsv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtbsv,DTBSV)))));
#else
#ifndef __APPLE__
void dtbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtbsv,DTBSV)))));
#else
void dtbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx){ FC_GLOBAL(dtbsv,DTBSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(dtpmv,DTPMV)(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtpmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtpmv.f77_hook_function[0];
	hook_pos_dtpmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtpmv_(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtpmv,DTPMV)))));
#else
#ifndef __APPLE__
void dtpmv(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtpmv,DTPMV)))));
#else
void dtpmv(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx){ FC_GLOBAL(dtpmv,DTPMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(dtpsv,DTPSV)(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtpsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtpsv.f77_hook_function[0];
	hook_pos_dtpsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtpsv_(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtpsv,DTPSV)))));
#else
#ifndef __APPLE__
void dtpsv(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtpsv,DTPSV)))));
#else
void dtpsv(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx){ FC_GLOBAL(dtpsv,DTPSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(dtrmm,DTRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtrmm.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtrmm.f77_hook_function[0];
	hook_pos_dtrmm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtrmm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dtrmm,DTRMM)))));
#else
#ifndef __APPLE__
void dtrmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dtrmm,DTRMM)))));
#else
void dtrmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb){ FC_GLOBAL(dtrmm,DTRMM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(dtrmv,DTRMV)(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtrmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtrmv.f77_hook_function[0];
	hook_pos_dtrmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtrmv_(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtrmv,DTRMV)))));
#else
#ifndef __APPLE__
void dtrmv(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtrmv,DTRMV)))));
#else
void dtrmv(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx){ FC_GLOBAL(dtrmv,DTRMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(dtrsm,DTRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtrsm.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtrsm.f77_hook_function[0];
	hook_pos_dtrsm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtrsm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dtrsm,DTRSM)))));
#else
#ifndef __APPLE__
void dtrsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dtrsm,DTRSM)))));
#else
void dtrsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb){ FC_GLOBAL(dtrsm,DTRSM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(dtrsv,DTRSV)(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dtrsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->dtrsv.f77_hook_function[0];
	hook_pos_dtrsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dtrsv_(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtrsv,DTRSV)))));
#else
#ifndef __APPLE__
void dtrsv(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dtrsv,DTRSV)))));
#else
void dtrsv(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx){ FC_GLOBAL(dtrsv,DTRSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



double FC_GLOBAL(dzasum,DZASUM)(blasint* n, double complex* zx, blasint* incx)
{
	double (*fn) (void* n, void* zx, void* incx);
	double (*fn_hook) (void* n, void* zx, void* incx);
	double ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dzasum.f77_blas_function;
	fn_hook = __flexiblas_hooks->dzasum.f77_hook_function[0];
	hook_pos_dzasum = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) zx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) zx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
double dzasum_(blasint* n, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dzasum,DZASUM)))));
#else
#ifndef __APPLE__
double dzasum(blasint* n, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dzasum,DZASUM)))));
#else
double dzasum(blasint* n, double complex* zx, blasint* incx){ return FC_GLOBAL(dzasum,DZASUM)((void*) n, (void*) zx, (void*) incx); }
#endif
#endif



double FC_GLOBAL(dznrm2,DZNRM2)(blasint* n, double complex* x, blasint* incx)
{
	double (*fn) (void* n, void* x, void* incx);
	double (*fn_hook) (void* n, void* x, void* incx);
	double ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dznrm2.f77_blas_function;
	fn_hook = __flexiblas_hooks->dznrm2.f77_hook_function[0];
	hook_pos_dznrm2 = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) x, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) x, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
double dznrm2_(blasint* n, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dznrm2,DZNRM2)))));
#else
#ifndef __APPLE__
double dznrm2(blasint* n, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(dznrm2,DZNRM2)))));
#else
double dznrm2(blasint* n, double complex* x, blasint* incx){ return FC_GLOBAL(dznrm2,DZNRM2)((void*) n, (void*) x, (void*) incx); }
#endif
#endif



int FC_GLOBAL(icamax,ICAMAX)(blasint* n, float complex* cx, blasint* incx)
{
	blasint (*fn) (void* n, void* cx, void* incx);
	blasint (*fn_hook) (void* n, void* cx, void* incx);
	blasint ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.icamax.f77_blas_function;
	fn_hook = __flexiblas_hooks->icamax.f77_hook_function[0];
	hook_pos_icamax = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) cx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) cx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
int icamax_(blasint* n, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(icamax,ICAMAX)))));
#else
#ifndef __APPLE__
int icamax(blasint* n, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(icamax,ICAMAX)))));
#else
int icamax(blasint* n, float complex* cx, blasint* incx){ return FC_GLOBAL(icamax,ICAMAX)((void*) n, (void*) cx, (void*) incx); }
#endif
#endif



int FC_GLOBAL(idamax,IDAMAX)(blasint* n, double* dx, blasint* incx)
{
	blasint (*fn) (void* n, void* dx, void* incx);
	blasint (*fn_hook) (void* n, void* dx, void* incx);
	blasint ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.idamax.f77_blas_function;
	fn_hook = __flexiblas_hooks->idamax.f77_hook_function[0];
	hook_pos_idamax = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) dx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) dx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
int idamax_(blasint* n, double* dx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(idamax,IDAMAX)))));
#else
#ifndef __APPLE__
int idamax(blasint* n, double* dx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(idamax,IDAMAX)))));
#else
int idamax(blasint* n, double* dx, blasint* incx){ return FC_GLOBAL(idamax,IDAMAX)((void*) n, (void*) dx, (void*) incx); }
#endif
#endif



int FC_GLOBAL(isamax,ISAMAX)(blasint* n, float* sx, blasint* incx)
{
	blasint (*fn) (void* n, void* sx, void* incx);
	blasint (*fn_hook) (void* n, void* sx, void* incx);
	blasint ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.isamax.f77_blas_function;
	fn_hook = __flexiblas_hooks->isamax.f77_hook_function[0];
	hook_pos_isamax = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) sx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) sx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
int isamax_(blasint* n, float* sx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(isamax,ISAMAX)))));
#else
#ifndef __APPLE__
int isamax(blasint* n, float* sx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(isamax,ISAMAX)))));
#else
int isamax(blasint* n, float* sx, blasint* incx){ return FC_GLOBAL(isamax,ISAMAX)((void*) n, (void*) sx, (void*) incx); }
#endif
#endif



int FC_GLOBAL(izamax,IZAMAX)(blasint* n, double complex* zx, blasint* incx)
{
	blasint (*fn) (void* n, void* zx, void* incx);
	blasint (*fn_hook) (void* n, void* zx, void* incx);
	blasint ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.izamax.f77_blas_function;
	fn_hook = __flexiblas_hooks->izamax.f77_hook_function[0];
	hook_pos_izamax = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) zx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) zx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
int izamax_(blasint* n, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(izamax,IZAMAX)))));
#else
#ifndef __APPLE__
int izamax(blasint* n, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(izamax,IZAMAX)))));
#else
int izamax(blasint* n, double complex* zx, blasint* incx){ return FC_GLOBAL(izamax,IZAMAX)((void*) n, (void*) zx, (void*) incx); }
#endif
#endif



float FC_GLOBAL(sasum,SASUM)(blasint* n, float* sx, blasint* incx)
{
	float (*fn) (void* n, void* sx, void* incx);
	float (*fn_hook) (void* n, void* sx, void* incx);
	float ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sasum.f77_blas_function;
	fn_hook = __flexiblas_hooks->sasum.f77_hook_function[0];
	hook_pos_sasum = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) sx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) sx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
float sasum_(blasint* n, float* sx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(sasum,SASUM)))));
#else
#ifndef __APPLE__
float sasum(blasint* n, float* sx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(sasum,SASUM)))));
#else
float sasum(blasint* n, float* sx, blasint* incx){ return FC_GLOBAL(sasum,SASUM)((void*) n, (void*) sx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(saxpy,SAXPY)(blasint* n, float* sa, float* sx, blasint* incx, float* sy, blasint* incy)
{
	void (*fn) (void* n, void* sa, void* sx, void* incx, void* sy, void* incy);
	void (*fn_hook) (void* n, void* sa, void* sx, void* incx, void* sy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.saxpy.f77_blas_function;
	fn_hook = __flexiblas_hooks->saxpy.f77_hook_function[0];
	hook_pos_saxpy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sa, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	} else {
		fn((void*) n, (void*) sa, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void saxpy_(blasint* n, float* sa, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(saxpy,SAXPY)))));
#else
#ifndef __APPLE__
void saxpy(blasint* n, float* sa, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(saxpy,SAXPY)))));
#else
void saxpy(blasint* n, float* sa, float* sx, blasint* incx, float* sy, blasint* incy){ FC_GLOBAL(saxpy,SAXPY)((void*) n, (void*) sa, (void*) sx, (void*) incx, (void*) sy, (void*) incy); }
#endif
#endif



float FC_GLOBAL(scasum,SCASUM)(blasint* n, float complex* cx, blasint* incx)
{
	float (*fn) (void* n, void* cx, void* incx);
	float (*fn_hook) (void* n, void* cx, void* incx);
	float ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.scasum.f77_blas_function;
	fn_hook = __flexiblas_hooks->scasum.f77_hook_function[0];
	hook_pos_scasum = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) cx, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) cx, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
float scasum_(blasint* n, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(scasum,SCASUM)))));
#else
#ifndef __APPLE__
float scasum(blasint* n, float complex* cx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(scasum,SCASUM)))));
#else
float scasum(blasint* n, float complex* cx, blasint* incx){ return FC_GLOBAL(scasum,SCASUM)((void*) n, (void*) cx, (void*) incx); }
#endif
#endif



float FC_GLOBAL(scnrm2,SCNRM2)(blasint* n, float complex* x, blasint* incx)
{
	float (*fn) (void* n, void* x, void* incx);
	float (*fn_hook) (void* n, void* x, void* incx);
	float ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.scnrm2.f77_blas_function;
	fn_hook = __flexiblas_hooks->scnrm2.f77_hook_function[0];
	hook_pos_scnrm2 = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) x, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) x, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
float scnrm2_(blasint* n, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(scnrm2,SCNRM2)))));
#else
#ifndef __APPLE__
float scnrm2(blasint* n, float complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(scnrm2,SCNRM2)))));
#else
float scnrm2(blasint* n, float complex* x, blasint* incx){ return FC_GLOBAL(scnrm2,SCNRM2)((void*) n, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(scopy,SCOPY)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy)
{
	void (*fn) (void* n, void* sx, void* incx, void* sy, void* incy);
	void (*fn_hook) (void* n, void* sx, void* incx, void* sy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.scopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->scopy.f77_hook_function[0];
	hook_pos_scopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	} else {
		fn((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void scopy_(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(scopy,SCOPY)))));
#else
#ifndef __APPLE__
void scopy(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(scopy,SCOPY)))));
#else
void scopy(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy){ FC_GLOBAL(scopy,SCOPY)((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy); }
#endif
#endif



float FC_GLOBAL(sdot,SDOT)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy)
{
	float (*fn) (void* n, void* sx, void* incx, void* sy, void* incy);
	float (*fn_hook) (void* n, void* sx, void* incx, void* sy, void* incy);
	float ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sdot.f77_blas_function;
	fn_hook = __flexiblas_hooks->sdot.f77_hook_function[0];
	hook_pos_sdot = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	} else {
		ret = fn((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
float sdot_(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sdot,SDOT)))));
#else
#ifndef __APPLE__
float sdot(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sdot,SDOT)))));
#else
float sdot(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy){ return FC_GLOBAL(sdot,SDOT)((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy); }
#endif
#endif



float FC_GLOBAL(sdsdot,SDSDOT)(blasint* n, float* sb, float* sx, blasint* incx, float* sy, blasint* incy)
{
	float (*fn) (void* n, void* sb, void* sx, void* incx, void* sy, void* incy);
	float (*fn_hook) (void* n, void* sb, void* sx, void* incx, void* sy, void* incy);
	float ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sdsdot.f77_blas_function;
	fn_hook = __flexiblas_hooks->sdsdot.f77_hook_function[0];
	hook_pos_sdsdot = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) sb, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	} else {
		ret = fn((void*) n, (void*) sb, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
float sdsdot_(blasint* n, float* sb, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sdsdot,SDSDOT)))));
#else
#ifndef __APPLE__
float sdsdot(blasint* n, float* sb, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sdsdot,SDSDOT)))));
#else
float sdsdot(blasint* n, float* sb, float* sx, blasint* incx, float* sy, blasint* incy){ return FC_GLOBAL(sdsdot,SDSDOT)((void*) n, (void*) sb, (void*) sx, (void*) incx, (void*) sy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(sgbmv,SGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sgbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->sgbmv.f77_hook_function[0];
	hook_pos_sgbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sgbmv_(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sgbmv,SGBMV)))));
#else
#ifndef __APPLE__
void sgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sgbmv,SGBMV)))));
#else
void sgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy){ FC_GLOBAL(sgbmv,SGBMV)((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(sgemm,SGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc)
{
	void (*fn) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sgemm.f77_blas_function;
	fn_hook = __flexiblas_hooks->sgemm.f77_hook_function[0];
	hook_pos_sgemm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sgemm_(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(sgemm,SGEMM)))));
#else
#ifndef __APPLE__
void sgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(sgemm,SGEMM)))));
#else
void sgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc){ FC_GLOBAL(sgemm,SGEMM)((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(sgemv,SGEMV)(char* trans, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sgemv.f77_blas_function;
	fn_hook = __flexiblas_hooks->sgemv.f77_hook_function[0];
	hook_pos_sgemv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sgemv_(char* trans, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sgemv,SGEMV)))));
#else
#ifndef __APPLE__
void sgemv(char* trans, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sgemv,SGEMV)))));
#else
void sgemv(char* trans, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy){ FC_GLOBAL(sgemv,SGEMV)((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(sger,SGER)(blasint* m, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda)
{
	void (*fn) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sger.f77_blas_function;
	fn_hook = __flexiblas_hooks->sger.f77_hook_function[0];
	hook_pos_sger = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sger_(blasint* m, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(sger,SGER)))));
#else
#ifndef __APPLE__
void sger(blasint* m, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(sger,SGER)))));
#else
void sger(blasint* m, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda){ FC_GLOBAL(sger,SGER)((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



float FC_GLOBAL(snrm2,SNRM2)(blasint* n, float* x, blasint* incx)
{
	float (*fn) (void* n, void* x, void* incx);
	float (*fn_hook) (void* n, void* x, void* incx);
	float ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.snrm2.f77_blas_function;
	fn_hook = __flexiblas_hooks->snrm2.f77_hook_function[0];
	hook_pos_snrm2 = 0;
	if ( fn_hook != NULL) {
		ret = fn_hook((void*) n, (void*) x, (void*) incx);
	} else {
		ret = fn((void*) n, (void*) x, (void*) incx);
	}
		return ret;
}
#ifdef FLEXIBLAS_ABI_IBM
float snrm2_(blasint* n, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(snrm2,SNRM2)))));
#else
#ifndef __APPLE__
float snrm2(blasint* n, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(snrm2,SNRM2)))));
#else
float snrm2(blasint* n, float* x, blasint* incx){ return FC_GLOBAL(snrm2,SNRM2)((void*) n, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(srot,SROT)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* c, float* s)
{
	void (*fn) (void* n, void* sx, void* incx, void* sy, void* incy, void* c, void* s);
	void (*fn_hook) (void* n, void* sx, void* incx, void* sy, void* incy, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.srot.f77_blas_function;
	fn_hook = __flexiblas_hooks->srot.f77_hook_function[0];
	hook_pos_srot = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy, (void*) c, (void*) s);
	} else {
		fn((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void srot_(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* c, float* s) __attribute__((alias(MTS(FC_GLOBAL(srot,SROT)))));
#else
#ifndef __APPLE__
void srot(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* c, float* s) __attribute__((alias(MTS(FC_GLOBAL(srot,SROT)))));
#else
void srot(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* c, float* s){ FC_GLOBAL(srot,SROT)((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(srotg,SROTG)(float* sa, float* sb, float* c, float* s)
{
	void (*fn) (void* sa, void* sb, void* c, void* s);
	void (*fn_hook) (void* sa, void* sb, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.srotg.f77_blas_function;
	fn_hook = __flexiblas_hooks->srotg.f77_hook_function[0];
	hook_pos_srotg = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) sa, (void*) sb, (void*) c, (void*) s);
	} else {
		fn((void*) sa, (void*) sb, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void srotg_(float* sa, float* sb, float* c, float* s) __attribute__((alias(MTS(FC_GLOBAL(srotg,SROTG)))));
#else
#ifndef __APPLE__
void srotg(float* sa, float* sb, float* c, float* s) __attribute__((alias(MTS(FC_GLOBAL(srotg,SROTG)))));
#else
void srotg(float* sa, float* sb, float* c, float* s){ FC_GLOBAL(srotg,SROTG)((void*) sa, (void*) sb, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(srotm,SROTM)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* sparam)
{
	void (*fn) (void* n, void* sx, void* incx, void* sy, void* incy, void* sparam);
	void (*fn_hook) (void* n, void* sx, void* incx, void* sy, void* incy, void* sparam);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.srotm.f77_blas_function;
	fn_hook = __flexiblas_hooks->srotm.f77_hook_function[0];
	hook_pos_srotm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy, (void*) sparam);
	} else {
		fn((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy, (void*) sparam);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void srotm_(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* sparam) __attribute__((alias(MTS(FC_GLOBAL(srotm,SROTM)))));
#else
#ifndef __APPLE__
void srotm(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* sparam) __attribute__((alias(MTS(FC_GLOBAL(srotm,SROTM)))));
#else
void srotm(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* sparam){ FC_GLOBAL(srotm,SROTM)((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy, (void*) sparam); }
#endif
#endif



void FC_GLOBAL(srotmg,SROTMG)(float* sd1, float* sd2, float* sx1, float* sy1, float* sparam)
{
	void (*fn) (void* sd1, void* sd2, void* sx1, void* sy1, void* sparam);
	void (*fn_hook) (void* sd1, void* sd2, void* sx1, void* sy1, void* sparam);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.srotmg.f77_blas_function;
	fn_hook = __flexiblas_hooks->srotmg.f77_hook_function[0];
	hook_pos_srotmg = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) sd1, (void*) sd2, (void*) sx1, (void*) sy1, (void*) sparam);
	} else {
		fn((void*) sd1, (void*) sd2, (void*) sx1, (void*) sy1, (void*) sparam);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void srotmg_(float* sd1, float* sd2, float* sx1, float* sy1, float* sparam) __attribute__((alias(MTS(FC_GLOBAL(srotmg,SROTMG)))));
#else
#ifndef __APPLE__
void srotmg(float* sd1, float* sd2, float* sx1, float* sy1, float* sparam) __attribute__((alias(MTS(FC_GLOBAL(srotmg,SROTMG)))));
#else
void srotmg(float* sd1, float* sd2, float* sx1, float* sy1, float* sparam){ FC_GLOBAL(srotmg,SROTMG)((void*) sd1, (void*) sd2, (void*) sx1, (void*) sy1, (void*) sparam); }
#endif
#endif



void FC_GLOBAL(ssbmv,SSBMV)(char* uplo, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssbmv.f77_hook_function[0];
	hook_pos_ssbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssbmv_(char* uplo, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ssbmv,SSBMV)))));
#else
#ifndef __APPLE__
void ssbmv(char* uplo, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ssbmv,SSBMV)))));
#else
void ssbmv(char* uplo, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy){ FC_GLOBAL(ssbmv,SSBMV)((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(sscal,SSCAL)(blasint* n, float* sa, float* sx, blasint* incx)
{
	void (*fn) (void* n, void* sa, void* sx, void* incx);
	void (*fn_hook) (void* n, void* sa, void* sx, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sscal.f77_blas_function;
	fn_hook = __flexiblas_hooks->sscal.f77_hook_function[0];
	hook_pos_sscal = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sa, (void*) sx, (void*) incx);
	} else {
		fn((void*) n, (void*) sa, (void*) sx, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sscal_(blasint* n, float* sa, float* sx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(sscal,SSCAL)))));
#else
#ifndef __APPLE__
void sscal(blasint* n, float* sa, float* sx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(sscal,SSCAL)))));
#else
void sscal(blasint* n, float* sa, float* sx, blasint* incx){ FC_GLOBAL(sscal,SSCAL)((void*) n, (void*) sa, (void*) sx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(sspmv,SSPMV)(char* uplo, blasint* n, float* alpha, float* ap, float* x, blasint* incx, float* beta, float* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sspmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->sspmv.f77_hook_function[0];
	hook_pos_sspmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sspmv_(char* uplo, blasint* n, float* alpha, float* ap, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sspmv,SSPMV)))));
#else
#ifndef __APPLE__
void sspmv(char* uplo, blasint* n, float* alpha, float* ap, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sspmv,SSPMV)))));
#else
void sspmv(char* uplo, blasint* n, float* alpha, float* ap, float* x, blasint* incx, float* beta, float* y, blasint* incy){ FC_GLOBAL(sspmv,SSPMV)((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(sspr,SSPR)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sspr.f77_blas_function;
	fn_hook = __flexiblas_hooks->sspr.f77_hook_function[0];
	hook_pos_sspr = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sspr_(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* ap) __attribute__((alias(MTS(FC_GLOBAL(sspr,SSPR)))));
#else
#ifndef __APPLE__
void sspr(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* ap) __attribute__((alias(MTS(FC_GLOBAL(sspr,SSPR)))));
#else
void sspr(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* ap){ FC_GLOBAL(sspr,SSPR)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap); }
#endif
#endif



void FC_GLOBAL(sspr2,SSPR2)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sspr2.f77_blas_function;
	fn_hook = __flexiblas_hooks->sspr2.f77_hook_function[0];
	hook_pos_sspr2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sspr2_(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* ap) __attribute__((alias(MTS(FC_GLOBAL(sspr2,SSPR2)))));
#else
#ifndef __APPLE__
void sspr2(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* ap) __attribute__((alias(MTS(FC_GLOBAL(sspr2,SSPR2)))));
#else
void sspr2(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* ap){ FC_GLOBAL(sspr2,SSPR2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap); }
#endif
#endif



void FC_GLOBAL(sswap,SSWAP)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy)
{
	void (*fn) (void* n, void* sx, void* incx, void* sy, void* incy);
	void (*fn_hook) (void* n, void* sx, void* incx, void* sy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sswap.f77_blas_function;
	fn_hook = __flexiblas_hooks->sswap.f77_hook_function[0];
	hook_pos_sswap = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	} else {
		fn((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sswap_(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sswap,SSWAP)))));
#else
#ifndef __APPLE__
void sswap(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(sswap,SSWAP)))));
#else
void sswap(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy){ FC_GLOBAL(sswap,SSWAP)((void*) n, (void*) sx, (void*) incx, (void*) sy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(ssymm,SSYMM)(char* side, char* uplo, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc)
{
	void (*fn) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssymm.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssymm.f77_hook_function[0];
	hook_pos_ssymm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssymm_(char* side, char* uplo, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(ssymm,SSYMM)))));
#else
#ifndef __APPLE__
void ssymm(char* side, char* uplo, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(ssymm,SSYMM)))));
#else
void ssymm(char* side, char* uplo, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc){ FC_GLOBAL(ssymm,SSYMM)((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(ssymv,SSYMV)(char* uplo, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssymv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssymv.f77_hook_function[0];
	hook_pos_ssymv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssymv_(char* uplo, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ssymv,SSYMV)))));
#else
#ifndef __APPLE__
void ssymv(char* uplo, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(ssymv,SSYMV)))));
#else
void ssymv(char* uplo, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy){ FC_GLOBAL(ssymv,SSYMV)((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(ssyr,SSYR)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssyr.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssyr.f77_hook_function[0];
	hook_pos_ssyr = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssyr_(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(ssyr,SSYR)))));
#else
#ifndef __APPLE__
void ssyr(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(ssyr,SSYR)))));
#else
void ssyr(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* a, blasint* lda){ FC_GLOBAL(ssyr,SSYR)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(ssyr2,SSYR2)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssyr2.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssyr2.f77_hook_function[0];
	hook_pos_ssyr2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssyr2_(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(ssyr2,SSYR2)))));
#else
#ifndef __APPLE__
void ssyr2(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(ssyr2,SSYR2)))));
#else
void ssyr2(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda){ FC_GLOBAL(ssyr2,SSYR2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(ssyr2k,SSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssyr2k.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssyr2k.f77_hook_function[0];
	hook_pos_ssyr2k = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssyr2k_(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(ssyr2k,SSYR2K)))));
#else
#ifndef __APPLE__
void ssyr2k(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(ssyr2k,SSYR2K)))));
#else
void ssyr2k(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc){ FC_GLOBAL(ssyr2k,SSYR2K)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(ssyrk,SSYRK)(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* beta, float* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ssyrk.f77_blas_function;
	fn_hook = __flexiblas_hooks->ssyrk.f77_hook_function[0];
	hook_pos_ssyrk = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ssyrk_(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(ssyrk,SSYRK)))));
#else
#ifndef __APPLE__
void ssyrk(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* beta, float* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(ssyrk,SSYRK)))));
#else
void ssyrk(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* beta, float* c, blasint* ldc){ FC_GLOBAL(ssyrk,SSYRK)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(stbmv,STBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.stbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->stbmv.f77_hook_function[0];
	hook_pos_stbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void stbmv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stbmv,STBMV)))));
#else
#ifndef __APPLE__
void stbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stbmv,STBMV)))));
#else
void stbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx){ FC_GLOBAL(stbmv,STBMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(stbsv,STBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.stbsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->stbsv.f77_hook_function[0];
	hook_pos_stbsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void stbsv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stbsv,STBSV)))));
#else
#ifndef __APPLE__
void stbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stbsv,STBSV)))));
#else
void stbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx){ FC_GLOBAL(stbsv,STBSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(stpmv,STPMV)(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.stpmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->stpmv.f77_hook_function[0];
	hook_pos_stpmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void stpmv_(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stpmv,STPMV)))));
#else
#ifndef __APPLE__
void stpmv(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stpmv,STPMV)))));
#else
void stpmv(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx){ FC_GLOBAL(stpmv,STPMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(stpsv,STPSV)(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.stpsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->stpsv.f77_hook_function[0];
	hook_pos_stpsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void stpsv_(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stpsv,STPSV)))));
#else
#ifndef __APPLE__
void stpsv(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(stpsv,STPSV)))));
#else
void stpsv(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx){ FC_GLOBAL(stpsv,STPSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(strmm,STRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.strmm.f77_blas_function;
	fn_hook = __flexiblas_hooks->strmm.f77_hook_function[0];
	hook_pos_strmm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void strmm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(strmm,STRMM)))));
#else
#ifndef __APPLE__
void strmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(strmm,STRMM)))));
#else
void strmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb){ FC_GLOBAL(strmm,STRMM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(strmv,STRMV)(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.strmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->strmv.f77_hook_function[0];
	hook_pos_strmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void strmv_(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(strmv,STRMV)))));
#else
#ifndef __APPLE__
void strmv(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(strmv,STRMV)))));
#else
void strmv(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx){ FC_GLOBAL(strmv,STRMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(strsm,STRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.strsm.f77_blas_function;
	fn_hook = __flexiblas_hooks->strsm.f77_hook_function[0];
	hook_pos_strsm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void strsm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(strsm,STRSM)))));
#else
#ifndef __APPLE__
void strsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(strsm,STRSM)))));
#else
void strsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb){ FC_GLOBAL(strsm,STRSM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(strsv,STRSV)(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.strsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->strsv.f77_hook_function[0];
	hook_pos_strsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void strsv_(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(strsv,STRSV)))));
#else
#ifndef __APPLE__
void strsv(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(strsv,STRSV)))));
#else
void strsv(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx){ FC_GLOBAL(strsv,STRSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(zaxpy,ZAXPY)(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zy, blasint* incy)
{
	void (*fn) (void* n, void* za, void* zx, void* incx, void* zy, void* incy);
	void (*fn_hook) (void* n, void* za, void* zx, void* incx, void* zy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zaxpy.f77_blas_function;
	fn_hook = __flexiblas_hooks->zaxpy.f77_hook_function[0];
	hook_pos_zaxpy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) za, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
	} else {
		fn((void*) n, (void*) za, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zaxpy_(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zaxpy,ZAXPY)))));
#else
#ifndef __APPLE__
void zaxpy(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zaxpy,ZAXPY)))));
#else
void zaxpy(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zy, blasint* incy){ FC_GLOBAL(zaxpy,ZAXPY)((void*) n, (void*) za, (void*) zx, (void*) incx, (void*) zy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zcopy,ZCOPY)(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy)
{
	void (*fn) (void* n, void* zx, void* incx, void* zy, void* incy);
	void (*fn_hook) (void* n, void* zx, void* incx, void* zy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->zcopy.f77_hook_function[0];
	hook_pos_zcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
	} else {
		fn((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zcopy_(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zcopy,ZCOPY)))));
#else
#ifndef __APPLE__
void zcopy(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zcopy,ZCOPY)))));
#else
void zcopy(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy){ FC_GLOBAL(zcopy,ZCOPY)((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zdotc,ZDOTC)( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy)
{
	double complex (*fn) (void* n, void* zx, void* incx, void* zy, void* incy);
	double complex (*fn_hook) (void* n, void* zx, void* incx, void* zy, void* incy);
	void (*fn_intel) (double complex *ret, void* n, void* zx, void* incx, void* zy, void* incy);
	void (*fn_intel_hook) (double complex *ret, void* n, void* zx, void* incx, void* zy, void* incy);
	double complex ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zdotc.f77_blas_function;
	fn_hook = __flexiblas_hooks->zdotc.f77_hook_function[0];
	hook_pos_zdotc = 0;
	fn_intel = (void *) fn;
	fn_intel_hook = (void *) fn_hook;
	if ( fn_hook != NULL) {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn_hook((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			} else {
				fn_intel_hook( &ret, (void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			}
	} else {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			} else {
				fn_intel( &ret, (void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			}
	}
	*returnvalue = ret; 
		return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zdotc_( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zdotc,ZDOTC)))));
#else
#ifndef __APPLE__
void zdotc( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zdotc,ZDOTC)))));
#else
void zdotc( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy){ FC_GLOBAL(zdotc,ZDOTC)( (void*) returnvalue, (void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zdotu,ZDOTU)( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy)
{
	double complex (*fn) (void* n, void* zx, void* incx, void* zy, void* incy);
	double complex (*fn_hook) (void* n, void* zx, void* incx, void* zy, void* incy);
	void (*fn_intel) (double complex *ret, void* n, void* zx, void* incx, void* zy, void* incy);
	void (*fn_intel_hook) (double complex *ret, void* n, void* zx, void* incx, void* zy, void* incy);
	double complex ret;
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zdotu.f77_blas_function;
	fn_hook = __flexiblas_hooks->zdotu.f77_hook_function[0];
	hook_pos_zdotu = 0;
	fn_intel = (void *) fn;
	fn_intel_hook = (void *) fn_hook;
	if ( fn_hook != NULL) {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn_hook((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			} else {
				fn_intel_hook( &ret, (void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			}
	} else {
		if(current_backend->info.intel_interface == 0 ) {
				ret = fn((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			} else {
				fn_intel( &ret, (void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
			}
	}
	*returnvalue = ret; 
		return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zdotu_( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zdotu,ZDOTU)))));
#else
#ifndef __APPLE__
void zdotu( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zdotu,ZDOTU)))));
#else
void zdotu( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy){ FC_GLOBAL(zdotu,ZDOTU)( (void*) returnvalue, (void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zdrot,ZDROT)(blasint* n, double complex* cx, blasint* incx, double complex* cy, blasint* incy, double* c, double* s)
{
	void (*fn) (void* n, void* cx, void* incx, void* cy, void* incy, void* c, void* s);
	void (*fn_hook) (void* n, void* cx, void* incx, void* cy, void* incy, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zdrot.f77_blas_function;
	fn_hook = __flexiblas_hooks->zdrot.f77_hook_function[0];
	hook_pos_zdrot = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy, (void*) c, (void*) s);
	} else {
		fn((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zdrot_(blasint* n, double complex* cx, blasint* incx, double complex* cy, blasint* incy, double* c, double* s) __attribute__((alias(MTS(FC_GLOBAL(zdrot,ZDROT)))));
#else
#ifndef __APPLE__
void zdrot(blasint* n, double complex* cx, blasint* incx, double complex* cy, blasint* incy, double* c, double* s) __attribute__((alias(MTS(FC_GLOBAL(zdrot,ZDROT)))));
#else
void zdrot(blasint* n, double complex* cx, blasint* incx, double complex* cy, blasint* incy, double* c, double* s){ FC_GLOBAL(zdrot,ZDROT)((void*) n, (void*) cx, (void*) incx, (void*) cy, (void*) incy, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(zdscal,ZDSCAL)(blasint* n, double* da, double complex* zx, blasint* incx)
{
	void (*fn) (void* n, void* da, void* zx, void* incx);
	void (*fn_hook) (void* n, void* da, void* zx, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zdscal.f77_blas_function;
	fn_hook = __flexiblas_hooks->zdscal.f77_hook_function[0];
	hook_pos_zdscal = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) da, (void*) zx, (void*) incx);
	} else {
		fn((void*) n, (void*) da, (void*) zx, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zdscal_(blasint* n, double* da, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(zdscal,ZDSCAL)))));
#else
#ifndef __APPLE__
void zdscal(blasint* n, double* da, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(zdscal,ZDSCAL)))));
#else
void zdscal(blasint* n, double* da, double complex* zx, blasint* incx){ FC_GLOBAL(zdscal,ZDSCAL)((void*) n, (void*) da, (void*) zx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(zgbmv,ZGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* kl, void* ku, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zgbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->zgbmv.f77_hook_function[0];
	hook_pos_zgbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zgbmv_(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zgbmv,ZGBMV)))));
#else
#ifndef __APPLE__
void zgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zgbmv,ZGBMV)))));
#else
void zgbmv(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy){ FC_GLOBAL(zgbmv,ZGBMV)((void*) trans, (void*) m, (void*) n, (void*) kl, (void*) ku, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zgemm,ZGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* transa, void* transb, void* m, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zgemm.f77_blas_function;
	fn_hook = __flexiblas_hooks->zgemm.f77_hook_function[0];
	hook_pos_zgemm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zgemm_(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zgemm,ZGEMM)))));
#else
#ifndef __APPLE__
void zgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zgemm,ZGEMM)))));
#else
void zgemm(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zgemm,ZGEMM)((void*) transa, (void*) transb, (void*) m, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(zgemv,ZGEMV)(char* trans, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy)
{
	void (*fn) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* trans, void* m, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zgemv.f77_blas_function;
	fn_hook = __flexiblas_hooks->zgemv.f77_hook_function[0];
	hook_pos_zgemv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zgemv_(char* trans, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zgemv,ZGEMV)))));
#else
#ifndef __APPLE__
void zgemv(char* trans, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zgemv,ZGEMV)))));
#else
void zgemv(char* trans, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy){ FC_GLOBAL(zgemv,ZGEMV)((void*) trans, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zgerc,ZGERC)(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda)
{
	void (*fn) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zgerc.f77_blas_function;
	fn_hook = __flexiblas_hooks->zgerc.f77_hook_function[0];
	hook_pos_zgerc = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zgerc_(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zgerc,ZGERC)))));
#else
#ifndef __APPLE__
void zgerc(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zgerc,ZGERC)))));
#else
void zgerc(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda){ FC_GLOBAL(zgerc,ZGERC)((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(zgeru,ZGERU)(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda)
{
	void (*fn) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* m, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zgeru.f77_blas_function;
	fn_hook = __flexiblas_hooks->zgeru.f77_hook_function[0];
	hook_pos_zgeru = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zgeru_(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zgeru,ZGERU)))));
#else
#ifndef __APPLE__
void zgeru(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zgeru,ZGERU)))));
#else
void zgeru(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda){ FC_GLOBAL(zgeru,ZGERU)((void*) m, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(zhbmv,ZHBMV)(char* uplo, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* k, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zhbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->zhbmv.f77_hook_function[0];
	hook_pos_zhbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zhbmv_(char* uplo, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zhbmv,ZHBMV)))));
#else
#ifndef __APPLE__
void zhbmv(char* uplo, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zhbmv,ZHBMV)))));
#else
void zhbmv(char* uplo, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy){ FC_GLOBAL(zhbmv,ZHBMV)((void*) uplo, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zhemm,ZHEMM)(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zhemm.f77_blas_function;
	fn_hook = __flexiblas_hooks->zhemm.f77_hook_function[0];
	hook_pos_zhemm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zhemm_(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zhemm,ZHEMM)))));
#else
#ifndef __APPLE__
void zhemm(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zhemm,ZHEMM)))));
#else
void zhemm(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zhemm,ZHEMM)((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(zhemv,ZHEMV)(char* uplo, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* a, void* lda, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zhemv.f77_blas_function;
	fn_hook = __flexiblas_hooks->zhemv.f77_hook_function[0];
	hook_pos_zhemv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zhemv_(char* uplo, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zhemv,ZHEMV)))));
#else
#ifndef __APPLE__
void zhemv(char* uplo, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zhemv,ZHEMV)))));
#else
void zhemv(char* uplo, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy){ FC_GLOBAL(zhemv,ZHEMV)((void*) uplo, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zher,ZHER)(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zher.f77_blas_function;
	fn_hook = __flexiblas_hooks->zher.f77_hook_function[0];
	hook_pos_zher = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zher_(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zher,ZHER)))));
#else
#ifndef __APPLE__
void zher(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zher,ZHER)))));
#else
void zher(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* a, blasint* lda){ FC_GLOBAL(zher,ZHER)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(zher2,ZHER2)(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* a, void* lda);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zher2.f77_blas_function;
	fn_hook = __flexiblas_hooks->zher2.f77_hook_function[0];
	hook_pos_zher2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zher2_(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zher2,ZHER2)))));
#else
#ifndef __APPLE__
void zher2(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda) __attribute__((alias(MTS(FC_GLOBAL(zher2,ZHER2)))));
#else
void zher2(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda){ FC_GLOBAL(zher2,ZHER2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) a, (void*) lda); }
#endif
#endif



void FC_GLOBAL(zher2k,ZHER2K)(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zher2k.f77_blas_function;
	fn_hook = __flexiblas_hooks->zher2k.f77_hook_function[0];
	hook_pos_zher2k = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zher2k_(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zher2k,ZHER2K)))));
#else
#ifndef __APPLE__
void zher2k(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zher2k,ZHER2K)))));
#else
void zher2k(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zher2k,ZHER2K)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(zherk,ZHERK)(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double complex* a, blasint* lda, double* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zherk.f77_blas_function;
	fn_hook = __flexiblas_hooks->zherk.f77_hook_function[0];
	hook_pos_zherk = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zherk_(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double complex* a, blasint* lda, double* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zherk,ZHERK)))));
#else
#ifndef __APPLE__
void zherk(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double complex* a, blasint* lda, double* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zherk,ZHERK)))));
#else
void zherk(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double complex* a, blasint* lda, double* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zherk,ZHERK)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(zhpmv,ZHPMV)(char* uplo, blasint* n, double complex* alpha, double complex* ap, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* ap, void* x, void* incx, void* beta, void* y, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zhpmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->zhpmv.f77_hook_function[0];
	hook_pos_zhpmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zhpmv_(char* uplo, blasint* n, double complex* alpha, double complex* ap, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zhpmv,ZHPMV)))));
#else
#ifndef __APPLE__
void zhpmv(char* uplo, blasint* n, double complex* alpha, double complex* ap, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zhpmv,ZHPMV)))));
#else
void zhpmv(char* uplo, blasint* n, double complex* alpha, double complex* ap, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy){ FC_GLOBAL(zhpmv,ZHPMV)((void*) uplo, (void*) n, (void*) alpha, (void*) ap, (void*) x, (void*) incx, (void*) beta, (void*) y, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zhpr,ZHPR)(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zhpr.f77_blas_function;
	fn_hook = __flexiblas_hooks->zhpr.f77_hook_function[0];
	hook_pos_zhpr = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zhpr_(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* ap) __attribute__((alias(MTS(FC_GLOBAL(zhpr,ZHPR)))));
#else
#ifndef __APPLE__
void zhpr(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* ap) __attribute__((alias(MTS(FC_GLOBAL(zhpr,ZHPR)))));
#else
void zhpr(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* ap){ FC_GLOBAL(zhpr,ZHPR)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) ap); }
#endif
#endif



void FC_GLOBAL(zhpr2,ZHPR2)(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* ap)
{
	void (*fn) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	void (*fn_hook) (void* uplo, void* n, void* alpha, void* x, void* incx, void* y, void* incy, void* ap);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zhpr2.f77_blas_function;
	fn_hook = __flexiblas_hooks->zhpr2.f77_hook_function[0];
	hook_pos_zhpr2 = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	} else {
		fn((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zhpr2_(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* ap) __attribute__((alias(MTS(FC_GLOBAL(zhpr2,ZHPR2)))));
#else
#ifndef __APPLE__
void zhpr2(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* ap) __attribute__((alias(MTS(FC_GLOBAL(zhpr2,ZHPR2)))));
#else
void zhpr2(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* ap){ FC_GLOBAL(zhpr2,ZHPR2)((void*) uplo, (void*) n, (void*) alpha, (void*) x, (void*) incx, (void*) y, (void*) incy, (void*) ap); }
#endif
#endif



void FC_GLOBAL(zrotg,ZROTG)(double complex* ca, double complex* cb, double* c, double complex* s)
{
	void (*fn) (void* ca, void* cb, void* c, void* s);
	void (*fn_hook) (void* ca, void* cb, void* c, void* s);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zrotg.f77_blas_function;
	fn_hook = __flexiblas_hooks->zrotg.f77_hook_function[0];
	hook_pos_zrotg = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) ca, (void*) cb, (void*) c, (void*) s);
	} else {
		fn((void*) ca, (void*) cb, (void*) c, (void*) s);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zrotg_(double complex* ca, double complex* cb, double* c, double complex* s) __attribute__((alias(MTS(FC_GLOBAL(zrotg,ZROTG)))));
#else
#ifndef __APPLE__
void zrotg(double complex* ca, double complex* cb, double* c, double complex* s) __attribute__((alias(MTS(FC_GLOBAL(zrotg,ZROTG)))));
#else
void zrotg(double complex* ca, double complex* cb, double* c, double complex* s){ FC_GLOBAL(zrotg,ZROTG)((void*) ca, (void*) cb, (void*) c, (void*) s); }
#endif
#endif



void FC_GLOBAL(zscal,ZSCAL)(blasint* n, double complex* za, double complex* zx, blasint* incx)
{
	void (*fn) (void* n, void* za, void* zx, void* incx);
	void (*fn_hook) (void* n, void* za, void* zx, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zscal.f77_blas_function;
	fn_hook = __flexiblas_hooks->zscal.f77_hook_function[0];
	hook_pos_zscal = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) za, (void*) zx, (void*) incx);
	} else {
		fn((void*) n, (void*) za, (void*) zx, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zscal_(blasint* n, double complex* za, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(zscal,ZSCAL)))));
#else
#ifndef __APPLE__
void zscal(blasint* n, double complex* za, double complex* zx, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(zscal,ZSCAL)))));
#else
void zscal(blasint* n, double complex* za, double complex* zx, blasint* incx){ FC_GLOBAL(zscal,ZSCAL)((void*) n, (void*) za, (void*) zx, (void*) incx); }
#endif
#endif



void FC_GLOBAL(zswap,ZSWAP)(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy)
{
	void (*fn) (void* n, void* zx, void* incx, void* zy, void* incy);
	void (*fn_hook) (void* n, void* zx, void* incx, void* zy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zswap.f77_blas_function;
	fn_hook = __flexiblas_hooks->zswap.f77_hook_function[0];
	hook_pos_zswap = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
	} else {
		fn((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zswap_(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zswap,ZSWAP)))));
#else
#ifndef __APPLE__
void zswap(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zswap,ZSWAP)))));
#else
void zswap(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy){ FC_GLOBAL(zswap,ZSWAP)((void*) n, (void*) zx, (void*) incx, (void*) zy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zsymm,ZSYMM)(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* side, void* uplo, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zsymm.f77_blas_function;
	fn_hook = __flexiblas_hooks->zsymm.f77_hook_function[0];
	hook_pos_zsymm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zsymm_(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zsymm,ZSYMM)))));
#else
#ifndef __APPLE__
void zsymm(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zsymm,ZSYMM)))));
#else
void zsymm(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zsymm,ZSYMM)((void*) side, (void*) uplo, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(zsyr2k,ZSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* b, void* ldb, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zsyr2k.f77_blas_function;
	fn_hook = __flexiblas_hooks->zsyr2k.f77_hook_function[0];
	hook_pos_zsyr2k = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zsyr2k_(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zsyr2k,ZSYR2K)))));
#else
#ifndef __APPLE__
void zsyr2k(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zsyr2k,ZSYR2K)))));
#else
void zsyr2k(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zsyr2k,ZSYR2K)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(zsyrk,ZSYRK)(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* c, blasint* ldc)
{
	void (*fn) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	void (*fn_hook) (void* uplo, void* trans, void* n, void* k, void* alpha, void* a, void* lda, void* beta, void* c, void* ldc);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zsyrk.f77_blas_function;
	fn_hook = __flexiblas_hooks->zsyrk.f77_hook_function[0];
	hook_pos_zsyrk = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	} else {
		fn((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zsyrk_(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zsyrk,ZSYRK)))));
#else
#ifndef __APPLE__
void zsyrk(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* c, blasint* ldc) __attribute__((alias(MTS(FC_GLOBAL(zsyrk,ZSYRK)))));
#else
void zsyrk(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* c, blasint* ldc){ FC_GLOBAL(zsyrk,ZSYRK)((void*) uplo, (void*) trans, (void*) n, (void*) k, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) c, (void*) ldc); }
#endif
#endif



void FC_GLOBAL(ztbmv,ZTBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztbmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztbmv.f77_hook_function[0];
	hook_pos_ztbmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztbmv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztbmv,ZTBMV)))));
#else
#ifndef __APPLE__
void ztbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztbmv,ZTBMV)))));
#else
void ztbmv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx){ FC_GLOBAL(ztbmv,ZTBMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ztbsv,ZTBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* k, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztbsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztbsv.f77_hook_function[0];
	hook_pos_ztbsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztbsv_(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztbsv,ZTBSV)))));
#else
#ifndef __APPLE__
void ztbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztbsv,ZTBSV)))));
#else
void ztbsv(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx){ FC_GLOBAL(ztbsv,ZTBSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) k, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ztpmv,ZTPMV)(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztpmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztpmv.f77_hook_function[0];
	hook_pos_ztpmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztpmv_(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztpmv,ZTPMV)))));
#else
#ifndef __APPLE__
void ztpmv(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztpmv,ZTPMV)))));
#else
void ztpmv(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx){ FC_GLOBAL(ztpmv,ZTPMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ztpsv,ZTPSV)(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* ap, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztpsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztpsv.f77_hook_function[0];
	hook_pos_ztpsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztpsv_(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztpsv,ZTPSV)))));
#else
#ifndef __APPLE__
void ztpsv(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztpsv,ZTPSV)))));
#else
void ztpsv(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx){ FC_GLOBAL(ztpsv,ZTPSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) ap, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ztrmm,ZTRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztrmm.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztrmm.f77_hook_function[0];
	hook_pos_ztrmm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztrmm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ztrmm,ZTRMM)))));
#else
#ifndef __APPLE__
void ztrmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ztrmm,ZTRMM)))));
#else
void ztrmm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb){ FC_GLOBAL(ztrmm,ZTRMM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(ztrmv,ZTRMV)(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztrmv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztrmv.f77_hook_function[0];
	hook_pos_ztrmv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztrmv_(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztrmv,ZTRMV)))));
#else
#ifndef __APPLE__
void ztrmv(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztrmv,ZTRMV)))));
#else
void ztrmv(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx){ FC_GLOBAL(ztrmv,ZTRMV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(ztrsm,ZTRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb)
{
	void (*fn) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* side, void* uplo, void* transa, void* diag, void* m, void* n, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztrsm.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztrsm.f77_hook_function[0];
	hook_pos_ztrsm = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztrsm_(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ztrsm,ZTRSM)))));
#else
#ifndef __APPLE__
void ztrsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(ztrsm,ZTRSM)))));
#else
void ztrsm(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb){ FC_GLOBAL(ztrsm,ZTRSM)((void*) side, (void*) uplo, (void*) transa, (void*) diag, (void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(ztrsv,ZTRSV)(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx)
{
	void (*fn) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	void (*fn_hook) (void* uplo, void* trans, void* diag, void* n, void* a, void* lda, void* x, void* incx);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.ztrsv.f77_blas_function;
	fn_hook = __flexiblas_hooks->ztrsv.f77_hook_function[0];
	hook_pos_ztrsv = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	} else {
		fn((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void ztrsv_(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztrsv,ZTRSV)))));
#else
#ifndef __APPLE__
void ztrsv(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx) __attribute__((alias(MTS(FC_GLOBAL(ztrsv,ZTRSV)))));
#else
void ztrsv(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx){ FC_GLOBAL(ztrsv,ZTRSV)((void*) uplo, (void*) trans, (void*) diag, (void*) n, (void*) a, (void*) lda, (void*) x, (void*) incx); }
#endif
#endif



void FC_GLOBAL(caxpby,CAXPBY)(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cb, float complex* cy, blasint* incy)
{
	void (*fn) (void* n, void* ca, void* cx, void* incx, void* cb, void* cy, void* incy);
	void (*fn_hook) (void* n, void* ca, void* cx, void* incx, void* cb, void* cy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.caxpby.f77_blas_function;
	fn_hook = __flexiblas_hooks->caxpby.f77_hook_function[0];
	hook_pos_caxpby = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) ca, (void*) cx, (void*) incx, (void*) cb, (void*) cy, (void*) incy);
	} else {
		fn((void*) n, (void*) ca, (void*) cx, (void*) incx, (void*) cb, (void*) cy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void caxpby_(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cb, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(caxpby,CAXPBY)))));
#else
#ifndef __APPLE__
void caxpby(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cb, float complex* cy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(caxpby,CAXPBY)))));
#else
void caxpby(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cb, float complex* cy, blasint* incy){ FC_GLOBAL(caxpby,CAXPBY)((void*) n, (void*) ca, (void*) cx, (void*) incx, (void*) cb, (void*) cy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(daxpby,DAXPBY)(blasint* n, double* da, double* dx, blasint* incx, double* db, double* dy, blasint* incy)
{
	void (*fn) (void* n, void* da, void* dx, void* incx, void* db, void* dy, void* incy);
	void (*fn_hook) (void* n, void* da, void* dx, void* incx, void* db, void* dy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.daxpby.f77_blas_function;
	fn_hook = __flexiblas_hooks->daxpby.f77_hook_function[0];
	hook_pos_daxpby = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) da, (void*) dx, (void*) incx, (void*) db, (void*) dy, (void*) incy);
	} else {
		fn((void*) n, (void*) da, (void*) dx, (void*) incx, (void*) db, (void*) dy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void daxpby_(blasint* n, double* da, double* dx, blasint* incx, double* db, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(daxpby,DAXPBY)))));
#else
#ifndef __APPLE__
void daxpby(blasint* n, double* da, double* dx, blasint* incx, double* db, double* dy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(daxpby,DAXPBY)))));
#else
void daxpby(blasint* n, double* da, double* dx, blasint* incx, double* db, double* dy, blasint* incy){ FC_GLOBAL(daxpby,DAXPBY)((void*) n, (void*) da, (void*) dx, (void*) incx, (void*) db, (void*) dy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(zaxpby,ZAXPBY)(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zb, double complex* zy, blasint* incy)
{
	void (*fn) (void* n, void* za, void* zx, void* incx, void* zb, void* zy, void* incy);
	void (*fn_hook) (void* n, void* za, void* zx, void* incx, void* zb, void* zy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zaxpby.f77_blas_function;
	fn_hook = __flexiblas_hooks->zaxpby.f77_hook_function[0];
	hook_pos_zaxpby = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) za, (void*) zx, (void*) incx, (void*) zb, (void*) zy, (void*) incy);
	} else {
		fn((void*) n, (void*) za, (void*) zx, (void*) incx, (void*) zb, (void*) zy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zaxpby_(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zb, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zaxpby,ZAXPBY)))));
#else
#ifndef __APPLE__
void zaxpby(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zb, double complex* zy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(zaxpby,ZAXPBY)))));
#else
void zaxpby(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zb, double complex* zy, blasint* incy){ FC_GLOBAL(zaxpby,ZAXPBY)((void*) n, (void*) za, (void*) zx, (void*) incx, (void*) zb, (void*) zy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(saxpby,SAXPBY)(blasint* n, float* sa, float* sx, blasint* incx, float* sb, float* sy, blasint* incy)
{
	void (*fn) (void* n, void* sa, void* sx, void* incx, void* sb, void* sy, void* incy);
	void (*fn_hook) (void* n, void* sa, void* sx, void* incx, void* sb, void* sy, void* incy);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.saxpby.f77_blas_function;
	fn_hook = __flexiblas_hooks->saxpby.f77_hook_function[0];
	hook_pos_saxpby = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) n, (void*) sa, (void*) sx, (void*) incx, (void*) sb, (void*) sy, (void*) incy);
	} else {
		fn((void*) n, (void*) sa, (void*) sx, (void*) incx, (void*) sb, (void*) sy, (void*) incy);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void saxpby_(blasint* n, float* sa, float* sx, blasint* incx, float* sb, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(saxpby,SAXPBY)))));
#else
#ifndef __APPLE__
void saxpby(blasint* n, float* sa, float* sx, blasint* incx, float* sb, float* sy, blasint* incy) __attribute__((alias(MTS(FC_GLOBAL(saxpby,SAXPBY)))));
#else
void saxpby(blasint* n, float* sa, float* sx, blasint* incx, float* sb, float* sy, blasint* incy){ FC_GLOBAL(saxpby,SAXPBY)((void*) n, (void*) sa, (void*) sx, (void*) incx, (void*) sb, (void*) sy, (void*) incy); }
#endif
#endif



void FC_GLOBAL(comatcopy,COMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.comatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->comatcopy.f77_hook_function[0];
	hook_pos_comatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void comatcopy_(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(comatcopy,COMATCOPY)))));
#else
#ifndef __APPLE__
void comatcopy(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(comatcopy,COMATCOPY)))));
#else
void comatcopy(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb){ FC_GLOBAL(comatcopy,COMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(zomatcopy,ZOMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zomatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->zomatcopy.f77_hook_function[0];
	hook_pos_zomatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zomatcopy_(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(zomatcopy,ZOMATCOPY)))));
#else
#ifndef __APPLE__
void zomatcopy(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(zomatcopy,ZOMATCOPY)))));
#else
void zomatcopy(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb){ FC_GLOBAL(zomatcopy,ZOMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(domatcopy,DOMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, double* b, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.domatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->domatcopy.f77_hook_function[0];
	hook_pos_domatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void domatcopy_(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(domatcopy,DOMATCOPY)))));
#else
#ifndef __APPLE__
void domatcopy(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(domatcopy,DOMATCOPY)))));
#else
void domatcopy(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, double* b, blasint* ldb){ FC_GLOBAL(domatcopy,DOMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(somatcopy,SOMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, float* b, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.somatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->somatcopy.f77_hook_function[0];
	hook_pos_somatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void somatcopy_(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(somatcopy,SOMATCOPY)))));
#else
#ifndef __APPLE__
void somatcopy(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(somatcopy,SOMATCOPY)))));
#else
void somatcopy(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, float* b, blasint* ldb){ FC_GLOBAL(somatcopy,SOMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(cimatcopy,CIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cimatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->cimatcopy.f77_hook_function[0];
	hook_pos_cimatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cimatcopy_(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(cimatcopy,CIMATCOPY)))));
#else
#ifndef __APPLE__
void cimatcopy(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(cimatcopy,CIMATCOPY)))));
#else
void cimatcopy(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, blasint* ldb){ FC_GLOBAL(cimatcopy,CIMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(zimatcopy,ZIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zimatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->zimatcopy.f77_hook_function[0];
	hook_pos_zimatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zimatcopy_(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(zimatcopy,ZIMATCOPY)))));
#else
#ifndef __APPLE__
void zimatcopy(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(zimatcopy,ZIMATCOPY)))));
#else
void zimatcopy(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, blasint* ldb){ FC_GLOBAL(zimatcopy,ZIMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(dimatcopy,DIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dimatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->dimatcopy.f77_hook_function[0];
	hook_pos_dimatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dimatcopy_(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dimatcopy,DIMATCOPY)))));
#else
#ifndef __APPLE__
void dimatcopy(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dimatcopy,DIMATCOPY)))));
#else
void dimatcopy(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, blasint* ldb){ FC_GLOBAL(dimatcopy,DIMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(simatcopy,SIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, blasint* ldb)
{
	void (*fn) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	void (*fn_hook) (void* order, void* trans, void* rows, void* cols, void* alpha, void* a, void* lda, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.simatcopy.f77_blas_function;
	fn_hook = __flexiblas_hooks->simatcopy.f77_hook_function[0];
	hook_pos_simatcopy = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	} else {
		fn((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void simatcopy_(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(simatcopy,SIMATCOPY)))));
#else
#ifndef __APPLE__
void simatcopy(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(simatcopy,SIMATCOPY)))));
#else
void simatcopy(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, blasint* ldb){ FC_GLOBAL(simatcopy,SIMATCOPY)((void*) order, (void*) trans, (void*) rows, (void*) cols, (void*) alpha, (void*) a, (void*) lda, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(sgeadd,SGEADD)(blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* beta, float* b, blasint* ldb)
{
	void (*fn) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	void (*fn_hook) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.sgeadd.f77_blas_function;
	fn_hook = __flexiblas_hooks->sgeadd.f77_hook_function[0];
	hook_pos_sgeadd = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void sgeadd_(blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* beta, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(sgeadd,SGEADD)))));
#else
#ifndef __APPLE__
void sgeadd(blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* beta, float* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(sgeadd,SGEADD)))));
#else
void sgeadd(blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* beta, float* b, blasint* ldb){ FC_GLOBAL(sgeadd,SGEADD)((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(dgeadd,DGEADD)(blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* beta, double* b, blasint* ldb)
{
	void (*fn) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	void (*fn_hook) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.dgeadd.f77_blas_function;
	fn_hook = __flexiblas_hooks->dgeadd.f77_hook_function[0];
	hook_pos_dgeadd = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void dgeadd_(blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* beta, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dgeadd,DGEADD)))));
#else
#ifndef __APPLE__
void dgeadd(blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* beta, double* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(dgeadd,DGEADD)))));
#else
void dgeadd(blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* beta, double* b, blasint* ldb){ FC_GLOBAL(dgeadd,DGEADD)((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(cgeadd,CGEADD)(blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* b, blasint* ldb)
{
	void (*fn) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	void (*fn_hook) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.cgeadd.f77_blas_function;
	fn_hook = __flexiblas_hooks->cgeadd.f77_hook_function[0];
	hook_pos_cgeadd = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void cgeadd_(blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(cgeadd,CGEADD)))));
#else
#ifndef __APPLE__
void cgeadd(blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(cgeadd,CGEADD)))));
#else
void cgeadd(blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* b, blasint* ldb){ FC_GLOBAL(cgeadd,CGEADD)((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb); }
#endif
#endif



void FC_GLOBAL(zgeadd,ZGEADD)(blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* b, blasint* ldb)
{
	void (*fn) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	void (*fn_hook) (void* m, void* n, void* alpha, void* a, void* lda, void* beta, void* b, void* ldb);
	if ( current_backend->post_init != 0 ) {
		__flexiblas_backend_init(current_backend);
		current_backend->post_init = 0;
	}
	fn = current_backend->blas.zgeadd.f77_blas_function;
	fn_hook = __flexiblas_hooks->zgeadd.f77_hook_function[0];
	hook_pos_zgeadd = 0;
	if ( fn_hook != NULL) {
		fn_hook((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	} else {
		fn((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb);
	}
	return;
}
#ifdef FLEXIBLAS_ABI_IBM
void zgeadd_(blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(zgeadd,ZGEADD)))));
#else
#ifndef __APPLE__
void zgeadd(blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* b, blasint* ldb) __attribute__((alias(MTS(FC_GLOBAL(zgeadd,ZGEADD)))));
#else
void zgeadd(blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* b, blasint* ldb){ FC_GLOBAL(zgeadd,ZGEADD)((void*) m, (void*) n, (void*) alpha, (void*) a, (void*) lda, (void*) beta, (void*) b, (void*) ldb); }
#endif
#endif




