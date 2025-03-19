/*
 * SYSCALL_DEFINE0(restart_syscall)
 */
#include "sanitise.h"

struct syscallentry syscall_restart_syscall = {
	.name = "restart_syscall",
	.num_args = 0,
	.flags = AVOID_SYSCALL,
};
