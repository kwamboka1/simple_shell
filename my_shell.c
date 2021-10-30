#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 *main - Entry point
  *read_s2 - strint to accept the command keyed in by user
  *type_prompt - displaying a prompt
  *
  *@par - parameters
  *@s2 - the command
  *@s1 - the PATH
  *return - Always 0.
  */
 
 void read_s2(char s1[], char *par[])
 {
         char line[1024];
         int count = 0, i = 0, j = 0;
         char *array[100], *pch;
 
         /**read one line*/
         for (;;)
         {
                 int c = fgetc(stdin);

                line[count++] = (char) c;
                if (c == '\n')
                        break;

        }

        if (count == 1)

                 return;

        pch = strtok(line, "\n");

/**parse the line into words*/
        while (pch != NULL)
        {
                 array[i++] = strdup(pch);
                pch = strtok(NULL, "\n");

        }
        /**first word is the command*/
        strcpy(s1, array[0]);
 
         /** others are parameters */
        for (;; j++)                par[j] = array[j];
        par[i] = "\0"; /**NULL terminates the parameters list */

 }
 
 void type_prompt(void)
 {
         static int first_time = 1;
 
         if (first_time)
         {               /**clear screen for the first time*/
                 const char *CLEAR_SCREEN = "\033[1;1H \033[2J";

                write(STDOUT_FILENO, CLEAR_SCREEN, 12);
                first_time = 0;
        }
        write(1, "#cisfun$ ", 9); /**display prompt*/
}

 int main(void)
{
        char s1[100], s2[100], *parameters[20];

        /** environment variable */
        char *envp[] = {(char *) "PATH=/bin", 0};

        while (1)
        {                                       /**repeat forever*/
                type_prompt();                  /**display prompt on screen*/
                read_s2(s2, parameters); /**read input from terminal*/
                if (fork() != 0)                /**parent*/
                        wait(NULL);                     /**wait for child*/
                 else
                 {
                        strcpy(s1, "/bin/");
                        strcat(s1, s2);
                         execve(s1, parameters, envp); /**execute command*/
                }
                 if (strcmp(s2, "exit") == 0)
                        break;
        }

        return (0);

}