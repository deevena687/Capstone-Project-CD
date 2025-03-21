#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    char name[50];
    int priority;
    int duration;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(char *name, int priority, int duration) {
    if (task_count < MAX_TASKS) {
        strcpy(tasks[task_count].name, name);
        tasks[task_count].priority = priority;
        tasks[task_count].duration = duration;
        task_count++;
    } else {
        printf("Task list is full!\n");
    }
}

int compare_tasks(const void *a, const void *b) {
    return ((Task *)b)->priority - ((Task *)a)->priority;
}

void schedule_tasks() {
    qsort(tasks, task_count, sizeof(Task), compare_tasks);
    printf("\nScheduled Tasks (Highest Priority First):\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task: %s, Priority: %d, Duration: %d min\n", tasks[i].name, tasks[i].priority, tasks[i].duration);
    }
}

void compile_script() {
    char script[100];
    printf("\nEnter task script (format: TaskName Priority Duration):\n");
    while (scanf("%s %d %d", script, &tasks[task_count].priority, &tasks[task_count].duration) == 3) {
        add_task(script, tasks[task_count].priority, tasks[task_count].duration);
        if (getchar() == '\n') break;
    }
    schedule_tasks();
}

int main() {
    printf("Student Time Management Compiler\n");
    compile_script();
    return 0;
}