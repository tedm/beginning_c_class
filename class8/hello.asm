section .data
    msg db "Hello, world!", 0x0A ; Our message, 0x0A is the newline character
    len equ $ - msg             ; Length of the message

section .text
    global _start               ; Entry point for the linker

_start:
    ; sys_write (syscall number 1)
    mov rax, 1                  ; System call number for sys_write
    mov rdi, 1                  ; File descriptor 1 (stdout)
    mov rsi, msg                ; Address of the message string
    mov rdx, len                ; Length of the message
    syscall                     ; Execute the system call

    ; sys_exit (syscall number 60)
    mov rax, 60                 ; System call number for sys_exit
    mov rdi, 0                  ; Exit code 0 (success)
    syscall                     ; Execute the system call
