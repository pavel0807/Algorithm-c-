#include <iostream>
#include "hashString.hpp"


int main(int argc, const char * argv[]) {
    
    hashString a("When Tap to Translate is on, you can copy text from any app on your Android device and translate it to another language. Tap to Translate can only translate text in an app, not images.Important: Text you've copied will be sent to Google for translation only after you yau yoy tap the Google Translate icon.",10);
    std::vector<std::string> resultSearch = a.searchInText("impotant");
    return 0;
}
