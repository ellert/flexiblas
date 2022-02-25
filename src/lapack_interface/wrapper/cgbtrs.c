/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Linking FlexiBLAS statically or dynamically with other modules is making a combined
 * work based on FlexiBLAS. Thus, the terms and conditions of the GNU General
 * Public License cover the whole combination.
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
 * Copyright (C) Martin Koehler, 2013-2022
 */
        
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <complex.h>

#include "flexiblas_fortran_mangle.h"

#include "flexiblas.h"


#if __GNUC__ > 7
typedef size_t fortran_charlen_t;
#else
typedef int fortran_charlen_t;
#endif

#ifdef INTEGER8
#define blasint int64_t
#else
#define blasint int
#endif



static TLS_STORE uint8_t hook_pos_cgbtrs = 0;
#ifdef FLEXIBLAS_ABI_INTEL
void FC_GLOBAL(cgbtrs,CGBTRS)(char* trans, blasint* n, blasint* kl, blasint* ku, blasint* nrhs, float complex* ab, blasint* ldab, blasint* ipiv, float complex* b, blasint* ldb, blasint* info)
#else
void FC_GLOBAL(cgbtrs,CGBTRS)(char* trans, blasint* n, blasint* kl, blasint* ku, blasint* nrhs, float complex* ab, blasint* ldab, blasint* ipiv, float complex* b, blasint* ldb, blasint* info)
#endif
{
	void (*fn) (void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info);
	void (*fn_hook) (void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info);

    if ( current_backend->post_init != 0 ) {
        __flexiblas_backend_init(current_backend);
        current_backend->post_init = 0;
    }
	fn = current_backend->lapack.cgbtrs.f77_blas_function; 
	fn_hook = __flexiblas_hooks->cgbtrs.f77_hook_function[0]; 
	if ( fn_hook == NULL ) { 
		fn((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info); 
		return;
	} else {
		hook_pos_cgbtrs = 0;
		fn_hook((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info);
		return;
	}
}
#ifdef FLEXIBLAS_ABI_IBM
void cgbtrs_(char* trans, blasint* n, blasint* kl, blasint* ku, blasint* nrhs, float complex* ab, blasint* ldab, blasint* ipiv, float complex* b, blasint* ldb, blasint* info) __attribute__((alias(MTS(FC_GLOBAL(cgbtrs,CGBTRS)))));
#else
#ifndef __APPLE__
void cgbtrs(char* trans, blasint* n, blasint* kl, blasint* ku, blasint* nrhs, float complex* ab, blasint* ldab, blasint* ipiv, float complex* b, blasint* ldb, blasint* info) __attribute__((alias(MTS(FC_GLOBAL(cgbtrs,CGBTRS)))));
#else
void cgbtrs(char* trans, blasint* n, blasint* kl, blasint* ku, blasint* nrhs, float complex* ab, blasint* ldab, blasint* ipiv, float complex* b, blasint* ldb, blasint* info){ FC_GLOBAL(cgbtrs,CGBTRS)((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info); }
#endif
#endif




/* Real Implementation for Hooks */


void flexiblas_real_cgbtrs_(void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info)
{
	void (*fn) (void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info);

	fn = current_backend->lapack.cgbtrs.f77_blas_function; 

		fn((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info); 

	return;
}
#ifndef __APPLE__
void flexiblas_real_cgbtrs(void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info) __attribute__((alias("flexiblas_real_cgbtrs_")));
#else
void flexiblas_real_cgbtrs(void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info){flexiblas_real_cgbtrs_((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info);}
#endif




/* Chainloader for Hooks */


void flexiblas_chain_cgbtrs_(void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info)
{
	void (*fn) (void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info);
	void (*fn_hook) (void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info);

	fn      = current_backend->lapack.cgbtrs.f77_blas_function; 

    hook_pos_cgbtrs ++;
    if( hook_pos_cgbtrs < __flexiblas_hooks->cgbtrs.nhook) {
        fn_hook = __flexiblas_hooks->cgbtrs.f77_hook_function[hook_pos_cgbtrs];
        fn_hook((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info);
    } else {
        hook_pos_cgbtrs = 0;
		fn((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info); 
	}
	return;
}
#ifndef __APPLE__
void flexiblas_chain_cgbtrs(void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info) __attribute__((alias("flexiblas_chain_cgbtrs_")));
#else
void flexiblas_chain_cgbtrs(void* trans, void* n, void* kl, void* ku, void* nrhs, void* ab, void* ldab, void* ipiv, void* b, void* ldb, void* info){flexiblas_chain_cgbtrs_((void*) trans, (void*) n, (void*) kl, (void*) ku, (void*) nrhs, (void*) ab, (void*) ldab, (void*) ipiv, (void*) b, (void*) ldb, (void*) info);}
#endif



