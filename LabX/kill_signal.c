#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process: Καθορίζει handler για το signal
        signal(SIGUSR1, signal_handler);
        printf("Child waiting for signal...\n");
        pause(); // Περιμένει για signal
    } else {
        // Parent process: Στέλνει το signal
        sleep(1); // Βεβαιώνεται ότι το child είναι έτοιμο
        kill(pid, SIGUSR1);
        printf("Parent sent signal to child\n");
    }

    return 0;
}
