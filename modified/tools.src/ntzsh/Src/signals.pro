void install_handler _((int sig));
void intr _((void));
void nointr _((void));
void holdintr _((void));
void noholdintr _((void));
sigset_t signal_mask _((int sig));
sigset_t signal_block _((sigset_t set));
sigset_t signal_unblock _((sigset_t set));
sigset_t signal_setmask _((sigset_t set));
int signal_suspend _((int sig, int sig2));
RETSIGTYPE handler _((int sig));
void killrunjobs _((int from_signal));
int killjb _((Job jn, int sig));
int settrap _((int sig, List l));
void unsettrap _((int sig));
void dotrapargs _((int sig, int *sigtr, void *sigfn));
void dotrap _((int sig));
