#include <stdio.h>

#include <iostream>
#include <chrono>
#include <pthread.h>

using namespace std;

// void thread_task(int n)
// {
//     std::this_thread::sleep_for(std::chrono::seconds(n));

//     std::cout << "thread " << std::this_thread::get_id() << " wait for " << n << " seconds"
//               << "\n";
// }

// int main(int argc, char* argv[])
// {
//     std::thread threads[5];

//     for (int i = 0; i < 5; i++) {
//         threads[i] = std::thread(thread_task, i + 1);
//     }

//     std::cout << "Done spawning threads ! Now wait for them to join\n";

//     for (auto& t : threads) {
//         t.join();
//     }

//     std::cout << "All threads joined.\n";

//     return EXIT_SUCCESS;
// }

static int total = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* func(void*)
{
    int i;
    for (int i = 0; i < 50; i++) {
        //pthread_mutex_lock(&m);
        total += i;
        //pthread_mutex_unlock(&m);
    }
}

int main()
{
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, &func, NULL)) {
        throw;
    }
    if (pthread_create(&thread2, NULL, &func, NULL)) {
        throw;
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    std::cout << "total: " << total << "\n";
    return 1;
}
