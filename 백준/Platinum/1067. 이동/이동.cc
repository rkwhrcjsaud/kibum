#include <iostream>
#include <complex>
#include <vector>

#define MAX(a, b) (a > b ? a : b)
typedef std::complex<double> cpx;
int N;
const double PI = acos(-1);
std::vector <cpx> v1;
std::vector <cpx> v2;

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
	v1.resize(N << 1);
	v2.resize(N << 1);
	int i = 0;
	while (i < N)
	{
		int temp;
		std::cin >> temp;
		v1[i] = cpx(temp, 0);
		v1[N + i] = v1[i];
		i++;
	}
	i = 0;
	while (i < N)
	{
		int temp;
		std::cin >> temp;
		v2[N - i - 1] = cpx(temp, 0);
		i++;
	}
	std::vector<cpx> ans = multiply(v1, v2);
	int max = 0;
	i = 0;
	while (i < ans.size())
	{
		max = MAX(max, ans[i].real());
		i++;
	}
	std::cout << max << "\n";
}
