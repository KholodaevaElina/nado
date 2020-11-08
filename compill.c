#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * My processor sends the number of instructions in the file to the processor.
 * The number of commands will be written as the first line in the file. 
 * */

#define STACK_SIZE_AT_THE_TIME_THE_PROCESSOR_BEGINS 10
#define MAX_SIZE_STACK 500
#define SUCCESS 0

#define ERROR_STACK_OVERFILLED 666

#define INSTRUCTION_NUMBER_IN 1
#define INSTRUCTION_NUMBER_POP 2
#define INSTRUCTION_NUMBER_MUL 3
#define INSTRUCTION_NUMBER_ADD 4
#define INSTRUCTION_NUMBER_SUB 5
#define INSTRUCTION_NUMBER_DIV 6
#define INSTRUCTION_NUMBER_OUT 7
#define INSTRUCTION_NUMBER_HLT 8
#define INSTRUCTION_NUMBER_SIN 9
#define INSTRUCTION_NUMBER_COS 10
#define INSTRUCTION_NUMBER_SQRT 11
#define INSTRUCTION_NUMBER_PUSH 12

struct stack {
	int top;
	double* data;
};

typedef struct stack Stack;

void constructor_stack (Stack* stek);
void push (Stack* stek, double number_to_add_to_stack);
void sqrt (Stack* p_stek);
void cos (Stack* p_stek);
void sin (Stack* p_stek);
void hlt (Stack* p_stek);
void out (Stack* p_stek);
void div (Stack* p_stek);
void sub (Stack* p_stek);
void add (Stack* p_stek);
void mull (Stack* p_stek);
double pop (Stack* p_stek);
void in (Stack* p_stek);


int main () {
	 Stack* p_processor_stack;

	 constructor_stack (p_processor_stack);

	 FILE* input_file = fopen ("input.txt", "r");
	 
	 int number_of_instructions = 0;
	 fscanf (input_file, "%d", &number_of_instructions);

	 int number_instruction = 0;
	 int number_to_add_to_stack = 0;

	 for (int i = 0; i < number_of_instructions; i++) {
	         fscanf (input_file, "%d", &number_instruction);

		 if (number_instruction == INSTRUCTION_NUMBER_PUSH) {
			 fscanf (input_file, "%d", &number_to_add_to_stack);
			 push (p_processor_stack, number_to_add_to_stack);
		 } else {
			 switch (number_instruction) {
				 case INSTRUCTION_NUMBER_IN: ;
			 }
		 }
 
	 }
}

void sqrt (Stack* p_stek) {
        (p_stek -> data)[(p_stek -> top) - 1] = sqrt ((p_stek -> data)[(p_stek -> top) - 1]);
}

void cos (Stack* p_stek) {
        (p_stek -> data)[(p_stek -> top) - 1] = cos ((p_stek -> data)[(p_stek -> top) - 1]);
}

void sin (Stack* p_stek) {
	(p_stek -> data)[(p_stek -> top) - 1] = sin ((p_stek -> data)[(p_stek -> top) - 1]);
}

void hlt (Stack* p_stek) {
	free (p_stek);
	exit (SUCCESS);//в качестве задерки можно вставить вычисление какой - нибудь степени двойки.
}

void out (Stack* p_stek) {
	(p_stek -> top)--;
	printf ("%lg", (p_stek -> data)[p_stek -> top]);
}

void div (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться
        int difference_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] - (p_stek -> data)[p_stek -> top - 2];
        (p_stek -> top)--;
        (p_stek -> data)[top] = difference_of_the_top_two_elements_of_the_stack;
}


void sub (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться
        int difference_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] - (p_stek -> data)[p_stek -> top - 2];
        (p_stek -> top)--;
        (p_stek -> data)[top] = difference_of_the_top_two_elements_of_the_stack;
}


void add (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться
        int sum_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] + (p_stek -> data)[p_stek -> top - 2];
        (p_stek -> top)--;
        (p_stek -> data)[top] = sum_of_the_top_two_elements_of_the_stack;
}


void mull (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться 
	int product_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] * (p_stek -> data)[p_stek -> top - 2];
	(p_stek -> top)--;
	(p_stek -> data)[top] = product_of_the_top_two_elements_of_the_stack;
}
	

double pop (Stack* p_stek) {
	(p_stek -> top)--;
	return (p_stek -> data)[p_stek -> top];
}

void in (Stack* p_stek) {
	printf ("Enter the number you would like to add to the stack:  ");

	double number_to_add_to_stack = 0.0;

	scanf ("%lg", &number_to_add_to_stack);
        push (p_stek, number_to_add_to_stack);
}	

void constructor_stack (Stack* p_stek) {
        (p_stek -> top) = 0;
        (p_stek -> data) = (double*) calloc (STACK_SIZE_AT_THE_TIME_THE_PROCESSOR_BEGINS, sizeof (double));
}

void push (Stack* p_stek, double number_to_add_to_stack) {
        if ((p_stek -> top) == MAX_SIZE_STACK) {
                printf ("STACK OVERFILLED\n");
                printf ("Now the program will crash\n");

                exit (ERROR_STACK_OVERFILLED);
        } else {
                (p_stek -> data)[p_stek -> top] = number_to_add_to_stack;
                (p_stek -> top)++;
        }
}

