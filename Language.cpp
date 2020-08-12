#include    <iostream>
#include    <experimental/filesystem>
#include    "Language.h"
namespace fs = std::experimental::filesystem;

//Language 클래스 생성자
Language::Language(std::string language_name) 
	: language_name(language_name), files(0), blank(0), comment(0), code(0), words(0) {}

//결과 출력함수
void Language::print_output(){
	printf("--------------------------------------------------------------------\n");
	printf("Language%20s%10s%10s%10s%10s\n", "files", "blank", "comment", "code", "words");
	printf("--------------------------------------------------------------------\n");
	
}

//
void Language::parse_string(fs::directory_entry entry, std::string content){
	
}

//files 리턴
int Language::get_files(){
	return files;
}

//blank 리턴
int Language::get_blank(){
	return blank;
}

//comment 리턴
int Language::get_comment(){
	return comment;
}

//code 리턴
int Language::get_code(){
	return code;
}

//words 리턴
int Language::get_words(){
	return words;
}

//files_sum 리턴
int Language::get_files_sum(){
	return files_sum;
}

//blank_sum 리턴
int Language::get_blank_sum(){
	return blank_sum;
}

//comment_sum 리턴
int Language::get_comment_sum(){
	return comment_sum;
}

//code_sum 리턴
int Language::get_code_sum(){
	return code_sum;
}

//words_sum 리턴
int Language::get_words_sum(){
	return words_sum;
}

//////////////////////
//files 초기화
void Language::set_files(int _files){
    files = _files;
}

//blank 초기화
void Language::set_blank(int _blank){
	blank = _blank;
}

//comment 초기화
void Language::set_comment(int _comment){
	comment = _comment;
}

//code 초기화
void Language::set_code(int _code){
	code = _code;
}

//words 초기화
void Language::set_words(int _words){
	words = _words;
}

//files_sum 초기화
void Language::set_files_sum(int _files_sum){
	files_sum = _files_sum;
}

//blank_sum 초기화
void Language::set_blank_sum(int _blank_sum){
	blank_sum = _blank_sum;
}

//comment_sum 초기화
void Language::set_comment_sum(int _comment_sum){
	comment_sum = _comment_sum;
}

//code_sum 초기화
void Language::set_code_sum(int _code_sum){
	code_sum = _code_sum;
}

//words_sum 초기화
void Language::set_words_sum(int _words_sum){
	words_sum = _words_sum;
}