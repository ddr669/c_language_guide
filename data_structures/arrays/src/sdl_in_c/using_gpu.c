#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_GPUDevice* device;
SDL_Window* window;

SDL_GPUDevice* SDL_CreateGPUDevice(
	SDL_GPUShaderFormat format_flags,
	bool debug_mode,
	const char *name);

SDL_GPURenderPass* SDL_BeginGPURenderPass(
	SDL_GPUCommandBuffer *commandBuffer,
	const SDL_GPUColorTargetInfo *color_target_infos,
	Uint32 num_color_targets,
	const SDL_GPUDepthStencilTargetInfo *depth_stencil_target_info);

//static SDL_FColor CLEAR_COLOR[] = { 255/255.0f, 255/255.0f, 255/255.0f, 255/255.0f };



SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
	window = SDL_CreateWindow("Triangle with GPU", 720, 410, 0);
	device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_MSL, 0, NULL);
	SDL_ClaimWindowForGPUDevice(device, window);
	return SDL_APP_CONTINUE;}

SDL_AppResult SDL_AppIterate(void *appstate){

	SDL_GPUCommandBuffer* commandBuffer = SDL_AcquireGPUCommandBuffer(device);

	SDL_GPUTexture* swapchainTexture;
	Uint32 width, height;

	SDL_WaitAndAcquireGPUSwapchainTexture(commandBuffer,
			window, &swapchainTexture,
			&width, &height);

	if (swapchainTexture == NULL){
		SDL_SubmitGPUCommandBuffer(commandBuffer);
		return SDL_APP_CONTINUE;
	}

	SDL_GPUColorTargetInfo colorTargetInfo = {0};
	colorTargetInfo.clear_color = (SDL_FColor) {250/255.0f, 125/255.0f,
					55/255.0f, 255/255.0f};

	colorTargetInfo.load_op = SDL_GPU_LOADOP_CLEAR;
	colorTargetInfo.store_op = SDL_GPU_STOREOP_STORE;
	colorTargetInfo.texture = swapchainTexture;

	SDL_GPURenderPass* renderpass = SDL_BeginGPURenderPass(commandBuffer, &colorTargetInfo, 1, NULL);
	// draw something
	SDL_EndGPURenderPass(renderpass);
	SDL_SubmitGPUCommandBuffer(commandBuffer);
	return SDL_APP_CONTINUE
;}
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	if(event->type==SDL_EVENT_WINDOW_CLOSE_REQUESTED){return SDL_APP_SUCCESS;}
	return SDL_APP_CONTINUE;}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
	SDL_DestroyWindow(window);
	SDL_DestroyGPUDevice(device);}



