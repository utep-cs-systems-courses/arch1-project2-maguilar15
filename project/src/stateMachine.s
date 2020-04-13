 	.arch msp430g2553
	.p2align 1, 0

	.text 

	.global	pwmCount
	.global	sm_update_led
	
JT:
	.word default 
	.word case1
	.word case2 
	.word case3
	.word case4 
	.word case5 
	.word case6 
	.word case7


sm_update_led:
	mov.b	&pwmCount, R12
	mov.b	#3, R13
	mov.b	R12, &pwmCount
	mov.b	&ledMode, R12 
	mov.b	#2, R13 
        jlo 	default
        mov     JT(R12),R0

break: 
	mov.b #1, led_changed
	call #sm_update_led 
	ret 

case2:
	cmp.b	#3, R12 
	cmp.b	#4, R12 
	jmp	break
case3:
	mov.b	#1, &new_red
	mov.b	#1, &new_green
	jmp	break
case1:
	mov.b	#0, &new_red
	mov.b	#0, &new_green
	jmp 	break
case5:
	call	#do_something
	jmp 	break
case6:
	mov.b	&pwmCount, R12
	mov.b	R12, &new_red
	mov.b	&pwmCount, R12
	mov.b	R12, &new_green
	nop
case4:
	mov.b	&red_on, R13
	mov.b	&new_red, R12
	cmp.b	R12, R13 
	mov.b	&green_on, R13
	mov.b	&new_green, R12
	cmp.b	R12, R13 
case7:
	mov.b	&new_red, R12
	mov.b	R12, &red_on
	mov.b	&new_green, R12
	mov.b	R12, &green_on
	mov.b	#1, &led_changed
default:
	
	
	
