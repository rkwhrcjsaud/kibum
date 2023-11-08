#include <iostream>
#include <complex>
#include <vector>

typedef std::complex<double> cpx;
int T;
const double PI = acos(-1);
bool prime[1000001];

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

void	eratos(void)
{
	int max = 1000;
	std::fill(prime + 2, prime + 1000000, true);
	int i = 2;
	while (i <= max)
	{
		int j = 2;
		while (i * j <= 1000000)
		{
			prime[i * j] = false;
			j++;
		}
		i++;
		while (prime[i] == false)
			i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	eratos();
	int i = 3;
	std::vector <cpx> v1(1000001);
	std::vector <cpx> v2(1000001);
	v2[4] = cpx(1, 0);
	while (i <= 1000000)
	{
		if (prime[i] == true)
		{
			v1[i] = cpx(1, 0);
			if ((i << 1) <= 1000000)
				v2[i << 1] = cpx(1, 0);
		}
		i++;
	}
	std::vector <cpx> ans = multiply(v1, v2);
	while (T--)
	{
		int N;
		std::cin >> N;
		std::cout << ans[N].real() << "\n";
	}
}
