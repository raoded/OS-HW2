#include "hw2_syscalls.h"
#include <sched.h>
#include <limits.h>
#include <stdlib.h>


#define SIZE 12

int main()
{
	printf("start_lottery_scheduler:\n");
    start_lottery_scheduler();
	printf("start_orig_scheduler:\n");
    start_orig_scheduler();
	printf("set_max_tickets:\n");
    set_max_tickets(2000);
	//printf("start_lottery_scheduler:\n");
	//print_pool_level();
    return 0;

}
