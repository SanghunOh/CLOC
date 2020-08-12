#include    <iostream>
#include    <string>
#include	<vector>
#include	<fstream>
#include	<queue>
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
	Language(std::string);
	static int files_sum;
	static int blank_sum;
	static int comment_sum;
	static int code_sum;
	static int words_sum;
	static void print_output();
};

std::priority_queue<Language> cloc_langs;

//Language 클래스 생성자
Language::Language(std::string language_name) 
	: language_name(language_name), files(0), blank(0), comment(0), code(0), words(0) {}

//결과 출력함수
void Language::print_output(){
	printf("--------------------------------------------------------------------\n");
	printf("Language%20s%10s%10s%10s%10s\n", "files", "blank", "comment", "code", "words");
	printf("--------------------------------------------------------------------\n");
	
}

//파일 내용 읽어오기
void readFile(const fs::directory_entry entry){
//	std::cout << entry.path() << std::endl;

	if(fs::is_empty(entry)){
		return;
	}
	if(fs::is_directory(entry)){
		return;
	}
	
	std::ifstream fp(entry.path());
	std::string content;
	if(fp.is_open()){
		fp.seekg(0, std::ios::end);
		int size = fp.tellg();
		std::cout << "size : " << size << std::endl;
		content.resize(size);
		
		fp.seekg(0, std::ios::beg);
		
		fp.read(&content[0], size);
		std::cout << content << std::endl;
	}
	else{
		std::cout << "There is no file\n";
	}
	
	return;
}

//파일이 존재하는 지확인
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
		readFile(entry);
	}
}

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