// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.
	//set up r0 and r1
	@R0
	M=0 	//R0 as the counter
	@R1
	M=0	
	
(LOOP)
	//if R0 the counter is 0, skip line 37 and go to END 
	@R0
	D=M     //D=R0
	@END
	D;JEQ

	//increment R2 the result address with R1
	@R1
	D=M 	//D=R1
	@R2
	M=M+D 	//R2=R2+R1

	//decrement R0 as the counter
	@R0
	M=M-1   //R0=R0-1

	//back to loop in any condition
	0;JMP

(END)
	@END
	0;JMP	//infinite loop 



