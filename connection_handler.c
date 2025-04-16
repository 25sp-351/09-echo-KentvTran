#include "socket_utils.h"
#include "connection_handler.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern int verbose;  // Defined in main.c

//reads data from client and echoes it back
void handle_echo(int client_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
        
        if(bytes_read <= 0) break;
        
        if(write(client_fd, buffer, bytes_read) < 0) { 
            perror("write failed");
            break;
        }
        
        if(verbose) { 
            printf("Echoed: %s", buffer);
        }
    }
    printf("Client disconnected\n");
}

void* handle_connection_thread(void* arg) {
    int client_fd = *(int*)arg;
    free(arg);
    handle_echo(client_fd);
    close_connection(client_fd);
    return NULL;
}