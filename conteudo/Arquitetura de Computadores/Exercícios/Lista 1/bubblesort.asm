.data
	vetor: .word	50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
.text
	la $s0, vetor	# int *vetor	
	li $s1, 0 	# int aux = 0;
	li $s2, 50	# int n = 50;	
	li $t1, 0	# int i = 0;
	li $t2, 1	# int j = 1;
	
	loopI:	bge $t1, $s2, exitI	#for (i = 0; i < 50; ) {
		addi $t2, $t1, 0
		loopJ:	bge $t2, $s2, exitJ	#for (j = 1; j < 50; j++) {
		
			lw $t3, 0($s0)			# int vetorJ_1 = vetor[i]
			addi $s0, $s0, 4	
			lw $t4, 0($s0)			# int vetorJ = vetor[j];
			subi $s0, $s0, 4
		
			ble   $t3, $t4, exitIf		#if (vetorJ < vetorJ_1) {
				addi $s1, $t3, 0		#aux = vetorJ;
				addi $t3, $t4, 0		#vetorJ = vetorJ_1;
				addi $t4, $s1, 0		#vetorJ_1 = aux

				sw $t3, 0($s0)			#vetor[j] = vetorJ
				addi $s0, $s0, 4
				sw $t4, 0($s0)			#vetor[j - 1] = vetorJ_1;
				
			exitIf:				#}
			addi $t2, $t2, 1		#j++;		
			j loopJ			#
		exitJ:		
		addi $t1, $t1, 1	# i++;
		j loopI			# }
	exitI:				
	
