#include<iostream>
#include<queue>
#include<mutex>
#include<thread>
#include<condition_variable>


std::queue<std::string> g_data;
std::mutex mut;
std::condition_variable cv;

void producter() {
    while (true)
    {
        std::string input;
        std::cin >> input;

        std::lock_guard<std::mutex> lock(mut);
        g_data.push(input); 
        cv.notify_one();

        if (input == "quit") {
            break;
        }
    }
}

void consutomer() {
    while (true)
    {
        std::unique_lock<std::mutex> lock(mut);
        cv.wait(lock, []{return !g_data.empty(); });
        auto input = g_data.front(); 
        g_data.pop();

        if (input == "quit") {
            break;
        }

        std::cout << input << std::endl;
    }
}

int main() {
    auto t1 = std::thread(producter);
    auto t2 = std::thread(consutomer);

    t1.join();
    t2.join();
}