//Includes
#include<bits/stdc++.h>
using namespace std;
//Defines
#define ten(x) (((x)<<1)+((x)<<3))
#define opposite(x) ((~(x))+1)
#define Fsize 100000
#ifdef ONLINE_JUDGE
#define getchar() (A==B&&(B=(A=Fin)+fread(Fin,1,Fsize,stdin),A==B)?EOF:*A++)
#define putchar(Ch) (FoutSize<Fsize?Fout[FoutSize++]=Ch:(fwrite(Fout,1,Fsize,stdout),Fout[(FoutSize=0)++]=Ch))
#define inline __inline__ __attribute__((always_inline)) 
#endif
#define register 
//Requires
template<typename T>concept Double = std::is_same<T, float>::value || std::is_same<T, double>::value || std::is_same<T, long double>::value;
template<typename T>concept Int = std::is_integral<T>::value;
//Vars
template<typename T = long long> constexpr T Pow10[10] = { 10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000 };
static struct ArrayWriter { char Insert = ' ', End = '\n'; }war;
template<typename T = char> struct VectorIOer { T* x; int Len; template<typename Other>inline VectorIOer<Other>& operator()(Other* x, int Len) { VectorIOer<Other> e; e.Len = Len, e.x = x; return e; } }; VectorIOer vio;
int Index, Top, FoutSize; char Ch, * A, * B, Fin[Fsize], Fout[Fsize], Stack[Fsize];
//Functions
template<Int T> inline void read(register T& x) { bool sign = 0; x = 0; while (!((Ch = getchar()) == '-' ? Ch = getchar(), sign = 1 : isdigit(Ch))); while (x = ten(x) + (Ch & 15), isdigit(Ch = getchar())); x = sign ? opposite(x) : x; }
template<Double T> inline void read(register T& x) { bool sign = 0; x = 0, Index = 1; while (!((Ch = getchar()) == '-' ? Ch = getchar(), sign = 1 : isdigit(Ch))); while (x = 10 * x + (Ch & 15), isdigit(Ch = getchar())); if (Ch == '.' && (Ch = getchar())) while (x += T(Ch & 15) / (Index *= 10), isdigit(Ch = getchar())); x = sign ? -x : x; }
inline void read(register char& x) { x = getchar(); }
inline void read(register char* x) { while ((*(x++) = getchar()) != '\n'); *(--x) = '\0'; }
template<size_t Len, typename T> inline void read(T* x) { Index = 0; while (read(*(x + Index++)), Index != Len); }
template<typename T> inline void read(register VectorIOer<T>&& io) { Index = 0; while (read(*(io.x + Index++)), Index != io.Len); }
template<typename T> inline void read(register VectorIOer<T>& io) { Index = 0; while (read(*(io.x + Index++)), Index != io.Len); }
template<typename T, typename... Args>inline void read(register T& x, register Args&... args) { read(x), read(args...); }
template<Int T> inline void write(register T x) { if (!x)return (void)(putchar('0')); if (x < 0)putchar('-'), x = -x; while (x)Stack[++Top] = (x % 10) ^ 48, x /= 10; while (Top)putchar(Stack[Top--]); }
inline void write(register char& x) { putchar(x); }
inline void write(register char* x) { while (putchar(*(x++)), *x ^ '\0'); }
inline void write(const char x[]) { register int i = 0; while (putchar(x[i++]), x[i] ^ '\0'); }
template<size_t Len, typename T> inline void write(T* x) { Index = 0; while (write(*(x + Index++)), Index != Len) putchar(war.Insert); putchar(war.End); }
template<typename T> inline void write(register VectorIOer<T>&& io) { Index = 0; while (write(*(io.x + Index++)), Index != io.Len) putchar(war.Insert); putchar(war.End); }
template<typename T> inline void write(register VectorIOer<T>& io) { Index = 0; while (write(*(io.x + Index++)), Index != io.Len) putchar(war.Insert); putchar(war.End); }
template<Double T>inline void write(T X, int k = 6) { long long x = X; if (!x) (putchar('0')); if (x < 0)putchar('-'), x = -x; while (x)Stack[++Top] = (x % 10) ^ 48, x /= 10; while (Top)putchar(Stack[Top--]); if (!k) return; putchar('.'), Index = 1; if (!(X -= (long long)X))while (k--) putchar('0'); write((long long)(X * Pow10<long long>[k])); }
template<typename T, typename... Args> inline void write(register T x, register Args... args) { write(x), write(args...); }
inline int clear() { fwrite(Fout, 1, FoutSize, stdout); return FoutSize = 0; }


template<Int T>
T power(T&& a, T&& b, T&& c) {//¿ìËÙÃÝ
	if (b == 0)
		return 1 % c;
	long long ans = 1, t = a;
	while (b > 0) {
		if (b & 1) ans = ans * t % c;
		b /= 2; t = t * t % c;
	}
	return ans;
}
template<Int T>
void exgcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}
template<Int T,Int Y,Int P>
inline void setinv(T* inv, Y p , P go) {
	inv[1] = 1;
	for (Y i = 2; i < go; ++i)
		inv[i] = (p - p / i) * inv[p % i] % p;
}
template<Int Y>
Y powmod(Y a, Y b, Y p) {
	Y res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % p;
		a = a * a % p, b >>= 1;
	}
	return res;
}

// Finds the primitive root modulo p
template<Int R>
int generator(R p) {
	vector<R> fact;
	R phi = p - 1, n = phi;
	for (R i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) fact.push_back(n);
	for (R res = 2; res <= p; ++res) {
		bool ok = true;
		for (R factor : fact) {
			if (powmod(res, phi / factor, p) == 1) {
				ok = false;
				break;
			}
		}
		if (ok) return res;
	}
	return -1;
}
