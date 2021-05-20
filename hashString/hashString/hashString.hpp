

#ifndef hashString_hpp
#define hashString_hpp
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <set>

class hashString{
public:
    hashString(std::string text,int sizeHash,std::string alphabet = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ") :
    __sourceText(text),__text(text),__sizeHash(sizeHash),__alphabet(alphabet)
    {
        distributionAlphabet();
        allTextToHash();
    };
    
    std::vector<std::string> searchInText(const std::string& searchWorld);

private:
    void distributionAlphabet();
    void allTextToHash();
    std::string worldToHash(const std::string& world);
    std::vector<std::string> differentOptionsHash(std::string& hash);
    
private:
    const std::string __sourceText;
    std::string __text;
    int __sizeHash;
    std::string __alphabet ;
    std::vector<std::string> __hashAplphabet;
    std::map<std::string,std::vector<std::string>> __hashText;
};
#endif /* hashString_hpp */
