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

void _constructor_stack (Stack* stek);
void _push (Stack* stek, double number_to_add_to_stack);
void _sqrt (Stack* p_stek);
void _cos (Stack* p_stek);
void _sin (Stack* p_stek);
void _hlt (Stack* p_stek);
void _out (Stack* p_stek);
void _div (Stack* p_stek);
void _sub (Stack* p_stek);
void _add (Stack* p_stek);
void _mull (Stack* p_stek);
double _pop (Stack* p_stek);
void _in (Stack* p_stek);


int main () {
	 Stack processor_stack;

	 _constructor_stack (&processor_stack);

	 FILE* input_file = fopen ("input.txt", "r");
 
	 int number_of_instructions = 0;
	 fscanf (input_file, "%d", &number_of_instructions);

	 int number_instruction = 0;
	 int number_to_add_to_stack = 0;

	 for (int i = 0; i < number_of_instructions; i++) {
	         fscanf (input_file, "%d", &number_instruction);
		 
		 printf ("%d\n", number_instruction);

		 if (number_instruction == INSTRUCTION_NUMBER_PUSH) {
			 fscanf (input_file, "%d", &number_to_add_to_stack);
			 _push (&processor_stack, number_to_add_to_stack);
		 } else {
			 switch (number_instruction) {
				 case INSTRUCTION_NUMBER_IN:
					 _in (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_POP:
					 _pop (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_MUL:
					 _mull (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_ADD:
				         _add (&processor_stack);
				         break;
				case INSTRUCTION_NUMBER_SUB:
					 _sub (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_DIV:
					 _div (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_OUT:
					 _out (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_HLT:
					 _hlt (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_SIN:
					 _sin (&processor_stack);
					 break;
				case INSTRUCTION_NUMBER_COS:
					 _cos (&processor_stack);
				         break;
				case INSTRUCTION_NUMBER_SQRT:
					 _sqrt (&processor_stack);
					 break;
                                //default прописать с какой - нибудь ругалкой.					 
			 }
	         }
 
	 }
}

void _sqrt (Stack* p_stek) {
        (p_stek -> data)[(p_stek -> top) - 1] = sqrt ((p_stek -> data)[(p_stek -> top) - 1]);
}

void _cos (Stack* p_stek) {
        (p_stek -> data)[(p_stek -> top) - 1] = cos ((p_stek -> data)[(p_stek -> top) - 1]);
}

void _sin (Stack* p_stek) {
	(p_stek -> data)[(p_stek -> top) - 1] = sin ((p_stek -> data)[(p_stek -> top) - 1]);
}

void _hlt (Stack* p_stek) {
	free (p_stek);
	exit (SUCCESS);//в качестве задерки можно вставить вычисление какой - нибудь степени двойки.
}

void _out (Stack* p_stek) {
	(p_stek -> top)--;
	printf ("%lg", (p_stek -> data)[p_stek -> top]);
}

void _div (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться
        int difference_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] - (p_stek -> data)[p_stek -> top - 2];
        (p_stek -> top)--;
        (p_stek -> data)[p_stek -> top] = difference_of_the_top_two_elements_of_the_stack;
}


void _sub (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться
        int difference_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] - (p_stek -> data)[p_stek -> top - 2];
        (p_stek -> top)--;
        (p_stek -> data)[p_stek -> top] = difference_of_the_top_two_elements_of_the_stack;
}


void _add (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться
        int sum_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] + (p_stek -> data)[p_stek -> top - 2];
        (p_stek -> top)--;
        (p_stek -> data)[p_stek -> top] = sum_of_the_top_two_elements_of_the_stack;
}


void _mull (Stack* p_stek) {//check that there are at least two elements компилятор же должен ругаться 
	int product_of_the_top_two_elements_of_the_stack = (p_stek -> data)[(p_stek -> top) - 1] * (p_stek -> data)[p_stek -> top - 2];
	(p_stek -> top)--;
	(p_stek -> data)[p_stek -> top] = product_of_the_top_two_elements_of_the_stack;
}
	

double _pop (Stack* p_stek) {
	(p_stek -> top)--;
	return (p_stek -> data)[p_stek -> top];
}

void _in (Stack* p_stek) {
	printf ("Enter the number you would like to add to the stack:  ");

	double number_to_add_to_stack = 0.0;

	scanf ("%lg", &number_to_add_to_stack);
        _push (p_stek, number_to_add_to_stack);
}	

void _constructor_stack (Stack* p_stek) {
        (p_stek -> data) = (double*) calloc (STACK_SIZE_AT_THE_TIME_THE_PROCESSOR_BEGINS, sizeof (double));
}

void _push (Stack* p_stek, double number_to_add_to_stack) {
        if ((p_stek -> top) == MAX_SIZE_STACK) {
                printf ("STACK OVERFILLED\n");
                printf ("Now the program will crash\n");

                exit (ERROR_STACK_OVERFILLED);
        } else {
                (p_stek -> data)[p_stek -> top] = number_to_add_to_stack;
                (p_stek -> top)++;
        }
}
