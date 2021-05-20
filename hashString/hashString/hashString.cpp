#include "hashString.hpp"


void hashString::distributionAlphabet()
{
    int sizeAplhabet = this->__alphabet.size();
    int sizeOneCell  = sizeAplhabet / this->__sizeHash;
    
    for(size_t indexAplhabet=0;indexAplhabet<sizeAplhabet;)
    {
        std::string inOneCell = "";
        for(size_t indexCell =0 ;indexCell<sizeOneCell & indexAplhabet < sizeAplhabet;++indexCell,++indexAplhabet)
        {
            inOneCell +=__alphabet[indexAplhabet];
        }
        this->__hashAplphabet.push_back(inOneCell);
    }
    
}

void hashString::allTextToHash()
{
    //TODO::редактируем текст от цифр и пунктуации
    this->__text.erase (std::remove_if (this->__text.begin (), this->__text.end (), ispunct), this->__text.end ());
    
    //TODO::разделяем весь текст на вектор  слова
    std::istringstream iss(this->__text);
    std::vector<std::string> vectorWorld;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter<std::vector<std::string> >(vectorWorld));
    
    std::set<std::string> setWorld(vectorWorld.begin(),vectorWorld.end());
    //TODO::каждой слову ставим хэш и заполняем словарь
    for(auto const& value: setWorld) {
        this->__hashText[worldToHash(value)].push_back(value);
    }
}

std::string hashString::worldToHash(const std::string& world){
    std::string hash = std::string(this->__sizeHash,'0');
    for(size_t indexHash=0;indexHash<this->__sizeHash;++indexHash)
    {
        for(size_t indexCell =0;indexCell < __hashAplphabet[indexHash].size();++indexCell)
        {
            if(std::find(world.begin(), world.end(), this->__hashAplphabet[indexHash][indexCell]) != world.end())
            {
                hash[indexHash] = '1';
                break;
            }
        }
    }
    return hash;
}
std::vector<std::string> hashString::searchInText(const std::string& searchWorld)
{
    std::vector<std::string> result;
    std::string hashSearchWorld = this->worldToHash(searchWorld);
    std::vector<std::string> differentHash = differentOptionsHash(hashSearchWorld);
    for(auto const& hash: differentHash)
    {
        if(this->__hashText.find(hash) != this->__hashText.end())
        {
            std::copy(this->__hashText[hash].begin(), this->__hashText[hash].end(),std::back_inserter(result));
        }
        
    }
    return result;
}

std::vector<std::string> hashString::differentOptionsHash(std::string& hash)
{
    std::vector<std::string> result;
    result.push_back(hash);
    
    size_t sizeHash = hash.size();
    
    for(size_t indexHash=0;indexHash<sizeHash;++indexHash)
    {
        hash[indexHash] == '0' ? hash[indexHash] = '1' : hash[indexHash] = '0';
        result.push_back(hash);
        hash[indexHash] == '0' ? hash[indexHash] = '1' : hash[indexHash] = '0';
    }
    return result;
}
