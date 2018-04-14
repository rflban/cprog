	.file	"test.c"
	.intel_syntax noprefix
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%f %f %f\0"
.LC2:
	.ascii "S = %f\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 80
	.seh_stackalloc	80
	movaps	XMMWORD PTR -16[rbp], xmm6
	.seh_savexmm	xmm6, 64
	.seh_endprologue
	call	__main
	lea	rcx, -28[rbp]
	lea	rdx, -24[rbp]
	lea	rax, -20[rbp]
	mov	r9, rcx
	mov	r8, rdx
	mov	rdx, rax
	lea	rcx, .LC0[rip]
	call	scanf
	movss	xmm1, DWORD PTR -20[rbp]
	movss	xmm0, DWORD PTR -24[rbp]
	addss	xmm0, xmm1
	cvtss2sd	xmm0, xmm0
	movsd	xmm1, QWORD PTR .LC1[rip]
	divsd	xmm0, xmm1
	movapd	xmm1, xmm0
	movss	xmm0, DWORD PTR -24[rbp]
	movss	xmm2, DWORD PTR -20[rbp]
	subss	xmm0, xmm2
	cvtss2sd	xmm0, xmm0
	mulsd	xmm0, xmm1
	movsd	xmm1, QWORD PTR .LC1[rip]
	movapd	xmm6, xmm0
	divsd	xmm6, xmm1
	movss	xmm0, DWORD PTR -28[rbp]
	cvtss2sd	xmm0, xmm0
	call	tan
	mulsd	xmm0, xmm6
	movq	rax, xmm0
	mov	rdx, rax
	mov	QWORD PTR -40[rbp], rdx
	movsd	xmm0, QWORD PTR -40[rbp]
	movapd	xmm1, xmm0
	mov	rdx, rax
	lea	rcx, .LC2[rip]
	call	printf
	mov	eax, 0
	movaps	xmm6, XMMWORD PTR -16[rbp]
	add	rsp, 80
	pop	rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.ident	"GCC: (Rev1, Built by MSYS2 project) 7.3.0"
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	tan;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
