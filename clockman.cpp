#include <windows.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

int main() {
    HWND console = GetConsoleWindow();
    SetLayeredWindowAttributes(console, 0, 150, LWA_ALPHA);

    while (true) {
        // ��տ���̨����
        system("cls");

        // ��ȡ��ǰϵͳʱ��
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        // ��ʱ��ת��Ϊ����ʱ��
        std::tm localNow;
        localtime_s(&localNow, &now_c);

        // ����ꡢ�¡��ա�ʱ���֡���
        std::cout << "���԰�F11��ctrl+������ȫ���Ŵ�" << std::endl;
        std::cout << "��ǰʱ�䣺"
            << localNow.tm_year + 1900 << "��"
            << localNow.tm_mon + 1 << "��"
            << localNow.tm_mday << "�� "
            << localNow.tm_hour << "ʱ"
            << localNow.tm_min << "��"
            << localNow.tm_sec << "��" << std::endl;

        // ÿ��ˢ��
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}