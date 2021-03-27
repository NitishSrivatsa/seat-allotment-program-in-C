#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//declaring a structure
struct college
{
    int sl_num, cutoffrank, seats;
    char name[];
};

// Function which Stores college data from a file named "college.csv" into <colleges>. <num> is the number of colleges in the file(11 colleges for our program).
void read(int num, struct college *colleges[])
{
    FILE *file = fopen("college.csv", "r");//opening the file
    char line[100]; // Assume a line in the file is no longer than 100 characters.
    int i = 0;
    while (fgets(line, 100, file) != NULL)//to read line by line
    {
        struct college *c = malloc(sizeof(struct college));//allocating memory
	//storing values in the structure based on , separation
        c->sl_num = atoi(strtok(line, ","));//stores sl no which is column 1 in our csv file
        c->cutoffrank = atoi(strtok(NULL, ","));//cutoffrank(2nd column)
        c->seats = atoi(strtok(NULL, ","));//stores no of seats(3rd column)
        strcpy(c->name, strtok(NULL, "\n"));//stores name of college (4th column)
        colleges[i++] = c;//command used to store contents of next line of the file
    }
    fclose(file);//closing the file
}

// Writes <colleges> to a file names "colleges.csv". <num> is the number of colleges in <colleges>.
void write(int num, struct college *colleges[])
{
    FILE *f = fopen("college.csv", "w");
    int i;
    for (i = 0; i < num; i++)
    {
        fprintf(f, "%d,%d,%d,%s\n", colleges[i]->sl_num, colleges[i]->cutoffrank, colleges[i]->seats, colleges[i]->name);//used to rewrite contents to file.(this function is used after seat is allotted to reduce total no of seats)
    }
    fclose(f);
}

int main()
{
    int size = 11;//no of colleges in our file. used to pass as arguments to function
    int rank;
    char desired_clg[100];
    int j = 0;
    int k = 0;
    struct college *colleges[size];//creating a structure of size 11
    read(size, colleges);//reading contents of file and storing into the structure
    printf("Enter your rank:");//taking input of rank from user
    scanf("%d", &rank);
    printf("The eligible colleges are:\n");
 
    for (j = 0; j < size; j++)//loop used to display the eligible colleges
    {
        if (colleges[j]->cutoffrank > rank)
            printf("%s\n", colleges[j]->name);
}   
    int allotted = 0;
    while (!allotted)  //loop used to allow the user to enter a college from the list of colleges and check the conditions if the college input is one among the eligible college list and if seats no is not equal to zero, and display the corresp message.
    {
        printf("Select a college u desire:\n");   //taking input from user 
        scanf("%s", desired_clg);
        printf("Desired clg is:%s\n", desired_clg);
        for (k = 0; k < size; k++)//loop to check if seats !=0 and college is one among the eligible colleges
            if (colleges[k]->cutoffrank > rank && colleges[k]->seats != 0 && strcmp(colleges[k]->name, desired_clg) == 0)
            {
                puts("Congratulations,College allotted!");
                colleges[k]->seats = colleges[k]->seats – 1;  / /if seat is allotted, no of seats reduces by 1
                write(size, colleges);//rewriting to the file.
                allotted = 1;//if seat is allotted, int allotted changes to 1, so that the next if loop doesnt execute. if seat isnt allotted, then int allotted remains 0, then the next if loop executes
                break;
            }
        if (!allotted)//loop executes only if seat doesnt get allotted.
            puts("No seats available. Please try another one:");
    }

    return 0;
}
