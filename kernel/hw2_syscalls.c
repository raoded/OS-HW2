#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
/*
int sys_enable_logging(int size) {
	if(size < 0 || logger_enabled) {
		return -EINVAL;
	}

	if(logs.logger_queue != NULL){
		kfree(logs.logger_queue);
		logs.logger_queue = NULL;
	}
	
	logs.logger_queue = kmalloc(sizeof(cs_log)*size, GFP_KERNEL);
	if(logs.logger_queue == NULL){
        return -ENOMEM;
    }
	logs.logger_max_size = size;
	logs.logger_next_index = 0
	
	logger_enabled = 1;
	
    return 0;
}

int sys_disable_logging () {
    if(!logger_enabled) {
		return -EINVAL;
	}
	
	logger_enabled = 0;

    return 0;
}

int sys_get_logger_records(cs_log* user_mem) {
	if(user_mem == NULL) {
		return -ENOMEM;
	}
	
	if(copy_to_user(user_mem, logs.logger_queue, logs.logger_next_index * sizeof(cs_log) )){ //return 0 on sucess
        return -ENOMEM;
    }
	
	logger_next_index = 0;
	
	return 0;
}
*/