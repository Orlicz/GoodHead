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
//Vars
static struct ArrayWriter { char Insert = ' ', End = '\n'; }war;
template<typename T = char> struct VectorIOer { T* x; int Len; template<typename Other>inline VectorIOer<Other>& operator()(Other* x, int Len) { VectorIOer<Other> e; e.Len = Len, e.x = x; return e; } }; VectorIOer vio;
template<typename T = double> struct DoubleWriter { T* x; int Len; template<typename Other>inline DoubleWriter<Other>& operator()(Other* x, int Len) { DoubleWriter<Other> e; e.Len = Len, e.x = x; return e; } }; DoubleWriter dio;
int Index, Top, FoutSize; char Ch, * A, * B, Fin[Fsize], Fout[Fsize], Stack[Fsize];
//Functions
template<typename T> inline void read(register T& x) { bool sign = 0; x = 0; while (!((Ch = getchar()) == '-' ? Ch = getchar(), sign = 1 : isdigit(Ch))); while (x = ten(x) + (Ch & 15), isdigit(Ch = getchar())); x = sign ? opposite(x) : x; }
inline void read(register char& x) { x = getchar(); }
inline void read(register char* x) { while ((*(x++) = getchar()) != '\n'); *(--x) = '\0'; }
inline void read(register double& x) { double On = 1; bool sign = 0, dot = 1; x = 0; while (!((Ch = getchar()) == '-' ? Ch = getchar(), sign = 1 : isdigit(Ch))); while (x = x * 10 + (Ch & 15), ((Ch = getchar()) == '.' ? Ch = getchar(), dot = 0 : isdigit(Ch))); if (!dot)while (x = x + (Ch & 15)/(On*=10), isdigit(Ch = getchar())); x = sign ? -(x) : x; }
template<size_t Len, typename T> inline void read(T* x) { Index = 0; while (read(*(x + Index++)), Index != Len); }
template<typename T> inline void read(register VectorIOer<T>&& io) { Index = 0; while (read(*(io.x + Index++)), Index != io.Len); }
template<typename T> inline void read(register VectorIOer<T>& io) { Index = 0; while (read(*(io.x + Index++)), Index != io.Len); }
template<typename T, typename... Args>inline void read(register T& x, register Args&... args) { read(x), read(args...); }
template<typename T> inline void write(register T x) { if (!x)return (void)(putchar('0')); if (x < 0)putchar('-'), x = -x; while (x)Stack[++Top] = (x % 10) ^ 48, x /= 10; while (Top)putchar(Stack[Top--]); }
inline void write(register char& x) { putchar(x); }
inline void write(register char* x) { while (putchar(*(x++)), *x ^ '\0'); }
inline void write(const char x[]) { register int i = 0; while (putchar(x[i++]), x[i] ^ '\0'); }
template<size_t Len, typename T> inline void write(T* x) { Index = 0; while (write(*(x + Index++)), Index != Len) putchar(war.Insert); putchar(war.End); }
template<typename T> inline void write(register VectorIOer<T>&& io) { Index = 0; while (write(*(io.x + Index++)), Index != io.Len) putchar(war.Insert); putchar(war.End); }
template<typename T> inline void write(register VectorIOer<T>& io) { Index = 0; while (write(*(io.x + Index++)), Index != io.Len) putchar(war.Insert); putchar(war.End); }
template<typename T> inline void write(register DoubleWriter<T>& io) { while(putchar) }
#define ll long long 
inline void write(double x, int k = 6)
{
    static int n = pow(10, k);
    if (x == 0)
    {
        putchar('0'), putchar('.');
        for (int i = 1; i <= k; ++i) putchar('0');
        return;
    }
    if (x < 0) putchar('-'), x = -x;
    ll y = (ll)(x * n) % n; x = (ll)x;
    write(x), putchar('.');
    int bit[10], p = 0, i;
    for (; p < k; y /= 10) bit[++p] = y % 10;
    for (i = p; i > 0; i--) putchar(bit[i] + 48);
}
template<typename T, typename... Args> inline void write(register T x, register Args... args) { write(x), write(args...); }
inline int clear() { fwrite(Fout, 1, FoutSize, stdout); return FoutSize = 0; }
