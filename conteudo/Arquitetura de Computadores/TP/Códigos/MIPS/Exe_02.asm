.data
	n1: 10;
	n2: 3;
	resto: 0

.text
	lw $s0, n1	#int n1 = 10;
	lw $s1, n2	#int n2 = 3;
	lw $t1, resto	#int resto = 0;
	li $t2, 0	#int zero = 0;

	div $s0, $s1	#n1 % n2;
	mfhi $t1	#resto = n1 % n2;
	
	Loop: beq $t1, $t2 Exit		#while (resto != 0) {
		add $s0, $t2, $s1		#n1 = n2;
		add $s1, $t2, $t1		#n2 = resto;
			
		div $s0, $s1			#n1 % n2;
		mfhi $t1			#resto = n1 % n2;
		j Loop			# }
	Exit: 
