#include <iostream>
#include <cmath>
using namespace std;


char pic[50][50] = { 0 };

void show_pic() {
	for (int i = 49; i >= 0; --i) {
		for (int j = 0; j < 50; j++) {
			if (pic[i][j] == 1) printf("x ");
			else printf("o ");
		}
		printf("\n");
	}
}
void drawline_old(int x0, int y0, int x1, int y1) {
	int dx = abs(x0 - x1);
	int dy = abs(y0 - y1);
	printf("dx: %d,dy: %d \n", dx, dy);

	int y = y0, e = -2 * dx;
	for (int x = x0; x <= x1; ++x) {
		pic[y][x] = 1;
		e += 2 * dy;
		if (e > 0) ++y;
		if (e >= dx) e -= 2 * dx;
	}
}
// ʹ�� Bresenham �㷨������б�ʵ�ֱ�ߣ�������ʼ�㣬��������ֹ�㣩
void Line_Bresenham(int x1, int y1, int x2, int y2) {
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int s1 = x2 > x1 ? 1 : -1;
	int s2 = y2 > y1 ? 1 : -1;

	char interchange = 0;	// Ĭ�ϲ����� dx��dy
	if (dy > dx)				// ��б�ʴ��� 1 ʱ��dx��dy ����
	{
		int temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}

	int p = 2 * dy - dx;
	for (int i = 0; i < dx; i++)
	{
		pic[y][x] = 1;
		if (p >= 0)
		{
			if (!interchange)		// ��б�� < 1 ʱ��ѡȡ�������ص�
				y += s2;
			else					// ��б�� > 1 ʱ��ѡȡ�������ص�
				x += s1;
			p -= 2 * dx;
		}
		if (!interchange)
			x += s1;				// ��б�� < 1 ʱ��ѡȡ x Ϊ����
		else
			y += s2;				// ��б�� > 1 ʱ��ѡȡ y Ϊ����
		p += 2 * dy;
	}
}

int main(void) {
	//drawline_old(2,2,50,10);
	Line_Bresenham(2, 2, 50, 10);
	show_pic();
	return EXIT_SUCCESS;
}
