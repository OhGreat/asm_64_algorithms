.globl test
.globl test2

.data
array: .long 11,23,53,12,34,15,31

test:
xorq %rcx, %rcx
leaq (%rdi, %rcx,1), %rdx
movl (%rdx), %eax
movl $191919, (%rdx)
ret


test2:
xorq %rax, %rax
movq $8, %rcx
leaq (%rdi, %rcx,1), %rdx
movq (%rdx), %r8
addl %r8d, %eax
ret
