#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define FOOBAR "\033c"

int number(void); // Func declar
int info(void); // Func declar 
int quits(void); // Func declar
int claf(void); // Func declar
int e_num(void); // Func declar 

int start(void)
{
    char prism_options[29] = "1) Number, 2) Info, 3) Quit";

    printf("Please enter one of the following\n\n%s: ", prism_options);
    char a = getchar(); 

    if (a == '1')
    {
        printf("Going to Numbers..."); 
        printf(FOOBAR); // Clear 
        number(); // Func call 
    }

    else if (a == '2')
    {
        printf("Going to Info..."); 
        printf(FOOBAR); // Clear 
        info(); // Func call 
    }

    else if (a == '3') 
    {
        printf("Going to Quit..."); 
        printf(FOOBAR); // Clear 
        quits(); // Func call 
    }

    else 
    {
        printf("Incorrect input please try again..."); 
        printf(FOOBAR); // Clear 
        start(); // Func call 
    }

    return (0); 
}

int number(void)
{ 
    FILE *rptr = fopen("read_num_file", "r"); // Read the file 

    char select_n[47] = "1) Add a Number, 2) Look at registry, 3) Exit";
    char s[2]; // To start the three options 
    char o[2]; // For option 3 
    char n[2]; // for else after option 3 
    int c; // For reading the file 

    printf("Welcome to the Menu..."); 
    printf("\n\nPlease select one of the following...\n\n%s", select_n);
    printf("\n\nSelecton: "); 

    while (getchar() != '\n') {} 

    fgets(s, 2, stdin);  

    if (strcmp(s, "1") == 0)
    {
        printf(FOOBAR); // Clear 
        e_num(); // Func call 
    }

    else if (strcmp(s, "2") == 0)
    {
        printf("\nLooking at registry...\n\n");    

        while((c = getc(rptr)) != EOF)
        {printf("%c", c);}

        printf("\n");
        fclose(rptr); // Close the file 
    }

    else if (strcmp(s, "3") == 0)
    {
        printf("\n\nAre you sure you want to exit?\n\nEnter (y) or (n)"); 
        printf("\n\nSelection: ");

        while (getchar() != '\n') {}

        fgets(o, 2, stdin);  

        if (strcmp(o, "y") == 0)
        {
            printf("Exiting...");
            printf(FOOBAR); // Clear 
            return (0);
        }

        else 
        {
            printf("Sorry you have not entered a correct input please try again..."); 
            printf(FOOBAR); // Clear 
            number(); // Func call 
        }

    }

    else 
    {
        printf("\n\nAre you sure you want to exit?\n\nEnter (y) or (n)"); 
        printf("\n\nSelection: "); 

        while (getchar() != '\n') {}

        fgets(n, 2, stdin);   

        if (strcmp(n, "y") == 0)
        {
            printf("Exiting...");
            printf(FOOBAR); // Clear 
            return (0); 
        }

        else 
        {
            printf("Sorry you have not entered a correct input please try again..."); 
            printf(FOOBAR); // Clear 
            number(); // Func call 
        }

    }

    return (0); 
}

int e_num(void)
{
    FILE *fptr = fopen("num_file_out", "a+"); // Append the file 
 
    if (!fptr) // Check if the file is there 
    {
        perror("fopen"); 
        return (-1); 
    }

    int b; 
    char num_input[30];
    char k[2]; 
    char f[2]; 

    printf("Would you like to see your phone book or wipe it?\n\n");
    printf("Enter (1) - to enter a number, (2) - see phone book, (3) - to wipe phone book or (4) - to return to menu");
    printf("\n\nSelection: ");  
    
    while (getchar() != '\n') {} 

    fgets(f, 2, stdin); 

    if (strcmp(f, "1") == 0)
    {
        printf("Please enter a phone number: ");

        while (getchar() != '\n') {} 

        fgets(num_input, 30, stdin);

        if (isdigit(num_input[0])) 
        {
            fputs(num_input, fptr);
            
            do 
            {
                printf("\n\nWould you like to look at your phone book?\n\nEnter (y) or (n): ");
                fgets(k, 2, stdin); 

                if (strcmp(k, "y") == 0) 
                {
                    printf("\nOk Here is your Phonebook...\n\n"); 
                    
                    fseek(fptr, 0, SEEK_SET); // To set the file at the start 
                    
                    while((b = getc(fptr)) != EOF)
                    {printf("%c", b);}
                    
                    printf("\n"); 
                    fclose(fptr); 
                }

                else if (strcmp(k, "n") == 0)
                {
                    printf("\n\nOk\n\nExiting program");
                    return (0); 
                }

                else 
                {
                    printf("\n\nYou have not entered a correct input\n\nPlease try again"); 
                    printf(FOOBAR); 
                }
            
            }
            while (strcmp(k, "y") != 0 && strcmp(k, "n") != 0);

        } 

        else 
        {
            printf("\n\nTry entering a number");   
            printf(FOOBAR); // Clear 
            e_num(); // Func call 
        }

    } 

    else if (strcmp(f, "2") == 0)
    {
        printf("\nOk Here is your Phonebook...\n\n"); 
                    
        fseek(fptr, 0, SEEK_SET); // To set the file at the start 
                    
        while((b = getc(fptr)) != EOF)
        {printf("%c", b);}
                    
        printf("\n"); 
        fclose(fptr);
    }

    else if (strcmp(f, "3") == 0)
    {
        printf("Ok lets wipe your phone book\n\n");
        fopen("num_file_out", "w"); 
    }

    else if (strcmp(f, "4") == 0)
    {
        printf("Going to menu");
        printf(FOOBAR);
        start(); 
    }
    
    else 
    {
        printf("Please enter a correct input"); 
        printf(FOOBAR); 
        e_num(); 
    }
    
    return (0); 
}

int info(void)
{
    char author[] = "Author: Delta Siv"; 
    char version[] = "Version: 0.0.3a"; 

    printf("Welcome to the Info menu...\n\n"); 
    printf("Printing out product info\n\n-----------------------------");  
    printf("\n\n%s\n\n%s\n", author, version);
    return (0); 
}

int quits(void)
{
    printf("Looks like you selected quit...\n\nAre you sure? ");
    printf("\n\nEnter (y) or (n): ");  
    char r = getchar(); 
    printf(FOOBAR); // Clear 

    if (r == 'n')
    {
        printf("Ok..."); 
        printf(FOOBAR); // Clear 
        start(); // Func call 
    }
    
    else if (r == 'y')
    {
        printf("Exiting...\n\n");
        printf(FOOBAR); // Clear 
        return (0); 
    }

    else 
    {
        printf("Please enter a valid input..."); 
        printf(FOOBAR); // Clear 
        quits(); // Func call 
    }
    
    return (0);
}

int main(int argc, char *argv[])
{
    char x[2]; 
    time_t start_time = time(NULL); // Start time of program 

    if (strcmp(argv[1], "--go") == 0)
    {

        do
        {
            printf("Welcome to the Number Logger!\n\n"); 
            printf("Would you like to go through a tutorial first?\n\n"); 
            printf("Enter (y) or (n): "); 
            fgets(x, 2, stdin); 

            if (strcmp(x, "y") == 0) 
            {
                claf(); // Func call 
                printf(FOOBAR); // Clear 
                printf("Please press Enter to continue..."); 
                getchar(); // Input for enter 
                printf(FOOBAR); // Clear 
                start(); // func call
            }

            else if (strcmp(x, "n") == 0)
            {
                printf("Please press Enter to continue..."); 
                getchar(); // Input for enter 
                printf(FOOBAR); // Clear 
                start(); // func call
            }

        }
        while (strcmp(x, "y") != 0 && strcmp(x, "n") != 0); 

    }

    sleep(3); // Sleep for 3,000 milliseconds 
    time_t end_time = time(NULL); // End time of program  
    printf(FOOBAR); // Clear 
    printf("Total time taken to execute program: %ld seconds\n", (end_time - start_time)); // Print total time 
    return (0); 
}

int claf(void)
{
    printf("Since you entered --help\n\n");
    printf("Heres how the application works\n\n");
    printf("When your done with this help menu press enter\n\n");
    printf("Then follow the instructions present\n\n");
    printf("Please input numerical digits only\n\n");
    sleep(7); // Sleep for 7,000 milliseconds 
    printf(FOOBAR); // Clear 
    return (0); 
}