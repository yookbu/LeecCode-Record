//535. TinyURL 的加密与解密
// Created by Administrator on 2020/5/6 0006.
//

class Solution {
    int short_len = 6;
    vector<char> chars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    map<string, string> m;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        while(true){
            string shortUrl;
            for(int i = 0; i < short_len;++i){
                int n = rand()%61;
                shortUrl += to_string(chars[n]);
            }
            if(m.find(shortUrl) != m.end()) continue;
            shortUrl = "http://tinyurl.com/" + shortUrl;
            m[shortUrl] = longUrl;
            return shortUrl;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string longUrl = m[shortUrl];
        m.erase(shortUrl);
        return longUrl;
    }
};