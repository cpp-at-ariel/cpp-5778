	.text
	.file	"/home/erelsgl/Dropbox/ariel/ariel-cpp-5778/week01-what-is-cpp/6-inline/square_outline.cpp"
	.globl	_Z6squarei              # -- Begin function _Z6squarei
	.p2align	4, 0x90
	.type	_Z6squarei,@function
_Z6squarei:                             # @_Z6squarei
# BB#0:
	imull	%edi, %edi
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	_Z6squarei, .Lfunc_end0-_Z6squarei
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rax
.Lcfi0:
	.cfi_def_cfa_offset 16
	movl	$4, %edi
	callq	_Znwm
	imull	%eax, %eax
                                        # kill: %EAX<def> %EAX<kill> %RAX<kill>
	popq	%rcx
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 5.0.1-svn319952-1~exp1 (branches/release_50)"
	.section	".note.GNU-stack","",@progbits
