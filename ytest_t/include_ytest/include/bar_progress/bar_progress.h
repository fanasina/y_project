#ifndef __BAR_PROGRESS_H__
#define __BAR_PROGRESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>



/*
 * Prepares screen for progress bar.
 */
void bar_progress_start(void);

void bar_progress_step_msg(int step_progress, int all_progress, char *msg, char fill_bar, char fill_dot, int colored);

/*
 * progress  value 0 to 100
 */
void bar_progress_step(float step_percent);

/*
 * Removes progress bar and restores original screen size.
 */
void bar_progress_stop(void);

#endif /* __BAR_PROGRESS_H */
