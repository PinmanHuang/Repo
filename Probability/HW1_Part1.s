	.file	"HW1_Part1.c"
	.section	.rodata
.LC0:
	.string	"There is no Black Card now. "
.LC1:
	.string	"You just can enter R. "
.LC2:
	.string	"There is no Red Card now. "
.LC3:
	.string	"You just can enter B. "
.LC4:
	.string	"%d / %d = %f\n"
.LC5:
	.string	"%c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$80, -24(%rbp)
	movl	$80, -20(%rbp)
	jmp	.L2
.L8:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	cmpl	$0, -16(%rbp)
	jne	.L3
	movl	$80, -24(%rbp)
	movl	$80, -20(%rbp)
.L3:
	cmpl	$0, -24(%rbp)
	jne	.L4
	movzbl	-25(%rbp), %eax
	cmpb	$66, %al
	jne	.L4
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %edi
	call	puts
.L4:
	cmpl	$0, -20(%rbp)
	jne	.L5
	movzbl	-25(%rbp), %eax
	cmpb	$82, %al
	jne	.L5
	movl	$.LC2, %edi
	call	puts
	movl	$.LC3, %edi
	call	puts
.L5:
	movzbl	-25(%rbp), %eax
	cmpb	$66, %al
	jne	.L6
	cmpl	$0, -24(%rbp)
	je	.L6
	subl	$1, -24(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2ss	-16(%rbp), %xmm1
	divss	%xmm1, %xmm0
	movd	%xmm0, %eax
	movl	%eax, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	-16(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
	jmp	.L2
.L6:
	movzbl	-25(%rbp), %eax
	cmpb	$82, %al
	jne	.L2
	cmpl	$0, -20(%rbp)
	je	.L2
	subl	$1, -20(%rbp)
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2ss	-16(%rbp), %xmm1
	divss	%xmm1, %xmm0
	movd	%xmm0, %eax
	movl	%eax, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	-16(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$1, %eax
	call	printf
.L2:
	leaq	-25(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	testl	%eax, %eax
	je	.L7
	movzbl	-25(%rbp), %eax
	cmpb	$48, %al
	jne	.L8
.L7:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.9.1-16ubuntu6) 4.9.1"
	.section	.note.GNU-stack,"",@progbits
