.data
	vetZ: .word 1, 2, 3, 4, 5
	vetX: .word 5, 4, 3, 2, 1
	
.text
	mov $s0, vetZ	#int vetZ = {1, 2, 3, 4, 5);
	mov $s1, vetX	#int vetX = {5, 4, 3, 2, 1);
	li $s2, 0	#int q = 0;
	li $s3, 5	#int n = 5;
	li $t1, 0	#int k = 0;
	li $t2, 0	#int aux = 0;
	
	Loop: bge $t1, $s3, Exit	#for (int k = 0; k < n;) {
		add $t2, 0($s1)		#aux = aux + vetZ[0];
		add $t2, 0($s2)		#aux+= vetX[0];
		addi $s1, 4		#vetX++;
		addi $s0, 4		#vetZ++;
		add $s2, $t2		#q = q + aux;
		addi $t1,  1		#k++;
		bra Loop		# }
	Exit:

			
