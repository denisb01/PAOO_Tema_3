#pragma once

#include <mutex>

class MutexRAII{
    private:
        std::mutex& priv_mutex;
    
    public:
        MutexRAII(std::mutex& mutex);
        ~MutexRAII();
};