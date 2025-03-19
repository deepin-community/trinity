#include <sys/vt.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <linux/serial.h>
#include <termios.h>

#include "utils.h"
#include "ioctls.h"

#ifndef HAVE_TERMIOS2
typedef unsigned char   cc_t;
typedef unsigned int    speed_t;
typedef unsigned int    tcflag_t;

#ifndef NCCS
#define NCCS 19
#endif
struct termios2 {
        tcflag_t c_iflag;               /* input mode flags */
        tcflag_t c_oflag;               /* output mode flags */
        tcflag_t c_cflag;               /* control mode flags */
        tcflag_t c_lflag;               /* local mode flags */
        cc_t c_line;                    /* line discipline */
        cc_t c_cc[NCCS];                /* control characters */
        speed_t c_ispeed;               /* input speed */
        speed_t c_ospeed;               /* output speed */
};
#endif

static const struct ioctl vt_ioctls[] = {
	IOCTL(VT_OPENQRY),
	IOCTL(VT_GETMODE),
	IOCTL(VT_SETMODE),
	IOCTL(VT_GETSTATE),
	IOCTL(VT_SENDSIG),
	IOCTL(VT_RELDISP),
	IOCTL(VT_ACTIVATE),
	IOCTL(VT_WAITACTIVE),
	IOCTL(VT_DISALLOCATE),
	IOCTL(VT_RESIZE),
	IOCTL(VT_RESIZEX),
	IOCTL(VT_LOCKSWITCH),
	IOCTL(VT_UNLOCKSWITCH),
	IOCTL(VT_GETHIFONTMASK),
	IOCTL(VT_WAITEVENT),
	IOCTL(VT_SETACTIVATE),

	IOCTL(GIO_FONT),
	IOCTL(PIO_FONT),
	IOCTL(GIO_FONTX),
	IOCTL(PIO_FONTX),
	IOCTL(PIO_FONTRESET),
	IOCTL(GIO_CMAP),
	IOCTL(PIO_CMAP),
	IOCTL(KIOCSOUND),
	IOCTL(KDMKTONE),
	IOCTL(KDGETLED),
	IOCTL(KDSETLED),
	IOCTL(KDGKBTYPE),
	IOCTL(KDADDIO),
	IOCTL(KDDELIO),
	IOCTL(KDENABIO),
	IOCTL(KDDISABIO),
	IOCTL(KDSETMODE),
	IOCTL(KDGETMODE),
	IOCTL(KDMAPDISP),
	IOCTL(KDUNMAPDISP),
	IOCTL(GIO_SCRNMAP),
	IOCTL(PIO_SCRNMAP),
	IOCTL(GIO_UNISCRNMAP),
	IOCTL(PIO_UNISCRNMAP),
	IOCTL(GIO_UNIMAP),
	IOCTL(PIO_UNIMAP),
	IOCTL(PIO_UNIMAPCLR),
	IOCTL(KDGKBMODE),
	IOCTL(KDSKBMODE),
	IOCTL(KDGKBMETA),
	IOCTL(KDSKBMETA),
	IOCTL(KDGKBLED),
	IOCTL(KDSKBLED),
	IOCTL(KDGKBENT),
	IOCTL(KDSKBENT),
	IOCTL(KDGKBSENT),
	IOCTL(KDSKBSENT),
	IOCTL(KDGKBDIACR),
	IOCTL(KDSKBDIACR),
	IOCTL(KDGKBDIACRUC),
	IOCTL(KDSKBDIACRUC),
	IOCTL(KDGETKEYCODE),
	IOCTL(KDSETKEYCODE),
	IOCTL(KDSIGACCEPT),
#ifdef KDGKBMUTE
	IOCTL(KDGKBMUTE),
#endif
#ifdef KDSKBMUTE
	IOCTL(KDSKBMUTE),
#endif
	IOCTL(KDKBDREP),
	IOCTL(KDFONTOP),

	IOCTL(TCGETS),
	IOCTL(TCSETS),
	IOCTL(TCSETSW),
	IOCTL(TCSETSF),
	IOCTL(TCGETA),
	IOCTL(TCSETA),
	IOCTL(TCSETAW),
	IOCTL(TCSETAF),
	IOCTL(TCSBRK),
	IOCTL(TCXONC),
	IOCTL(TCFLSH),
	IOCTL(TIOCEXCL),
	IOCTL(TIOCNXCL),
	IOCTL(TIOCSCTTY),
	IOCTL(TIOCGPGRP),
	IOCTL(TIOCSPGRP),
	IOCTL(TIOCOUTQ),
	IOCTL(TIOCSTI),
	IOCTL(TIOCGWINSZ),
	IOCTL(TIOCSWINSZ),
	IOCTL(TIOCMGET),
	IOCTL(TIOCMBIS),
	IOCTL(TIOCMBIC),
	IOCTL(TIOCMSET),
	IOCTL(TIOCGSOFTCAR),
	IOCTL(TIOCSSOFTCAR),
	IOCTL(FIONREAD),
	IOCTL(TIOCLINUX),
	IOCTL(TIOCCONS),
	IOCTL(TIOCGSERIAL),
	IOCTL(TIOCSSERIAL),
	IOCTL(TIOCPKT),
	IOCTL(FIONBIO),
	IOCTL(TIOCNOTTY),
	IOCTL(TIOCSETD),
	IOCTL(TIOCGETD),
	IOCTL(TCSBRKP),
	IOCTL(TIOCSBRK),
	IOCTL(TIOCCBRK),
	IOCTL(TIOCGSID),
#ifdef TCGETS2
	IOCTL(TCGETS2),
#endif
#ifdef TCSETS2
	IOCTL(TCSETS2),
#endif
#ifdef TCSETSW2
	IOCTL(TCSETSW2),
#endif
#ifdef TCSETSF2
	IOCTL(TCSETSF2),
#endif
#ifdef TIOCGRS485
	IOCTL(TIOCGRS485),
#endif
#ifdef TIOCSRS485
	IOCTL(TIOCSRS485),
#endif
	IOCTL(TIOCGPTN),
	IOCTL(TIOCSPTLCK),
#ifdef TIOCGDEV
	IOCTL(TIOCGDEV),
#endif
#ifdef TCGETX
	IOCTL(TCGETX),
#endif
#ifdef TCSETX
	IOCTL(TCSETX),
#endif
#ifdef TCSETXF
	IOCTL(TCSETXF),
#endif
#ifdef TCSETXW
	IOCTL(TCSETXW),
#endif
#ifdef TIOCSIG
	IOCTL(TIOCSIG),
#endif
#ifdef TIOCVHANGUP
	IOCTL(TIOCVHANGUP),
#endif
#ifdef TIOCGPKT
	IOCTL(TIOCGPKT),
#endif
#ifdef TIOCGPTLCK
	IOCTL(TIOCGPTLCK),
#endif
#ifdef TIOCGEXCL
	IOCTL(TIOCGEXCL),
#endif

	IOCTL(FIONCLEX),
	IOCTL(FIOCLEX),
	IOCTL(FIOASYNC),
	IOCTL(TIOCSERCONFIG),
	IOCTL(TIOCSERGWILD),
	IOCTL(TIOCSERSWILD),
	IOCTL(TIOCGLCKTRMIOS),
	IOCTL(TIOCSLCKTRMIOS),
	IOCTL(TIOCSERGSTRUCT),
	IOCTL(TIOCSERGETLSR),
	IOCTL(TIOCSERGETMULTI),
	IOCTL(TIOCSERSETMULTI),
	IOCTL(TIOCMIWAIT),
	IOCTL(TIOCGICOUNT),
	IOCTL(FIOQSIZE),
};

static const char *const vt_devs[] = {
	"/dev/vc/0",
	"tty",
	"ttyS",
	"/dev/tty",
	"/dev/console",
	"/dev/ptmx",
	"vcs",
};

static const struct ioctl_group vt_grp = {
	.devtype = DEV_CHAR,
	.devs = vt_devs,
	.devs_cnt = ARRAY_SIZE(vt_devs),
	.sanitise = pick_random_ioctl,
	.ioctls = vt_ioctls,
	.ioctls_cnt = ARRAY_SIZE(vt_ioctls),
};

REG_IOCTL_GROUP(vt_grp)
