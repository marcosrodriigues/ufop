.data
	n1: 10;
	n2: 3;
	resto: 0

.text
	mov $s0, n1	#int n1 = 10;
	mov $s1, n2	#int n2 = 3;
	mov $t1, resto	#int resto = 0;

	div $s0, $s1	#n1 % n2;
	mfhi $t1	#resto = n1 % n2;
	
	Loop: beq $t1, $t2 Exit		#while (resto != 0) {
		mov $s0, $s1			#n1 = n2;
		mov $s1, $t1			#n2 = resto;
			
		div $s0, $s1			#n1 % n2;
		mfhi $t1			#resto = n1 % n2;
		bra Loop			# }
	Exit: 
