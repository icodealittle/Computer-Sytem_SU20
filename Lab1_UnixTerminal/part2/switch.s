	.file	"switch.c"
	.section	.rodata
.LC0:
	.string	"Excellent\n"
.LC1:
	.string	"Asian B\n"
.LC2:
	.string	"Asian C\n"
.LC3:
	.string	"No dinner!\n"
.LC4:
	.string	"You're a disgrace\n"
.LC5:
	.string	"Why are you like this?\n"
.LC6:
	.string	"Your grade is: %d\n"
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
	subq	$16, %rsp
	movl	$85, -4(%rbp)
	movl	-4(%rbp), %eax
	subl	$80, %eax
	cmpl	$20, %eax
	ja	.L2
	movl	%eax, %eax
	movq	.L4(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L3
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L5
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L6
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L7
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L2
	.quad	.L8
	.text
.L8:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L7:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L6:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L5:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L3:
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	jmp	.L9
.L2:
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
.L9:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
