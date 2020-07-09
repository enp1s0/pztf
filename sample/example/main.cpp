#include <vector>
#include <CL/cl.hpp>
#include <pztf/error.hpp>

constexpr std::size_t N = 1lu << 10;

int main() {
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	const auto& platform = platforms[0];

	std::vector<cl::Device> devices;
	platform.getDevices(CL_DEVICE_TYPE_DEFAULT, &devices);
	cl_device = devices[0];

	cl_context = cl::Context(cl_device);

	cl_queue = cl::CommandQueue(cl_context, cl_device, CL_QUEUE_PROFILING_ENABLE);

	auto dA = cl::Buffer(cl_context, CL_MEM_READ_WRITE, sizeof(double) * N);
	auto hA = new double [N];

	PZTF_CHECK_ERROR(cl_queue.enqueueReadBuffer(dA, true, 0, sizeof(double) * N, hA));
	cl_queue.finish();

	delete [] hA;
}
