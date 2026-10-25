#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// stdio -> fprintf, stderr, perror
// fcntl.h -> file control O_WRONLY, O_CREAT
// unistd.h -> standard symbolic constants and system calls
// 	       like close()
//
// 0666 -> an octal constant that establishes read and write
//         permissions across owner, group, and other classes
//         subject to umask modification.
int main(int argc, char *argv[]) {
	// check for an arg
	// argc is the number of args
	// a `touch` program has 2, touch, and the new filename
	// if not provided tell an error msg
	// if a name is provided, create it
	int fd;

	if (argc < 2) {
		fprintf(stderr, "If you want to create a file, name one.");
		return 1;
	}

	char *filename = argv[1];
	// the open syscall 
	fd = open(filename, O_WRONLY | O_CREAT, 0666);
	if (fd == -1) {
		perror("can't open that ...");
		return 1;
	}

	close(fd);
	return 0;
}
