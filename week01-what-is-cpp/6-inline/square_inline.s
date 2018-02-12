	.text
	.file	"/home/erelsgl/Dropbox/ariel/ariel-cpp-5778/week01-what-is-cpp/6-inline/square_inline.cpp"
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
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 5.0.1-svn319952-1~exp1 (branches/release_50)"
	.section	".note.GNU-stack","",@progbits
