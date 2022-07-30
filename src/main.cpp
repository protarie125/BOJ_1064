#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	const auto& px = x2 - x1;
	const auto& py = y2 - y1;

	const auto& qx = x3 - x1;
	const auto& qy = y3 - y1;

	if (px * qy == py * qx) {
		cout << -1;
		return 0;
	}

	const auto& ax = static_cast<double>(x1 - x2);
	const auto& ay = static_cast<double>(y1 - y2);
	const auto& a = sqrt(ax * ax + ay * ay);

	const auto& bx = static_cast<double>(x2 - x3);
	const auto& by = static_cast<double>(y2 - y3);
	const auto& b = sqrt(bx * bx + by * by);

	const auto& cx = static_cast<double>(x3 - x1);
	const auto& cy = static_cast<double>(y3 - y1);
	const auto& c = sqrt(cx * cx + cy * cy);

	auto v = vector<double>{ a, b, c };
	sort(v.begin(), v.end());

	const auto& mn = 2 * (v[0] + v[1]);
	const auto& mx = 2 * (v[1] + v[2]);

	cout << fixed << setprecision(10) << mx - mn;

	return 0;
}