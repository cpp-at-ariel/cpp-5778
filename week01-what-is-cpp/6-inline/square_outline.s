_Z6squarei:                             # @_Z6squarei
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	imull	-4(%rbp), %edi
	movl	%edi, %eax
	popq	%rbp
	retq
.Lfunc_end0:

main:                                   # @main
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$1234, %edi             # imm = 0x4D2
	movl	$0, -4(%rbp)
	callq	_Z6squarei
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
