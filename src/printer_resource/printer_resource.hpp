#pragma once
#include <iostream>
#include <thread>

class PrinterResource{
    public:
        void printInfo(std::thread::id thread_id);
};