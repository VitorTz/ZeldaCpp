#pragma once
#include <cstdint>


namespace ze {


	typedef std::uint32_t Entity;
	typedef std::uint8_t Zindex;	
	typedef std::uint8_t ComponentId;

	constexpr static ze::Zindex MIN_Z_INDEX = 0;
	constexpr static ze::Zindex MAX_Z_INDEX = 10;

}