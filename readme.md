Starter code for a vulkan app.

Note in order to run validation layers on mac I had to add the following
Device.hpp
#pragma once
#define VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME "VK_KHR_portability_subset"<---------

106

const std::vector<const char *> deviceExtensions = {
VK_KHR_SWAPCHAIN_EXTENSION_NAME,
VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME};<---------
};

Device.cpp
79
VkInstanceCreateInfo createInfo = {};
createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
createInfo.pApplicationInfo = &appInfo;
createInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;<----------

283
// Manually specify the extensions that OS X/MoltenVK/Metal needs<-----------
extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);<-----------
extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);<-----------

return extensions;
}
