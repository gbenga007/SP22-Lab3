#include <iostream>
#include <string>
#include <fstream>

class Node{

	public : 
		std::string Name;
		float GPA;
		int total_credits;
		Node* next;
		Node();
		Node(std::string fileName);
		void printList();
	

};

Node::Node(){
	next = nullptr;
	Name="*";
	GPA=0.0;
	total_credits=0;
}


Node::Node(std::string fileName){

	std::ifstream ifs(fileName);
	
	if(!ifs){
		std::cout << "Unable to read file `" << fileName <<  "`" << std::endl;
	}

	std::string tmp_str;
	Node* currentNode = this;
	while(!ifs.eof()){
		ifs >> currentNode->Name;
		ifs >> tmp_str;
		currentNode->GPA = std::stof(tmp_str);
		ifs >> tmp_str;
		currentNode->total_credits = std::stoi(tmp_str,nullptr,10);
		
		if(!ifs.eof()){
			Node* newNode = new Node(); 
		    currentNode->next = newNode;
		    currentNode = newNode;
		}
		
	}

}

void Node::printList(){


	std::cout << "\n**BEGIN LIST**" << std::endl;
	Node* currentNode = this;
	while(currentNode!=nullptr){
		std::cout << currentNode->Name << "->";
		currentNode = currentNode->next;
	}
	std::cout << "\n**END OF LIST**" << std::endl;
}

void print_usage(std::string progName){
	std::cout << "Usage :\n\t" << progName << " <Input file name>" << std::endl; 
}

int main(int argc, char* argv[]){

	if(argc < 2){
		std::cout << "ERROR :: Insufficient command line" << std::endl;
		print_usage(argv[0]);
		return -1;
	}
	std::string fileName(argv[1]);
	Node* list = new Node(fileName);
	list->printList();




	

	return 0;

}
