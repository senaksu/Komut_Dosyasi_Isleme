#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "fields.h"
#include "jval.h"
#include "dllist.h"
#define MAX_COMMAND_LENGTH 1000
#define MAX_BUFFER_SIZE 10000

void processCommand(char *command, JRB output) {
    char cmd[MAX_COMMAND_LENGTH], arg1[MAX_COMMAND_LENGTH], arg2[MAX_COMMAND_LENGTH];
    int numArgs = sscanf(command, "%s %s %s", cmd, arg1, arg2);
    if (numArgs >= 2) {
        if (strcmp(cmd, "Yaz") == 0) {
            int numChars = atoi(arg1);
            char character = arg2[0];
            for (int i = 0; i < numChars; i++) {
                fprintf(stdout, "%c", character);
                JRB_insert_str(output, strdup(&character), new_jval_i(1));
            }
        } else if (strcmp(cmd, "Sil") == 0) {
            int numChars = atoi(arg1);
            char character = arg2[0];
            JRB node;
            while ((node = jrb_find_str(output, &character)) != NULL && numChars > 0) {
                fprintf(stdout, "Deleted: %c\n", character);
                JRB_delete_node(node);
                numChars--;
            }
        } else if (strcmp(cmd, "Sonagit") == 0) {
            fprintf(stdout, "Go to end\n");
            jrb_free_tree(output);
            output = make_jrb();
        } else if (strcmp(cmd, "Dur") == 0) {
            fprintf(stdout, "Finish\n");
            jrb_free_tree(output);
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

    JRB output = make_jrb();
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        processCommand(buffer, output);
    }

    fclose(inputFile);
    fclose(outputFile);
    jrb_free_tree(output);

    return 0;
}