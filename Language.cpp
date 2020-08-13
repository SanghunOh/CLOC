#include    <iostream>
#include    <experimental/filesystem>
#include    "Language.h"
namespace fs = std::experimental::filesystem;

//define static variables;
int Language::files_sum = 0;
int Language::blank_sum = 0;
int Language::comment_sum = 0;
int Language::code_sum = 0;
int Language::words_sum = 0;

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
	return Language::files;
}

//blank 리턴
int Language::get_blank(){
	return Language::blank;
}

//comment 리턴
int Language::get_comment(){
	return Language::comment;
}

//code 리턴
int Language::get_code(){
	return Language::code;
}

//words 리턴
int Language::get_words(){
	return Language::words;
}

//files_sum 리턴
int Language::get_files_sum(){
	return Language::files_sum;
}

//blank_sum 리턴
int Language::get_blank_sum(){
	return Language::blank_sum;
}

//comment_sum 리턴
int Language::get_comment_sum(){
	return Language::comment_sum;
}

//code_sum 리턴
int Language::get_code_sum(){
	return Language::code_sum;
}

//words_sum 리턴
int Language::get_words_sum(){
	return Language::words_sum;
}

//////////////////////
//files 초기화
void Language::set_files(int _files){
    Language::files = _files;
}

//blank 초기화
void Language::set_blank(int _blank){
	Language::blank = _blank;
}

//comment 초기화
void Language::set_comment(int _comment){
	Language::comment = _comment;
}

//code 초기화
void Language::set_code(int _code){
	Language::code = _code;
}

//words 초기화
void Language::set_words(int _words){
	Language::words = _words;
}

//files_sum 초기화
void Language::set_files_sum(int _files_sum){
	Language::files_sum = _files_sum;
}

//blank_sum 초기화
void Language::set_blank_sum(int _blank_sum){
	Language::blank_sum = _blank_sum;
}

//comment_sum 초기화
void Language::set_comment_sum(int _comment_sum){
	Language::comment_sum = _comment_sum;
}

//code_sum 초기화
void Language::set_code_sum(int _code_sum){
	Language::code_sum = _code_sum;
}

//words_sum 초기화
void Language::set_words_sum(int _words_sum){
	Language::words_sum = _words_sum;
}