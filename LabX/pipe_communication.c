#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    // Δημιουργία pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process: Διαβάζει από το pipe
        close(pipefd[1]); // Κλείσιμο του write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        // Parent process: Γράφει στο pipe
        close(pipefd[0]); // Κλείσιμο του read end
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    }

    return 0;
}
