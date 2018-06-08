#pragma once
#include <string>
#include "password_entry.h"

using namespace std;

class CryptedPasswordEntry :
	public PasswordEntry
{
public:
	explicit CryptedPasswordEntry(string key);
	~CryptedPasswordEntry();

	std::string name() const { return name_; }
	void set_name(std::string name) { name_ = name; }

	std::string password() const;
	void set_password(std::string password) { password_ = password; }

	std::string url() const { return url_; }
	void set_url(std::string url) { url_ = url; }

	std::string account() const { return account_; }
	void set_account(std::string account) { account_ = account; }

	std::string to_string() const;
protected:
	string key_;
};

