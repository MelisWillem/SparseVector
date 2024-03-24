export module spr:isempty;

export import :indexlist;

namespace spr{

template<typename List>
struct is_empty;

template<auto... vals>
struct is_empty<Indexlist<vals...>>{
    static constexpr bool value = (sizeof...(vals) == 0);
};

export template<typename List>
constexpr bool is_empty_v = is_empty<List>::value;

}
