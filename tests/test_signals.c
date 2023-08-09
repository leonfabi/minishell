#include <signal.h>
#include <criterion/criterion.h>
#include "minishell.h"

void crash(void);

Test(simple, caught, .signal = SIGINT) {
	raise(SIGINT);
}

// Test(simple, wrong_signal, .signal = SIGINT) {
//     crash();
// }
// 
// Test(simple, uncaught) {
//     crash();
// }
