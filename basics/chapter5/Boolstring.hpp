#include <string>

class BoolString
{
private:
    std::string value;

public:
    BoolString(std::string &tmp) : value{tmp} {}
    template <typename T>
    T get() const
    {
        return value;
    }
};

// 成员模板也可特化
template <>
inline bool BoolString::get<bool>() const
{ // 对成员模板的特化必须内联，以免其他编译单元重复包含
    return value == "true" || value == "1" || value == "on";
}