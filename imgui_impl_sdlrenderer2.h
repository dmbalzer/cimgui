// dear imgui: Renderer Backend for SDL_Renderer for SDL2
// (Requires: SDL 2.0.17+)

// Note how SDL_Renderer is an _optional_ component of SDL2.
// For a multi-platform app consider using e.g. SDL+DirectX on Windows and SDL+OpenGL on Linux/OSX.
// If your application will want to render any non trivial amount of graphics other than UI,
// please be aware that SDL_Renderer currently offers a limited graphic API to the end-user and
// it might be difficult to step out of those boundaries.

// Implemented features:
//  [X] Renderer: User texture binding. Use 'SDL_Texture*' as ImTextureID. Read the FAQ about ImTextureID!
//  [X] Renderer: Large meshes support (64k+ vertices) with 16-bit indices.
// Missing features:
//  [ ] Renderer: Multi-viewport support (multiple windows).

// You can use unmodified imgui_impl_* files in your project. See examples/ folder for examples of using this.
// Prefer including the entire imgui/ repository into your project (either as a copy or as a submodule), and only build the backends you need.
// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#ifndef CIMGUI_SDLRENDERER2_INCLUDED
#define CIMGUI_SDLRENDERER2_INCLUDED
#include <stdio.h>
#include <stdint.h>
#if defined _WIN32 || defined __CYGWIN__
    #ifdef CIMGUI_NO_EXPORT
        #define API
    #else
        #define API __declspec(dllexport)
    #endif
#else
    #ifdef __GNUC__
        #define API  __attribute__((__visibility__("default")))
    #else
        #define API
    #endif
#endif

#if defined __cplusplus
    #define EXTERN extern "C"
#else
    #include <stdarg.h>
    #include <stdbool.h>
    #define EXTERN extern
#endif

#define CIMGUI_SDLRENDERER2_API EXTERN API
#define CONST const


#ifdef _MSC_VER
typedef unsigned __int64 ImU64;
#else
//typedef unsigned long long ImU64;
#endif

#ifndef IMGUI_DISABLE
#include "imgui.h"      // IMGUI_IMPL_API

struct SDL_Renderer;

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_SDLRENDERER2_API bool     ImGui_ImplSDLRenderer2_Init(SDL_Renderer* renderer);
CIMGUI_SDLRENDERER2_API void     ImGui_ImplSDLRenderer2_Shutdown();
CIMGUI_SDLRENDERER2_API void     ImGui_ImplSDLRenderer2_NewFrame();
CIMGUI_SDLRENDERER2_API void     ImGui_ImplSDLRenderer2_RenderDrawData(ImDrawData* draw_data, SDL_Renderer* renderer);

// Called by Init/NewFrame/Shutdown
CIMGUI_SDLRENDERER2_API bool     ImGui_ImplSDLRenderer2_CreateFontsTexture();
CIMGUI_SDLRENDERER2_API void     ImGui_ImplSDLRenderer2_DestroyFontsTexture();
CIMGUI_SDLRENDERER2_API bool     ImGui_ImplSDLRenderer2_CreateDeviceObjects();
CIMGUI_SDLRENDERER2_API void     ImGui_ImplSDLRenderer2_DestroyDeviceObjects();

#endif // #ifndef IMGUI_DISABLE
#endif // CIMGUI_SDLRENDERER2_INCLUDED
