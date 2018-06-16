subs:
	addi $sp, $sp, 8
	sub $v0, $a0, $a1
	jr $ra
	
compare:
	add $a0, $a0, 0($sp)
	add $a1, $a1, 4($sp)
	jal subs
	