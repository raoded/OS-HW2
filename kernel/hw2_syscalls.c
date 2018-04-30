#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

void move_elements(task_t* found_task, int size);
int sys_enable_policy (pid_t pid, int size, int password);
int sys_disable_policy (pid_t pid, int password);
int sys_set_process_capabilities(pid_t pid, int new_level, int password);
int sys_get_process_log(pid_t pid, int size, struct forbidden_activity_info* user_mem);

/*
void move_elements(task_t* found_task, int size){
      int i;
      int remainingElements = found_task->forbidden_next_index - size;
      for(i = 0; i < remainingElements; i++){
          found_task->forbidden_queue[i] = found_task->forbidden_queue[i+size];
      }
      found_task->forbidden_next_index -= size;
}
*/

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