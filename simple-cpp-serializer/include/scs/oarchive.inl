#include "oarchive.hpp"
// scs::oarchive Inline Definition File



template<class Formatter>
inline scs::oarchive<Formatter>::oarchive(std::ostream& ostream) :
	m_OStream(ostream)
{

}



template<class Formatter>
template<class ...Targs>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::operator()(Targs&&... args)
{
	return process(std::forward<Targs>(args)...);
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::newLine()
{
	m_OStream << '\n';
	return *this;
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process()
{
	return newLine();
}



template<class Formatter>
template<class Head, class ...Tail>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process(Head&& head, Tail&&... tail)
{
	process_impl(std::forward<Head>(head));
	m_OStream << Formatter::delimiter;
	return process(std::forward<Tail>(tail)...);
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process_impl(const bool b)
{
	m_OStream << Formatter::out_bool(b);
	return *this;
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process_impl(const char c)
{
	m_OStream << Formatter::out_char(c);
	return *this;
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process_impl(const std::int32_t i)
{
	m_OStream << Formatter::out_int(i);
	return *this;
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process_impl(const std::uint32_t u)
{
	m_OStream << Formatter::out_uint(u);
	return *this;
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process_impl(const float f)
{
	m_OStream << Formatter::out_float(f);
	return *this;
}



template<class Formatter>
inline scs::oarchive<Formatter>& scs::oarchive<Formatter>::process_impl(const double d)
{
	m_OStream << Formatter::out_double(f);
	return *this;
}
