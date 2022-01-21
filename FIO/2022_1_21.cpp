//Includes
#include<bits/stdc++.h>
using namespace std; 
//Defines
#define ten(x) ((x<<1)+(x<<3))
#define Fsize 100000
#if ONLINE_JUDGE
#define getchar() (A==B&&(B=(A=Fin)+fread(Fin,1,Fsize,stdin),A==B)?EOF:*A++)
#define putchar(Ch) (FoutSize<Fsize?Fout[FoutSize++]=Ch:(fwrite(Fout,1,Fsize,stdout),Fout[(FoutSize=0)++]=Ch))
#define inline __inline__ __attribute__((always_inline)) 
#endif
#define register 
//Vars
int Top, FoutSize; char Ch, * A, * B, Fin[Fsize], Fout[Fsize], Stack[Fsize];
//Functions
template<typename T> inline void read(register T& x) { x = 0; while (!isdigit(Ch = getchar())); while (x = ten(x) + (Ch & 15), isdigit(Ch = getchar())); }
inline void read(register char& x) { x = getchar(); }
inline void read(register char* x) { while ((*(x++) = getchar()) != '\n'); *(--x) = '\0'; }
template<typename T, typename... Args>inline void read(register T& x, register Args&... args) { read(x), read(args...); }

template<typename T> inline void write(register T& x) {if (!x)return (void)(putchar('0'));if (x < 0)putchar('-'),x = -x;while (x)Stack[++Top] = (x % 10) ^ 48, x /= 10;while (Top)putchar(Stack[Top--]);}
inline void write(register char& x) { putchar(x); }
inline void write(register char* x) { while (putchar(*(x++)), *x ^ '\0'); }
template<typename T, typename... Args> inline void write(register T x, register Args... args) { write(x), write(args...); }
inline int clear() { fwrite(Fout, 1, FoutSize, stdout); return FoutSize = 0; }
