#ifndef __LANGUAGE_H__
#define __LANGUAGE_H__

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
	

public:
	//Language 클래스 생성자
	Language(std::string language_name) 
		: language_name(language_name), files(0), blank(0), comment(0), code(0), words(0) {};
	
	//static sum properties;
	//static 들은 꼭 선언과 초기화를 해주어야함
	static int files_sum;
	static int blank_sum;
	static int comment_sum;
	static int code_sum;
	static int words_sum;
	
	//get properties;
	int get_files();
	int get_blank();
	int get_comment();
	int get_code();
	int get_words();
	static int get_files_sum();
	static int get_blank_sum();
	static int get_comment_sum();
	static int get_code_sum();
	static int get_words_sum();
	
	//set properties;
	void set_files(int);
	void set_blank(int);
	void set_comment(int);
	void set_code(int);
	void set_words(int);
	static void set_files_sum(int);
	static void set_blank_sum(int);
	static void set_comment_sum(int);
	static void set_code_sum(int);
	static void set_words_sum(int);
	
	static void print_output();
	static void parse_string(fs::directory_entry, std::string);
};

#endif