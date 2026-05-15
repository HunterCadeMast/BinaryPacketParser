#pragma once
#include <queue>;
#include <mutex>;
#include <condition_variable>;

// Simulates UART wire as a synchronization layer to prevent data races or corrupted queue.

template<typename T> class ThreadQueue {
    private:
        std::queue<T> queue;
        std::mutex mutex;
        std::condition_variable condition;
    public:
        void push(const T& value) {
            {
                std::lock_guard<std::mutex> lock(mutex);
                queue.push(value);
            }
            condition.notify_one();
        }
        T pop() {
            std::unique_lock<std::mutex> lock(mutex);
            condition.wait(lock, [this] {
                return !queue.empty();
            });
            T value = queue.front();
            queue.pop();
            return value;
        }
};