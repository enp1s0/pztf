#ifndef __PZTF_CREATE_PROGRAM_HPP__
#define __PZTF_CREATE_PROGRAM_HPP__
#include <fstream>
#include <stdexcept>
#include <vector>
#include <pzcl/pzcl.h>

namespace pztf {
inline cl::Program create_program(cl::Context& context, const cl::Device& device, const std::string& filename) {
	std::ifstream ifs(filename, std::ios::in | std::ios::binary);
	if(!ifs) {
		throw std::runtime_error("No such a file : " + filename);
	}

	ifs.seekg(0, std::ios::end);
	const std::size_t filesize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	std::vector<char> binary_data;
	binary_data.resize(filesize);
	ifs.read(reinterpret_cast<char*>(binary_data.data()), filesize);

	cl::Program::Binaries binaries;
	binaries.push_back(std::make_pair(&binary_data[0], filesize));

	return cl::Program(context, std::vector<cl::Device>{device}, binaries, nullptr, nullptr);
}
}

#endif
