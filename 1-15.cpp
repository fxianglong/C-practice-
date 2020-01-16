//#include<iostream>
//
//using namespace std;
//int main()
//{
//	unsigned char a = 0xA5;
//	unsigned char b = ~a >> 4 + 1;
//	printf("%d", b);
//	system("pause");
//	return 0;
//}

//int cal_score(int score[], int judge[], int N)
//{
//	int ret = 0, n = 0, m = 0;
//	double sum1 = 0, sum2 = 0;
//	if (N&&score&&judge){
//		for (int i = 0; i < N; i++)
//		{
//			switch (judge[i])
//			{
//			case 1:sum1 += score[i]; n++; break;
//			case 0:sum2 += score[i]; m++;break;
//			}
//		}
//	}
//	if (n) sum1 = (int)sum1 / n;
//	if (m) sum2 = (int)sum2 / m;
//	ret = n ? sum1*0.6 + sum2*0.4 : sum2;
//	return ret;
//}
//int main()
//{
//	int score[] = { 98, 97, 98, 98, 94, 93 };
//	int judge[] = { 1, 0, 0, 0, 0, 1 };
//	cout << cal_score(score, judge, 6) << endl;
//	system("pause");
//	return 0;
//}

const int bufsize = 100;
#include<Windows.h>
#include<iostream>
#define BUF_SIZE 30
using namespace std;
class A
{
public:
	A();
	~A(){};
public:
	inline const[A] BYTE* GetBuffer() const[B] {return m_pBuf; }
	int Pop(void);
private:
	const[C] BYTE * const[D] m_pBuf;
};

A::A() m_pBuf()
{
	BYTE* pBuf = new BYTE(BUF_SIZE);
	if (pBuf == NULL){
		return;
		for (int i = 0; i < BUF_SIZE; i++)
		{
			pBuf[i] = i;
		}
		m_pBuf = pBuf;
	}
}

int main()
{
	A a;
	CONST[E] BYTE* pb = a.GetBuffer();
	if (pB != NULL)
	{
		for (int i = 0; i < BUF_SIZE; i++)
		{
			printf("%u", pB(i++));
		}
	}
	system("pause");
	return 0;
}











