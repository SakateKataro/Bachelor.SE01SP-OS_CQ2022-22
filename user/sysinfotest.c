#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

void
sysinfotest(void)
{
    struct sysinfo info;

    // Gọi syscall sysinfo
    if (sysinfo(&info) < 0) {
        printf("sysinfotest: sysinfo failed\n");
        exit(1);
    }

    // In ra thông tin thu thập được
    printf("sysinfotest: freemem = %ld, nproc = %ld\n", info.freemem, info.nproc);

    // Kiểm tra giá trị hợp lý
    if (info.freemem <= 0) {
        printf("sysinfotest: freemem invalid\n");
        exit(1);
    }

    if (info.nproc <= 0) {
        printf("sysinfotest: nproc invalid\n");
        exit(1);
    }

    printf("sysinfotest: OK\n");
}

int
main(int argc, char *argv[])
{
    sysinfotest();
    exit(0);
}