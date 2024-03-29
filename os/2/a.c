#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char buffer[100];
    char input[] = "Hello, pipe!";

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        close(pipe_fd[1]);  // Close the write end of the pipe
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipe_fd[0]);  // Close the read end of the pipe
    } else {
        // Parent process
        close(pipe_fd[0]);  // Close the read end of the pipe
        write(pipe_fd[1], input, sizeof(input));
        printf("Parent sent: %s\n", input);
        close(pipe_fd[1]);  // Close the write end of the pipe
    }

    return 0;
}
