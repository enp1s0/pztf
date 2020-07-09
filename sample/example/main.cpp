#include <vector>
#include <CL/cl.hpp>
#include <pztf/error.hpp>
#include <pztf/create_program.hpp>
#include <pztf/work_size.hpp>

constexpr std::size_t N = 1lu << 10;

int main() {
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	const auto& platform = platforms[0];

	std::vector<cl::Device> devices;
	platform.getDevices(CL_DEVICE_TYPE_DEFAULT, &devices);
	auto cl_device = devices[0];

	auto cl_context = cl::Context(cl_device);

	auto cl_queue = cl::CommandQueue(cl_context, cl_device, CL_QUEUE_PROFILING_ENABLE);

	auto dA = cl::Buffer(cl_context, CL_MEM_READ_WRITE, sizeof(double) * N);
	auto hA = new double [N];

	PZTF_CHECK_ERROR(cl_queue.enqueueReadBuffer(dA, true, 0, sizeof(double) * N, hA));
	cl_queue.finish();

	// Creating program
	const auto program = pztf::create_program(cl_context, cl_device, "pzcl_kernel/kernel.pz");

	// Getting Global Work Size
	const auto global_work_size = pztf::get_global_work_size(device);

	delete [] hA;
}
