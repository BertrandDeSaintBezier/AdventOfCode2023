#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[])
{    
    char *puzzle_filename = argv[1];

    FILE *puzzle_fptr = fopen(puzzle_filename, "r");

    if (puzzle_fptr == NULL)
    {
        printf("Error: could not open file %s", puzzle_filename);
        return 1;
    }

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    char curr;
    char digits[3] = { 'a', 'a', '\0'};

    int temp = 0;
    int sum = 0;

    while (fgets(buffer, MAX_LENGTH, puzzle_fptr))
    {
	for(int i = 0; i < strlen(buffer); i++){
	    curr = *(buffer + i);
	    if(isdigit(curr)){
		digits[0] = curr;
		break;
	    }
	}

	for(int i = strlen(buffer); i >= 0; i--){
	    curr = buffer[i];
	    if(isdigit(curr)){
		digits[1] = curr;
		break;
	    }
	}
	sscanf(digits, "%d", &temp);
	printf("Adding %d to %d\n", temp, sum);
	sum += temp;
	digits[0] = 'a';
    }

    printf("Done decoding. Result is %d", sum);

    // close the files
    fclose(puzzle_fptr);

    return 0;
}
