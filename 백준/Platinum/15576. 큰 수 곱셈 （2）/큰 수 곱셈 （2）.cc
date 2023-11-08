#include <iostream>
#include <complex>
#include <vector>

typedef long long ll;
typedef std::complex<double> cpx;
std::string A, B;
const double PI = acos(-1);
bool prime[1000001];

void	FFT(std::vector <cpx> &f, cpx w)
{
	ll n = f.size();
	if (n == 1)
		return ;
	std::vector <cpx> even(n / 2), odd(n / 2);
	ll i = 0;
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
	ll n = 1;
	while (n < a.size() + 1 || n < b.size() + 1)
		n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	std::vector <cpx> c(n);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	FFT(a, w);
	FFT(b, w);
	ll i = 0;
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
	std::cin >> A >> B;
	ll i = 0;
	std::vector <cpx> v1;
	std::vector <cpx> v2;
	std::vector <ll> v3;
	while (i < A.size())
		v1.push_back(cpx(A[A.size() - 1 - i++] - '0', 0));
	i = 0;
	while (i < B.size())
		v2.push_back(cpx(B[B.size() - 1 - i++] - '0', 0));
	std::vector <cpx> ans = multiply(v1, v2);
	ll max = ans.size() - 1;
	while (ans[max].real() == 0)
		max--;
	ll temp = 0;
	i = 0;
	while (i <= max)
	{
		v3.push_back(((ll)ans[i].real() + temp) % 10);
		temp = ((ll)ans[i].real() + temp) / 10;
		i++;
	}
	while (temp)
	{
		v3.push_back(temp % 10);
		temp /= 10;
	}
	i = v3.size() - 1;
	if (i == -1)
	{
		std::cout << "0\n";
		return (0);
	}
	while (i >= 0)
		std::cout << v3[i--];
	std::cout << "\n";
}
