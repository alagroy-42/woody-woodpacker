BITS 64

segment .text
	global test

test:
	push rax
	push rsi
	push rdi
	push rdx
	jmp woody
end_code:
	pop rsi
	mov rax, 1
	mov rdi, 1
	mov rdx, 14
	syscall
	pop rdx
	pop rdi
	pop rsi
	pop rax
	jmp 53
woody:
	call end_code
	woody_str: db "....WOODY....", 10