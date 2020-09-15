#include    <iostream>
#include    <string>
#include	<fstream>
#include    <experimental/filesystem>

#include	"Language.h"
#include	"LanguageDB.h"
namespace fs = std::experimental::filesystem;

int readFile(const fs::directory_entry entry, std::string& content);
bool does_exist(fs::path p);
bool count_lines_of_code(fs::path target_path);
int files_ignored;
int text_files;

std::vector<Language*> cloc_langs;


int main(int argc, char* argv[]){
	if(argc < 2){
	    std::cout << "Please enter filename" << '\n';
	    
	    return -1;
	}
	else if(argc > 2){
	    std::cout << "Please enter onely 1 filename" << '\n';
	    
	    return -1;
	} 

	std::string path = argv[1];
	fs::path target_path(path);
	
	if(count_lines_of_code(target_path)){
		Language::print_output(text_files, files_ignored);
	}
	
	return 0;
}

//파일 내용 읽어오기
int readFile(const fs::directory_entry entry, std::string& content){
	if(fs::is_empty(entry)){
		files_ignored++;
		return 0;
	}
	if(fs::is_directory(entry)){
		return -1;
	}
	
//	std::cout << entry.path() << std::endl;
	text_files++;
	
	std::ifstream fp(entry.path());
	if(fp.is_open()){
		fp.seekg(0, std::ios::end);
		int size = fp.tellg();
		content.resize(size);
		
		fp.seekg(0, std::ios::beg);
		
		fp.read(&content[0], size);
	}
	else{
		std::cout << "There is no file\n";
	}
	
	return 1;
}

//파일이 존재하는 지 확인
bool does_exist(fs::path p){
	return fs::exists(p);
}

//cloc 계산
bool count_lines_of_code(fs::path target_path){
	bool multi_line_comments = false;
	if(!does_exist(target_path)){	//파일 경로 확인 없으면 종료
		std::cout << "Path doesn't exist\n";
		return false;
	}

	if(fs::is_empty(target_path)){	//폴더가 비어있는지 확인 비어있으면 종료
		std::cout << "Folder is empty\n";
		return false;
	}
	
	for(const fs::directory_entry entry : fs::recursive_directory_iterator(target_path)){	//폴데 내 파일을 모두 확인
	
		if(fs::is_directory(entry))
			continue;
	
		std::string content;
		std::vector<std::string> lines;
		int index;
		std::string lang = Language::find_lang(entry.path().extension().string().substr(1));
		int state = readFile(entry, content);
		
		if(state == 0){
			Language::files_sum++;
			Language* tmp;
		
			if((index = Language::find_lang_instance_exists(lang)) != -1)
				tmp = cloc_langs[index];
			else
				tmp = new Language(lang);
				
			tmp->set_files(tmp->get_files() + 1);
			
			if(index == -1){
				cloc_langs.push_back(tmp);
			}
				
			continue;
		}
		else if(state == -1){
			continue;
		}
		else{
			Language::files_sum++;
			if(lang.empty())
				continue;
			else
				Language::parse_string_by_lines(content, lines);	//파일을 읽어와 lines에 저장
			
			Language* tmp;
			
			if((index = Language::find_lang_instance_exists(lang)) != -1)
				tmp = cloc_langs[index];
			else
				tmp = new Language(lang);
			
			tmp->set_files(tmp->get_files() + 1);
			
			if(index == -1){
				cloc_langs.push_back(tmp);
			}
			
			for(const std::string s : lines){	//lines에 저장된 line을 분석
				Language::parse_line(entry.path(), s, multi_line_comments, tmp);
			}
		}
		
	}
	
	return true;
}