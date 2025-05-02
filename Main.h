#define GLM_FORCE_LEFT_HANDED     
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <windows.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void ErrorMessage_1(const char* message);
void ErrorMessage_2(HWND hwnd,const char* message);