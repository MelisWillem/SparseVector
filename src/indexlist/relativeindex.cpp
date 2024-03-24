module;
#include<type_traits>

export module spr:relativeindex;

export import :contains;
export import :pop_front;

namespace spr{
    template<
        auto indexSparse,
        typename List,
        auto startIndex = -1,
        bool = contains_v<List, indexSparse>>
    struct relative_index;

    template<
        auto indexSparse,
        typename List,
        auto startIndex>
    struct relative_index<indexSparse, List, startIndex, false>
    : std::integral_constant<decltype(indexSparse), startIndex>
    {
    };

    template<
        auto indexSparse,
        typename List,
        auto startIndex>
    struct relative_index<indexSparse, List, startIndex, true>
    : relative_index<indexSparse, pop_front_t<List>, startIndex + 1>
    {
    };

    export template<auto indexSparse, typename List>
    constexpr auto relative_index_v 
        = relative_index<indexSparse, List>::value;
}
