states:
	.word case1		;states
	.word case2
	.word case3
	.word case4

sm_update_led:
	
case1:
	mov.b #1, 0(r1) 	;red light on
	mov.b #1, 1(r1)		;green light on
	jmp end
case2:
	mov.b #0, 0(r1) 	;red is off
	mov.b #0, 1(r1)		;green is off
	jmp end
end:
	cmp.b 0(r1), &red_on 	;check red change
	jnz change_leds
	cmp.b 1(r1), &green_on 	;check green change
	jnz change_leds
	jz final
change_leds:
	mov.b 0(r1), &red_on
	mov.b 1(r1), &green_on
	mov.b #1, &led_changed
final:
	add #2, r1
	ret
