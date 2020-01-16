.globl merge_sort_asm

merge_sort_asm:
    movl %esi, %r8d         #%r8d = low
    movl %edx, %r9d         #r9d = high
    cmpl %r8d, %r9d
    jle .end_merge_sort

    #calculate m
    movl %r9d, %ecx         #ecx = m
    subl %r8d, %ecx
    shrl $1, %ecx
    addl %r8d, %ecx

    #recursive step
    
    movl %ecx, %edx

    push %r8
    push %r9
    push %rcx
    call merge_sort_asm
    pop %rcx
    pop %r9
    pop %r8

    movl %ecx, %esi
    incl %esi
    movl %r9d, %edx

    push %r8
    push %r9
    push %rcx
    call merge_sort_asm
    pop %rcx
    pop %r9
    pop %r8

    movl %r8d, %esi
    movl %ecx, %edx
    movl %r9d, %ecx

    push %r8
    push %r9
    push %rcx
    call merge2
    pop %rcx
    pop %r9
    pop %r8

    #reverse the order of the array
    .swap_items2:
        movl %r8d, %eax
        movl %r9d, %edx
    .swap_loop2:
        cmpl %eax, %edx
        jle .end_merge_sort

        leaq (%rdi, %rax,4), %r10
        movl (%r10), %r11d
        leaq (%rdi, %rdx,4), %r12
        movl (%r12), %esi
        movl %esi, (%r10)
        movl %r11d, (%r12)

        incl %eax
        decl %edx
        jmp .swap_loop2



.end_merge_sort:
    ret


merge2:
                        #edi = array, esi = low, edx = m, ecx = high
    movl %esi, %r8d     #r8d = i = low
    movl %edx, %r9d     #r9d = j = m+1
    incl %r9d
    movl %ecx, %r10d    #r10d = high-low+1 number of items to be copied to/from stack
    subl %esi, %r10d
    incl %r10d



    .first_loop:
        cmpl %r8d, %edx
        jl .second_loop
        cmpl %r9d, %ecx
        jl .second_loop 

        #calculating ptr of array[i] and array[j]
        leaq (%rdi, %r8, 4), %r11
        leaq (%rdi, %r9, 4), %r12
        movl (%r12), %r13d           #r13d = array[j] 

        cmpl (%r11), %r13d
        jl .j_is_smaller

        push (%r11)
        incl %r8d
        jmp .first_loop
    .j_is_smaller:
        push (%r12)
        incl %r9d
        jmp .first_loop
    

    #second_loop & third_loop copy the rest of the array to stack
    .second_loop:
        cmpl %r8d, %edx
        jl .third_loop
        leaq (%rdi, %r8, 4), %r11
        push (%r11)
        incl %r8d
        jmp .second_loop
    .third_loop:
        cmpl %r9d, %ecx
        jl .copy_array
        leaq (%rdi, %r9, 4), %r12
        push (%r12)
        incl %r9d
        jmp .third_loop

    #copy array back from stack to array in reverse order
    .copy_array:
        xorl %eax, %eax
        movl %esi, %r12d 
    .copy_item:
        cmpl %eax, %r10d
        jle .end_merge
        pop  %rdx
        movl %edx, (%rdi,%r12,4)
        incl %eax
        incl %r12d
        jmp .copy_item

    .end_merge:
        ret




