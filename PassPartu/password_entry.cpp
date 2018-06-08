#include "stdafx.h"
#include <sstream>
#include "password_entry.h"

PasswordEntry::PasswordEntry()
	: PasswordEntry{ "" }
{
}

PasswordEntry::PasswordEntry(std::string name)
	: name_{ name }
{
}

PasswordEntry::PasswordEntry(std::string name, std::string url)
	: PasswordEntry{ name }
{
	set_url(url);
}


PasswordEntry::~PasswordEntry()
{
}

std::string PasswordEntry::to_string() const
{
	std::string separator = "|";
	std::stringstream ss;
	ss << name_ << separator << password_ << separator << url_ << separator << account_;
	return ss.str();
}
