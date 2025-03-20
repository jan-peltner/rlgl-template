#include <stddef.h>
#include "raylib.h"
#include "colors.h"
#include "window.h"


int main(void) {
	// init 
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RLGL Template");	
	SetTargetFPS(TARGET_FPS);
	Vector2* resolution = getResolution();

	// get colors for CPU
	Color* colors = getColors();
	size_t colors_length = getColorsLength();

	// prepare colors as vec4 for GPU shader
	float color_palette_vec[colors_length * 4];
	normalizedColorsToFloatVec4(color_palette_vec);

	// set up shaders
	Shader main_shader = LoadShader("main.vert", "main.frag");

	int main_shader_colors_loc = GetShaderLocation(main_shader, "colors"); 
	int main_shader_time_loc = GetShaderLocation(main_shader, "time");
	int main_shader_resolution_loc = GetShaderLocation(main_shader, "resolution");

	SetShaderValueV(main_shader, main_shader_colors_loc, &color_palette_vec, SHADER_UNIFORM_VEC4, colors_length);
	SetShaderValue(main_shader, main_shader_resolution_loc, resolution, SHADER_UNIFORM_VEC2);

	RenderTexture2D main_target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

	while (!WindowShouldClose()) {
		float elapsed_time = GetTime();
		SetShaderValue(main_shader, main_shader_time_loc, &elapsed_time, SHADER_UNIFORM_FLOAT);

		BeginTextureMode(main_target);
		    ClearBackground(BLACK);
		    BeginShaderMode(main_shader);
		    DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, WHITE);
		    EndShaderMode();
		EndTextureMode();
		BeginDrawing();

			ClearBackground(BLACK);

			DrawTexturePro(
			main_target.texture,
			(Rectangle){ 0, 0, (float)main_target.texture.width, (float)main_target.texture.height },
			(Rectangle){ 0, 0, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT},
			(Vector2){ 0, 0 },
			0.0f,
			WHITE
			);

			DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, BLACK);
			DrawText(TextFormat("Frametime: %.2fms", GetFrameTime() * 1000), 10, 30, 20, BLACK);

		EndDrawing();
	}

	
	UnloadRenderTexture(main_target);
	UnloadShader(main_shader);
	CloseWindow();
	return 0;
}
