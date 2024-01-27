include .env

# create list of all spv files and set as dependency
vertSources = $(shell find ./shaders -type f -name "*.vert")
vertObjFiles = $(patsubst %.vert, %.vert.spv, $(vertSources))
fragSources = $(shell find ./shaders -type f -name "*.frag")
fragObjFiles = $(patsubst %.frag, %.frag.spv, $(fragSources))

app: $(vertObjFiles) $(fragObjFiles)
app: *.cpp *.hpp
	g++ -w -g --std=c++17 -I$(PROJECT_PATH)/include/ -I$(VULKAN_SDK_PATH)/include/ -Wl,-rpath,$(PROJECT_PATH)/lib -L$(PROJECT_PATH)/lib -L${VULKAN_SDK_PATH}/lib/ -lglfw.3 -lvulkan.1 -lvulkan.1.3.268 -o ./build/app *.cpp

# make shader targets
%.spv: %
	${GLSLC} $< -o $@


clean:
	rm ./build/app
	rm -rf ./build/app.dSYM
