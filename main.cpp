#include    <iostream>
#include    <string>
#include	<vector>
#include	<fstream>
#include	<queue>
#include    <experimental/filesystem>
#include	"Language.h"
namespace fs = std::experimental::filesystem;

void readFile(const fs::directory_entry entry, std::string& content);
bool does_exist(fs::path p);
bool count_lines_of_code(fs::path target_path);

std::priority_queue<Language> cloc_langs;

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
		Language::print_output();
	}
	
	return 0;
}

//파일 내용 읽어오기
void readFile(const fs::directory_entry entry, std::string& content){
	if(fs::is_empty(entry)){
		return;
	}
	if(fs::is_directory(entry)){
		return;
	}
	
	std::ifstream fp(entry.path());
	if(fp.is_open()){
		fp.seekg(0, std::ios::end);
		int size = fp.tellg();
		std::cout << "size : " << size << std::endl;
		content.resize(size);
		
		fp.seekg(0, std::ios::beg);
		
		fp.read(&content[0], size);
	}
	else{
		std::cout << "There is no file\n";
	}
	
	return;
}

//파일이 존재하는 지 확인
bool does_exist(fs::path p){
	return fs::exists(p);
}

//cloc 계산
bool count_lines_of_code(fs::path target_path){
	if(!does_exist(target_path)){
		std::cout << "Path doesn't exist\n";
		return false;
	}

	if(fs::is_empty(target_path)){
		std::cout << "Folder is empty\n";
		return false;
	}
	
	for(const fs::directory_entry entry : fs::recursive_directory_iterator(target_path)){
		std::string content;
		readFile(entry, content);
		
		Language::parse_string(entry, content);
	}
	
	return false;
}