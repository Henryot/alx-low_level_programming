section .data
    hello db 'Hello, Holberton', 0
    format db '%s', 0
    nl db 10, 0

section .text
    extern printf

global main
main:
    ; Set up the stack frame
    push rbp
    mov rbp, rsp

    ; Push the addresses of hello and format strings on the stack (in reverse order)
    lea rdi, [format]
    lea rsi, [hello]
    call printf

    ; Print the new line
    lea rdi, [nl]
    call printf

    ; Restore the stack and exit the program
    pop rbp
    xor eax, eax         ; Return value 0
    ret
