#include "mutex_raii.hpp"

MutexRAII::MutexRAII(std::mutex& mutex) : priv_mutex(mutex) 
{
    this->priv_mutex.lock();
}

MutexRAII::~MutexRAII()
{
    this->priv_mutex.unlock();
}