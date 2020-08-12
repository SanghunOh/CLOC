#pragma once

#include    <experimental/filesystem>
namespace fs = std::experimental::filesystem;
//language 클래스
class Language{
private:
	std::string language_name;
	int files;
	int blank;
	int comment;
	int code;
	int words;
	static int files_sum;
	static int blank_sum;
	static int comment_sum;
	static int code_sum;
	static int words_sum;

public:
	Language(std::string);
	
	int get_files();
	int get_blank();
	int get_comment();
	int get_code();
	int get_words();
	int get_files_sum();
	int get_blank_sum();
	int get_comment_sum();
	int get_code_sum();
	int get_words_sum();
	
	void set_files(int);
	void set_blank(int);
	void set_comment(int);
	void set_code(int);
	void set_words(int);
	void set_files_sum(int);
	void set_blank_sum(int);
	void set_comment_sum(int);
	void set_code_sum(int);
	void set_words_sum(int);
	
	static void print_output();
	static void parse_string(fs::directory_entry, std::string);
};