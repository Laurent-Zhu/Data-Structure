#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int squareCount = 0;
    int minSide = min(n, m);
    for (int size = 1; size <= minSide; size++) {
        squareCount += (n - size + 1) * (m - size + 1);
    }

    // �����ܳ���������
    int totalRectangles = (n * (n + 1) / 2) * (m * (m + 1) / 2);
    cout << squareCount << " " << totalRectangles - squareCount;

    
    return 0;
}
