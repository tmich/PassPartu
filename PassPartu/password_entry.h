#pragma once
class PasswordEntry
{
public:
	PasswordEntry();
	explicit PasswordEntry(std::string name);
	PasswordEntry(std::string name, std::string url);
	
	~PasswordEntry();

	std::string name() const { return name_; }
	void set_name(std::string name) { name_ = name; }

	std::string password() const { return password_; }
	void set_password(std::string password) { password_ = password; }

	std::string url() const { return url_; }
	void set_url(std::string url) { url_ = url; }

	std::string account() const { return account_; }
	void set_account(std::string account) { account_ = account; }

	std::string to_string() const;

protected:
	std::string name_;
	std::string password_;
	std::string url_;
	std::string account_;
};

