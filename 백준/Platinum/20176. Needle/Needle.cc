#include <iostream>
#include <complex>
#include <vector>

typedef std::complex<double> cpx;
int N;
const double PI = acos(-1);
std::vector <cpx> v[3];

void	FFT(std::vector <cpx> &f, cpx w)
{
	int n = f.size();
	if (n == 1)
		return ;
	std::vector <cpx> even(n / 2), odd(n / 2);
	int i = 0;
	while (i < n)
	{
		((i & 1) ? odd : even)[i / 2] = f[i];
		i++;
	}
	FFT(even, w * w);
	FFT(odd, w * w);
	cpx wp(1, 0);
	i = 0;
	while (i < n / 2)
	{
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
		i++;
	}
}

std::vector <cpx> multiply(std::vector<cpx> a, std::vector <cpx> b)
{
	int n = 1;
	while (n < a.size() + 1 || n < b.size() + 1)
		n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	std::vector <cpx> c(n);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	FFT(a, w);
	FFT(b, w);
	int i = 0;
	while (i < n)
	{
		c[i] = a[i] * b[i];
		i++;
	}
	FFT(c, cpx(1, 0) / w);
	i = 0;
	while (i < n)
	{
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
		i++;
	}
	return c;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	int i = 0;
	while (i < 3)
	{
		std::cin >> n;
		v[i].resize(60001);
		int j = 0;
		while (j < n)
		{
			int temp;
			std::cin >> temp;
			v[i][temp + 30000] = cpx(1, 0);
			j++;
		}
		i++;
	}
	std::vector <cpx> temp = multiply(v[0], v[2]);
	i = 0;
	int cnt = 0;
	while (i < v[1].size())
	{
		if (v[1][i].real() > 0)
			cnt += temp[i << 1].real();
		i++;
	}
	std::cout << cnt << "\n";
}
