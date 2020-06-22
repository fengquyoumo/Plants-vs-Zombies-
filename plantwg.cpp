// plantwg.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

//主菜单
void MainMenu()
{
	printf("-----歪瓜选项------\n");
	printf("    1.修改阳光\n");
	printf("    2.修改金币\n");
	printf("    3.退出\n");
	printf("---created by wjl---\n");
}

//修改阳光
void ModifySun()
{
	//根据窗口名字获取窗口句柄
	HWND hgame = ::FindWindow(NULL, "Plants vs. Zombies 1.2.0.1073 RELEASE");

	//得到线程或者进程id
	DWORD ProcessId;
	::GetWindowThreadProcessId(hgame, &ProcessId);

	//根据id得到进程句柄
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
	//内存基址
	LPVOID pBase = (LPVOID)7836920;//十六进制7794F8转换为10进制
	int sun = 0;
	LPVOID rbuffer = (LPVOID)&sun;
	//传出参数
	DWORD byred;
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);

	pBase = (LPVOID)(sun + 2152);//十六进制868转换为10进制
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);

	pBase = (LPVOID)(sun + 21880);//十六进制5578转换为10进制
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);
	printf("当前阳光值：%d \n", sun);
	int wsun = 0;
	printf("请输入阳光的修改值\n");
	scanf("%d", &wsun);
	LPVOID wbuf = (LPVOID)&wsun;
	DWORD by;
	::WriteProcessMemory(hProcess,(LPVOID)pBase,wbuf,4,&by);
	printf("修改阳光成功！\n");
}

//修改金币
void ModifyMoney()
{
	//根据窗口名字获取窗口句柄
	HWND hgame = ::FindWindow(NULL, "Plants vs. Zombies 1.2.0.1073 RELEASE");

	//得到线程或者进程id
	DWORD ProcessId;
	::GetWindowThreadProcessId(hgame, &ProcessId);

	//根据id得到进程句柄
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
	//内存基址
	LPVOID pBase = (LPVOID)7836920;//十六进制7794F8转换为10进制
	int money = 0;
	LPVOID rbuffer = (LPVOID)&money;
	//传出参数
	DWORD byred;
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);

	pBase = (LPVOID)(money + 2384);//十六进制868转换为10进制
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);

	pBase = (LPVOID)(money + 80);//十六进制5578转换为10进制
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);
	printf("当前金币值：%d \n", money);
	int wmoney = 0;
	printf("请输入金币的修改值\n");
	scanf("%d", &wmoney);
	LPVOID wbuf = (LPVOID)&wmoney;
	DWORD by;
	::WriteProcessMemory(hProcess, (LPVOID)pBase, wbuf, 4, &by);
	printf("修改金币成功！\n");
}


int main()
{
	//根据窗口名字获取窗口句柄
	HWND hgame = ::FindWindow(NULL, "Plants vs. Zombies 1.2.0.1073 RELEASE");

	//得到窗口的具体信息
	RECT r;
	::GetWindowRect(hgame, &r);
	//printf("窗口信息：\n 左上角坐标：%d %d       右下角坐标: %d %d\n", r.left, r.top, r.right, r.bottom);

	//获得鼠标点击的位置
	POINT P;
	::GetCursorPos(&P);
	//printf("鼠标位置：%d %d\n", P.x, P.y);
	
	if (NULL == hgame)
	{
		printf("请先运行游戏，后重新开启歪瓜！\n");
		Sleep(3000);
		return 0;
	}
	int op;
	while (1)
	{
		MainMenu();
		scanf("%d",&op);
		switch (op)
		{
		case 1:
		{
			ModifySun();
			break;
		}
		case 2:
		{
			ModifyMoney();
			break;
		}
		default: break;
		}
		if (op != 1 && op != 2)
		{
			printf("感谢使用！\n");
			break;
		}
	}
	return 0;
}

