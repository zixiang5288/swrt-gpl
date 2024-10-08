#include <string.h>
#include "do_multi.h"

int main(int argc, char *argv[])
{
	char *progname;
	int ret = 0;

	progname = basename(argv[0]);

#ifdef AR_DEBUG
	if (strcmp(progname, "80211debug") == 0)
		ret = a80211debug_init(argc, argv);
#endif
#ifndef HAVE_MICRO
	if (strcmp(progname, "80211stats") == 0)
		ret = a80211stats_init(argc, argv);
	if (strcmp(progname, "athchans") == 0)
		ret = athchans_init(argc, argv);
	if (strcmp(progname, "athctrl") == 0)
		ret = athctrl_init(argc, argv);
#endif
#ifdef AR_DEBUG
	if (strcmp(progname, "athdebug") == 0)
		ret = athdebug_init(argc, argv);
#endif
#ifndef HAVE_MICRO
	if (strcmp(progname, "athkey") == 0)
		ret = athkey_init(argc, argv);
	if (strcmp(progname, "athstats") == 0)
		ret = athstats_init(argc, argv);
#endif
	if (strcmp(progname, "wlanconfig") == 0)
		ret = wlanconfig_init(argc, argv);
#ifndef HAVE_MICRO
	if (strcmp(progname, "ath_info") == 0)
		ret = athinfo_init(argc, argv);
#endif

	return ret;
}
