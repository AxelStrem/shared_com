#pragma once

template <class T> IID GetIID()
{
	static_assert(false,"Missing GetIID specialization - use REGISTER_IID( interface name )");
}

#define REGISTER_IID(interface_name) template<> IID GetIID< interface_name >() { return IID_##interface_name; }

REGISTER_IID(IUnknown)