#include <iostream>
#include "mutex_raii.hpp"
#include "printer_resource.hpp"
#include <thread>
#include <memory>
#include <vector>

void thread_function(std::shared_ptr<PrinterResource> shared_printer, std::mutex& given_mutex)
{
    for(int i = 0; i < 3; i++){
        MutexRAII mutex_raii(given_mutex);

        shared_printer->printInfo(std::this_thread::get_id());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::mutex mutex;
    std::vector<std::thread> threads_vector;

    std::shared_ptr<PrinterResource> printer = std::make_shared<PrinterResource>();

    for(int i = 0; i < 2; i++){
        threads_vector.emplace_back(thread_function, printer, std::ref(mutex));
    }

    for(int i = 0; i < 2; i++){
        threads_vector[i].join();
    }
}