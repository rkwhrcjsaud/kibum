#include <iostream>
#include <complex>
#include <vector>

typedef std::complex<double> cpx;
int N, M;
const double PI = acos(-1);
std::vector <cpx> v;

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
	std::cin >> N;
	std::vector <cpx> v;
	int i = 1;
	v.resize(1);
	v[0] = cpx(1, 0);
	while (i <= N)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp >= v.size())
			v.resize(tmp + 1);
		v[tmp] = cpx(1, 0);
		i++;
	}
	std::vector <cpx> ans = multiply(v, v);
	std::cin >> M;
	i = 1;
	int cnt = 0;
	while (i <= M)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp < ans.size() && ans[tmp].real())
			cnt++;
		i++;
	}
	std::cout << cnt << "\n";
}
