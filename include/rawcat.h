// Header file(s) for the project
#ifndef RAWCAT_H
#define RAWCAT_H

// Networking Libs
#include <sys/socket.h>
#include <netinet/ip.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

// C++ Libs
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>

using byte = uint8_t;

// testing function only
const char* test(void);
/*
bool InterfaceHook ( Interface& device, int sockfd );
int InterfaceHook ( Interface& device );
int capture ( Interface device, void* buffer, size_t size);
void* capture ( Interface device, size_t size );
*/
#endif

