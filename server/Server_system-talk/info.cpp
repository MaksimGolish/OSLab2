#include "info.hpp"

std::string Info::getSystemInfo() {
	std::string result, string_buffer;
	int buffer_num;
	char buffer[100];
	int parameters[] = {CTL_HW, HW_MACHINE};
	size_t len = sizeof(buffer);
	size_t num_len = sizeof(int);
	sysctl(parameters, 2, buffer, &len, nullptr, 0);
	string_buffer = buffer;
	result = "Machine type: " + string_buffer + "\n";
	parameters[1] = HW_MODEL;
	sysctl(parameters, 2, buffer, &len, nullptr, 0);
	result += "Machine model: " + string_buffer + "\n";
	parameters[1] = HW_MACHINE_ARCH;
	sysctl(parameters, 2, buffer, &len, nullptr, 0);
	result += "Machine architecture: " + string_buffer + "\n";
	parameters[1] = HW_PHYSMEM;
	sysctl(parameters, 2, &buffer_num, &num_len, nullptr, 0);
	result += "Physical memory: " + std::to_string(buffer_num) + " bytes\n";
	parameters[1] = HW_PAGESIZE;
	sysctl(parameters, 2, &buffer_num, &num_len, nullptr, 0);
	result += "Memory page size: " + std::to_string(buffer_num) + " bytes\n";
	return result;
}
