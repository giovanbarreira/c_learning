// reader.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;

    const int SHM_C_ERR = 1;
    const int SHM_ATT_ERR = 2;
    const int NO_ERR = 0;

    int shm_id = shmget(key, 0, 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(SHM_C_ERR);
    }

    // Attach to shared memory
    int* shm_array = (int*)shmat(shm_id, NULL, 0);
    if (shm_array == (int*)-1) {
        perror("shmat");
        exit(SHM_ATT_ERR);
    }

    int n = shm_array[0];
    printf("Reading %d numbers from shared memory:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", shm_array[i]);
    }
    printf("\n");

    // Detach
    shmdt(shm_array);

    puts("Wanna clear the shme? 0-yes 1-no");
    int a = 0;
    scanf("%d", &a);
    if (a == 0) shmctl(shm_id, IPC_RMID, NULL);

    return NO_ERR;
}
