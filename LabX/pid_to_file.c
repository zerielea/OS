#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pid_output.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
        printf("Child process with PID: %d\n", getpid());  // Προσθήκη για έλεγχο
    } else {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
        printf("Parent process with PID: %d\n", getpid());  // Προσθήκη για έλεγχο
    }

    fclose(file);
    return 0;
}

