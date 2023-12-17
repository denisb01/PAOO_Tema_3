#include "printer_resource.hpp"

void PrinterResource::printInfo(std::thread::id thread_id)
{
    std::cout << "Printed from thread with ID: " << thread_id << std::endl;
}