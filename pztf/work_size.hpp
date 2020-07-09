#ifndef __PZTF_FORK_SIZE_HPP__
#define __PZTF_FORK_SIZE_HPP__
#include <pzcl/pzcl.h>

namespace pztf {
inline std::size_t get_global_work_size(const cl::Device& device) {
        std::size_t global_work_size[3] = {0};
        device.getInfo(CL_DEVICE_MAX_WORK_ITEM_SIZES, &global_work_size);
        std::string device_name;
        device.getInfo(CL_DEVICE_NAME, &device_name);

        auto gws = global_work_size[0];

        if (device_name.find("PEZY-SC2") != std::string::npos) {
                gws = std::min(gws, (size_t)15872);
        }

        return gws;
}
} // namespace pztf
#endif
