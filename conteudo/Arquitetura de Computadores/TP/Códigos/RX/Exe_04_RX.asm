.data
	mas: .word 2, 3, 1, 9, 8, 7, 6, 5
	arr: .word 0, 0, 0, 0, 0, 0, 0, 0, 0

.text

jal main

.globl
main:			#int main() {
	mov $s0, mas		#mas[93] = {2, 3, 1, 9, 8, 7, 6, 5}
	mov $s1, arr		#*arr[9] = {0, 0, 0, 0, 0, 0, 0, 0}

	add $a0, $s0
	add $a1, $zero
	add $a2, $zero
	add $a3, $s1

	jal inorder		#inorder(mas, 0, 0, arr);
	
	li $t0, 0		#int k = 0;
	li $t1, 10		#int max = 10;
	Loop: bge $t0, $t1, Exit 	#for (;k < 10;) {
		mov $a0, 0($s1)
		syscall				#print(arr[k]);
		addi $s1, 4
		addi $t0, 1		#k++;
	Exit:				#}
	
	addi $v0, 0
	jr $ra			#return 0}
	
	
	

inorder:		#int inorder(int *mas, int nodeindex, int i, int *arr) {
	
	add $t3, $a0
	add $t3, $a1
	
	add $t4, 0($t3)
	
	bne $t4, $zero, Continue	#if(mas[nodeindex] == 0) {
		addi $v0, $zero, 0		#return 0;
		jr $ra			#}
	Continue:
	
	add $t4, $a0			#aux = mas; // guardo o valor do a0 para poder usar na proxima funcao
	addi $a0, $a1			#transfiro meu valor do nodeindex para o a0
	jal leftchild			#leftchild(nodeindex);
	add $a1, $a0			#volto com meu a1 pro lugar original
	add $a0, $t4			#volto com meu a0 pro lugar original
	jal inorder			#chamo o meu inorder
	#arr[i] = mas[nodeindex]
	add $t5, $a3			#t5 = arr[i] // Transfiro meu vetor para a posição I
	add $t5, $a2
	add $t6, $a0			#t6 = mas[nodeindex] 
	add $t6, $a1
	add $t5, $t6			#t5 = t6
	add $a3, $a2			#arr[0] >> arr[i]
	mov $t6, 0($a3)			#arr[i] = t6
	
	add $t4, $a0			#aux = mas; // guardo o valor do a0 para poder usar na proxima funcao
	addi $a0, $a1			#transfiro meu valor do nodeindex para o a0
	jal rightchild			#rightchild(nodeindex);
	add $a1, $a0			#volto com meu a1 pro lugar original
	add $a0, $t4			#volto com meu a0 pro lugar original
	jal inorder
			#}

leftchild:			#int leftchild (int nodeindex) {
	li $t0, 2			#int d = 2;
	mul $t1, $a0, $t0		#int x = nodeindex * 2;
	addi $t1, 1		#x++;
	add $v0, $t1	
jr $ra				#return x; }

rightchild:			#int rightchild (int nodeindex) {
	li $t0, 2			#int d = 2;
	mul $t1, $a0, $t0		#int x = nodeindex * 2;
	addi $t1, 2		#x = x + 2;
	add $v0, $t1	
jr $ra				#return x; }
