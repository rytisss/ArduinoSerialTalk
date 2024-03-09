#include "SerialCommander.h"
#include "boost/asio.hpp"
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>

using namespace boost::asio;

SerialCommander::SerialCommander()
{
}

SerialCommander::~SerialCommander()
{
}

void SerialCommander::StartListening(std::string com)
{
    try {
        io_service io;
        serial_port port(io);

        port.open(com); // Change this to your Arduino's serial port

        // Set serial port options
        port.set_option(serial_port_base::baud_rate(115200));
        port.set_option(serial_port_base::flow_control(serial_port_base::flow_control::none));
        port.set_option(serial_port_base::parity(serial_port_base::parity::none));
        port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
        port.set_option(serial_port_base::character_size(8));

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Writing data to the serial port
        std::string message = "position\n";
        write(port, buffer(message.c_str(), message.size()));

        char c;
        std::string response;

        int counter = 0;
        // Read data from the serial port
        while (read(port, buffer(&c, 1))) {
            response += c;
            if (c == '\n') {
                std::cout << "Received: " << response;
                response.clear();
                counter++;
            }
            // send command
            if (counter == 20)
            {
                message = "position\n";
                write(port, buffer(message.c_str(), message.size()));
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
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
