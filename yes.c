#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototype
void printHelp();

int main(int argc, char *argv[]) {
    // The message to print. Default is "y".
    const char *message = "y";
    
    // If there is at least one argument (excluding program name), use it as the message.
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            printHelp();
            return 0; // Exit after displaying help
        }
        else if (strcmp(argv[1], "--version") == 0) {
            printf("yes (Your Version)\n");
            return 0; // Exit after displaying version
        }
        else {
            // Concatenate all arguments into a single string
            int message_length = 0;
            for (int i = 1; i < argc; i++) {
                message_length += strlen(argv[i]) + 1; // +1 for space or null terminator
            }
            char *temp_message = malloc(message_length);
            strcpy(temp_message, argv[1]);
            for (int i = 2; i < argc; i++) {
                strcat(temp_message, " ");
                strcat(temp_message, argv[i]);
            }
            message = temp_message;
        }
    }
    while (1) {
        printf("%s\n", message);
        fflush(stdout);
        usleep(1000);
    }
    
    return 0;
}

void printHelp() 
{
    printf("Usage: yes [STRING]...\n"
           "  or:  yes OPTION\n"
           "Repeatedly output a line with all specified STRING(s), or 'y'.\n\n"
           "  --help        display this help and exit\n"
           "  --version     output version information and exit\n");
}
