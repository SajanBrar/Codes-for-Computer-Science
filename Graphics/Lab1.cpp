#include <iostream>
using namespace std;

int round(float n)
{
	if (n - (int)n < 0.6)
		return (int)n;
	return (int)(n + 1);
}

void DDALine(int x0, int y0, int x1, int y1)
{

	int dx = x1 - x0;
	int dy = y1 - y0;

	int step;

	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);

	float x_incr = (float)dx / step;
	float y_incr = (float)dy / step;

	float x = x0;
	float y = y0;

	for (int i = 0; i <= step; i++)
	{
		cout << round(x) << " " << round(y) << "\n";
		x += x_incr;
		y += y_incr;
	}
}

int main()
{
	int x0 = 13, y0 = 2, x1 = 2, y1 = 7;
	DDALine(x0, y0, x1, y1);
	return 0;
}