#include <stdio.h>
#include <unistd.h>
#include <map>
#include <getopt.h>
#include <string>


using namespace std;

int main(int argc, char *argv[]) {
    int rez = 0;
    int index = -1;
    
    map<string, bool> call;
    
    const char *srt_options = "lvha:s";

    static const struct option lng_options[] = {
            {"list", 0, NULL, 'l'},
            {"version",  0, NULL, 'v'},
            {"help",  0, NULL, 'h'},
            {"arg", 1, NULL, 'a'}, 
            {"showopt",0,NULL,'s'},
            {NULL,0,NULL,0}
    };

    while ((rez = getopt_long(argc, argv, srt_options, lng_options, &index)) != -1) {
        switch (rez) {
            case 'l': {
                if (call["l"] == false) {
                    printf("Arg: List\n");
                    call["l"] = true;
                    break;
                }
                break;
            }
            case 'v': {
                if (call["v"] == false) {
                    printf("Arg: Version\n");
                    call["v"] = true;
                    break;
                }
                break;
            }
            case 'h': {
                if (call["h"] == false) {
                    printf("Arg: Help\n");
                    call["h"] = true;
                    break;
                }
                break;
            }
            case 's': {
                if (call["s"] == false) {
                    printf("Arg:\n-l --list List\n-h --help Help\n-v --version Version\n-s --showopt Options\n");
                    call["s"] = true;
                    break;
                }
                break;    
            }
            case 'a': {
		 if (call["a"] == false) {
                    printf("arg = %s\n", optarg); 		
                    call["a"] = true;
                    break;
                }
                break;    
            }
            
            case '?': default: {
                printf("error %c not found\n", rez);
                break;
            }
        }
        index = -1;
    }
}
