#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct{
    char description[50];
    bool isDone;
}Task;


int addTask();
void printTasks();

int menu();
void menuOption(int option);

void cleanBuffer();


Task taskList[100];
int taskAmount = 0;

#define SUCCESS 0
#define FAIL 1

int main(void){

    while(1){

        int option = menu();
        menuOption(option);
    }

    return 0;
}


/* addTask()
*
*   moves you to a screen where the app ask you to add a task.
*   the user enters a task name and that task is added to the tasklist.    
*
*/


int addTask(){

    Task newTask;

    newTask.isDone = false;
    newTask.description[0] = '\0';

    printf("\nWrite description of your new task: ");

        if(fgets(newTask.description, sizeof(newTask.description), stdin) == NULL){
            return FAIL;
        }
        

    int index = strcspn(newTask.description, "\n");
    newTask.description[index] = '\0';

    taskList[taskAmount] = newTask;
    taskAmount++;

    return SUCCESS;
}


/* printTasks()
*
*   prints out a list of all the added tasks and their status.
*   
*/


void printTasks(){

    printf("These are all your tasks (press 1 to exit)\n");

    for(int i = 0; i < taskAmount; i++){
        printf("\n%s: ", taskList[i].description);

        if(taskList[i].isDone == false){
            printf("Not Done\n");
        }else{
            printf("Done!!");
        }
    }

    int exit = 0;
    while(exit != 1){
        scanf("%d", &exit);
    }
    return;
}


/* menu()
*
*   creates the mainframe of the to do list. Asks for a number which redirects
*    you to another frame by calling another function.   
*
*/


int menu(){

    system("cls");
    printf("Welcome to your personal To Do List: Press button (1-4)\n");
    printf("\n1. Add new Task\n");
    printf("2. Print out Tasks\n");

    int button;
    scanf("%d", &button);
    cleanBuffer();

    return button;
}


void menuOption(int option){
    system("cls");
    switch(option){
        case 1:
            while(addTask() == 1){printf("add task failed");}
            break;
        case 2:
            printTasks();
            break;
    }

    return;
}

/* cleanBuffer()
*
*      
*   
*
*/


void cleanBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
