section .text

global ft_strcat

;	char	*ft_strcat(char *dest, const char *src)

ft_strcat:

	;	saving registers that will be used
	push	rdi
	push	rsi


	;	pops
	pop		rsi
	pop		rdi

	;	return rest
	mov		rax, rdi
	ret
