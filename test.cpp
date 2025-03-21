import std;
using namespace std;
class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;//显式默认的默认构造函数
	SpreadsheetCell(int c);
	SpreadsheetCell(double s);
	explicit SpreadsheetCell(int c, double s);//显式转换构造函数
	SpreadsheetCell(const string& name);//委托构造函数
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);//返回值是引用可连续使用等号
	int a{ 0 };
	double double_a{};
	vector<int> int_A{};
};

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	//避免自赋值
	if (this != &rhs) {
		this->a = rhs.a;
		this->double_a = rhs.double_a;
		this->int_A = rhs.int_A;
	}
	return *this;
}
SpreadsheetCell::SpreadsheetCell(int c)
{
	a = c;
	cout << format("INT构造函数{}",a)<< endl;
}
SpreadsheetCell::SpreadsheetCell(int c, double s) :a{ c }, double_a{ s }
{
	cout << format("INT,DOUBLE构造函数{},{}", a, double_a) << endl;
}
SpreadsheetCell::SpreadsheetCell(const string& name):SpreadsheetCell(10)
{
	cout << "委托构造函数" << endl;
}
SpreadsheetCell ::SpreadsheetCell(double s):double_a{s}
{

	cout << format("DOUBLE构造函数{}",double_a) << endl;
}

class EvenSequnce
{
public:
	//初始化列表构造函数
	EvenSequnce(initializer_list<double> args)
	{
		if (args.size() % 2 != 0) {
			throw invalid_argument{ "initializer_list should"
			"contain even number of elements." };
		}
		m_sequnce.reserve(args.size());
		for (const auto& value : args) {
			m_sequnce.push_back(value);
		}
	}
	void dump()const
	{
		for (const auto& value : m_sequnce) {
			cout << value << ",";
		}
		cout << endl;
	}
private:
	vector<double> m_sequnce;
};
int main()
{
    EvenSequnce p1{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
	p1.dump();
	try {
		EvenSequnce p2{ 1.0,2.0,3.0 };
	}catch (const invalid_argument& e) {
		cout<<e.what()<<endl;
	}
	SpreadsheetCell cell3[3];
	SpreadsheetCell cell("nihao");
	SpreadsheetCell cell1{ 1 };
	cell1 = 6.0;
	cell1 = SpreadsheetCell{ 2,12.0 };
	cout << "------------" << endl;
	SpreadsheetCell cell2;
	cell2 = cell1;
	cout << cell2.a << endl << cell2.double_a << endl;
	cout << "------------" << endl;
	/*以下是关于 **`std::vector`** 和 **`std::string`** 的核心方法及其相关特性的介绍，基于参考材料：

---

### **1. `std::vector` 的常用方法**
#### **(1) 核心操作方法**
- **`push_back()`**：向容器尾部添加元素。
- **`resize()`**：调整容器大小，可指定新大小及默认值。
- **`size()`**：返回容器元素个数。
- **`capacity()`**：返回当前分配的存储容量（可能大于 `size()`）。
- **`reserve()`**：预分配内存空间以优化性能。
[^2]: 材料2提到 `std::vector` 的改进包括处理别名、强异常保证，以及减少元素操作的开销。

#### **(2) 迭代与访问**
- **`at()`**：安全访问元素（越界时抛出异常）。
- **`operator[]`**：直接访问元素（无越界检查）。
- **`begin()`/`end()`**：返回迭代器以遍历容器。

#### **(3) 内存管理优化**
- **别名处理**：`std::vector` 现支持在插入和安置操作中处理别名，符合 C++ 标准要求。
- **性能提升**：插入和安置操作的元素操作减少，吞吐量提高。
[^2]: 材料2详细说明了 `std::vector` 的内存管理和性能优化改进。
以下是关于 `std::vector` 的 `assign` 方法的说明，基于参考材料：

### **`std::vector` 的 `assign` 方法**
#### **功能**
`assign` 方法用于通过指定范围或重复值重新初始化容器，**替换原有内容**。其典型用法包括：
1. **用另一范围的元素赋值**：
   ```cpp
   meshData.Indices32.assign(&k[0], &k[60]); // 将 Indices32 初始化为 k 数组的元素 
   ```
   这里通过迭代器 `&k[0]` 和 `&k[60]` 指定范围，将 `Indices32` 的内容替换为 `k` 数组的元素。

2. **用相同值填充**（未在材料中直接体现，但为标准用法）：
   ```cpp
   vec.assign(n, value); // 将容器设置为 n 个 value
   ```

#### **特性**
- **替换原有内容**：调用 `assign` 后，容器的原有元素会被清除，并替换为新值。
- **高效性**：若新元素数量与当前容量匹配，可避免多次内存分配。

---

### **参考材料关联**
- **材料1** 中的代码示例明确使用了 `assign` 方法，通过迭代器范围初始化 `std::vector` 的内容。
[^1]: 材料1展示了 `std::vector` 的 `assign` 方法用于从数组初始化索引列表。

---

### **总结**
`assign` 是 `std::vector` 的核心方法，用于高效地通过范围或重复值重新初始化容器内容。其典型应用场景包括从数组或其他容器批量赋值，如材料1中的几何数据初始化。


---

### **2. `std::string` 的常用方法**
#### **(1) 字符串操作**
- **`append()`** 或 **`+` 操作符**：拼接字符串。
- **`substr()`**：提取子字符串。
- **`find()`**：查找子字符串位置。
- **`erase()`**：删除指定位置或范围的字符。
[^2]: 材料2提到 `std::string` 的移动构造函数性能提升超过三倍。

#### **(2) 容量与大小**
- **`size()`**：返回字符数量。
- **`capacity()`**：返回当前分配的字符缓冲区大小。
- **`resize()`**：调整字符串长度。

#### **(3) 性能优化**
- **移动语义**：`std::string` 的移动构造函数优化显著提升性能（材料2）。
- **`operator==` 优化**：先比较字符串长度，再比较内容，减少不必要的比较。
[^2]: 材料2指出 `std::string` 的 `operator==` 已优化。

---

### **3. `std::vector<std::string>` 的典型用法**
#### **(1) 存储字符串集合**
```cpp
std::vector<std::string> vec;
vec.push_back("Hello"); // 添加字符串
vec.push_back("World");
```

#### **(2) 遍历与访问**
```cpp
for (const auto& str : vec) {
    std::cout << str << std::endl; // 输出每个字符串
}
```

#### **(3) 性能考虑**
- 使用 `reserve()` 预分配空间以避免频繁内存重分配。
- 利用 `std::string` 的移动语义减少拷贝开销。

---

### **4. 材料关联**
- **`std::vector` 的改进**：材料2提到 `std::vector` 在插入和安置操作中支持别名处理，并优化了异常保证。
- **`std::string` 的优化**：材料2指出其移动构造函数性能提升，且 `operator==` 更高效。
- **向量数学运算**：材料6列出的向量操作符（如 `+`, `-`, `*`）与 `std::vector` 容器无关，但可能用于数学库中的向量类型（如 `XMVECTOR`）。

---

### **总结**
`std::vector` 和 `std::string` 是 C++ 标准库中核心容器类，其方法覆盖了数据存储、操作和性能优化。结合材料中的改进（如 `std::vector` 的别名处理和 `std::string` 的移动语义优化），开发者可高效实现动态数组和字符串管理。

[^2]: 材料2详细描述了 `std::vector` 和 `std::string` 的性能优化及功能改进。*/
	return 0;
}