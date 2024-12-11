#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
// Semaphores
sem_t mutex;
sem_t wrt;
// Shared resource and reader count
int reader_count = 0;
int shared_data = 0;
// Reader function
void *reader(void *arg) {
int reader_id = *((int *)arg);
while (1) {
// Entry section for reader
sem_wait(&mutex);
reader_count++;
if (reader_count == 1) {
sem_wait(&wrt);
}
sem_post(&mutex);
printf("Reader %d is reading the shared data: %d\n", reader_id,
shared_data);
sleep(1);
// Exit section for reader
sem_wait(&mutex);
reader_count--;
if (reader_count == 0) {
sem_post(&wrt);
}
sem_post(&mutex);
// Non-critical section
sleep(1);
}
pthread_exit(NULL);
}
// Writer function
void *writer(void *arg) {
int writer_id = *((int *)arg);
while (1) {
// Entry section for writer
sem_wait(&wrt);
// Critical section for writer
shared_data++;
printf("Writer %d is writing to the shared data: %d\n", writer_id,
shared_data);
sleep(2);
// Exit section for writer
sem_post(&wrt);
// Non-critical section
sleep(1);
}
pthread_exit(NULL);
}
int main() {
pthread_t readers[3], writers[2];
int reader_ids[3] = {1, 2, 3};
int writer_ids[2] = {1, 2};
sem_init(&mutex, 0, 1);
sem_init(&wrt, 0, 1);
// Create reader threads
for (int i = 0; i < 3; i++) {
pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
}
// Create writer threads
for (int i = 0; i < 2; i++) {
pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
}
}