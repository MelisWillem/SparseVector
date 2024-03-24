module;
#include<type_traits>

export module spr:indexlist;

namespace spr{
    export template<auto... indexes>
    struct Indexlist{};
}
