/*
Name: Abhishek Jain
ID: 1001759977
*/

#define _GNU_SOURCE

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 5     // Mav shell only supports five arguments

static void handle_signal (int sig )
{
    switch( sig )
    {
        case SIGINT:
        // Caught a SIGINT
        break;

        case SIGTSTP:
        // Caught a SIGTSTP
        break;

        default:
        // Unable to determine the signal
        break;
    }

}

int main()
{
    struct sigaction act;

    // Zero out the sigaction struct
    memset (&act, '\0', sizeof(act));

    // Set the handler to use the function handle_signal()
    act.sa_handler = &handle_signal;

    // Install the handler for SIGINT and SIGTSTP and check the return value.

    if (sigaction(SIGINT , &act, NULL) < 0)
        {
            perror ("sigaction: ");
            return 1;
        }

    if (sigaction(SIGTSTP , &act, NULL) < 0)
        {
            perror ("sigaction: ");
            return 1;
        }

    char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );
    char path0[50],path1[50],path2[50],path3[50],path4[50],path5[50],p[100];
    char e[50][20];
    int x=-1,z,r=0,w,c=-1,y=0;
    int g[50];

    while( 1 )
        {
            // Print out the msh prompt
            printf ("msh> ");

            // Read the command from the commandline.  The
            // maximum command that will be read is MAX_COMMAND_SIZE
            // This while command will wait here until the user
            // inputs something since fgets returns NULL when there
            // is no input
            while( !fgets (cmd_str, MAX_COMMAND_SIZE, stdin) );

            // Parse input
            char *token[MAX_NUM_ARGUMENTS];

            int token_count = 0;

            // Pointer to point to the token
            // parsed by strsep
            char *arg_ptr;

            char *working_str  = strdup( cmd_str );

            // we are going to move the working_str pointer so
            // keep track of its original value so we can deallocate
            // the correct amount at the end
            char *working_root = working_str;

            // Tokenize the input strings with whitespace used as the delimiter
            while ( ( (arg_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) &&
              (token_count<MAX_NUM_ARGUMENTS))
              {
                  token[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
                  if( strlen( token[token_count] ) == 0 )
                    {
                        token[token_count] = NULL;
                    }
                  token_count++;
              }

            // Forks a child process
            pid_t child_pid = fork();
            int status;
            int token_index  = 0;

            if( child_pid == 0 )
                {
                    // Checking for all the tokens in the child process
                    for( token_index = 0; token_index < token_count; token_index ++ )
                    {
                        // Shell backgrounds the last suspended process
                        if(strcmp("bg",token[0])==0)
                            {
                                kill(child_pid,SIGCONT);
                            }

                        // Shell exits if user enters exit or quit
                        if(strcmp("exit",token[token_index])==0 || strcmp("quit",token[token_index])==0)
                            {
                                int flag=1;
                                exit(flag);
                            }
                        // Shell checks the command entered
                        // by the user
                        // in the necessary PATH order
                        // and executes the command. Displays
                        // command not found in case of invalid command.

                        strcpy(path0, "./");
                        strcpy(path1, "/usr/local/bin/");
                        strcpy(path2, "/usr/bin/");
                        strcpy(path3, "/bin/");

                        int i,j;

                        if(token_count==4)
                            {
                                strcpy(path4,token[1]);
                                strcat(path4,token[2]);
                                strcat(path4,"\0");
                                strcpy(path5,"-");
                                for(i=1,j=1;i<8;i=i+2,j++)
                                {
                                    path5[j]=path4[i];
                                }
                                strcat(path5,"\0");
                                strcat(path0, token[0]);
                                execl(path0,token[0],path5,NULL);
                                strcat(path1, token[0]);
                                execl(path1,token[0],path5,NULL);
                                strcat(path2, token[0]);
                                execl(path2,token[0],path5,NULL);
                                strcat(path3, token[0]);
                                execl(path3,token[0],path5,NULL);
                                printf("%s \n",path5);
                            }

                        else

                        if(token_count==5)
                            {
                                strcpy(path4,token[1]);
                                strcat(path4,token[2]);
                                strcat(path4,token[3]);
                                strcat(path4,"\0");
                                strcpy(path5,"-");

                                for(i=1,j=1;i<8;i=i+2,j++)
                                    {
                                        path5[j]=path4[i];
                                    }

                                strcat(path5,"\0");
                                strcat(path0, token[0]);
                                execl(path0,token[0],path5,NULL);
                                strcat(path1, token[0]);
                                execl(path1,token[0],path5,NULL);
                                strcat(path2, token[0]);
                                execl(path2,token[0],path5,NULL);
                                strcat(path3, token[0]);
                                execl(path3,token[0],path5,NULL);
                                printf("%s \n",path5);
                            }

                        else

                        if(token_count==6)
                            {
                                strcpy(path4,token[1]);
                                strcat(path4,token[2]);
                                strcat(path4,token[3]);
                                strcat(path4,token[4]);
                                strcat(path4,"\0");
                                strcpy(path5,"-");

                                for(i=1,j=1;i<8;i=i+2,j++)
                                {
                                    path5[j]=path4[i];
                                }

                                strcat(path5,"\0");
                                strcat(path0, token[0]);
                                execl(path0,token[0],path5,NULL);
                                strcat(path1, token[0]);
                                execl(path1,token[0],path5,NULL);
                                strcat(path2, token[0]);
                                execl(path2,token[0],path5,NULL);
                                strcat(path3, token[0]);
                                execl(path3,token[0],path5,NULL);
                                printf("%s \n",path5);
                            }

                        else

                        if(token_count==3 || token_count==2)
                        {
                            if(strcmp(token[0],"cd")==0)
                            {
                                exit(0);
                            }
                            if(strcmp(token[0],"history")==0)
                                {
                                    exit(0);
                                }

                            strcat(path0, token[token_index]);
                            execl(path0,token[token_index],token[token_index+1],NULL);

                            strcat(path1, token[token_index]);
                            execl(path1,token[token_index],token[token_index+1],NULL);

                            strcat(path2, token[token_index]);
                            execl(path2,token[token_index],token[token_index+1],NULL);

                            strcat(path3, token[token_index]);
                            execl(path3,token[token_index],token[token_index+1],NULL);

                            if((strcmp("bg",token[token_index])!=0) && (strcmp("listpids",token[token_index])!=0))
                                {
                                    printf(token[token_index]);
                                    printf(": Command not found.\n");
                                }
                        }
                    }
                }

            // Checks for exit
            int flag=0;
            wait(&flag);

            if((flag/255) == 1 )
                {
                    exit(0);
                }

            // Shell continues to work
            // if user enters blank space
            if(token[0]==0)
                {
                    continue;
                }

            // Shell displays the pids
            // of the last 15 processes
            // spawned.
            if(strcmp(token[0],"listpids")!=0)
                {
                    c++;
                    g[c]=child_pid;
                }
            if(strcmp(token[0],"listpids")!=0)
                {
                    if(c>=15)
                    {
                        y++;
                    }
                }

            if(strcmp(token[0],"listpids")==0)
                {
                    if(c<15)
                        {
                            for(z=0;z<=c;z++)
                            {
                                printf("%d: %d \n",z,g[z]);
                            }
                        }

                    else

                    if(c>=15)
                        {
                            for(z=y,w=0;z<=c;z++,w++)
                            {
                                printf("%d: %d \n",w,g[z]);
                            }
                        }
                }

            // Shell supports navigating
            // through directories through cd.
            if(strcmp(token[0],"cd")==0)
                {
                    chdir(token[1]);
                }

            x++;
            strcpy(p,token[0]);
            strcat(p,"\0");
            strcpy(e[x],p);

            if(x>=15)
                {
                    r++;
                }
            // Stores the last 15 commands
            // in an array and displays it
            // if the user enters the command history.
            if(strcmp(token[0],"history")==0)
                {
                    if(x<15)
                        {
                            for(z=0;z<=x;z++)
                            {
                                printf("%d: %s \n",z,e[z]);
                            }
                        }

                    else

                    if(x>=15)
                        {
                            for(z=r,w=0;z<=x;z++,w++)
                            {
                                printf("%d: %s \n",w,e[z]);
                            }
                        }
                }

            waitpid( child_pid, &status, 0 );

            free( working_root );
        }

    return 0;
}
