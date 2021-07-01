
/*#include <iostream>
#include "Serialport.h"
#include "Handler.h"

using namespace std;

int main(int argc, char* argv[])
{
		SimpleSerial serial("COM3", 9600);

		unsigned char cmd[6];
		request(Robot_Actions::DOWN, cmd, 255);

		serial.writeBytes(cmd);

		int a;

	

		cout << "Received : " << serial.readLine() << " : end" << endl;

}*/

#include <iostream>
#include <httplib.h>
#include <json.hpp>
#include "SimpleSerial.h"
#include <asio/serial_port.hpp>
#include "Handler.h"
#include <fstream>
#include <string>


using json = nlohmann::json;


std::string get(json j, std::string req)
{
	std::cout << j << std::endl;
	if (j[req] == nullptr)
		throw std::invalid_argument("Invalid json");
	return j[req];
}

bool valid_header(const httplib::Request& req)
{
	if (!req.has_header("Content-Type")) 
		return false;
	if (req.get_header_value("Content-Type") != "application/json")
		return false;
	return true;
}


int main()
{ 
	setlocale(0, "Rus");
	int length;
	char* buffer;

	std::ifstream is;
	is.open("C:\\project\\ProjectX\\FirstServer\\site.txt", std::ios::binary);

	// get length of file:
	is.seekg(0, std::ios::end);
	length = is.tellg();
	is.seekg(0, std::ios::beg);

	// allocate memory:
	buffer = new char[length];

	// read data as a block:
	is.read(buffer, length);
	is.close();

	//std::cout.write(buffer, length);

	//asio::io_service service;
    //asio::serial_port sp(service, "COM7");
	httplib::Server svr;
	svr.Post("/test", [](const httplib::Request& req, httplib::Response& res) {
		if (!valid_header(req))
			return;
		try
		{
			std::cout << "<" << req.body << ">" << std::endl;
			json j = json::parse(req.body); 
			Robot_Actions action = static_cast <Robot_Actions> (stoi(get(j, "action")));
			unsigned char power = stoi(get(j, "power"));
			unsigned char r[6];
			SimpleSerial serial("COM3", 9600);
			request(action, r, power);
			serial.writeBytes(r);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			res.set_content(ex.what(), "text/plain");
			return;
		}
	});

	svr.Get("/robot", [&buffer](const httplib::Request&, httplib::Response& res) {
		res.set_content(buffer, "text/html");
	});

	svr.listen("127.0.0.1", 8080);
	delete[] buffer;
}
