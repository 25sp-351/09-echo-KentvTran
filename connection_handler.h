#ifndef ECHO_HANDLER_H
#define ECHO_HANDLER_H

void handle_echo(int client_fd);
void* handle_connection_thread(void* arg);

#endif
