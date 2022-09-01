#pragma once

// --- Standard ---
#include <iomanip>
#include <sstream>
#include <ostream>



namespace scs
{
	struct BasicTextFormatter final
	{
		static constexpr char delimiter = ' ';

		inline static std::string out_bool(const bool b)
		{
			std::ostringstream converter;
			converter << std::boolalpha << b;
			return converter.str();
		}

		inline static char out_char(const char c)
		{
			return c;
		}

		inline static std::int32_t out_int(const std::int32_t i)
		{
			return i;
		}

		inline static std::uint32_t out_uint(const std::uint32_t u)
		{
			return u;
		}

		inline static std::string out_float(const float f)
		{
			std::ostringstream converter;
			converter << std::setprecision(9) << f;
			return converter.str();
		}

		inline static std::string out_double(const double d)
		{
			std::ostringstream converter;
			converter << std::setprecision(18) << d;
			return converter.str();
		}
	};
}
