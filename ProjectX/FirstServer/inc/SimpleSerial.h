#pragma once

#include <asio.hpp>

class SimpleSerial
{
public:
    /**
     * Constructor.
     * \param port device name, example "/dev/ttyUSB0" or "COM4"
     * \param baud_rate communication speed, example 9600 or 115200
     * \throws boost::system::system_error if cannot open the
     * serial device
     */
    SimpleSerial(std::string port, unsigned int baud_rate)
        : io(), serial(io, port)
    {
        serial.set_option(asio::serial_port_base::baud_rate(baud_rate));
    }


    void writeString(std::string s)
    {
        asio::write(serial, asio::buffer(s.c_str(), s.size()));
    }

    void writeBytes(unsigned char* cmd)
    {
        asio::write(serial, asio::buffer(cmd, 6));
    }


    std::string readLine()
    {
        //Reading data char by char, code is optimized for simplicity, not speed
        using namespace boost;
        char c;
        std::string result;
        for (;;)
        {
            asio::read(serial, asio::buffer(&c, 1));
            switch (c)
            {
            case '\r':
                break;
            case '\n':
                return result;
            default:
                result += c;
            }
        }
    }

private:
    asio::io_service io;
    asio::serial_port serial;
};