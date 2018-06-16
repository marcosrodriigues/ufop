.data
	mas: .word 2, 3, 1, 9, 8, 7, 6, 5
	arr: .word 0, 0, 0, 0, 0, 0, 0, 0, 0

.text

jal main

.globl
main:			#int main() {
	lw $s0, mas		#mas[93] = {2, 3, 1, 9, 8, 7, 6, 5}
	lw $s1, arr		#*arr[9] = {0, 0, 0, 0, 0, 0, 0, 0}

	addi $a0, $s0, 0
	addi $a1, $zero, 0
	addi $a2, $zero, 0
	addi $a3, $s1, 0

	jal inorder		#inorder(mas, 0, 0, arr);
	
	li $t0, 0		#int k = 0;
	li $t1, 10		#int max = 10;
	Loop: bge $t0, $t1, Exit 	#for (;k < 10;) {
		lw $a0, 0($s1)
		syscall				#print(arr[k]);
		addi $s1, $s1, 4
		addi $t0, $t0, 1		#k++;
	Exit:				#}
	
	addi $v0, $zero, 0
	jr $ra			#return 0}
	
	
	

inorder:		#int inorder(int *mas, int nodeindex, int i, int *arr) {
	
	add $t3, $a0, $a1
	addi $t4, 0($t3), 0
	bne $t4, $zero, Continue	#if(mas[nodeindex] == 0) {
		addi $v0, $zero, 0		#return 0;
		jr $ra			#}
	Continue:
	
	add $t4, $a0, $zero		#aux = mas; // guardo o valor do a0 para poder usar na proxima funcao
	addi $a0, $a1, 0		#transfiro meu valor do nodeindex para o a0
	jal leftchild			#leftchild(nodeindex);
	addi $a1, $a0, 0		#volto com meu a1 pro lugar original
	add $a0, $t4, $zero		#volto com meu a0 pro lugar original
	jal inorder			#chamo o meu inorder
	#arr[i] = mas[nodeindex]
	add $t5, $a3, $a2		#t5 = arr[i] // Transfiro meu vetor para a posição I
	add $t6, $a0, $a1		#t6 = mas[nodeindex] 
	add $t5, $zero, $t6		#t5 = t6
	add $a3, $a3, $a2		#arr[0] >> arr[i]
	sw $t6, 0($a3)			#arr[i] = t6
	
	add $t4, $a0, $zero		#aux = mas; // guardo o valor do a0 para poder usar na proxima funcao
	addi $a0, $a1, 0		#transfiro meu valor do nodeindex para o a0
	jal rightchild			#rightchild(nodeindex);
	addi $a1, $a0, 0		#volto com meu a1 pro lugar original
	add $a0, $t4, $zero		#volto com meu a0 pro lugar original
	jal inorder
			#}

leftchild:			#int leftchild (int nodeindex) {
	li $t0, 2			#int d = 2;
	mul $t1, $a0, $t0		#int x = nodeindex * 2;
	addi $t1, $t1, 1		#x++;
	add $v0, $t1, $zero	
jr $ra				#return x; }

rightchild:			#int rightchild (int nodeindex) {
	li $t0, 2			#int d = 2;
	mul $t1, $a0, $t0		#int x = nodeindex * 2;
	addi $t1, $t1, 2		#x = x + 2;
	add $v0, $t1, $zero	
jr $ra				#return x; }
