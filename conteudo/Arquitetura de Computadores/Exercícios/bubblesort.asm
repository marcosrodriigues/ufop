.data
	vetor: .word	40, 20, 10, 10, 5, 4, 30, 2, 4, 5, 6, 7, 8 ,34, 22, 40, 20, 10, 10, 5, 4, 30, 2, 4, 5, 6, 7, 8 ,34, 22, 40, 20, 10, 10, 5, 4, 30, 2, 4, 5, 6, 7, 8 ,34, 22, 44, 41, 33, 44, 11
.text
	la $s0, vetor	# int *vetor	
	li $s1, 0 	# int aux = 0;
	li $s2, 50	# int n = 50;	
	li $t1, 0	# int i = 0;
	li $t2, 1	# int j = 1;
	
	loopI:	bge $t1, $s2, exitI	#for (i = 0; i < 50; ) {
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
	
