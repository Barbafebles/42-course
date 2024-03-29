
#include "pipex.h"

/*open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid*/

//open
int fT_open(const char *file, int flags);

//close 
int close(int fd);

//write
ssize_t write(int fd, const void *buf, size_t count);

//malloc
void *malloc(size_t size);

//free 
void free(void *ptr);

//perror
void perror(const char *s);

//strerror
char *strerror(int errnum);

//access 
int access(const char *pathname, int mode);

//dup
int dup(int oldfold);

// drup2 
int dup2(int oldfd, int newfd);

// execve
int execve(const char *filename, char *const argv[], char *const envp[]);

// exit
void exit(int status);

// fork
pid_t fork(void);

// pipe
int pipe(int pipefd[2]);

// unlink
int unlink(const char *pathname);

// wait
pid_t wait(int *wstatus);

// waitpid
pid_t waitpid(pid_t pid, int *wstatus, int options);

