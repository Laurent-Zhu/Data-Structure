#include <windows.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

int main() {
    HWND console = GetConsoleWindow();
    SetLayeredWindowAttributes(console, 0, 150, LWA_ALPHA);

    while (true) {
        // 清空控制台窗口
        system("cls");

        // 获取当前系统时间
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        // 将时间转换为本地时间
        std::tm localNow;
        localtime_s(&localNow, &now_c);

        // 输出年、月、日、时、分、秒
        std::cout << "可以按F11在ctrl+鼠标滚轮全屏放大" << std::endl;
        std::cout << "当前时间："
            << localNow.tm_year + 1900 << "年"
            << localNow.tm_mon + 1 << "月"
            << localNow.tm_mday << "日 "
            << localNow.tm_hour << "时"
            << localNow.tm_min << "分"
            << localNow.tm_sec << "秒" << std::endl;

        // 每秒刷新
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}