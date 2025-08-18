// writer.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    const int SHM_C_ERR = 1;
    const int SHM_ATT_ERR = 2;
    const int NO_ERR = 0;

    int n;
    printf("How many numbers? ");
    scanf("%d", &n);

    // Create shared memory segment
    key_t key = 1234;
    int shm_id = shmget(key, sizeof(int) * (n + 1), IPC_CREAT | 0666);
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

    // Store size at index 0
    shm_array[0] = n;

    // Read numbers into shared memory
    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &shm_array[i]);
    }

    printf("Numbers saved to shared memory.\n");

    // Insertion Sort (CLRS-style, starting from index 2)
    for (int j = 2; j <= n; j++) {
        int key = shm_array[j];
        int i = j - 1;

        while (i > 0 && shm_array[i] > key) {
            shm_array[i + 1] = shm_array[i];
            i = i - 1;
        }
        shm_array[i + 1] = key;
    }

    // Detach
    shmdt(shm_array);
    return NO_ERR;
}
