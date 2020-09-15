#include    <iostream>
#include    <experimental/filesystem>
#include	<iomanip>
#include    "Language.h"
#include	"LanguageDB.h"
namespace fs = std::experimental::filesystem;

//define static variables;
int Language::files_sum = 0;
int Language::blank_sum = 0;
int Language::comment_sum = 0;
int Language::code_sum = 0;
int Language::words_sum = 0;

extern std::vector<Language*> cloc_langs;

//결과 출력함수
void Language::print_output(int text_files, int files_ignored){
	printf("%d text files\n", text_files);
	printf("%d files ignored\n", files_ignored);
	printf("----------------------------------------------------------\n");
	printf("Language%20s%10s%10s%10s\n", "files", "blank", "comment", "code");
	printf("----------------------------------------------------------\n");
	
	for(const auto& l : cloc_langs){
		std::cout.width(22);
		std::cout << std::left << l->get_language_name();
		
		std::cout.width(6);
		std::cout << std::right << l->get_files();
		
		std::cout.width(10);
		std::cout << std::right << l->get_blank();
	
		std::cout.width(10);
		std::cout << std::right << l->get_comment();
		
		std::cout.width(10);
		std::cout << std::right << l->get_code();
		
		std::cout << std::endl;
	}
	
	printf("----------------------------------------------------------\n");
	printf("SUM:%24d%10d%10d%10d\n", files_sum, blank_sum, comment_sum, code_sum);
	printf("----------------------------------------------------------\n");
	
	
}

std::string Language::find_lang(std::string ext){
	//std::cout << ext << std::endl;
	for(int i=0 ; i<159 ; i++){
		for(int j=0 ; j<10 ; j++){
			if(Langs_exts[i][j].empty())
				break;
			if(ext == Langs_exts[i][j]){
				return Langs[i];
			}
		}
	}
	
	return "";
}

int Language::find_lang_instance_exists(std::string lang){
	for(unsigned int i=0 ; i<cloc_langs.size() ; i++){
		if(lang == cloc_langs[i]->get_language_name())
			return i;
	}
	return -1;
}

void Language::parse_line(fs::path p, std::string content, bool& multi_line_comments, Language*& tmp){
	int index2;
	
	if(content == "\n")
		tmp->set_blank(tmp->get_blank() + 1);
	else if((index2 = content.find("//")) != -1){	//한줄 주석
		if(content.substr(0, index2-1).empty())
			tmp->set_comment(tmp->get_comment() + 1);
		else
			tmp->set_code(tmp->get_code() + 1);
	}
	else if((index2 = content.find("/*")) != -1){	//여러줄 주석 시작
		tmp->set_comment(tmp->get_comment() + 1);
		multi_line_comments = true;
	}
	else if((index2 = content.find("*/")) != -1){
		tmp->set_comment(tmp->get_comment() + 1);
		multi_line_comments = false;
	}
	else{
		if(multi_line_comments)
			tmp->set_comment(tmp->get_comment() + 1);
		else
			tmp->set_code(tmp->get_code() + 1);
	}
	
	return;
}

//
void Language::parse_string_by_lines(std::string content, std::vector<std::string>& lines){
	int cur = 0;
	
	while(true){
		cur = content.find('\n');
		if(cur == -1){
			if(!content.empty())
				lines.push_back(content);
			break;
		}
		std::string tmp_string = content.substr(0, ++cur);
		content = content.substr(cur);
		lines.push_back(tmp_string);
	}
}


std::string Language::get_language_name(){
	return language_name;
}

void Language::set_language_name(std::string lang){
	Language::language_name = lang;
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