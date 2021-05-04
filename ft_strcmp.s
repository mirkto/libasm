			global		_ft_strcmp

			section		.text
_ft_strcmp:	mov		rcx, -1				;rdi=dest, rsi=source
loop:		inc		rcx
			cmp		byte[rdi + rcx], 0
			jz		rdizero
			cmp		byte[rsi + rcx], 0
			jz		positive
			mov		al, byte[rdi + rcx]
			sub		al, byte[rsi + rcx]
			cmp		al, 0
			jg		positive
			jl		negative
			jmp		loop
rdizero:	cmp		byte[rsi + rcx], 0
			jz		zero
negative:	mov		rax, -1
			ret
positive:	mov		rax, 1
			ret
zero:		mov		rax, 0
			ret