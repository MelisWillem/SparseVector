export module spr:head;

export import :indexlist;

namespace spr{

export template<typename List>
struct head;

export template<auto val, auto... tail>
struct head<Indexlist<val, tail...>>
{
    static constexpr auto value = val;
};

export template<typename List>
constexpr auto head_v = head<List>::value;

}
