#define SDL_MAIN_HANDLED
#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <SDL2/SDL.h>
// #pragma comment(lib, "winmm.lib")

// 定义一些常用的颜色代码，方便记忆
// 格式：前景色 + 背景色 * 16
// 比如 0 是黑，7是白，F是亮白
enum ConsoleColor
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	YELLOW = 6,
	WHITE = 7,
	GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_YELLOW = 14,
	BRIGHT_WHITE = 15
};

// 设置颜色的函数
void set_color(int foreground, int background)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// 颜色代码的计算方法是：前景色 + 背景色 * 16
	SetConsoleTextAttribute(hConsole, foreground + background * 16);
}

void play_wav(const char* filename) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return;
    }

    SDL_AudioSpec spec;
    Uint8 *buf = NULL;
    Uint32 len = 0;

    if (!SDL_LoadWAV(filename, &spec, &buf, &len)) {
        printf("SDL_LoadWAV error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_AudioDeviceID dev = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
    if (!dev) {
        printf("SDL_OpenAudioDevice error: %s\n", SDL_GetError());
        SDL_free(buf);
        SDL_Quit();
        return;
    }

    if (SDL_QueueAudio(dev, buf, len) < 0) {
        printf("SDL_QueueAudio error: %s\n", SDL_GetError());
        SDL_CloseAudioDevice(dev);
        SDL_free(buf);
        SDL_Quit();
        return;
    }

    SDL_PauseAudioDevice(dev, 0); // 开始播放

    // 等待播放结束
    while (SDL_GetQueuedAudioSize(dev) > 0) {
        SDL_Delay(100);
    }

    SDL_CloseAudioDevice(dev);
    SDL_free(buf);
    SDL_Quit();
}

// 该程序检测指定点的rgb值,报警
int main(int argc, char *argv[])
{

	char pos[32] = {0};
	char rgba[32] = {0};
	char pos[32] = {0};
	char rgba[32] = {0};
	FILE *f = fopen("config.ini", "r");
	if (f == NULL)
	{
		perror("open file error!!");
		return 0;
	}
	else
	{
		// read config prama
		char str[256];
		int kk = 0;
		int kk = 0;
		while (fgets(str, sizeof(str), f))
		{
			//	char *str = strchr(str2,'\n');
			// use : cutting string
			char *key = strtok(str, ":");
			char *value = strtok(NULL, "\n");

			if (strcmp(key, "pos") == 0)
			{
				kk = 1;
			}
			if (strcmp(key, "rgba") == 0)
			{
				kk = 2;
			}

			switch (kk)
			{
			case 1:
				strcpy(pos, value);
				break;

			case 2:
				strcpy(rgba, value);
				break;
			}
		}
		fclose(f);
	}

	// 保存原始颜色
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD saved_attributes = consoleInfo.wAttributes;
	// 设置为白底黑字
	set_color(BLACK, BRIGHT_WHITE);

	printf("[%36sJ Color Monitor Alarm v1.0%36s]\n\n", "", "");
	// printf("CONFIG INFO ==>  POS:%s RGBA:%s\n\n", pos, rgba);
	// 恢复到程序启动时的原始颜色
	SetConsoleTextAttribute(hConsole, saved_attributes);
	LONG zx = -1;
	LONG zy = -1;

	HMODULE hM = NULL;
	// 注意函数的 指针类型一定要正确, 否则会报错!!!  WINAPI
	// typedef COLORREF (*Func)(HDC hdc, int a, int b);
	typedef COLORREF(WINAPI * Func)(HDC hdc, int a, int b);
	// 注意函数的 指针类型一定要正确, 否则会报错!!!  WINAPI
	// typedef COLORREF (*Func)(HDC hdc, int a, int b);
	typedef COLORREF(WINAPI * Func)(HDC hdc, int a, int b);

	hM = LoadLibrary("gdi32.dll");
	POINT ptB = {0, 0};
	LPPOINT xy = &ptB; // 内存地址
	ptB.x = 0;		   // 初始化
	ptB.y = 0;
	COLORREF cr = RGB(0, 0, 0); // 初始化，避免未赋值;
	ptB.x = 0;		   // 初始化
	ptB.y = 0;
	COLORREF cr = RGB(0, 0, 0); // 初始化，避免未赋值;
	COLORREF cr1;

	HDC hdc = GetDC(NULL);

	// 获取某个像素点
	Func fu = (Func)GetProcAddress(hM, "GetPixel");
	if (fu == NULL)
	{
		printf("GetProcAddress 获取 GetPixel 失败！\n");
		return 1;
	}
	if (fu == NULL)
	{
		printf("GetProcAddress 获取 GetPixel 失败！\n");
		return 1;
	}
	// 获取配置pos的像素点
	char pos_copy[32];
	strcpy(pos_copy, pos); // strtok 会修改原字符串
	char *sx_str = strtok(pos_copy, ",");
	char *sy_str = strtok(NULL, ",");
	if (sx_str == NULL || sy_str == NULL)
	{
		printf("配置文件pos格式错误！应为:x,y\n");
		return 1;
	}
	int sx = atoi(sx_str);
	int sy = atoi(sy_str);
	char pos_copy[32];
	strcpy(pos_copy, pos); // strtok 会修改原字符串
	char *sx_str = strtok(pos_copy, ",");
	char *sy_str = strtok(NULL, ",");
	if (sx_str == NULL || sy_str == NULL)
	{
		printf("配置文件pos格式错误！应为:x,y\n");
		return 1;
	}
	int sx = atoi(sx_str);
	int sy = atoi(sy_str);

	int ca = 0;
	int cb = 0;
	int cc = 0;

	int r = 0;
	int g = 0;
	int b = 0;

	char curpos[32] = {0};
	char currgba[32] = {0};

	// 1. 先停止当前所有播放，释放资源（相当于“清空缓存”）
	// PlaySound(NULL, NULL, SND_PURGE);

	while (1)
	{
		Sleep(2200);
		Sleep(2200);
		fflush(stdout);
		// 不停获取内存中的值
		if (!GetCursorPos(xy))
		{
			printf("GetCursorPos 失败\n");
			continue;
		}
		if (!GetCursorPos(xy))
		{
			printf("GetCursorPos 失败\n");
			continue;
		}

		zx = xy->x;
		zy = xy->y;
		// 每次都获取当前像素点
		cr = fu(hdc, zx, zy);
		zy = xy->y;
		// 每次都获取当前像素点
		cr = fu(hdc, zx, zy);

		ca = (int)GetRValue(cr);
		cb = (int)GetGValue(cr);
		cc = (int)GetBValue(cr);
		ca = (int)GetRValue(cr);
		cb = (int)GetGValue(cr);
		cc = (int)GetBValue(cr);

		snprintf(curpos, sizeof(curpos), "%d,%d", zx, zy);
		memset(currgba, 0, sizeof(currgba)); // 清空字符串
		// printf("ca=%d cb=%d cc=%d\n", ca, cb, cc); // 调试输出
		snprintf(curpos, sizeof(curpos), "%d,%d", zx, zy);
		memset(currgba, 0, sizeof(currgba)); // 清空字符串
		// printf("ca=%d cb=%d cc=%d\n", ca, cb, cc); // 调试输出
		snprintf(currgba, sizeof(currgba), "%d,%d,%d", ca, cb, cc);
		printf("MOUSE INFO ==> pos:%s\t rgba:%s\n", curpos, currgba);
		printf("MOUSE INFO ==> pos:%s\t rgba:%s\n", curpos, currgba);

		// --------------------
		cr1 = fu(hdc, sx, sy);
		// printf("配置的位置%d %d",sx,sy); // 同pos变量
		r = GetRValue(cr1);
		g = GetGValue(cr1);
		b = GetBValue(cr1);
		cr1 = fu(hdc, sx, sy);
		// printf("配置的位置%d %d",sx,sy); // 同pos变量
		r = GetRValue(cr1);
		g = GetGValue(cr1);
		b = GetBValue(cr1);

		char findrgba[32] = {0};
		snprintf(findrgba, sizeof(findrgba), "%d,%d,%d", r, g, b);
		// printf("=%s=",findrgba);
		printf("FOUND INFO ==> POS:%d,%d\t RGBA:%s (%s) \n\n", sx, sy, findrgba, rgba);
		char findrgba[32] = {0};
		snprintf(findrgba, sizeof(findrgba), "%d,%d,%d", r, g, b);
		// printf("=%s=",findrgba);
		printf("FOUND INFO ==> POS:%d,%d\t RGBA:%s (%s) \n\n", sx, sy, findrgba, rgba);

		// 配置点的颜色值  == 配置文件的颜色值
		if (strcmp(findrgba, rgba) == 0)
		{

			set_color(WHITE, RED);
			printf("%44s alarm...%44s\n", "", "");
			// 恢复到程序启动时的原始颜色
			SetConsoleTextAttribute(hConsole, saved_attributes);
			LPCSTR soundPath = "alarm.wav";
			// playsound会缓存音频文件，所以如果需要重复播放同一个文件，最好先停止当前播放，稍作延迟，再播放。
			// PlaySound(soundPath, NULL, SND_FILENAME | SND_ASYNC);
			// 弹出播放器播放
			// ShellExecute(NULL, "open", "alarm.wav", NULL, NULL, SW_SHOWNORMAL);

			play_wav(soundPath); // 替换文件后立即生效
		}
	}
	FreeLibrary(hM);
	return 0;
}
