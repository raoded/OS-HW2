#ifndef HW1_WRAPPER
#define HW1_WRAPPER

#include <errno.h>
#include <termios.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
 pid_t prev;
 pid_t next;
 int prev_priority;
 int next_prioroty;
 int prev_policy;
 int next_policy;
 long switch_time;
} cs_log;

int enable_logging(int size) {
	int __res;
	__asm__(
	"int $0x80;"
	: "=a" (__res)
	: "0" (243), "b" (size)
	: "memory"
	);
	if ((__res) < 0) {
		errno = (-__res); 
		return -1;
	}
	return __res;
} 

int disable_logging() {
	int __res;
	__asm__(
		"int $0x80;"
		: "=a" (__res)
		: "0" (244)
		:"memory"
		);
	if ((__res) < 0) {
		errno = (-__res); 
		return -1;
	}
	return __res;
}

int get_logger_records(cs_log* user_mem) {
	int __res;
	__asm__(
	"int $0x80;"
	: "=a" (__res)
	: "0" (245), "b" (user_mem)
	: "memory"
	);
	if ((__res) < 0) {
		errno = (-__res); 
		return -1;
	}
	return __res;
}

int start_lottery_scheduler() {
	int __res;
	__asm__(
	"int $0x80;"
	: "=a" (__res)
	: "0" (246)
	: "memory"
	);
	if ((__res) < 0) {
		errno = (-__res); 
		return -1;
	}
	return __res;
}

int start_orig_scheduler() {
	int __res;
	__asm__(
	"int $0x80;"
	: "=a" (__res)
	: "0" (247)
	: "memory"
	);
	if ((__res) < 0) {
		errno = (-__res); 
		return -1;
	}
	return __res;
}

void set_max_tickets(int max_tickets) {
	if(max_tickets<1) {
		return;
	}
	
	__asm__(
	"int $0x80;"
	: "0" (248), "b" (max_tickets)
	: "memory"
	);
}

#endif