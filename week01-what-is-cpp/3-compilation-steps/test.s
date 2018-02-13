	.text
	.file	"/home/erelsgl/Dropbox/ariel/ariel-cpp-5778/week01-what-is-cpp/3-compilation-steps/test.cpp"
	.globl	_Z6squarei              # -- Begin function _Z6squarei
	.p2align	4, 0x90
	.type	_Z6squarei,@function
_Z6squarei:                             # @_Z6squarei
# BB#0:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	imull	-4(%rbp), %edi
	movl	%edi, %eax
	popq	%rbp
	retq
.Lfunc_end0:
	.size	_Z6squarei, .Lfunc_end0-_Z6squarei
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movl	$5, %edi
	movl	$0, -4(%rbp)
	callq	_Z6squarei
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
                                        # -- End function

	.ident	"clang version 5.0.1-svn319952-1~exp1 (branches/release_50)"
	.section	".note.GNU-stack","",@progbits
