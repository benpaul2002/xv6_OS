# xv6 OS

# Specification 1: syscall tracing

1. In proc.h, added a mask variable (int) to struct proc.
2. In proc.c, added the line -
        **np->mask = p->mask;**
to fork() function so as to copy the trace mask from the parent to the child process.
3. In syscall.c, added the line -
        **extern uint64 sys_trace(void);**
to the list of function prototypes.
Also added **sys_trace** to the array of syscalls.
Created an array **syscall_names** containing the names of all the syscalls and another array **argnums** containing the number of arguments that each syscall takes.
    
    In syscall() function, added appropriate code to display the strace details when the mask of the process matches the mask set during input.
    
4. In syscall.h, added **SYS_trace** as the 22nd syscall.
5. In sysproc.c, added the **sys_trace** function.
6. Created user program **strace.c**, which contains the main code for the syscall.
7. Updated makefile for strace.c program.
8. In user.h, added the function prototype **int trace(int);** 
9. In usys.pl, added the line **entry("trace");**

# Specification 2: Scheduling

## a. First Come First Served (FCFS)

1. Updated makefile to allow for the SCHEDULER parameter (if left blank, the parameter takes the value "RR", which is the default round robin scheduler).
2. In proc.h, added the **ctime** variable to struct proc. It stores the creation time of the process.
3. In proc.c, initialized the ctime of a program to the current ticks in the program.
4. In proc.c, added the main scheduling code for FCFS. This only runs if the SCHEDULER parameter was set to "FCFS".

## b. Priority Based Scheduler (PBS)

1. In proc.h, added the **static_priority** and **schedule_count** variables to struct proc. They store the static priority of the process and the number of times the process was scheduled.
2. In proc.c, added the **change_priority** function to change the priority of the process for the set_priority() syscall.
    
    Also added the **time_updates** function to update the sleeping or running time of the process at each tick of the clock.
    
    Added the main scheduling code for PBS in the scheduler function.
    
3. Created user program **setpriority.c.**
4. Added **set_priority** syscall, similar to how spec 1 was done.
