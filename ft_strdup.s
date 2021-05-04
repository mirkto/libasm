			global		_ft_strdup
			extern		_ft_strlen
			extern		_ft_strcpy
			extern		_malloc

			section		.text
_ft_strdup:	xor			rax, rax		;rdi=*str
			;cmp		rdi, 0
			;jz			error
			push		rdi
			call		_ft_strlen			;rdi=*str
			inc			rax
			mov			rdi, rax
			call		_malloc				;rdi=len of str
			cmp			rax, 0
			jz			error
			mov			rdi, rax
			pop			rsi
			call		_ft_strcpy			;rdi=dest, rsi=source
done:		ret
error:		xor			rax,rax
			ret