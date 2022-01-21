//Includes
#include<bits/stdc++.h>
using namespace std;OnlyTheBigFoolWillEnterThisVariable_
//Defines
#define ten(x) ((x<<1)+(x<<3))
#define OnlyTheBigFoolWillEnterThisVariable_Fsize 100000
#define Type(T) template<typename T> inline T
#define Type(T,body) template<typename T> inline body
#if ONLINE_JUDGE
#define getchar() (OnlyTheBigFoolWillEnterThisVariable_A==OnlyTheBigFoolWillEnterThisVariable_B&&(OnlyTheBigFoolWillEnterThisVariable_B=(OnlyTheBigFoolWillEnterThisVariable_A=OnlyTheBigFoolWillEnterThisVariable_Fin)+fread(OnlyTheBigFoolWillEnterThisVariable_Fin,1,OnlyTheBigFoolWillEnterThisVariable_Fsize,stdin),OnlyTheBigFoolWillEnterThisVariable_A==OnlyTheBigFoolWillEnterThisVariable_B)?EOF:*OnlyTheBigFoolWillEnterThisVariable_A++)
#define putchar(OnlyTheBigFoolWillEnterThisVariable_Ch) (OnlyTheBigFoolWillEnterThisVariable_FoutSize<OnlyTheBigFoolWillEnterThisVariable_Fsize?OnlyTheBigFoolWillEnterThisVariable_Fout[OnlyTheBigFoolWillEnterThisVariable_FoutSize++]=OnlyTheBigFoolWillEnterThisVariable_Ch:(fwrite(OnlyTheBigFoolWillEnterThisVariable_Fout,1,OnlyTheBigFoolWillEnterThisVariable_Fsize,stdout),OnlyTheBigFoolWillEnterThisVariable_Fout[(OnlyTheBigFoolWillEnterThisVariable_FoutSize=0)++]=OnlyTheBigFoolWillEnterThisVariable_Ch))
#define inline __inline__ __attribute__((always_inline)) 
#endif
//Vars
int OnlyTheBigFoolWillEnterThisVariable_Top, OnlyTheBigFoolWillEnterThisVariable_FoutSize; char OnlyTheBigFoolWillEnterThisVariable_Ch, * OnlyTheBigFoolWillEnterThisVariable_A, * OnlyTheBigFoolWillEnterThisVariable_B, OnlyTheBigFoolWillEnterThisVariable_Fin[OnlyTheBigFoolWillEnterThisVariable_Fsize], OnlyTheBigFoolWillEnterThisVariable_Fout[OnlyTheBigFoolWillEnterThisVariable_Fsize], OnlyTheBigFoolWillEnterThisVariable_Stack[OnlyTheBigFoolWillEnterThisVariable_Fsize];
//Functions
Type(T, void read(register T& x) { x = 0; while (!isdigit(OnlyTheBigFoolWillEnterThisVariable_Ch = tc())); while (x = ten(x) + (OnlyTheBigFoolWillEnterThisVariable_Ch & 15), isdigit(OnlyTheBigFoolWillEnterThisVariable_Ch = tc())); });
Type(T, void read(register T*& x, size_t& Len) { register size_t index = 0; while (index < Len)read(x[Len++]); });
inline void read(register char& x) { x = getchar(); }
inline void read(register char* x) { while ((*(x++) = getchar()) != '\n'); *(--x) = '\0'; }
template<typename T, typename... Args>inline void read(register T& x, register Args&... args) { read(T), read(args...); }

Type(T, void write(register T& x) { if (!x) return (void)(putchar('0')); if (x < 0) putchar('-'), x = -x; while (x) OnlyTheBigFoolWillEnterThisVariable_Stack[++OnlyTheBigFoolWillEnterThisVariable_Top] = (x % 10) ^ 48, x /= 10; while (OnlyTheBigFoolWillEnterThisVariable_Top) putchar(OnlyTheBigFoolWillEnterThisVariable_Stack[OnlyTheBigFoolWillEnterThisVariable_Top--]); });
Type(T, void write(register T*& x, size_t& Len) { register size_t index = 0; while (index < Len)write(x[Len++]); });
inline void write(register char& x) { putchar(x); }
inline void write(register char* x) { while (putchar(*(x++)), *x ^ '\0'); }
template<typename T, typename... Args>inline void write(register T& x, register Args&... args) { write(T), write(args...); }

inline int clear() { fwrite(OnlyTheBigFoolWillEnterThisVariable_Fout, 1, OnlyTheBigFoolWillEnterThisVariable_FoutSize, stdout); return OnlyTheBigFoolWillEnterThisVariable_FoutSize = 0; }