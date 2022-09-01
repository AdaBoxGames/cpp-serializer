#pragma once

// --- Standard ---
#include <ostream>

// --- SCS ---
#include "BasicTextFormatter.hpp"

// --- SCS impl ---
#include "impl/TypeTraits.hpp"



namespace scs
{
	template<class Formatter>
	class oarchive final
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - MEMBER TYPES --------------------------------------------------------------

		// Foramatter type
		using fomatter = Formatter;



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		oarchive(std::ostream& ostream);

		// Default destructor
		~oarchive() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATORS -----------------------------------------------------------------

		// Output data to the stream
		// Note: Each call outputs data arguments on a new line
		template<class... Targs>
		oarchive& operator()(Targs&&... args);



	private:
		////////////////////////////////////////////////////////////////////////////////
		// - PRIVATE HELPER FUNCTIONS --------------------------------------------------

		// Output a new line character to the stream
		oarchive& newLine();

		// Empty process function. Inserts a new line character to the stream
		oarchive& process();

		// Calls the appropriate SFINAE scs::oarchive::process_impl function 
		// for each argument
		template<class Head, class... Tail>
		oarchive& process(Head&& head, Tail&&... tail);



		// --- Process Primitive Data Types ---

		// Output boolean data to the stream
		oarchive& process_impl(const bool b);

		// Output character data to the stream
		oarchive& process_impl(const char c);

		// Output integer data to the stream
		oarchive& process_impl(const std::int32_t i);

		// Output unsigned integer data to the stream
		oarchive& process_impl(const std::uint32_t u);

		// Output floating point data to the stream
		oarchive& process_impl(const float f);

		// Output floating point (double) data to the stream
		oarchive& process_impl(const double d);



	private:
		std::ostream& m_OStream;
	};



	// --- Inline Definition ---
#	include "oarchive.inl"



	// --- Common scs::oarchive Types ---
	using text_oarchive = oarchive<BasicTextFormatter>;
}
