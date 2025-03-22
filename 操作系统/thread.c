struct  context
{
int eid;
int esp;
int ebx; //....
};

enum proc_state {UNUSED,EMBRYO,SLEEPING,RUNNABLE,RUNNING,ZOMBIE};

struct proc
{
char *mem; // start of process memory
uint sz;// size of process memory
char* kstack;//bottom of kernel stack for this process

enum proc_state state;// process state
int pid;// process ID
struct proc *parent; // parent process
void *chan; // if non-zero, sleeping on chan
int killed;// if non-zero, have been killed
struct file *ofile[NOFILE];
struct inode *cwd;
struct  context context;
struct trapframe *tf;



};