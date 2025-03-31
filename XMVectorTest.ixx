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
	cout.setf(ios_base::boolalpha);//����Ϊtrue��false
	//���CPU�Ƿ�֧��SSE2
	if (!XMVerifyCPUSupport())
	{
		cout << "���ָ�" << endl;
		exit(1);//�쳣�˳�
	}
	XMVECTOR v1{ XMVectorZero() };//����0����
	XMVECTOR v2{ XMVectorSplatOne() };//��������(1.1.1.1)
	XMVECTOR v3{ XMVectorSet(1.0f,2.0f,3.0f,4.0f) };//����ָ������;
	XMVECTOR v4{ XMVectorReplicate(1.0f) };//��������(1.0f.1.0f.1.0f.1.0f)
	XMVECTOR v5{ XMVectorSplatX(v3) };//����x
	XMVECTOR v6{ XMVectorSplatY(v3) };//����y
	XMVECTOR v7{ XMVectorSplatZ(v3) };//����z
	cout << "v1=" << v1 << endl;
	cout << "v1=" << v2 << endl;
	cout << "v1=" << v3 << endl;
	cout << "v1=" << v4 << endl;
	cout << "v1=" << v5 << endl;
	cout << "v1=" << v6 << endl;
	cout << "v1=" << v7 << endl;
}