export module XMVectorTest;
import config;
import "DirectXMath.h";
import "DirectXPackedVector.h";
import "windows.h";
import "iostream";
import "format";
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

export void testVector()
{
	cout.setf(ios_base::boolalpha);//设置为true和false
	//检查CPU是否支持SSE2
	if (!XMVerifyCPUSupport())
	{
		cout << "检查指令集" << endl;
		exit(1);//异常退出
	}
	XMVECTOR v1{ XMVectorZero() };//返回0向量
	XMVECTOR v2{ XMVectorSplatOne() };//返回向量(1.1.1.1)
	XMVECTOR v3{ XMVectorSet(1.0f,2.0f,3.0f,4.0f) };//返回指定向量;
	XMVECTOR v4{ XMVectorReplicate(1.0f) };//返回向量(1.0f.1.0f.1.0f.1.0f)
	XMVECTOR v5{ XMVectorSplatX(v3) };//返回x
	XMVECTOR v6{ XMVectorSplatY(v3) };//返回y
	XMVECTOR v7{ XMVectorSplatZ(v3) };//返回z
	cout << "v1=" << v1 << endl;
	cout << "v1=" << v2 << endl;
	cout << "v1=" << v3 << endl;
	cout << "v1=" << v4 << endl;
	cout << "v1=" << v5 << endl;
	cout << "v1=" << v6 << endl;
	cout << "v1=" << v7 << endl;
}