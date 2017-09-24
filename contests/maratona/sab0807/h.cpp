#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>

typedef long long ll;

struct PT
{
	ll x, y;

	PT(){PT(0, 0);}
	PT(ll xx, ll yy){x = xx; y = yy;}

	ll operator *(PT a)
	{
		return a.x * y - a.y * x;
	}

	PT operator -(PT a)
	{
		return PT(x - a.x, y - a.y);
	}

	PT operator +(PT a)
	{
		return PT(x + a.x, y + a.y);
	}

	PT operator *(ll a)
	{
		return PT(x * a, y * a);
	}

	PT operator /(ll a)
	{
		return PT(x / a, y / a);
	}
	void read()
	{
		std::cin >> x >> y;
		x *= 4;
		y *= 4;
	}
	void print()
	{
		std::cout << "(" << x / 4 << ", " << y / 4 << ")\n";
	}
};

PT a[4];

bool cmp(PT b, PT c)
{
	return (b - a[0]) * (c - a[0]) > 0;
}

int main()
{
	std::cout << std::fixed << std::setprecision(3);
	while(1)
	{
		bool skip = true;
		for(int i = 0; i < 4; i++)
		{
			a[i].read();
			if(a[i].y < a[0].y || (a[i].y == a[0].y && a[i].x < a[0].x))
				std::swap(a[0], a[i]);
			skip = skip && a[i].x == 0 && a[i].y == 0;
		}
		if(skip)
			break;
		std::sort(a + 1, a + 4, cmp);
		for(int i = 0; i < 4; i++)
			a[i].print();
		ll ans = llabs((a[1] - a[0]) * (a[2] - a[0]));
		ll area = ans + llabs((a[2] - a[0]) * (a[3] - a[0]));
		ans = std::min(area - ans, ans);
		for(int i = 0; i < 4; i++)
		{
			std::cout << "on " << i << ":\n";
			PT med = (a[(i + 1) % 4] + a[(i + 2) % 4]) / 2;
			ll cur_area = llabs((a[(i + 1) % 4] - a[i]) * (med - a[i]));
			cur_area = std::min(area - cur_area, cur_area);
			
			ans = std::max(ans, cur_area);
			
			med = (a[(i + 2) % 4] + a[(i + 3) % 4]) / 2;
			cur_area = llabs((a[(i + 3) % 4] - a[i]) * (med - a[i]));
			cur_area = std::min(area - cur_area, cur_area);
			ans = std::max(ans, cur_area);
			
			cur_area = llabs((a[(i + 1) % 4] - a[i]) * (a[(i + 2) % 4] - a[i]));
			cur_area = std::min(area - cur_area, cur_area);
			ans = std::max(ans, cur_area);
		}
		for(int i = 0; i < 4; i++)
		{
			for(int j = i; j < i + 3; j++)
			{
				PT med1 = (a[(i + 0) % 4] + a[(i + 3) % 4]) / 2;
				PT med2 = (a[(i + j) % 4] + a[(i + j + 3) % 4]) / 2;
				ll cur_area = (med1 * a[i % 4]) + (med2 * med1);
				for(int k = i; k < i + j - 1; k++)
					cur_area += a[k % 4] * a[(k + 1) % 4];
				cur_area = llabs(cur_area);
				cur_area = std::min(cur_area, area - cur_area);
				ans = std::max(cur_area, ans);
				std::cout << "got " << cur_area / 32.0 << "on (" << i << ", " << j << ")\n";
			}
		}
		std::cout << (double) ans / 32.0 << " " << (double) (area - ans) / 32.0 << '\n';
	}
}
