.globl insertion_sort


#array =  %rdi, n_bytes = %rsi, size_of_int = %rdx

insertion_sort:
      xorl %ecx, %ecx                     #ecx = i
      xorl %eax, %eax
      movl %esi, %r14d
      subl $4, %r14d                      #r14d = len - 1
      xorl %r8d, %r8d                     #r8d = aux2

  .while1:
      cmpl %ecx, %r14d
      jle .endWhile1
      movl %ecx, %eax                     #eax = aux = i
      movl $4, %r9d
      addl %ecx, %r9d                     #r9d = k = i+1

    .while2:
      cmpl $0, %eax
      jl .endWhile2
      cmpl %r9d, %esi
      jle .endWhile2
      leaq (%rdi, %r9,1), %r10            #(r10) = array[k]
      leaq (%rdi, %rax,1), %r11           #(r11) = r13 = array[aux]
      movl (%r11), %r13d
      cmpl (%r10), %r13d
      jle .endWhile2

      movl (%r10), %r8d
      movl %r13d, (%r10)
      movl %r8d, (%r11)

      subl %edx, %r9d
      subl %edx, %eax
      jmp .while2

    .endWhile2:
      addl %edx, %ecx
      jmp .while1

  .endWhile1:
    movq %rdi, %rax
    ret
