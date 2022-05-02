#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define tsz template<size_t ts>
#define tpe template<typename tp>
namespace FFTSpace {
#define inline inline
#define MAXN 3000100

	using namespace std;
	char s1[MAXN], s2[MAXN];
	int N, M, K, res = 0, ans[MAXN], AA, BB;
	int i, j, k, l, Lim = 1, L, R[MAXN];
	const double Pi = acos(-1.0);
	struct node {
		double x, y;
		node(double xx = 0, double yy = 0) {
			x = xx, y = yy;
		}
	}A[MAXN], B[MAXN];
	node operator * (node J, node Q) {
		return node(J.x * Q.x - J.y * Q.y, J.x * Q.y + J.y * Q.x);
	}
	node operator + (node J, node Q) {
		return node(J.x + Q.x, J.y + Q.y);
	}
	node operator - (node J, node Q) {
		return node(J.x - Q.x, J.y - Q.y);
	}
	inline void FFT(node* J, double flag) {
		for (i = 0; i < Lim; i++)
			if (i < R[i]) swap(J[i], J[R[i]]);
		for (j = 1; j < Lim; j <<= 1) {
			node T(cos(Pi / j), flag * sin(Pi / j));
			for (k = 0; k < Lim; k += (j << 1)) {
				node t(1, 0);
				for (l = 0; l < j; l++, t = t * T) {
					node Nx = J[k + l], Ny = t * J[k + j + l];
					J[k + l] = Nx + Ny;
					J[k + j + l] = Nx - Ny;
				}
			}
		}
	}
	int maisn() {
		//scanf("%s%s", s1, s2);
		N = max(strlen(s1), strlen(s2));
		int M = min(strlen(s1), strlen(s2));
		if (strlen(s1) > strlen(s2)) {
			for (int i = strlen(s2); i < strlen(s1); i++)
				s2[i] = 48;
		}
		else {
			for (int i = strlen(s1); i < strlen(s2); i++)
				s1[i] = 48;
		}//
		for (i = N - 1; i >= 0; i--) A[AA++].x = s1[i] - 48;
		for (i = N - 1; i >= 0; i--) B[BB++].x = s2[i] - 48;
		while (Lim < N + N) Lim <<= 1, L++;
		for (i = 0; i <= Lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
		FFT(A, 1), FFT(B, 1);
		for (i = 0; i <= Lim; i++) A[i] = A[i] * B[i];
		FFT(A, -1);
		int tot = 0;
		for (i = 0; i <= Lim; i++) {
			ans[i] += (int)(A[i].x / Lim + 0.5);
			if (ans[i] >= 10)
				ans[i + 1] += ans[i] / 10, ans[i] %= 10, Lim += (i == Lim);
		}//
		while (!ans[Lim] && Lim >= 1) Lim--;
		Lim++;
		while (--Lim >= N - M) cout << ans[Lim];
		return 0;
	}
}using namespace FFTSpace;
template<size_t Size>
struct BigInt{
	using me = BigInt<Size>;
	using mes = BigInt<Size>&;
	using st = size_t;
	using ofs = ostream&;
	using ifs = istream&;
	char val[Size];






#pragma region InitEqsIO

	BigInt() {
		memset(val, 0, Size);
	}
	tsz	inline mes operator= (BigInt<ts> Other) {
		for (st i = 0; i < Size; ++i) val[i] = Other.val[i];
		return *this;
	}
	
	tpe inline mes operator=(tp Others) {
		for (st i = 0; Others; ++i, Others /= 10) {
			val[i] = Others % 10;
		}
		return *this;
	}
	inline friend ofs operator << (ofs out, const mes I) {
		st top=Size;
		while (!I.val[--top]);
		do out << char(I.val[top] ^ 48); while (top--);
		return out;
	}
	inline friend ifs operator >> (ifs in, mes I) {
		char cch[Size];
		cin >> cch;
		st top = strlen(cch)-1;
		auto pot = top;
		do I.val[pot - top] = cch[top]^48; while (top--);
		return in;
	}
#pragma endregion
#pragma region Add	
	tsz mes operator+(const BigInt<ts> Other) {
		for (st i = 0; i < Size; ++i) val[i] += Other.val[i];
		for (st i = 0; i < Size; ++i) val[i + 1] += (val[i] / 10), val[i] = val[i] % 10;
		return *this;
	}
	tpe mes operator+(tp Others) {
		for (st i = 0; Others; ++i,Others/=10) val[i] += Others%10;
		for (st i = 0; i < Size; ++i) val[i + 1] += (val[i] / 10), val[i] = val[i] % 10;
		return *this;
	}
#pragma endregion
#pragma region Times
	mes operator*(mes Other) {
		st s1l = Size, s2l = Size;
		while (val[--s1l]);
		while (Other.val[--s2l]);
		N = max(s1l, s2l);
		int M = min(s1l, s2l);
		for (i = N - 1; i >= 0; i--) A[i].x = val[i];
		for (i = N - 1; i >= 0; i--) B[i].x = Other.val[i];
		while (Lim < N + N) Lim <<= 1, L++;
		for (i = 0; i <= Lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
		FFT(A, 1), FFT(B, 1);
		for (i = 0; i <= Lim; i++) A[i] = A[i] * B[i];
		FFT(A, -1);
		int tot = 0;
		for (i = 0; i <= Lim; i++) {
			ans[i] += (int)(A[i].x / Lim + 0.5);
			if (ans[i] >= 10)
				ans[i + 1] += ans[i] / 10, ans[i] %= 10, Lim += (i == Lim);
		}

		while (!ans[Lim] && Lim >= 1) Lim--;
		Lim++;
		st ttop = 0;
		char Sta[Size];
		while (--Lim >= N - M) cout<<(ans[Lim]);
		ttop--;
		//for (st i = 0; i <= ttop; ++i) val[i] = Sta[ttop - i];
		return *this;
	}
#pragma endregion

};
int main() {
	BigInt<1000000> bt,at;
	cin >> at >> bt;
	at * bt;

}
