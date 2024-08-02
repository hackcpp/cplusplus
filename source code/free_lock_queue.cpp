#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

template <typename T>
class LockFreeQueue {
public:
    LockFreeQueue(size_t capacity)
        : capacity(capacity), head(0), tail(0) {
        buffer = new T[capacity];
    }

    ~LockFreeQueue() {
        delete[] buffer;
    }

    bool enqueue(const T& item) {
        size_t currentTail = tail.load(std::memory_order_relaxed);
        size_t nextTail = (currentTail + 1) % capacity;

        if (nextTail == head.load(std::memory_order_acquire)) {
            return false; // 队列已满
        }

        buffer[currentTail] = item;
        tail.store(nextTail, std::memory_order_release);

        return true;
    }

    bool dequeue(T& item) {
        size_t currentHead = head.load(std::memory_order_relaxed);

        if (currentHead == tail.load(std::memory_order_acquire)) {
            return false; // 队列为空
        }

        item = buffer[currentHead];
        head.store((currentHead + 1) % capacity, std::memory_order_release);

        return true;
    }

private:
    T* buffer;
    size_t capacity;
    std::atomic<size_t> head;
    std::atomic<size_t> tail;
};

int main() {
    LockFreeQueue<int> queue(10);

    // 启动生产者线程
    std::thread producer([&queue]() {
        for (int i = 0; i < 20; ++i) {
            while (!queue.enqueue(i)) {
                // 如果队列已满，等待
            }
            std::cout << "Produced: " << i << std::endl;
        }
    });

    // 启动消费者线程
    std::thread consumer([&queue]() {
        for (int i = 0; i < 20; ++i) {
            int item;
            while (!queue.dequeue(item)) {
                // 如果队列为空，等待
            }
            std::cout << "Consumed: " << item << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
