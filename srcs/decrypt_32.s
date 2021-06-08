BITS 32

segment .text
	global decrypt

decrypt:
	pusha
	jmp woody
end_code:
	pop ecx
	mov eax, 4
	mov ebx, 1
	mov edx, 14
	int 0x80
	mov ecx, 43 ; text_size
	mov esi, 4 ; key_size 
	call get_eip ; text
	sub edx, 0x10000
	xor ebx, ebx ; key_index
	xor eax, eax ; key_offset
	jmp key
back_key:
	pop edi ; key
routine:
	mov al, byte [edi + ebx]
	add al, ah
	xor [edx], al
	inc edx
	inc ebx
	cmp ebx, esi
	jne loopinstr
	add ah, byte 42
	xor ebx, ebx
loopinstr:
	loop routine
	popa
	jmp 42
get_eip:
	mov edx, [esp]
	ret
woody:
	call end_code
	woody_str: db "....WOODY....", 10
key:
	call back_key
	key_str: db ''