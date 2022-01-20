#pragma region GoodHead
#define SafeStyle 0

#define _CRT_SECURE_NO_WARNINGS
#if SafeStyle
	namespace FastIO {
	template<typename... Args>
	inline void read(Args&... args){
		(cin>>...>>args);
	}
	template<typename... Args>
	inline void write(Args... args){
		(cout<<...<<args);
	}
	inline int clear(){
		return 0;
	}
	class FastIOStream{
	private:
	public:
		template<typename... T>
		FastIOStream& operator <<(T... t){
			return write(t...),*this;
		}
		template<typename... T>
		FastIOStream& operator >>(T&... t){
			return read(t...),*this;
		}
		FastIOStream& operator !(){
			return *this;
		}
	}cio;
}using namespace FastIO;
#else
	#define USE_IOGO
	#define USE_FUN
	#define USE_CIO
	
	#ifdef USE_IOGO
		#if _WIN32
			#include<cmath>
			#include<iostream>
			#include<algorithm>
			#define atline inline
		#else
			#include<bits/stdc++.h>
			#define atline __inline__ __attribute__((always_inline)) 
		#endif
		using namespace std;
		#define LL register long long
		namespace FastIO {
		#define ten(x) ((x<<1)+(x<<3))
		#define Fsize 100000
		#if ONLINE_JUDGE
			#define tc() (A==B&&(B=(A=Fin)+fread(Fin,1,100000,stdin),A==B)?EOF:*A++)
		
		#else
			auto _ = []() {
				return ios::sync_with_stdio(false),
				cin.tie(0),
				cout.tie(0);
			};
			auto __ = _();
			#define tc() cin.get()
		#endif
		#define pc(ch) (FoutSize<Fsize?Fout[FoutSize++]=ch:(fwrite(Fout,1,Fsize,stdout),Fout[(FoutSize=0)++]=ch))
		int Top, FoutSize; char ch, * A, * B, Fin[Fsize], Fout[Fsize], Stack[Fsize];
		
			
		#ifdef USE_CIO
			class FastIOStream{
			private:
			public:
				template<typename T>
				atline FastIOStream& operator >>(register T& x) { x = 0; while (!isdigit(ch = tc())); while (x = ten(x) + (ch & 15), isdigit(ch = tc())); return *this; }
				atline FastIOStream& operator >>(register char*& x) { register char index = 0; for (; ((x[index] = tc()) != ' ') && (x[index] != '\n'); ++index); x[index] = '\0'; return*this; }
				atline FastIOStream& operator >>(register char& x) { x = tc(); return *this; }
				template<typename T>
				atline FastIOStream& operator <<(register T x) { if (!x) { return (void)(pc('0')), * this; }if (x < 0) pc('-'), x = -x; while (x) Stack[++Top] = x % 10 + 48, x /= 10; while (Top) pc(Stack[Top--]); return *this; }
				atline FastIOStream& operator <<(register char* x) { for (; *x != '\0'; pc(*(x++))); return *this; }
				atline FastIOStream& operator <<(const char* x) { for (register int i = 0; i < sizeof(x); pc(x[i++])); return *this; }
				atline FastIOStream& operator <<(register char x) { pc(x); return *this; }
				atline FastIOStream& operator !() { return fwrite(Fout, 1, FoutSize, stdout), FoutSize = 0, * this; }
			}cio;
			
			atline void cret() { !cio, exit(0); }
		#endif
		#ifdef USE_FUN
			template<typename T>
			atline void read(register T& x) { x = 0; while (!isdigit(ch = tc())); while (x = ten(x) + (ch & 15), isdigit(ch = tc())); }
			atline void read(register char*& x) { register unsigned char index = 0; for (; ((x[index] = tc()) != ' ') && (x[index] != '\n'); ++index); x[index] = '\0'; }
			atline void read(register char& x) { x = tc(); }
			template<typename T, typename... I>
			atline void read(T& x, I&... y) { read(x), read(y...); }
			template<typename... I>
			atline void read(I*... x) { read(*x...); }
			template<typename... I>
			atline void read(const char* null,I*... x) { read(*x...); }

			template<typename T = long long>
			atline T read() { T ret, read(ret); return ret; }
			
			template<typename T>
			atline void write(register T x) { if (!x) return (void)(pc('0')); if (x < 0) pc('-'), x = -x; while (x) Stack[++Top] = x % 10 + 48, x /= 10; while (Top) pc(Stack[Top--]); }
			atline void write(register char* x) { for (; *x != '\0'; pc(*(x++))); }
			atline void write(const char* x) { for (register int i = 0; i < sizeof(x); pc(x[i++])); }
			atline void write(register char x) { pc(x); }
			template<typename T, typename... I>
			atline void write(register T x, register I... y) { write(x), write(y...); }
			atline int clear() { fwrite(Fout, 1, FoutSize, stdout);return FoutSize = 0; }
			
			atline void fret() { exit(clear()); }
		#endif
	}using namespace FastIO;
	#endif
#endif
#pragma endregion
