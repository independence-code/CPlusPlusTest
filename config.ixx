export module config;
import <iostream>;
import <string>;
import <vector>;
import "format";
import "DirectXMath.h";
import "DirectXMath.h";
import "DirectXPackedVector.h";
import "windows.h";
import "iostream";
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;
//XMVECTOR������Ϊ�����Ĳ���ʱҪʹ��
//FXMVECTOR����(ǰ����)��GXMVECTOR����(���ĸ�),HXMVECTOR����(5��6��)
//����ʹ��CXMVECTOR����
//��XMVECTORת��ΪXMFLOAT3,����ʹ��XMFLOAT3����Ҫ����ΪXMVECTOR
//XMVECTOR���͵�������Ҫ��16�ֽڶ��룬
//����ھֲ�������ȫ�ֱ���ʱ�Զ�ʵ�ֵģ��������е����ݳ�Ա����Ҫ�ֱ�ʹ��XMFLOAT3���ͣ�3d���������Դ���
//���ط���XMFLOAT3���ͼ��ص�XMVECTOR����
//�洢����XMVECTOR���ʹ洢��XMFLOAT3����
export ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	os << format("({},{},{})", dest.x, dest.y, dest.z);
	return os;
}
int a(int i);