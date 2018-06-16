.data
	dctBlock: .word 1, 1, 1, 1, 1, 1, 1, 1

.text

voiddct1dTest:	
					#static voiddct1dTest(int *dctBlock) {
	addi $s0, 1004, 0		#static const int c1=1004 /*cos(pi/16)<<10*/; 
	addi $s1, 200, 0		#static const int s1=200 /*sin(pi/16)<<10*/;
	addi $s2, 851, 0		#static const int c3=851 /*cos(3pi/16)<<10*/
	addi $s3, 569, 0		#static sont int s3=569 /*sin(3pi/16)<<10*/;
	addi $s4, 554, 0		#static const int r2c6=554 /*sqrt(2)*cos(6pi/16)<<10*/;
	addi $s5, 1337, 0		#static const int r2s6=1337;
	addi $s6, 181, 0		#static const int r2=181; /* sqrt(2)<<7 */
	
	
	
	lw $t0, 0($a0)			#int x0 = dctBlock[0];
	lw $t1, 4($a0)			#int x1 = dtcBlock[1];
	lw $t2, 8($a0)			#int x2 = dtcBlock[2];
	lw $t3, 12($a0)			#int x3 = dtcBlock[3];
	lw $t4, 16($a0)			#int x4 = dtcBlock[4];
	lw $t5, 20($a0)			#int x5 = dtcBlock[5];
	lw $t6, 24($a0)			#int x6 = dtcBlock[6];
	lw $t7, 28($a0)			#int x7 = dtcBlock[7];
	
	li $t8, 0			#int x8 = 0;
	li $t9, 0			#int xAux = 0;
					
					#/* Stage 1 */
	add $t8, $t7, $t0		#x8=x7+x0; 
	sub $t0, $t0, $t7		#x0-=x7;  
	add $t7, $t1, $t6		#x7=x1+x6; 
	sub $t1, $t1, $t6		#x1-=x6;
	add $t6, $t2, $t5		#x6=x2+x5; 
	sub $t2, $t2, $t5		#x2-=x5;  
	add $t5, $t3, $t4		#x5=x3+x4; 
	sub $t3, $t3, $t4		#x3-=x4;
	
					#/* Stage 2 */
	add $t4, $t8, $t5		#x4=x8+x5; 
	sub $t8, $t8, $t5		#x8-=x5;  
	add $t5, $t7, $t6		#x5=x7+x6; 
	sub $t7, $t7, $t6		#x7-=x6;
	add $t9, $s1, $t2		#xAux = x1+x2;
	mul $t6, $s0, $t9		#x6 = c1 * xAux;

	
	sub $t9, $zero, $s1		#vAux = -s1;
	sub $t9, $t9, $s0		#vAux = vAux-c0;
	mul $t9, $t9, $t2		#vAux = vAux * x2;
	add $t2, $t9, $t6		#x2 = vAux+x6;
	
	sub $t9, $s1, $s0		#vAux = s1 - c1;
	mul $t9, $t9, $t1		#vAUx = vAux * x1;
	add $t1, $t9, $t6		#x1 = vAux + x6;

	add $t9, $t0, $t3		#vAux = x0 + x3;
	mul $t6, $s2, $t9		#x6 = vAux * c3;

	
	sub $t9, $zero, $s3		#vAux = -s3
	sub $t9, $t9, $s2		#vAux = vAux - c3;
	mul $t9, $t9, $t3		#vAux = vAux * x3;
	add $t3, $t9, $t6		#vAux = vAux + x6;
	
	sub $t9, $s3, $s2		#vAux = s3 - c3;
	mul $t0 $t9, $t0		#x0 = vAux * x0;
	add $t0, $t0, $t6		#x0 = x0 + x6;
	
					#/* Stage 3 */
	add $t6, $t4, $t5		#x6 = x4 + x5; 
	sub $t4, $t4, $t5		#x4 -= x5;
	
	add $t9, $t7, $t8		#vAux = x7 + x8;
	mul $t5, $s4, $t9		#x5 = r2c6 *vAux;
	
	sub $t9, $zero, $s5		#vAux = -r2s6
	sub $t9, $t9, $s4		#vAux -= r2c6;
	mul $t7, $t9, $t7		#x7 = vAux * x7;
	add $t7, $t7, $t5		#x7 = x7 + x5;
	
	sub $t9, $s5, $s4		#vAux = r2s6 - rsc6;
	mul $t8, $t9, $t8		#x8 = vAux * x8;
	add $t8, $t8, $t5		#x8 = x8 + x5;
	
	add $t5, $t0, $t2		#x5 = x0 + x2;
	sub $t0, $t0, $t2		#x0 -= x2;
	add $t2, $t3, $t1		#x2 = x3 + x1;
	sub $t3, $t3, $t1		#x3 -= x1;
	
					#/* Stage 4, round, and output */
	sw $t6, 0($a0)			#dctBlock[0] = x6;
	sw $t4, 16($a0)			#dctBlock[4] = x4;
	
	addi $t8, $t8, 512		#x8 = x8 + 512;
	sra $t8, $t8, 10		# x8 >> 10;
	sw $t8, 8($a0)			#dctBlock[2] = x8;
	
	addi $t7, $t7, 512		#x7 = x7 + 512
	sra $t7, $t7, 10		#x7 >> 10;
	sw $t7, 24($a0)			#dctBlock[6] = x7;
	
	sub $t9, $t2, $t5		#vAux = x2 - x5;
	addi $t9, $t9, 512		#vAux = vAux + 512
	sra $t9, $t9, 10		#vAux >> 10;
	sw $t9, 28($a0)			#dctBlock[7] = vAux;
	
	add $t9, $t2, $t5		#vAux = x2 + x5;
	addi $t9, $t9, 512		#vAux = vAux + 512
	sra $t9, $t9, 10		#vAux >> 10;
	sw $t9, 4($a0)			#dctBlock[7] = vAux;
	
	mul $t3, $t3, $s6		#x3 = x3 * r2;
	addi $t3, $t3, 65536		#x3 = x3 + 65536
	sra $t3, $t3, 17		#x3 >> 17
	sw $t3, 12($a0)			#dctBlock[3] = x3
	
	mul $t0, $t0, $s6		#x0 = x0 * r2;
	addi $t0, $t0, 65536		#x0 = x0 + 65536
	sra $t0, $t0, 17		#x0 >> 17
	sw $t0, 20($a0)			#dctBlock[5] = x0
	
	add $v0, $a0, $zero
	jr $ra
