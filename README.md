# Utils for PEZY-SCx processors
Header only PZCL utility livbrary

## Example
```cpp
#include <vector>
#include <CL/cl.hpp>
#include <pztf/error.hpp>

int main() {
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	const auto& platform = platforms[0];

	std::vector<cl::Device> devices;
	platform.getDevices(CL_DEVICE_TYPE_DEFAULT, &devices);
	cl_device = devices[0];

	cl_context = cl::Context(cl_device);

	cl_queue = cl::CommandQueue(cl_context, cl_device, CL_QUEUE_PROFILING_ENABLE);

	PZTF_CHECK_ERROR(cl_queue.enqueueReadBuffer(...));
}
```
