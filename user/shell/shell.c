#include "shell.h"
#include "../../include/print.h"
#include "../../include/string.h"
#include "../../include/fs.h"  

extern FileSystem fs;
#define NULL 0
char* cmdline="shell:# ";

void help(){
	print("Basic Commands:\n");
	print("about\t-\tabout the system\n");
	print("clear\t-\tclear the screen\n");
	print("help\t-\tbasic help\n");
     print("create <filename>\t-\tcreate a new file\n");
    print("delete <filename>\t-\tdelete an existing file\n");
    print("write <filename> <content>\t-\twrite content to a file\n");
    print("read <filename>\t-\tread content from a file\n");
    print("list\t-\tlist all files\n");
}

void shell(){
	char *cmd;
	cmd[0]='\n';
	while(1){
	print_color(cmdline, 0xf9);
	cmd=(char*)readStr();
	print("\n");
	if(strcmp("\0", cmd)==1){ }
		
	else if(strcmp("help", cmd)==1){
		help();
		cmd[0]='\n';	
	}
	
	else if(strcmp("clear", cmd)==1){
		clear_();
		cmd[0]='\n';	
	}
	else if(strcmp("about", cmd)==1){
		print("Maya is an x86 based OS\n");			
		cmd[0]='\n';
	}
 else if (strncmp(cmd, "create ", 7) == 0) {
           
            char* filename = cmd + 7;
            if (create_file(&fs, filename)) {
                print("File created successfully.\n");
            } else {
                print("No space available to create file.\n");
            }
            cmd[0] = '\n';
        }
        else if (strncmp(cmd, "delete ", 7) == 0) {
            
            char* filename = cmd + 7;
            if (delete_file(&fs, filename)) {
                print("File deleted successfully.\n");
            } else {
                print("File not found.\n");
            }
            cmd[0] = '\n';
        }
        else if (strncmp(cmd, "write ", 6) == 0) {
           
            char filename[32], content[256];
            sscanf(cmd + 6, "%s %[^\n]", filename, content);  
            if (write_file(&fs, filename, content)) {
                print("File written successfully.\n");
            } else {
                print("File not found.\n");
            }
            cmd[0] = '\n';
        }
        else if (strncmp(cmd, "read ", 5) == 0) {
            
            char* filename = cmd + 5;
            const char* content = read_file(&fs, filename);
            if (content) {
                print("File content: ");
                print(content);
                print("\n");
            } else {
                print("File not found.\n");
            }
            cmd[0] = '\n';
        }
        else if (strcmp(cmd, "list") == 0) {
           
            list_files(&fs);
            cmd[0] = '\n';
        }
	else{
		print("command not found\n");
		cmd[0]='\n';
	}
}
}

