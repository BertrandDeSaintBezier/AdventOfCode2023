#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char* read_chunk(char *start){
	char result[3];
	for(int i = 0; i <= 3; i++){
		char tmp = start[i];
		if(isdigit(tmp)){		
		}

	}
}

int main(int argc, char *argv[]) {
	// read first line. Store in prevLine and remember lineLength
	// init buffer of currContent of size 4
	// init empty array of indices to check
	// init result

	// LOOP
	// read new line, store in currLine
	// foreach int in indicesToCheck
	// read at index -3, -2, -1, 0 and +1 for a number
	// if found number, add to result
	// 
	// foreach char in line
	// currContent = next 4 chars of line
	// evaluate char : if char is > 32 && < 47 && != 46 it is a symbol
	// Add char index to indices
	// check 3 first entries of currContent if not empty and read as int. add to result.
	// check 3 next entries after symbol or until you hit . add to result
	// check in prevLine from index -4 to index + 1
	// else if char is . then clear currContent
	
	char *puzzle_input = argv[1];
	FILE *fptr = fopen(puzzle_input, "r");

    	if (fptr == NULL) {
        	printf("Error: could not open file %s", puzzle_input);
        	return 1;
    	}
	
	const unsigned MAX_LENGTH = 256;
	size_t line_length = 0;
	char curr_line[MAX_LENGTH];
	char prev_line[MAX_LENGTH]; 
	char curr_char;

	char curr_word[4];
	int curr_word_index = 0;

	bool include_next = false;

	// Read the first line. Store in prevline and save the length.
	if(fgets(curr_line, MAX_LENGTH, fptr)){
		line_length = strlen(curr_line);
		memcpy(prev_line, curr_line, line_length);
	}

	rewind(fptr); // C is awesome

	while(fgets(curr_line, MAX_LENGTH, fptr)){
		printf("Include : ");
		for(int i = 0; i < strlen(curr_line); i++){
			curr_char = curr_line[i];
			// detect symbol
			if(curr_char > 32 && curr_char < 47 && curr_char != 46){
				include_next = true;
				if(curr_word_index > 0){
					// printf("%s%c ", curr_word, curr_char);
					for(int j = 0; j < 4; j++){
						curr_word[j] = '\0';
					}
					curr_word_index = 0;
				}

				// TODO : read the line on top
				for(int j = i - 3; j <= i ; j++){
					char tmp = prev_line[j];
					if(isdigit(tmp)){
						printf("%c", tmp);
					}
					else{
						break;
					}
				}
				printf(" ");
				
				if(isdigit(prev_line[i + 1])){
					printf("xxx");
				}
			}
			// detect word 
			else if(isdigit(curr_char)){
				curr_word[curr_word_index] = curr_char;
				curr_word_index++;
			}
			// clear word if punctuation
			else {
				if(true == include_next && curr_word[0] != '\0'){
					// printf("%c%s ", curr_line[i - curr_word_index - 1], curr_word);				
				}
				include_next = false;
				curr_word_index = 0;
				for(int k = 0; k < 4; k++){
					curr_word[k] = '\0';
				}
			}
		}
		memcpy(prev_line, curr_line, line_length);
		printf("\n");
	}
}
