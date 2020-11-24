			global		_ft_read
			extern		___error

			section		.text
_ft_read:	mov			rax, 0x2000003		;rdi=fd, rsi=buffer, rdx=len
			syscall
			jc			error
			jmp			done
error:		push		rax
			call		___error
			pop			rcx
			mov			[rax], rcx
			mov			rax, -1
done:		ret