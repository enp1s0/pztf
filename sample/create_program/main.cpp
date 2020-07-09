#include <vector>
#include <CL/cl.hpp>
#include <pztf/create_program.hpp>

int main() {
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	const auto& platform = platforms[0];

	std::vector<cl::Device> devices;
	platform.getDevices(CL_DEVICE_TYPE_DEFAULT, &devices);
	auto cl_device = devices[0];

	auto cl_context = cl::Context(cl_device);

	auto cl_queue = cl::CommandQueue(cl_context, cl_device, CL_QUEUE_PROFILING_ENABLE);

	const auto program = pztf::create_program(cl_context, cl_device, "pzcl_kernel/kernel.pz");
}
