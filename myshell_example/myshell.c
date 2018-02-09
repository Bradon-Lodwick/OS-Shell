/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Define boolean values
typedef int bool;
#define true 1
#define false 0

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // The path to the README file
    char* readme_path;
    readme_path = "../README.md";  // Change this when this file is moved

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    // Parse the commands provided using argc and argv

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Removes trailing newline character from buffer
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        
        // Perform string tokenization to get the command and argument
        // The character array that will hold the buffer arguments after string tokenization
        char* buffer_arg;
        buffer_arg = strtok(buffer, " ");
        
        // Used to assign the first value into the command variable
        bool first_arg = true;
        // Loop through the arguments
        while(buffer_arg)
        {
            if(first_arg)
            {
                // Set command to first buffer argument
                strcpy(command, buffer_arg);
                // Change so the command won't be overwritten in next loops
                first_arg = false;               
            }
            else
            {
                // TODO make it so multiple arguments work
                strcpy(arg, buffer_arg);
            }
            // Go to the next argument
            buffer_arg = strtok(NULL, " ");
        }

        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            // your code here
        }

        // help command -- send the contents of the README file to the terminal
        else if (strcmp(command, "help") == 0)
        {
            FILE *README;
            README = fopen(readme_path, "r");
            // Tries to open the readme file
            if(README)
            {
                // The character that is read in from the file
                int c;
                while((c = getc(README)) != EOF)
                {
                    // Outputs the character
                    putchar(c);
                }
            }
            // If the readme file could not open
            else
            {
                fputs("Could not find README.md file\n", stderr);
            }
           
            fclose(README);
        }
        
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}