#include "SerialCommander.h"
#include "boost/asio.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

SerialCommander::SerialCommander()
{
}

SerialCommander::~SerialCommander()
{
}

std::vector<std::string> SerialCommander::GetComports()
{
#ifdef _WIN32
    std::vector<std::string> ports;

    // Enumerate serial ports
    for (int i = 1; i <= 16; ++i) {
        std::string portName = "COM" + std::to_string(i);
        HANDLE handle = CreateFile(portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (handle != INVALID_HANDLE_VALUE) {
            ports.push_back(portName);
            CloseHandle(handle);
        }
    }
    return ports;
#endif
    return std::vector<std::string>();
}
