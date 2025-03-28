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
//XMVECTOR类型作为函数的参数时要使用
//FXMVECTOR类型(前三个)，GXMVECTOR类型(第四个),HXMVECTOR类型(5，6个)
//其余使用CXMVECTOR类型
//将XMVECTOR转换为XMFLOAT3,类中使用XMFLOAT3类型要传唤为XMVECTOR
//XMVECTOR类型的数据需要按16字节对齐，
//这对于局部变量和全局变量时自动实现的，至于类中的数据成员，需要分别使用XMFLOAT3类型（3d向量）加以代替
//加载方法XMFLOAT3类型加载到XMVECTOR类型
//存储方法XMVECTOR类型存储到XMFLOAT3类型
export ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	os << format("({},{},{})", dest.x, dest.y, dest.z);
	return os;
}
int a(int i);