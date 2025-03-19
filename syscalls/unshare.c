/*
 * SYSCALL_DEFINE1(unshare, unsigned long, unshare_flags)
 */
#include <linux/sched.h>
#include "sanitise.h"

static unsigned long unshare_flags[] = {
	CLONE_THREAD, CLONE_FS, CLONE_NEWNS, CLONE_SIGHAND,
	CLONE_VM, CLONE_FILES, CLONE_SYSVSEM, CLONE_NEWUTS,
	CLONE_NEWIPC, CLONE_NEWNET, CLONE_NEWUSER, CLONE_NEWPID,
};

struct syscallentry syscall_unshare = {
	.name = "unshare",
	.num_args = 1,
	.arg1name = "unshare_flags",
	.arg1type = ARG_LIST,
	.arg1list = ARGLIST(unshare_flags),
};
