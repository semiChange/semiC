#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
// 该程序检测指定点的rgb值,报警
int main()
{

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
		int kk=0;
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

	printf("CONFIG INFO ==>  POS:%s RGBA:%s\n\n", pos, rgba);

	LONG zx = -1;
	LONG zy = -1;

	HMODULE hM = NULL;
	typedef COLORREF (*Func)(HDC hdc, int a, int b);

	hM = LoadLibrary("gdi32.dll");
	POINT ptB = {0, 0};
	LPPOINT xy = &ptB; // 内存地址
	ptB.x = 0; // 初始化
    ptB.y = 0;
	COLORREF cr= RGB(0,0,0); // 初始化，避免未赋值;
	COLORREF cr1;

	HDC hdc = GetDC(NULL);

	// 获取某个像素点
	Func fu = (Func)GetProcAddress(hM, "GetPixel");
    if (fu == NULL) {
        printf("GetProcAddress 获取 GetPixel 失败！\n");
        return 1;
    }
	// 获取配置pos的像素点
    char pos_copy[32];
    strcpy(pos_copy, pos); // strtok 会修改原字符串
    char *sx_str = strtok(pos_copy, ",");
    char *sy_str = strtok(NULL, ",");
    if (sx_str == NULL || sy_str == NULL) {
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

	while (1)
	{
		Sleep(2000);
		fflush(stdout);
		// 不停获取内存中的值
		if (!GetCursorPos(xy)) {
            printf("GetCursorPos 失败\n");
            continue;
        }


		zx = xy->x;
        zy = xy->y;
        // 每次都获取当前像素点
        cr = fu(hdc, zx, zy);

        char curpos[32] = {0};
        char currgba[32] = {0};

        ca = GetRValue(cr);
        cb = GetGValue(cr);
        cc = GetBValue(cr);


		snprintf(curpos, sizeof(curpos), "%ld,%ld", zx, zy);
		snprintf(currgba, sizeof(currgba), "%d,%d,%d", ca, cb, cc);
		printf("CURRENT INFO ==> pos:%s rgba:%s\n",curpos, currgba);

		// --------------------
		// cr1 = fu(hdc, sx, sy);
		// printf("配置的位置%d %d",sx,sy);
		// r = GetRValue(cr1);
		// g = GetGValue(cr1);
		// b = GetBValue(cr1);

		char configrgba[11] = {0};
		// snprintf(configrgba, sizeof(configrgba), "%d,%d,%d", r, g, b);
		// printf("SETTING INFO ==> POS:%d,%d RGBA:%s\n\n", sx,sy, configrgba);
		// printf("SETTING INFO ==> |RGBA:%s|\n\n",configrgba);

		// 配置点的颜色值  == 配置文件的颜色值
		// if (strcmp(configrgba, rgba) == 0)
		// {
		// 	printf("alarm...\n");
		// 	PlaySound(TEXT("alarm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		// }
	}
	FreeLibrary(hM);
	return 0;
}
