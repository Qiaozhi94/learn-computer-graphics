#include <iostream>
#include <cmath>
using namespace std;
bool pic[50][50];


void DrawALine(int x0, int y0, int x1, int y1)
{
	int dx = fabs(x0 - x1);
	int dy = fabs(y0 - y1);
	int y = y0;
	int e = -2 * dx;
	for (auto x = x0; x <= 1; ++x) {
		pic[x][y] = true;
		e += 2 * dy;
		if (e > 0) ++y;
		if (e >= dx) e -= 2 * dx;
	}
}


void ShowPic() {

	for (auto i = 49; i >= 0; --i) {
		for (auto j : pic[i]) {
			if (j)
				cout << 'x' <<endl;
			else
				cout << 'o' <<endl;
		}
	}
}

int main() {

	DrawALine(2, 2, 40, 10);
	ShowPic();

	return 0;
}

