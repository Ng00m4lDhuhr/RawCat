// Main source code file
#include "rawcat.h"
#include <iostream>


int main(int argc, char* argv[]){
	// Here we are to handle the CLI of user
	// No networking functionallity is to be written in main
	// Only call from rawcat.cpp file and rawcat.h
	std::cout << test() << std::endl;
	return EXIT_SUCCESS;
}


// TODO 
// [ ] read buffer 
// 	[ ] from file
// 	[ ] from base64 text string
//
// [ ] output 
// 	[ ] base64 string
// 		[ ] to a file
// 		[ ] to console
// 	[ ] raw data
// 		[ ] to a file
// 		[ ] to console

