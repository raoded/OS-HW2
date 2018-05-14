#include "hw2_syscalls.h"
#include <sched.h>
#include <limits.h>
#include <stdlib.h>


#define SIZE 12

int main()
{
    start_lottery_scheduler();
    start_orig_scheduler();
    set_max_tickets(2000);
	print_pool_level();
    return 0;

}
