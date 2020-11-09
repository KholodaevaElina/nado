#include <stdio.h>

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

int main () {
	 FILE* input_file = fopen ("input.txt", "r");

	 int number_of_instructions = 0;
	 fscanf (input_file, "%d", &number_of_instructions);

	 int number_instruction = 0;

	 int number_to_add_to_stack = 0;

	 FILE* output_file = fopen ("file_from_deasm.txt", "w");

	 for (int i = 0; i < number_of_instructions; i++) {
	         fscanf (input_file, "%d", &number_instruction);

		  if (number_instruction == INSTRUCTION_NUMBER_PUSH) {
			 fscanf (input_file, "%d", &number_to_add_to_stack);
			 fprintf (output_file, "%s %d %c", "_push ",number_to_add_to_stack, '\n');
		 } else {
			 switch (number_instruction) {
				case INSTRUCTION_NUMBER_IN:
					 fprintf (output_file, "%s", "_in\n");
					 break;
				case INSTRUCTION_NUMBER_POP:
					 fprintf (output_file, "%s", "_pop\n");
					 break;
				case INSTRUCTION_NUMBER_MUL:
					 fprintf (output_file, "%s", "_mull\n");
					 break;
				case INSTRUCTION_NUMBER_ADD:
				         fprintf (output_file, "%s", "_add\n");
				         break;
				case INSTRUCTION_NUMBER_SUB:
					 fprintf (output_file, "%s", "_sub\n");
					 break;
				case INSTRUCTION_NUMBER_DIV:
					 fprintf (output_file, "%s", "_div\n");
					 break;
				case INSTRUCTION_NUMBER_OUT:
					 fprintf (output_file, "%s", "_out\n");
					 break;
				case INSTRUCTION_NUMBER_HLT:
					 fprintf (output_file, "%s", "_hlt\n");
					 break;
				case INSTRUCTION_NUMBER_SIN:
					 fprintf (output_file, "%s", "_sin\n");
					 break;
				case INSTRUCTION_NUMBER_COS:
					 fprintf (output_file, "%s", "_cos\n");
				         break;
				case INSTRUCTION_NUMBER_SQRT:
					 fprintf (output_file, "%s", "_sqrt\n");
					 break;					 
			 }
	         }
 
	 }

}
