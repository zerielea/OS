#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // Για την συνάρτηση wait()

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();  // Δημιουργία νέου διαδικαστικού

        if (pid == 0) {
            // Child process: Ο κάθε παιδί εκτελεί αυτή την εντολή
            printf("Child process with PID: %d\n", getpid());
            return 0; // Τερματισμός του child process
        } else if (pid > 0) {
            // Parent process: Περιμένει το κάθε child να τελειώσει
            wait(NULL); // Περιμένει για το child process
        } else {
            // Σε περίπτωση αποτυχίας του fork()
            perror("fork failed");
            return 1;
        }
    }
    return 0;
}
