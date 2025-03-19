/*
 * SYSCALL_DEFINE4(utimensat, int, dfd, const char __user *, filename,
	 struct timespec __user *, utimes, int, flags)
 */
#include <fcntl.h>
#include "sanitise.h"

static unsigned long utimensat_flags[] = {
	AT_SYMLINK_NOFOLLOW,
};

struct syscallentry syscall_utimensat = {
	.name = "utimensat",
	.num_args = 4,
	.arg1name = "dfd",
	.arg1type = ARG_FD,
	.arg2name = "filename",
	.arg2type = ARG_PATHNAME,
	.arg3name = "utimes",
	.arg3type = ARG_ADDRESS,
	.arg4name = "flags",
	.arg4type = ARG_LIST,
	.arg4list = ARGLIST(utimensat_flags),
	.flags = NEED_ALARM,
};
