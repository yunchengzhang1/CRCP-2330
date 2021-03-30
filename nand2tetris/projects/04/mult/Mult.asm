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
	@R1
	D=M
	@counter	//set counter to R1	
	M=D	
	@R2
	M=0		//R2 TO 0

(LOOP)
	//if counter is 0,  go to END 
	@counter
	D=M     //D=counter
	@END
	D;JEQ

	//increment R2 the result address with R0
	@R0
	D=M 	//D=R0
	@R2
	M=D+M 	//R2=R2+R0

	//decrement the counter
	@counter
	M=M-1   //R0=R0-1

	//back to loop in any condition
	@loop
	0;JMP

(END)
	@END
	0;JMP	//infinite loop 



