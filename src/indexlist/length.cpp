module;
#include<type_traits>

export module spr:length;
export import :indexlist;

namespace spr{
    template<typename List>
    struct length;

    template<auto... args>
    struct length<Indexlist<args...>>
    : std::integral_constant<unsigned, sizeof...(args)>
    {
    };

    export template<typename List>
    constexpr std::size_t length_v = length<List>::value;
}
